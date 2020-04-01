#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<pair<int,int> > adj;
int weight[MAX];
int n,m;

void bellmanFord(int v){
    int dist[MAX];
	for(int i=0;i<n;i++)    dist[i]=INT_MAX;
	dist[v] = 0;
	for(int i=1;i<=n;i++){
	    for(int j=0;j<m;j++){
	        if(dist[adj[j].second]>dist[adj[j].first]+weight[j]){
	            if(i==n)    printf("Negative cycle is present in graph");
	            dist[adj[j].second]=dist[adj[j].first]+weight[j];
	        }
	    }
	}
	
    for(int i=0;i<n;i++)    printf("distance from node %d to node %d = %d\n",v+1,i+1,dist[i]);
}

int main(){
    int u,v,w;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> u >> v >> w;
        adj.push_back(make_pair(u-1,v-1));
        weight[i]=w;
    }
    bellmanFord(0);
    return 0;
}
