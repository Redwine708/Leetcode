#include<iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(long long int x) {
        if(x < 0) return false;
        else if(x == 0 ) return true;
        long long int tmp = x;
        long long int res = 0;
        while(tmp)
        {
            res = res * 10 + tmp % 10;
            tmp /= 10;
        }
        return res == x ;
    }
};
int main()
{
    Solution s;
    cout<<s.isPalindrome(0);
}