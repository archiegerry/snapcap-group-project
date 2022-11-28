#ifndef PROTOTYPELAYOUT_H
#define PROTOTYPELAYOUT_H

#include <QtGui>
#include <QList>
#include <QLayout>

class prototypeLayout : public QLayout
{
public:
    prototypeLayout(): QLayout() {};
    ~prototypeLayout();

    void setDimensions(const QRect &rectangle);

private:
    QList<QLayoutItem*> layoutList;

};

#endif // PROTOTYPELAYOUT_H
