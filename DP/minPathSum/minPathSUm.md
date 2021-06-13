#The description of the question
```txt
给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
```
#Solution
**dp[i][j] = min(dp[i][j-1],dp[i-1][j]) + grid[i][j]**

#Improvement
We can scroll to the array and reduce the consumption of space