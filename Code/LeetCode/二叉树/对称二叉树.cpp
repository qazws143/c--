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

class Solution
{
public:
    bool symmetric(TreeNode *l, TreeNode *r)
    {
        if (l == nullptr && r == nullptr)
            return true;
        if (l == nullptr || r == nullptr)
            return false;
        if (l->val != r->val)
            return false;
        return symmetric(l->left, r->right) && symmetric(l->right, r->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        return symmetric(root->left, root->right);
    }
};