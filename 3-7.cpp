#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
int main()
{
    int kase;
    scanf("%d", &kase);
    for (size_t k = 0; k < kase; k++)
    {
        int r, c;
        scanf("%d %d", &r, &c);
        char **groups = new char *[r];
        char *res = new char[c + 1];
        res[c] = '\0';

        for (size_t i = 0; i < r; i++)
        {
            groups[i] = new char[c];
        }
        for (size_t i = 0; i < r; i++)
        {
            for (size_t j = 0; j < c; j++)
            {
                cin >> groups[i][j];
            }
        }

        map<char, int> representatives;
        int cons_error = 0;
        for (size_t j = 0; j < c; j++)
        {
            for (size_t i = 0; i < r; i++)
            {
                representatives[groups[i][j]]++;
            }

            int maximum = 0;
            for (auto const &item : representatives)
            {
                if (item.second > maximum)
                {
                    res[j] = item.first;
                    maximum = item.second;
                }
            }

            // calculate consensus error
            for (auto const &item : representatives)
            {
                if (item.first != res[j])
                {
                    cons_error += item.second;
                }
            }

            representatives.clear();
        }
        printf("%s\n%d\n", res,cons_error);
        for (size_t i = 0; i < r; i++)
        {
            delete []groups[i];
        }
        delete[] groups;
        delete[]res;
    }
}