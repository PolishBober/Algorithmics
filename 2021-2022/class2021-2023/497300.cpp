#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn = 1e6;
ll coins[maxn + 1];
ll answers[maxn + 1];
ll k, n;

inline void readUI(ll *n) //tylko dodatnie
{
    register char c = 0;
    while (c < 33) c=getc_unlocked(stdin);
    (*n) = 0;
    while (c>32) {(*n)=(*n)*10LL + (c-48); c=getc_unlocked(stdin);}
}

int main() {
    readUI(&k); readUI(&n);
    for(ll i = 0; i < n; ++i)
        readUI(&coins[i]);
    for(ll i = 1; i <= k; ++i) {
        answers[i] = k + 1;
        for(ll j = 0; j < n; ++j)
            if(coins[j] <= i)
                answers[i] = min(answers[i], answers[i - coins[j]] + 1);
    }
    if(answers[k] == k + 1)
        printf("NIE");
    else
        printf("%i", answers[k]);
}