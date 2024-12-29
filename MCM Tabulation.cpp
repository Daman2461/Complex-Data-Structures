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
        vector<vector<int>> dp(arr.size() ,vector<int>(arr.size() ,0) );
        
        // for(int i=0;i<arr.size();i++){
        //     dp[i][i]==0;
        // }
        
        for(int i=arr.size()-1;i>=1  ;i--){
            for(int j=i+1;j<arr.size();j++){
                int m = INT_MAX;
                
                for(int k = i ; k < j ;k++){
                m = min(m, dp[i][k] + dp[k+1][j] + (arr[i-1]* arr[k] * arr[j]));
          
                 }
             dp[i][j] = m;
            }
        }
        
        return dp[1][arr.size()-1];
        
        
        
        
        
     
        
        
    }
};
