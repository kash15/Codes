#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>
#include<string.h>

#define MAX 1000000;

using namespace std;

struct node {
	int vertex;
	int cost;
};

vector< node > graph[10001];
int dist[10001];
bool visited[10001];

bool operator < ( node a, node b){
	if (a.cost != b.cost){
		return (a.cost > b.cost );
	}
	if (a.vertex != b.vertex){
		return a.vertex > b.vertex;
	}
	return false;
}

void dijkstra(int N, int start, int end){
	priority_queue< node > d_heap;
	dist[start] = 0;
	d_heap.push( (node){start, 0});
	while (!d_heap.empty()){
		node top = d_heap.top();
		d_heap.pop();
		
		// make sure we don't visit the same vertex again
		if (visited[top.vertex])
			continue;
		
		visited[top.vertex] = true;
		
		int u = top.vertex;
		for (int i = 0; i < graph[u].size(); i++){
			int v = graph[u][i].vertex;
			int cost = graph[u][i].cost;
			if ( dist[u] + cost < dist[v]){
				dist[v] = dist[u] + cost ;
				d_heap.push(graph[u][i]);	// push this node (vertex, cost) into the heap (See Dijkstra Algorithm)
			}
		}
	
	}
}

int main(){
	int t;
	int num_vertices, num_edges; /*number of vertices, number of edges*/
	int u, v, w;
	int start_vertex, end_vertex;
	cin >> t;
	while (t--){
		cin >> num_vertices >> num_edges;
		for (int i=0; i<=num_vertices; i++){
			graph[i].clear();
			dist[i] = MAX;
			visited[i] = false;
		}
		for (int i=0; i<num_edges; i++){
			scanf("%d%d%d",&u, &v, &w);
			graph[u].push_back( (node) {v, w});
		}
		scanf("%d%d",&start_vertex, &end_vertex);
		dijkstra(num_vertices, start_vertex, end_vertex);
		if (dist[end_vertex] != 1000000){
			printf("%d\n", dist[end_vertex]);
		}
		else {
			printf("NO\n");
		}
	}
}
