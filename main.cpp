#include "IntArray/IntArray.h"

#include <iostream>
#include <cassert>
#include <chrono>
#include <iomanip>

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
    const int length = 20;
    IntArray array(length);
    array.randArray(0, 10000);
    std::cout << array << "\n";

    Timer t;
    array.BubbleSort();
    std::cout << "Bubble sort with length = " << length << ". Runtime = "  << t << "\n";

    array.shuffle();
    
    return 0;
}