/*
#include <iostream>
#include <vector>

using namespace std;

// 열린 괄호 이후 연산자 2개 이상인 경우 처리해야함.
//

// 중위 표기식 입력.
void B1918Input(string &notation)
{
	cin >> notation;
}

// 문자(매개변수)가 연산자인지 아닌지 판단한다.
bool isOp(char a)
{
	if (a == '+' || a == '-' || a == '*' || a == '/' || a == '(' || a == ')')
		return true;
	else
		return false;
}

// 중위 표기식을 후위 표기식으로 변환한다.
void translateNotation(string notation)
{
	vector<char> st;
	string rearNotation = "";
	int openBracketCount = 0;

	for (int i = 0; i < notation.size(); i++)
	{
		// 숫자라면
		if (!isOp(notation[i]))
			// 표기식에 추가한다
			rearNotation += notation[i];
		// 연산자라면
		else
		{
			// '(', ')' 연산자는 그냥 넣는다.
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
					// 열린 괄호라면 ptr 증가
					if (st[i] == '(')
						ptr++;

					// ptr이 열린 괄호 수 만큼 있다면 => 가장 안쪽 괄호라면
					if (ptr == openBracketCount)
					{
						// 열린 괄호를 pop 한다.
						st.erase(st.begin() + i);

						// 현재 연산자를 기억한다.
						char currentOp = st[i];
						int j = i + 1;
						// 닫힌 괄호를 찾기 전까지 후위 표기식에 추가
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
			// '(' 연산자 이후의 연산자라면 그냥 넣는다.
			if (openBracketCount > 0)
			{
				st.emplace_back(notation[i]);
				continue;
			}

			// 스택이 비어있으면 스택에 넣는다.
			if (st.empty())
			{
				st.emplace_back(notation[i]);
				continue;
			}
			// 스택이 비어있지 않다면
			else
			{
				int size = st.size();
				char top = st[size - 1];

				// 스택 꼭대기가 '+', '-' 연산자일 때
				if (top == '+' || top == '-')
					st.emplace_back(notation[i]);
				// 스택 꼭대기가 '*', '/' 연산자일 때
				else
				{
					// 현재 연산자가 '*', '/' 라면 스택에 넣는다.
					if (notation[i] == '*' || notation[i] == '/')
						st.emplace_back(notation[i]);
					// 현재 연산자가 '+', '-' 라면 스택에서 뽑아 후위연산자에 추가하고 현재 연산자를 넣는다.
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