// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<bool>fi(V,0);
        vector<int>dis(V,INT_MAX);
        dis[0]=0;
        for(int count=0;count<V;count++)
        {
            int mini=INT_MAX,u;
            for(int i=0;i<V;i++)
            {
                if(fi[i]==0 && dis[i]<mini)
                {
                    mini=dis[i],u=i;
                }
            }
            fi[u]=1;
            for(auto it:adj[u])
            {
                int q=it[0];
                int we=it[1];
                if(fi[q]==0 && dis[q]>we)
                {
                    dis[q]=we;
                }
            }
        }
        int sum=0;
        for(int i=0;i<V;i++)
        {
            sum+=dis[i];
        }
        return sum;
    }
};
// optimised
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<bool>fi(V,0);
        vector<int>dis(V,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>que;
        que.push({0,0});
        dis[0]=0;
        while(que.size())
        {
            int u;
            u=que.top().second;
            que.pop();
            fi[u]=1;
            for(auto it:adj[u])
            {
                int vv=it[0];
                int we=it[1];
                if(fi[vv]==0 && we<dis[vv])
                {
                    dis[vv]=we;
                    que.push({dis[vv],vv});
                }
            }
        }
        int sum=0;
        for(int i=0;i<V;i++)
        {
            sum+=dis[i];
                // cout<<dis[i]<<" ";
        }
        return sum;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends