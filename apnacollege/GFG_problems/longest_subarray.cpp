   
   
   //asa sodavla hota fakt tyasathi
   
    int lenOfLongSubarr(int A[],  int N, int k) 
    { 
        // Complete the function
        int maxlen = 0;
        int sum = 0;
        map<int,int>mp;
        
        for(int i=0;i<N; i++){
            sum += A[i];
            
            
            if(sum==k){
                maxlen = i+1;//this will execute just on time
            }
            
            //find function gives a pointer which pointing to that element if exist , but if not then it points at end 
            if(mp.find(sum) == mp.end()){
                mp[sum] = i;//i for getting index sum quickly
            }
            
            if(mp.find(sum-k) != mp.end()){
              maxlen = max(maxlen, i-mp[sum-k]);
            }
        }
            return maxlen;
    } 




