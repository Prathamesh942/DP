int fun(int arr[], int left, int right){
        //base case
        if(left+1 == right) return 0;
        if(dp[left][right]!=-1) return dp[left][right];
        int result=INT_MAX;
        for(int k = left+1; k < right; k++){
            int res = arr[left]*arr[k]*arr[right];
            res+=fun(arr,left,k);
            res+=fun(arr,k,right);
            result=min(res,result);
        }
        return dp[left][right] = result;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        dp.resize(N, vector<int> (N, -1));
        return fun(arr,0,N-1);
    }
}