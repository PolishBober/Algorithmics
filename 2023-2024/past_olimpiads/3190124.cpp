#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Edge {
	ll id;
	char letter;
};

#define MAXN int(2e3 + 7)

vector <Edge> graph[MAXN];
bool visited[MAXN];

ll n;


ll levels[MAXN];
void dfs_levels(ll vertex) {
	visited[vertex] = true;

	for(auto edge : graph[vertex]) {
		if(!visited[edge.id]) {
			levels[edge.id] = levels[vertex] + 1;
			dfs_levels(edge.id);
		}
	}
}



vector <Edge> trie[MAXN];


ll end_trie = 2;
void dfs_trie(ll vertex, ll vertex_trie = 1) {
	visited[vertex] = true;


	for(auto edge : graph[vertex]) {
		if(!visited[edge.id]) {
			
			ll next = -1;
			for(auto edge_trie : trie[vertex_trie])
				if(edge_trie.letter == edge.letter)
					next = edge_trie.id;
			if(next == -1) {
				trie[vertex_trie].push_back({end_trie, edge.letter});
				next = end_trie++;
			}
			

			dfs_trie(edge.id, next);
		}
	}
					
}


struct Description {
	ll beg, end, top;
};
vector <Description> pointers[MAXN];

bool visited_trie[MAXN];


ll start;
void dfs(ll vertex, ll vertex_trie = 1, ll top = 0) {
	visited[vertex] = true;
	visited_trie[vertex_trie] = true;

	if(levels[top] > levels[vertex])
		top = vertex;

	pointers[vertex_trie].push_back({start, vertex, top});


	for(auto edge : graph[vertex]) {
		if(!visited[edge.id]) {
			for(auto edge_trie : trie[vertex_trie]) {
				if(!visited_trie[edge_trie.id] && edge.letter == edge_trie.letter) {
					dfs(edge.id, edge_trie.id, top);
				}
			}
		}
	}

	visited_trie[vertex_trie] = false;
}


void prep() {


	for(ll i = 1; i <= n; ++i)
		visited[i] = false;
	dfs_levels(1);
	levels[0] = INT_MAX;


	for(ll vertex = 1; vertex <= n; ++vertex) {
		for(ll i = 1; i <= n; ++i)
			visited[i] = false;
		start = vertex;
		dfs(vertex);
	}
}


bool check;
ll weights[MAXN];
void dfs_sum(ll vertex) {
	visited[vertex] = true;

	for(auto edge : graph[vertex]) {
		if(!visited[edge.id]) {
			dfs_sum(edge.id);
			weights[vertex] += weights[edge.id];
		}
	}
	if(vertex != 1 && weights[vertex] <= 0)
		check = false;
}


set <string> answer;
void dfs_check(ll vertex, string word = "") {
	visited_trie[vertex] = true;

	for(ll i = 1; i <= n; ++i)
		weights[i] = 0;
	for(auto pointer : pointers[vertex]) {
		weights[pointer.beg] += 1;
		weights[pointer.end] += 1;
		weights[pointer.top] -= 2;
	}

	// for(ll i = 1; i <= n; ++i)
	// 	cout << weights[i] << ' ';
	// cout << '\n';

	check = true;
	for(ll i = 1; i <= n; ++i)
		visited[i] = false;
	dfs_sum(1);

	// cout << word << '\n';
	// for(ll i = 1; i <= n; ++i)
	// 	cout << weights[i] << ' ';
	// cout << '\n';

	
	if(check) {
		answer.insert(word);
		reverse(word.begin(), word.end());
		answer.insert(word);
		reverse(word.begin(), word.end());
	}


	for(auto edge : trie[vertex])
		if(!visited_trie[edge.id])
			dfs_check(edge.id, word + edge.letter);
}


void solv() {

	ll leaf;
	for(ll i = 1; i <= n; ++i) {
		if(graph[i].size() == 1) {
			leaf = i;
			break;
		}
	}

	dfs_trie(leaf);


	prep();


	// for(ll i = 1; i <= n; ++i) {
	// 	cout << levels[i] << ' ';
	// }
	// cout << '\n';
	// for(ll i = 1; i <= n; ++i) {
	// 	cout << i << '\n';
	// 	for(auto edge : trie[i])
	// 		cout << edge.id << ' ' << edge.letter << '\n';
	// }
	// cout << '\n';
	// for(ll i = 1; i <= n; ++i) {
	// 	cout << i << '\n';
	// 	for(auto pointer : pointers[i])
	// 		cout << pointer.beg << ' ' << pointer.end << ' ' << pointer.top << '\n';
	// }
	// cout << '\n';

	dfs_check(1);


	cout << answer.size() << '\n';
	for(auto a : answer)
		cout << a << '\n';
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(ll i = 1; i < n; ++i) {
		ll a, b;
		char letter;
		cin >> a >> b >> letter;
		graph[a].push_back({b, letter});
		graph[b].push_back({a, letter});
	}

	solv();

	return 0;
}