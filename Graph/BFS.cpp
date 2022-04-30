#inlcude <bits/stdc++.h>
using namespace std;
void find(vector<int>adj[],int n,int m,vector<int>arr,int vis[])
{
    queue<int>q;
    q.push(i);
    vis[i]=1;
    while(q.size())
    {   
        int x=q.front();
        arr.push_back(x);
        q.pop();
        for(auto x:adj)
        {
            if(!vis[x])
            {
                vis[x]=1;
                q.push(x);
            }
        }
    }
}
vector<int>BFS(vector<int>adj[],int n,int m)
{
    vector<int>vis(n+1,0);
    int vis[n+1];
    vector<int>arr;
    for(int i=0;i<m;i++)
    {
        if(!vis[i])
        {
            find(adj,,n,m,arr,vis);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>n;
    vector<int>adj[n];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>bfs=BFS(adj,int n,int m);
    for(int i=0;i<bfs.size();i++)
    {
        cout<<bfs[i]<<" ";
    }
    return 0;
}