//
// Created by Michał Podstawski on 13/12/2020.
//

#ifndef PROJECT_CHECKBOXKDEWIDGET_H
#define PROJECT_CHECKBOXKDEWIDGET_H

#include "factory/gui/Widget.h"

namespace factory::gui {
    class CheckBoxKdeWidget : public Widget {
    private:
        int kdeVersion;
    public:
        explicit CheckBoxKdeWidget(int kdeVersion);
        void draw() override;
    };


}

#endif //PROJECT_CHECKBOXKDEWIDGET_H
