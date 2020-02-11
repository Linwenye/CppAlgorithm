#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int factor[3] = {2, 3, 5};
    vector<long long> res;
    size_t size_former = 0, size_now = 0, size_former_add = 0;
    res.push_back(1);
    while (res.size() < 1500)
    {
        size_former_add = size_now - size_former;
        size_former = size_now;
        size_now = res.size();
        for (size_t i = size_former; i < size_now; i++)
        {
            // for (size_t j = 0; j < 3; j++)
            res.push_back(res[i] * 2);
        }
        for (size_t i = size_former + size_former_add; i < size_now; i++)
        {
            res.push_back(res[i] * 3);
        }
        res.push_back(res[size_now - 1] * 5);
    }

    sort(res.begin(), res.end());
    // for (size_t i = 0; i < 1500; i++)
    // {
    //     printf("%lld ", res[i]);
    // }

    printf("The 1500'th ugly number is %lld.", res[1499]);
}