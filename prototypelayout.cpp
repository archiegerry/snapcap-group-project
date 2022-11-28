#include "prototypelayout.h"
#include <iostream>

//Destructor
prototypeLayout::~prototypeLayout()
{

}

void prototypeLayout::setDimensions(const QRect &rectangle)
{
    QLayout::setGeometry(rectangle);

}
