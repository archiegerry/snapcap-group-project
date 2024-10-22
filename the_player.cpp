//
// Created by twak on 11/11/2019.
//

#include "the_player.h"


void ThePlayer::playStateChanged (QMediaPlayer::State ms) {
    switch (ms) {
        case QMediaPlayer::State::StoppedState:
            play(); // starting playing again...
            break;
            if (mediaStatus() == QMediaPlayer::EndOfMedia){
                emit ended();
            }

        break;
    default:
        break;
    }
}

void ThePlayer::jumpTo (IconInfo* button) {
    setMedia( * button -> url);
    currentMedia=button;
    play();
}

void ThePlayer::toStart() {
    // if more than 1 sec in, go to start
    if (position()>1000){
        jumpTo(currentMedia);
    // if less than 1 sec in, skip to previous video
    }else{
        emit previous();
    }
    play();
}

void ThePlayer::toEnd() {
    setPosition(QMediaPlayer::duration()-1);
}
