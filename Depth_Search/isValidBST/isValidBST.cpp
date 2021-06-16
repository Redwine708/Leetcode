/**
 * @file isValidBST.cpp
 * @author your name (you@domain.com)
 * @brief Given the root of a binary tree, determine if it is a valid binary search tree (BST).
 * @version 0.1
 * @date 2021-06-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
    //value
    int val;
    //pointer
    TreeNode *left;
    TreeNode *right;
    //constructor function
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left = nullptr, TreeNode *right = nullptr)
                             : val(x), left(left), right(right) {}
};


class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        return checkBST(root,LLONG_MIN,LLONG_MAX);
    }
    bool checkBST(TreeNode* node , long long int low, long long int high)
    {
        if(node == nullptr)return true;
        if( node->val <= low || node->val >= high) return false;
        return checkBST(node->left,low,node->val) && checkBST(node->right,node->val,high);
    }
};
class Solution {
public:
    bool helper(TreeNode* root, long long lower, long long upper) {
        if (root == nullptr) {
            return true;
        }
        if (root -> val <= lower || root -> val >= upper) {
            return false;
        }
        return helper(root -> left, lower, root -> val) && helper(root -> right, root -> val, upper);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};