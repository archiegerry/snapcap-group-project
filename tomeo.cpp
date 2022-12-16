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
#include <QMediaPlayer>
#include <QtWidgets>
#include <QtGui>
#include <QTranslator>

#include "scrub.h"
#include "headerButtons.h"
#include "settings_page.h"
#include "the_player.h"
#include "toolbox.h"
#include "tool.h"

int main(int argc, char *argv[]) {

    // let's just check that Qt is operational first
	qDebug() << "Qt version: " << QT_VERSION_STR << Qt::endl;

    // create the Qt Application
    QApplication app(argc, argv);

	// create the Translator
	QTranslator translator;
	QString lang = "translator/the-fra.qm";
	bool result = translator.load(lang);
	app.installTranslator(&translator);

    // the widget that will show the video
	QVideoWidget *videoWidget = new QVideoWidget;

    // the QMediaPlayer which controls the playback
    ThePlayer *player = new ThePlayer;
    player->setVideoOutput(videoWidget);

    // create the main window and layout
    QWidget window;

	QVBoxLayout *screen = new QVBoxLayout();
	QHBoxLayout *footer = new QHBoxLayout();

	headerButtons *header = new headerButtons();
	Scrub *scrubber = new Scrub(std::string(argv[1]));
    QObject::connect(scrubber, &Scrub::jumpto, player, &ThePlayer::jumpTo); // when clicked, tell the player to play.
    QObject::connect(player, &ThePlayer::ended, scrubber, &Scrub::nextVideo);

	QPushButton *settingsButton = header->getSettings();

	// settings
	SettingsPage *settingsPage = new SettingsPage(&window, settingsButton);

	// lay out media controls
	QHBoxLayout *mediaControls = new QHBoxLayout();

	QPushButton *rewindButton = new QPushButton;
	QPushButton *skipButton = new QPushButton;
	QPushButton *pauseButton = new QPushButton;
	QPushButton *playButton = new QPushButton;

	QSlider *volSlider = new QSlider(Qt::Horizontal);
    volSlider->setRange(0,100);
    volSlider->setFixedHeight(100);
    volSlider->setValue(50);

    volSlider->connect(volSlider, &QSlider::valueChanged, player, &QMediaPlayer::setVolume);

    mediaControls->addWidget(rewindButton);
    mediaControls->addWidget(pauseButton);
    mediaControls->addWidget(playButton);
    mediaControls->addWidget(skipButton);
    mediaControls->addWidget(volSlider);
    mediaControls->setSpacing(0);

    playButton->setIcon(QIcon(":/play.png"));
    playButton->connect(playButton, &QPushButton::clicked, player, &QMediaPlayer::play);
    pauseButton->setIcon(QIcon(":/pause.png"));
    pauseButton->connect(pauseButton, &QPushButton::clicked, player, &QMediaPlayer::pause);
    rewindButton->setIcon(QIcon(":/backwards.png"));
    rewindButton->connect(rewindButton, &QPushButton::clicked, player, &ThePlayer::toStart);
    skipButton->setIcon(QIcon(":/fast_forward.png"));
    skipButton->connect(skipButton, &QPushButton::clicked, player, &ThePlayer::toEnd);

	playButton->setFixedHeight(20);
	pauseButton->setFixedHeight(20);
	rewindButton->setFixedHeight(20);
	skipButton->setFixedHeight(20);
	volSlider->setFixedHeight(20);

    mediaControls->setStretch(0,1);
    mediaControls->setStretch(1,1);
    mediaControls->setStretch(2,1);
    mediaControls->setStretch(3,1);
    mediaControls->setStretch(4,1);

	// toolbox
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
    screen->addLayout(footer);


    // showtime!
    window.show();

    // wait for the app to terminate
    return app.exec();
}
