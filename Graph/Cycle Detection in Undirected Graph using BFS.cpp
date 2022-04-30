// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool dfsOfGraph(int V, vector<int> adj[],int i,vector<int>vis) {
        queue<pair<int,int>>s;
        s.push({i,-1});
        vis[i]=1;
        while(s.size())
        {
            int x=s.front().first;
            int prev=s.front().second;
            s.pop();
            for(auto it : adj[x])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    s.push({it,x});
                }
                else if(prev!=it){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfsOfGraph(V,adj,i,vis))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends