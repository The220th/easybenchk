#include <iostream>
#include <utility>

#include "./include/cpu.h"
#include "./include/mem.h"

using namespace std;

int main()
{
    pair<size_t, size_t> onecore = oneCore();
    cout << "pi + e test: " << onecore.first << "/" << onecore.second << " ms. " << endl;

    cout << endl;

    cout << "Multicore tests: " << endl;
    const unsigned TH[] = {1, 2, 4, 6, 8, 12, 16};
    const unsigned TH_NUM = 7;
    for(unsigned i = 0; i < TH_NUM; ++i)
        cout << "\t* " << TH[i] << " core(s): " << mulCore(TH[i]) << " ms. " << endl;
    
    cout << endl;

    cout << "mem + cpu test: " << memTest() << " ms. " << endl;
    return 0;
}