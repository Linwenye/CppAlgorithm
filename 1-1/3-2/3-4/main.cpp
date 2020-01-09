//
//  main.cpp
//  3-2
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
    char the_str[85];
    for (int i = 0; i < n; i++) {
        scanf("%s", the_str);
        int res = 0;
        for (int j = 1; j <= strlen(the_str) / 2; j++) {  // j as index of the length of smallest period
            bool match = true;
            if (strlen(the_str) % j != 0) {
                continue;
            }
            for (int k = 0; k < j; k++) {
                for (int l = 0; l < strlen(the_str) / j; l++) {  // l as index of period
                    if (the_str[k] != the_str[k + l * j]) {
                        match = false;
                        break;
                    }
                }
                if (!match) break;
            }
            if (match) {
                res = j;
                break;
            }
        }
        if (res == 0) {
            res = strlen(the_str);
        }
        printf("%d\n", res);
        if(i!=n-1) printf("\n");
    }

    return 0;
}
