#include <iostream>
#include <string>
#include <map>
#include <math.h>
using namespace std;

struct Record
{
    int M;
    int E;
    Record(int m, int e)
    {
        M = m;
        E = e;
    }
};

int main()
{
    string s;
    // Mantissa 0<=M<=9
    // Exponent 1<=E<=30
    map<string, Record> res_table;
    for (size_t M = 0; M <= 9; M++)
    {
        for (size_t E = 1; E <= 30; E++)
        {
            Record record(M, E);
            // 0.1~M+1位 2进制 * pow(2,pow(2,E)-1)
            double base = 1.0 - 1.0 / pow(2, M + 1);
            double exponent = pow(2, E) - 1;

            int decimal_e = 0;
            for (int i = exponent; i > 0; i--)
            {
                base = base * 2;
                if (base >= 10)
                {
                    base = base / 10.0;
                    decimal_e++;
                }
            }
            printf("%.15lfe%d\n", base, decimal_e);
        }
    }

    // while (cin >> s && s != "0e0")
    // {
    // }
}
