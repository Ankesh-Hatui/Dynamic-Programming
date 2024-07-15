class Solution {
    /*
    void solve(vector<int>& nums, vector<int>& ans, vector<int> temp,
               int index) {

        if(index==nums.size()){
            if(ans.size()<temp.size()){
                ans=temp;
            }
            return;
        }

        // if(temp.empty() || nums[index]% temp.back()==0){
        //     temp.push_back(nums[index]);
        //     solve(nums,ans,temp,index+1);
        //     temp.pop_back();
        // }

        // solve(nums,ans,temp,index+1);

        for (int i = index; i < nums.size(); i++) {
            if (temp.empty() || nums[i] % temp.back() == 0) {

                temp.push_back(nums[i]);
                // if (temp.size() > ans.size()) {
                //     ans = temp;
                // }
                solve(nums, ans, temp, i + 1);
                temp.pop_back();
            }
        }
    }
    */

    /*

    void solve(vector<int>&nums,vector<int>&ans,int index){


        // if i do this this test case will be fail:
    [5,9,18,54,108,540,90,180,360,720]
        // As it will not backtrack it will not try all combination
        // for a particular index

        vector<int>temp;
        for(int i=index;i<nums.size();i++){
            if(temp.empty() || nums[i]%temp.back()==0){
                temp.push_back(nums[i]);
                solve(nums,ans,i+1);
            }
        }

        if(ans.size()<temp.size()){
            ans=temp;
        }


    }
    */

    void solve(vector<int>& nums, vector<int>& ans, vector<int> temp,
               int index) {

        for (int i = index; i < nums.size(); i++) {
            if (temp.empty() || nums[i] % temp.back() == 0) {
                temp.push_back(nums[i]);
                solve(nums, ans, temp,i + 1);
                if (ans.size() < temp.size()) {
                    ans = temp;
                }
                temp.pop_back();
            }
        }
    }

    // Bottom-up

    // int solve(vector<int>&nums){
    //     vector<vector<int>>dp(nums.size());
    //     dp[0].push_back(nums[0]);
    //     for(int i=1;i<nums.size();i++){
    //         for(int j=0;j<i;j++){
    //             if(nums[i]%nums[j]==0){
    //                 dp[i].push_back(nums[j]);
    //             }
    //         }
    //     }
    //     int ans=0;
    //     for(int i=1;i<nums.size();i++){
    //         if(nums[ans].size()<nums[i].size()){
    //             ans=i;
    //         }
    //     }
    //     return dp[i];
    // }

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // vector<int> ans;
        // vector<int> temp;
        // sort(nums.begin(), nums.end());
        // solve(nums, ans,temp, 0);
        // return ans;
        
        sort(nums.begin(), nums.end());
        vector<vector<int>>dp(nums.size());
        
        for(int i=0;i<nums.size();i++){
            dp[i].push_back(nums[i]);
        }
        vector<int> ans=dp[0];
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i].size()<dp[j].size()+1){
                    dp[i]=dp[j];
                    dp[i].push_back(nums[i]);
                }
            }

            if(ans.size()<dp[i].size()){
                ans=dp[i];
            }
            
        }
        
        return ans;
    }
};
