//
// Created by Michał Podstawski on 13/12/2020.
//

#ifndef PROJECT_LISTGNOMEWIDGET_H
#define PROJECT_LISTGNOMEWIDGET_H
#include "factory/gui/Widget.h"
namespace factory::gui {
    class ListGnomeWidget : public Widget {
    private:
        int gnomeVersion;
    public:
        explicit ListGnomeWidget(int gnomeVersion);
        void draw() override;
    };
}
#endif //PROJECT_LISTGNOMEWIDGET_H
