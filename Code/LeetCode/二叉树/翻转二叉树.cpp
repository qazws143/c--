#include "vector"
#include "algorithm"
#include "stack"
#include "queue"

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

/*递归*/
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;
        // 前序遍历
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        // swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;
        // 中序遍历
        // 遍历左节点后直接与右节点交换
        invertTree(root->left);
        TreeNode *tmp = root->right;
        root->right = root->left;
        root->left = tmp;
        invertTree(root->left);
        return root;
    }
};

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;
        // 后序遍历
        invertTree(root->left);
        invertTree(root->right);
        TreeNode *tmp = root->right;
        root->right = root->left;
        root->left = tmp;
        return root;
    }
};

/*迭代*/
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;
        stack<TreeNode *> stk;
        // 前序迭代
        stk.push(root);
        while (!stk.empty())
        {
            TreeNode *node = stk.top();
            if (node != nullptr)
            {
                stk.pop();
                swap(node->left, node->right);
                if (node->right)
                    stk.push(node->right);
                if (node->left)
                    stk.push(node->left);
            }
        }
        return root;
    }
};
