
class Solution {
public:
    int magicalString(int n) {
        if (n <= 3) return 1;

        vector<int> s(n);
        s[0] = 1;
        s[1] = 2;
        s[2] = 2;

        int i = 2;
        int len = 3;
        int num = 1;
        int ans = 1;

        while (len < n) {
            for (int j = 0; j < s[i] && len < n; j++) {
                s[len] = num;

                if (num == 1) {
                    ans++;
                }

                len++;
            }

            num = 3 - num;
            i++;
        }

        return ans;
    }
};
