
#include <QApplication> 
#include <QWidget> 
#include <qpushbutton.h>
#include <phonon> 
#include <QUrl> 
#include "controlbtn.h"


#define USE_FF_PLAY 1


int main(int argc, char * argv[])
{

    QApplication app(argc, argv); 

  QWidget *widget = new QWidget; 
  widget->setWindowTitle("Video Player"); 
  widget->resize(800,400); 

  ControlBtn *show = new ControlBtn(widget);

  widget->show(); 

#if USE_FF_PLAY

#else
  Phonon::VideoPlayer *player = new Phonon::VideoPlayer(Phonon::VideoCategory, widget); 
  player->load(Phonon::MediaSource("video.mp4")); 

  player->play(); 
#endif


  return app.exec(); 
}


