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
    TreeNode(int x, TreeNode *left = nullptr, TreeNode *right = nullptr) 
                                : val(x), left(left), right(right) {}
};


class Solution
{
    public:
        void inOrder(TreeNode* root, vector<int>& nums)
        {
            if(root == nullptr)return;
            inOrder(root->left,nums);
            nums.push_back(root->val);
            inOrder(root->right,nums);
        }

        pair<int,int> findTwoSwapped(vector<int>&nums)
        {
            //a[i] > a[i+1] a[j] > a[j+1] swap(a[i],a[j+1])
            //if the scrambled element is adjcent and then break the loop
            int n = nums.size();
            int x = -1; int y = -1;
            for(int i = 0; i < n-1 ; i ++)
            {
                if(nums[i+1] < nums[i] ) 
                {
                    y = nums[i+1];
                    if(x == -1)
                    {
                        x = nums[i];
                    }
                    else    
                        break;
                }

            }
            return { x , y };
        }
        
        void recover(TreeNode* root , int count , int x , int y)
        {
            if(root != nullptr)
            {
                if(root->val == x || root -> val == y)
                {
                    //swap two elements.
                    root -> val = ( root->val == x ? y : x);
                    if(--count == 0)return;
                }
                recover(root->left , count , x , y );
                recover(root->right, count , x , y );
            }
            
            
        }

        void recoverTree(TreeNode* node)
        {
            vector<int >nums;
            inOrder(node,nums);
            pair<int ,int >x = findTwoSwapped(nums);
            recover(node,2,x.first,x.second);

        }
};
