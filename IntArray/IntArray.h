#ifndef INTARRAY_H
#define INTARRAY_H

#include <iostream>

class IntArray {
    int *m_array = nullptr;
    int m_length;

    void swap(int x, int y);
    void swap(int *x, int *y);

public:
    IntArray(int lenght);
    IntArray(const IntArray &array);
    ~IntArray();

    void randArray(int min, int max);
    void shuffle();
    IntArray& operator=(const IntArray &array);
    int& operator[](const int index) const;
    friend std::ostream& operator<<(std::ostream &out, IntArray &array);

    void BubbleSort();
    void ShakerSort();
    void CombSort();
    void InsertionSort();
    void SelectionSort();

private:
    int Partition(int l, int r);
    void QuickSortImpl(int l, int r);
public:
    void QuickSort();

private:
    void MergeSortImpl(IntArray &buffer, int l, int r);
public:
    void MergeSort();
};

#endif