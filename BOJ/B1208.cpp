/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// func
void B1208Input();
void B1208Solution();
void getPartialSum(int index, int end, long long sum, vector<long long> &sum_arr);
long long twoPointer();

// val
int S = 0;

vector<int> arr;
vector<long long> lsum;	// left's partial sum
vector<long long> rsum;	// right's partial sum

int main()
{
	B1208Solution();
}

void B1208Input()
{
	int N, tmp;
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		arr.emplace_back(tmp);
	}
}

void B1208Solution()
{
	B1208Input();

	// ascending order
	sort(arr.begin(), arr.end(), less<int>());

	int len = arr.size();

	if (len == 1) {
		if (arr[0] == S)
			cout << "1";
		else
			cout << "0";
	}
	else {
		getPartialSum(0, len / 2, 0, lsum);
		getPartialSum(len / 2, len, 0, rsum);

		// debugging
		//for (int i = 0; i < len / 2; i++) {
		//	cout << lsum[i] << ' ';
		//}
		//cout << endl;
		

		sort(lsum.begin(), lsum.end(), less<int>());
		sort(rsum.begin(), rsum.end(), less<int>());

		long long answer = twoPointer();

		cout << answer;
	}
}

// get partial sum between index and end
void getPartialSum(int index, int end, long long sum, vector<long long> &sum_arr)
{
	if (index == end) {
		sum_arr.emplace_back(sum);
		return;
	}

	// recursion
	getPartialSum(index + 1, end, sum + arr[index], sum_arr);
	getPartialSum(index + 1, end, sum, sum_arr);
}

// two pointer algorithm
long long twoPointer()
{
	int lp = 0;
	int rp = rsum.size() - 1;
	int lend = lsum.size();
	long long count = 0;

	while (lp < lend && rp >= 0) {
		// when partial sum larger than S
		if (lsum[lp] + rsum[rp] > S) {
			rp--;
		}
		// when partial sum smaller than S
		else if (lsum[lp] + rsum[rp] < S) {
			lp++;
		}
		// when partial sum same with S
		else {
			long long tmp1 = lsum[lp];
			long long lcount = 0;
			
			while (lp < lend && lsum[lp] == tmp1) {
				lcount++;
				lp++;
			}

			long long tmp2 = rsum[rp];
			long long rcount = 0;

			while (rp >= 0 && rsum[rp] == tmp2) {
				rcount++;
				rp--;
			}

			count += lcount * rcount;
		}
	}

	if (S == 0)
		count--;

	return count;
}
*/