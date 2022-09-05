class Solution
{
    public:
        int trap(vector<int> &height)
        {
            stack<int> s;
            int total = 0;

            for (int i = 0; i < height.size(); i++)
            {
                while (!s.empty() && height[s.top()] < height[i])
                {
                    int removedInd = s.top();
                    s.pop();
                    if (s.empty()) break;

                    int heightVal = min(height[i], height[s.top()]) - height[removedInd];
                    int length = i - s.top() - 1;
                    total += heightVal * length;
                }
                s.push(i);
            }
            return total;
        }
};