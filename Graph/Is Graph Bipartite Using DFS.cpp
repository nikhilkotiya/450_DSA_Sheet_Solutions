class Solution {
public:
    bool ans(vector<int>&color ,vector<vector<int>>& graph,int prev,int i)
    {
        if(prev==-1)
        {
            color[i]=0;    
        }
        else
        {
            color[i]=1-prev;
        }
        for(auto x: graph[i])
        {
            if(color[x]==-1)
            {
                if(ans(color,graph,color[i],x))
                {
                    return true;        
                }
            }
            else if(color[x]==color[i])
            {
                return true;
            }
        }
        return false;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n+1,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(ans(color,graph,-1,i))
                {
                    return false;
                }   
            }    
        }
        return true;
    }
};