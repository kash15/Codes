/**KASHISH BABBAR**/
/*
  Problem - SPOJ JOKER1
  Algorithm - Sorting
  Sort all the numbers and then number of possibilies for each index value = arr[i]-i
  (considering 0-based indices)
  Take the product of these values to get the answer.
*/
#include<iostream>
#include<stdio.h>
#include<algorithm>

#define MAX 67
#define ll long long
#define MOD 1000000007
using namespace std;

int maxN[MAX];

int main(){
    int t;
    int N;
    ll ans ;
    cin >> t;
    while (t--){
        ans = 1;
        scanf("%d",&N);
        for (int i=0; i<N; i++){
            scanf("%d",&maxN[i]);
        }
        sort(maxN, maxN + N);
        for (int i=0; i<N; i++){
            ans = (ans * (maxN[i]-i))%MOD;
        }
        cout << ans << endl;
    }
    cout << "KILL BATMAN\n";
    return 0;
}
