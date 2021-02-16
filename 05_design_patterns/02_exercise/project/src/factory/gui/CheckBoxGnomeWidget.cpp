//
// Created by Michał Podstawski on 13/12/2020.
//

#include <factory/gui/CheckBoxGnomeWidget.h>
#include <iostream>
factory::gui::CheckBoxGnomeWidget::CheckBoxGnomeWidget(int gnomeVersion) : gnomeVersion(gnomeVersion) {

}

void factory::gui::CheckBoxGnomeWidget::draw() {
    std::cout<<"factory::gui::CheckBoxGnomeWidget{gnomeVersion: " << this->gnomeVersion <<"}" <<std::endl;
}

