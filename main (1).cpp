//fractional knapsack by brute force recursively 

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
int max(int a, int b) {
    return (a > b) ? a : b;
}
int knapSack(int W, int wt[], int val[], int n)
{
    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] <= W) {
        return max((val[n - 1]) + knapSack(W - (wt[n - 1]), wt, val, n - 1), knapSack(W, wt, val, n - 1));
    }
    // Return the maximum of two cases:
    // nth item included, not included
    else
    {
        double delta=(double)W/(double)wt[n-1];
        return max((val[n - 1])*delta + knapSack(W - (delta*wt[n - 1]), wt, val, n - 1), knapSack(W, wt, val, n - 1));
    }
   
}

int main()
{
    int val[] = { 120, 100, 60 };
    int wt[] = { 30, 20, 10 };  
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << "Maximum value we can obtain = "<< knapSack(W, wt, val, n);
    return 0;
}

//The time complexity of this naive recursive solution is exponential (2^n).  