#include<bits/stdc++.h>
using namespace std;

class graph{
	public:
		unordered_map<int,list<int>>adj;
		void make_edge(int u, int v){
			adj[u].push_back(v);
		}
		
		void dfs(int src,unordered_map<int,bool>& visited,stack<int>& st){
			visited[src] = true;
			for(auto i:adj[src]){
				if(!visited[i]) dfs(i,visited,st);
			}
			st.push(src);
		}
		
		void dfs2(int src,unordered_map<int,bool>& visited,unordered_map<int,list<int>>& adjT){
			visited[src] = true;
			for(auto i:adjT[src]){
				if(!visited[i]) dfs2(i,visited,adjT); 
			}
		}
		
		void kosaraju(int n){
			unordered_map<int,bool> visited(n+1);
			stack<int> st;
			for(int i =0; i<n; i++){
				if(!visited[i]) dfs(i,visited,st);
			}
			
			unordered_map<int,list<int>> adjT;
			for(int i=0; i<n; i++){
				visited[i] = false;
				for(auto it:adj[i]){
					adjT[it].push_back(i);
				}
			}
			
			int scc =0;
			while(!st.empty()){
				int src=st.top();
				st.pop();
				if(!visited[src]){
					scc++;
					dfs2(src,visited,adjT);
				}
			}
			
			cout<<scc;
			
		}
};

int main(){
	int n;
	int m;
	cin>>n;
	cin>>m;
	 graph g;
	
	for(int i =0;i<m; i++){
		int u;
		int v;
		cin>>u>>v;
		g.make_edge(u,v);
	}
	g.kosaraju(n);
}
