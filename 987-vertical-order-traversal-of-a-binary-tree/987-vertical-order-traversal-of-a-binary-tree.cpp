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
// class Solution
// {
//     public:
//         vector<vector < int>> verticalTraversal(TreeNode *root)
//         {
//             map<int, map<int, set< int>>> m;
//             queue<pair<TreeNode*, pair<int, int>>> q;

//             vector<vector < int>> ans;
//             if (root == NULL)
//             {
//                 return ans;
//             }

//             q.push(make_pair(root, make_pair(0, 0)));

//             while (!q.empty())
//             {

//                 pair<TreeNode*, pair<int, int>> temp = q.front();
//                 q.pop();
//                 TreeNode *frontNode = temp.first;

//                 int hd = temp.second.first;
//                 int lvl = temp.second.second;

//                 m[hd][lvl].insert(frontNode->val);

//                 if (frontNode->left)
//                 {
//                     q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));
//                 }
//                 if (frontNode->right)
//                 {
//                     q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
//                 }
//             }
//             for (auto i: m)
//             {
//                 vector<int> ans1;

//                 for (auto j: i.second)
//                 {
//                     ans1.insert(ans1.end(), j.second.begin(), j.second.end());
//                 }
//                 ans.push_back(ans1);
//             }
//             return ans;
//         }
// };

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0, 0}});
        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;
            nodes[x][y].insert(node -> val);
            if (node -> left) {
                todo.push({node -> left, {x - 1, y + 1}});
            }
            if (node -> right) {
                todo.push({node -> right, {x + 1, y + 1}});
            }
        }
        vector<vector<int>> ans;
        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};