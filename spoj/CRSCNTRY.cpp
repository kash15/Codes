/****KASHISH BABBAR****/
/*
    Problem SPOJ - CRSCNTRY
    http://www.spoj.com/problems/CRSCNTRY/
    Algorithm - DP (Longest Common Subsequence)
*/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>

#define MAX 2001
using namespace std;

int LCS[MAX][MAX];

int LCS_length(vector<int> a, vector<int> b){
    memset(LCS, 0, sizeof(LCS));
    for(int i=1; i<=a.size(); i++){
        for(int j=1;j<=b.size(); j++){
            if(a[i-1]==b[j-1]){
                LCS[i][j] = 1 + LCS[i-1][j-1];
            }
            else{
                LCS[i][j] = max(LCS[i][j-1], LCS[i-1][j]);
            }
        }
    }
    return LCS[a.size()][b.size()];
}

int main(){
    int t;
    vector<int> agnes_route;
    vector<int> tom_route;
    int max_meets;
    cin >> t;
    while(t--){
        max_meets = 0;
        agnes_route.clear();
        int checkpoint;
        while(1){
            scanf("%d", &checkpoint);
            //cin >> checkpoint;
            if(checkpoint == 0)
                break;
            agnes_route.push_back(checkpoint);
        }
        while(1){
            tom_route.clear();
            scanf("%d", &checkpoint);
            //cin >> checkpoint;
            if(checkpoint == 0){
                cout << max_meets << endl;
                break;
            }
            else{
                tom_route.push_back(checkpoint);
                while(1){
                    scanf("%d", &checkpoint);
                    //cin >> checkpoint;
                    if(checkpoint == 0){
                        break;
                    }
                    tom_route.push_back(checkpoint);
                }
                int common_route_length = LCS_length(agnes_route, tom_route);
                max_meets = max(max_meets, common_route_length);
            }
        }
    }
    return 0;
}
