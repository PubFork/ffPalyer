#ifndef __FFPLAY_H__
#define __FFPLAY_H__

#include <QWidget> 
   
void playSetSlider(QSlider *slider);
int ffplay(char *fileName,  QWidget *widget);
void playPause();
void playSeek(double frac);
void stopPlay();

#endif