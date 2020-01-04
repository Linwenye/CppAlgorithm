//
//  main.cpp
//  2-1
//
//  Created by 林文烨 on 2020/1/4.
//  Copyright © 2020 林文烨. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    int a,b,c;
    for (int i=100; i<1000; i++) {
        c=i%10;
        b=(i%100)/10;
        a=i/100;
        if (i==a*a*a+b*b*b+c*c*c) {
            printf("%d ",i);
        }
    }
    return 0;
}
