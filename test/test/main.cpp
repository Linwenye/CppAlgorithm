#include <cstdio>

int N=0, k=0, m=0;

struct Node
{
    Node *next;
    Node *prev;
    int value;
    Node(int v)
    {
        value = v;
    }
};

class NodeQueue
{
public:
    Node *head;
    int size;
    NodeQueue(int size)
    {
        this->size = size;
        head = new Node(1);
        Node *pre = head;
        Node *curr = head;
        for (size_t i = 2; i <= size; i++)
        {
            curr = new Node(i);
            curr->prev = pre;
            pre->next = curr;
            pre = curr;
        }
        head->prev = curr;
        curr->next = head;
    };

    void removeNode(Node *node)
    {
        if (node->prev)
        {
            node->prev->next = node->next;
        }
        if (node->next)
        {
            node->next->prev = node->prev;
        }
        size--;
        printf("%3d",node->value);
        delete node;
    }

    void remove(int k, int m)
    {
        Node *clockwise = head;
        Node *counter = head->prev;
        while (size)
        {
            if(size!=N) printf(",");
            for (size_t i = 0; i < k % size; i++)
            {
                clockwise = clockwise->next;
            }
            for (size_t i = 0; i < m % size; i++)
            {
                counter = counter->prev;
            }
            if (clockwise->prev == counter->next)
                removeNode(clockwise->prev);
            else
            {
                removeNode(clockwise->prev);
                removeNode(counter->next);
            }
        }
        printf("\n");
    }
};

int main()
{
    while (true)
    {
        scanf("%d %d %d", &N, &k, &m);
        if (N == 0)
            break;
        NodeQueue node_q(N);
        node_q.remove(k,m);
    }
}
