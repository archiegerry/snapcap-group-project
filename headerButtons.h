#ifndef HEADERBUTTONS_H
#define HEADERBUTTONS_H

#include <QWidget>
#include <QPushButton>


class headerButtons : public QWidget
{
    Q_OBJECT

public:
    headerButtons();
	QPushButton *getSettings(){ return settings; }


protected:
    void createHeader();
	QPushButton *settings;

};

#endif // HEADERBUTTONS_H
