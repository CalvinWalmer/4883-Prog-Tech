#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long int ll;


//Code adapted from https://www.geeksforgeeks.org/lcm-of-given-array-elements/
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Returns LCM of array elements
//Code adapted from https://www.geeksforgeeks.org/lcm-of-given-array-elements/
ll findlcm(vector<int> list, int n)
{
    // Initialize result
    ll ans = list.at(0);
 
    // ans contains LCM of arr[0], ..arr[i]
    // after i'th iteration,
    for (int i = 1; i < n; i++)
        ans = (((list.at(i) * ans)) /
                (gcd(list.at(i), ans)));
 
    return ans;
}




int main()
{
    int x, c;
    vector<int> list;

    while(cin >> x){
        if(x == 0){
            c++;
            cout << findlcm(list, list.size()) << endl;
            list.empty();
        }
        else{
            c = 0;
            list.push_back(x);
        } 
        if (c >= 3){
            break;
        }
    };
}