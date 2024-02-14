#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> things[101];
int answers[101][100001] = {0, };

void B12865Input(int &N, int &K, pair<int, int> things[])
{
	cin >> N >> K;
	int w, v;
	for (int i = 1; i <= N; i++)
	{
		cin >> w >> v;
		things[i] = make_pair(w, v);
	}
}

/* �ð� �ʰ�
// �賶�� �ִ��� �ִ´�. i = N - 1, K = �賶�� ���� �� �ִ� �ִ� ����
int put_in_bag(int i, int K, pair<int, int> things[])
{
	int value = 0;
	// ���� �ʰ� �� ���� ó��
	if (i < 0 || K <= 0)
		return 0;

	// ���� Ž������ ������ ���� �賶�� ���� �� �ִ� �ִ� ���Ժ��� ũ�ٸ�
	if (things[i].first > K)
	{
		// ���� ���濡 ����ִ� value�� ��ȯ�Ѵ�.
		value = put_in_bag(i - 1, K, things);
		return value;
	}
	else // bag[i].first <= K
	{
		// ���� Ž������ ������ ���� �ʰ� ���� ������ Ž���Ѵ�.
		int left = put_in_bag(i - 1, K, things);
		// ���� Ž������ ������ �ְ� ���� ������ Ž���Ѵ�.
		int right = put_in_bag(i - 1, K - things[i].first, things);

		// �� �� ��� �� value ���� ū ���� ��ȯ�Ѵ�.
		return max(left, right + things[i].second);
	}
}
*/
/*
// 1. ���� �ϳ��� ���� �賶�� �ִ´�.
// 1-1) �ֱ� ���� ���� 1 ~ K�� ������ �� �ִ� �賶�� �غ��Ѵ�.
// 1-2) �賶�� ������ ���� �� �ִٸ� �ְ� �� �賶�� ��ġ�� ����Ѵ�(answers �迭)
// 1-3) ���� �� ���ٸ� �� ������ �ֱ� ���� �賶�� ��ġ�� ����Ѵ�.
// 2. ������ ��ü�� �� ��ġ�� Ŭ ���
// 2-1) �ٷ� �� ������ ���� �賶���� (���� ��� 4��° ������ �ִ� ���̶�� 3��° ������ ���� �賶�� ã��)
// 2-2) ���� ������ ���� �賶�� ���� ���Կ� ������ ���Ը� �� �賶�� ã��
// 2-3) ã�� �賶(�賶�� ��ġ)�� ���� ������ ��ġ�� ���� ���� ���� ��
// 2-4) �ٷ� �� ������ ���� �賶�� ���Ѵ�.
*/
int put_in_bag(int N, int K, int answers[][100001], pair<int, int> things[])
{
	for (int i = 1; i <= N; i++)
	{
		for (int w = 1; w <= K; w++)
		{
			if (things[i].first <= w) // �ִ� ���Ը� 1�� �÷����� ����Ѵ�.
			{
				if ((things[i].second + answers[i - 1][w - things[i].first]) > answers[i - 1][w])
				{
					answers[i][w] = things[i].second + answers[i - 1][w - things[i].first];
				}
				else
					answers[i][w] = answers[i - 1][w];
			}
			else
				answers[i][w] = answers[i - 1][w];
		}
	}

	return answers[N][K];
}
void B12865Solution()
{
	int N, K, max_value = 0;
	// N, K, things �Է�
	B12865Input(N, K, things);
	
	max_value = put_in_bag(N, K, answers, things);

	cout << max_value;
}
/*
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	B12865Solution();
	return 0;
}
*/