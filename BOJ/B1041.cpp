/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

// ������ü�� ũ��(N^3)�� �ֻ��� 6�� (A B C D E F)�� �Է��Ѵ�.
void B1041Input(int &N, vector<int> &dice)
{
	cin >> N;

	int tmp;
	for (int i = 0; i < 6; i++)
	{ 
		cin >> tmp;
		dice.emplace_back(tmp);
	}
}

void B1041Solution()
{
	int N;
	long long sum = 0;
	vector<int> dice;
	B1041Input(N, dice);

	// N�� 1�̶�� �ֻ����� �ϳ�. ==> 5���� ���δ�
	if (N == 1)
	{
		for (int i = 0; i < 6; i++)
			sum += (long long)dice[i];

		sum -= (long long)*max_element(dice.begin(), dice.end());
		cout << sum;
		return;
	}

	// �� ��(1��, 2��, 3��)�� �ּҰ��� ���Ѵ�.
	int oneMin = *min_element(dice.begin(), dice.end());
	int twoMin = 101, threeMin = 151;

	// 2�� �ּ� ���ϱ�
	for (int i = 0; i <= 5; i++)
	{
		int tmp = dice[i];
		switch (i)
		{
		// A(0)�� F(5)�� ������ ����.
		case 0:
		{
			for (int j = 1; j <= 4; j++)
			{
				twoMin = min(twoMin, tmp + dice[j]);
			}
			break;
		}
		// B(1)�� E(4)�� ������ ����
		case 1:
		{
			for (int j = 0; j <= 5; j++)
			{
				if (j == 1 || j == 4)
					continue;

				twoMin = min(twoMin, tmp + dice[j]);
			}
			break;
		}
		// C(2)�� D(3)�� ������ ����
		case 2:
		{
			for (int j = 0; j <= 5; j++)
			{
				if (j == 2 || j == 3)
					continue;

				twoMin = min(twoMin, tmp + dice[j]);
			}
			break;
		}
		// D�� C�� ������ ����
		case 3:
		{
			for (int j = 0; j <= 5; j++)
			{
				if (j == 2 || j == 3)
					continue;

				twoMin = min(twoMin, tmp + dice[j]);
			}
			break;
		}
		// E�� B�� ������ ����
		case 4:
		{
			for (int j = 0; j <= 5; j++)
			{
				if (j == 1 || j == 4)
					continue;

				twoMin = min(twoMin, tmp + dice[j]);
			}
			break;
		}
		// F�� A�� ������ ����
		case 5:
		{
			for (int j = 1; j <= 4; j++)
			{
				twoMin = min(twoMin, tmp + dice[j]);
			}
			break;
		}
		}
	}

	// 3�� �ּ� ���ϱ�
	// ������ ��, 1�ڷ� 3���� ����� ���� ���ܽ��Ѿ��Ѵ�.

	// BC, BD, CE, DE �� ���� ���� ����
	int twoSide[4] = {dice[1] + dice[2], dice[1] + dice[3], dice[4] + dice[2], dice[4] + dice[3]};
	// A, F
	int oneSide[2] = { dice[0], dice[5] };

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			threeMin = min(threeMin, oneSide[i] + twoSide[j]);
		}
	}

	// N�� ���� �� ���� ���� ���ϱ�
	long long oneSideCount = pow(N - 2, 2) * 5 + (N - 2) * 4;
	long long twoSideCount = (N - 1) * 4 + (N - 2) * 4;
	long long threeSideCount = 4;

	// �����
	//cout << "twoMin = " << twoMin << " threeMin = " << threeMin << endl;

	// �ּ��� ����
	sum = (long long)oneMin * oneSideCount + (long long)twoMin * twoSideCount
		+ (long long)threeMin * threeSideCount;

	cout << sum;
	return;
}

int main()
{
	B1041Solution();
	return 0;
}
*/