#include <iostream>
using namespace std;

// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

#define ll long long int 
 
// Function to return the minimum cost 
int minimumCost(ll price[], int n) 
{ 
  
    // Sort the price array 
    sort(price, price + n); 
    ll totalCost = 0; 
  
    // Calcualte minimum price 
    // of n-2 most costly person 
    for (int i = n - 1; i > 1; i -= 2) { 
        if (i == 2) { 
            totalCost += price[2] + price[0]; 
        } 
        else { 
  
            // Both the ways as discussed above 
            ll price_first = price[i] + price[0] + 2 * price[1]; 
            ll price_second = price[i] + price[i - 1] + 2 * price[0]; 
            totalCost += min(price_first, price_second); 
        } 
    } 
  
    // Calculate the minimum price 
    // of the two cheapest person 
    if (n == 1) { 
        totalCost += price[0]; 
    } 
    else { 
        totalCost += price[1]; 
    } 
  
    return totalCost; 
} 
  
// Driver code 
int main() 
{ 
    ll price[] = {300,400,600,700};
    int n = sizeof(price) / sizeof(price[0]); 
  
    cout << minimumCost(price, n); 
  
    return 0; 
} 