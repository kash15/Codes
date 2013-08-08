/****KASHISH BABBAR****/
/*
    Problem - SPOJ LISA
    Algorithm - DP (Matrix Chain Multiplication) Need to fond the best parenthesization.
*/
#include<iostream>
#include<stdio.h>
#include<string>
#include<limits.h>

#define ll long long
#define MAXLEN 52
#define MAXOP 51
using namespace std;

int operands[MAXLEN];
char operators[MAXOP];
ll max_values[MAXLEN][MAXLEN];
ll min_values[MAXLEN][MAXLEN];

int main(){
    int k;
    string expr;
    cin >> k;
    while(k--){
        cin >> expr;
        int operand_index = 0;
        int operator_index = 0;
        for(int i=0; i<expr.length(); i+=2){
            operands[operand_index++] = expr[i]-'0';
            //cout << operand_index-1 << " " << operands[operand_index-1] << endl;
        }
        for(int i=1; i<expr.length(); i+=2){
            operators[operator_index++] = expr[i];
            //cout << operator_index-1 << " " << operators[operator_index-1] << endl;
        }

        for(int i=0;i<operand_index; i++){
            max_values[i][i] = operands[i];
            min_values[i][i] = operands[i];
        }

        ll val_for_max;
        ll val_for_min;
        // len is the chain length
        for(int len = 2; len <= operand_index; len++){
            //cout << "Length " << len << endl;
            for(int start=0; start<operand_index-len+1; start++){
                //cout << "Start " << start << endl;

                int end = start+len-1;
                //cout << "End " << end << endl;
                max_values[start][end] = LLONG_MIN;
                //cout << max_values[start][end];
                min_values[start][end] = LLONG_MAX;
                for(int k = start; k <= end-1; k++){
                    if(operators[k] == '+'){
                        val_for_max = max_values[start][k] + max_values[k+1][end];
                        //cout << "val_for_max " << val_for_max << endl;
                        if(val_for_max > max_values[start][end])
                            max_values[start][end] = val_for_max;

                        val_for_min = min_values[start][k] + min_values[k+1][end];
                        //cout << "val_for_min " << val_for_min << endl;
                        if(val_for_min < min_values[start][end])
                            min_values[start][end] = val_for_min;
                    }
                    // else the operator is '*'
                    else{

                        val_for_max = max_values[start][k] * max_values[k+1][end];
                        //cout << "val_for_max " << val_for_max << endl;
                        if(val_for_max > max_values[start][end])
                            max_values[start][end] = val_for_max;

                        val_for_min = min_values[start][k] * min_values[k+1][end];
                        //cout << "val_for_min " << val_for_min << endl;
                        if(val_for_min < min_values[start][end])
                            min_values[start][end] = val_for_min;
                    }
                }
            }
        }
        cout << max_values[0][operand_index-1] << " " << min_values[0][operand_index-1] << endl;

    }
    return 0;
}
