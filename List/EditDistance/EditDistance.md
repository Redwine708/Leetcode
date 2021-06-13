# Problem Description
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 

Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.

# ways of solving
**This problem can be solved by dynamic programming**
```
Before establishing the state transition equation,
we should simplify operations we can do.
insert an element in word1 equals to remove an element in word2
remove an element in word1 equals to insert an element in word2
After that we have actual operations
1. insert an element in word2
2. insert an element in word1
3. modify an element in word1
```
```
First: we should define conditions by Dp[i][j] 
       which represents the distance from string word1 to string word2.

Second: we should divide the operations to two parts.
    one :
        the current char word1[i] equals to char word2[j]
        So we only need to calculate Dp[i-1][j-1]

    the other:
        the current char word1[i] don't equal to char word2[j]
        So now we have three ways to operate
        1. calculate D[i][j-1] + 1 (insert an element in word1)
        2. calculate D[i-1][j] + 1 (insert an element in word2)
        3. calculate D[i-1][j-1] + 1 (modify an element in word1)

In conclusion
we can synthesize the above state transition equations.
D[i][j] = min(
    D[i-1][j] + 1 , min( D[i][j-1] + 1 , D[i-1][j-1] + bool(word1[i-1] != word2[j-1]))
) 
          
```
