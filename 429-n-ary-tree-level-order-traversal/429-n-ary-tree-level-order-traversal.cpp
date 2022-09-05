/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
    public:

        vector<vector < int>> levelOrder(Node *root)
        {
           	//Initializing Result Vector
            vector<vector < int>> v;

            if (root == NULL) return v;

           	//Iterative BFS, so using Queue
            queue<Node*> qu;
            qu.push(root);

            while (!qu.empty())
            {
               	//Temporary vector to take the elements of current level
                vector<int> temp;
               	//Basically number of elements at current level ⤵
                int size = qu.size();

                while (size--)
                {
                    Node *current = qu.front();
                   	//Push the current element of current level
                    temp.push_back(current->val);

                   	//if there are children of current element of current level, push them into queue
                    if (current->children.size())
                    {
                        for (int i = 0; i < current->children.size(); i++)
                        {
                            qu.push(current->children[i]);
                        }
                    }
                   	//Since we have recorded the current element in temp vector and it's children in queue, pop it off!
                    qu.pop();
                }
               	//All elements recorded in temp, push it to result vector
                v.push_back(temp);
            }

            return v;
        }
};