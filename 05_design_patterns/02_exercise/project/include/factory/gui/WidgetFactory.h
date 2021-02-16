//
// Created by Michał Podstawski on 13/12/2020.
//

#ifndef PROJECT_WIDGETFACTORY_H
#define PROJECT_WIDGETFACTORY_H
#include "factory/gui/Widget.h"
#include <memory>
#include <iostream>

namespace factory::gui {
    class WidgetFactory {
    public:
        virtual std::shared_ptr<Widget> create (std::string type) = 0;
        virtual ~WidgetFactory() = default;
    };
}
#endif //PROJECT_WIDGETFACTORY_H
