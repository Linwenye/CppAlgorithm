//
//  main.cpp
//  2-4
//
//  Created by 林文烨 on 2020/1/6.
//  Copyright © 2020 林文烨. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char *argv[])
{
    // insert code here...
    int n, m;
    int case_num = 1;
    while (scanf("%d %d", &n, &m) != EOF) {
        if (n == 0 && m == 0) {
            break;
        }
        double res = 0;
        for (int i = n; i < m + 1; i++) {
//            res += 1.0 / double(i * i);   i*i超出了int最大值！！
            res += 1.0 / (double(i)* double(i));
        }
        printf("Case %d: %.5lf\n", case_num++, res);
    }
    return 0;
}
