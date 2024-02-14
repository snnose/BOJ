/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// -> ������(X)���� �ٸ� ������ ���� �ִ� ��θ� ���� ��
//    �׷����� ���������� ������ �ٽ� ���������� �ٸ� ������ ���� �ִ� ��θ� ���Ѵ�.

vector<pair<int, int>> field[1001];
vector<pair<int, int>> rev[1001]; // ������ ������ ���� ���.
vector<int> answer;
int N, M, X;
void B1238Input(int& N, int& M, int& X)
{
	cin >> N >> M >> X;

	int v1, v2, dis;
	for (int i = 0; i < M; i++)
	{
		cin >> v1 >> v2 >> dis;
		field[v1].emplace_back(make_pair(v2, dis));
		rev[v2].emplace_back(make_pair(v1, dis));
	}
}

// ���ͽ�Ʈ�� �˰���
void diikstra(int start)
{
	int d[1001];
	int rev_d[1001];
	for (int i = 0; i < 1001; i++)
	{
		d[i] = 1e9;
		rev_d[i] = 1e9;
	}

	d[start] = 0;
	priority_queue<pair<int, int>> pq; // ���� ������ �Ÿ��� ���� ����� ������ ���� Ž���ϵ��� ����.
	priority_queue<pair<int, int>> rev_pq;
	pq.push(make_pair(start, 0));
	rev_pq.push(make_pair(start, 0));

	// ������ �׷��� ó��
	while (!pq.empty())
	{
		int curr_node = pq.top().first;
		int curr_dis = -pq.top().second;
		
		pq.pop();

		if (d[curr_node] < curr_dis)
			continue;
		
		int size = field[curr_node].size();
		for (int i = 0; i < size; i++)
		{
			int next = field[curr_node][i].first;
			int next_dis = curr_dis + field[curr_node][i].second;
			if (next_dis < d[next])
			{
				d[next] = next_dis;
				
				// pq�� ���������̹Ƿ� �Ÿ��� ����ȭ�Ͽ� ª�� �Ÿ��� ť�� �տ� ������ ����.
				pq.push(make_pair(next, -next_dis));
			}
		}
	}
	// ������ �׷��� ó��
	while (!rev_pq.empty())
	{
		int curr_rev_node = rev_pq.top().first;
		int curr_rev_dis = -rev_pq.top().second;

		rev_pq.pop();

		if (rev_d[curr_rev_node] < curr_rev_dis)
			continue;

		int size = rev[curr_rev_node].size();
		for (int i = 0; i < size; i++)
		{
			int next_rev = rev[curr_rev_node][i].first;
			int next_rev_dis = curr_rev_dis + rev[curr_rev_node][i].second;
			if (next_rev_dis < rev_d[next_rev])
			{
				rev_d[next_rev] = next_rev_dis;

				rev_pq.push(make_pair(next_rev, -next_rev_dis));
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (i != start)
		{
			answer.emplace_back(d[i] + rev_d[i]);
		}
	}
	return;
}

void B1238Solution()
{
	B1238Input(N, M, X);
	diikstra(X);
	cout << *max_element(answer.begin(), answer.end());;
}

int main()
{
	B1238Solution();
	return 0;
}
*/