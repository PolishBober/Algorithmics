#include <bits/stdc++.h>
using namespace std;
const int LIM = 1<<30;
struct Node{
	Node *l=nullptr,*r=nullptr;
	int val=0, lazy=0;
};
void split(Node *v, int x){
	(v->l)->val=x/2-(v->l)->val;
	(v->l)->lazy^=v->lazy;
	(v->r)->val=x/2-(v->r)->val;
	(v->r)->lazy^=v->lazy;
	v->lazy=0;
}
void upd(Node *v, int l, int r, int a, int b){
	if(a<=l && r<=b){
		v->val=r-l+1-v->val;
		v->lazy^=1;
		return;
	}
	if(a>r || b<l){
		return;
	}
	if(v->l==nullptr) v->l= new Node();
	if(v->r==nullptr) v->r= new Node();
	if(v->lazy!=0)split(v, r-l+1);
	int mid=(r+l)/2;
	upd(v->l, l, mid, a, b);
	upd(v->r, mid+1, r, a, b);
	v->val=(v->l)->val+(v->r)->val;
	return;
}
int cnt(Node *v, int l, int r, int a, int b){
	if(a<=l && r<=b){
		return v->val;
	}
	if(a>r || b<l){
		return 0;
	}
	if(v->l==nullptr) v->l= new Node();
	if(v->r==nullptr) v->r= new Node();
	if(v->lazy!=0)split(v, r-l+1);
	int mid=(r+l)/2;
	int out=cnt(v->l, l, mid, a, b)+cnt(v->r, mid+1, r, a, b);
	v->val=(v->l)->val+(v->r)->val;
	return out;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, a, b;
	Node *root = new Node();
	char c;
	upd(root, 0, LIM-1, 0, LIM-1);
	cin >> n >> m;
	for(int i=0; i<m; i++){
		cin >> c >> a >> b; a--; b--;
		if(c=='?'){
			cout << cnt(root, 0, LIM-1, a, b) << "\n"; 
		}else{
			upd(root, 0, LIM-1, a, b);
		}
	}
	return 0;
}