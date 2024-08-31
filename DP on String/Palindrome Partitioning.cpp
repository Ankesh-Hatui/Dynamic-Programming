// LC no : 131
class Solution {
    void solve(int i,vector<vector<string>>&ans,vector<string>&temp,string& s,vector<vector<bool>>&dp)
    {
        if(i==s.length())
        {
            ans.push_back(temp);
            return;
        }

        for(int j=i;j<s.size();j++)
        {
            if(dp[i][j]==true)
            {
                temp.push_back(s.substr(i,j-i+1));
                solve(j+1,ans,temp,s,dp);
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        // all diagonal will be palindrome

        for(int i=0;i<n;i++)
        {
            dp[i][i]=true;
        }
        // Filling DP table

        for(int len=2;len<=n;len++)
        {
            for(int index=0;index<n-len+1;index++)
            {
                int j=index+len-1;
                if(s[index]==s[j])
                {
                        if(len==2)
                        {
                            // Means there is two element from i to j
                            dp[index][j]=true;
                        }
                        else
                        {  
                            dp[index][j]=dp[index+1][j-1];
                        }
                }
            }
        }

        vector<vector<string>>ans;
        
        vector<string>temp;
        solve(0,ans,temp,s,dp);

        return ans;
    }
};
