class Solution {
    int solve(vector<int>&nums,int target,vector<int>&dp){
        if(target==0){
            return 0;
        }
        if(target<0){
            return -1;
        }

        if(dp[target]!=-1){
            return dp[target];
        }

        int total=0;
        int ans_level=1e9;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=target){
                total=1+solve(nums,target-nums[i],dp);
            }
            else if(nums[i]>target){
                // continue;
                break;
            }

            ans_level=min(ans_level,total);

        }

        return dp[target]=ans_level;


    }
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        vector<int>dp(amount+1,-1);
        int ans=solve(coins,amount,dp);
        if(ans==1e9){
            return -1;
        }
        else{
            return ans;
        }
    }
};
