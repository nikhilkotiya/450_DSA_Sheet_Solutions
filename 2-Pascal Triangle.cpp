#include <bits/stdc++.h> 
vector<vector<long long int>> printPascal(int n) 
{
    int x=1;
    vector<vector<long long int>>ans;
    for(int i=0;i<n;i++)
    {
        vector<long long int>v;
        for(int j=0;j<=i;j++)
        {
            if(j==0 || j==i)
            {
                v.push_back(1);    
            }
            else
            {
                v.push_back(ans[i-1][j]+ans[i-1][j-1]);    
            }
        }
        ans.push_back(v);
    }
    return ans;
}


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> r(numRows);

        for (int i = 0; i < numRows; i++) {
            r[i].resize(i + 1);
            r[i][0] = r[i][i] = 1;
  
            for (int j = 1; j < i; j++)
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
        }
        
        return r;
    }
};