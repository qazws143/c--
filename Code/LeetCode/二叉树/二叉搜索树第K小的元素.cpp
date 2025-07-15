#include "vector"
#include "stack"
#include "algorithm"

using namespace std;

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
    int kthSmallest(TreeNode *root, int k)
    {
        // 中序遍历
        stack<TreeNode *> stk;
        int kthval; // 记录第k小的数
        while (root != nullptr || !stk.empty())
        {
            while (root != nullptr)
            {
                stk.push(root);
                root = root->left;
            } // 先遍历左树
            root = stk.top();
            stk.pop();
            if (--k == 0)
            {
                return root->val; // 当k为0时找到第k小的数,返回值
            }
            root = root->right;
        }
        return -1;
    }
};