#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> maxset(vector<int> &A)
{
	int old_sum = 0; int new_sum = 0; int startIndex = 0;
	int indexLast = 0;
	bool flag = true;
	vector<int> sum; vector<int> startIdx; vector<int> endIdx;

	for (int i = 0; i <= A.size() - 1; i++)
	{
		if (flag)
		{
			startIndex = i;
		}
		int temp = A.size() - 1;
		int num = A[i];

		if (A[i] > 0)
		{			
			new_sum = new_sum + A[i];
			flag = false;

			if (i == A.size() -1)
			{
				indexLast = i;
			}
		}
		else
		{			
			sum.push_back(new_sum);
			startIdx.push_back(startIndex);
			endIdx.push_back(i - 1);
			flag = true;
			new_sum = 0;
		}
	}

	if (new_sum > 0)
	{
		sum.push_back(new_sum);
		startIdx.push_back(startIndex);
		endIdx.push_back(indexLast);
	}
	
	vector<int> result; int largest = 0;
	
	for (int i = 0; i <= sum.size() - 1; i++)
	{
		largest = *(max_element(sum.begin(), sum.end()));
	}

	return result;
}

vector<int> maxsetSoln(vector<int> Vec) {
	int N = Vec.size();

	long long mx_sum = 0;
	long long cur_sum = 0;
	int mx_range_left = -1;
	int mx_range_right = -1;
	int cur_range_left = 0;
	int cur_range_right = 0;

	while (cur_range_right < N) {
		if (Vec[cur_range_right] < 0) {
			cur_range_left = cur_range_right + 1;
			cur_sum = 0;
		}
		else {
			cur_sum += (long long)Vec[cur_range_right];
			if (cur_sum > mx_sum) {
				mx_sum = cur_sum;
				mx_range_left = cur_range_left;
				mx_range_right = cur_range_right + 1;
			}
			else if (cur_sum == mx_sum) {
				if (cur_range_right + 1 - cur_range_left > mx_range_right - mx_range_left) {
					mx_range_left = cur_range_left;
					mx_range_right = cur_range_right + 1;
				}
			}
		}
		cur_range_right++;
	}
	vector<int> ans;
	if (mx_range_left == -1 || mx_range_right == -1)
		return ans;

	for (int i = mx_range_left; i < mx_range_right; ++i)
		ans.push_back(Vec[i]);
	return ans;
}

int main()
{
	vector<int> input;
	input.push_back(-1);
	input.push_back(2);
	input.push_back(5);
	input.push_back(-7);
	input.push_back(2);
	input.push_back(5);
	input.push_back(-1);
	input.push_back(3);

	vector<int> result = maxset(input);

	for (vector<int>::iterator i = result.begin(); i != result.end(); i++)
	{
		cout << *i << ' ';
	}
	_getch();
	return 0;
}

