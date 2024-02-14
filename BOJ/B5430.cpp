/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;

void B5430Input(int &size, string &fuc, string &arr)
{
	cin >> fuc >> size >> arr;
}
// ���ڿ��� ','�� �������� �и��Ѵ�.
void split(string arr, int answer[])
{
	int index = 0;
	string s = arr;
	s.erase(s.end() - 1);
	s.erase(s.begin());
	
	istringstream ss(s);
	string stringBuffer;

	while (getline(ss, stringBuffer, ','))
	{
		answer[index] = stoi(stringBuffer);
		index++;
	}
}

// 1. ���ڿ��� �и��Ѵ�.
// 2. �Է¹��� �Լ��� �´� ó���� �Ѵ�.
// 2-1) �迭�� ������ �� ������ �������� ���� �ڿ��� ����.
// 2-2) ���� �迭�� �������� �ִ��� �� �� �ִ� bool ������ �����ϵ��� �Ѵ�.
// 2-3) �迭�� �������� �ִٸ� �迭�� �� �ڸ�, �׷��� �ʴٸ� �迭�� �� ���� �����ϵ��� �Ѵ�.
// 3. �� ������ ������ ���� ���� ���� ���Ϳ� ���� �� �׽�Ʈ���̽��� ������ �Ѳ����� ����Ѵ�.

void B5430Solution()
{
	int T;
	cin >> T;

	int tmp[100000];
	vector<string> answers;
	string fuc = "", arr = "", answer = "";
	int size = 0;
	bool isReverse = false;

	for (int i = 0; i < T; i++)
	{	
		memset(tmp, 100000, sizeof(int));
		B5430Input(size, fuc, arr);
		split(arr, tmp);
		
		int beginPtr = 0, endPtr = size - 1; // �Լ� D ���� �� �迭�� ���� ��ġ�� ����Ű�� ������.
		int fuc_count = fuc.size();
		// �Է¹��� �Լ� ����ŭ �ݺ�
		for (int j = 0; j < fuc_count; j++)
		{
			// �迭�� 0�� �Ǹ� Ż��
			if (size < 0)
				break;

			// �Լ� R ����
			if (fuc[j] == 'R')
			{
				// �迭�� �������ش�.
				if (isReverse)
					isReverse = false;
				else
					isReverse = true;
			}
			// �Լ� D ����
			else if (fuc[j] == 'D')
			{
				// �迭�� ������ ���ο� ���� �� ��, �� �ڸ� �����Ѵ�.
				if (isReverse)
				{
					tmp[endPtr] = -1;
					endPtr--;
					size--;
				}
				else
				{
					tmp[beginPtr] = -1;
					beginPtr++;
					size--;
				}
			}
		}

		if (size < 0)
		{
			answer += 'e';
			answer += 'r';
			answer += 'r';
			answer += 'o';
			answer += 'r';
		}
		else if (size == 0)
		{
			answer += '[';
			answer += ']';
		}
		else
		{
			answer += '[';
			
			if (isReverse)
			{
				for (int j = endPtr; j > beginPtr; j--)
				{
					answer += to_string(tmp[j]);
					answer += ',';
				}
				answer += to_string(tmp[beginPtr]);
			}
			else
			{
				for (int j = beginPtr; j < endPtr; j++)
				{
					answer += to_string(tmp[j]);
					answer += ',';
				}
				answer += to_string(tmp[endPtr]);
			}
			answer += ']';
		}
		answers.emplace_back(answer);

		// �ʱ�ȭ
		answer.clear();
		isReverse = false;
	}

	for (int i = 0; i < answers.size() - 1; i++)
	{
		cout << answers[i] << endl;
	}
	cout << answers[answers.size() - 1];
}


int main()
{
	B5430Solution();
	return 0;
}
*/