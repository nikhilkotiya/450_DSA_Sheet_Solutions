class Solution {
public:
    void dfs(int i,vector<int>&vis,vector<vector<int>>&rooms)
    {
        vis[i]=1;
        for(auto it : rooms[i])
        {
            if(vis[it]==0)
            {
                dfs(it,vis,rooms);        
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>vis(n,0);
        vis[0]=1;
        dfs(0,vis,rooms);
        for(int i=1;i<rooms.size();i++)
        {
            if(vis[i]==0)
            {
                return false;
            }
        }
        return true;
    }
};