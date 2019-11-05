/*
给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）。例如：给定二叉树 [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：
[
  [15,7],
  [9,20],
  [3]
]
*/

/*方法：使用STL
利用二叉树的层次遍历的解法，将最后的res进行reverse(res.begin(),res.end())，快速解决。
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        queue<TreeNode*> Q;
        TreeNode* tmp;
        Q.push(root);
        while(!Q.empty())
        {
            vector<int> a;
            int len = Q.size();
            for(int i=0;i<len;++i){
                tmp = Q.front();
                a.push_back(tmp->val);
                Q.pop();
                if(tmp->left)
                    Q.push(tmp->left);
                if(tmp->right)
                    Q.push(tmp->right);
            }
            res.push_back(a); 
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
