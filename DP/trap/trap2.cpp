//This solution will calculate the height consecutively
//show it by two pointers
//height[left] < heigh[right]equals to leftMax < rightMax
//So the leftMax[i] must be smaller than rightMax[i]
//So we can increas res by leftMax - height[left]
//That is the subtlety of this solution
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
       int res = 0;
       //left  : left pointer
       //right : right pointer
       //leftMax  : the maximum of the left vector from left to right
       //rightMax 
       int left = 0 ; int right = height.size() - 1;
       int leftMax = 0 ; int rightMax = 0;
       while(left < right)
       {
           leftMax = max(height[left],leftMax)   ;
           rightMax = max(height[right],rightMax);
           if(height[left] <= height[right])
           {
               res += leftMax - height[left];
               left++;
           }
           else 
           {
               res += rightMax - height[right];
               right--;
           }
       }
       return res;
    }
       
};