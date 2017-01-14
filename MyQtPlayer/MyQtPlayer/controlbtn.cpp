#include "controlbtn.h"

#include "ffplay.h"

ControlBtn::ControlBtn(QWidget *parent)
	: QWidget(parent),
	m_nProcess(0)
{
	ui.setupUi(this);

	connect(ui.btnPlay, SIGNAL(clicked()), this, SLOT(slot_btnPlayClicked()));
	connect(ui.btnNext, SIGNAL(clicked()), this, SLOT(slot_btnNextClicked()));
	connect(ui.btnStop, SIGNAL(clicked()), this, SLOT(slot_btnStopClicked()));
	connect(ui.btnPause, SIGNAL(clicked()), this, SLOT(slot_btnPauseClicked()));
	
	connect(ui.ctlSlider, SIGNAL(valueChanged(int)), this, SLOT(slot_SliderChanged(int)));	
	connect(this, SIGNAL(signal_playProgress(int)), ui.ctlSlider, SLOT(setValue(int)));
	
	connect(ui.btnSmall, SIGNAL(clicked()), this, SLOT(slot_btnSmallClicked()));
	connect(ui.btnBig, SIGNAL(clicked()), this, SLOT(slot_btnBigClicked()));
	connect(this, SIGNAL(signal_allocTexture(SDL_Renderer*, VideoState*, AVFrame*)), this, SLOT(slot_allocTexture(SDL_Renderer*, VideoState*, AVFrame*)));
	connect(this, SIGNAL(signal_drawTexture(VideoState*, float*)), this, SLOT(slot_drawTexture(VideoState*, float*)));

	w = ui.viewPlay->width();
	h = ui.viewPlay->height();
}

ControlBtn::~ControlBtn()
{
	playStop(&mPlayer);
}

void ControlBtn::slot_btnPlayClicked()
{	
	stopOthers();
	mPlayer = ffplay("video3.mp4", ui.viewPlay);
}
	
void ControlBtn::slot_btnNextClicked()
{
	stopOthers();
	ffplay("video2.mp4", ui.viewPlay);
}

void ControlBtn::stopOthers()
{
	playStop(&mPlayer);
	mPlayer = NULL;
	w = ui.viewPlay->width();
	h = ui.viewPlay->height();
	playSetCtl(this);
}

void ControlBtn::slot_btnStopClicked()
{
	if(mPlayer)
		playStop(&mPlayer);
}

void ControlBtn::slot_btnPauseClicked()
{
	playPause(mPlayer);
}

void ControlBtn::slot_btnSmallClicked()
{
	palySetWinWidthAndHeight(w-=10 ,h-=10);
}

void ControlBtn::slot_btnBigClicked()
{
	palySetWinWidthAndHeight(w+=10 ,h+=10);
}

void ControlBtn::slot_SliderChanged(int val)
{
	if(m_nProcess != val)
	{
		playSeek((float)val / 1000.0);
	}
}

void ControlBtn::changeSlider(int pos)
{
	if(pos<=1000 & pos >= 0)
	{
		if(m_nProcess != pos)
		{
			m_nProcess = pos;
			emit signal_playProgress(m_nProcess);
		}
	}
}

//
void ControlBtn::allocTexture(SDL_Renderer *renderer, VideoState *is, AVFrame *src)
{
	emit signal_allocTexture(renderer, is, src);
}
	
void ControlBtn::drawTexture(VideoState *is, float *remaining_time)
{
	emit signal_drawTexture(is, remaining_time);
}

void ControlBtn::slot_allocTexture(SDL_Renderer *renderer, VideoState *is, AVFrame *src)
{
	ff_alloc_picture(is, src);
}

void ControlBtn::slot_drawTexture(VideoState *is, float *remaining_time)
{
	ff_video_refresh(is, remaining_time);
}
