/*
给定一个二叉树，返回它的中序遍历。
示例：
输入：[1,null,2,3]
   1
    \
     2
    /
   3
输出：[1,3,2]
进阶：递归算法很简单，你可以通过迭代算法完成吗？
*/

/*方法一：递归法
时间复杂度：Ｏ(n)　递归函数T(n) = 2T(n/2)+1。
空间复杂度：最坏情况下需要Ｏ(n)，平均情况下需要Ｏ(lgn)。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<int> res;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr)
            return res;
        else
        {
            inorderTraversal(root->left);
            res.push_back(root->val);
            inorderTraversal(root->right);
        }
        return res;
    }
};

/*方法二：非递归方法
基于栈的遍历
时间复杂度：Ｏ(n)
空间复杂度：Ｏ(n)
*/


