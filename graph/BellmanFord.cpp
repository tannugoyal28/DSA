//algo to find the shortest possible path in a directed graph having negative weights but there should not ne any negative cycle in the graph.
//you can also use this algo to find negative cycle in the graph .
//if you keep obesrving the change in the distance even after the n-1 comparison then you can say there is a negative cycle present .

//#include<iostream>
#include<bits/stdc++.h>
//#include<unordered_map>
//#include<vector>
//#include<list>
//#include<utility>
//#include<limits.h>
using namespace std;

class graph{
	public:
		
		void bellManFord(int n,int src,vector<vector<int>>& edges){
			vector<int> distance(n+1,INT_MAX);
			distance[src] = 0;
			
			//update distance n-1 times;
			for(int i=1; i<=n; i++){
				//traverse the whole list
				for(auto i:edges){
					int u = i[0];
					int v = i[1];
					int wt = i[2];
					
					if(distance[u] != INT_MAX && distance[u] + wt < distance[v]) distance[v] = distance[u] + wt;
				}
			}
			
			//check for negative cycle
			
			bool flag=0;
			for(auto i:edges){
					int u = i[0];
					int v = i[1];
					int wt = i[2];
					
					if(distance[u] != INT_MAX && distance[u] + wt < distance[v]){
						flag = true;
						break;
					}
				}
				
				if(flag) cout<<"cannot find shortest possible path for the nodes because there is a negative cycle present in the graph";
				else{
					for(int i =1; i<=n; i++) cout<<distance[i]<<" ";
				}
		}
		
		
		
};

int main(){
	int n;
	cin>>n; // no of nodes;
	
	int m;
	cin>>m; //no of edges;
	
	graph g;
	
	int u , v;
	int dis;
	vector<vector<int>> edges;
	for(int i =0; i<m ; i++){
		cin>>u>>v>>dis;
		vector<int> temp;
		temp.push_back(u);
		temp.push_back(v);
		temp.push_back(dis);
		edges.push_back(temp);
	}
	int src;
	cin>>src;
	g.bellManFord(n,src,edges);
}
