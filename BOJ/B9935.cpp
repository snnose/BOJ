/*
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

void B9935Input(string &str1, string &str2)
{
	cin >> str1 >> str2;
}

void explosion(string str, string bomb)
{
	vector<char> answer;
	int len = str.length();
	int bombLen = bomb.length();

	// ���ڿ� ������ �ݺ�
	for (int i = 0; i < len; i++)
	{
		answer.emplace_back(str[i]);

		// ���ڿ��� ���� ���ڿ� ũ�⺸�� Ŀ����
		if (answer.size() >= bombLen)
		{
			bool isExplode = true;
			// ���� ���ڿ��� �ִ��� �˻��Ѵ�.
			for (int j = 0; j < bombLen; j++)
			{
				if (answer[answer.size() - bombLen + j] != bomb[j])
				{
					isExplode = false;
					break;
				}
			}
			// ���� ���ڿ��� �ִٸ� ����
			if (isExplode)
			{
				for (int j = 0; j < bombLen; j++)
					answer.pop_back();
			}
		}
	}

	if (answer.empty())
		cout << "FRULA";
	else
	{
		for (int i = 0; i < answer.size(); i++)
			cout << answer[i];
	}
}

void B9935Solution()
{
	string str, bomb;
	B9935Input(str, bomb);
	explosion(str, bomb);
}

int main()
{
	B9935Solution();
	return 0;
}
*/