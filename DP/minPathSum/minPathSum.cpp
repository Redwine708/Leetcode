#include<vector>
#include<iostream>
using namespace std;
/**
 * @brief Given a m x n grid filled with non-negative numbers, 
 *        find a path from top left to bottom right, 
 *        which minimizes the sum of all numbers along its path.
 * 
 */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>dp (n,0);
        int sum  = 0;
        for(int i = 0 ; i < n ; i ++)
        {
            sum+=grid[0][i];
            dp[i] = sum;
        }
        int sumb = grid[0][0];
        for(int i = 1 ; i < m ; i ++)
        {
            sumb+=grid[i][0];
            dp[0] = sumb;
            for(int j = 1 ; j < n ; j ++)
            {
                dp[j] = min(dp[j],dp[j-1]) + grid[i][j] ;
            }
        }
        return dp[n-1];
    }
   
};