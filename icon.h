#ifndef ICON_H
#define ICON_H

#include <QLabel>
#include <QMouseEvent>

//information about each icon
class IconInfo {

public:
    QUrl* url; // video file to play
    QIcon* icon; // icon to display

    IconInfo ( QUrl* url, QIcon* icon) : url (url), icon (icon) {}
};


class Icon: public QLabel
{
    //for signals and slots
    Q_OBJECT

    //global variables for moving
    int x, startx, globalstartx, mousestartx;


signals:
    void doubleclicked();
    void jumpTo(IconInfo* info, int index);

private slots:
    void mouseDoubleClickEvent(QMouseEvent *event);
public:
    IconInfo * info;

    Icon();
    Icon(QString name);
    void init(IconInfo * i);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *);
    bool isInitiated=false;
    void play();



};
#endif // ICON_H
