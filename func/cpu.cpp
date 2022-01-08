#include <string>
#include <time.h>
#include <iostream>
#include <chrono>
#include <utility>

#include "../include/cpu.h"
#include "../include/calcPI.h"
#include "../include/calcE.h"
#include "../include/calcI.h"
#include "../include/calcSeries.h"

using namespace std;

/*
Одно ядро

Возвращает число милисек высчитывания числа pi (100 000) и e (10 000)
*/
pair<size_t, size_t> oneCore()
{
    pair<size_t, size_t> res_cpu_real;

    auto time_begin = std::chrono::steady_clock::now();
    clock_t startTime = clock();

    /*
    Вычисление 100 000 знаков после запятой числа pi
    */
    calcPI();

    /*
    Вычисление 10 000 знаков после запятой числа Эйлера
    */
    calcE();

    clock_t endTime = clock();
    auto time_end = std::chrono::steady_clock::now();

    size_t milisecFromStart = 0;
    milisecFromStart = (size_t)(((double)(endTime - startTime) / CLOCKS_PER_SEC) * 1000 + 0.5);

    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(time_end - time_begin);
    size_t milisecFromStart1 = elapsed_ms.count();
    //cout << "*" << milisecFromStart1 << endl;

    res_cpu_real.first = milisecFromStart;
    res_cpu_real.second = milisecFromStart1;

    return res_cpu_real;
}

/*
Несколько ядер
*/
size_t mulCore(unsigned threadNum)
{
    auto time_begin = std::chrono::steady_clock::now();


    //=====chek=====
    if(whatSaysOpenMP(threadNum) != threadNum)
    {
        cout << "OpenMP is not working. " << endl;
        throw "OpenMP is not working. ";
    }
    //=====chek=====

    //=====shittyPI=====
    calcPI_mul(threadNum);
    //=====shittyPI=====

    //=====definiteIntegral=====
    calcI(threadNum);
    //=====definiteIntegral=====

    //=====series=====
    calcSeries(threadNum);
    //=====series=====

    auto time_end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(time_end - time_begin);
    size_t milisecFromStart = elapsed_ms.count();

    return milisecFromStart;
}

unsigned whatSaysOpenMP(unsigned thNum)
{
    unsigned count = 0;
    #ifdef _OPENMP
    #pragma omp parallel num_threads(thNum)
    {
        #pragma omp atomic
        ++count;
    }
    #endif
   return count;
}