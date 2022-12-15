#include "settings_page.h"
#include <QtWidgets>

SettingsPage::SettingsPage(QWidget *p, QPushButton *b)
{
    setParent(p);
    setMaximumSize(p->width()/2,p->height()/2 );
    createWidgets();
    arrangeWidgets();
    connect(b, SIGNAL(clicked()), this, SLOT(toggleDisplay()));
    setVisible(false);

    move(b->x(), b->y()+200);
	setWindowTitle("Settings Page");
}


void SettingsPage::createWidgets(){
    // Create widgets
	language = new QLabel("Language:");
	languageField = new QPushButton(tr("Languages"));

    colourScheme = new QLabel("Colour Scheme:");
	colourField = new QPushButton(tr("Colour Scheme"));

    fontSize = new QLabel("Font Size:");
	fontSizeField = new QPushButton(tr("Select Font Size"));

    shortcuts = new QLabel("Shortcuts:");
	shortcutField = new QPushButton(tr("Keyboard Shortcuts"));

    access = new QLabel("Accessibility:");
	accessField = new QPushButton(tr("Accessibility Options"));

    privacy = new QLabel("Privacy:");
	privacyField = new QPushButton(tr("Check Privacy Information"));

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
    move(this->height()/2, this->y()/2);

    if(!isShowing){
        isShowing = true;
        raise();
        setVisible(true);
    } else {
        isShowing = false;
        setVisible(false);
    }
}
