/*
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// func
void B1463Input();
void B1463Solution();
void makeOne();

// val
int N;
int memo[1000001];

int main()
{
	B1463Solution();
}

void B1463Input()
{
	cin >> N;
	memset(memo, 1000000, sizeof(memo));
}

void B1463Solution()
{
	B1463Input();
	makeOne();
	cout << memo[1];
}

void makeOne()
{
	memo[N] = 0;
	for (int i = N; i > 1; i--) {
		memo[i - 1] = min(memo[i - 1], memo[i] + 1);

		if (i % 3 == 0) {
			memo[i / 3] = min(memo[i / 3], memo[i] + 1);
		}

		if (i % 2 == 0) {
			memo[i / 2] = min(memo[i / 2], memo[i] + 1);
		}
	}
}
*/