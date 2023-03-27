//time complexity O(V+E) 
//space complexity O(V)


#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

class graph{
	public:
		unordered_map<int,list<int>> adj;
		void make_Edge(int u,int v){
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		void dfs(int node,int &timer,vector<int>&parent, vector<int> &low,unordered_map<int,bool>&visited,vector<vector<int>> &result,vector<int> &disc){
			visited[node] = true;
			disc[node] = low[node] = timer++;
			
			for(auto i:adj[node]){
				if(i==parent[node]) continue;
				if(!visited[i]){
					parent[i] = node;
					dfs(i,timer,parent,low,visited,result,disc);
					low[node] = min(low[node],low[i]);
					//check edge is bridge or not
					if(low[i] > disc[node]) {
						vector<int> ans;
						ans.push_back(node);
						ans.push_back(i);
						result.push_back(ans);
					}
				}else{
					low[node] = min(low[node],disc[i]);
				}
			}
			
		}
		
		void findBridge(int n){
			unordered_map<int,bool> visited(n+1);
			int timer =0;
			vector<int> parent(n+1,-1);
			vector<int> disc(n+1,-1);
			vector<int> low(n+1,-1);
			
			vector<vector<int>> result;
			//dfs
			for(int i =0; i<n ;i++){
				if(!visited[i]){
					dfs(i,timer,parent,low,visited,result,disc);
				}
			}
			
			for(int i=0; i<result.size();i++){
				cout<<result[i][0] << " node makes bridge with node "<<result[i][1]<<endl;
			}
		}
};

int main(){
	int n;
	cin>>n; //no of nodes
	
	int m;
	cin>>m; //no of edges
	
	graph g;
	for(int i =0;i<m; i++){
		int u, v;
		cin>> u>> v;
		g.make_Edge(u,v);
	}
	
	g.findBridge(n);
	return 0;
}
