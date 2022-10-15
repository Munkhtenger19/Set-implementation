#ifndef MENU_H
#define MENU_H
#include "set.h"

class Menu
{
    public:
        Menu(){};
        void Run();
    private:
        int MenuPrint();
        void insertElement();
        void removeElement();
        void isEmpty();
        void isIn();
        void rands();
        void evens();
        void print();
        void loadTest();
        Set S;

};

#endif // MENU_H

