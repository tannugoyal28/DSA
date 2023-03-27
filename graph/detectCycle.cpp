//finding cycle in undirected graph using bfs traversal 
#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>
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
			for(auto i:adj){
				cout<<i.first<<"->";
				for(auto j:i.second){
					cout<<j<<" ";
				}
				cout<<endl;
			}
		}
		
		bool isCycle(int node , unordered_map<int,bool> &visited){
			unordered_map<int,int> parent;
			parent[node] = -1;
			visited[node] = 1;
			queue<int> q;
			q.push(node);
			while(!q.empty()){
				int front = q.front();
				q.pop();
				for(auto neighbour:adj[front]){
					if(visited[neighbour] && neighbour != parent[front]) return true;
					else if(!visited[neighbour]){
						q.push(neighbour);
						visited[neighbour] = 1;
						parent[neighbour] = front;
					}
				}
			}
			return false;
		}
		
		string detectCycle(int n){
			unordered_map<int,bool> visited;
			for(int i=0; i<n;i++){
				if(!visited[i]){
					bool ans = isCycle(i,visited);
					if(ans) return "yes cycle is present";
				}
			}
			return "no there is no cycle present in the graph";
		}
};

int main(){
	int n;
	cin>>n; //no of node
	
	int m;
	cin>>m; //no of edges
	
	graph g;
	
	for(int i=0;i<n;i++){
		int u, v;
		cin>>u>>v;
		g.makeEdge(u,v,false);
	}
	
	cout<<g.detectCycle(n);
	
	return 0;
}
