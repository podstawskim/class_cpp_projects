//
// Created by Michał Podstawski on 13/12/2020.
//

#ifndef PROJECT_BUTTONKDEWIDGET_H
#define PROJECT_BUTTONKDEWIDGET_H

#include "factory/gui/Widget.h"
namespace factory::gui {
    class ButtonKdeWidget : public Widget {
    private:
        int kdeVersion;
    public:
        explicit ButtonKdeWidget(int kdeVersion);
        void draw() override;
    };



}
#endif //PROJECT_BUTTONKDEWIDGET_H
