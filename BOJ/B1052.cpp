#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void input(int &N, int &K)
{
	cin >> N >> K;
}

int solution1052(int N, int K)
{
	vector<int> bottle; // ������ ���� ����.

	int tmp = N;
	int count = 0;		// �ݺ� Ƚ��
	int buy_Count = 0;	// ���� ���� ��

	// N���� ������ 2���� ���� ��ü ���� ���δ�. (2�� �����鼭 ����)
	while (tmp != 1)
	{
		// ������ Ȧ�� ������ŭ �ִٸ�
		if (tmp % 2 == 1)
		{
			// ���� �ϳ��� ���� �� ������ �����Ѵ�. (�� ������ ���͸� ����)
			bottle.emplace_back(pow(2, count)); 
			tmp--;
		}

		tmp = tmp / 2;
		count++;
	}

	// �� ������ ��ġ�� ������� ������ �����Ѵ�.
	bottle.emplace_back(pow(2, count));

	int size = bottle.size();

	int buy = 0;	// �� �ݺ����� �� ���� ����

	// ��� �� ���� ������ �� �� ���� �ݺ�
	while (K < size)
	{
		// ������ �����ϰ� �� ���� ���� ���� ���Ѵ�.
		buy += (bottle[1] - bottle[0]);
		buy_Count += buy;

		// ������ ��ģ��.
		tmp = buy + bottle[0] + bottle[1];

		// ���� �ε��� ó�� �� ��ģ ������ �迭�� ���� �տ� �д�.
		bottle.erase(bottle.begin());
		bottle[0] = tmp;
		
		// ���� �ʱ�ȭ
        buy = 0;
		size = bottle.size();
	}

	return buy_Count;
}

/*
int main()
{
	int N, K;
	input(N, K);

	cout << solution1052(N, K);
}
*/