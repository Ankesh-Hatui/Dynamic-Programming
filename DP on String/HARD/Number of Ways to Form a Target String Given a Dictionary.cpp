/*
* Leetcode : 1639
* T.C : O(N) N=words[0].size()
* S.C : O(1001*1001)
* Leetcode link: https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/description/
*/

class Solution {
    typedef long long ll;
    const int mod=1e9+7;
    ll dp[1001][1001];
    int solve(vector<vector<ll>>&freq,vector<string>& words,string&target,int r,int c){
        if (c>=target.size()){
            return 1;
        }
        if (r>= words[0].size()){
            return 0;
        }
        if (dp[r][c]!=-1){
            return dp[r][c];
        }
        
        ll np=solve(freq,words,target,r+1,c);
        ll pick=(freq[target[c]-'a'][r]*solve(freq,words,target,r+1,c+1));

        return dp[r][c]=(np+pick)%mod;
    }
public:
    int numWays(vector<string>& words, string target) {
        int rows=26;
        int cols=words[0].size();
        memset(dp,-1,sizeof(dp));

        vector<vector<ll>>freq(rows,vector<ll>(cols,0));
        for (int i=0;i<words.size();i++){
            for (int j=0;j<words[0].size();j++){
                freq[words[i][j]-'a'][j]+=1;
            }
        }

        return solve(freq,words,target,0,0);
    }
};
