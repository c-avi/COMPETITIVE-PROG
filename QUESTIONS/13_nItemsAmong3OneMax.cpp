#include <bits/stdc++.h>
using namespace std;

int ways(int n) {
    if (n < 4) return 0;
    
    // total no of ways to distribute n items among 3 people
    int ans = ((n - 1) * (n - 2)) / 2;

    //distribution which are not possible
    int s = 0;

    for (int i = 2; i <= n-3; i++) {
        for (int j = 1; j < i; j++) {

            // count possibilities of two persons receiving the maximum
            if (n == 2 * i + j) s++;
        }
    }

    if (n % 3 == 0) s = 3 * s + 1;
    else s = 3 * s;

    return  ans - s;
}

int main() {
    int n;
    cout << "N = ";
    cin >> n;
    cout << ways(n);

    return 0;
}