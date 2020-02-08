#include <stdio.h>

enum Direction
{
    HORIZON,
    VERTICAL
};

bool **connects_h;
bool **connects_v;
bool detect(size_t size, int i, int j);

int main()
{
    int n, m;
    int kase = 1;

    while (scanf("%d %d", &n, &m) == 2)
    {
        connects_h = new bool *[n + 1];
        connects_v = new bool *[n + 1];
        for (size_t i = 0; i < n + 1; i++)
        {
            connects_h[i] = new bool[n + 1]();
            connects_v[i] = new bool[n + 1]();
        }

        for (size_t i = 0; i < m; i++)
        {
            char type;
            int p, q;
            scanf(" %c %d %d", &type, &p, &q);
            if (type == 'H')
            {
                connects_h[p][q] = true;
            }
            else
            {
                connects_v[q][p] = true;
            }
        }
        if (kase != 1)
        {
            printf("\n**********************************\n\n");
        }
        printf("Problem #%d\n\n", kase++);

        bool found = false;
        for (size_t size = 1; size <= n - 1; size++) // square size
        {
            int count = 0;
            for (int i = 1; i <= n - size; i++)
            {
                for (int j = 1; j <= n - size; j++)
                {
                    if (detect(size, i, j))
                    {
                        count++;
                        found = true;
                    }
                }
            }
            if (count)
                printf("%d square (s) of size %d\n", count, size);
        }
        if (!found)
        {
            printf("No completed squares can be found.\n");
        }
    }
}

bool detect(size_t size, int i, int j)
{
    bool found = true;
    for (int k = 0; k < size; k++)
    {
        if (!(connects_h[i][j + k] && connects_h[i + size][j + k] && connects_v[i + k][j] && connects_v[i + k][j + size]))
        {
            found = false;
            break;
        }
    }

    return found;
}
