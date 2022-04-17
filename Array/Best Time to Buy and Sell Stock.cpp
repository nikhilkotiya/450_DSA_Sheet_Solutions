class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=prices[0];
        int result=0;
        for(int i=1;i<n;i++)
        {
            ans=min(ans,prices[i]);
            result=max(result,prices[i]-ans);
        }
        return result;
    }
};