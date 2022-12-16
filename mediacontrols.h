#ifndef MEDIACONTROLS_H
#define MEDIACONTROLS_H

#include <the_player.h>

#include <QWidget>
#include <QPushButton>

class mediaControls : public QWidget
{
    Q_OBJECT

public:
    mediaControls();
    void connectButtons(QPushButton * button, ThePlayer *player, int signal);

    QPushButton* getRewind() { return rewindButton;}
    QPushButton* getSkip() { return skipButton;}
    QPushButton* getPause() { return pauseButton;}
    QPushButton* getPlay() { return playButton;}


protected:
    void createMediaControls();
    QPushButton* rewindButton;
    QPushButton* skipButton;
    QPushButton* pauseButton;
    QPushButton* playButton;

};

#endif // MEDIACONTROLS_H
