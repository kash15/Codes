/*******KASHISH BABBAR******/
/*
    Problem - SPOJ FISHER
    Algorithm - DP
    ( can also be done using Dijkstra (did it for FPOLICE).
    This problem is similar to spoj PROBLEM FPOLICE AND ROADS.
    dp[i][t] -> represents the minimum toll u need to pay
    to reach state n in time t.
    DP equation : dp[i][t] = min(dp[i][t-1], dp[j][t-time[j][i]] + toll[j][i])
     Either you stay at the same state for 1 time unit or you come to to state i
     from some other state j.
     For each value of time t, calculate the minimum toll for each state using the above equation.
*/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>

#define MAX 10000000

using namespace std;

int reach_time[51][51];
int toll[51][51];
int dp[51][1001];

int main(){
    int N, T;
    while(1){
        scanf("%d%d",&N, &T);
        if (N==0 && T==0)
            break;
        for (int i=1; i<=N; i++){
            for (int j=1; j<=N; j++){
                scanf("%d",&reach_time[i][j]);
            }
        }
          for (int i=1; i<=N; i++){
            for (int j=1; j<=N; j++){
                scanf("%d",&toll[i][j]);
            }
        }
        // We start from the first state.
        for (int i=0; i<=T; i++){
            dp[1][i] = 0;
        }
        // for all other states, initialize toll to a very high value.
        for (int i=2; i<=N; i++){
            for (int j=0; j<=T; j++){
                dp[i][j] = MAX;
            }
        }

        for(int t=0; t<=T; t++){
            for(int i=1; i<=N; i++){
                for(int j=1; j<=N; j++){
                    if (t > 0){
                        dp[i][t] = min(dp[i][t], dp[i][t-1]);
                    }
                    if ((t-reach_time[j][i] >=0)){
                        dp[i][t] = min(dp[i][t], dp[j][t-reach_time[j][i]] + toll[j][i]);
                    }
                }
            }
        }
        int ans = MAX;
        int min_time = MAX ;
        for (int i=0; i<=T; i++){
            if(dp[N][i] < ans){
                ans = dp[N][i];
                min_time = i;
            }
        }
        if (min_time != MAX){
            printf("%d %d\n", ans, min_time);
        }
        else {
            printf("-1\n");
        }
    }
    return 0;
}
