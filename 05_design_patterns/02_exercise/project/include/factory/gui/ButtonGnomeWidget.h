//
// Created by Michał Podstawski on 13/12/2020.
//

#ifndef PROJECT_BUTTONGNOMEWIDGET_H
#define PROJECT_BUTTONGNOMEWIDGET_H
#include "factory/gui/Widget.h"
namespace factory::gui {
    class ButtonGnomeWidget : public Widget {
    private:
        int gnomeVersion;
    public:
        explicit ButtonGnomeWidget(int gnomeVersion);
        void draw() override;
    };
}
#endif //PROJECT_BUTTONGNOMEWIDGET_H
