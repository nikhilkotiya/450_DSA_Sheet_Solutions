class Solution {
public:
    bool rec(string s,int n,string p,int m)
    {
        if(n<0 && m<0)
        {
            return true;
        }
        if(n == -1 && p[m] == '*')return rec(s, n,p, m-2);
        if(n<0 || m<0)
        {
            return false;    
        }
        if(s[n]==p[m])
        {
            return rec(s,n-1,p,m-1);    
        }
        if(p[m]=='*')
        {
            if(p[m-1]==s[n] || p[m-1]=='.')
            {
                return rec(s,n-1,p,m) || rec(s,n,p,m-2);
            }
            else
            {
                return rec(s,n,p,m-2);
            } 
        }
        else if(p[m]=='.')
        {
            return rec(s,n-1,p,m-1);     
        }
        else
        {
            return false;
        }
    }
    bool isMatch(string s, string p) {
        return rec(s,s.size()-1,p,p.size()-1);
    }
};



class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        dp[0][0]=1;
        for(int i=1;i<=m;i++)
        {
            if(p[i-1]=='*')
            {
                dp[0][i]=dp[0][i-2];
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==p[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];    
                }
                else if(p[j-1]=='*')
                {
                    if(p[j-2]==s[i-1] || p[j-2]=='.')
                    {
                        dp[i][j]=dp[i-1][j] || dp[i][j-2];
                    }
                    else
                    {
                       dp[i][j]=dp[i][j-2];
                    } 
                }
                else if(p[j-1]=='.')
                {
                    dp[i][j]=dp[i-1][j-1];    
                }
            }    
        }
        return dp[n][m];
    }
};