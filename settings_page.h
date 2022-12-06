#ifndef SETTINGS_PAGE_H
#define SETTINGS_PAGE_H
#include <QWidget>
// Forward declaration
class QLabel;
class QPushButton;
class QFormLayout;

class SettingsPage : public QWidget
{
     Q_OBJECT

public:
    SettingsPage(QWidget *parent, QPushButton *b);
    virtual ~SettingsPage() {};

private:
    void createWidgets();
    void arrangeWidgets();


    // Pointers to widgets
    QLabel *language;
    QPushButton *languageField;
    QLabel *colourScheme;
    QPushButton *colourField;
    QLabel *fontSize;
    QPushButton *fontSizeField;
    QLabel *access;
    QPushButton *accessField;
    QLabel *shortcuts;
    QPushButton *shortcutField;
    QLabel *privacy;
    QPushButton *privacyField;

    QFormLayout *mainLayout;
    bool isShowing = false;

private slots:
    void toggleDisplay();
};

#endif // SETTINGS_PAGE_H
