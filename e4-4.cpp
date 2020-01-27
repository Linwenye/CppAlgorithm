#include <iostream>
#include <string>

using namespace std;

// TNM AEIOU
// 0010101100011
// 1010001001110110011
// 11000
// $#**\
// 0100000101101100011100101000

int get_number(int n)
{ // n as number of sequences
    int res = 0;
    int count = 0;
    while (count != n)
    {
        char digit = cin.get();
        if (digit == '\r' || digit == '\n')
        {
            continue;
        }
        res = res * 2 + digit - '0';
        count++;
    }
    return res;
}

int main()
{
    string header;
    while (getline(cin, header))
    {
        while (true)
        {
            int n = get_number(3);

            //
            // cout<<endl<<endl<<"1n is "<<n;

            if (n == 0)
            {
                cin.ignore();
                break;
            }
            int max_as_stop = (1 << n) - 1;
            int str_index_base = 0;
            for (size_t i = 1; i < n; i++)
            {
                str_index_base += (1 << i) - 1;
            }
            // cout<<endl<<endl<<"index base is "<<str_index_base;

            while (true)
            {
                int str_index = get_number(n);
                //
                // cout<<endl<<endl<<"index is "<<str_index;
                if (str_index == max_as_stop)
                {
                    break;
                }
                str_index += str_index_base;
                cout<<header[str_index];
            }
        }
        cout<<endl;
    }
}