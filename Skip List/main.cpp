#include <iostream>
#include <random>
#include <time.h>

using namespace std;

int INF = 1e9;

typedef
struct Quad
{
    Quad* up;
    Quad* down;
    Quad* left;
    Quad* right;
    Quad* end;

    int val;

    Quad(int x)
    {
        val = x;
        up = down = left = right = end = NULL;
    }
}
* Qptr;

Qptr search(Qptr Q, int key)
{
    while (1)
    {
        if (Q -> val == key) return Q;
        if (Q -> right && Q -> right -> val <= key) Q = Q -> right;
        else if (Q -> down) Q = Q -> down;
        else return Q;
    }
}

// 8 assignments in total
// while making new level
// U ... (J)U->right
// K ... (L)K->end
//
// U -> r, U -> d, U -> end
// K -> u
// L -> u
// J -> l, J -> d, J -> end


void insert(Qptr &Q, int key)
{
    Qptr K = search(Q, key);
    while (K -> down) K = K -> down;

    Qptr P = NULL;
    while (1)
    {
        Qptr T = new Quad(key);
        K -> right -> left = T;
        T -> right = K -> right;
        K -> right = T;
        T -> end = K -> end;
        T -> left = K;

        if (P) P -> up = T, T -> down = P;
        P = T;

        if (rand()&1) break;

        while ((K -> up == NULL) && K -> left) K = K -> left;

        if (K -> up == NULL)
        {
            K -> up = new Quad(-INF);
            Qptr U = K -> up;
            U -> right = new Quad(INF);
            U -> right -> left = U;
            U -> end = U -> right -> end = U -> right;
            U -> down = K;
            U -> right -> down = K -> end;
            K -> end -> up = U -> right;
        }
        K = K -> up;
    }
    while (Q -> up) Q = Q -> up;
}

void prtSkipList(Qptr Q)
{
    while (Q)
    {
        Qptr T = Q;
        while (T)
        {
            cout << T -> val;
            if (T -> right) cout << " -> ";
            else cout << "\n";
            T = T -> right;
        }
        Q = Q -> down;
    }
}

int main()
{
    srand(time(0));
    srand(rand()*1000);
    srand(rand());

    Qptr Q = new Quad(-INF);
    Q -> right = new Quad(INF);
    Q -> right -> left = Q;
    Q -> end = Q -> right -> end = Q -> right;

    // prtSkipList(Q);

    for (int i = 1; i <= 7; i++) insert(Q, i);

    prtSkipList(Q);
}

