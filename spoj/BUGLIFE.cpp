/**KASHISH BABBAR**/
/*
  Problem - SPOJ BUGLIFE
  Algorithm - Bipartite 
  For each node, check whether it is possible to color it only using 1 color.
  Start from the first node and color its neighboring nodes using color different
  from color of first node.
  Repeat this process for all nodes.
  If at aan time, you come accross a node that has alreay been colored but now has to
  colored with  the other color, stop. No bipartite graph possible.
*/
#include<iostream>
#include<stdio.h>
#include<vector>
 
#define MAX 20001
using namespace std;
 
vector<int> bugs[MAX];
int color[MAX];
 
int main(){
 
    int t;
    int num_bugs, num_intr;
    int bug1, bug2;
    cin >> t;
    int scenario = 1;
    while(scenario <= t){
        scanf("%d%d",&num_bugs, &num_intr);
        for (int i=1; i<=num_bugs; i++){
            bugs[i].clear();
            color[i] = 2;
        }
        for (int i=0; i<num_intr; i++){
            scanf("%d%d",&bug1,&bug2);
            bugs[bug1].push_back(bug2);
            bugs[bug2].push_back(bug1);
        }
        color[1] = 0;
        bool flag = true;
        for (int i=1; i<=num_bugs; i++){
            if (color[i] == 2)
                color[i] = 0;
            int cur_color = color[i];
            //cout << "Color " << i << " " << color[i] << endl;
            int color_neighbors = (cur_color + 1)%2;
            for(int j=0; j<bugs[i].size();j++){
                if (color[bugs[i][j]] == cur_color){
                    //cout << i << " Neighbor " << bugs[i][j] << endl;
                    flag = false;
                    break;
                }
                else {
                    color[bugs[i][j]] = color_neighbors;
                }
            }
            if (flag == false)
                break;
        }
        printf("Scenario #%d:\n",scenario);
        if (flag == false){
            printf("Suspicious bugs found!\n");
        }
        else{
            printf("No suspicious bugs found!\n");
        }
        scenario++;
    }
    return 0;
}
 
