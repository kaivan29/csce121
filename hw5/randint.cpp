//randint.cpp
#include "randint.h"
#include <chrono>
using namespace std::chrono;
//linear congruential pseudorandom number generator

int randint(){
        //use the clock for an initial pseudorandom number
        static long x = time_point_cast<microseconds>(
                                        system_clock::now()).time_since_epoch().count();
        //calculate the next pseudorandom number
        x = (1103515245 * x + 12345) & 0x7fffffff;	//parameters from glibc(?)
        return x;
}