class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<vector<int>>v;
        pair<int,int>p;
        if(n==1||n==0)
        {
            return intervals;    
        }
        p={intervals[0][0],intervals[0][1]};
        for(int i=1;i<n;i++)
        {
            if(p.second>=intervals[i][0])
            {
                p.second=max(intervals[i][1],p.second);
                p.first=min(intervals[i][0],p.first);
                if(i==n-1)
                {
                    vector<int>v1;
                    v1.push_back(p.first);
                    v1.push_back(p.second);
                    v.push_back(v1);                       
                }
            }
            else
            {
                vector<int>v1;
                v1.push_back(p.first);
                v1.push_back(p.second);
                v.push_back(v1);
                p.first=intervals[i][0];
                p.second=intervals[i][1];
                if(i==n-1)
                {
                    vector<int>v1;
                    v1.push_back(p.first);
                    v1.push_back(p.second);
                    v.push_back(v1);                  
                }
            }
        }
        return v;
    }
};