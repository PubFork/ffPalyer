#ifndef CONTROLBTN_H
#define CONTROLBTN_H

#include <QWidget>
#include "ui_XYPlayView.h"
#include "ffplay.h"


class XYPlayView 
	: public QWidget,
	public XYPlayViewHandler
{
	Q_OBJECT

public:
	XYPlayView(QWidget *parent = 0);

	virtual void allocTexture(VideoState* is, void *srcFrame);
	virtual void drawTexture(VideoState *is, float *remaining_time);
	virtual void setProgress(int pos);

	~XYPlayView();
private slots:
	void slot_btnPlayClicked();
	void slot_btnNextClicked();
	void slot_btnStopClicked();
	void slot_btnPauseClicked();
	void slot_SliderChanged(int val);
	void slot_allocTexture(VideoState* is, void *srcFrame);
	void slot_drawTexture(VideoState *is, float *remaining_time);


signals:
	void signal_playProgress(int pos);
	void signal_allocTexture(VideoState* is, void *srcFrame);
	void signal_drawTexture(VideoState *is, float *remaining_time);
private:
	void stopOthers();
	void playFile(char *fileName);

private:
	Ui::XYPlayView ui;
	VideoState* mPlayer;
	int w;
	int h;
};

#endif // CONTROLBTN_H
