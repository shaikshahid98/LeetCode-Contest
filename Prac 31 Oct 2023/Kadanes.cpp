long long maxSubarraySum(int arr[], int n){
        int64 lmax=arr[0],gmax=arr[0];
        
        for(int i=1;i<n;i++)
        {
            lmax= max(arr[i]*1LL,lmax+arr[i]);
            gmax=max(gmax,lmax);
        }
        return gmax;
        
        
    }