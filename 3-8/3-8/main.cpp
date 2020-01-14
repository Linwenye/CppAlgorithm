//
//  main.cpp
//  3-8
//
//  Created by 林文烨 on 2020/1/10.
//  Copyright © 2020 林文烨. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int a,b;
    while (scanf("%d %d",&a,&b)!=EOF)
    {
        int original_a = a;
        int left_part = a/b;
        a = a%b;
        int decimal_count = 0;
        string res="";
        res+=to_string(left_part).append(".");
        string right="";
        
        map<int,int> int_map;
        while (true)
        {
            a = a*10;
            if(int_map[a]){
                break;
            }
            int_map[a]=++decimal_count;
            right.append(to_string(a/b));
            a = a%b;
        }
        
        int repeat_length = right.length()-int_map[a]+1;
        res.append(right.substr(0,int_map[a]-1)).append("(");
        if(repeat_length<=50){
            res.append(right.substr(int_map[a]-1));
        }
        else
        {
            res.append(right.substr(int_map[a]-1,50)).append("...");
        }
        res.append(")");

        cout<<original_a<<"/"<<b<<" = "<<res<<endl;
        cout<<"   "<<repeat_length<<" = number of digits in repeating cycle"<<endl<<endl;
    }
    
    return 0;
}
