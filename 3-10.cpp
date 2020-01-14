#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
    bool pair[6];
    int in[6][2];
    int represent[3];
    while (cin >> in[0][0] >> in[0][1])
    {
        memset(pair, 0, sizeof(pair));

        for (size_t i = 1; i < 6; i++)
        {
            cin >> in[i][0] >> in[i][1];
        }
        for (size_t i = 0; i < 6; i++)
        {
            if (in[i][0] > in[i][1])
            {
                swap(in[i][0], in[i][1]);
            }
        }

        int repr_i = 0;
        for (size_t i = 1; i < 6; i++)
        {
            for (size_t j = 0; j < i; j++)
            {
                if (!pair[j])
                {
                    if (in[i][0] == in[j][0] && in[i][1] == in[j][1])
                    {
                        pair[i] = pair[j] = true;
                        represent[repr_i++] = j;
                    }
                }
            }
        }

        if (repr_i != 3)
        {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        else
        {
            if (in[represent[0]][0] == in[represent[2]][0])
            {
                swap(represent[1], represent[2]);
            }
            else if (in[represent[1]][0] == in[represent[2]][0])
            {
                swap(represent[0], represent[2]);
            }

            if (in[represent[0]][0] == in[represent[1]][0])
            {
                if (in[represent[0]][1] == in[represent[2]][0] && in[represent[1]][1] == in[represent[2]][1] ||
                    in[represent[0]][1] == in[represent[2]][1] && in[represent[1]][1] == in[represent[2]][0])
                {
                    cout << "POSSIBLE" << endl;
                    continue;
                }
            }
            cout << "IMPOSSIBLE" << endl;
        }
    }
}