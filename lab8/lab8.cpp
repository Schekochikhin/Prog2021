#include <iostream>
#include "handler.h"

int main() {
    ErrorHandler a("A");
    AverageHandler b;

    vector <Handler> vec = {a, b};

    a.create();
    b.create();

    Handler_list list(2, vec);
    list.print();

    return 0;
}
