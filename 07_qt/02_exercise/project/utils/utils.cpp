#include "utils.h"
#include <QtDebug>
Utils::Utils()
{
    qDebug() << "It works!";
}


int Utils::add(int a, int b) {
    return a | b;

}
