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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> que;
        vector<vector<int>> result;
        if (root == nullptr)
            return result;
        que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            vector<int> levelNodes;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                levelNodes.push_back(node->val);
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            result.push_back(levelNodes);
        }
        return result;
    }
};