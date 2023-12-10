/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<vector < int>> levelOrder(TreeNode *root)
        {
            if (!root) return {};
            queue<TreeNode*> q;
            q.push(root);
            q.push(NULL);
            vector<vector < int>> levelO;
            vector<int> temp;
            while (!q.empty())
            {
                TreeNode *front = q.front();
                q.pop();
                if (front == NULL)
                {
                    levelO.push_back(temp);
                    temp.clear();
                    if (!q.empty()) q.push(NULL);
                }
                else
                {
                    temp.push_back(front->val);
                    if (front->left) q.push(front->left);
                    if (front->right) q.push(front->right);
                }
            }
            return levelO;
        }
};