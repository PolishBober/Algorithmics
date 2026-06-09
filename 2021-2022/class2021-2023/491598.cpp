#include <iostream>
using namespace std;
long long n,m,q;
const long long MAX_N = 1e3;
bool arr[MAX_N+1][MAX_N+1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	long long a, b;
	for(long long i = 0; i < m; ++i) {
		cin >> a >> b;
		arr[a][b] = true;
		arr[b][a] = true;
	}
	cin >> q;
	for(long long i = 0; i < q; ++i) {
		cin >> a >> b;
		if(arr[a][b])
			cout << "TAK\n";
		else
			cout << "NIE\n";
	}
}