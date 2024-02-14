#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

vector<bool> B1107Input(int& N, int& M)
{
	vector<bool> button = {false, false, false, false, false, false, false, false, false, false};
	
	cin >> N >> M;

	int tmp;
	for (int i = 0; i < M; i++)
	{
		cin >> tmp;
		button[tmp] = true;
	}

	return button;
}

// ä���� �Է��� �� �ִ��� �˻��Ѵ�.
bool isCanInput(int current, vector<bool> Button)
{
	string channel = to_string(current);

	int digits = channel.size();

	for (int i = 0; i < digits; i++)
	{
		if (Button[channel[i] - '0'])
			return false;
	}

	return true;
}

int B1107Solution()
{
	int N, M;
	vector<bool> Button = B1107Input(N, M);

	int currentChannel = 100;
	int min = abs(N - currentChannel);

	for (int i = 0; i <= 1000000; i++)
	{
		if (isCanInput(i, Button))
		{
			if (abs(N - i) + to_string(i).size() < min)
				min = abs(N - i) + to_string(i).length();
		}
	}

	return min;
}

/*
int main()
{
	cout << B1107Solution();
}
*/