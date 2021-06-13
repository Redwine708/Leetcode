/*
 *Problem 26
 *
 */
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0 ) return 0;
        vector<int>::iterator iter = nums.begin();
        int flag = *iter;
        iter++;
        while(iter < nums.end() )
        {
            if(*iter == flag)
            {
                iter = nums.erase(iter);
            }
            else{
                flag  = *iter;
                iter++;
            }
        }
        return nums.size();
    }
};
int main()
{
    vector<int>a(4) ;
    a[0] = 1; a[1] = 1;a[2] =2;a[3] = 2;
    Solution s;
    int t = s.removeDuplicates(a);
    cout<<t;
}