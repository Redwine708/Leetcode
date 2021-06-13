#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for(auto& x :nums)
        {
            pre = max(pre,pre+x);
            maxAns = max(maxAns,pre);
        }
    }
};
int main()
{
    vector<int> t(100);
    for(int i = 0 ; i < 1 ; i ++)
    {
        cin>>t[i];
    }
    Solution s;
    cout<<s.maxSubArray(t);

}