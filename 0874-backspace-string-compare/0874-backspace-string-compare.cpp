class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string resultS, resultT;

        // Process string S
        for (char ch : S) {
            if (ch == '#' && !resultS.empty()) {
                resultS.pop_back();
            } else if (ch != '#') {
                resultS.push_back(ch);
            }
        }

        // Process string T
        for (char ch : T) {
            if (ch == '#' && !resultT.empty()) {
                resultT.pop_back();
            } else if (ch != '#') {
                resultT.push_back(ch);
            }
        }

        return resultS == resultT;
    }
};
