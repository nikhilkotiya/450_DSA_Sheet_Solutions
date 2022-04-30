class Solution {
public:
    bool ans(vector<int>&color ,vector<vector<int>>& graph,int prev,int i)
    {
        color[i]=1;
        queue<int>q;
        q.push(i);
        while(q.size())
        {
            int s=q.front();
            q.pop();
            for(auto x: graph[s])
            {
                if(color[x]==-1)
                {
                    color[x]=1-color[s];
                    q.push(x);
                }
                else if(color[x]==color[s])
                {
                    return true;
                }
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