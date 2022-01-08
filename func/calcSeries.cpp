/*
Подсчёт суммы этого ряда:
https://i.imgur.com/JjdxXIt.png
*/

#include <iostream>
#include <iomanip>

#include <boost/multiprecision/cpp_int.hpp>

#include "../include/calcSeries.h"

using namespace boost::multiprecision;

void calcSeries(const unsigned threadNum)
{
    const size_t N = 7500000;
    const cpp_int num_87 = 87;
    const cpp_int num_13 = 13;

    const unsigned REP_NUM = 2;

    for(unsigned i = 0; i < REP_NUM; ++i)
    {



        cpp_int sum = 0;

        #pragma omp parallel num_threads(threadNum)
        {
            #pragma omp for nowait
            for(size_t i = 0; i < N; ++i)
            {
                cpp_int buff;
                buff = i+1;
                buff = pow(buff, 5) + num_87*buff + num_13*buff*buff;
                #pragma omp critical
                {
                    sum += buff;
                }
            }
        }

        //std::cout << "sum = " << sum << std::endl;



    }
}
