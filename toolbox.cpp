#include "toolbox.h"
#include "tool.h"

#include <QPainter>
#include <QPainterPath>
#include <QPaintEvent>
#include <QTextItem>


ToolBox::ToolBox(QWidget *parent) :
    QWidget(parent), m_activated(-1), m_padding(10), m_buttonSize(40, 40)
{
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
}

void ToolBox::paintEvent(QPaintEvent *event)
{
    QPainter gc(this);
    gc.setRenderHint(QPainter::Antialiasing);

    QPoint tempTopLeft = event->rect().topLeft();
    QColor highlightedBack(86, 128, 194);
    QColor back(49, 49, 49);

    QPoint topLeft = tempTopLeft;
    m_toolRects.clear();

    for(int i=0; i<m_breaks.count(); i++){
        int count = m_breaks[i] + 1;
        if(i>0){
            count = count - m_breaks[i-1] - 1;
        }
        int h = m_buttonSize.height() * (count);
        QRect backRect(topLeft, QSize(m_buttonSize.width(), h));
        QPainterPath p;
        p.addRoundedRect(backRect, 3, 3);
        gc.fillPath(p, back);
        topLeft += QPoint(0, 2+h);
    }

    int breakCount = 0;
    topLeft = tempTopLeft;

    for(int i=0;i<m_tools.count();i++){
        QRect toolRect(topLeft, m_buttonSize);
        QPainterPath path;
        path.addRoundedRect(toolRect, 3, 3);

        if(i == m_activated){
            gc.fillPath(path, highlightedBack);
        }

        QRect iconRect = toolRect.adjusted(m_padding, m_padding, -m_padding, -m_padding);
        m_tools[i].icon().paint(&gc, iconRect);
        m_toolRects.push_back(toolRect);
        topLeft += QPoint(0, m_buttonSize.height());

        if(breakCount < m_breaks.count() && m_breaks[breakCount] == i){
            topLeft += QPoint(0, 2);
            breakCount++;
        }

    }

    int w = m_buttonSize.width();
    int h = topLeft.y() + m_buttonSize.height() + 2;

    resize(w, h);
}

void ToolBox::addTool(Tool t)
{
    m_tools.push_back(t);
}

void ToolBox::addBreak()
{
    m_breaks.push_back(m_tools.count()-1);
}

void ToolBox::mousePressEvent(QMouseEvent *event)
{
    QPoint pos = event->pos();
    m_lastMousePos = pos;

    if(event->button() != Qt::LeftButton)
        return;

    for(int i=0; i<m_tools.count(); i++){
        if(m_toolRects[i].contains(pos)){
            m_activated = i;
            update();
            return;
        }
    }
}
