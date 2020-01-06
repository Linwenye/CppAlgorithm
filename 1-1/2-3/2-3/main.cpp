//
//  main.cpp
//  2-3
//
//  Created by 林文烨 on 2020/1/5.
//  Copyright © 2020 林文烨. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char *argv[])
{
    // insert code here...
    int n;
    cin >> n;
    int total = 2 * n - 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        for (int j=0; j<total-2*i; j++) {
            cout<<'#';
        }
        cout<<endl;
    }
    return 0;
}
