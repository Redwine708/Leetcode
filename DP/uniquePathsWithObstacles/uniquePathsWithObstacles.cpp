#include<vector>
using namespace std;
//Normal dp uses two-dimensional array
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector< vector<int> >dp(m,
                    vector<int>(n,1)  );
        int flag = 1;
        for(int i = 0 ; i < m ; i ++)
        {
            if(flag && obstacleGrid[i][0] == 0)
            {
                dp[i][0] = 1;
            }
            else{
                flag = 0;
                dp[i][0] = 0;
            }
        }
        flag = 1;
        for(int i = 0 ;i < n; i ++)
        {
            if(flag&& obstacleGrid[0][i] == 0)
            {
                dp[0][i] = 1;
            }
            else{
                flag = 0;
                dp[0][i] = 0;
            }
        }
        for(int i = 1 ; i < m ;  i++ )
        for(int j = 1 ; j < n ; j++ )
        {
            if(obstacleGrid[i][j] == 1)
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
                
        }
        return dp[m-1][n-1];
    }
};
//scroll to the array
class Solution2 {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid.at(0).size();
        vector <int> f(m);

        f[0] = (obstacleGrid[0][0] == 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    f[j] = 0;
                    continue;
                }
                if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0) {
                    f[j] += f[j - 1];
                }
            }
        }

        return f.back();
    }
};

