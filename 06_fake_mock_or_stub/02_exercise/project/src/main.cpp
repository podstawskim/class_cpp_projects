//#include <iostream>
//
//#include "Universe.h"
//
//#include "TimeImpl.h"
//#include "SpaceImpl.h"
//#include "ObserverImpl.h"
//
//int main() {
//
//    std::cout << "Are you sure you want to run this thing? [yes/no]" << std::endl;
//
//    std::string confirmation{};
//    std::cin >> confirmation;
//
//    if (confirmation != "yes") {
//
//        std::cout << "Uff... It was close..." << std::endl;
//        return 0;
//    }
//
//    std::cout << "Whatever..." << std::endl;
//
//    TimeImpl time{};
//    SpaceImpl space{};
//    ObserverImpl observer{};
//
//    Universe universe{time, space, observer};
//
//    universe.create();
//    universe.simulate(13800000000);
//
//    std::string question = "Have People evolved?";
//    std::string answer = observer.answer(question);
//
//    std::cout << question << " : " << answer << std::endl;
//
//    return 0;
//}

#include <cstdio>
#include <iostream>
using namespace std;


int main(){
    char c=255;
    if(c>10)
        printf("cos");
    else
        printf("inne");
    return (0);
}


