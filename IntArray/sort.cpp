#include "IntArray.h"

IntArray& IntArray::BubbleSort() {
    int tmp;
    for(int i=0; i < m_length-1; i++) {
        for(int j=0; j < m_length-i-1; j++) {
            if(m_array[j] > m_array[j+1]) {
                tmp = m_array[j];
                m_array[j] = m_array[j+1];
                m_array[j+1] = tmp;
            }
        }
    }
    return *this;
}