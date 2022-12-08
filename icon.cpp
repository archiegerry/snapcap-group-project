#include "icon.h"
#include "QHBoxLayout"
#include <QDebug>
#include <QIcon>




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

void Icon::init(IconInfo* i) {
    setPixmap( i->icon->pixmap(100) );
    setScaledContents(true);
    info =  i;
    isInitiated=true;
}

void Icon::mousePressEvent(QMouseEvent *event)
{
    //bring to front
    raise();
    if (event->buttons() == Qt::LeftButton){
        //find start position global to screen
        startx=geometry().x();
        globalstartx = mapToGlobal(parentWidget()->pos()).x()-11;
        mousestartx=event->globalX();
        qDebug() << startx << mousestartx;
    }
}

void Icon::mouseMoveEvent(QMouseEvent *event)
{
    if (!(event->buttons() == Qt::LeftButton)) return;
    x=startx+event->globalX()-mousestartx;
    if(!(geometry().x()<parentWidget()->geometry().x() & x<0))
        move(x,geometry().y());
}

void Icon::mouseReleaseEvent(QMouseEvent *event)
{

    //qDebug() << "icon: " << * info -> url;

    //if not drag, play video
    if (event->globalX()==mousestartx && isInitiated){
        emit jumpTo(info);
        return;
    }

    //parent layout
    QHBoxLayout* layout = qobject_cast<QHBoxLayout*>(parentWidget()->layout());

    float mousex=event->globalX()-globalstartx;


    float boxsize=width();
    int difference=int((mousex)/boxsize) - 1*(mousex<0 && layout->indexOf(this)>0);
    int newIndex=layout->indexOf(this) + int(difference);
    if (newIndex < 0) newIndex = 0;



    qDebug() << globalstartx << mousex << boxsize << difference;

    layout->removeWidget(this);
    //if dragged over play button
    if (newIndex > layout->count()){
        delete this;
    }
    else{
        layout->insertWidget(newIndex,this);
    }

}

//void Icon::doubleclicked(){}

void Icon::mouseDoubleClickEvent(QMouseEvent *event)
{
    if( event->button() & Qt::LeftButton)
    {
        emit doubleclicked();
    }
}



