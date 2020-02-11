#include <stdio.h>
#include <queue>
#include <unordered_map>
#include <string.h>
#define MAX_N 1000100
using namespace std;

int main()
{
    int n;
    int kase = 1;
    while (scanf("%d", &n) != EOF && n)
    {
        queue<int> *team_queues = new queue<int>[n];
        queue<int> behalf_queue;
        unordered_map<int, int> team_map;
        for (int i = 0; i < n; i++)
        {
            int t;
            scanf("%d", &t);
            int temp_in;
            for (size_t j = 0; j < t; j++)
            {
                scanf("%d", &temp_in);
                team_map[temp_in] = i + 1;
            }
        }

        char cmd[15];
        printf("Scenario #%d\n", kase++);
        while (true)
        {
            scanf("%s", cmd);
            if (cmd[0] == 'E')
            {
                int temp_in;
                scanf("%d", &temp_in);
                if (team_queues[team_map[temp_in] - 1].empty())
                {
                    behalf_queue.push(team_map[temp_in]);
                }
                team_queues[team_map[temp_in] - 1].push(temp_in);
            }
            else if (cmd[0] == 'D')
            {
                int queue_i = behalf_queue.front();
                int pop_n = team_queues[queue_i - 1].front();
                team_queues[queue_i-1].pop();
                if (team_queues[queue_i - 1].empty())
                    behalf_queue.pop();
                printf("%d\n", pop_n);
            }
            else // stop
            {
                break;
            }
        }
        printf("\n");
    }
}