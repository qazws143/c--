#include "vector"
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

// 前序遍历
class Solution
{
public:
    bool isValidBST(TreeNode *root, long long left = LLONG_MIN, long long right = LLONG_MAX)
    {
        if (root == nullptr)
            return true;
        long long x;
        x = root->val;
        return x > left &&
               x < right &&
               isValidBST(root->left, left, x) &&
               isValidBST(root->right, x, right);
    }
};

// 中序遍历
class Solution
{
public:
    long long pre = LLONG_MIN;
    bool isValidBST(TreeNode *root)
    {
        // 需要上一个节点小于当前节点
        if (root == nullptr)
            return true;
        if (!isValidBST(root->left))
            return false;
        if (root->val <= pre)
            return false;
        pre = root->val;
        return isValidBST(root->right);
    }
};