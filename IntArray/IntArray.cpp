#include "IntArray.h"
#include <cassert>

IntArray::IntArray(int length) : m_length(length) {
    assert(length > 0);
    m_array = (int*)malloc(sizeof(int)*length);
}
IntArray::IntArray(const IntArray &array) : m_length(array.m_length) {
    m_array = (int*)malloc(sizeof(int)*array.m_length);
    for (int count = 0; count < array.m_length; ++count) {
        m_array[count] = array.m_array[count];
    }
}
IntArray::~IntArray() {
    delete[] m_array;
}

void IntArray::randArray(int min, int max) {
    srand(static_cast<unsigned int>(time(0)));
    for(int i = 0; i < m_length; i++) {
        m_array[i] = rand() % max + min;
    }
}

void IntArray::shuffle() {
    // Перебираем каждую карту в колоде
    for (int i = 0; i < m_length; i++)
    {
        int swapIndex = rand() % (m_length-1);
        int tmp = m_array[i];
        m_array[i] = m_array[swapIndex];
        m_array[swapIndex] = tmp;
    }
}

IntArray& IntArray::operator=(const IntArray &array) {
    if(this == &array) {
        return *this;
    }

    delete[] m_array;
    m_length = array.m_length;
    m_array = (int*)malloc(sizeof(int)*m_length);
    for(int i=0; i < m_length; i++) {
        m_array[i] = array[i];
    }

    return *this;
}

int& IntArray::operator[](const int index) const {
    assert(index >=0);
    assert(index < m_length);
    return m_array[index];
}

std::ostream& operator<<(std::ostream &out, IntArray &array) {
    out << "[";
    for(int i=0; i < array.m_length - 1; i++) {
        out << array[i] << ", ";
    }
    out << array[array.m_length-1] <<"]";
    return out;
}
