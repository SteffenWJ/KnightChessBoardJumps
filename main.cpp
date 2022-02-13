#include <iostream>
#include "driver.h"

using namespace std;

int main()
{

    //Creates two chrono objects for comparison later.
    std::chrono::time_point<std::chrono::system_clock> start, end;

    //Takes the Current time
    start = std::chrono::system_clock::now();

    //Returns the needed jumps to go from start to end point
    int steps = Driver::MinimumSteps(1000,1000,99,100,10,19);


    std::cout << "Steps needed:" << steps << std::endl;

    end = std::chrono::system_clock::now();

        std::chrono::duration<double> elapsed_seconds = end - start;
        std::time_t end_time = std::chrono::system_clock::to_time_t(end);

        std::cout << "finished computation at " << std::ctime(&end_time)
                  << "elapsed time: " << elapsed_seconds.count() << "s\n";

    return 0;
}
