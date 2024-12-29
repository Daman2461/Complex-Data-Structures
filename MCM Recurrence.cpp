class Solution {
  public:
  
  int f(vector<int> &arr, vector<vector<int>> &dp, int i,int j){
      if(i==j)return 0;
      int m = INT_MAX;
      if(dp[i][j]!=-1)return dp[i][j];
      for(int k = i ; k<j ;k++){
          m = min(m, f(arr,dp, i,k) + f(arr,dp, k+1,j) + (arr[i-1]* arr[k] * arr[j]));
          
      }
      return dp[i][j] = m;
  }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        vector<vector<int>> dp(arr.size() ,vector<int>(arr.size() ,-1) );
       return  f(arr,dp,1,arr.size()-1);
        
        
    }
};
