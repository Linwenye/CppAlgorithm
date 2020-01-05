//
//  main.cpp
//  2-2
//
//  Created by 林文烨 on 2020/1/4.
//  Copyright © 2020 林文烨. All rights reserved.
//
#include <stdio.h>
int main(int argc, const char *argv[])
{
    // insert code here...
    int case_i = 0;
    int a, b, c;
    while (scanf("%d %d %d", &a, &b, &c) != EOF) {
        bool got_answer = false;
        for (int i = 10; i < 100; i++) {
            if (i % 3 == a && i % 5 == b && i % 7 == c) {
                printf("Case %d: %d\n", ++case_i, i);
                got_answer = true;
                break;
            }
        }
        if (!got_answer) {
            printf("Case %d: No answer\n", ++case_i);
        }
    }

    return 0;
}
