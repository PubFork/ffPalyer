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
	mPlayView = NULL;
}

ControlBtn::~ControlBtn()
{
	stopPlay();
	if(mPlayView)
	{
		delete mPlayView;
		mPlayView = NULL;
	}
}

void ControlBtn::slot_btnPlayClicked()
{	
	stopOthers();
	ffplay("video.mp4", mPlayView);
}
	
void ControlBtn::slot_btnNextClicked()
{
	stopOthers();
	ffplay("video2.mp4", mPlayView);
}

void ControlBtn::stopOthers()
{
	stopPlay();
	playSetCtl(this);
	if(mPlayView)
	{
		delete mPlayView;
		mPlayView = NULL;
	}
	if(!mPlayView)
	{
		mPlayView = new QWidget(this);
		mPlayView->resize(800,200); 
		mPlayView->show(); 
	}
}
void ControlBtn::slot_btnStopClicked()
{
	stopPlay();
	if(mPlayView)
	{
		delete mPlayView;
		mPlayView = NULL;
	}
}

void ControlBtn::slot_btnPauseClicked()
{
	playPause();
}

void ControlBtn::slot_SliderChanged(int val)
{
	if(m_nProcess != val)
	{
		playSeek((float)val / 100.0);
	}
}

void ControlBtn::changeSlider(int pos)
{
	if(pos<=100 & pos >= 0)
	{
		if(m_nProcess != pos)
		{
			m_nProcess = pos;
			emit signal_playProgress(m_nProcess);
		}
	}
}

