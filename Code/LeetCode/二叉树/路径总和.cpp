#include "vector"
#include "algorithm"
#include "unordered_map"

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
    bool triverl(TreeNode *node, int count)
    {
        if (node->left == NULL &&
            node->right == NULL &&
            count == 0)
            return true;
        if (node->left == NULL &&
            node->right == NULL &&
            count != 0)
            return false;
        if (node->left)
        {
            count -= node->left->val;
            if (triverl(node->left, count) == true)
                return true;
            count += node->left->val;
        }
        if (node->right)
        {
            count -= node->right->val;
            if (triverl(node->right, count) == true)
                return true;
            count += node->right->val;
        }
        return false;
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return false;
        return triverl(root, targetSum - root->val);
    }
};