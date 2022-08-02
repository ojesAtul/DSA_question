class TreeAncestor {
    int dp[18][50005];
public:
    TreeAncestor(int n, vector<int>& parent) {
        for(int i=0;i<18;i++){
            dp[i][0]=-1;
        }
        for(int i=1;i<n;i++){
            dp[0][i]=parent[i];
        }
        for(int i=1;i<18;i++){
            for(int j=1;j<n;j++){
                if(dp[i-1][j]==-1)
                    dp[i][j]=-1;
                else
                dp[i][j]=dp[i-1][dp[i-1][j]];
            }
        }
    }
    int fun(int num){
        for(int i=31;i>=0;i--){
            if(num&(1<<i))
                return i;
        }
        return 0;
    }
    int getKthAncestor(int node, int k) {
         if(k==0){
             return node;
         }
        int hst=fun(k);
         if(dp[hst][node]==-1)
             return -1;
         return getKthAncestor(dp[hst][node],k^(1<<hst));
        
    }
};



