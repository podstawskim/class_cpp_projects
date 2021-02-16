//
// Created by Michał Podstawski on 13/12/2020.
//

#include "factory/gui/CheckBoxKdeWidget.h"
#include <iostream>

factory::gui::CheckBoxKdeWidget::CheckBoxKdeWidget(int kdeVersion) : kdeVersion(kdeVersion){

}

void factory::gui::CheckBoxKdeWidget::draw() {
    std::cout<<"factory::gui::CheckBoxKdeWidget{kdeVersion: " << this->kdeVersion << "}"<<std::endl;

}
