#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for (size_t i = 0; i < n; i++)
    {
        int chess[8][8];
        for (size_t i = 0; i < 8; i++)
        {
            for (size_t j = 0; j < 8; j++)
            {
                // space to skip \n or space, tab, etc
                scanf(" %c",&chess[i][j]);
            }
        }
         
    }
}