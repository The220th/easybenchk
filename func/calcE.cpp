/*
Неэффективная реализация этой формулы:
https://i.imgur.com/SZNcbva.png
Для сходящихся знакочередующихся рядов справедлив следующий критерий: 
члены следует суммировать до тех пор, пока они по модулю больше заданной точности.
*/

#include <iostream>
#include <iomanip>

#include <boost/multiprecision/cpp_dec_float.hpp>

#include "../include/calcE.h"

using namespace boost::multiprecision;
//namespace mp = boost::multiprecision; // mp::pow

const long long ACCUR = 10000; // Кол-во знаков после запятой
const size_t DIGNUM = ACCUR+10;

typedef number< cpp_dec_float<DIGNUM> > cpp_dec_float_DIGNUM;

void calcE()
{
    const cpp_dec_float_DIGNUM one = 1;
    cpp_dec_float_DIGNUM e;
    cpp_dec_float_DIGNUM xi;
    cpp_dec_float_DIGNUM buff;
    cpp_dec_float_DIGNUM fac;

    buff = 10;
    buff = pow(buff, -ACCUR);
    const cpp_dec_float_DIGNUM accur = buff;

    size_t i = 2;
    fac = 2;
    e = 0;
    int iter = 0;
    do
    {
        xi = one / fac;
        if(iter == 0) // чет
            e += xi;
        else // нечет
            e -= xi;
        
        ++i;
        iter = (iter == 0?1:0);

        buff = i;
        fac *= buff;
    }while(xi >= accur);

    buff = 1;
    e = buff / e;

    //std::cout << std::setprecision(std::numeric_limits<number< cpp_dec_float<ACCUR> >>::max_digits10) << "e = " << e << std::endl;
}