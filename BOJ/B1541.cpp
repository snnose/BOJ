/*
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// ���ڿ��� �޾� �����ڿ� ���ڸ� �и���Ų��.
void split(string question, vector<string> &number, vector<char> &op)
{	
	int size = question.size();

	// ���� �����ڸ� ���� �и��ϰ� �� �ڸ��� ������ ä���.
	for (int i = 0; i < size; i++)
	{
		if (question[i] == '+' || question[i] == '-')
		{
			op.emplace_back(question[i]);
			question[i] = ' ';
		}
	}

	// ���� ������ �������� ���ڿ��� �и��Ѵ�. (���ڸ� ���� ����)
	istringstream ss(question);
	string stringbuffer;

	while (getline(ss, stringbuffer, ' '))
	{
		number.emplace_back(stringbuffer);
	}
}
// - ������ �ڿ� + �����ڰ� �ִٸ� -�� �ٲ� ��ȣ�� �����ִ� �� ó�� ���̰� �Ѵ�.
void changeOp(vector<char> &op)
{
	for (int i = 0; i < op.size(); i++)
	{
		if (op[i] == '-' && i < op.size() - 1)
		{
			for (int j = i + 1; j < op.size(); j++)
			{
				if (op[j] == '+')
					op[j] = '-';
				else if (op[j] == '+' || j == op.size() - 1)
				{
					i = j;
					break;
				}
			}
		}
	}
}
// ���� ����
int cal(vector<string> number, vector<char> op)
{
	int sum = stoi(number[0]);
	int size = op.size();

	for (int i = 0; i < size; i++)
	{
		if (op[i] == '+')
		{
			sum += stoi(number[i + 1]);
		}
		else
		{
			sum -= stoi(number[i + 1]);
		}
	}

	return sum;
}

int B1541Solution()
{
	string question;
	int answer = 0;

	vector<string> number;
	vector<char> op;

	cin >> question;

	split(question, number, op);

	/* �����
	for (int i = 0; i < number.size(); i++)
		cout << number[i] << ' ';
	cout << endl;
	for (int i = 0; i < op.size(); i++)
		cout << op[i] << ' ';
	cout << endl;
	

	changeOp(op);

	answer = cal(number, op);

	return answer;
}


int main()
{
	cout << B1541Solution();
	return 0;
}
*/