#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x) {
    string s = to_string(x);
    string r = s;
    reverse(r.begin(), r.end());
    return s == r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> pal;

    // Precompute palindromes from products of 3-digit numbers
    for (int i = 100; i <= 999; i++) {
        for (int j = i; j <= 999; j++) { // j = i to avoid duplicates
            int p = i * j;
            if (isPalindrome(p)) pal.push_back(p);
        }
    }

    sort(pal.begin(), pal.end());

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        // Find largest palindrome < n
        auto it = lower_bound(pal.begin(), pal.end(), n);
        it--;   // move to value < n
        cout << *it << "\n";
    }

    return 0;
}
