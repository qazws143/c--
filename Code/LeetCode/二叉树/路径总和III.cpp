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
    unordered_map<long long, int> tree;
    int dfs(TreeNode *node, long long cursum, long sum)
    {
        if (node == nullptr)
            return 0;
        int ret = 0;         // 记录符合要求的路径和个数
        cursum += node->val; // 计算路径和
        if (tree.count(cursum - sum))
            ret = tree[cursum - sum];

        tree[cursum]++; // 将当前和加入哈希表
        ret += dfs(node->left, cursum, sum);
        ret += dfs(node->right, cursum, sum);
        tree[cursum]--;

        return ret;
    }
    int pathSum(TreeNode *root, long targetSum)
    {
        tree[0] = 1; // 前缀和为0的有一个
        return dfs(root, 0, targetSum);
    }
};