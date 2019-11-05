/*
给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。例如：给定二叉树: [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：
[
  [3],
  [9,20],
  [15,7]
]
*/

/*方法：广度优先搜索BFS
二叉树的层次遍历思路，借助队列来实现，相当于广度优先搜索。若根节点为空，直接返回；根节点非空，则将根节点入队，然后判断其左右子节点是否为空，若不为空，则压入队列。此时将根节点打印输出，并将根节点出队列。依次循环执行，直到队列为空。
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
    vector<vector<int>> levelOrder(TreeNode* root) {
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
        return res;
    }
};
