//
// Created by twak on 11/11/2019.
//

#include "the_player.h"


void ThePlayer::playStateChanged (QMediaPlayer::State ms) {
    switch (ms) {
        case QMediaPlayer::State::StoppedState:
            if (mediaStatus() == QMediaPlayer::EndOfMedia){
                emit ended();
            }
            //play(); // starting playing again...
        break;
    default:
        break;
    }
}

void ThePlayer::jumpTo (IconInfo* button) {
    setMedia( * button -> url);
    play();
}

void ThePlayer::toStart() {
    setPosition(0);
    pause();
}

void ThePlayer::toEnd() {
    setPosition(QMediaPlayer::duration()-1);
}
