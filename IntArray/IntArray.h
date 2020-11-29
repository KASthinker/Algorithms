#ifndef INTARRAY_H
#define INTARRAY_H

#include <iostream>

class IntArray {
    int *m_array = nullptr;
    int m_length;

public:
    IntArray(int lenght);
    IntArray(const IntArray &array);
    ~IntArray();

    void randArray(int min, int max);
    void shuffle();
    IntArray& operator=(const IntArray &array);
    int& operator[](const int index) const;
    friend std::ostream& operator<<(std::ostream &out, IntArray &array);

    IntArray& BubbleSort();
};

#endif