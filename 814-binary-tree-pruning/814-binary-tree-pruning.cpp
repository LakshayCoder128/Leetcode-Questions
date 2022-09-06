/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *int val;
 *TreeNode * left;
 *TreeNode * right;
 *TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:

        TreeNode* pruneTree(TreeNode *root)
        {
           	// base case : 
            if (!root) return NULL;
           	// go to the leftmost node
            root->left = pruneTree(root->left);
           	// go to the rightmost node 
            root->right = pruneTree(root->right);
           	//check the value of leaf node is 0 
            if (root->val == 0 && !root->left && !root->right) return NULL;
            return root;
        }
};