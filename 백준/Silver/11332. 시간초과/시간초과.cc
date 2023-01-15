#include <iostream>
#include <cmath>

using namespace std;

double log_f(double n)
{
    int i = 1; double v = 1;
    while ((v *= ++i) <= n);
    return i-1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int C; cin >> C;

    while (C--) {
        string S; double N, T, L;
        cin >> S >> N >> T >> L;

        L *= 100'000'000;
        L /= T; 

        bool isPossible = true;
        if (S == "O(N)" && N > L) { isPossible = false; }
        if (S == "O(N^2)" && N*N > L) { isPossible = false; }
        if (S == "O(N^3)" && N*N*N > L) { isPossible = false; }
        if (S == "O(2^N)" && N > log2(L)) { isPossible = false; }
        if (S == "O(N!)" && N > log_f(L)) { isPossible = false; }

        cout << ((isPossible) ? "May Pass." : "TLE!") << endl;
    }
}