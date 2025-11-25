#include "Time.hpp"

std::chrono::steady_clock::time_point Time::s_start = std::chrono::steady_clock::now();
std::chrono::steady_clock::time_point Time::s_prev  = Time::s_start;
double Time::s_dt = 0.0;

void Time::beginFrame() {
    auto now = std::chrono::steady_clock::now();
    s_dt = std::chrono::duration<double>(now - s_prev).count();
    s_prev = now;
}

double Time::now() {
    auto now = std::chrono::steady_clock::now();
    return std::chrono::duration<double>(now - s_start).count();
}

double Time::dt() {
    return s_dt;
}
