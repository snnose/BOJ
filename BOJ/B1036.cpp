/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// �ڸ����� ������ Z�� �ٲٸ� �� Ŀ���� ��츦 ����ؾ���.

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

// 36���� ���ڿ����� K�� ������ŭ �ִ밪�� �ǵ��� Z�� �ٲ۴�
void changeZ(int N, int K, vector<string> &decimal)
{
	// �� 36���� ���ڿ��� ����
	vector<int> decimalSize;
	for (int i = 0; i < N; i++)
	{
		decimalSize.emplace_back(decimal[i].size());
	}

	int maxCount = 0, currentK = K;
	while (currentK > 0)
	{
		// ���� �� ���̸� ã�´�.
		int maxSize = *max_element(decimalSize.begin(), decimalSize.end());
		// �����
		cout << "maxSize : " << maxSize << " currentK : " << currentK << endl;

		// �� �̻� �ٲ� ���ڰ� ���ٸ� Ż��
		if (maxSize <= 0)
			break;

		// ���� �� ���ڿ��� ������ ����.
		for (int i = 0; i < N; i++)
		{
			if (decimalSize[i] == maxSize)
				maxCount++;
		}

		// ���� �� ���ڿ� ������ ���� K�� �������� �۰ų� ���ٸ�
		if (maxCount <= currentK)
		{
			char a = NULL;
			// ���� �� ���ڸ� 'Z'�� �ٲ��ش�.
			for (int i = 0; i < N; i++)
			{
				if (decimalSize[i] == maxSize)
				{
					// ���� �� ���ڰ� 'Z'�� �ƴ϶��
					if (decimal[i][decimal[i].size() - decimalSize[i]] != 'Z')
					{
						// �ٲ� ���ڸ� ����Ѵ�.
						a = decimal[i][decimal[i].size() - decimalSize[i]];
						decimal[i][decimal[i].size() - decimalSize[i]] = 'Z';
					}
					// 'Z'���
					else
						maxCount--; // �ٲ��� �ʴ´�
						
					decimalSize[i]--;
				}

				// ���ڸ� �ٲ�ٸ�
				if (a != NULL)
				{
					// ��� ������ �ٲ� Ư�� ���ڸ� 'Z'�� �ٲ۴�.
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
		// �ƴ϶��
		else
		{
			// ���� �ڸ��� �� ���� ���� ���ڸ� Z�� �ٲ���Ѵ�.
			char minChar = 'Z';
			char a = NULL;
			
			// ���� ���� �� ���ڿ��� ���� ��(Z�� �ƴ�)�� �ּ� ���ڸ� ã�´�.
			for (int i = 0; i < N; i++)
			{
				if (decimalSize[i] == maxSize)
				{
					minChar = min(minChar, decimal[i][decimal[i].size() - decimalSize[i]]);
				}
			}

			// ���� �ּ� ���ڰ� Z�� ������ �ε��� ���� �� ��ݺ��Ѵ�.
			if (minChar == 'Z')
			{
				for (int i = 0; i < N; i++)
				{
					if (decimalSize[i] == maxSize)
						decimalSize[i]--;
				}

				continue;
			}

			// ��� 36���� ���ڿ��� �ּ� ���ڿ� ���� ���ڸ� Z�� �ٲ۴�.
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

// 36���� �� ���� �޾� ���� ���� ��ȯ�Ѵ�.
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

// ���ڸ� 36������ �ٲ��ش�.
int encode(char a)
{
	if (a < 65)
		return a - 48;
	else
		return a - 55;
}

// 36������ ǥ��� ���ڸ� ������ ���ڷ� ��ȯ�Ѵ�.
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

// 36���� ���͸� �޾� ��� ���� ���� ��ȯ�Ѵ�.
string decimal36Plus(vector<string> decimal36)
{
	string current = decimal36[0];
	string next = "";

	vector<int> tmp;

	for (int i = 1; i < decimal36.size(); i++)
	{
		int ptr = 0;
		next = decimal36[i];

		// ���� ������ ���ڿ� ���̺��� ��ٸ�
		if (next.size() > current.size())
		{
			string s = current;
			current = next;
			next = s;
		}
		// �޾ƿø� �� ���, �޾ƿø� �� ��ġ ���
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
			
			// �����
			cout << "c : " << c << endl;

			// c�� �ƽ�Ű �ڵ� ���� ���Ϳ� ����.
			tmp.emplace_back(c);
		}

		current = "";

		// �޾ƿø� ó�� (ptr + 1 �ε��� ~)
		for (int j = tmp.size() - 1; j > ptr + 1; j--)
		{
			if (tmp[j] > 35)
			{
				tmp[j] -= 36;
				tmp[j - 1] += 1;
			}
		}

		// �޾ƿø� ó�� (ptr �ε���)
		if (tmp[ptr + 1] > 35)
		{
			// current�� next�� ���̰� ���� ����� ó��
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
				
				// �޾� �÷��� �ε����� 36 �̻��̸� �ٽ� �޾ƿø���.
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

		// �����
		for (int j = 0; j < tmp.size(); j++)
			cout << "tmp[" << j << "] = " << tmp[j] << ' ';
		cout << endl;

		for (int j = 0; j < tmp.size(); j++)
		{
			current += decode(tmp[j]);
		}
		// �����
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

	// �����
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