#include <stdio.h>
#include <vector>
#include <queue>
#include <functional> // greater<int> means min-heap, opposite to intuition
#include <unordered_set>

using namespace std;

int main()
{
    long long factor[3] = {2, 3, 5};
    vector<long long> res;
    unordered_set<long long> existed;
    priority_queue<long long, vector<long long>, greater<long long> > pq;

    existed.insert(1);
    pq.push(1);

    while (res.size() < 1500)
    {
        long long to_add = pq.top();
        res.push_back(to_add);
        pq.pop();

        for(int i=0;i<3;i++){
            long long new_add = to_add*factor[i];
            if(!existed.count(new_add)){
                pq.push(new_add);
                existed.insert(new_add);
            }
        }
    }

    printf("The 1500'th ugly number is %lld.\n", res[1499]);
}