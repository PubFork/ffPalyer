
#include <QApplication> 
#include <QWidget> 
#include <phonon> 
#include <QUrl> 
#include "ffplay.h"


#define USE_FF_PLAY 1


int main(int argc, char * argv[])
{

    QApplication app(argc, argv); 

  QWidget *widget = new QWidget; 
  widget->setWindowTitle("Video Player"); 
  widget->resize(400,400); 
#if USE_FF_PLAY
	ffplay("video.mp4", widget);

#else
  Phonon::VideoPlayer *player = new Phonon::VideoPlayer(Phonon::VideoCategory, widget); 
  player->load(Phonon::MediaSource("video.mp4")); 

  player->play(); 
#endif

  widget->show(); 

  return app.exec(); 
}


