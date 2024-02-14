/*
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void B2138Input(string &currentState, string &endState)
{
	int N;
	string tmp;
	cin >> N;

	cin >> tmp;
	currentState = tmp;

	cin >> tmp;
	endState = tmp;
}
// 0�̸� 1��, 1�̸� 0���� ��ȯ�Ѵ�.
void switching (char &num)
{
	if (num == '0')
		num = '1';
	else
		num = '0';
}
// ���� ���¿� �ε����� �޾� �ε����� ��ġ�� ���� �ٸ� ������� ��ȯ�Ѵ�.
void change(string& currentState, int i)
{
	int size = currentState.size();

	if (i == 0)
	{
		switching(currentState[i]);
		switching(currentState[i + 1]);
	}
	else if (i == size - 1)
	{
		switching(currentState[i - 1]);
		switching(currentState[i]);
	}
	else
	{
		switching(currentState[i - 1]);
		switching(currentState[i]);
		switching(currentState[i + 1]);
	}
}

int B2138Solution()
{
	string currentState, endState, firstState;
	int changeCount1 = 0, changeCount2 = 0, minCount;

	B2138Input(currentState, endState);
	
	firstState = currentState;

	int size = currentState.size();
	// 0�� ����ġ�� ������ ���
	change(currentState, 0);
	changeCount1++;

	for (int i = 1; i < size; i++)
	{
		// ���� ����ġ�� ���°� ���� ����ġ ���¶� ���� �ʴٸ�
		if (currentState[i - 1] != endState[i - 1])
		{
			// ������
			change(currentState, i);
			changeCount1++;
		}
	}

	// �� ������ ��ģ ����ġ�� ���� ���¶� ���� �ʴٸ�
	if (currentState != endState)
		changeCount1 = -1;

	// �ʱ�ȭ
	currentState = firstState;

	// 0�� ����ġ�� ������ �ʴ� ���
	for (int i = 1; i < size; i++)
	{
		if (currentState[i - 1] != endState[i - 1])
		{
			change(currentState, i);
			changeCount2++;
		}
	}

	if (currentState != endState)
		changeCount2 = -1;

	// ����ġ ���� Ƚ�� ����
	if (changeCount1 == -1 && changeCount2 == -1)
		return -1;
	else if (changeCount1 == -1)
		return changeCount2;
	else if (changeCount2 == -1)
		return changeCount1;
	else if (changeCount1 <= changeCount2)
		return changeCount1;
	else if (changeCount2 < changeCount1)
		return changeCount2;
}


int main()
{
	cout << B2138Solution();
}
*/