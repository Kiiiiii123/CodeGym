/*
翻转一棵二叉树。示例：
输入：
     4
   /   \
  2     7
 / \   / \
1   3 6   9
输出：
     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/

/*方法一：深度优先搜索DFS
栈存储，左右节点进行交换，循环翻转每个节点的左右子节点，将未翻转的子节点存入栈中，循环直到栈里所有节点都循环交换完为止。
1、判断根结点是否为空，为空则返回NULL；
2、新建栈，用于节点存储，初始存入根节点到栈里；
3、while循环，栈为空时结束循环；
（１）出栈一个节点，将该节点的左右子节点交换；
（２）判断左右子节点是否为NULL，非NULL则继续将左右节点入栈；
4、循环交换结束，返回根节点;
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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return NULL;
        stack<TreeNode*> stack;
        stack.push(root);
        while(!stack.empty())
        {
            TreeNode* curr = stack.top();
            TreeNode* tmp = curr->left;
            curr->left = curr->right;
            curr->right = tmp;
            stack.pop();
            if(curr->left)
                stack.push(curr->left);
            if(curr->right)
                stack.push(curr->right);
        }
        return root;
    }
};

/*方法二：广度优先搜索BFS
队列存储，左右节点进行交换，循环翻转每个节点的左右子节点，将未翻转的子节点存入队列中，循环直到队列里所有节点都循环交换完为止。
１、判断根结点是否为空，为空则返回NULL；
２、新建队列，用于节点存储，初始存入根节点到队列里；
３、while循环，队列为空时结束循环；
（１）出队列一个节点，将该节点的左右子节点交换；
（２）判断左右子节点是否为NULL，非NULL续将左右节点入队列；
４、循环交换结束，返回根节点;
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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            TreeNode* tmp = curr->left;
            curr->left = curr->right;
            curr->right = tmp;
            q.pop();
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
        return root;
    }
};

/*方法三：递归
１、判断节点是否为空，为空则返回NULL;
２、交换根节点的左右节点；
３、递归交换左右子树。
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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return NULL;
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
