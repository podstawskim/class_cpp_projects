//
// Created by Michał Podstawski on 13/12/2020.
//

#ifndef PROJECT_WIDGET_H
#define PROJECT_WIDGET_H

namespace factory::gui {
    class Widget {
    public:
        virtual ~Widget() = default;
        virtual void draw() = 0;
    };
}

#endif //PROJECT_WIDGET_H
