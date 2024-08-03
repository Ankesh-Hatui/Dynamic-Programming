//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    int mod=1e9+7;
    int solveRec(int arr[],int n,int sum,int index,vector<vector<int>>&dp){
        if(index>=n){
            if(sum==0){
                return 1;
            }
            return 0;
        }
        
        if(sum==0 && arr[index]!=0){
            return 1;
        }
        
        if(dp[index][sum]!=-1){
            return dp[index][sum];
        }
        
         int pick=0;
        
        if(arr[index]<=sum){
            pick=solveRec(arr,n,sum-arr[index],index+1,dp)%mod;
            
        }
        int np=solveRec(arr,n,sum,index+1,dp);
        return dp[index][sum]=(pick+np)%mod;
    }

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        sort(arr,arr+n);
        int ans=solveRec(arr,n,sum,0,dp);
        return ans;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
