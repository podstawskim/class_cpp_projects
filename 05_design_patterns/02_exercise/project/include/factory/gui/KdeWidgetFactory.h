//
// Created by Michał Podstawski on 13/12/2020.
//

#ifndef PROJECT_KDEWIDGETFACTORY_H
#define PROJECT_KDEWIDGETFACTORY_H

#include "factory/gui/WidgetFactory.h"

namespace factory::gui {
    class KdeWidgetFactory : public WidgetFactory {
    private:
        int kdeVersion;
    public:
        explicit KdeWidgetFactory(int kdeVersion);
        std::shared_ptr<Widget> create(std::string type);
    };
}
#endif //PROJECT_KDEWIDGETFACTORY_H
