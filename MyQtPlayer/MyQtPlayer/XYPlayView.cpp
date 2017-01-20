#include "XYPlayView.h"

#include "ffplay.h"

XYPlayView::XYPlayView(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.btnPlay, SIGNAL(clicked()), this, SLOT(slot_btnPlayClicked()));
	connect(ui.btnNext, SIGNAL(clicked()), this, SLOT(slot_btnNextClicked()));
	connect(ui.btnStop, SIGNAL(clicked()), this, SLOT(slot_btnStopClicked()));
	connect(ui.btnPause, SIGNAL(clicked()), this, SLOT(slot_btnPauseClicked()));
	
	connect(ui.ctlSlider, SIGNAL(valueChanged(int)), this, SLOT(slot_SliderChanged(int)));	
	connect(this, SIGNAL(signal_playProgress(int)), ui.ctlSlider, SLOT(setValue(int)));

	connect(this, SIGNAL(signal_allocTexture(VideoState*, void*)), this, SLOT(slot_allocTexture(VideoState*, void*)));
	connect(this, SIGNAL(signal_drawTexture(VideoState*, float*)), this, SLOT(slot_drawTexture(VideoState*, float*)));

	w = ui.viewPlay->width();
	h = ui.viewPlay->height();
}

XYPlayView::~XYPlayView()
{
	playStop(&mPlayer);
}

void XYPlayView::slot_btnPlayClicked()
{	
	playFile("video3.mp4");
}
	
void XYPlayView::slot_btnNextClicked()
{
	playFile("video2.mp4");
}

void XYPlayView::playFile(char *fileName)
{
	stopOthers();
	mPlayer = ffplay(fileName, ui.viewPlay->winId());
}

void XYPlayView::stopOthers()
{
	playStop(&mPlayer);
	mPlayer = NULL;
	w = ui.viewPlay->width();
	h = ui.viewPlay->height();
	playSetCtl(this);
}

void XYPlayView::slot_btnStopClicked()
{
	if(mPlayer)
		playStop(&mPlayer);
}

void XYPlayView::slot_btnPauseClicked()
{
	playPause(mPlayer);
}

void XYPlayView::slot_SliderChanged(int val)
{
	if(m_nProcess != val)
	{
		playSeek((float)val / 1000.0);
	}
}

void XYPlayView::setProgress(int pos)
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
void XYPlayView::allocTexture(VideoState *is, void *srcFrame)
{
	emit signal_allocTexture(is, srcFrame);
}
	
void XYPlayView::drawTexture(VideoState *is, float *remaining_time)
{
	emit signal_drawTexture(is, remaining_time);
}

void XYPlayView::slot_allocTexture(VideoState *is, void *srcFrame)
{
	playAllocPicture(is, srcFrame);
}

void XYPlayView::slot_drawTexture(VideoState *is, float *remaining_time)
{
	playVideoRefresh(is, remaining_time);
}
