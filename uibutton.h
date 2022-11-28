#ifndef UIBUTTON_H
#define UIBUTTON_H

#include <QPushButton>
#include <QUrl>

class UIButtonInfo
{
    public:
    QIcon *buttonIcon;

    UIButtonInfo( QIcon *buttonIcon );
};

class UIButton : public QPushButton
{
    Q_OBJECT

public:
    UIButtonInfo *info;
    UIButton(QWidget *parent) : QPushButton(parent)
    {

    }

    void init(UIButtonInfo *info);

private:

};

#endif // UIBUTTON_H
