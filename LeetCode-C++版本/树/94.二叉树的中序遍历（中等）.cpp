/*
给定一个二叉树，返回它的中序遍历（左->中->右）。
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
基于栈的遍历，不断压入左节点后更新为右节点重复。
时间复杂度：Ｏ(n)
空间复杂度：Ｏ(n)
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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stack;  //存放未遍历完成的点
        while(root != nullptr || !stack.empty())
        {
            while(root)  //遍历左子树，直至root为空
            {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();  //左子树为空，可以输出root
            stack.pop();
            res.push_back(root->val);
            root = root->right;  //如果root->right为空，下次循环继续弹出栈顶元素
        }
        return res;
    }
};
