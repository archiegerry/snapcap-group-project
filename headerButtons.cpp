#include "headerButtons.h"

#include <QGridLayout>

headerButtons::headerButtons()
{
    setWindowTitle("2811: Coursework 1");

    createHeader();
}

void headerButtons::createHeader()
{
    QHBoxLayout *header = new QHBoxLayout();

    QPushButton * newProject = new QPushButton("");
    QPushButton * loadProject = new QPushButton("");
    settings = new QPushButton("");

    newProject -> setFixedSize(QSize(50,50));
    settings -> setFixedSize(QSize(50,50));
    loadProject -> setFixedSize(QSize(50,50));

    newProject -> setIcon(QIcon(":/new.png"));
    newProject -> setIconSize(QSize(50,50));
    settings -> setIcon(QIcon(":/settings.png"));
    settings -> setIconSize(QSize(50,50));
    loadProject -> setIcon(QIcon(":/load.png"));
    loadProject -> setIconSize(QSize(50,50));

    header ->addWidget(settings);
	header ->addWidget(newProject);
	header ->addWidget(loadProject);

    setLayout(header);

}
