#include "headerButtons.h"

#include <QGridLayout>

headerButtons::headerButtons()
{
    setWindowTitle("2811: Coursework 1");
    setMaximumSize(1280, 720);

    createHeader();
}

void headerButtons::createHeader()
{
    QHBoxLayout *header = new QHBoxLayout();

    QPushButton * newProject = new QPushButton("New");
    QPushButton * loadProject = new QPushButton("Load");
    QPushButton * settings = new QPushButton("Settings");

    newProject -> setFixedSize(QSize(60,30));
    settings -> setFixedSize(QSize(100,30));
    loadProject -> setFixedSize(QSize(60,30));

    header ->addWidget(newProject,2);
    header ->addWidget(settings,6);
    header ->addWidget(loadProject,2);

    setLayout(header);

}
