#Description of the question
```txt
给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。
'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符串（包括空字符串）
```
```txt
Definition status : dp[i][j] represents whether the s[0...i-1] and p[0...j-1] match
Two cases:
    first case :
            When p[j] == '?' and s[i]==p[j] , dp[i][j] = dp[i-1][j-1]
    second case：
            When p[j] =='*' dp[i][j] = dp[i][j-1](do not use '*') + dp[i-1][j] (use '*')
```
In fact :
    dp[0][0] represents the special case which string s and string p both are empty string
#Conclusion
```txt
We must write the equation of state first and write state transition of equation
```
