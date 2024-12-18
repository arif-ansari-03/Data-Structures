#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

// this heap is specifically made for Dijkstra's algorithm
// this heap has logn insertion and extract_min
// it also has update_dist in logn time, same time as insertion

struct Heap
{
    int* heap;
    int* pos;
    int* val;
    int N = 0;

    void init(int n)
    {
        heap = malloc(sizeof(int) * n);
        val = malloc(sizeof(int) * n);
        pos = malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++) pos[i] = -1;
    }

    void bubble_up(int u)
    {
        int i = pos[u];

        while (i > 0)
        {
            int j = (i-1)/2;
            if (val[j] <= val[i]) break;
            int v = heap[j];

            int t = heap[i];
            heap[i] = heap[j];
            heap[j] = t;

            t = val[i];
            val[i] = val[j];
            val[j] = t;

            pos[v] = i;
            pos[u] = j;

            i = j;
        }
    }

    void bubble_down(int u)
    {
        int i = pos[u];

        while (1)
        {
            int j1 = 2*i+1;
            int j2 = 2*i+2;

            int k1 = j1 < N && val[i] > val[j1];
            int k2 = j2 < N && val[i] > vaj[j2];

            if (!k1 && !k2) break;

            if (!k1) j1 = j2;

            int v = heap[j1];

            int t = heap[i];
            heap[i] = heap[j1];
            heap[j1] = t;

            t = val[i];
            val[i] = val[j1];
            val[j1] = t;

            pos[v] = i;
            pos[u] = j1;

            i = j1;
        }
    }

    void insert(int u, int d)
    {
        int i = pos[u];
        if (i == -1)
        {
            pos[u] = N;
            heap[N] = u;
            val[N] = d;
            N++;
            return;
        }
        if (val[i] == d) return;

        int k = val[i] < d;
        val[i] = d;

        if (k) bubble_up(u);
        else bubble_down(u);
    }
};

int main()
{


}