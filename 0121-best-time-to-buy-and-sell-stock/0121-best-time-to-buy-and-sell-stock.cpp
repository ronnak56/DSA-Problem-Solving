class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestbuy=prices[0];
       int maxprofit=0;

        for(int i=1;i<prices.size();i++){
            maxprofit=max(maxprofit,prices[i]-bestbuy);

            if(prices[i]<bestbuy) bestbuy=prices[i];
        }
        return maxprofit;
    }
};