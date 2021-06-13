#include<iostream>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while(x)
        {
            int temp = x%10;
            if(result > INT_MAX / 10 ||( result == INT_MAX /10 && result %10 > 7))return 0;
            if(result < -INT_MAX / 10 || (result == -INT_MAX / 10 && result % 10 < -8))return 0;
            result = result * 10 + temp;
            x /= 10;
        }
        return result;
    }
};