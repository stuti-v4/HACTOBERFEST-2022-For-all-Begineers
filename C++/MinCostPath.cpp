// Name : Stuti Verma
// Date : 23/10/2022

#include <bits/stdc++.h>
using namespace std;
 
#define row 3
#define col 3
 
int minCost(int cost[row][col])
{
 
    // for 1st column
    for (int i = 1; i < row; i++)
        cost[i][0] += cost[i - 1][0];
   
    // for 1st row
    for (int j = 1; j < col; j++)
        cost[0][j] += cost[0][j - 1];
   
    // for rest of the 2d matrix
    for (int i = 1; i < row; i++)
        for (int j = 1; j < col; j++)
            cost[i][j] += min(cost[i - 1][j - 1], min(cost[i - 1][j], cost[i][j - 1]));
 
    // returning the value in last cell
    return cost[row - 1][col - 1];
}
int main(int argc, char const* argv[])
{
    int cost[row][col] = { { 1, 2, 3 }, { 4, 8, 2 }, { 1, 5, 3 } };
 
    cout << minCost(cost) << endl;
    return 0;
}
