#include <iostream>
#include <vector>

using namespace std;

void B6064Input(int &N, int &M, int &x, int &y)
{
	cin >> N >> M >> x >> y;
}

void B6064Solution()
{
	vector<int> answers;
	int T, N, M, x, y;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int curr_x = 1, curr_y = 1;
		int year = 1;
		bool isInvalid = true; // ��ȿ ���� (true : ��ȿ���� ����)
		B6064Input(N, M, x, y);

		
	}

	for (int i = 0; i < answers.size(); i++)
		cout << answers[i] << endl;
}

/*
int main()
{
	B6064Solution();
	return 0;
}
*/