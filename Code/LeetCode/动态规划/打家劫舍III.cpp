#include "vector"
#include "algorithm"
#include <cstdio>
#include <cstring>

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
    int rob(TreeNode *root)
    {
        // 数组大小为2，0表示不偷，1表示偷
        vector<int> dp = robTree(root);
        return max(dp[0], dp[1]);
    }

    vector<int> robTree(TreeNode *cur)
    {
        if (cur == nullptr)
            return {0, 0};
        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);
        // 如果偷根节点
        int val1 = cur->val + left[0] + right[0];
        // 如果不偷根节点
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);
        return {val2, val1};
    }
};