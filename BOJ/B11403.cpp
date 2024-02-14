#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

// func
void B11403Input();
void B11403Solution();
void bfs(int start);

// val
vector<int> edge[100];
vector<int> answers[100];
bool visited[100] = {false, };

int main()
{
	B11403Solution();
}

void B11403Input()
{
	int N;
	vector<int> tmpV;

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;

			tmpV.emplace_back(tmp);
		}
		edge[i] = tmpV;
		tmpV.clear();
	}
}

void B11403Solution()
{
	B11403Input();

	int size = edge[0].size();

	for (int i = 0; i < size; i++) {
		bfs(i);
		memset(visited, false, sizeof(bool) * 100);
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << answers[i][j] << ' ';
		}
		cout << endl;
	}
}

void bfs(int start)
{
	queue<int> que;
	vector<int> graph;
	int size = edge[0].size();

	for (int i = 0; i < size; i++)
		graph.emplace_back(0);

	que.push(start);
	
	while (!que.empty()) {
		int curr = que.front();
		que.pop();

		for (int i = 0; i < size; i++) {
			int next = edge[curr][i];

			if (!visited[i] && next == 1) {
				que.push(i);
				visited[i] = true;
				graph[i] = 1;
			}
		}
	}

	answers[start] = graph;
}