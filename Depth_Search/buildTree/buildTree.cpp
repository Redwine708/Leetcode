#include<iostream>
#include<vector>
#include<unordered_map>
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

class Solution {
private:
    unordered_map<int , int >index;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i = 0 ; i < n ; i ++)
        {
            index[inorder[i]] = i;
        }
        return myBuildTree(preorder,inorder,0,n-1,0,n-1);
    }
    TreeNode* myBuildTree(vector<int>& preorder,vector<int>&inorder  
                                ,int preorder_left,int preorder_right
                                ,int inorder_left,int inorder_right)
    {
        if(preorder_left > preorder_right)
            return nullptr;
        //demarcation point
        int myTree_root = index[ preorder[preorder_left] ];
        //new node
        int subsTree_length = myTree_root - inorder_left;
        TreeNode* newNode = new TreeNode(preorder[preorder_left]);

        newNode->left = myBuildTree(preorder,inorder,
                        preorder_left + 1,preorder_left + subsTree_length,
                            inorder_left, myTree_root - 1);
        
        newNode->right = myBuildTree(preorder,inorder,
                        preorder_left + subsTree_length + 1 , preorder_right,
                        myTree_root + 1 , inorder_right);
        //return the newNode to become the sub_left_tree of the node or the sub_right_tree
        return newNode;
    }
};