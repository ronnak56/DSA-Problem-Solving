class Solution {
public:
int helper(int n,vector<int>& dp){
    if(n==0 || n==1) return 1;
    if(n==2) return 2;
    int sum=0;
    if(dp[n]!=-1) return dp[n];
    for(int i=1;i<=n;i++){
        sum+=helper(i-1,dp)*helper(n-i,dp);
    }
    return dp[n]=sum;

}
    int numTrees(int n) {
        vector<int>dp(n+1,-1);
        return helper(n,dp);
        
    }
};