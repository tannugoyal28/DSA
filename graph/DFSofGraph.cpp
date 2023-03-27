#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class graph{
	public:
		unordered_map<int,list<int>> adj;
		void makeEdge(int u,int v, bool direction){
			if(!direction){
				adj[v].push_back(u);
			}
			adj[u].push_back(v);
		}
		
		void printList(){
			for(auto i: adj){
				cout<<i.first<<"->";
				for(auto j:i.second){
					cout<<j<<",";
				}
				cout<<endl;
			}
		}
		
		void dfs(int node,unordered_map<int,bool>&visited){
			cout<<node;
			visited[node] = true;
			for(auto i:adj[node]){
				if(!visited[i]){
					dfs(i,visited);
				}
			}
		}
		
		void DFS(int n){
			unordered_map<int,bool> visited;
			for(int i=0;i<n;i++){
				if(!visited[i]){
					dfs(i,visited);
					cout<<endl;
				}
			}
		}
};

int main(){
	int n;
	cin>>n; //no. of nodes
	
	int m;
	cin>>m; //no of edges
	
	graph g;
	
	for(int i =0;i<m;i++){
		int u , v;
		cin>>u>>v;
		g.makeEdge(u,v,false);
	}
	g.printList();
	g.DFS(n);
	
	return 0;
}

