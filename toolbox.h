#ifndef TOOLBOX_H
#define TOOLBOX_H

#include <QWidget>
//#include <QTimer>
#include <QMenu>
#include <QAction>

#include "tool.h"

class ToolBox : public QWidget
{
    Q_OBJECT

public:
    explicit ToolBox(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

    void addTool(Tool t);
    void addBreak();

private:
    int m_activated, m_padding;
    QSize m_buttonSize;
    QVector<QRect> m_toolRects;
    QVector<Tool> m_tools;
    QVector<int> m_breaks;
    QPoint m_lastMousePos;
};

#endif // TOOLBOX_H
