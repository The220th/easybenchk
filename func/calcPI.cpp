#include <iostream>
#include <iomanip>
#include <time.h>

#include <boost/multiprecision/cpp_dec_float.hpp>

#include "../include/calcPI.h"

#include <omp.h>

using namespace boost::multiprecision;
//namespace mp = boost::multiprecision; // mp::pow

const long long ACCUR = 100000; // Кол-во знаков после запятой
const size_t DIGNUM = ACCUR+10;

typedef number< cpp_dec_float<DIGNUM> > cpp_dec_float_DIGNUM;


/*
Неэффективная реализация этой формулы:
https://i.imgur.com/dE8klLQ.png
*/
void calcPI()
{
    const cpp_dec_float_DIGNUM ONE = 1;
    const cpp_dec_float_DIGNUM TWO = 2;
    cpp_dec_float_DIGNUM pi;
    cpp_dec_float_DIGNUM buff;
    cpp_dec_float_DIGNUM a;
    cpp_dec_float_DIGNUM b;
    cpp_dec_float_DIGNUM diff;
    cpp_dec_float_DIGNUM arith;
    cpp_dec_float_DIGNUM geom;
    cpp_dec_float_DIGNUM series;

    buff = 10;
    buff = pow(buff, -ACCUR);
    const cpp_dec_float_DIGNUM epsilon = buff;

    a = 1;

    buff = sqrt(TWO);
    b = ONE / buff;

    diff = a - b;
    series = 0;

    size_t n = 0;
    while(diff > epsilon)
    {
        ++n;
        arith = (a + b) / TWO;
        geom = sqrt(a*b);

        a = arith;
        b = geom;

        buff = pow(TWO, n+1);
        series += buff * (a*a - b*b);
        
        diff = a - b;
    }

    buff = 4;
    pi = (buff*a*a) / (ONE - series);

    //std::cout << "n = " << n << std::endl;
    //std::cout << std::setprecision(std::numeric_limits<number< cpp_dec_float<ACCUR> >>::max_digits10) << "pi = " << pi << std::endl;
}


/*
Неточное вычисление числа pi, с помощью этой формулы:
https://i.imgur.com/gAMAToc.png
*/
void calcPI_mul(const unsigned threadNum)
{
    const size_t N = 100000000;
    const size_t blocksize = 50000;
    const unsigned REP_NUM = 50;


    for(unsigned gi = 0; gi < REP_NUM; ++gi)
    {

        long double sum = 0;

        #pragma omp parallel reduction (+: sum) num_threads(threadNum)
        {
            #pragma omp for schedule(dynamic, blocksize) nowait
            for (size_t i = 0; i < N; ++i)
            {
                long double xi;
                xi = (i + 0.5); xi /= N;
                sum += (long double)4 / (1 + xi*xi);
            }
        }
        sum /= N;
        //std::cout << std::setprecision(80) << sum << std::endl;
    }
}
