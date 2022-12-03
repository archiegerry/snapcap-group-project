#include "icon.h"
#include "QHBoxLayout"


Icon::Icon() : QLabel()
{
    Icon("");
}

Icon::Icon(QString name) : QLabel()
{
    setText(name);

    setMinimumHeight(35);
    setMouseTracking(true);

}

void Icon::mousePressEvent(QMouseEvent *event)
{
    //bring to front
    raise();
    if (event->buttons() == Qt::LeftButton){
        startx = geometry().x();
        mousestartx=event->globalX();
    }
}

void Icon::mouseMoveEvent(QMouseEvent *event)
{
    if (!(event->buttons() == Qt::LeftButton)) return;
    x=event->globalX()-mousestartx+startx;
    if(!(geometry().x()<parentWidget()->geometry().x() & x<0))
        move(x,geometry().y());
}

void Icon::mouseReleaseEvent(QMouseEvent *event)
{
    QHBoxLayout* layout = qobject_cast<QHBoxLayout*>(parentWidget()->layout());

    float mousex=event->globalX()-parentWidget()->x();
    float boxsize=parentWidget()->width()/layout->count();
    int newIndex=int(mousex/boxsize);

    layout->removeWidget(this);
    layout->insertWidget(newIndex,this);

    move(x,y());
}

//void Icon::doubleclicked(){}

void Icon::mouseDoubleClickEvent(QMouseEvent *event)
{
    if( event->button() & Qt::LeftButton)
    {
        emit doubleclicked();
    }
}

