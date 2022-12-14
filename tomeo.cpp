//    ______
//   /_  __/___  ____ ___  ___  ____
//    / / / __ \/ __ `__ \/ _ \/ __ \
//   / / / /_/ / / / / / /  __/ /_/ /
//  /_/  \____/_/ /_/ /_/\___/\____/
//              video for sports enthusiasts...
//
//

#include <iostream>
#include <QApplication>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QMediaPlaylist>
#include <string>
#include <vector>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtCore/QFileInfo>
#include <QtWidgets/QFileIconProvider>
#include <QDesktopServices>
#include <QImageReader>
#include <QMessageBox>
#include <QtCore/QDir>
#include <QtCore/QDirIterator>
#include "the_player.h"
#include "the_button.h"
#include <QtWidgets>
#include <QtGui>

#include "scrub.h"
#include "headerButtons.h"
#include "newMedia.h"
#include "settings_page.h"
#include "the_player.h"
#include "toolbox.h"
#include "tool.h"

// read in videos and thumbnails to this directory
std::vector<TheButtonInfo> getInfoIn (std::string loc) {

    std::vector<TheButtonInfo> out =  std::vector<TheButtonInfo>();
    QDir dir(QString::fromStdString(loc) );
    QDirIterator it(dir);

    while (it.hasNext()) { // for all files

        QString f = it.next();

            if (f.contains("."))

#if defined(_WIN32)
            if (f.contains(".wmv"))  { // windows
#else
            if (f.contains(".mp4") || f.contains("MOV"))  { // mac/linux
#endif

            QString thumb = f.left( f .length() - 4) +".png";
            if (QFile(thumb).exists()) { // if a png thumbnail exists
                QImageReader *imageReader = new QImageReader(thumb);
                    QImage sprite = imageReader->read(); // read the thumbnail
                    if (!sprite.isNull()) {
                        QIcon* ico = new QIcon(QPixmap::fromImage(sprite)); // voodoo to create an icon for the button
                        QUrl* url = new QUrl(QUrl::fromLocalFile( f )); // convert the file location to a generic url
                        out . push_back(TheButtonInfo( url , ico  ) ); // add to the output list
                    }
                    else
                        qDebug() << "warning: skipping video because I couldn't process thumbnail " << thumb << endl;
            }
            else
                qDebug() << "warning: skipping video because I couldn't find thumbnail " << thumb << endl;
        }
    }

    return out;
}


int main(int argc, char *argv[]) {

    // let's just check that Qt is operational first
    qDebug() << "Qt version: " << QT_VERSION_STR << endl;

    // create the Qt Application
    QApplication app(argc, argv);

    // collect all the videos in the folder
    std::vector<TheButtonInfo> videos;

    if (argc == 2)
        videos = getInfoIn( std::string(argv[1]) );

    if (videos.size() == 0) {

        const int result = QMessageBox::information(
                    NULL,
                    QString("Tomeo"),
                    QString("no videos found! Add command line argument to \"quoted\" file location."));
        exit(-1);
    }

    // the widget that will show the video
    QVideoWidget *videoWidget = new QVideoWidget;

    // the QMediaPlayer which controls the playback
    ThePlayer *player = new ThePlayer;
    player->setVideoOutput(videoWidget);

    // a row of buttons
    QWidget *buttonWidget = new QWidget();
    // a list of the buttons
    std::vector<TheButton*> buttons;
    // the buttons are arranged horizontally
    QHBoxLayout *layout = new QHBoxLayout();
    buttonWidget->setLayout(layout);


    // create the four buttons
    for ( int i = 0; i < 4; i++ ) {
        TheButton *button = new TheButton(buttonWidget);
        button->connect(button, SIGNAL(jumpTo(TheButtonInfo* )), player, SLOT (jumpTo(TheButtonInfo*))); // when clicked, tell the player to play.
        buttons.push_back(button);
        layout->addWidget(button);
        button->init(&videos.at(i));
    }

    // tell the player what buttons and videos are available
    player->setContent(&buttons, & videos);

    // create the main window and layout
    QWidget window;

    QVBoxLayout *screen = new QVBoxLayout();
    QHBoxLayout *footer = new QHBoxLayout();

    headerButtons * header = new headerButtons();
    Scrub * scrubber = new Scrub();
    newMedia * addMedia = new newMedia();

    QPushButton * settingsButton = header->getSettings();

    SettingsPage * settingsPage = new SettingsPage(&window, settingsButton);

    QHBoxLayout *mediaControls = new QHBoxLayout();

    QPushButton* rewindButton = new QPushButton;
    QPushButton* skipButton = new QPushButton;
    QPushButton* pauseButton = new QPushButton;
    QPushButton* playButton = new QPushButton;

    mediaControls->addWidget(rewindButton);
    mediaControls->addWidget(pauseButton);
    mediaControls->addWidget(playButton);
    mediaControls->addWidget(skipButton);
    mediaControls->setSpacing(0);

    playButton->setIcon(QIcon(":/play.png"));
    playButton->connect(playButton, &QPushButton::clicked, player, &QMediaPlayer::play);
    pauseButton->setIcon(QIcon(":/pause.png"));
    pauseButton->connect(pauseButton, &QPushButton::clicked, player, &QMediaPlayer::pause);
    rewindButton->setIcon(QIcon(":/backwards.png"));
    rewindButton->connect(rewindButton, &QPushButton::clicked, player, &ThePlayer::toStart);
    skipButton->setIcon(QIcon(":/fast_forward.png"));
    skipButton->connect(skipButton, &QPushButton::clicked, player, &ThePlayer::toEnd);

    playButton -> setFixedHeight(20);
    pauseButton -> setFixedHeight(20);
    rewindButton -> setFixedHeight(20);
    skipButton -> setFixedHeight(20);

    mediaControls->setStretch(0,1);
    mediaControls->setStretch(1,1);
    mediaControls->setStretch(2,1);
    mediaControls->setStretch(3,1);

    Tool textTool("Text", QIcon(":/draw-text.svg"));
    Tool filter("Filter", QIcon(":/draw-filter.svg"));
    ToolBox *tb = new ToolBox(&window);
    tb->addTool(textTool);
    tb->addBreak();
    tb->addTool(filter);
    tb->addBreak();

    window.setLayout(screen);
    window.setWindowTitle("Tomeo");
    window.setMinimumSize(375, 812);     //Size of an iPhone X's viewport

    // add the video and the buttons to the top level widget
    screen->addWidget(header);
    screen->addWidget(videoWidget);
    screen->addLayout(mediaControls);
    footer->addWidget(scrubber, 9);
    footer->addWidget(addMedia, 1);
    screen->addLayout(footer);

    // showtime!
    window.show();

    // wait for the app to terminate
    return app.exec();
}
