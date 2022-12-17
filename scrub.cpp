#include "scrub.h"
#include <QGridLayout>
#include <QLabel>
#include <string>
#include <QDirIterator>
#include <QImageReader>
#include <QDebug>
#include <QFileDialog>


// read in videos and thumbnails to this directory
IconInfo * getInfo (QString f) {


    QString thumb = f.left( f .length() - 4) +".png";
    QIcon* ico = new QIcon();
    if (QFile(thumb).exists()) { // if a png thumbnail exists
        QImageReader *imageReader = new QImageReader(thumb);
        QImage sprite = imageReader->read(); // read the thumbnail
        if (!sprite.isNull()) {
            ico->addPixmap(QPixmap::fromImage(sprite)); // voodoo to create an icon for the button
            //QUrl* url = new QUrl(QUrl::fromLocalFile( f )); // convert the file location to a generic url
            //return new IconInfo(url,ico);
            //out . push_back(IconInfo( url , ico  ) ); // add to the output list
        }
        else
            qDebug() << "warning: couldn't process thumbnail " << thumb << Qt::endl;
    }
    else
        qDebug() << "warning: couldn't find thumbnail " << thumb << Qt::endl;
    QUrl* url = new QUrl(QUrl::fromLocalFile( f )); // convert the file location to a generic url
    return new IconInfo(url,ico);

}

Scrub::Scrub(std::string location)
{
    loc=location;
    createWidgets();
}


void Scrub::createWidgets()
{
    //whole scrub
    QVBoxLayout * owt = new QVBoxLayout();

    //icons and add
    QWidget * audiobar = new QWidget();
    QWidget * videobar = new QWidget();

    QHBoxLayout * audiobarLayout = new QHBoxLayout();
    QHBoxLayout * videobarLayout = new QHBoxLayout();

    //icons
    QWidget * videos= new QWidget;
    QWidget * audios= new QWidget;

//    for (int i=0;i<4;i++){

//        addAudio();
//    }
//    for (int i=0;i<4;i++){
//        addVideo();
//    }

	// videoslayout and audioslayout are global
    audios->setLayout(audioslayout);
    audiobarLayout->addWidget(audios);
    videos->setLayout(videoslayout);
    videobarLayout->addWidget(videos);

	// buttons to add new icons
    QPushButton * addaudiobutton = new QPushButton();
    addaudiobutton->setMaximumSize(25,25);
    addaudiobutton->setIcon(QIcon(":/plus.png"));
	// add audio
    QObject::connect(addaudiobutton,SIGNAL(clicked()),this,SLOT(addAudio()));
    audiobarLayout->addWidget(addaudiobutton);
    QPushButton * addvideobutton = new QPushButton();
    addvideobutton->setMaximumSize(25,25);
    addvideobutton->setIcon(QIcon(":/plus.png"));
	// add video
    QObject::connect(addvideobutton,SIGNAL(clicked()),this,SLOT(addVideo()));
    videobarLayout->addWidget(addvideobutton);

	// options and effects
    QGridLayout * audiobuttonlayout = new QGridLayout();
    QGridLayout * videobuttonlayout = new QGridLayout();
    audiobuttons.at(0).setText("CROP");
    audiobuttons.at(1).setText("CUT");
    audiobuttons.at(2).setText("SPLICE");
    audiobuttons.at(3).setText("EQ");

    videobuttons.at(0).setText("CROP");
    videobuttons.at(1).setText("CUT");
    videobuttons.at(2).setText("SPLICE");
    videobuttons.at(3).setText("FX");


    //add options and effects
    for (int i=0;i<NO_OF_AUDIOOPTIONS;i++){
        audiobuttons.at(i).setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Minimum);
        audiobuttons.at(i).setStyleSheet("background-color: mediumturquoise");
        audiobuttonlayout->addWidget(&audiobuttons.at(i),i/4,i%4);
    }
    audiooptions->setLayout(audiobuttonlayout);

    for (int i=0;i<NO_OF_VIDEOOPTIONS;i++){
        videobuttons.at(i).setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Minimum);
        videobuttons.at(i).setStyleSheet("background-color: mediumturquoise");
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

void Scrub::addAudio()
{
    QString name =QString::fromStdString(" AUDIO ") ;
    Icon * audio = new Icon(QString(name));
    audio->setStyleSheet("QLabel { background-color : mediumturquoise }");
    QObject::connect(audio,SIGNAL(doubleclicked()),this,SLOT(toggleExpandedAudio()));
    audioslayout->addWidget(audio);
}

void Scrub::addVideo()
{

    QString name =QString::fromStdString("Vid ");
    Icon * video = new Icon(QString(name));
    video->setStyleSheet("QLabel { background-color : blue }");
    QObject::connect(video,SIGNAL(doubleclicked()),this,SLOT(toggleExpandedVideo()));
    QObject::connect(video,&Icon::jumpTo, this, &Scrub::jumptochain); // when clicked, tell the player to play.

    QString filename = QFileDialog::getOpenFileName(this, QObject::tr("Which Video?"),QObject::tr(loc.c_str()));

    video->init(getInfo(filename));
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

void Scrub::nextVideo()
{
    if (playingIndex<videoslayout->count()-1){

        playingIndex+=1;
        Icon* nexticon=static_cast<Icon*>(videoslayout->itemAt(playingIndex)->widget());
        nexticon->play();
        jumptochain(nexticon->info,playingIndex);
    }
}

void Scrub::previousVideo()
{
    if (playingIndex>0){

        playingIndex-=1;
        Icon* nexticon=static_cast<Icon*>(videoslayout->itemAt(playingIndex)->widget());
        nexticon->play();
        jumptochain(nexticon->info,playingIndex);
    }
}

void Scrub::jumptochain(IconInfo * info, int index)
{
    playingIndex=index;
    //qDebug() << playingIndex;
    emit jumpto(info);
}
