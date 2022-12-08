//
// Created by twak on 11/11/2019.
//


#include "the_player.h"

// all buttons have been setup, store pointers here
void ThePlayer::setContent(std::vector<Icon*>* b, std::vector<IconInfo>* i) {
    buttons = b;
    infos = i;
    jumpTo(buttons -> at(0) -> info);
}

void ThePlayer::playStateChanged (QMediaPlayer::State ms) {
    switch (ms) {
        case QMediaPlayer::State::StoppedState:
            play(); // starting playing again...
            break;
    default:
        break;
    }
}

void ThePlayer::jumpTo (IconInfo* info) {
    qDebug() << "player:" << info->url ;
    setMedia( * info -> url);
    play();
}
