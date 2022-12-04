#ifndef NEWMEDIA_H
#define NEWMEDIA_H

#include <QWidget>
#include <QPushButton>

class newMedia : public QWidget
{
    Q_OBJECT

public:
    newMedia();

protected:
    void createButtons();

};

#endif // NEWMEDIA_H
