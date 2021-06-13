#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(); int n = p.size();
        vector< vector<int> > dp( m + 1 , vector<int>(n + 1));
        dp[0][0] = true;
        for(int i = 0 ; i < n ; i ++)
        {
            if(p[i] == '*')dp[0][i + 1] = true;
            else break;
        }
        for(int i = 0 ; i < m  ; i ++)
        {
            for(int j = 0 ; j < n  ; j ++)
            {
                if(s[i] == p[j] || p[j] == '?')
                    dp[i + 1][j + 1] = dp[i][j];
                else if(p[j] == '*')
                {
                    dp[i+1][j+1] = dp[i+1][j] | dp[i][j+1];
                }
            }
        }
        return dp[m][n];
    }
};
int main()
{
    string s;
    string p;
    cin>>s>>p;
    Solution t;
    cout<<t.isMatch(s,p);
}