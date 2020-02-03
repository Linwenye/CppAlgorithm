#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
bool danger[11][10];
char chess[11][10];

struct Point
{
    int x, y;
    Point(int x1, int y1)
    {
        x = x1, y = y1;
    }
    Point operator+(const Point &p2)
    {
        return Point(x + p2.x, y + p2.y);
    }

    bool valid()
    {
        return x > 0 && x < 11 && y > 0 && y < 10;
    }

    bool general_valid()
    {
        return x >= 1 && x <= 3 && y >= 4 && y <= 6;
    }
};

void print_danger()
{
    cout << endl;
    for (size_t i = 1; i < 11; i++)
    {
        for (size_t j = 1; j < 10; j++)
        {
            cout << chess[i][j] << danger[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main()
{

    int n;
    // black general x 1~3, y 4~6

    int black_x, black_y;
    while (cin >> n && n)
    {
        memset(danger, 0, sizeof(danger));
        memset(chess, '*', sizeof(chess));
        cin >> black_x >> black_y;

        for (size_t i = 0; i < n; i++)
        {
            char type;
            cin >> type;
            int x, y;
            cin >> x >> y;
            chess[x][y] = type;
        }

        for (size_t x = 1; x < 11; x++)
        {
            for (size_t y = 1; y < 10; y++)
            {
                switch (chess[x][y])
                {
                case 'G':
                {
                    for (int i = x - 1; i > 0; i--)
                    {
                        danger[i][y] = true;
                        if (chess[i][y] != '*')
                        {
                            break;
                        }
                    }

                    break;
                }
                case 'C':
                {
                    int count = 0;
                    for (int i = x - 1; i > 0; i--)
                    {
                        if (count == 1)
                            danger[i][y] = true;
                        if (chess[i][y] != '*')
                        {
                            count++;
                        }
                    }
                    count = 0;
                    for (int i = y - 1; i > 0; i--)
                    {
                        if (count == 1)
                            danger[x][i] = true;
                        if (chess[x][i] != '*')
                        {
                            count++;
                        }
                    }
                    count = 0;
                    for (int i = x + 1; i < 11; i++)
                    {
                        if (count == 1)
                            danger[i][y] = true;
                        if (chess[i][y] != '*')
                        {
                            count++;
                        }
                    }
                    count = 0;
                    for (int i = y + 1; i < 11; i++)
                    {
                        if (count == 1)
                            danger[x][i] = true;
                        if (chess[x][i] != '*')
                        {
                            count++;
                        }
                    }

                    break;
                }
                case 'H':
                {
                    Point horse(x, y);
                    // (1,2),(2,1),(2,-1),(1,-2),(-1,2),(-1,-2),(-2,-1),(-2,1)
                    Point horse_jumps[8] = {Point(1, 2), Point(2, 1), Point(2, -1), Point(1, -2), Point(-1, 2), Point(-1, -2), Point(-2, -1), Point(-2, 1)};
                    Point hobbling[8] = {Point(0, 1), Point(1, 0), Point(1, 0), Point(0, 1), Point(0, 1), Point(0, -1), Point(-1, 0), Point(-1, 0)};

                    for (size_t i = 0; i < 8; i++)
                    {
                        Point after_jump = horse + horse_jumps[i];
                        if (after_jump.valid())
                        {
                            Point hobb_place = horse + hobbling[i];
                            if (chess[hobb_place.x][hobb_place.y] == '*')
                            {
                                danger[after_jump.x][after_jump.y] = true;
                            }
                        }
                    }

                    break;
                }
                case 'R':
                {
                    for (int i = x - 1; i > 0; i--)
                    {
                        danger[i][y] = true;
                        if (chess[i][y] != '*')
                        {
                            break;
                        }
                    }
                    for (int i = y - 1; i > 0; i--)
                    {
                        danger[x][i] = true;
                        if (chess[x][i] != '*')
                        {
                            break;
                        }
                    }
                    for (int i = x + 1; i < 11; i++)
                    {
                        danger[i][y] = true;
                        if (chess[i][y] != '*')
                        {
                            break;
                        }
                    }
                    for (int i = y + 1; i < 11; i++)
                    {
                        danger[x][i] = true;
                        if (chess[x][i] != '*')
                        {
                            break;
                        }
                    }

                    break;
                }
                default:
                    break;
                }
            }
        }

        Point black(black_x, black_y);
        Point move[4] = {Point(0, 1), Point(1, 0), Point(0, -1), Point(-1, 0)};
        bool safe = false;
        for (size_t i = 0; i < 4; i++)
        {
            Point temp = move[i] + black;
            if (temp.general_valid() && (!danger[temp.x][temp.y]))
            {
                safe = true;
            }
        }

        if (safe)
        {
            cout << "NO";
        }
        else
        {
            cout << "YES";
        }

        print_danger();
    }
}