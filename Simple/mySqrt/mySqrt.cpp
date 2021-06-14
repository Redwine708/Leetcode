/**
 * @file mySqrt.cpp
 * @author your name (you@domain.com)
 * @brief compute and return the square root of x
 * @version 0.1
 * @date 2021-06-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<iostream>
using namespace std;

class Solution {
public:
    long long int mySqrt(long long int x) {
        if(x == 0) return 0;
        for(long long int i = 1 ; 1 ; i ++)
        {
            if(i * i == x )return i;
            if(i * i <= x && x < (i+1) * (i+1))
                return i;
        }
    }
};
int main()
{
    int m = 0;
    Solution t;
    cin>>m;
    cout<<t.mySqrt(m);
}