#include "stds.h"

// N1 = people_Num, N2 = party_Num, N3 = known_Num
void input_nums(int& N1, int& N2, int& N3, vector<int>& knowns, vector<vector<int>>& party_Info)
{
	cin >> N1 >> N2 >> N3;

	// ������ �ƴ� ����� �ִٸ�
	if (N3 > 0)
	{
		// �ƴ� ��� �� ��ŭ knowns�� �߰�.
		for (int i = 0; i < N3; i++)
		{
			int tmp = 0;
			cin >> tmp;
			knowns.emplace_back(tmp);
		}
	}

	vector<int> p_Number; // ��� ��ȣ

	for (int j = 0; j < N2; j++)
	{
		int p = 0; // ��� ��
		cin >> p;

		for (int k = 0; k < p; k++)
		{
			int n = 0; // ��ȣ
			cin >> n;

			p_Number.emplace_back(n);
		}

		party_Info.emplace_back(p_Number);
		p_Number.clear();
	}
}

int lier()
{
	int people_Num, party_Num, known_Num, count = 0; // ��� ��, ��Ƽ ��, ������ �ƴ� ��� ��, ���� �� �ִ� ��Ƽ ��
	vector<int> knowns;					  // ������ �ƴ� ������� ��ȣ
	vector<vector<int>> party_Info;				  // �� ��Ƽ�� ����

	input_nums(people_Num, party_Num, known_Num, knowns, party_Info);

	bool check[51] = { false, };		// ������ �ƴ� ����� ��ȣ Ȯ�ο�

	// ������ �ƴ� ����� �ִٸ�
	if (known_Num > 0)
	{
		// �� ��ȣ�� ����� ������ �ƴ� ������ �Ѵ�.
		for (int i = 0; i < known_Num; i++)
		{
			check[knowns[i]] = true;
		}
	}

	// ������ �ƴ� ����� �þ�� ��ó�� ����
	for (int i = 0; i < party_Num; i++)
	{
		int len = party_Info[i].size();
		// ������ �ƴ� ����� �þ��� ��� ó������ �ٽ� Ž���ϱ� ���� flag
		bool flag = false;

		for (int j = 0; j < len; j++)
		{
			// ���� ��ȣ�� ����� ������ �ȴٸ�
			if (check[party_Info[i][j]] == true)
			{
				// �� ��Ƽ�� ��� ����� ������ �˰� �ȴ�.
				for (int k = 0; k < len; k++)
				{
					// ������ �ƴ� ����� �þ��ٸ�
					if (check[party_Info[i][k]] == false)
						flag = true;

					check[party_Info[i][k]] = true;
				}
			}
		}

		if (flag)
			i = -1;
	}

	// ���� �� �ִ� ��Ƽ �� ���ϱ� (��ó�� ������ ���� ����ϴ�)
	for (int i = 0; i < party_Num; i++)
	{
		int len = party_Info[i].size();
		count++;

		for (int j = 0; j < len; j++)
		{
			if (check[party_Info[i][j]] == true)
			{
				count--;
				break;
			}
		}
	}
	return count;
}