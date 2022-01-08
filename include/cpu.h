#ifndef _CPU

#define _CPU

#include <utility>

std::pair<size_t, size_t> oneCore();

size_t mulCore(unsigned threadNum);

unsigned whatSaysOpenMP(unsigned thNum);

#endif