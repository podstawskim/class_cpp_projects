#include <iostream>
#include "Calculator.h"

#include "factory/executor/CpuCoreFactory.h"
#include "factory/executor/CudaCoreFactory.h"
#include "factory/executor/Demo.h"

#include "factory/gui/GnomeWidgetFactory.h"
#include "factory/gui/KdeWidgetFactory.h"
#include "factory/gui/Demo.h"

#include "observer/observers/Acceleration.h"
#include "observer/observers/Displacement.h"
#include "observer/observers/Speed.h"

int main()
{
    Calculator calculator{1, 2};

    std::cout << "Sum: " << calculator.add() << std::endl;


    {
        auto factory = std::make_shared<factory::executor::CpuCoreFactory>(10);
        auto demo = std::make_shared<factory::executor::Demo>(factory);

        demo->run("acoustic");
        demo->run("elastic");
        demo->run("anisotropic");
    }

    {
        auto factory = std::make_shared<factory::executor::CudaCoreFactory>(1);
        auto demo = std::make_shared<factory::executor::Demo>(factory);

        demo->run("acoustic");
        demo->run("elastic");
        demo->run("anisotropic");
    }

    {
        auto factory = std::make_shared<factory::gui::GnomeWidgetFactory>(2);
        auto demo = std::make_shared<factory::gui::Demo>(factory);

        demo->run("button");
        demo->run("list");
        demo->run("check_box");
    }

    {
        auto factory = std::make_shared<factory::gui::KdeWidgetFactory>(3);
        auto demo = std::make_shared<factory::gui::Demo>(factory);

        demo->run("button");
        demo->run("list");
        demo->run("check_box");
    }

    {
        observer::observers::Displacement displacement;

        observer::observers::Speed speed;
        observer::observers::Acceleration acceleration;

        displacement.registerObserver(&speed);
        displacement.registerObserver(&acceleration);

        displacement.set(10);
        displacement.set(11);
        displacement.set(13);

        std::cout << "Result: speed: " << speed.get() << ", acceleration: " << acceleration.get();
    }

    return 0;
}