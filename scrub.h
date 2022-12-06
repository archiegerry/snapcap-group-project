#ifndef SCRUB_H
#define SCRUB_H

#include "icon.h"

#include <QWidget>
#include <vector>
#include <QPushButton>
#include <QObject>
#include <QHBoxLayout>

const int NO_OF_VIDEOOPTIONS=8;
const int NO_OF_AUDIOOPTIONS=8;

class Scrub : public QWidget
{
    //for signals and slots
    Q_OBJECT

public:
    Scrub();

private slots:

    void toggleExpandedVideo();
    void toggleExpandedAudio();
    //void mouseDoubleClickEvent (QMouseEvent * event);

private slots:
    //void toggleExpanded();
    void addAudio();
    void addVideo();

private:
    std::vector<QPushButton> videobuttons=std::vector<QPushButton>(8);
    std::vector<QPushButton> audiobuttons=std::vector<QPushButton>(8);
    QWidget * audiooptions = new QWidget;
    QWidget * videooptions = new QWidget;
    QHBoxLayout * videoslayout = new QHBoxLayout();
    QHBoxLayout * audioslayout = new QHBoxLayout();
protected:
    void createWidgets();
};

#endif // SCRUB_H
