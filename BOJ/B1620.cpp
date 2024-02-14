/*
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// func
void B1620Input();
void B1620Solution();
void makeMap();
void answer();

// val
vector<string> pocketmons;
vector<string> answers;
map<int, string> nTop;
map<string, int> pTon;
int N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	B1620Solution();
}

void B1620Input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		pocketmons.emplace_back(tmp);
	}

	for (int i = 0; i < M; i++) {
		string tmp2;
		cin >> tmp2;
		answers.emplace_back(tmp2);
	}
}

void B1620Solution()
{
	B1620Input();
	makeMap();
	answer();
}

void makeMap()
{
	for (int i = 0; i < N; i++) {
		string name = pocketmons[i];
		nTop.insert({ i + 1, name });
		pTon.insert({ name, i + 1});
	}
}

void answer()
{
	for (int i = 0; i < M; i++) {
		try {
			int tmp = stoi(answers[i]);
			cout << nTop[tmp] << '\n';
		}
		catch (invalid_argument const &e) {
			cout << pTon[answers[i]] << '\n';
		}
	}
}
*/