//
//  main.cpp
//  CppAlgorithm
//
//  Created by 林文烨 on 2020/1/1.
//  Copyright © 2020 林文烨. All rights reserved.
//

#include <iostream>
#include <stdio.h>
int main(int argc, const char *argv[])
{
    // insert code here...
    double i = 1.0 / 100;
    int count = 1;
    printf("%d%d", count++, count++);
    count = 1;
    count = count++;
    printf("\n%d",count);
    if (i < 1e-6) std::cout << "hh";
    return 0;
}
