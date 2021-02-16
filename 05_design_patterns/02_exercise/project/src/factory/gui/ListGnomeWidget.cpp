//
// Created by Michał Podstawski on 13/12/2020.
//

#include <factory/gui/ListGnomeWidget.h>
#include <iostream>
factory::gui::ListGnomeWidget::ListGnomeWidget(int gnomeVersion) : gnomeVersion(gnomeVersion) {

}

void factory::gui::ListGnomeWidget::draw() {
    std::cout<<"factory::gui::ListGnomeWidget{gnomeVersion: " << this->gnomeVersion << "}"<< std::endl;
}

