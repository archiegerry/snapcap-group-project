//
// Created by twak on 11/11/2019.
//

#ifndef CW2_THE_PLAYER_H
#define CW2_THE_PLAYER_H


#include <QApplication>
#include <QMediaPlayer>
#include "icon.h"
#include <vector>
#include <QTimer>

class ThePlayer : public QMediaPlayer {

Q_OBJECT

private:
    std::vector<IconInfo>* infos;
    std::vector<Icon*>* buttons;
    //QTimer* mTimer;
    long updateCount = 0;

public:
    ThePlayer() : QMediaPlayer(NULL) {
        setVolume(0); // be slightly less annoying
        connect (this, SIGNAL (stateChanged(QMediaPlayer::State)), this, SLOT (playStateChanged(QMediaPlayer::State)) );
    }

    // all buttons have been setup, store pointers here
    void setContent(std::vector<Icon*>* b, std::vector<IconInfo>* i);

private slots:

    void playStateChanged (QMediaPlayer::State ms);

public slots:

    // start playing this IconInfo
    void jumpTo (IconInfo* button);
};

#endif //CW2_THE_PLAYER_H
