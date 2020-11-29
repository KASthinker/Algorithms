#include "IntArray/IntArray.h"

#include <iostream>
#include <chrono>

class Timer
{
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;
	std::chrono::time_point<clock_t> m_beg;
 
public:
	Timer() : m_beg(clock_t::now()) {}
	
	void reset()
	{
		m_beg = clock_t::now();
	}
	
    friend std::ostream& operator<<(std::ostream &out, Timer &t);
};

std::ostream& operator<<(std::ostream &out, Timer &t) {
    out << std::chrono::duration_cast<Timer::second_t>(Timer::clock_t::now() - t.m_beg).count();
    return out;
}

int main() {
    const int length = 50000;
    IntArray array(length);
    array.randArray(0, 10000);
    // std::cout << array << "\n";

    Timer t;
    array.BubbleSort();
    std::cout << "BubbleSort with length = " << length << ". Runtime = "  << t << "\n";
    //std::cout << array << "\n";


    array.shuffle();
    //std::cout << array << "\n";

    t.reset();
    array.ShakerSort();
    std::cout << "ShakerSort with length = " << length << ". Runtime = "  << t << "\n";
    //std::cout << array << "\n";

    array.shuffle();
    //std::cout << array << "\n";

    t.reset();
    array.CombSort();
    std::cout << "CombSort with length = " << length << ". Runtime = "  << t << "\n";
    //std::cout << array << "\n";

    array.shuffle();
    //std::cout << array << "\n";

    t.reset();
    array.InsertionSort();
    std::cout << "InsertionSort with length = " << length << ". Runtime = "  << t << "\n";
    //std::cout << array << "\n";

    array.shuffle();
    //std::cout << array << "\n";

    t.reset();
    array.SelectionSort();
    std::cout << "SelectionSort with length = " << length << ". Runtime = "  << t << "\n";
    //std::cout << array << "\n";

    array.shuffle();
    //std::cout << array << "\n";

    t.reset();
    array.QuickSort();
    std::cout << "QuickSort with length = " << length << ". Runtime = "  << t << "\n";
    //std::cout << array << "\n";

    array.shuffle();
    //std::cout << array << "\n";

    t.reset();
    array.MergeSort();
    std::cout << "MergeSort with length = " << length << ". Runtime = "  << t << "\n";
    //std::cout << array << "\n";

    return 0;
}