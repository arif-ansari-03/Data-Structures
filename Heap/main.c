#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int heap;

struct heap_elem
{
    int a;
    heap_elem(int b)
    {
        a = b;
    }
};

int heap_elem_cmp(struct heap_elem a, struct heap_elem b)
{
    if (a.a < b.a) return -1;
    if (a.a == b.a) return 0;
    return 1;
}

struct Heap
{
    int N;
    struct heap_elem* heap;
    int MAX;
    
    void init(int n)
    {
        N = 0;
        heap = malloc(sizeof(struct heap_elem) * n);
        MAX = -1;
    }

    void insert(struct heap_elem a)
    {
        heap[N] = a;
        int i = N++;

        while (i > 0)
        {
            int p = (i-1)/2;
            if (heap_elem_cmp(heap[p], heap[i]) == MAX) break;
            struct heap_elem t = heap[p];
            heap[p] = heap[i];
            heap[i] = t;
            i = p;
        }
    }

    struct heap_elem extract()
    {
        if (N <= 0)
        {
            printf("Heap empty\n");
            exit(-1);
        }

        heap_elem ret_val = heap[0];
        heap[0] = heap[--N];

        int i = 0;
        while (1)
        {
            int j1 = 2*i+1, j2 = 2*i+2;
            if (j1 >= N) break;
            if (j2 < N)
            {
                if (heap_elem_cmp(heap[j1], heap[j2]) != MAX)
                {
                    int t = j1;
                    j1 = j2;
                    j2 = t;
                }
            }
            struct heap_elem t = heap[i];
            heap[i] = heap[j1];
            heap[j1] = t;
            i = j1;
        }
    }
};

/*
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
*/

int main()
{
    struct Heap H;
    H.insert(4);

}