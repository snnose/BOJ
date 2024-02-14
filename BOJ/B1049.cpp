#include <iostream>
#include <vector>

using namespace std;

void input(int &N, int &M, vector<pair<int, int>> &brands)
{
	int first, second;

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> first >> second;

		brands.emplace_back(make_pair(first, second));
	}
}

// O(n^2) �� ���� �� ���� �� ����. �Ƹ���?
int solution(int N, int M, vector<pair<int, int>> brands)
{
	int min_price = 1000000;

	int quotient = 0, remain = 0;

	quotient = N / 6;
	remain = N % 6;

	int tmp = 0;

	// ��Ű���� ���� ������ �� �������� ���� Ȥ�� ��Ű���� �����Ѵ�.
	for (int i = 0; i < M; i++)
	{
		// ��Ű���� ������ ���� ��δٸ� ���� ����
		if (brands[i].first / 6 >= brands[i].second)
			tmp += brands[i].second * 6 * quotient;
		else
			tmp += brands[i].first * quotient;

		// ��Ű�� ���� �� ����
		int check = tmp;

		for (int j = 0; j < M; j++)
		{
			// ������ ��� ������ ��Ű�� ���ݺ��� ��δٸ� ��Ű�� ����
			if (brands[i].first < brands[j].second * remain)
				tmp += brands[i].first;
			else
				tmp += brands[j].second * remain;

			if (tmp < min_price)
				min_price = tmp;
			
			// ���� �귣�� ���� ���ϱ� ���� �ʱ�ȭ
			tmp = check;
		}

		tmp = 0;
	}

	return min_price;
}
/*
int main()
{
	int N, M; // N = ������ ��Ÿ�� ����, M = ��Ÿ�� �귣�� ��
	vector<pair<int, int>> brands; // first = ��Ű��(6��) ����, second = 1�� ����

	input(N, M, brands);

	cout << solution(N, M, brands);
}
*/