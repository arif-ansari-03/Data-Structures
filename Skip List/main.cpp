#include <iostream>
#include "skiplist.h"
#include <time.h>

using namespace std;


int main()
{
    srand(time(0));
    srand(rand()*1000);
    srand(rand());

    Qptr Q = new Quad(-INF);
    init_skiplist(Q);

    for (int i = 1; i <= 7; i++) insert(Q, i);

    prtSkipList(Q);

    erase(Q, 4);
    cout << '\n';

    prtSkipList(Q);
}

