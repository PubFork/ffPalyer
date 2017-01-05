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
}

ControlBtn::~ControlBtn()
{
	stopPlay();
}

void ControlBtn::slot_btnPlayClicked()
{	
	stopOthers();
	ffplay("video.mp4", ui.viewPlay);
}
	
void ControlBtn::slot_btnNextClicked()
{
	stopOthers();
	ffplay("video2.mp4", ui.viewPlay);
}

void ControlBtn::stopOthers()
{
	stopPlay();
	playSetCtl(this);
}
void ControlBtn::slot_btnStopClicked()
{
	stopPlay();
}

void ControlBtn::slot_btnPauseClicked()
{
	playPause();
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

