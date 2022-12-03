#ifndef HEADERBUTTONS_H
#define HEADERBUTTONS_H

#include <QWidget>
#include <QPushButton>


class headerButtons : public QWidget
{
    Q_OBJECT

public:
    headerButtons();


protected:
    void createHeader();

};

#endif // HEADERBUTTONS_H
