/*
给定一个二叉树，返回它的前序遍历。
示例：
输入：[1,null,2,3]
   1
    \
     2
    /
   3
输出：[1,2,3]
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
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)
            return res;
        else
        {
            res.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);  
        }
        return res; 
    }
};

/*方法二：迭代法
弹出栈顶元素并输出后先压入右节点再压入左节点。
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
    vector<int> preorderTraversal(TreeNode* root) {
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
                stack.push(tmp->right);  //先压入右子树而不是左子树是根据栈后入先出的特点
                stack.push(tmp->left);
            }
        }
        return res;
    }
};
