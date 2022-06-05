//fractional knapsack by greedy approach
#include <bits/stdc++.h> //library for the sort() function
#include <iostream>
using namespace std;

struct Item {
int value, weight;
Item(int value, int weight)
{
this->value = value;
this->weight = weight;
}
};

bool cmp(struct Item a, struct Item b)
{
double r1 = (double)a.value / (double)a.weight;
double r2 = (double)b.value / (double)b.weight;
return r1 > r2;
}

double fractionalKnapsack(int W, struct Item arr[], int n)
{
sort(arr, arr + n, cmp);    //O(N log N)
double finalvalue = 0.0;
for (int i = 0; i < n; i++) {
 if (arr[i].weight <= W) {
   W -= arr[i].weight;
   finalvalue += arr[i].value;
 }
else {
finalvalue += arr[i].value * ((double)W / (double)arr[i].weight);
break;
}
}

return finalvalue;
}

int main()
{
int W = 50;
Item arr[] = { { 120, 30 }, { 100, 20}, { 60, 10 } };
int n = sizeof(arr) / sizeof(arr[0]);
cout << "Maximum value we can obtain = " << fractionalKnapsack(W, arr, n);
return 0;
}

//The whole problem can be solved in O(n log n) only.
