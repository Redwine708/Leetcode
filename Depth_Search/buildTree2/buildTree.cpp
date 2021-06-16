#include<vector>
#include<unordered_map>
using namespace std;
//This question is the same as the question that according to inorder and preorder to rebuild the
//tree
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

class Solution
{
private:
    unordered_map<int ,int > index;
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        for(int i = 0 ; i < n ; i ++)
        {
            index[inorder[i]] = i;
        }
        return myTree(inorder,postorder,0,n-1,0,n-1);
    }
    TreeNode* myTree(vector<int>& inorder, vector<int>& postorder,
                    int inorder_left , int inorder_right,
                    int postorder_left, int postorder_right)
    {
        if(postorder_left > postorder_right)
        {
            return nullptr;
        }
        int inorder_root = index[postorder[postorder_right]];
        int subTreeLength = inorder_root - inorder_left;
        TreeNode* newNode = new TreeNode(postorder[postorder_right]);
        newNode->left = myTree(inorder,postorder,   
                        inorder_left,inorder_root - 1,
                        postorder_left,postorder_left + subTreeLength - 1);
        newNode->right = myTree(inorder,postorder,
                        inorder_root+1,inorder_right,
                        postorder_left+subTreeLength ,postorder_right - 1);
        return newNode;
    }
};
