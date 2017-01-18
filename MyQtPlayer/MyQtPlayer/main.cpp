
#include <QApplication> 
#include <QWidget> 
#include <qpushbutton.h>
#include <phonon> 
#include <QUrl> 
#include "XYPlayView.h"


#define USE_FF_PLAY 1


int main(int argc, char * argv[])
{

    QApplication app(argc, argv); 

  QWidget *widget = new QWidget; 
  widget->setWindowTitle("Video Player"); 
  widget->resize(800,400); 


  //begin layout
    QVBoxLayout *verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

		
  XYPlayView *showView = new XYPlayView(widget);


  QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(showView->sizePolicy().hasHeightForWidth());
        showView->setSizePolicy(sizePolicy);

		
        verticalLayout->addWidget(showView);
		//


  widget->show(); 

#if USE_FF_PLAY

#else
  Phonon::VideoPlayer *player = new Phonon::VideoPlayer(Phonon::VideoCategory, widget); 
  player->load(Phonon::MediaSource("video.mp4")); 

  player->play(); 
#endif


  return app.exec(); 
}


