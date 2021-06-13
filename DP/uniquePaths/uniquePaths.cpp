#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        for(int i = 0 ; i < m - 1 ; i ++)
        {
            for(int j  = 0 ; j <n - 1 ; j ++)
                dp[j+1] = dp[j+1] + dp[j];
        }
        return dp[n - 1];
    }
};
int main()
{
    Solution t;
    int m,n;
    cin>>m>>n;
    cout<<t.uniquePaths(m,n);
}