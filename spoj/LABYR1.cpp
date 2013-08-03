/***********KASHISH BABBAR*************/
/*
    Problem - SPOJ LABYR1
    http://www.spoj.com/problems/LABYR1/
    Algorithm - DFS

*/

#include<iostream>
#include<stdio.h>
#include<stack>
#include<string.h>

#define MAX 1001
#define mp(i,j) make_pair(i,j)
#define pp pair<int, int>
#define ppp pair<pair<int,int>, int>
using namespace std;

int C, R;
char labyr[MAX][MAX];
bool visited[MAX][MAX];

int x[4] = {0, 0, 1, -1};
int y[4] = {-1, 1, 0, 0};

int dfs(int i, int j, int stage){
    memset(visited, 0, sizeof(visited));
    stack<pair<pair<int,int>, int> > s;
    s.push(mp(mp(i,j),0));
    int max_depth = 0;
    int max_x = i, max_y = j;
    while(!s.empty()){
        ppp top = s.top();
        s.pop();
        pp index = top.first;
        visited[index.first][index.second] = true;
        int cur_depth = top.second;
        if (cur_depth > max_depth){
            max_depth = cur_depth;
            max_x = index.first;
            max_y = index.second;
        }
        for (int i=0;i<4;i++){
            int x_next = index.first + x[i];
            int y_next = index.second + y[i];
            if (x_next>=0 && x_next <R && y_next>=0 && y_next<C ){
                if (labyr[x_next][y_next] == '.' && !visited[x_next][y_next]){
                    s.push(mp(mp(x_next,y_next), cur_depth+1));
                }
            }
        }
    }
    /*
        ...#
        ..##
        .###
        ####
        On starting at index 0,0 , we need two DFS to find the maximum length of rope.
        First DFS will give the index at maximum depth from vertex 0,0 .
        Now, we apply DFS using that index as start node to get the maximum length of rope.
    */
    if (stage == 1){
         return dfs(max_x, max_y, 2);
    }
    else {
        return max_depth;
    }
}

int main(){
    int t, max_length;
    string s;
    cin >> t;
    while(t--){
        max_length = 0;
        cin >> C >> R;
        for (int i=0; i<R; i++){
            cin >> s;
            for (int j=0; j<C; j++){
                labyr[i][j] = s[j];
            }
        }
        memset(visited, 0, sizeof(visited));
        for (int i=0; i<R; i++){
            for (int j=0; j<C; j++){
                if (!visited[i][j] && labyr[i][j]=='.'){
                    int depth = dfs(i, j, 1);
                    if (depth > max_length){
                        max_length = depth;
                    }
                }
            }
        }
        cout << "Maximum rope length is " << max_length << "." << endl;
    }
    return 0;
}

