#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        vector<string> res;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            res.push_back(s);
        }
        sort(res.begin(), res.end());

        // caculate columns
        int max_len = 0;
        for (size_t i = 0; i < res.size(); i++)
        {
            max_len = res[i].size() > max_len ? res[i].size() : max_len;
        }
        // (c-1)*(l+2)+l <=60
        int c = (60 - max_len) / (max_len + 2) + 1;
        int r = ceil(double(res.size()) / double(c));

        cout << "------------------------------------------------------------" << endl;

        for (size_t i = 0; i < r; i++)
        {
            for (size_t j = 0; j < c; j++)
            {
                size_t linear_i = r * j + i;
                if (linear_i < res.size())
                {
                    cout << res[linear_i];
                    int spaces = max_len - res[linear_i].size();
                    if (j != c)
                        spaces += 2;
                    for (size_t k = 0; k < spaces; k++)
                    {
                        cout << " ";
                    }
                }
            }
            cout << endl;
        }
    }
}