#include "vector"
#include "queue"
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
    vector<int> rightSideView(TreeNode *root)
    {
        queue<TreeNode *> que;
        vector<int> result;
        if (!root)
            return result;
        // 使用层序遍历
        que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                root = que.front();
                que.pop();
                // 找到每一层最后一个元素
                if (i == size - 1)
                {
                    result.push_back(root->val);
                }
                if (root->left)
                    que.push(root->left);
                if (root->right)
                    que.push(root->right);
            }
        }
        return result;
    }
};