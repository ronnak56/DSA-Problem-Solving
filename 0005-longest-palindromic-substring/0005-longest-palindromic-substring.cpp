class Solution {
public:
    string longestPalindrome(string s) { int n=s.length();
      
        int maxLen=1;
        int start=0;
        vector<vector<int>>dp(n,vector<int>(n,0));
        
        for(int k=0;k<n;k++){
            int i=0,j=k;
            while(j<n){
                if(i==j){
                    dp[i][j]=1;
                
                }
                else if(j==i+1){
                    if(s[i]==s[j]){
                    dp[i][j]=1;
                   if(maxLen < 2) {
                            maxLen = 2;
                            start = i;
                    }
                 }
                }
                  else { 
                    if(s[i] == s[j] && dp[i+1][j-1] == 1) {
                        dp[i][j] = 1;
                        if(maxLen < j - i + 1) {
                            maxLen = j - i + 1;
                            start = i;
                        }
                    }
                }
                  i++;j++;
            }
          
        }
       return s.substr(start,maxLen); 
    }
};