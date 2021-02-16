//
// Created by Michał Podstawski on 13/12/2020.
//

#include <factory/gui/ListKdeWidget.h>
#include <iostream>
factory::gui::ListKdeWidget::ListKdeWidget(int kdeVersion) : kdeVersion(kdeVersion){

}

void factory::gui::ListKdeWidget::draw() {
    std::cout<<"factory::gui::ListKdeWidget{kdeVersion: " << this->kdeVersion << "}"<<std::endl;
}

