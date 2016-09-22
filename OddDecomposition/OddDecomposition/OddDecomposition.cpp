#include<iostream>
#include <algorithm>
#include<vector>
#include<conio.h>

using namespace std;

vector<int> solution(int N)
{
	std::vector<int> R(100, 0);
	int sum = 0;
	int counter = 0;
	
	for (int i = 1; i < N - sum; i += 2)
	{
		R.insert((R.begin() + counter++), i);
		//counter += 1;
		sum += i;
	}
	int alpha = 0;
	int r = N - sum;
	if (r % 2 == 0)
	{
		//a[counter - 1] += r;
		//R.push_back(R.at(counter - 1) + r);
		R.insert((R.begin() + counter-1), (R.at(counter - 1) + r));
	}
	else if (r > R.at(counter - 1)) {
		R.insert((R.begin() + counter++), r);
	}
	else {
		alpha = 1;
		//a[counter - 1] += r + 1;
		R.insert((R.begin()+counter-1), (R.at(counter - 1) + r + 1));
	}	

	for (int i = alpha; i < counter; i++) {
		cout<<R.at(i)<<endl;
	}

	return R;
	// write your code in C++11 (g++ 4.8.2)
}

int main()
{
	int N;
	cout << "Enter the number" << endl;
	cin >> N;
	solution(N);
	_getch();
	return 0;
}

