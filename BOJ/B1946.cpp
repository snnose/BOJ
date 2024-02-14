#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void B1946Input(vector<pair<int, int>> &workers)
{
	int N;

	cin >> N;

	int document_Grade, interview_Grade;
	for (int i = 0; i < N; i++)
	{
		cin >> document_Grade >> interview_Grade;
		workers.emplace_back(make_pair(document_Grade, interview_Grade));
	}
}
// ���� ������ �������� �������� ����
bool compareDocument(pair<int, int> &a, pair<int, int> &b)
{
	return a.first < b.first;
}
// ���� ������ �������� �������� ����
bool compareInterview(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
}

void B1946Solution()
{
	vector<pair<int, int>> workers;
	vector<int> answers;
	int T, hireCount, size, maxInterview;
	
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		hireCount = 1; // ���� ���� 1���� ������ ä��ǹǷ� 1���� ����.

		B1946Input(workers);

		// ���� ������ �������� �������� ����
		sort(workers.begin(), workers.end(), compareDocument);

		maxInterview = workers[0].second;
		size = workers.size();

		for (int j = 1; j < size; j++)
		{
			// Ÿ �������� �ְ� ���� �������� ���ٸ� Ż��
			if (workers[j].second > maxInterview) 
			{}
			// Ÿ �������� �ְ� ���� �������� ���ٸ� ä��
			else
			{
				maxInterview = workers[j].second;
				hireCount++;
			}
		}
	

		// �׽�Ʈ ���̽� ���� �� �ʱ�ȭ
		workers.clear();

		answers.emplace_back(hireCount);
	}

	for (int i = 0; i < answers.size(); i++)
	{
		cout << answers[i] << endl;
	}
}
/*
int main()
{
	B1946Solution();
}
*/