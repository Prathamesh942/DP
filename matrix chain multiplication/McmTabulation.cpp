int matrixMultiplication(int N, int arr[]){
    //dp representation
    vector<vector<int>> dp(N, vector<int>(N,INT_MAX));
    
    //base cases
    //for all (l,r) such that l+1>=r, cost of multiplication=0
    
    for(int r=0; r<N; r++){
        for(int l=max(r-1,0); l<N; l++){
            dp[l][r] = 0;
        }
    }
    
    //dp transition
    //for l=n-1 to l=0;
        //for r=min(l+2,n) to r<n
            //for k=l+1 to k<r
                //dp[l][r] = min(dp[l][r], arr[l]*arr[r]*arr[k] + dp[l][k] + dp[k][r])
    
    for(int l=N-1; l>=0; l--){
        for(int r=min(l+2,N-1); r<N; r++){
            for(int k=l+1; k<r; k++){
                dp[l][r]=min(dp[l][r], (dp[l][k]+dp[k][r]+arr[l]*arr[r]*arr[k]));
            }
        }
    }
    return dp[0][N-1];
}