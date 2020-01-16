//
//  main.cpp
//  3-11
//
//  Created by 林文烨 on 2020/1/10.
//  Copyright © 2020 林文烨. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, const char *argv[])
{
    // brute force
    string up, down;
    while (cin >> up)
    {
        cin >> down;
        if (up.length() > down.length())
            swap(up, down);

        int res = int(up.length() + down.length());
        for (int i = -int(up.length()) + 1; i < int(down.length()); i++)
        {
            bool match = true;
            for (int down_k = max(0, i), up_k = max(0, -i); down_k < min(int(down.length()), i + int(up.length())); down_k++, up_k++)
            {
                if (down[down_k] == '2' && up[up_k] == '2')
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                int new_length = int(up.length()) + int(down.length()) - (min(int(down.length()), i + int(up.length())) - max(0, i));
                res = new_length < res ? new_length : res;
            }
        }
        cout << res << endl;
    }
    return 0;
}
