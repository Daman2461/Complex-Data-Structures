# define MOD 1000000007
# define ll long long
// ll f(string &s , ll i, ll j, bool isTrue, vector<vector<vector<ll>>> & dp)
// {
//     if(i>j)return 0;
//     if(i==j){
//         if(isTrue)return  s[i]=='T';
//         else return  s[i]=='F';


//     }

//     if(dp[i][j][isTrue]!=-1)
//         return dp[i][j][isTrue];
//     ll ways =0;
//     for(ll ind = i+1; ind <=j-1;ind+=2){
//         ll lf,rf,lt,rt;

//         lf = f(s,i, ind-1, 0,dp) % MOD;
//         lt = f(s,i, ind-1, 1,dp)% MOD;

//         rf = f(s,ind+1,j, 0,dp)% MOD;
//         rt = f(s,ind+1,j, 1,dp)% MOD;

//         if(s[ind] == '&' ){
//             if(isTrue)
//             ways =( ways + (rt * lt)%MOD ) % MOD;
//             else 
//             ways =( ways + (rf * lt)%MOD + (rt * lf)%MOD +(rf * lf) %MOD ) % MOD;
//         }

//         if(s[ind] == '|' ){
//             if(isTrue)
//             ways =( ways + (rt * lt)%MOD  + (rf * lt)%MOD +(rt * lf)%MOD ) % MOD;
//             else 
//             ways =( ways  +(rf * lf) %MOD ) % MOD;
//         }

//         if(s[ind] == '^' ){
//             if(isTrue)
//             ways =( ways + (rt * lf)%MOD  + (rf * lt)%MOD  ) % MOD;
//             else 
//             ways =( ways  +(rf * lf) %MOD +(rt * lt) %MOD ) % MOD;
//         }
     
//     }

//    return dp[i][j][isTrue]=ways;
// }
int evaluateExp(string & s) {
    int n=s.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, 0)));

    
    for(int i=n-1;i>=0;i--){
        for(int j=i;j<n;j++){


         
        if (i == j) {
                dp[i][j][1] = (s[i] == 'T');  
                dp[i][j][0] = (s[i] == 'F');  
                continue;
            }
            ll waystrue  =0;
            ll  waysfalse =0;

    for(ll ind = i+1; ind <=j-1;ind+=2){
        ll lf,rf,lt,rt;

        lf = dp[i] [ind-1] [0] % MOD;
        lt = dp[i] [ind-1] [1]% MOD;

        rf = dp[ind+1][j][0]% MOD;
        rt = dp[ind+1][j][1]% MOD;

        if(s[ind] == '&' ){
         
            waystrue  =( waystrue  + (rt * lt)%MOD ) % MOD;
          
            waysfalse =( waysfalse  + (rf * lt)%MOD + (rt * lf)%MOD +(rf * lf) %MOD ) % MOD;
        }

        if(s[ind] == '|' ){
            
            waystrue =( waystrue  + (rt * lt)%MOD  + (rf * lt)%MOD +(rt * lf)%MOD ) % MOD;
            
            waysfalse  =( waysfalse  +(rf * lf) %MOD ) % MOD;
        }

        if (s[ind] == '^') {
            
            waystrue = (waystrue + (rt * lf) % MOD + (rf * lt) % MOD) % MOD;
             
            waysfalse = (waysfalse + (rf * lf) % MOD + (rt * lt) % MOD) % MOD;
        }
    }
     dp[i][j][1]=waystrue ;
    dp[i][j][0]=waysfalse ;
    }
    
   
     

        
    }
      return dp[0][n-1][1];
} 
