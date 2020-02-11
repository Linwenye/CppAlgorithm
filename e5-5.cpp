#include <string>
#include <iostream>
#include <stack>
#include <set>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

/*
    不太会啊～
    利用 单独id 设为标识来实现递归定义的结构
    unordered_set<unordered_set<int>> 一样不行，得自己添加hash function
*/

int main()
{
    int kase;
    cin >> kase;
    for (int p = 0; p < kase; p++)
    {
        int n;
        cin >> n;
        string oper;
        stack<int> my_stack;
        vector<set<int>> access_set;

        set<int> primary; // id 1
        access_set.push_back(primary);
        access_set.push_back(primary); // pivot

        map<set<int>, int> map_sets;
        map_sets[primary] = 1;
        int id = 2;

        for (size_t t = 0; t < n; t++)
        {
            cin >> oper;
            if (oper == "PUSH")
            {
                my_stack.push(1);
            }
            else if (oper == "DUP")
            {
                my_stack.push(my_stack.top());
            }
            else if (oper == "ADD")
            {
                int first_set = my_stack.top();
                my_stack.pop();

                int second_set = my_stack.top();
                my_stack.pop();

                set<int> tem = access_set[second_set];
                tem.insert(first_set);

                int set_i = map_sets[tem];
                if (set_i)
                {
                    my_stack.push(set_i);
                }
                else
                {
                    my_stack.push(id);
                    map_sets[tem] = id++;
                    access_set.push_back(tem);
                }
            }
            else if (oper == "UNION")
            {
                int first_set = my_stack.top();
                my_stack.pop();

                int second_set = my_stack.top();
                my_stack.pop();

                set<int> union_set;
                set_union(access_set[first_set].begin(), access_set[first_set].end(), access_set[second_set].begin(), access_set[second_set].end(),  std::inserter(union_set,union_set.begin()));

                int set_i = map_sets[union_set];
                if (set_i)
                {
                    my_stack.push(set_i);
                }
                else
                {
                    my_stack.push(id);
                    map_sets[union_set] = id++;
                    access_set.push_back(union_set);
                }
            }
            else if (oper == "INTERSECT")
            {
                int first_set = my_stack.top();
                my_stack.pop();

                int second_set = my_stack.top();
                my_stack.pop();

                set<int> inter_set;
                set_intersection(access_set[first_set].begin(), access_set[first_set].end(), access_set[second_set].begin(), access_set[second_set].end(),  std::inserter(inter_set,inter_set.begin()));

                int set_i = map_sets[inter_set];
                my_stack.push(set_i);
            }

            printf("%d\n",access_set[my_stack.top()].size());
        }
        printf("***\n");
    }
}