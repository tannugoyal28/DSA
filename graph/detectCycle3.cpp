//detecting cycle in the directed graph using dfs traversal
#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class graph{
	public:
		unordered_map<int,list<int>> adj;
		void makeEdge(int u, int v){
			adj[u].push_back(v);
		}
		
		bool checkCycleDFS(int node, unordered_map<int,bool> &visited, unordered_map<int,bool> &visitedDfs){
			visited[node] = true;
                        visitedDfs[node] = true;
                       for(auto i:adj[node]){
                            if(visited[i] && visitedDfs) return true;
                            else if(!visited[i]) isCycle(visited,i);
                       }
                       visitedDfs[node] = false;
                       return false;
		}
		
		bool detectCycle(int n){
			unordered_map<int,bool> visited;
			unordered_map<int,bool> visitedDfs;
			for(int i=0; i<n ; i++){
				if(!visited[i]){
					bool cycleFound = checkCycleDFS(i,visited,visitedDfs);
					if(cycleFound) return true;
				}
			}
			return false;
		}
};

int main(){
	
	int n;
	cin>>n; //no of node;
	
	int m;
	cin>>m; //no of edges;
	
	graph g;
	
	for(int i =0;i<m; i++){
		int u , v;
		cin>>u>>v;
		g.makeEdge(u,v);
	}
	
	cout<<g.detectCycle(n);
	
	return 0;
}
