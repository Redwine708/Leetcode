//LeetCode : dynamic programing 42
//This solution calculate the answear by increment every step 
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        for(int i = 2 ; i < height.size() ; i ++)
        {
            if(height[i] <= height[i-1])continue;
            else{
                //find the maximum height of all height[0...i-1]
                int max = i-2 ;
                for(int j = 0 ; j < i-2 ; j ++)
                {
                    if(height[j] > height[max]) max = j;
                }
                int secMax = height[i];
                if(height[max] < secMax) secMax = height[max];
                for(int m = max + 1 ; m < i ; m ++)
                {
                    if(height[m] < secMax){
                    res += secMax - height[m];
                    height[m] = secMax;
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<int>height(12);
    for(int i = 0 ;  i< 12 ; i ++)
    {
        cin>>height[i];
    }
    Solution s;
    cout<<s.trap(height);
}
//T(^2n)
//O(1)