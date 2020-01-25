//
//  main.cpp
//  3-6
//
//  Created by 林文烨 on 2020/1/10.
//  Copyright © 2020 林文烨. All rights reserved.
//

#include <iostream>
#include <stdio.h>

using namespace std;

// 数字对齐～ %3d
int main(int argc, const char *argv[])
{
    // insert code here...

    int r, c;
    int kase = 1;
    while (cin >> r)
    {
        if (r == 0)
        {
            return 0;
        }
        cin >> c;
        char **puzzle = new char *[r];
        int **numbers = new int *[r];
        bool **mark = new bool *[r]();
        for (size_t i = 0; i < r; i++)
        {
            puzzle[i] = new char[c];
            numbers[i] = new int[c];
            mark[i] = new bool[c];
        }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> puzzle[i][j];
            }
        }

        int number = 1;
        // initialize numbers
        for (size_t i = 0; i < r; i++)
        {
            for (size_t j = 0; j < c; j++)
            {
                if (puzzle[i][j] == '*')
                {
                    numbers[i][j] = 0;
                }
                else
                {
                    if (i == 0 || j == 0 || puzzle[i - 1][j] == '*' || puzzle[i][j - 1] == '*')
                    {
                        numbers[i][j] = number++;
                    }
                }
            }
        }

        if (kase != 1)
        {
            cout << endl;
        }

        printf("puzzle #%d:\n", kase++);
        printf("Across\n");

        bool printed = false;
        for (size_t i = 0; i < r; i++)
        {
            printed = false;
            for (size_t j = 0; j < c; j++)
            {
                if (puzzle[i][j] == '*')
                {
                    printed = false;
                }
                else
                {
                    if (numbers[i][j] && !printed)
                    {
                        if (numbers[i][j] <= 9)
                        {
                            printf("  ");
                        }
                        else if (numbers[i][j] <= 99)
                        {
                            printf(" ");
                        }
                        printf("%d.%c", numbers[i][j], puzzle[i][j]);
                        printed = true;
                    }

                    else
                    {
                        printf("%c", puzzle[i][j]);
                    }
                    if (j==c-1||puzzle[i][j+1]=='*')
                    {
                        printf("\n");
                    }
                    
                }
            }
        }

        printf("Down\n");

        for (size_t i = 0; i < r; i++)
        {
            for (size_t j = 0; j < c; j++)
            {
                if (!mark[i][j] && numbers[i][j])
                {
                    if (numbers[i][j] <= 9)
                    {
                        printf("  ");
                    }
                    else if (numbers[i][j] <= 99)
                    {
                        printf(" ");
                    }
                    printf("%d.", numbers[i][j]);
                    for (size_t k = i; k < r; k++)
                    {
                        if (puzzle[k][j] == '*')
                        {
                            break;
                        }
                        else
                        {
                            printf("%c", puzzle[k][j]);
                            mark[k][j] = true;
                        }
                    }
                    printf("\n");
                }
            }
        }
    }

    return 0;
}
