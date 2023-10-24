class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans, 0);
        return ans;
    }
    
    void dfs(TreeNode* node, vector<int>& ans, int level) {
        if (node == NULL) return;
        
        // Ensure the 'ans' vector has a value for the current level.
        if (level >= ans.size()) {
            ans.push_back(node->val);
        } else {
            // Update 'ans' if the current value is larger.
            ans[level] = max(ans[level], node->val);
        }
        
        // Recursively process children with an increased level.
        dfs(node->left, ans, level + 1);
        dfs(node->right, ans, level + 1);
    }
};
