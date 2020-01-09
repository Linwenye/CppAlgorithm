//
//  main.cpp
//  3-3
//
//  Created by 林文烨 on 2020/1/8.
//  Copyright © 2020 林文烨. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char *argv[])
{
    // insert code here...
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int number;
        int res[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        scanf("%d", &number);
        // number<= 9999
        // brute force
        for (int j=1; j<=number; j++) {
            int temp = j;
            while (temp>0) {
                res[temp%10]++;
                temp = temp/10;
            }
        }
        for (int j=0; j<9; j++) {
            printf("%d ",res[j]);
        }
        printf("%d\n",res[9]);
    }
    return 0;
}
