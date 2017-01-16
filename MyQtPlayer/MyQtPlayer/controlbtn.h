#ifndef CONTROLBTN_H
#define CONTROLBTN_H

#include <QWidget>
#include "ui_controlbtn.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_thread.h"
#include "ffplay.h"


class ControlBtn : public QWidget
{
	Q_OBJECT

public:
	ControlBtn(QWidget *parent = 0);
	~ControlBtn();

	void changeSlider(int pos);
	void allocTexture(SDL_Renderer *renderer, VideoState* is, AVFrame *src);
	void drawTexture(VideoState *is, float *remaining_time);
private slots:
	void slot_btnPlayClicked();
	void slot_btnNextClicked();
	void slot_btnStopClicked();
	void slot_btnPauseClicked();
	void slot_SliderChanged(int val);
	void slot_allocTexture(SDL_Renderer *renderer, VideoState* is, AVFrame *src);
	void slot_drawTexture(VideoState *is, float *remaining_time);


signals:
	void signal_playProgress(int pos);
	void signal_allocTexture(SDL_Renderer *renderer, VideoState* is, AVFrame *src);
	void signal_drawTexture(VideoState *is, float *remaining_time);
private:
	void stopOthers();

private:
	Ui::ControlBtn ui;
	VideoState* mPlayer;
	int m_nProcess;
	int w;
	int h;
};

#endif // CONTROLBTN_H
