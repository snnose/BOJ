/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

// 정육면체의 크기(N^3)와 주사위 6면 (A B C D E F)를 입력한다.
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

	// N이 1이라면 주사위가 하나. ==> 5면이 보인다
	if (N == 1)
	{
		for (int i = 0; i < 6; i++)
			sum += (long long)dice[i];

		sum -= (long long)*max_element(dice.begin(), dice.end());
		cout << sum;
		return;
	}

	// 각 면(1면, 2면, 3면)의 최소값을 구한다.
	int oneMin = *min_element(dice.begin(), dice.end());
	int twoMin = 101, threeMin = 151;

	// 2면 최소 구하기
	for (int i = 0; i <= 5; i++)
	{
		int tmp = dice[i];
		switch (i)
		{
		// A(0)는 F(5)와 접하지 않음.
		case 0:
		{
			for (int j = 1; j <= 4; j++)
			{
				twoMin = min(twoMin, tmp + dice[j]);
			}
			break;
		}
		// B(1)는 E(4)와 접하지 않음
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
		// C(2)는 D(3)와 접하지 않음
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
		// D와 C는 접하지 않음
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
		// E와 B는 접하지 않음
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
		// F와 A는 접하지 않음
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

	// 3면 최소 구하기
	// 펼쳤을 때, 1자로 3개가 연결된 것은 제외시켜야한다.

	// BC, BD, CE, DE 두 면을 더한 값들
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

	// N에 따른 각 면의 갯수 구하기
	long long oneSideCount = pow(N - 2, 2) * 5 + (N - 2) * 4;
	long long twoSideCount = (N - 1) * 4 + (N - 2) * 4;
	long long threeSideCount = 4;

	// 디버깅
	//cout << "twoMin = " << twoMin << " threeMin = " << threeMin << endl;

	// 최소합 도출
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