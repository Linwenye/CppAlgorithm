//
//  main.cpp
//  2-5
//
//  Created by 林文烨 on 2020/1/6.
//  Copyright © 2020 林文烨. All rights reserved.
//

#include <stdio.h>
//#include <string>

//using namespace std;
int main(int argc, const char *argv[])
{
    // insert code here...
    int a, b, c;
    int case_i = 1;
    while (scanf("%d %d %d", &a, &b, &c) != EOF) {
        if (a == 0 && b == 0 && c == 0) {
            break;
        }
//        string print_str = string("Case %d: %.")+to_string(c)+string("lf\n");
//        Case %d: %.if
        printf("Case %d: %.*lf\n", case_i++, c, double(a) / double(b));
    }
    return 0;
}
