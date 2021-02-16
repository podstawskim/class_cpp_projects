//
// Created by Michał Podstawski on 13/12/2020.
//

#ifndef PROJECT_CHECKBOXGNOMEWIDGET_H
#define PROJECT_CHECKBOXGNOMEWIDGET_H
#include "factory/gui/Widget.h"
namespace factory::gui {
    class CheckBoxGnomeWidget : public Widget {
    private:
        int gnomeVersion;
    public:
        explicit CheckBoxGnomeWidget(int gnomeVersion);
        void draw() override;
    };


}
#endif //PROJECT_CHECKBOXGNOMEWIDGET_H
