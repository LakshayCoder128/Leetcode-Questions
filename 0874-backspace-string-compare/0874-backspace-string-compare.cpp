// class Solution
// {
//     public:
//         bool backspaceCompare(string s, string t)
//         {
//             string a, b;
//             for (char
//                 const &ch: s)
//             {

//                 if (ch == '#'
//                     and a.size() >= 1) a.pop_back();
//                 else a.push_back(ch);
//             }
//             for (char
//                 const &ch: t)
//                 if (ch == '#'
//                     and b.size() >= 1) b.pop_back();
//                 else b.push_back(ch);
//             if (a[0] == '#')
//             {
//                 if (b[0] == '#')
//                 {
//                     return a.substr(1) == b.substr(1);
//                 }
//                 else
//                 {
//                     return a.substr(1) == b;
//                 }
//             }
//             else if (b[0] == '#')
//             {
//                 if (a[0] == '#')
//                 {
//                     return a.substr(1) == b.substr(1);
//                 }
//                 else
//                 {
//                     return a == b.substr(1);
//                 }
//             }
//             return a == b;
//         }
// };
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
