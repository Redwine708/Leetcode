#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int> m;
        m.push(-1);
        for(int i = 0 ; i < s.length() ; i ++)
        {
            if(s[i] == '(')
                m.push(i);
            else 
            {
                m.pop();
                if(m.empty())
                {
                   m.push(i);
                }
                else
                {
                    ans = max(ans,i - m.top()) ;
                }
            }
        }
        return ans;
    }
};
int main()
{
    string t = "()()";
    Solution s;
    cout<<s.longestValidParentheses(t);
}