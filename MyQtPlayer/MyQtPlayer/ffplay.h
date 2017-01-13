#ifndef __FFPLAY_H__
#define __FFPLAY_H__

#include <QWidget> 
class ControlBtn;


void* ffplay(char *fileName,  QWidget *widget);
void playSetCtl(ControlBtn* ctl);
void playPause();
void playSeek(double frac);
void stopPlay();
void deleteView();
void palySetWinWidthAndHeight(int w, int h);

#endif