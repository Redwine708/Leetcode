/**
 * @file searchInsert.cpp
 * @author your name (you@domain.com)
 * @brief floor_binarySearch  return the index of the number that is bigger or equals to x
 * @version 0.1
 * @date 2021-06-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //mid index
        int mid = 0;
        int left = 0; int right = nums.size();
        while(left < right)
        {
            mid = (left + right) / 2;
            if(nums[mid] == target) return mid;
            else if( target < nums[mid]){
                right = mid;
            }
            else left = ++mid;
        }
        // if(left == nums.size() - 1) return ++left;
        return left;
    }
};