#include "mediacontrols.h"

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>

mediaControls::mediaControls()
{
    setWindowTitle("2811: Coursework 1");

    createMediaControls();
}

void mediaControls::connectButtons(QPushButton * button, ThePlayer *player, int signal)
{
    button->connect(button, &QPushButton::clicked(), player, &QMediaPlayer::play());
}

void mediaControls::createMediaControls()
{
    QHBoxLayout *mediaControls = new QHBoxLayout();

    rewindButton = new QPushButton("");
    skipButton = new QPushButton("");
    pauseButton = new QPushButton("");
    playButton = new QPushButton("");

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

}


