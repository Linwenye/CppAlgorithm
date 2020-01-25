#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
int main()
{
    int n;
    string a, b;
    while (true)
    {
        cin >> n;
        if (n == -1)
        {
            break;
        }
        cin >> a >> b;
        unordered_set<char> original;
        for (size_t i = 0; i < a.length(); i++)
        {
            original.insert(a[i]);
        }

        cout << "Round " << n << endl;

        int count = 7;
        bool done = false;
        for (size_t i = 0; i < b.length(); i++)
        {
            if (original.count(b[i]))
            {
                original.erase(b[i]);
            }
            else
            {
                count--;
            }
            
            if (original.empty())
            {
                cout << "You win." << endl;
                done = true;
                break;
            }
            if (count <= 0)
            {
                cout << "You lose." << endl;
                done = true;
                break;
            }
        }

        if (!done)
            cout << "You chickened out." << endl;
    }
}
