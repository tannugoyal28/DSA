//finding cycle in undirected graph using dfs traversal 
#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>
#include<vector>
using namespace std;

class graph{
	public:
	unordered_map<int,list<int>> adj;
	void makeEdge(int u, int v, bool direction){
		if(!direction){
			adj[v].push_back(u);
		}
		adj[u].push_back(v);
	}
	
	void printList(int n){
		for(auto i: adj){
			cout<<i.first<<"->";
			for(auto j:i.second){
				cout<<j<<",";
			}
			cout<<endl;
		}
	}
	
	bool isCyclic(int node , unordered_map<int,bool> &visited,int parent){
		visited[node] = 1;
		
		for(auto i:adj[node]){
			if(visited[i] && i!=parent[node]) return true;
			else if(!visited[i]) isCyclic(i,visited,node);
		}
		return false;
	}
	
	string detectCycle(int n){
		unordered_map<int,bool> visited;
		for(int i=0; i<n; i++){
			if(!visited[i]){
				bool ans = isCyclic(i,visited,-1);
				if(ans) return "yes cycle is present in the graph";
			}
		}
		return " no cycle is not present in the graph";
	}
};

int main(){
	int n;
	cin>>n;
	
	int m;
	cin>>m;
	
	graph g;
	
	for(int i=0; i<m; i++){
		int u , v;
		cin>>u>>v;
		g.makeEdge(u,v,false);
	}
	cout<<g.detectCycle(n);
	return 0;
}
