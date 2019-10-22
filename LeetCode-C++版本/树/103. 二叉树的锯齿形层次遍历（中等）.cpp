/*
给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。例如：给定二叉树 [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下： 
[
  [3],
  [20,9],
  [15,7]
]
*/

/*方法：利用STL
奇数层节点的左子节点先进栈，右子节点后进栈，访问偶数层节点时，顺序相反。这里直接在队列添加完子节点后用布尔变量判断是否翻转数组元素。
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        queue<TreeNode*> q;
        TreeNode* tmp;
        q.push(root);
        bool isReverse = false;
        while(!q.empty())
        {
            vector<int> a;
            int len = q.size();
            for(int i=0;i<len;++i)
            {
                tmp = q.front();
                a.push_back(tmp->val);
                q.pop();
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
            if(isReverse)
                reverse(a.begin(),a.end());
            isReverse=!isReverse;
            res.push_back(a);
        }
        return res;
    }
};
