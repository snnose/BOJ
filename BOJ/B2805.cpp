/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// func
void B2805Input();
void B2805Solution();
void binarySearch(int start, int end);

// val
int N, M;
vector<int> trees;

// 최적의 절단기 길이 값을 이분 탐색으로 찾는 알고리즘

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	B2805Solution();
}

void B2805Input()
{
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		trees.emplace_back(tmp);
	}

	// descending order
	sort(trees.begin(), trees.end(), greater<int>());
}

void B2805Solution()
{
	B2805Input();
	binarySearch(1, trees[0]);
}

void binarySearch(int start, int end)
{
	long long curr; int i;
	int max_height = 0;

	while (start <= end) {
		curr = 0; i = 0;
		int middle = start + (end - start) / 2;

		while (i < N) {
			if (middle < trees[i])
				curr += (trees[i] - middle);
			
			if (curr > M)
				break;

			i++;
		}

		if (curr >= M) {
			max_height = max(max_height, middle);
			start = middle + 1;
		}
		else {
			end = middle - 1;
		}
	}

	cout << max_height;
}
*/