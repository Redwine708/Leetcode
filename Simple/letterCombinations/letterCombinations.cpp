/*
 *Problem17
 *Deep find search 
 */
#include<string>
#include<vector>
#include<iostream>
using namespace std;
class Solution
{
    public:
        string tmp;
        vector<string>result;
        vector<string> table= {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        void DFS(int pos , string& digits)
        {
            if(pos == digits.size())
            {
                result.push_back(tmp);
                return;
            }
            int num = digits[pos] - '0';
            for(int i = 0 ; i < table[num].size()  ; i++)
            {
                tmp.push_back(table[num][i]);
                DFS(pos+1,digits);
                tmp.pop_back();
            }
        }
        vector<string>& letterCombinations(string& digits)
        {
            if(digits.size() == 0)return result;
            DFS(0,digits);
            return result;
        }
};
// FULL Permutation
string tmp;
vector<string> res = {"123","456","789"};
void DeepFindSearch(int degree){
    if(degree == 3) 
    {
        cout<<tmp<<" ";
        return;
    }
    for(int i = 0 ; i < res[degree].size() ; i++)
    {
        tmp.push_back(res[degree][i]);
        DeepFindSearch(degree+1);
        tmp.pop_back();
    }
}
int main()
{
    DeepFindSearch(0);
}