/**********KASHISH BABBAR**********/
/*
  Problem - SPOJ FPOLICE
	Algorithm - Dijkstra (can also be done using DP ) (similar to SPOJ problem FISHER)
	Instead of only having a single node as the state, we take
	node and time as one state and then apply dijkstra.
	risk is the weight between the states.
	we need to minimize the risk without exceeding the time limit.
*/
#include<iostream>
#include<stdio.h>
#include<queue>
#include<string.h>
 
const int MAX=1000000;
 
using namespace std;
 
int risk[101][101];
int reach_time[101][101];
int dist[101][251];
bool visited[101][251];
 
struct node {
	int vertex;
	int n_time;
	int n_risk;
};
 
bool operator < (node a, node b){
	if (a.n_risk != b.n_risk)
		return a.n_risk > b.n_risk;
	if (a.n_time != b.n_time)
		return a.n_time > b.n_time;
	return a.vertex > b.vertex;
}
 
void dijkstra(int N, int T){
	priority_queue< node > d_heap;
	dist[1][0] = 0;
	d_heap.push((node){1, 0, 0});
	while (!d_heap.empty()){
		node top = d_heap.top();
		d_heap.pop();
		//cout << "TOP " << top.vertex << endl;	
		if (visited[top.vertex][top.n_time]){
			continue;
		}
 
		visited[top.vertex][top.n_time] = true;
		int u = top.vertex;
		int cur_time = top.n_time;
		int cur_risk = top.n_risk;
		for (int i=1; i<=N; i++){
			if (i != u){
				int i_time = cur_time + reach_time[u][i];
				if (i_time > T)
						continue;
				//cout << "dist[u]cur_time] " << dist[u][cur_time] << " risk[u][i] " << risk[u][i]  << endl;
				if (dist[u][cur_time] + risk[u][i] <= dist[i][i_time]){
					dist[i][i_time] = dist[u][cur_time] + risk[u][i];
					d_heap.push((node){i, i_time, dist[i][i_time]});
					//cout << "Vertex " << i << " Time " << i_time << " Risk " << dist[i][i_time] << endl;
				}
			}
		}
	}
}
 
int main(){
	
	int t;
	int N, T;
	cin >> t;
	while (t--){
		scanf("%d%d",&N,&T);
		memset(visited, 0, sizeof(visited));
        //	cout << visited[3][4] << visited[1][3];
		for(int i=1;i<=N;i++){
			for (int j=0; j<=T; j++){
				dist[i][j] = MAX;
			}
            		//time_min_risk[i] = MAX;
            		for (int j=1;j<=N;j++){
                	scanf("%d",&reach_time[i][j]);
            		}
        	}
        
		for(int i=1;i<=N;i++){
            		for (int j=1;j<=N;j++){
                		scanf("%d",&risk[i][j]);
            		}
        	}
		dijkstra(N, T);
		int min_risk = MAX;
		int min_time = MAX;
		for (int i=0; i<=T; i++){
			if (dist[N][i] < min_risk){
				min_risk = dist[N][i];
				min_time = i;
			}
		}
		if (min_time != MAX)
			printf("%d %d\n", min_risk, min_time);
		else
			printf("-1\n");
	}	
	return 0;
}
