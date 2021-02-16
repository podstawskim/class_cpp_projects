//
// Created by Michał Podstawski on 13/12/2020.
//

#include <factory/gui/ButtonKdeWidget.h>
#include <iostream>
factory::gui::ButtonKdeWidget::ButtonKdeWidget(int kdeVersion) : kdeVersion(kdeVersion) {

}

void factory::gui::ButtonKdeWidget::draw() {
    std::cout<<"factory::gui::ButtonKdeWidget{kdeVersion: " << this->kdeVersion <<"}" <<std::endl;
}

