class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int>s;
        int n =heights.size();
        vector<int>ans(n,0);
       
        for(int i=heights.size()-1;i>=0;i--)
        {
             int count=0;
            while(s.size()>0 && s.top()<heights[i])
            {
                s.pop();
                count++;
            }
            if(s.size()!=0) count++;
            ans[i]=count;
           
        
            s.push(heights[i]);
        }
        return ans;
    }
};