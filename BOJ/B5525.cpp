/*
#include <iostream>
#include <vector>

using namespace std;

// func
void B5525Input();
void B5525Solution();
void checkIOI();
void findPatternNum();

// val
char S[1000001];
int memo[1000001];
int N, M;

// ���ڿ� S�� �� �˻��ϸ鼭 
// ���� ���� I�� P(N)�� �޸��Ѵ�.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	B5525Solution();
}

void B5525Input()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> S[i];
	}
}

void B5525Solution()
{
	B5525Input();
	checkIOI();
	findPatternNum();
}

void checkIOI()
{
	for (int i = 0; i < M; i++) {
		switch (i) {
		case 0:
			if (S[i] == 'I')
				memo[i] = 0;
			else
				memo[i] = -1;
			break;
		case 1:
			if (S[i] == 'I')
				memo[i] = 0;
			else
				memo[i] = -1;
			break;
		default:
			if (S[i] == 'I') {
				// ������ ��� �ٷ� ���� I�� P(N)�� 1�� ���� ���� ����
				if (S[i - 2] == 'I' && S[i - 1] == 'O')
					memo[i] = memo[i - 2] + 1;
				else
					memo[i] = 0;
			}
			else {
				memo[i] = -1;
			}
			break;
		}
	}
}

// ã���� �ϴ� ������ ���� ���
void findPatternNum()
{
	int count = 0;

	for (int i = 0; i < M; i++) {
		if (memo[i] >= N)
			count++;
	}

	cout << count;
}
*/