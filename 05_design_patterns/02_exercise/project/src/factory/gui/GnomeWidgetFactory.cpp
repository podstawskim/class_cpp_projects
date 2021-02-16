//
// Created by Michał Podstawski on 13/12/2020.
//

#include <factory/gui/GnomeWidgetFactory.h>
#include <factory/gui/ListGnomeWidget.h>
#include <factory/gui/CheckBoxGnomeWidget.h>
#include <factory/gui/ButtonGnomeWidget.h>


factory::gui::GnomeWidgetFactory::GnomeWidgetFactory(int gnomeVersion) : gnomeVersion(gnomeVersion){

}

std::shared_ptr<factory::gui::Widget> factory::gui::GnomeWidgetFactory::create(std::string type) {
    if(type == "button") {
        return std::make_shared<ButtonGnomeWidget>(this->gnomeVersion);
    }

    if(type == "check_box") {
        return std::make_shared<CheckBoxGnomeWidget>(this->gnomeVersion);
    }

    if(type == "list") {
        return std::make_shared<ListGnomeWidget>(this->gnomeVersion);
    }

    throw std::runtime_error("Unsupported gnome widget type: " + type);
}

