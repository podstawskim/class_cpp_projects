//
// Created by Michał Podstawski on 13/12/2020.
//

#include <factory/gui/ButtonGnomeWidget.h>
#include <iostream>
factory::gui::ButtonGnomeWidget::ButtonGnomeWidget(int gnomeVersion) : gnomeVersion(gnomeVersion) {

}

void factory::gui::ButtonGnomeWidget::draw() {
    std::cout<<"factory::gui::ButtonGnomeWidget{gnomeVersion: " << this->gnomeVersion<< "}" << std::endl;
}

