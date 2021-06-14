#include<vector>
#include<iostream>
using namespace std;
//dp[i+2] = dp[i-1] + dp[i]
class Solution {
public:
    int climbStairs(int n) {
        //vector<int> dp(n+1,0);
        //dp[0] = 1; dp[1] = 1;
        int first = 1, second = 1;
        int result = 1;
        for(int i = 2; i <=n ; i ++)
        {
            result = first + second;
            first = second;
            second = result;
        }
        return result;
    }
};
int main()
{
    Solution t;
    int n ;
    cin>>n;
    cout<<t.climbStairs(n);
}