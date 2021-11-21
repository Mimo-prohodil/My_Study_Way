#pragma once
#include <chrono>
#include <string>

class Timer {

	std::chrono::steady_clock::time_point start; 
	static std::chrono::nanoseconds duration;

public:
	Timer() {		
		start = std::chrono::steady_clock::now();
	}
	~Timer() {
		duration = std::chrono::duration_cast<std::chrono::nanoseconds>
			(std::chrono::steady_clock::now() - start);
	}
	static std::string getDuration() {		
		return std::to_string((double)duration.count() * 0.000000001) + "s";		
	}
};

std::chrono::nanoseconds Timer::duration = std::chrono::nanoseconds(0);