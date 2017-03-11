// generate accurate delay using usleep, avoid small delta value

#include <chrono>
#include <unistd.h>

void accurate_sleep(double microSeconds, int delta=1000)
{
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
    std::chrono::duration<double> eTime;
    while( std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - start).count() < microSeconds) 
        usleep(delta);
}

