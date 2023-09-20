class Solution {
public:
bool solve(int i, int j, string p, string t, vector<vector<int>> &dp) {
  if (i < 0 && j < 0)
    return true;
  if (i < 0 && j >= 0)
    return false;
  if (j < 0 && i >= 0) {
    for (int ii = 0; ii <= i; ii++) {
      if (p[ii] != '*') 
        return false;
    }
    return true;
  }
  if (dp[i][j] != -1)
    return dp[i][j];

  if (p[i] == t[j] || p[i] == '?')
    return dp[i][j] = solve(i - 1, j - 1, p, t, dp);
  if (p[i] == '*') {
    return dp[i][j] = solve(i - 1, j, p, t, dp) || solve(i, j - 1, p, t, dp);
  }
  return dp[i][j] = false;
}
bool solveBU(string p, string t) {

  vector<vector<int>> dp(p.size() + 1, vector<int>(t.size() + 1, 0));
  dp[0][0] = 1;

  for (int j = 1; j <= t.length(); j++)
    dp[0][j] = 0;

  for (int i = 1; i <= p.length(); i++) {
    bool flag = true;
    for (int ii = 0; ii <= i; ii++) {
      if (p[ii] != '*')
        flag = false;
      break;
    }
    dp[i][0] = flag;
  }

  for (int i = 1; i <= p.size(); i++) {
    for (int j = 1; j <= t.size(); j++) {
      if (p[i - 1] == t[j - 1] || p[i - 1] == '?')
        dp[i][j] = dp[i - 1][j - 1];
      else if (p[i - 1] == '*') {
        dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
      } else
        dp[i][j] = false;
    }
  }

  return dp[p.size()][t.size()];
}

bool lcsol(string s,string p){
  vector<vector<bool>> dp(s.size() + 1, vector(p.size() + 1, false));
        dp[0][0] = true;
        for (int j = 0; j < p.size() && p[j] == '*'; ++j) {
            dp[0][j + 1] = true;
        }
        
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 1; j <= p.size(); ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && dp[i - 1][j - 1];
                }
            }
        }

        return dp[s.size()][p.size()];
}
bool wildcardMatching(string p, string t) {
  //   int i = p.size() - 1, j = t.length() - 1;
  //   vector<vector<int>> dp(i + 2, vector<int>(j + 2, -1));
  //   return solve(i, j, p, t, dp);
  // return solveBU(p, t);.
  return lcsol(p,t);
  
}
    bool isMatch(string s, string p) {
        return lcsol(s,p);
    }
};