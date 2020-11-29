#include "IntArray.h"
#include <algorithm>

void IntArray::BubbleSort() {
    int tmp;
    for(int i=0; i < m_length-1; ++i) {
        for(int j=0; j < m_length-i-1; ++j) {
            if(m_array[j] > m_array[j+1]) {
                swap(j, j+1);
            }
        }
    }
}

void IntArray::ShakerSort() {
    if (!m_length) {
        return;
    }
    int left = 0;
    int right = m_length - 1;
    while (left <= right) {
        for (int i = right; i > left; --i) {
            if (m_array[i - 1] > m_array[i]) {
            swap(i - 1, i);
            }
        }
        ++left;
        for (int i = left; i < right; ++i) {
            if (m_array[i] > m_array[i + 1]) {
                swap(i, i + 1);
            }
        }
        --right;
    }
}

void IntArray::CombSort() {
    const double factor = 1.247;
    double step = m_length - 1;

    while(step >= 1) {
        for(int i = 0; i + step < m_length; ++i) {
            if(m_array[i] > m_array[i+static_cast<int>(step)]) {
                swap(i, i + step);
            }
        }
        step /= factor;
    }
    BubbleSort();
}

void IntArray::InsertionSort() {
    for(int i = 1; i < m_length; ++i) {
        int x = m_array[i];
        int j = i;
        while(j > 0 && m_array[j - 1] > x) {
            m_array[j] = m_array[j - 1];
            --j;
        }
        m_array[j] = x;
    }
}

void IntArray::SelectionSort() {
    for(auto i = &m_array[0]; i != &m_array[m_length-1]; ++i) {
        auto j = std::min_element(i, &m_array[m_length]);
        swap(i, j);
    }
}

int IntArray::Partition(int l, int r) {
    int x = m_array[r];
    int less = l;

    for(int i = l; i < r; ++i) {
        if(m_array[i] <= x) {
            swap(i, less);
            ++less;
        }
    }
    swap(less, r);
    return less;
}
void IntArray::QuickSortImpl(int l, int r) {
    if(l < r) {
        int q = Partition(l, r);
        QuickSortImpl(l, q - 1);
        QuickSortImpl(q + 1, r);
    }
}
void IntArray::QuickSort() {
    if(m_length) {
        QuickSortImpl(0, m_length - 1);
    }
}

void IntArray::MergeSortImpl(IntArray &buffer, int l, int r) {
    if(l < r) {
        int m = (l + r) / 2;
        MergeSortImpl(buffer, l, m);
        MergeSortImpl(buffer, m + 1, r);

        int k = l;
        for(int i = l, j = m + 1; i <= m || j <= r; ) {
            if(j > r || (i <= m && m_array[i] < m_array[j])) {
                buffer[k] = m_array[i];
                ++i;
            } else {
                buffer[k] = m_array[j];
                ++j;
            }
            ++k;
        }
        for(int i = l; i <= r; ++i) {
            m_array[i] = buffer[i];
        }
    }
}

void IntArray::MergeSort() {
    if (m_length) {
        IntArray buffer(m_length);
        MergeSortImpl(buffer, 0, m_length - 1);
    }
}