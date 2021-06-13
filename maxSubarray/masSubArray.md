# Problem description
```
LeetCode: offer problem 42
Enter an integer array in which one or more consecutive integers form a subarray.
Find the maximum value of the sum of all the subarrays.
```

# Solution
```
We can use dynamic programing to solve it.
Because when we calculate the maximum value of the sum of the subarrays which has n integers,
we can calculate it from the subarrays which has n-1 integers.
```
* dp[i] = dp[i-1] + vec[i] : (dp[i-1] < 0>) When the sum of the n-1-length subarrays is negative.
* dp[i] = vec[i] :(dp[i-1] >=0) When the sum of the n-1-length subarrays is positive.

# Conclusion
When a problem has optimal structure or it can use the result of the previous step, we can use
dynamic programing.
And we can use the method to solve many problems.