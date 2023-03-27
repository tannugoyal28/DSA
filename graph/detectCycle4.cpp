//detecting cycle in the directed graph using bfs traversal
#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<list>
using namespace std;

class graph{
	public:
		unordered_map<int,list<int>> adj;
		void makeEdge(int u,int v){
			adj[u].push_back(v);
		}
		
		bool topologicalSort(int n){
			vector<int> indegree(n);
			queue<int> q;
			for(auto i: adj){
				for(auto j:i.second){
					indegree[j]++;
				}
			}
			
			for(int i =0; i<n ; i++){
				if(indegree[i] == 0) q.push(i);
			}
			
			int count;
			while(!q.empty()){
				int front = q.front();
				q.pop();
				count++;
				for(auto i:adj[front]){
					indegree[i]--;
					if(indegree[i] == 0) q.push(i);
				}
			}
			
			return n==count;
			
		}
		
};

int main(){
	
	int n;
	cin>>n; //no of nodes;
	
	int m;
	cin>>m; //no of edges;
	
	graph g;
	for(int i=0; i<m; i++){
		int u ,v;
		cin>>u>>v;
		g.makeEdge(u,v);
	}
	
	if(g.topologicalSort(n)) cout<<"cycle is present";
	else cout<<"there is no cycle in the graph";
	
	return 0;
}

