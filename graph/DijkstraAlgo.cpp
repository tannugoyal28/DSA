//dijkstra's shortest path Algorithm
//time complexity O(ElogV) e for edges and v stands for vertices
//undirected cyclic weighted graph 
//space complexity O(N+E) linear
#include<iostream>
#include<bits/stdc++.h>
#include<unordered_set>
#include<vector>
#include<list>
#include<utility>
#include<limits.h>
using namespace std;

class graph{
	public:
		//creating adjancey matrix
		unordered_map<int,list<pair<int,int>>> adj;
		void makeEdge(int u,int v,int dis){
			adj[u].push_back({v,dis});
			adj[v].push_back({u,dis});
	    }
	    
	    void dijkstraAlgo(int n,int src){
	    	//creation of distance array with infinite value intially
	    	vector<int> distance(n,INT_MAX);
	    	//creation of set on basis (distance, node)
	    	set<pair<int,int>> st;
	    	
	    	//initialse distance and set with source node
	    	distance[src] = 0; 
	    	st.insert(make_pair(0,src));
	    	
	    	while(!st.empty()){
	    		//fetch top record
	    		auto top = *(st.begin());
	    		int nodeDistance = top.first;
	    		int topNode = top.second;
	    		//remove top record
	    		st.erase(st.begin());

	    		//traverse on neighbours
	    		for(auto i:adj[topNode]){
	    			if(nodeDistance + i.second < distance[i.first]){
	    				auto record = st.find(make_pair(distance[i.first],i.first));
	    				//if record found then erase it
	    				if(record != st.end()) st.erase(record);
					distance[i.first] = nodeDistance + i.second;
					st.insert(make_pair(distance[i.first],i.first));
				}
			}
		}
		
		for(int i=0; i<distance.size(); i++){
			cout<<distance[i]<<" ";
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
		int u , v , dis;
		cin>>u>>v>>dis;
		g.makeEdge(u,v,dis);
	}
	
	int src;
	cin>>src;
	
	g.dijkstraAlgo(n,src);
	return 0;
}
