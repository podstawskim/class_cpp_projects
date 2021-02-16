//
// Created by Michał Podstawski on 13/12/2020.
//

#ifndef PROJECT_LISTKDEWIDGET_H
#define PROJECT_LISTKDEWIDGET_H
#include "factory/gui/Widget.h"

namespace factory::gui {
    class ListKdeWidget : public Widget {
    private:
        int kdeVersion;
    public:
        explicit ListKdeWidget(int kdeVersion);
        void draw() override;
    };



}
#endif //PROJECT_LISTKDEWIDGET_H
