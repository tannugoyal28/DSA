#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<vector>
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
			for(auto i:adj){
				cout<<i.first<<"->";
				for(auto j:i.second){
					cout<<j<<",";
				}
				cout<<endl;
			}
		}
		
		void bfs(unordered_map<int,bool> &visited,vector<int> &ans,int node){
			queue<int> q;
			q.push(node);
			visited[node] = true;
			while(!q.empty()){
				int frontNode = q.front();
				q.pop();
				
				ans.push_back(frontNode);
				for(auto i:adj[frontNode]){
					if(!visited[i]){
						q.push(i);
					    visited[i] = true;
					}
				}
			}
		}
		
		void BFS(int n){
			unordered_map<int,bool>visited ;
			vector<int> ans;
			for(int i =0; i<n; i++){
				if(!visited[i]) bfs(visited,ans,i);
			}
			
			for(int i =1; i<ans.size(); i++){
				cout<<ans[i];
			}
		}
};

int main(){
	int n;
	cin>>n; //no of node
	
	int m;
	cin>>m; //no of edges
	
	graph g;
	
	for(int i =0; i<m; i++){
		int u , v;
		cin>>u >> v;
		g.makeEdge(u,v,false);
	}
	
	g.BFS(n);
	return 0;
	
}
