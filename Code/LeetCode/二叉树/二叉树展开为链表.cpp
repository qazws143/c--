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
    void flatten(TreeNode *root)
    {
        TreeNode *cur = root; // 保存根节点
        while (cur)           // 遍历直到结束
        {
            if (cur->left) // 是否存在左子树
            {
                TreeNode *precur = cur->left;
                while (precur->right) // 检测是否有右子树
                {
                    precur = precur->right;
                }
                // 将左子树移向右子树
                precur->right = cur->right;

                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur = cur->right;
        }
    }
};