#include <iostream>
#include <vector>
using namespace std;

int maximize_profit(int n, int m, vector<int>& weights, vector<int>& profits) {
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j >= weights[i-1]) {
                dp[i][j] = max(dp[i-1][j], profits[i-1] + dp[i-1][j-weights[i-1]]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][m];
}

int main() {
    int n, m;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the sack: ";
    cin >> m;
    
    vector<int> weights(n), profits(n);
    cout << "Enter the weight and profit of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> weights[i] >> profits[i];
    }
    
    int max_profit = maximize_profit(n, m, weights, profits);
    cout << "Maximum profit that can be earned: " << max_profit << endl;
    
    return 0;
}


dp table will be

  | 0 1 2 3 4 5 6 7
--+---------------
0 | 0 0 0 0 0 0 0 0
1 | 0 0 3 3 3 3 3 3
2 | 0 0 3 4 4 7 7 7
3 | 0 0 3 4 5 7 8 8
4 | 0 0 3 4 5 8 9 11
  
  
  dp table explanaion:
Sure, here's an explanation of the dynamic programming table:

The table has n+1 rows and m+1 columns, where n is the number of items and m is the capacity of the sack.

The first row and the first column of the table are initialized to 0, since we cannot earn any profit by considering no items or by using a sack with no capacity.

Each cell dp[i][j] in the table represents the maximum profit that can be earned by considering the first i items and having a sack capacity of j.

To fill in the table, we use the following recurrence relation:

json
Copy
dp[i][j] = max(dp[i-1][j], profits[i-1] + dp[i-1][j-weights[i-1]])
If the weight of the i-th item is less than or equal to j (i.e., we can fit the i-th item in the sack), then there are two options:

We do not take the i-th item, and the maximum profit we can earn is the same as considering the first i-1 items with a sack capacity of j: dp[i-1][j].
We take the i-th item, and the maximum profit we can earn is the profit of the i-th item plus the maximum profit we can earn
by considering the first i-1 items with a reduced sack capacity of j-weights[i-1]: profits[i-1] + dp[i-1][j-weights[i-1]].
If the weight of the i-th item is greater than j (i.e., we cannot fit the i-th item in the sack), then we cannot take the i-th item,
and the maximum profit we can earn is the same as considering the first i-1 items with a sack capacity of j: dp[i-1][j].

We choose the maximum of these two options as the value of dp[i][j].

The final answer is the value of dp[n][m], which represents the maximum profit that can be earned by considering all the items with a sack capacity of m.

In the example input you provided (n=4, m=7, weights=[2,3,4,5], profits=[3,4,5,8]), the dynamic programming table would look like this:

basic
Copy
  | 0 1 2 3 4 5 6 7
--+---------------
0 | 0 0 0 0 0 0 0 0
1 | 0 0 3 3 3 3 3 3
2 | 0 0 3 4 4 7 7 7
3 | 0 0 3 4 5 7 8 8
4 | 0 0 3 4 5 8 9 11
For example, the value in cell dp[3][5] represents the maximum profit that can be earned by considering the first 3 items 
(with weights [2,3,4] and profits [3,4,5]) and having a sack capacity of 5. We can see that the maximum profit in this case is 7, 
which is obtained by taking the first and third items (with a total weight of 6 and a total profit of 8).
  
  sample inputs:
1) In this input, the thief has 4 items to choose from, with weights and profits as follows:

Item 1: weight = 2, profit = 3
Item 2: weight = 3, profit = 4
Item 3: weight = 4, profit = 5
Item 4: weight = 5, profit = 8
The capacity of the sack is 7 units.     o/p:-11
  
  2)In this input, the thief has 4 items to choose from, with weights and profits as follows:

Item 1: weight = 2, profit = 3
Item 2: weight = 3, profit = 4
Item 3: weight = 4, profit = 5
Item 4: weight = 5, profit = 6
The capacity of the sack is 5 units.      o/p :- 7
  
