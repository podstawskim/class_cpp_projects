//
// Created by Michał Podstawski on 13/12/2020.
//

#ifndef PROJECT_GNOMEWIDGETFACTORY_H
#define PROJECT_GNOMEWIDGETFACTORY_H
#include "factory/gui/WidgetFactory.h"

namespace factory::gui {
    class GnomeWidgetFactory : public WidgetFactory {
    private:
        int gnomeVersion;
    public:
        explicit GnomeWidgetFactory(int gnomeVersion);
        std::shared_ptr<Widget> create(std::string type);
    };
}
#endif //PROJECT_GNOMEWIDGETFACTORY_H
