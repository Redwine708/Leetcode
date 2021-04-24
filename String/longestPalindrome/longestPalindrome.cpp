/**
 * @brief the fifth one in the leetcode
 * @author liuqi
 * @url https://leetcode-cn.com/problems/longest-palindromic-substring/
 * 
 */
#include<string>
#include<cmath>
using namespace std;

namespace CenterSolution{
class Solution
{
  public:
  //calculate the length to expand
   string Expandpalindrome( string s, int left , int right)
   {
       while(left >= 0 && right <= s.size()&&s[left] == s[right])
       {
           left--;right++;
       }
       return s.substr(left + 1, right - left - 1);
   } 
   string longestPalindrome(string s)
   {
       string result("");
       for(int i = 0 ; i<s.size() ; i++)
       {
           //old case
           string k1 = Expandpalindrome(s, i, i);
           //even case
           string k2 = Expandpalindrome(s ,i, i + 1);
           if(k1.length() > result.length())
           {
               result = k1;
           }
           if(k2.length() > result.length())
           {
               result = k2;
           }
       }
       return result;
   }
};
}