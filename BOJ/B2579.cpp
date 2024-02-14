/*
#include <iostream>
#include <vector>

using namespace std;

// func
void B2579Input();
void B2579Solution();
void goDown();

// val
int N;
vector<int> stairs;
pair<int, int> memo[301];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	B2579Solution();
}

void B2579Input()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		stairs.emplace_back(tmp);
	}

	for (int i = 0; i < 301; i++) {
		memo[i] = make_pair(0, 0);
	}
}

void B2579Solution()
{
	B2579Input();
	goDown();
	// debug
	//for (int i = 0; i < N; i++)
		//cout << memo[i].first << ", " << memo[i].second << endl;

	cout << max(memo[0].first, memo[1].first);
}

void goDown()
{
	memo[N - 1].first = stairs[N - 1];
	for (int i = N - 1; i >= 0; i--) {
		if (i - 1 >= 0 && memo[i].second != 1) {
			if (memo[i - 1].first < memo[i].first + stairs[i - 1])
				memo[i - 1].second = 1;

			memo[i - 1].first = max(memo[i - 1].first, memo[i].first + stairs[i - 1]);
		}

		if (i - 2 >= 0) {
			if (memo[i - 2].first < memo[i].first + stairs[i - 2])
				memo[i - 2].second = 0;

			memo[i - 2].first = max(memo[i - 2].first, memo[i].first + stairs[i - 2]);
		}
	}
}
*/