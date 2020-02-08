#include <stdio.h>
#include <unordered_map>
#include <map>
#include <string>
#include <utility>
#include <climits>
using namespace std;
/*
    1. 自定义类作为unordered_map 需要定义 hash!!
    2. pair 没定义hash！！ vector 也不能作为key!!
    委屈求全使用map（只需定义<和==
*/
struct Point
{
    int x, y;
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    bool operator==(const Point &p)
    {
        return this->x = p.x && this->y == p.y;
    }
};
int main()
{
    int kase, n;
    scanf("%d", &kase);
    for (size_t i = 0; i < kase; i++)
    {
        int n;
        scanf("%d", &n);
        //int leftmost, rightmost; 错！！ 没有初始化
        int leftmost = INT_MAX, rightmost = INT_MIN;
        map<pair<int, int>, int> res;
        int x, y;
        for (size_t i = 0; i < n; i++)
        {
            scanf("%d %d", &x, &y);
            if (x < leftmost)
                leftmost = x;
            if (x > rightmost)
                rightmost = x;
            res[make_pair(x, y)]++;
        }

        int middle_double = leftmost + rightmost;
        bool syme = true;
        for (auto &it : res)
        {
            if (res[make_pair(middle_double - it.first.first, it.first.second)] != it.second)
            {
                syme = false;
                break;
            }
        }
        if (syme)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}