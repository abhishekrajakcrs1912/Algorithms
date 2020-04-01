#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<pair<int,int> > adj[MAX];
int n,m;

void dijkstra(int v){
    int dist[MAX];
	for(int i=0;i<n;i++)    dist[i]=INT_MAX;
	dist[v] = 0;
	int u;
	set<pair<int,int> > s;
	s.insert(make_pair(dist[v], v));
	while(!s.empty()){
		u = s.begin() -> second;
		s.erase(s.begin());
		for(int i=0;i<adj[u].size();i++)
			if(dist[adj[u][i].first] > dist[u] + adj[u][i].second){
				s.erase(make_pair(dist[adj[u][i].first], adj[u][i].first));
				dist[adj[u][i].first] = dist[u] + adj[u][i].second;
				s.insert(make_pair(dist[adj[u][i].first], adj[u][i].first));
			}
	}
	
    for(int i=0;i<n;i++)
        printf("distance from 1 to %d = %d\n",i+1,dist[i]);
}

int main(){
    int u,v,d;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> u >> v >> d;
        adj[u-1].push_back(make_pair(v-1,d));
        adj[v-1].push_back(make_pair(u-1,d));
    }
    dijkstra(0);
    return 0;
}
