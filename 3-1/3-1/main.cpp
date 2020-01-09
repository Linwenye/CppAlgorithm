//
//  main.cpp
//  3-1
//
//  Created by 林文烨 on 2020/1/8.
//  Copyright © 2020 林文烨. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int main(int argc, const char *argv[])
{
    // insert code here...
    int n;
    scanf("%d", &n);
    char series[85];
    for (int i = 0; i < n; i++) {
        scanf("%s", series);
        int scores = 0;
        int res = 0;
        for (int j = 0; j < strlen(series); j++) {
            if (series[j] == 'O') {
                res += ++scores;
            } else {
                scores = 0;
            }
        }
        printf("%d\n",res);
    }
    
    return 0;
}
