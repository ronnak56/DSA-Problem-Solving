class Solution {
public:
    vector<string> ans;
    vector<string> temp;

    void solve(string &s, int index) {
        // If we have 4 parts
        if (temp.size() == 4) {
            if (index == s.size()) {
                string ip = temp[0] + "." + temp[1] + "." +
                            temp[2] + "." + temp[3];

                ans.push_back(ip);
            }
            return;
        }

        // Try 1, 2, or 3 digits
        for (int len = 1; len <= 3; len++) {
            if (index + len > s.size())
                break;

            string part = s.substr(index, len);

            // Leading zero
            if (part.size() > 1 && part[0] == '0')
                continue;

            // Value greater than 255
            if (stoi(part) > 255)
                continue;

            temp.push_back(part);

            solve(s, index + len);

            temp.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {
        solve(s, 0);
        return ans;
    }
};