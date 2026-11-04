class Solution {
public:
    int minSteps(int i, int j, string &a, string &b, vector<vector<int>>& dp) {
        if (i == 0) return j;      
        if (j == 0) return i;  
        
        if (dp[i][j] != -1) return dp[i][j];

        if (a[i-1] == b[j-1]) {
            return dp[i][j] = minSteps(i-1, j-1, a, b, dp);
        } else {
            int del = minSteps(i-1, j, a, b, dp);      
            int ins = minSteps(i, j-1, a, b, dp);      
            int rep = minSteps(i-1, j-1, a, b, dp);   

            return dp[i][j] = 1 + min({del, ins, rep});
        }
    }

    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size(); 
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return minSteps(m, n, word1, word2, dp);
    }
};