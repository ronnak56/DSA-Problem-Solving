class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        vector<long long>sq;
        for(int x:nums) sq.push_back(1LL* x * x);

        sort(sq.begin(),sq.end(),greater<long long>());

       int k=(n+1)/2;
        for(int i=0;i<n;i++){
            if(i<k) ans+=sq[i];
            else ans-=sq[i];
        }
        return ans;
    }
};