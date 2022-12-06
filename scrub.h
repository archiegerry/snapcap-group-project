#ifndef SCRUB_H
#define SCRUB_H

#include <QWidget>
#include <vector>
#include <QPushButton>

const int NO_OF_VIDEOOPTIONS=8;
const int NO_OF_AUDIOOPTIONS=8;

class Scrub : public QWidget
{
    //for signals and slots
    Q_OBJECT

public:
    Scrub();
    //void mouseDoubleClickEvent (QMouseEvent * event);

private slots:
    void toggleExpandedVideo();
    void toggleExpandedAudio();

private:
    std::vector<QPushButton> videobuttons=std::vector<QPushButton>(8);
    std::vector<QPushButton> audiobuttons=std::vector<QPushButton>(8);
    QWidget * audiooptions = new QWidget;
    QWidget * videooptions = new QWidget;

protected:
    void createWidgets();
};

#endif // SCRUB_H
