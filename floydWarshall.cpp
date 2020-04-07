#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

int adj[MAX][MAX],n,m;

void floydWarshall(){
    
	for(int i=0;i<n;i++){
	    for(int j=0;j<n;j++){
	        for(int k=0;k<n;k++){
	            adj[i][k] = min(adj[i][k], adj[i][j] + adj[j][k]);
	        }
	    }
	}
	
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adj[i][j]==MAX)  printf("distance from %d to %d = INF\n",i+1,j+1);
            else                printf("distance from %d to %d = %d\n",i+1,j+1,adj[i][j]);
        }
    }
}

int main(){
    
    int u,v,d;
    cin >> n >> m;
    
    // initialize the array with infinity
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            adj[i][j]=MAX;
            if(i==j)    adj[i][j]=0;
        }
    }
    
    for(int i=0;i<m;i++){
        cin >> u >> v >> d;
        adj[u-1][v-1]=d;
    }
    
    floydWarshall();
    
    return 0;
}
/*
sample input
4 4
1 2 5
1 4 10
2 3 3
3 4 1
*/
