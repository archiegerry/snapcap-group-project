#ifndef ICON_H
#define ICON_H

#include <QLabel>
#include <QMouseEvent>


class Icon: public QLabel
{
    //for signals and slots
    Q_OBJECT

    //global variables for moving
    int x, startx, globalstartx, mousestartx;
signals:
    void doubleclicked();
private slots:
    void mouseDoubleClickEvent(QMouseEvent *event);
public:
    Icon();
    Icon(QString name);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *);



};
#endif // ICON_H
