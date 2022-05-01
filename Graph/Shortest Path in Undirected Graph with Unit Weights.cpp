#include <bits/stdc++.h>
using namespace std;
class Solution
{
	public:
	vector<int> shortestpath(int V, vector<int> adj[]) 
	{
	    queue<int>q;
	    vector<int>vis(V,INT_MAX);
        // distance from 0 to n
        q.push(0);
        vis[0]=0;
        while(q.size())
        {
            int x=q.front();
            for(auto it : adj[x])
            {
                if(vis[it]>vis[x]+1)
                {
                    vis[it]=vis[x]+1;
                    q.push(it);
                }
            }
            q.pop();
        }
	    vector<int>ans;
	    while(s.size())
	    {
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
        map[res[i]] = i;
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends