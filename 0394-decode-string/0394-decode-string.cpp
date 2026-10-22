class Solution {
public:
    string decode(string &s, int &i) {
        string result;

        while (i < s.size() && s[i] != ']') {

            // If current character is a letter
            if (isalpha(s[i])) {
                result += s[i];
                i++;
            }

            // If current character is a number
            else {
                int num = 0;

                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }

                // Skip '['
                i++;

                // Decode inside brackets
                string temp = decode(s, i);

                // Skip ']'
                i++;

                // Repeat temp num times
                while (num--) {
                    result += temp;
                }
            }
        }

        return result;
    }

    string decodeString(string s) {
        int i = 0;
        return decode(s, i);
    }
};