class Solution {
public:
    vector<string> ans;

    void solve(string curr, int n){
        if(curr.size() == n){
            ans.push_back(curr);
            return;
        }
        for(char ch : {'a','b','c'}){
            if(curr.empty() || curr.back() != ch){
                solve(curr + ch, n);
            }
        }
    }
    string getHappyString(int n, int k) {
        solve("", n);
        if(ans.size() < k) return "";
        return ans[k-1];
    }
};