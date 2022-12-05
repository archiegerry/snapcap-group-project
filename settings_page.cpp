#include "settings_page.h"
#include <QtWidgets>

SettingsPage::SettingsPage(QWidget *p, QPushButton *b)
{
    setParent(p);
    createWidgets();
    arrangeWidgets();
    connect(b, SIGNAL(clicked()), this, SLOT(toggleDisplay()));
    setVisible(false);

    move(width() * 0.25, height() * 0.25);
    setWindowTitle("Settings Page");
}


void SettingsPage::createWidgets(){
    // Create widgets
    language = new QLabel("Language:");
    languageField = new QPushButton("Select Language");

    colourScheme = new QLabel("Colour Scheme:");
    colourField = new QPushButton("Select Colour Scheme");

    fontSize = new QLabel("Font Size:");
    fontSizeField = new QPushButton("Select Font Size");

    shortcuts = new QLabel("Shortcuts:");
    shortcutField = new QPushButton("Modify Shortcuts");

    access = new QLabel("Accessibility:");
    accessField = new QPushButton("Accessibility Options");

    privacy = new QLabel("Privacy:");
    privacyField = new QPushButton("Check Privacy Information");

    mainLayout = new QFormLayout();
}

void SettingsPage::arrangeWidgets(){
    QFormLayout * mainLayout = new QFormLayout();

    mainLayout->addRow(language, languageField);
    mainLayout->addRow(colourScheme, colourField);
    mainLayout->addRow(fontSize, fontSizeField);
    mainLayout->addRow(shortcuts, shortcutField);
    mainLayout->addRow(access, accessField);
    mainLayout->addRow(privacy, privacyField);
    setLayout(mainLayout);

}

void SettingsPage::toggleDisplay(){
    if(!isShowing){
        isShowing = true;
        raise();
        setVisible(true);
    } else {
        isShowing = false;
        setVisible(false);
    }
}
