

#include "splaytree.h"
#include <iostream>

using namespace std;

int main() {

    splaytree* t = new splaytree(10);

    t->d(); t->print(); cout << endl;

    t = t->insert(new splaytree(9));

    t->d(); t->print(); cout << endl;

    int xs[] = {99, 1, 5, 3 , 6};

    for(int i = 0; i < 20; ++i){

        splaytree* x = new splaytree(i);

        t = t->insert(x);

        t->d(); t->print(); cout << endl;

    }


    t->d(); t->print(); cout << endl;


    return 0;
}


