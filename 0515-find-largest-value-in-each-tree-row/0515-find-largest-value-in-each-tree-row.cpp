class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        stack<pair<TreeNode*, int>> s; // Stack with node and corresponding level
        s.push({root, 0});
        
        while (!s.empty()) {
            TreeNode* node = s.top().first;
            int level = s.top().second;
            s.pop();
            
            // Ensure the 'ans' vector has a value for the current level.
            if (level >= ans.size()) {
                ans.push_back(node->val);
            } else {
                // Update 'ans' if the current value is larger.
                ans[level] = max(ans[level], node->val);
            }
            
            if (node->left) {
                s.push({node->left, level + 1});
            }
            if (node->right) {
                s.push({node->right, level + 1});
            }
        }
        return ans;
    }
};