class Solution {
public:
    int minDistance(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<int>dp(m+1,0);
        for(int i=0;i<=m;i++)
        {
            dp[i]=i;
        }
        for(int i=1;i<=n;i++)
        {
            vector<int>temp(m+1,0);
            temp[0]=i;
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    temp[j]=dp[j-1];
                }
                else
                {
                    temp[j]=1+min(temp[j-1],min(dp[j],dp[j-1]));
                }
            }
            dp=temp;
        }
        return dp[m];
    }
};