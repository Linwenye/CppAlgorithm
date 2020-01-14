#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
int main()
{
    string a,b;
    while(cin>>a>>b){
        int a_i=0,b_i=0;
        while (true)
        {
            if(a_i>=a.length()){
                cout<<"Yes"<<endl;
                break;
            }
            if(b_i>=b.length()){
                cout<<"No"<<endl;
                break;
            }
            if(a[a_i]==b[b_i]){
                a_i++;
                b_i++;
            }
            else
            {
                b_i++;
            }
        }
    }
}
