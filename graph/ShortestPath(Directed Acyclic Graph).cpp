//shortest path in directed Acyclic graphs
#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<utility>
#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

class graph{
	public:
		unordered_map<int,list<pair<int,int>>> adj;
		void makeEdge(int u,int v, int dis){
			adj[u].push_back({v,dis});
		}
		
		void print(){
			for(auto i:adj){
				cout<<i.first<<"->";
				for(auto j:i.second){
					cout<<"{"<<j.first<<","<<j.second<<"} ";
				}
				cout<<endl;
			}
		}
		
		void dfs(int node,unordered_map<int,bool> &visited,vector<int> &Ts,int& Trial){
			visited[node] = true;
			for(auto i:adj[node]){
				if(!visited[i.first]) dfs(i.first,visited,Ts,Trial);
			}
			
			Ts[Trial--] = node;
		}
		
		void ShortestPath(int src, int n){
			unordered_map<int,bool> visited;
			vector<int> Ts(n) ;//topologicalsort 
			int trial = n;
			for(int i =0; i<n; i++){
				if(!visited[i]){
					dfs(i,visited,Ts,trial);
				}
			}
			
			vector<int> ans(n,INT_MAX);
			ans[src] = 0;
			for(int i =0; i<n;i++){
				int top = Ts[i];
				if(ans[top] != INT_MAX){
					for(auto i:adj[top]){
						if(ans[top] + i.second < ans[i.first]){
							ans[i.first] = ans[top] + i.second;
						} 
					}
				}
			}
			
			for(int i=0; i<ans.size(); i++){
				cout<<ans[i]<<" ";
			}
			
			
			
		}
};

int main(){
	int n;
	cin>>n; //no of nodes
	
	int m;
	cin>>m; //no of edges
	
	graph g;
	for(int i =0; i<m; i++){
		int u ,v , dis;
		cin>>u>>v>>dis;
		g.makeEdge(u,v,dis);
	}
	
//	g.print(); print adjency list
	
	int src;
	cin>>src;
	
	g.ShortestPath( src, n);
	
	
	return 0;
}
