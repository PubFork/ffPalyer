#ifndef CONTROLBTN_H
#define CONTROLBTN_H

#include <QWidget>
#include "ui_controlbtn.h"

class ControlBtn : public QWidget
{
	Q_OBJECT

public:
	ControlBtn(QWidget *parent = 0);
	~ControlBtn();
	void changeSlider(int pos);

private slots:
	void slot_btnPlayClicked();
	void slot_btnNextClicked();
	void slot_btnStopClicked();
	void slot_btnPauseClicked();
	void slot_SliderChanged(int val);

signals:
	void signal_playProgress(int pos);
private:
//void ffplay_callback(int pos);
void stopOthers();


private:
	Ui::ControlBtn ui;
	int m_nProcess;
};

#endif // CONTROLBTN_H
