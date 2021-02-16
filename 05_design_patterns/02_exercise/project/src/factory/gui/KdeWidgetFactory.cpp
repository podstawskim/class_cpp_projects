//
// Created by Michał Podstawski on 13/12/2020.
//

#include <factory/gui/KdeWidgetFactory.h>

#include <factory/gui/ButtonKdeWidget.h>
#include <factory/gui/CheckBoxKdeWidget.h>
#include <factory/gui/ListKdeWidget.h>


factory::gui::KdeWidgetFactory::KdeWidgetFactory(int kdeVersion) : kdeVersion(kdeVersion){

}

std::shared_ptr<factory::gui::Widget> factory::gui::KdeWidgetFactory::create(std::string type) {
    if(type == "button") {
        return std::make_shared<ButtonKdeWidget>(this->kdeVersion);
    }

    if(type == "check_box") {
        return std::make_shared<CheckBoxKdeWidget>(this->kdeVersion);
    }

    if(type == "list") {
        return std::make_shared<ListKdeWidget>(this->kdeVersion);
    }

    throw std::runtime_error("Unsupported kde widget type: " + type);

}

