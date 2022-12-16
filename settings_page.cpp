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
    // put in a sensible location
    move(30, b->y()+100);
	setWindowTitle("Settings Page");
}


void SettingsPage::createWidgets(){
    // Create widgets
	languageField = new QPushButton(tr("Languages"));

	colourField = new QPushButton(tr("Colour Scheme"));

	fontSizeField = new QPushButton(tr("Select Font Size"));

	shortcutField = new QPushButton(tr("Keyboard Shortcuts"));

	accessField = new QPushButton(tr("Accessibility Options"));

	privacyField = new QPushButton(tr("Check Privacy Information"));

    mainLayout = new QFormLayout();
}

void SettingsPage::arrangeWidgets(){
    QFormLayout * mainLayout = new QFormLayout();

    mainLayout->addRow(languageField);
    mainLayout->addRow(colourField);
    mainLayout->addRow(fontSizeField);
    mainLayout->addRow(shortcutField);
    mainLayout->addRow(accessField);
    mainLayout->addRow(privacyField);
    setLayout(mainLayout);
}

void SettingsPage::toggleDisplay(){
//  move(this->height()/2, this->y()/2);

    if(!isShowing){
        isShowing = true;
        raise();
        setVisible(true);
    } else {
        isShowing = false;
        setVisible(false);
    }
}

void SettingsPage::cycleLanguage() {

}
