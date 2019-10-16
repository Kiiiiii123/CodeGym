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

/*方法三：使用两个栈
先将节点１放到栈１中后弹出并放到栈２中，节点１的左节点２先进入栈１，后节点１的右节点放入到栈１中，从栈１中弹出节点３放到栈２中，节点３的左右子节点依次放入到栈１中，从栈１中弹出节点７放入到栈２中，节点７无子节点所以继续，从栈１中弹出节点６放入到栈２中，节点６也无子节点所以依然继续，从栈１中弹出节点２放入到栈２中，节点２的左右子节点４和５依次放入到栈１中，从栈１中弹出节点５放入到栈２中，节点５无子节点所以继续，将节点４放入到栈２中，节点４无子节点且栈１为空，过程停止，最后只需要将栈２中的元素依次弹出并输出即可。
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
        vector<int> res;
        stack<TreeNode*> stack1,stack2;
        if(!root)
            return res;
        stack1.push(root);
        TreeNode* tmp;
        while(!stack1.empty())
        {
            tmp = stack1.top();
            stack1.pop();
            stack2.push(tmp);
            if(tmp->left)
                stack1.push(tmp->left);
            if(tmp->right)
                stack1.push(tmp->right);
        }
        while(!stack2.empty())
        {
            res.push_back(stack2.top()->val);
            stack2.pop();
        }
        return res;
    }
};

/*方法四：使用一个栈
利用了一个用于判定是否已经弹出的变量pre。
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
        TreeNode* pre = root;  //最近一次弹出并输出的节点
        TreeNode* curr = NULL;
        stack.push(root);
        while(!stack.empty())
        {
            curr = stack.top();  //当前stack的栈顶节点
            if(curr->left && pre != (curr->left) && pre != (curr->right))
            {
                stack.push(curr->left);
            }
            else if(curr->right && pre != (curr->right))
            {
                stack.push(curr->right);                
            }
            else
            {
                stack.pop();              
                res.push_back(curr->val); 
                pre = curr;
            }
        }
        return res;
    }
};
