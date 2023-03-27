//topologicalSort using BFS(Kahn's Algo)
#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
using namespace std;

class graph{
	public:
		unordered_map<int,list<int>> adj;
		void makeEdge(int u, int v){
			adj[u].push_back(v);
		}
		
		void topologicalSort(int n){
			vector<int> indegree(n+1);
			queue<int> q;
			vector<int> ans;
			for(auto i:adj){
				for(auto j:i.second) indegree[j]++;
			}
			for(int i=0; i<n;i++){
				if(indegree[i] == 0) q.push(i);
			}
			while(!q.empty()){
				int front = q.front();
				q.pop();
				ans.push_back(front);
				for(auto i: adj[front]){
					indegree[i]--;
					if(indegree[i]==0) q.push(i);
				}
			}
			for(int i=1; i<=n; i++){
				cout<<ans[i]<<" ";
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
		int u, v;
		cin>>u>>v;
		g.makeEdge(u,v);
	}
	g.topologicalSort(n);
	return 0;
}
