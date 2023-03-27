//articulation point
#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;

class graph{
	public:
		unordered_map<int,list<int>> adj;
		void make_Edge(int u,int v){
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		void dfs(int node,unordered_map<int,bool> &visited,vector<int> &parent,vector<int> & disc,vector<int> &low,int &timer){
			visited[node] = true;
			low[node] = disc[node] = timer++;
			int child = 0;
			for(auto i:adj[node]){
				if(parent[node] == i) continue;
				
				if(!visited[i]){
					parent[i] = node;
					dfs(i,visited,parent,disc,low,timer);
					low[node] = min(low[node],low[i]);
					if(low[i]>=disc[node] && parent[i]!=-1) cout<<node<<" is a articulation point"<<endl;
					child++;
				}else{
						low[node] = min(low[node],disc[i]);
					}
			}
			if(parent[node] == -1 && child > 1) cout<<node<<" is a articulation point"<<endl;
			
		}
		
		void findAtriculationPoint(int n){
			unordered_map<int,bool>visited(n+1);
			vector<int> parent(n+1,-1);
			vector<int> disc(n+1,-1);
			vector<int> low(n+1,-1);
			int timer= 0;
			
			for(int i =0 ; i<n; i++){
				if(!visited[i]) dfs(i,visited,parent,disc,low,timer);
			}
			
		}
};

int main(){
	
	int n;
	cin>>n;
	
	int m;
	cin>>m;
	
	graph g;
	
	int u , v;
	for(int i =0; i<m; i++){
		cin>>u>>v;
		g.make_Edge(u,v);
	}
	
	g.findAtriculationPoint(n);
	
	return 0;
}
