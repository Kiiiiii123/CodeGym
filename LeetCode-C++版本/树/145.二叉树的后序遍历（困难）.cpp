/*
给定一个二叉树，返回它的后序遍历（左->右->中）。
示例：
输入：[1,null,2,3]
   1
    \
     2
    /
   3
输出：[3,2,1]
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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)
            return res;
        else
        {
            postorderTraversal(root->left);
            postorderTraversal(root->right);  
            res.push_back(root->val);
 
        }
        return res; 
    }
};

/*方法二：迭代法
按照与前序相似的方法（前序压栈的顺序是先右后左，这里是先左后右），先得到一个结果，然后对结果倒序一下。
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stack;
        vector<int> res;
        if(!root)
            return res;
        stack.push(root);
        while(!stack.empty())
        {
            TreeNode* tmp = stack.top();
            stack.pop();
            if(tmp)
            {
                res.push_back(tmp->val);
                stack.push(tmp->left);
                stack.push(tmp->right);
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
