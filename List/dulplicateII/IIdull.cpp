#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator iter = nums.begin();
        iter++;
        int temp = nums[0];
        for( ; iter!=nums.end() ; iter++)
        {
            if( *iter == temp ) 
            {
                iter = nums.erase(iter);
                continue;
            }
            else{ temp = *iter;}
        }
        return nums.size();
    }
};
vector<int>nums(100,0);
int main()
{
    for(int i = 0 ; i < 5; i++)
    {
        nums[i] = i ;
    }
    nums[5] = 4;
    Solution s;
    s.removeDuplicates(nums);
    for(int i = 0 ; i< 20; i++)
    {
        cout<<nums[i];
    }
}