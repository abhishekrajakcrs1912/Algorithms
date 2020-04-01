#include<bits/stdc++.h>
using namespace std;

#define MAX 1000
#define inf 1000000000

vector<pair<int,int> > adj[MAX];
int n,m;

void dijkstra(int v){
    int d[MAX];
	fill(d,d + n, inf);
	d[v] = 0;
	int u;
	set<pair<int,int> > s;
	s.insert({d[v], v});
	while(!s.empty()){
		u = s.begin() -> second;
		s.erase(s.begin());
		for(auto p : adj[u])
			if(d[p.first] > d[u] + p.second){
				s.erase({d[p.first], p.first});
				d[p.first] = d[u] + p.second;
				s.insert({d[p.first], p.first});
			}
	}
	
    for(int i=0;i<n;i++)
        printf("distance from 0 to %d = %d\n",i,d[i]);
}

int main(){
    int u,v,d;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> u >> v >> d;
        adj[u].push_back(make_pair(v,d));
        adj[v].push_back(make_pair(u,d));
    }
    dijkstra(0);
    return 0;
}
