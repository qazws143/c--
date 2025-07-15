#include "vector"
#include "algorithm"

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        // 后序遍历
        if (root == nullptr)
            return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        int nums = 1 + max(left, right);
        return nums;
    }
};