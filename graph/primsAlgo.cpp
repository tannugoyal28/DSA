//prims Algo used to find the mst(minimum spanning tree)
#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<unordered_map>
#include<list>
#include<utility>
#include<limits.h>
using namespace std;

class graph{
	public:
		unordered_map<int,list<pair<int,int>>> adj;
		void make_edge(int u,int v,int dis){
			adj[u].push_back({v,dis});
			adj[v].push_back({u,dis});
		}
		
		void findMst(int n,int src){
			vector<int> key(n+1, INT_MAX);
			vector<bool> mst(n+1,false);
			vector<int> parent(n+1,-1);
			
			key[src] = 0;
			
			for(int i=0; i<n; i++){
				int mini = INT_MAX;
				int u;
				for(int v=0; v<=n ; v++){
					if(mst[v] == false && key[v] < mini){
						u=v;
						mini = key[v];
					}
				}
				
				mst[u] = true;
				for(auto it:adj[u]){
					int v = it.first;
					int w = it.second; 
					if(mst[v]==false && w<key[v]){
						parent[v] = u;
						key[v] = w;
					}
				}
			}
			
			vector<pair<pair<int,int>,int>> ans;
			for(int i =1; i<n; i++){
				ans.push_back({{parent[i],i},key[i]});
			}
			for(auto i:ans){
				cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<endl;
			}
				
		}
		
		
		
};

int main(){
	int n;0
	cin>>n; //no of nodes
	
	int m;
	cin>>m; //no of edges
	
	graph g;
	for(int i=0; i<m; i++){
		int u, v, dis;
		cin>>u>>v>>dis;
		g.make_edge(u,v,dis);
	}
	int src;
	cin>>src;
	g.findMst(n,src);
	
	return 0;
}

