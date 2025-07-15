#include "vector"
#include "stack"

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> tree;
        if (!root)
            return tree;
        TreeNode *prev = nullptr; // 记录前一个访问节点
        stack<TreeNode *> stk;
        while (root || !stk.empty())
        {
            // 将左边节点压入栈中
            while (root)
            {
                stk.push(root);
                root = root->left;
            }
            TreeNode *node = stk.top();
            if (node->right && node->right != prev)
                root = node->right;
            else
            {
                tree.push_back(node->val);
                prev = node;
                stk.pop();
            }
        }
        return tree;
    }
};