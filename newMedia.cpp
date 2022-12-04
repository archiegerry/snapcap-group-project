#include "newMedia.h"
#include <QGridLayout>


newMedia::newMedia()
{
    setWindowTitle("2811: Coursework 1");
    setMaximumSize(1280, 720);

    createButtons();
}

void newMedia::createButtons()
{
    QVBoxLayout *verticalOrientation = new QVBoxLayout;

    QPushButton * newVideo = new QPushButton("+");
    QPushButton * newAudio = new QPushButton("+");

    newVideo -> setFixedSize(QSize(40,40));
    newAudio -> setFixedSize(QSize(40,40));

    verticalOrientation->addWidget(newAudio);
    verticalOrientation->addWidget(newVideo);

    setLayout(verticalOrientation);

}
