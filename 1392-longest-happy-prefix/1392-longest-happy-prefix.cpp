class Solution {
public:
    string longestPrefix(string s) {
        long long prefix = 0;
        long long suffix = 0;
        
        long long power = 1;
        long long mod = 1000000007;
        long long base = 31;
        
        int ans = 0;
        int n = s.size();

        for (int i = 0; i < n - 1; i++) {
            // Prefix hash
            prefix = (prefix * base + (s[i] - 'a' + 1)) % mod;

            // Suffix hash
            suffix = (suffix + (s[n - 1 - i] - 'a' + 1) * power) % mod;

            if (prefix == suffix) {
                ans = i + 1;
            }

            power = (power * base) % mod;
        }

        return s.substr(0, ans);
    }
};