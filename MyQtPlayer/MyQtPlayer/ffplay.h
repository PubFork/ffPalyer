#ifndef __FFPLAY_H__
#define __FFPLAY_H__

#include <QWidget> 
int ffplay(char *fileName,  QWidget *widget);
void pause();
void seek(double frac);
#endif