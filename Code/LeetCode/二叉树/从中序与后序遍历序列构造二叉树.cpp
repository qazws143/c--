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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.empty() || postorder.empty())
            return nullptr;
        if (postorder.size() == 0)
            return nullptr;
        // 后序遍历最后一个元素为根节点
        int rootvalue = postorder[postorder.size() - 1];
        // 创造新节点接收根节点
        TreeNode *root = new TreeNode(rootvalue);
        if (postorder.size() == 1)
            return root;
        // 找到中序数组切割节点
        int index = 0;
        for (index; index < inorder.size(); index++)
        {
            if (inorder[index] == rootvalue)
                break;
        }
        // 切割中序数组左区间
        vector<int> leftInorder(inorder.begin(), inorder.begin() + index);
        // 切割中序数组右区间
        vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());

        // 去掉根节点
        postorder.resize(postorder.size() - 1);

        // 切割后序数组左区间
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        // 切割后序数组右区间
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        root->left = buildTree(leftInorder, leftPostorder);
        root->right = buildTree(rightInorder, rightPostorder);

        return root;
    }
};