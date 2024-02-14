#include <iostream>

using namespace std;

char map[65][65];

/*
// ������������ 2���� �迭�� 4��� �ϸ鼭 ��� 0 Ȥ�� 1�� �����Ǿ��ִ��� Ȯ��
*/

void B1992Input(int &N)
{
	cin >> N;

	char tmp;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> tmp;
			map[i][j] = tmp;
		}
	}
}

void divide(int N, int x, int y, string &answer)
{
	bool all_Zero = true, all_One = true;

	for (int i = x; i < x + N; i++)
	{
		for (int j = y; j < y + N; j++)
		{
			if (map[i][j] == '0')
				all_One = false;

			else if (map[i][j] == '1')
				all_Zero = false;
		}
	}

	if (all_Zero == false && all_One == false)
	{
		answer += "(";
	}

	if (all_Zero)
	{
		answer += "0";
		return;
	}
	else if (all_One)
	{
		answer += "1";
		return;
	}

	divide(N / 2, x, y, answer);
	divide(N / 2, x, y + N / 2, answer);
	divide(N / 2, x + N / 2, y, answer);
	divide(N / 2, x + N / 2, y + N / 2, answer);

	answer += ")";
}

void B1992Solution()
{
	int N;
	string answer = "";
	B1992Input(N);

	divide(N, 0, 0, answer);

	int size = answer.size();
	for (int i = 0; i < size; i++)
		cout << answer[i];
}

/*
int main()
{
	B1992Solution();
	return 0;
}
*/