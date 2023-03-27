#include<bits/stdc++.h>
#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;

class graph{
	public:
		unordered_map<int,list<int>> adj;
		void makeEdge(int u,int v){
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		void shortestPath(int n,int s,int t){
			unordered_map<int,bool> visited;
			unordered_map<int,int> parent;
			queue<int> q;
			q.push(s);
			parent[s] = -1;
			visited[s] = true;
			
			while(!q.empty()){
				int front = q.front();
				q.pop();
				
				for(auto i:adj[front]){
					if(!visited[i]){
						visited[i] = true;
						parent[i] = front;
						q.push(i);
					}
				}
			}
			
			vector<int> ans;
			int currNode = t;
			ans.push_back(t);
			while(currNode != s){
				currNode = parent[currNode];
				ans.push_back(currNode);
			}
			
			reverse(ans.begin(),ans.end());
			for(int i=0;i<ans.size();i++){
				cout<<ans[i]<<" ";
			}
			
		}
		
};

int main(){
	int n;
	cin>>n; //no of nodes;
	
	int m;
	cin>>m; //no of edges;
	
	graph g;
	for(int i=0; i<m; i++){
		int u,v;
		cin>>u>>v;
		g.makeEdge(u,v);
	}
	int src,t;
	cin>>src>>t;
	g.shortestPath(n,src,t);
	
	return 0;
}
