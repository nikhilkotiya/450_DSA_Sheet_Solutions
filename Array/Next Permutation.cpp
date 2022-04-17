class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size()-1;
        int found=0;
        if(n==0 || n==-1)
        {
            return ;
        }
        int i=n;
        for(i;i>=1;i--)
        {
            if(nums[i]>nums[i-1])
            {
                found=1;
                break;
            }
        }
        if(found==0)
        {
            reverse(nums.begin(),nums.end());
            return ;
        }
        int x=nums[i-1];
        int val=INT_MAX;
        int r;
        for(int a=i;a<=n;a++)
        {
            if(nums[a]>x && val>nums[a])
            {
                r=a;
                val=nums[a];
            }
        }
        swap(nums[i-1],nums[r]);
        sort(nums.begin()+i,nums.end());
    }
};