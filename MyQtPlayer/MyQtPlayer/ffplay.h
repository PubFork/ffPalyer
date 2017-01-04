#ifndef __FFPLAY_H__
#define __FFPLAY_H__

#include <QWidget> 
class ControlBtn;


void playSetCtl(ControlBtn* ctl);
int ffplay(char *fileName,  QWidget *widget);
void playPause();
void playSeek(double frac);
void stopPlay();

#endif