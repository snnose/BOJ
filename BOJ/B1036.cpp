/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 자릿수가 작은데 Z로 바꾸면 더 커지는 경우를 고려해야함.

void B1036Input(int &N, int &K, vector<string> &decimal)
{
	cin >> N;
	
	string tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		decimal.emplace_back(tmp);
	}

	cin >> K;
}

// 36진법 문자열들을 K의 개수만큼 최대값이 되도록 Z로 바꾼다
void changeZ(int N, int K, vector<string> &decimal)
{
	// 각 36진법 문자열의 길이
	vector<int> decimalSize;
	for (int i = 0; i < N; i++)
	{
		decimalSize.emplace_back(decimal[i].size());
	}

	int maxCount = 0, currentK = K;
	while (currentK > 0)
	{
		// 가장 긴 길이를 찾는다.
		int maxSize = *max_element(decimalSize.begin(), decimalSize.end());
		// 디버깅
		cout << "maxSize : " << maxSize << " currentK : " << currentK << endl;

		// 더 이상 바꿀 문자가 없다면 탈출
		if (maxSize <= 0)
			break;

		// 가장 긴 문자열의 갯수를 샌다.
		for (int i = 0; i < N; i++)
		{
			if (decimalSize[i] == maxSize)
				maxCount++;
		}

		// 가장 긴 문자열 갯수가 현재 K의 개수보다 작거나 같다면
		if (maxCount <= currentK)
		{
			char a = NULL;
			// 가장 앞 문자를 'Z'로 바꿔준다.
			for (int i = 0; i < N; i++)
			{
				if (decimalSize[i] == maxSize)
				{
					// 가장 앞 문자가 'Z'가 아니라면
					if (decimal[i][decimal[i].size() - decimalSize[i]] != 'Z')
					{
						// 바뀔 문자를 기억한다.
						a = decimal[i][decimal[i].size() - decimalSize[i]];
						decimal[i][decimal[i].size() - decimalSize[i]] = 'Z';
					}
					// 'Z'라면
					else
						maxCount--; // 바꾸지 않는다
						
					decimalSize[i]--;
				}

				// 문자를 바꿨다면
				if (a != NULL)
				{
					// 모든 문자의 바뀐 특정 문자를 'Z'로 바꾼다.
					for (int j = 0; j < N; j++)
					{
						int size = decimal[j].size();
						for (int k = 0; k < size; k++)
						{
							if (decimal[j][k] == a)
								decimal[j][k] = 'Z';
						}
					}

					a = NULL;
				}
			}

			currentK -= maxCount;
		}
		// 아니라면
		else
		{
			// 현재 자릿수 중 가장 작은 문자를 Z로 바꿔야한다.
			char minChar = 'Z';
			char a = NULL;
			
			// 현재 가장 긴 문자열의 가장 앞(Z가 아닌)의 최소 문자를 찾는다.
			for (int i = 0; i < N; i++)
			{
				if (decimalSize[i] == maxSize)
				{
					minChar = min(minChar, decimal[i][decimal[i].size() - decimalSize[i]]);
				}
			}

			// 만약 최소 문자가 Z가 나오면 인덱스 조정 후 재반복한다.
			if (minChar == 'Z')
			{
				for (int i = 0; i < N; i++)
				{
					if (decimalSize[i] == maxSize)
						decimalSize[i]--;
				}

				continue;
			}

			// 모든 36진법 문자에서 최소 문자와 같은 문자를 Z로 바꾼다.
			for (int i = 0; i < N; i++)
			{
				int size = decimal[i].size();
				for (int j = 0; j < size; j++)
				{
					if (decimal[i][j] == minChar)
						decimal[i][j] = 'Z';
				}
			}

			currentK--;
		}

		maxCount = 0;
	}
}

// 36진수 두 수를 받아 더한 값을 반환한다.
int convert(char a, char b)
{
	char tmp1, tmp2;
	// 0 ~ 9 => 48 ~ 57
	if (a < 65)
		tmp1 = a - 48;
	// A ~ Z => 65 ~ 90
	else
		tmp1 = a - 55;

	if (b < 65)
		tmp2 = b - 48;
	else
		tmp2 = b - 55;

	return tmp1 + tmp2;
}

// 문자를 36진수로 바꿔준다.
int encode(char a)
{
	if (a < 65)
		return a - 48;
	else
		return a - 55;
}

// 36진수로 표기된 문자를 원래의 문자로 변환한다.
char decode(int a)
{
	if (a < 10)
	{
		return a + 48;
	}
	else
	{
		return a + 55;
	}
}

// 36진수 벡터를 받아 모두 더한 값을 반환한다.
string decimal36Plus(vector<string> decimal36)
{
	string current = decimal36[0];
	string next = "";

	vector<int> tmp;

	for (int i = 1; i < decimal36.size(); i++)
	{
		int ptr = 0;
		next = decimal36[i];

		// 현재 더해진 문자열 길이보다 길다면
		if (next.size() > current.size())
		{
			string s = current;
			current = next;
			next = s;
		}
		// 받아올림 할 경우, 받아올림 할 위치 기억
		ptr = current.size() - next.size() - 1;

		if (ptr >= 0)
		{
			for (int j = 0; j <= ptr; j++)
				tmp.emplace_back(encode(current[j]));
		}

		for (int j = next.size(); j > 0; j--)
		{
			char a = current[current.size() - j];
			char b = next[next.size() - j];
			int c = convert(a, b);
			
			// 디버깅
			cout << "c : " << c << endl;

			// c의 아스키 코드 값이 벡터에 들어간다.
			tmp.emplace_back(c);
		}

		current = "";

		// 받아올림 처리 (ptr + 1 인덱스 ~)
		for (int j = tmp.size() - 1; j > ptr + 1; j--)
		{
			if (tmp[j] > 35)
			{
				tmp[j] -= 36;
				tmp[j - 1] += 1;
			}
		}

		// 받아올림 처리 (ptr 인덱스)
		if (tmp[ptr + 1] > 35)
		{
			// current와 next의 길이가 같을 경우의 처리
			if (ptr == -1)
			{
				current += '1';
				tmp[ptr + 1] -= 36;
			}
			else
			{
				int a = ptr;
				
				tmp[ptr + 1] -= 36;
				tmp[a] += 1;
				
				// 받아 올려진 인덱스가 36 이상이면 다시 받아올린다.
				while (tmp[a] > 35 && a >= -1)
				{

					tmp[a] -= 36;
					a--;
					if (a == -1)
					{
						current += '1';

						break;
					}
					else
						tmp[a] += 1;
				}
			}
		}

		// 디버깅
		for (int j = 0; j < tmp.size(); j++)
			cout << "tmp[" << j << "] = " << tmp[j] << ' ';
		cout << endl;

		for (int j = 0; j < tmp.size(); j++)
		{
			current += decode(tmp[j]);
		}
		// 디버깅
		cout << "i = " << i << " current = " << current << endl;
		tmp.clear();
	}

	return current;
}

void B1036Solution()
{
	int N, K;
	vector<string> decimal36;
	string answer = "";

	B1036Input(N, K, decimal36);
	changeZ(N, K, decimal36);

	// 디버깅
	for (int i = 0; i < N; i++)
	{
		cout << decimal36[i] << ' ';
	}

	cout << endl;
	
	if (decimal36.size() > 1)
		answer = decimal36Plus(decimal36);
	else
		answer = decimal36[0];

	cout << answer;
}

int main()
{
	B1036Solution();

	return 0;
}
*/