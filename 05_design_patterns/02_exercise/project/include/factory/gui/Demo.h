//
// Created by Michał Podstawski on 13/12/2020.
//


#include "factory/gui/WidgetFactory.h"

namespace factory {
    namespace gui {

        class Demo {
        private:
            std::shared_ptr<WidgetFactory> factory;
        public:
            explicit Demo(std::shared_ptr<WidgetFactory> factory);
            void run(std::string type);

        };
    }
}
