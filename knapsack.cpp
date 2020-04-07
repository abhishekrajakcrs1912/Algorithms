#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

int n,w,dp[MAX][MAX],weight[MAX],value[MAX];

void knapsack(){
    
    for(int i=0;i<=n;i++){ 
       for(int j=0;j<=w;j++){ 
            if(i==0 || j==0)    dp[i][j]=0; 
            else if (weight[i-1]<=j)
                dp[i][j] = max(value[i-1]+dp[i-1][j-weight[i-1]], dp[i-1][j]); 
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    printf("%d\n",dp[n][w]);
}

int main(){
    
    cin >> n >> w;
    for(int i=0;i<n;i++)    cin >> value[i] >> weight[i];
    
    knapsack();
    
    return 0;
}
/*
sample input:

3 50
60 10
100 20
120 30

*/
