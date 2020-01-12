//
//  main.cpp
//  3-6
//
//  Created by 林文烨 on 2020/1/10.
//  Copyright © 2020 林文烨. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(int argc, const char *argv[])
{
    // insert code here...

    int r, c;
    vector<string> puzzle;

    while (cin>>r)
    {
        if (r == 0)
        {
            return 0;
        }
        cin >> c;
        char **puzzle = new char*[r];
        for (size_t i = 0; i < r; i++)
        {
            puzzle[i] = new char[c];
        }
        
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                cin>>puzzle[i][j];
            }
        }
        
         for (size_t i = 0; i < r; i++)
         {
             for (size_t j = 0; j < c; j++)
             {
                 cout<<puzzle[i][j]<<" ";
             }
             cout<<endl;
         }
    }

    return 0;
}
