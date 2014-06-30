// Given a string s, partition s such that every substring of the partition is a palindrome.

// Return all possible palindrome partitioning of s.

// For example, given s = "aab",
// Return

//   [
//     ["aa","b"],
//     ["a","a","b"]
//   ]

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > res;
        int len = s.size();
        if(!len) return res;
        vector<vector<bool> > P(len, vector<bool>(len, false));
        vector<string> sol;
        helper(s, 0, sol, res, P);
        return res;
    }
    
    void helper(string s, int startIdx, vector<string> &sol, vector<vector<string> > &res, vector<vector<bool> > &P) {
        if(startIdx == s.size()) {
            res.push_back(sol);
            return;
        }
        for(int i = startIdx; i < s.size(); ++i) {
            if(s[i] == s[startIdx] && (i-startIdx < 2 || P[startIdx+1][i-1])) {
                P[startIdx][i] = true;
                sol.push_back(s.substr(startIdx, i-startIdx+1));
                helper(s, i+1, sol, res, P);
                sol.pop_back();
            }
        }
    }
};
