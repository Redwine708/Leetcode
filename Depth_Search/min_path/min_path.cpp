#include <queue>
using namespace std;
// Definition for a binary tree node.
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
public:
    int minDepth(TreeNode *root)
    {
        queue<pair<TreeNode *, int>> q;
        if (root == nullptr)
            return 0;
        q.push(make_pair(root, 1));
        int level = 1;
        while (!q.empty())
        {
            pair<TreeNode *, int> tmp = q.front();
            q.pop();
            if (tmp.first->left == nullptr && tmp.first->right == nullptr)
                return tmp.second;
            if (tmp.first->left)
            {
                q.push(make_pair(tmp.first->left, tmp.second + 1));
            }
            if (tmp.first->right)
            {
                q.push(make_pair(tmp.first->right, tmp.second + 1));
            }
        }
        return 0;
    }
};