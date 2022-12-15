//
// Created by twak on 11/11/2019.
//

#include "the_player.h"


void ThePlayer::playStateChanged (QMediaPlayer::State ms) {
    switch (ms) {
        case QMediaPlayer::State::StoppedState:
            play(); // starting playing again...
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
	qint64 duration = QMediaPlayer::duration();
	setPosition(duration-1);
	pause();
}

void ThePlayer::setVol(int volume) {
    setVolume(volume);
}
