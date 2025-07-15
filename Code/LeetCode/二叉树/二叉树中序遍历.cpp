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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> tree;
        stack<TreeNode *> stk;
        // 要达到迭代法进行二叉树中序遍历,遵循左中右
        // 先将root左节点压入栈中
        while (root != nullptr || !stk.empty())
        {
            while (root != nullptr)
            {
                stk.push(root);
                root = root->left;
            }
            // 再弹出左节点栈顶,也就是遍历的第一个数
            root = stk.top();
            stk.pop();
            tree.push_back(root->val);

            root = root->right;
        }
        return tree;
    }
};