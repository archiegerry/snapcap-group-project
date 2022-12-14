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
    Scrub(std::string loc);
    int playingIndex;

private slots:
    void toggleExpandedVideo();
    void toggleExpandedAudio();

    void addAudio();
    void addVideo();

public slots:
    void nextVideo();
    void jumptochain(IconInfo* info, int index);

signals:
    void jumpto(IconInfo* info);

private:
    std::vector<QPushButton> videobuttons=std::vector<QPushButton>(8);
    std::vector<QPushButton> audiobuttons=std::vector<QPushButton>(8);
    QWidget * audiooptions = new QWidget;
    QWidget * videooptions = new QWidget;
    QHBoxLayout * videoslayout = new QHBoxLayout();
    QHBoxLayout * audioslayout = new QHBoxLayout();
    std::vector<IconInfo> Iconinfos;

protected:
    void createWidgets();
};

#endif // SCRUB_H
