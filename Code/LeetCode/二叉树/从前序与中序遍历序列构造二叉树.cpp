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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (inorder.empty() || preorder.empty())
            return nullptr;

        int rootval = preorder[0];
        TreeNode *root = new TreeNode(rootval);

        int index = 0;
        for (; index < inorder.size(); index++)
        {
            if (inorder[index] == rootval)
                break;
        }

        vector<int> leftInorder(inorder.begin(), inorder.begin() + index);
        vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());

        // 创建前序数组的副本，避免修改原始数组
        vector<int> newPreorder(preorder.begin() + 1, preorder.end());

        vector<int> leftPreorder(newPreorder.begin(), newPreorder.begin() + leftInorder.size());
        vector<int> rightPreorder(newPreorder.begin() + leftInorder.size(), newPreorder.end());

        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);

        return root;
    }
};