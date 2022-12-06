#include "scrub.h"
#include <QGridLayout>
#include <QLabel>
#include <string>

Scrub::Scrub()
{
    setWindowTitle("2811: Coursework 1");
    //setMinimumSize(320, 320);
    setMaximumSize(1280, 720);

    createWidgets();

    //box layout for media
    //box layout for videooptions for media
}

void Scrub::createWidgets()
{
    QVBoxLayout * owt = new QVBoxLayout();

    QWidget * audiobar = new QWidget();
    QWidget * videobar = new QWidget();
    audiobar->setMaximumHeight(1000);
    videobar->setMaximumHeight(1000);
    audiobar->setMaximumHeight(100);
    videobar->setMaximumHeight(100);
    QHBoxLayout * audiobarLayout = new QHBoxLayout();
    QHBoxLayout * videobarLayout = new QHBoxLayout();

    QWidget * videos= new QWidget;
    QWidget * audios= new QWidget;

    for (int i=0;i<4;i++){

        addAudio();
    }
    for (int i=0;i<4;i++){
        addVideo();
    }

    audios->setLayout(audioslayout);
    audiobarLayout->addWidget(audios);
    videos->setLayout(videoslayout);
    videobarLayout->addWidget(videos);

    QPushButton * addaudiobutton = new QPushButton();
    addaudiobutton->setMaximumSize(25,25);
    addaudiobutton->setText("+");
    //add audio
    QObject::connect(addaudiobutton,SIGNAL(clicked()),this,SLOT(addAudio()));
    audiobarLayout->addWidget(addaudiobutton);
    QPushButton * addvideobutton = new QPushButton();

    addvideobutton->setMaximumSize(25,25);
    addvideobutton->setText("+");
    //add video
    QObject::connect(addvideobutton,SIGNAL(clicked()),this,SLOT(addVideo()));
    videobarLayout->addWidget(addvideobutton);

    QGridLayout * audiobuttonlayout = new QGridLayout();
    QGridLayout * videobuttonlayout = new QGridLayout();
    audiobuttons.at(0).setText("crop");
    audiobuttons.at(1).setText("cut");
    audiobuttons.at(2).setText("splice");
    audiobuttons.at(3).setText("smth");
    audiobuttons.at(4).setText("eq");
    audiobuttons.at(5).setText("audio option");
    audiobuttons.at(6).setText("audio option");
    audiobuttons.at(7).setText("audio option");
    videobuttons.at(0).setText("crop");
    videobuttons.at(1).setText("cut");
    videobuttons.at(2).setText("splice");
    videobuttons.at(3).setText("smth");
    videobuttons.at(4).setText("fx");
    videobuttons.at(5).setText("video option");
    videobuttons.at(6).setText("video option");
    videobuttons.at(7).setText("video option");



    for (int i=0;i<NO_OF_AUDIOOPTIONS;i++){
        audiobuttons.at(i).setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        audiobuttons.at(i).setStyleSheet("background-color: red");
        audiobuttonlayout->addWidget(&audiobuttons.at(i),i/4,i%4);
    }
    audiooptions->setLayout(audiobuttonlayout);

    for (int i=0;i<NO_OF_VIDEOOPTIONS;i++){
        videobuttons.at(i).setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        videobuttons.at(i).setStyleSheet("background-color: blue");
        videobuttonlayout->addWidget(&videobuttons.at(i),i/4,i%4);
    }
    videooptions->setLayout(videobuttonlayout);


    audiooptions->setVisible(false);
    videooptions->setVisible(false);

    owt->addWidget(audiooptions);
    audiobar->setLayout(audiobarLayout);
    owt->addWidget(audiobar);
    owt->addWidget(videooptions);
    videobar->setLayout(videobarLayout);
    owt->addWidget(videobar);

    setLayout(owt);
}

//void Scrub::mouseDoubleClickEvent (QMouseEvent * event)
//{
//    if (event->button() == Qt::LeftButton ){
//        toggleExpanded();
//    }
//}

void Scrub::addAudio()
{
    QString name =QString::fromStdString("Aud ") ;
    Icon * audio = new Icon(QString(name));
    audio->setStyleSheet("QLabel { background-color : red }");
    QObject::connect(audio,SIGNAL(doubleclicked()),this,SLOT(toggleExpandedAudio()));
    audioslayout->addWidget(audio);
}

void Scrub::addVideo()
{
    QString name =QString::fromStdString("Vid ");
    Icon * video = new Icon(QString(name));
    video->setStyleSheet("QLabel { background-color : blue }");
    QObject::connect(video,SIGNAL(doubleclicked()),this,SLOT(toggleExpandedVideo()));
    videoslayout->addWidget(video);
}

void Scrub::toggleExpandedAudio()
{
    audiooptions->setVisible(!audiooptions->isVisible());
    videooptions->setVisible(false);
}

void Scrub::toggleExpandedVideo()
{
    videooptions->setVisible(!videooptions->isVisible());
    audiooptions->setVisible(false);
}


