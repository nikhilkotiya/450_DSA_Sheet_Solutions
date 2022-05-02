// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>dis(V,INT_MAX);
        // lets find distance from 0 to n
        int src=0;
        dis[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greter<pair<int,int>>>q;
        q.push(src,dis[src]);
        while(q.size())
        {
            int distance=q.top().first;
            int node=q.top().second;
            q.pop();
            for(auto it : adj[node])
            {
                int next=it.first;
                int dis=it.second;
                if(dis[next]>dis+distance)
                {
                    dis[next]=dis+distance;
                    q.push({dis[next],next});
                }
            }
        }
        return dis;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<pair<int,int>> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v,w;
            cin >> u >> v >>w;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends