//
//  main.cpp
//  3-5
//
//  Created by 林文烨 on 2020/1/9.
//  Copyright © 2020 林文烨. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <algorithm>

using namespace std;
int main(int argc, const char *argv[])
{
    // 若该空在行末尾，则无空格符号！
    char a[5][6]; // place '\0'
    int kase = 1;
    while (true) {
        //read puzzle

//        fgets(a[0], 5, stdin);
        gets(a[0]);
        if (a[0][0] == 'Z') {
            break;
        }
        for (int i = 0; i < 4; i++) {
//            scanf("%s", a[i + 1]);  遇空格会结束！！不能用在此
//            fgets(a[i+1], 6, stdin);
            gets(a[i + 1]);
        }

        // get empty index
        int empty_i = 0, empty_j = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (!isalpha(a[i][j])) {
                    a[i][j]=' ';
                    empty_i = i;
                    empty_j = j;
                }
            }
        }

        bool invalid = false;

        while (true) {
            char move = getchar();
            //output

            if (isdigit(move)) {
                getchar(); // 读掉换行
                if (kase != 1) {
                    printf("\n");
                }
                printf("Puzzle #%d:\n", kase++);
                if (invalid) {
                    printf("This puzzle has no final configuration.\n");
                } else {
                    for (int i = 0; i < 5; i++) {
                        for (int j = 0; j < 4; j++) {
                            printf("%c ", a[i][j]);
                        }
                        printf("%c\n", a[i][4]);
                    }
                }
                break;
            }

            if (!invalid) {
                switch (move) {
                    case 'A':
                        if (empty_i - 1 < 0) {
                            invalid = true;
                        } else {
                            swap(a[empty_i - 1][empty_j], a[empty_i][empty_j]);
                            empty_i--;
                        }
                        break;

                    case 'B':
                        if (empty_i + 1 > 4) {
                            invalid = true;
                        } else {
                            swap(a[empty_i + 1][empty_j], a[empty_i][empty_j]);
                            empty_i++;
                        }
                        break;

                    case 'R':
                        if (empty_j + 1 > 4) {
                            invalid = true;
                        } else {
                            swap(a[empty_i][empty_j + 1], a[empty_i][empty_j]);
                            empty_j++;
                        }
                        break;
                    case 'L':
                        if (empty_j - 1 < 0) {
                            invalid = true;
                        } else {
                            swap(a[empty_i][empty_j - 1], a[empty_i][empty_j]);
                            empty_j--;
                        }
                        break;
                }
            }
        }
    }
    return 0;
}
