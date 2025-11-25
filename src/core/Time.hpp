#pragma once
#include <chrono>

class Time {
public:
    // Llama a beginFrame() al inicio de cada frame
    static void beginFrame();

    // Tiempo actual en segundos desde inicio del programa
    static double now();

    // Delta time del último frame en segundos
    static double dt();

private:
    static std::chrono::steady_clock::time_point s_start;
    static std::chrono::steady_clock::time_point s_prev;
    static double s_dt;
};
