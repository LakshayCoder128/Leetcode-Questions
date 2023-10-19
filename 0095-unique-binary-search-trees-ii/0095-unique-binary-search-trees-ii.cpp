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
        vector<TreeNode*> solve(int start, int end)
        {
            if (start > end) return {
                NULL
            };
            if (start == end)
            {
                TreeNode *root = new TreeNode(start);
                return {
                    root
                };
            }

           	// if(dp[{start,end}] != NULL}) return dp[{start,end}];

            vector<TreeNode*> result;
            for (int i = start; i <= end; i++)
            {
                vector<TreeNode*> left_bst = solve(start, i - 1);
                vector<TreeNode*> right_bst = solve(i + 1, end);

                for (TreeNode *leftRoot: left_bst)
                {
                    for (TreeNode *rightRoot: right_bst)
                    {
                        TreeNode *root = new TreeNode(i);
                        root->left = leftRoot;
                        root->right = rightRoot;
                        result.push_back(root);
                    }
                }
            }
            return result;
        }

    map<pair<int, int>, vector< TreeNode*>> dp;

    vector<TreeNode*> MemoSolve(int start, int end)
    {
        if (start > end) return {
            NULL
        };
        if (start == end)
        {
            TreeNode *root = new TreeNode(start);
            return {
                root
            };
        }

       	if(dp.find({start,end}) != dp.end()) return dp[{start,end}];

        vector<TreeNode*> result;
        for (int i = start; i <= end; i++)
        {
            vector<TreeNode*> left_bst = MemoSolve(start, i - 1);
            vector<TreeNode*> right_bst = MemoSolve(i + 1, end);

            for (TreeNode *leftRoot: left_bst)
            {
                for (TreeNode *rightRoot: right_bst)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = leftRoot;
                    root->right = rightRoot;
                    result.push_back(root);
                }
            }
        }
        return dp[{start,end}] = result;
    }

    vector<TreeNode*> generateTrees(int n)
    {
       	// map<pair<int,int>,vector<TreeNode*>>dp(n+1,vector<TreeNode*>(n+1,NULL));
        return solve(1, n);
    }
};