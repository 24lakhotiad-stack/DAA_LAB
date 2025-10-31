#include <bits/stdc++.h>
using namespace std;
class Solution{
    public :
        int optimalSearchTree(int keys[], int freq[], int n){
            int cost[n][n];
for (int i = 0; i < n; i++)
    cost[i][i] = freq[i];
for (int L = 2; L <= n; L++)
{
    for (int i = 0; i <= n - L; i++)
    {
        int j = i + L - 1;
        cost[i][j] = INT_MAX;
        int sum = 0;
        for (int s = i; s <= j; s++)
            sum += freq[s];
        for (int r = i; r <= j; r++)
        {
            int c = ((r > i) ? cost[i][r - 1] : 0) +
                    ((r < j) ? cost[r + 1][j] : 0) + sum;
            cost[i][j] = min(cost[i][j], c);
        }
    }
}
return cost[0][n - 1];
}
}
;