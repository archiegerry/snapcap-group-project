//   ____
//  / ___| _ __   __ _ _ __   ___ __ _ _ __
//  \___ \| '_ \ / _` | '_ \ / __/ _` | '_ \
//   ___) | | | | (_| | |_) | (_| (_| | |_) |
//  |____/|_| |_|\__,_| .__/ \___\__,_| .__/
//                    |_|             |_|
//              "nah, that's cap"
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

#include "icon.h"
#include "scrub.h"
#include "headerButtons.h"
#include "newMedia.h"
#include "settings_page.h"


int main(int argc, char *argv[]) {

    // let's just check that Qt is operational first
    qDebug() << "Qt version: " << QT_VERSION_STR << endl;

    // create the Qt Application
    QApplication app(argc, argv);

    // the widget that will show the video
    QVideoWidget *videoWidget = new QVideoWidget;

    // the QMediaPlayer which controls the playback
    ThePlayer *player = new ThePlayer;
    player->setVideoOutput(videoWidget);

    // create the main window and layout
    QWidget window;

    QVBoxLayout *screen = new QVBoxLayout();
    QHBoxLayout *footer = new QHBoxLayout();

    headerButtons * header = new headerButtons();
    Scrub * scrub = new Scrub(std::string(argv[1]));
    QObject::connect(scrub, &Scrub::jumptochain, player, &ThePlayer::jumpTo); // when clicked, tell the player to play.

    newMedia * mediaButtons = new newMedia();

    QPushButton * settingsButton = header->getSettings();

    SettingsPage * settingsPage = new SettingsPage(&window, settingsButton);

    window.setLayout(screen);
    window.setWindowTitle("Snapcap");
    window.setMinimumSize(375, 812);     //Size of an iPhone X's viewport

    // add the video and the buttons to the top level widget
    screen->addWidget(header);
    screen->addWidget(videoWidget);
    footer->addWidget(scrub, 9);
    //footer->addWidget(mediaButtons, 1);
    screen->addLayout(footer);

    // showtime!
    window.show();

    // wait for the app to terminate

    return app.exec();
}
