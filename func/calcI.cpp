#include <cmath>
#include <iostream>
#include <limits>
#include <iomanip>
#include <chrono>
#include <thread>


using namespace std;

#include "../include/calcI.h"

long double func_I(long double x)
{
    long double res;
    res = sqrt(1 + 2*x*x - x*x*x);
    return res;
}

/*
Вычисление определённого интеграла с помощью формулы симпсона и правила Рунге:
https://i.imgur.com/eXASQTM.png
*/
void calcI(const unsigned threadNum)
{
    const long double e = ((long double)1.0) / pow(10, 15);
    //cout << e << endl;
    const long double a = -23.7;
    const long double b = 2.1;

    const unsigned REP_NUM = 750;

    for(unsigned gi = 0; gi < REP_NUM; ++gi)
    {



        long double I_n = 0;
        long double I_2n = std::numeric_limits<long double>::infinity();
        size_t n2 = 2;
        long double I_2n_diff_I_2;
        do
        {

            long double sum = 0;
            const long double h = (b - a) / (n2);
            size_t N = n2+1;

            #pragma omp parallel reduction (+: sum) num_threads(threadNum)
            {
                #pragma omp for nowait
                for(size_t i = 0; i < N; ++i)
                {
                    long double xi = a + i*h;
                    long double lsum = func_I(xi);
                    if(i == 0 || i == N-1)
                        lsum = lsum;
                    else if(i % 2 == 0)
                        lsum = 2*lsum;
                    else
                        lsum = 4*lsum;
                    sum += lsum;
                }
            }
            I_n = I_2n;
            I_2n = (sum*h)/3.0;
            n2*=2;

            I_2n_diff_I_2 = I_2n - I_n;
            I_2n_diff_I_2 = I_2n_diff_I_2<0?-I_2n_diff_I_2:I_2n_diff_I_2;
            I_2n_diff_I_2 = I_2n_diff_I_2/15.0;
        }while( I_2n_diff_I_2 >= e);

        //std::cout << n2 << ":" << std::setprecision(80) << I_2n << std::endl;


    
    }
}
