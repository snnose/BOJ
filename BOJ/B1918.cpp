/*
#include <iostream>
#include <vector>

using namespace std;

// ���� ��ȣ ���� ������ 2�� �̻��� ��� ó���ؾ���.
//

// ���� ǥ��� �Է�.
void B1918Input(string &notation)
{
	cin >> notation;
}

// ����(�Ű�����)�� ���������� �ƴ��� �Ǵ��Ѵ�.
bool isOp(char a)
{
	if (a == '+' || a == '-' || a == '*' || a == '/' || a == '(' || a == ')')
		return true;
	else
		return false;
}

// ���� ǥ����� ���� ǥ������� ��ȯ�Ѵ�.
void translateNotation(string notation)
{
	vector<char> st;
	string rearNotation = "";
	int openBracketCount = 0;

	for (int i = 0; i < notation.size(); i++)
	{
		// ���ڶ��
		if (!isOp(notation[i]))
			// ǥ��Ŀ� �߰��Ѵ�
			rearNotation += notation[i];
		// �����ڶ��
		else
		{
			// '(', ')' �����ڴ� �׳� �ִ´�.
			if (notation[i] == '(')
			{
				st.emplace_back(notation[i]);
				openBracketCount++;
				continue;
			}
			else if (notation[i] == ')')
			{
				st.emplace_back(notation[i]);

				int ptr = 0;
				for (int i = 0; i < st.size(); i++)
				{
					// ���� ��ȣ��� ptr ����
					if (st[i] == '(')
						ptr++;

					// ptr�� ���� ��ȣ �� ��ŭ �ִٸ� => ���� ���� ��ȣ���
					if (ptr == openBracketCount)
					{
						// ���� ��ȣ�� pop �Ѵ�.
						st.erase(st.begin() + i);

						// ���� �����ڸ� ����Ѵ�.
						char currentOp = st[i];
						int j = i + 1;
						// ���� ��ȣ�� ã�� ������ ���� ǥ��Ŀ� �߰�
						while (st[j] != ')')
						{
							if (currentOp == '+' || currentOp == '-')
							{
								rearNotation += currentOp;
								currentOp = st[j];
							}
							else
							{
								
							}
							j++;
						}
					}
				}
				openBracketCount--;
				continue;
			}
			// '(' ������ ������ �����ڶ�� �׳� �ִ´�.
			if (openBracketCount > 0)
			{
				st.emplace_back(notation[i]);
				continue;
			}

			// ������ ��������� ���ÿ� �ִ´�.
			if (st.empty())
			{
				st.emplace_back(notation[i]);
				continue;
			}
			// ������ ������� �ʴٸ�
			else
			{
				int size = st.size();
				char top = st[size - 1];

				// ���� ����Ⱑ '+', '-' �������� ��
				if (top == '+' || top == '-')
					st.emplace_back(notation[i]);
				// ���� ����Ⱑ '*', '/' �������� ��
				else
				{
					// ���� �����ڰ� '*', '/' ��� ���ÿ� �ִ´�.
					if (notation[i] == '*' || notation[i] == '/')
						st.emplace_back(notation[i]);
					// ���� �����ڰ� '+', '-' ��� ���ÿ��� �̾� ���������ڿ� �߰��ϰ� ���� �����ڸ� �ִ´�.
					else
					{
						rearNotation += top;
						st[size - 1] = notation[i];
					}
				}
				continue;
			}
		}
	}
}

void B1918Solution()
{
	string notation = "";
	B1918Input(notation);
}

int main()
{
	return 0;
}
*/