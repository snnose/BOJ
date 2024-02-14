/*
#include <iostream>
#include <vector>

using namespace std;

long long modular = 1000000007;
vector<pair<int, int>> dices;

long long fpow(long long C, long long n);
int getGcd(int a, int b);

void B13172_Input() 
{
	int M, a, b;

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> b >> a;
		dices.emplace_back(make_pair(b, a));
	}
}

long long B13172_Solution() 
{
	int len = dices.size();
	long long a = 0, b = 0;
	long long answer = 0;

	for (int i = 0; i < len; i++) {
		a = dices[i].second; 
		b = dices[i].first;

		int gcd = getGcd(a, b);

		a /= gcd;
		b /= gcd;
		
		answer += (a * fpow(b, modular - 2)) % modular; // (a * b^modular-1)Mod modular

		answer %= modular;
	}

	cout << answer;
	return answer;
}

int main() 
{
	B13172_Input();
	long long answer = B13172_Solution();
}

long long fpow(long long C, long long n)
{
	if (n == 1)
		return C;

	long long tmp = fpow(C, n / 2);
	if (n % 2 == 1)
		return (((tmp * tmp) % modular) * C) % modular;
	else
		return (tmp * tmp) % modular;
}

int getGcd(int a, int b)
{
	return b ? getGcd(b, a % b) : a;
}
*/