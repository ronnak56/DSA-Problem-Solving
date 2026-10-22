class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();

        if (n == 0) return "";
        string rev = s;
        reverse(rev.begin(), rev.end());

        string temp = s + "#" + rev;

        vector<int> lps(temp.size(), 0);

        for (int i = 1; i < temp.size(); i++) {
            int j = lps[i - 1];

            while (j > 0 && temp[i] != temp[j]) {
                j = lps[j - 1];
            }

            if (temp[i] == temp[j]) {
                j++;
            }
            lps[i] = j;
        }

        int len = lps.back();

        string remaining = s.substr(len);
        reverse(remaining.begin(), remaining.end());

        return remaining + s;
    }
};