#include <string>
#include <time.h>
#include <iostream>
#include <chrono>
#include <cstdlib>

#include "../include/mem.h"

using namespace std;

size_t memTest()
{
    auto time_begin = std::chrono::steady_clock::now();

    mem1();

    auto time_end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(time_end - time_begin);
    size_t milisecFromStart = elapsed_ms.count();

    return milisecFromStart;
}

void mem1()
{
    const unsigned SEED = 13*11*7*5*3*2;
    srand(SEED);

    const unsigned REP_NUM = 75;

    const size_t N = 30000;
    const int MAX_ITEM = 1000;

    for(unsigned gi = 0; gi < REP_NUM; ++gi)
    {



        int **a = NULL;
        a = (int**)malloc(N*sizeof(int*));

        int **res = NULL;
        res = (int**)malloc(N*sizeof(int*));

        for(size_t i = 0; i < N; ++i)
        {
            a[i] = (int*)malloc(1*sizeof(int));
            res[i] = (int*)malloc(1*sizeof(int));
        }

        for(size_t i = 0; i < N; ++i)
            a[i][0] = 1 + rand() % MAX_ITEM;

        //for(size_t i = 0; i < N; ++i) cout << a[i][0] << endl;

        //Очень неэффективная сортировка
        for(size_t j = 0; j < N; ++j)
        {
            int min_el = MAX_ITEM + 1;
            int min_el_i = -1;
            for(size_t i = 0; i < N; ++i)
            {
                if(min_el > a[i][0])
                {
                    min_el = a[i][0];
                    min_el_i = i;
                }
            }
            res[j][0] = min_el;
            a[min_el_i][0] = MAX_ITEM + 1;
        }
        //Очень неэффективная сортировка


        //for(size_t i = 0; i < N; ++i) cout << res[i][0] << endl;

        for(size_t i = 0; i < N; ++i)
        {
            free(a[i]);
            free(res[i]);
        }
        free(a);
        free(res);

    }
}