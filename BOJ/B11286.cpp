/*
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

void B11286Input(int& N, vector<int>& func)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		func.emplace_back(tmp);
	}
}

void B11286Solution()
{
	int N;
	vector<int> func;
	vector<int> answer;
	priority_queue<int, vector<int>, less<int>> minus_pq;
	priority_queue<int, vector<int>, greater<int>> pq;

	B11286Input(N, func);

	for (int i = 0; i < N; i++)
	{
		// �Է� ���� ���� 0���� Ŭ �� (���)
		if (func[i] > 0)
		{
			pq.push(func[i]);
		}
		// �Է� ���� ���� 0�϶�
		else if (func[i] == 0)
		{
			// ���� �켱���� ť�� ��� �켱���� ť�� ������� ����� ó��
			if (minus_pq.empty() && pq.empty())
			{
				answer.emplace_back(0);
				continue;
			}
			else if (minus_pq.empty())
			{
				answer.emplace_back(pq.top());
				pq.pop();
				continue;
			}
			else if (pq.empty())
			{
				answer.emplace_back(minus_pq.top());
				minus_pq.pop();
				continue;
			}

			// ť ��� ������� �ʴٸ�
			if (abs(minus_pq.top()) <= pq.top())
			{
				answer.emplace_back(minus_pq.top());
				minus_pq.pop();
			}
			else
			{
				answer.emplace_back(pq.top());
				pq.pop();
			}
		}
		// �Է� ���� ���� 0���� ���� �� (����)
		else
		{
			minus_pq.push(func[i]);
		}
	}

	int size = answer.size();
	for (int i = 0; i < size; i++)
	{
		cout << answer[i] << endl;
	}
}

int main()
{
	B11286Solution();
	return 0;
}
*/