/*
 *Problem 72 
 */
#include<string>
#include<cmath>
#include<iostream>
using namespace std;
class Solution {
public:
    int Min(int a, int b)
    {
        if(a<b)return a;
        else return b;
    }
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        int**D = new int*[n+1];
        for(int i =0 ; i<n+1;i++)
        {
            D[i] = new int [m+1];
        }
        if(n*m == 0)return n + m;
        for(int i = 0; i< n + 1 ; i++)
        {
            D[i][0] = i;
        }
        for(int i = 0; i < m + 1 ; i++)
        {
            D[0][i] = i;
        }
//状态转移
        for(int i = 1 ; i < n + 1 ; i++ )
        for(int j = 1 ; j < m + 1 ; j++)
        {
            
           D[i][j] = Min(
               //注意要转为bool类型，不然返回的是0
               D[i-1][j] + 1 , Min(D[i][j-1] + 1 , D[i-1][j-1] + bool(word1[i-1] != word2[j-1]))
           );
        }
        return D[n][m];
    }
};
int main()
{
    string A = "horse";
    string B = "ros";
    Solution ss;
    cout<<ss.minDistance(A,B);
}