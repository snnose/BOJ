#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void B1263input(vector<pair<int, int>> &schedule)
{
	int N, T, S;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> T >> S;
		
		schedule.emplace_back(make_pair(T, S));
	}
}

// ���� �ð�(S) �������� ����
bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
}

int B1263solution(vector<pair<int, int>> schedule)
{
	sort(schedule.begin(), schedule.end(), compare);

	// first = �ҿ� �ð�(T), second = ���� �ð�(S)
	int start_Time = schedule[0].second - schedule[0].first; // ù �������� �ִ��� �ʰ� �����Ѵ�.
	int current_Time = start_Time;
	int size = schedule.size();

	// ������ ����
	for (int i = 0; i < size; i++)
	{
		// 0�ÿ� �����ص� �������� ������ ���Ѵٸ� -1 ���.
		if (start_Time < 0)
		{
			start_Time = -1;
			break;
		}

		current_Time += schedule[i].first;

		// ������ �ð� ���� �ذ����� ���ߴٸ�
		if (current_Time > schedule[i].second)
		{
			// ù ������ ���� �ð��� �� �ð� �մ�� �ٽ� �����Ѵ�.
			start_Time--;
			current_Time = start_Time;
			i = -1;
			continue;
		}
	}

	return start_Time;
}

/*
int main()
{
	vector<pair<int, int>> schedule;

	B1263input(schedule);
	
	cout << B1263solution(schedule);
}
*/