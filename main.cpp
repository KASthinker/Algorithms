#include "IntArray/IntArray.h"

#include <iostream>
#include <cassert>

int main() {
    IntArray array(10);

    for(int i=0; i < 10; i++) {
        array[i] = 10 - i;
    }

    std::cout << array << "\n";

    array.BubbleSort();

    std::cout << array << "\n";

    return 0;
}