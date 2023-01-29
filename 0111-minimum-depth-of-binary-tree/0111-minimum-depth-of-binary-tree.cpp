/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:

        void f(TreeNode *root, int count, int &ans)
        {
            if (root == NULL)
            {
                return;
            }
            if (root->left == NULL && root->right == NULL)
            {
                if (ans == -1) ans = count;
                else ans = min(ans, count);
                return;
            }

            count++;
            f(root->left, count, ans);
            f(root->right, count, ans);
            return;
        }
    int minDepth(TreeNode *root)
    {
        if (root == NULL) return 0;
        int count = 1;
        int ans = -1;
        f(root, count, ans);
        return ans;
    }
};