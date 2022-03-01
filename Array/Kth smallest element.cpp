class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        int l=0;
        int r=arr.size()-1;
        priority_queue<int,vector<int>,greater<int>>q;
        while(l<=r)
        {
            if(q.size()==k)
            {
                if(q.top()<arr[l])
                {
                    q.pop();
                    q.push(arr[l]);
                }
            }
            else
            {
                q.push(arr[l]);
            }
            l++;
        }
        return q.top();
    }
};