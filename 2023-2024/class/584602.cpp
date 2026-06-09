#include <bits/stdc++.h>
#define ll long long
using namespace std;

inline void readUI(ll *n) //tylko dodatnie
{
    register char c = 0;
    while (c < 33) c=getc_unlocked(stdin);
    (*n) = 0;
    while (c>32) {(*n)=(*n)*10LL + (c-48); c=getc_unlocked(stdin);}
}

struct Description {
	ll beg, end, k;
	ll answer;
	ll index;
};

ll sgn(ll value) {
	if(value < 0)
		return -1;
	return 1;
}

#define MAXN int(2e5 + 100)

pair <ll, ll> input[MAXN];
ll scaled[MAXN];
ll count_[MAXN];
ll answer[MAXN];
Description questions[MAXN];
ll n;
ll m;
ll _n;

ll level(ll value) {
	if((n - 1 - _n / 2) / _n != (n - 1) / _n && value / _n == (n - 1) / _n)
		return value / _n - 1;
	return value / _n;
}

bool condition1(const Description & a, const Description & b) {
	if(level(a.beg) == level(b.beg)) {
		if(level(a.beg) % 2)
			return a.end > b.end;
		return a.end < b.end;
	}
	return level(a.beg) < level(b.beg);

	
}

bool condition2(const Description & a, const Description & b) {
	return a.index < b.index;
}

ll end_, beg_;
void init() {
	_n = sqrt(n);
	end_ = 0, beg_ = -1;
	sort(input, input + n);
	scaled[input[0].second] = 0;
	ll value = 0;
	for(ll i = 1; i < n; ++i) {
		if(input[i - 1].first < input[i].first)
			++value;
		scaled[input[i].second] = value;
	}

	sort(questions, questions + m, condition1);
}

void set_beg(ll value) {
	for(ll i = 0; i < abs(value); ++i) {
		if(value < 0) {
			--answer[count_[scaled[beg_]]];
			--count_[scaled[beg_]];
			++answer[count_[scaled[beg_]]];
		}
		else {
			--answer[count_[scaled[beg_ + 1]]];
			++count_[scaled[beg_ + 1]];
			++answer[count_[scaled[beg_ + 1]]];
		}
		beg_ += sgn(value);
	}
}

void set_end(ll value) {
	for(ll i = 0; i < abs(value); ++i) {
		if(value < 0) {
			--answer[count_[scaled[end_ - 1]]];
			++count_[scaled[end_ - 1]];
			++answer[count_[scaled[end_ - 1]]];
		}
		else {
			--answer[count_[scaled[end_]]];
			--count_[scaled[end_]];
			++answer[count_[scaled[end_]]];
		}
		end_ += sgn(value);
	}
}

void gasiennica() {
	ll index = 0;
	ll direction = 1;
	while(beg_ + _n < n) {
		if(beg_ == -1 && _n >= 2)
			set_beg(_n / 2);
		else
			set_beg(_n);
		bool stop = true;
		for(ll i = 0; i < n; ++i) {
			if(!stop)
				set_end(direction);
			stop = false;

			while(index < m && questions[index].end == end_ && level(questions[index].beg) == level(beg_)) {
				ll help = questions[index].beg - beg_;
				set_beg(help);
				questions[index].answer = answer[questions[index].k];
				set_beg(-help);
				++index;
			}
		}
		direction *= -1;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	readUI(&n);
	for(ll i = 0; i < n; ++i) {
		readUI(&input[i].first);
		input[i].second = i;
	}
	readUI(&m);
	for(ll i = 0; i < m; ++i) {
		readUI(&questions[i].end);
		readUI(&questions[i].beg);
		readUI(&questions[i].k);
		--questions[i].end;
		--questions[i].beg;
		questions[i].index = i;
	}

	init();
	gasiennica();
	sort(questions, questions + m, condition2);

	for(ll i = 0; i < m; ++i)
		printf("%i\n", questions[i].answer);

	return 0;
}