#include<iostream>
#include<vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
namespace easy
{
    class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }

    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        // 总是选择中间位置左边的数字作为根节点
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, left, mid - 1);
        root->right = helper(nums, mid + 1, right);
        return root;
    }
};
}
class Solution
{
private:
    TreeNode* root;
    void preOrder(TreeNode* node)
    {
        if(node == nullptr)return;
        // cout<<node->val<<" ";
        preOrder(node->left);
        cout<<node->val<<" ";
        preOrder(node->right);
    }
public:
    Solution()
    {
        root = nullptr;
    }
    TreeNode* insert(TreeNode* node,int value)
    {
        if(node == nullptr)
        {
            return new TreeNode(value);
        }
        else
        {
            if(value < node->val)
            {
                node->left = insert(node->left, value);
            }
            else
            {
                node->right = insert(node->right,value);
            }
        }
        return balance(node);
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        for(int i = 0 ; i < nums.size() ; i++)
        {
            root = insert(root,nums[i]);
        }
        return root;
    }
    TreeNode* leftRotate(TreeNode* node)
    {
        if(node == nullptr)return nullptr;
        TreeNode* temp = node->right;
        node->right = temp->left;
        temp->left = node;
        return temp;
    }
    TreeNode* rightRotate(TreeNode* node)
    {
        if(node==nullptr)return nullptr;
        TreeNode* temp = node->left;
        node->left = temp->right;
        temp->right = node;
        return temp;
    }
    int getHeight(TreeNode* node)
    {
        if(node == nullptr) return 0;
        int m = getHeight(node->left) + 1;
        int n = getHeight(node->right) + 1;
        return m > n ? m : n ;
    }
    int getBalanceFactor(TreeNode* node)
    {
        if(node == nullptr) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }
    TreeNode* balance(TreeNode* node)
    {
        if(node == nullptr)return nullptr;
        if(getBalanceFactor(node) == 2)
        {
            if(getBalanceFactor(node->left) == 1)
            {
                node = rightRotate(node);
            }
            else 
            {
                node->left = leftRotate(node->left);
                node = rightRotate(node);
            }
        }
        else if(getBalanceFactor(node) == -2)
        {
            if(getBalanceFactor(node->right) == -1)
            {
                node = leftRotate(node);
            }
            else
            {
                node->right = rightRotate(node->right);
                node = leftRotate(node);
            }
        }
        return node;
    }
    void preOrder()
    {
        preOrder(root);
    }
};
int main()
{
    vector<int> nums(5);
    for(int i = 0  ; i< nums.size() ; i++)
    {
        nums[i] = i+1;
    }
    Solution t;
    t.sortedArrayToBST(nums);
    t.preOrder();
}