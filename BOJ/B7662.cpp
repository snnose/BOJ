/*
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>

using namespace std;

// ���ڿ��� �Է¹ް� �и����� func�� num�� ��ȯ.
void B7662Input(vector<char> &func, vector<long long> &num)
{
	int N;
	cin >> N;

	char a;
	long long b;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;

		func.emplace_back(a);
		num.emplace_back(b);
	}
}

void B7662Solution()
{
	priority_queue<long long, vector<long long>, less<long long>> pq_max; // �������� �켱���� ť
	priority_queue<long long, vector<long long>, greater<long long>> pq_min;  // �������� �켱���� ť
	vector<char> func;
	vector<long long> num;
	vector<string> answer;
	map<long long, int> remain_num; // ������ �����ִ� ���� ��� ���� �迭.
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		func.clear();
		num.clear();
		B7662Input(func, num);

		// �ʱ�ȭ
		while (!pq_min.empty())
			pq_min.pop();
		while (!pq_max.empty())
			pq_max.pop();
		remain_num.clear();
		
		
		int size = func.size();
		for (int j = 0; j < size; j++)
		{
			// Insert
			if (func[j] == 'I')
			{
				pq_max.push(num[j]);
				pq_min.push(num[j]);
				remain_num[num[j]]++;
			}
			// Delete
			else
			{
				// Delete minimum
				if (num[j] == -1)
				{
					while (!pq_min.empty() && remain_num[pq_min.top()] == 0)
						pq_min.pop();

					if (!pq_min.empty())
					{
						remain_num[pq_min.top()]--;
						pq_min.pop();
					}
				}
				// Delete maximum
				else 
				{
					while (!pq_max.empty() && remain_num[pq_max.top()] == 0)
						pq_max.pop();

					if (!pq_max.empty())
					{
						remain_num[pq_max.top()]--;
						pq_max.pop();
					}
				}
			}
		}

		while (!pq_min.empty() && remain_num[pq_min.top()] == 0)
			pq_min.pop();

		while (!pq_max.empty() && remain_num[pq_max.top()] == 0)
			pq_max.pop();

		if (pq_min.empty() || pq_max.empty())
		{
			answer.emplace_back("EMPTY");
		}
		else
		{
			answer.emplace_back(to_string(pq_max.top()) + " " + to_string(pq_min.top()));
		}
	}

	int answer_size = answer.size();
	for (int j = 0; j < answer_size; j++)
	{
		cout << answer[j] << endl;
	}
}


int main()
{
	B7662Solution();
	return 0;
}
*/