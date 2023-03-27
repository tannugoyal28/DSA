#include<iostream>
#include<stack>
#include<unordered_map>
#include<list>
using namespace std;

class graph{
	public:
		unordered_map<int,list<int>> adj;
		void makeEdge(int u,int v){
			adj[u].push_back(v);
		}
		
		void dfs(int node, unordered_map<int,bool> &visited,stack<int> &st){
			visited[node] = true;
			for(auto i:adj[node]){
				if(!visited[i]){
					dfs(i,visited,st);
				}
			}
			st.push(node);
			
		}
		
		void topologicalSort(int n){
			unordered_map<int,bool> visited;
			stack<int> st;
			for(int i =0; i<n; i++){
				if(!visited[i]){
					dfs(i,visited,st);
				}
			}
			
			while(!st.empty()){
				cout<<st.top()<<" ";
				st.pop();
			}
		}
};

int main(){
	int n;
	cin>>n; //no of node;
	
	int m;
	cin>>m; //no of edges;
	
	graph g;
	
	for(int i =0; i<m; i++){
		int u , v;
		cin>>u>>v;
		g.makeEdge(u,v);
	}
	g.topologicalSort(n);
	
	return 0;
	
}
