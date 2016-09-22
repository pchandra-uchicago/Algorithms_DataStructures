#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cassert>

using namespace std;

int coverPoints(vector<int> &X, vector<int> &Y)
{
	int stepCount = 0;
	int startPointX = X.front(); int startPointY = Y.front();

	vector<int>::iterator i = X.begin() ; vector<int>::iterator j = Y.begin();
	*i++; *j++;

	while (i != X.end())
	{
		while (*i != startPointX || *j != startPointY)
		{
			if (*i > startPointX)
			{
				if (*j > startPointY)
				{
					startPointX++;
					startPointY++;
					stepCount++;
				}
				else if (*j < startPointY)
				{
					startPointX++;
					startPointY--;
					stepCount++;
				}
				else
				{
					startPointX++;
					stepCount++;
				}
			}
			else if (*i < startPointX)
			{
				if (*j > startPointY)
				{
					startPointX--;
					startPointY++;
					stepCount++;
				}
				else if (*j < startPointY)
				{
					startPointX--;
					startPointY--;
					stepCount++;
				}
				else
				{
					startPointX--;
					stepCount++;
				}
			}
			else if (*i == startPointX)
			{
				if (*j > startPointY)
				{
					startPointY++;
					stepCount++;
				}
				else if (*j < startPointY)
				{
					startPointY--;
					stepCount++;
				}
			}
		}
		*i++; *j++;
	}
	return stepCount;
}

int coverPointsSoln(vector<int> x, vector<int> y) 
{
	if (x.size() <= 1) return 0;

	assert(x.size() == y.size());

	int stepCount = 0;
	for (int i = 1; i < x.size(); i++) 
	{
		stepCount += max(abs(x[i] - x[i - 1]), abs(y[i] - y[i - 1]));
	}
	return stepCount;
}
int main()
{
	vector<int> X;
	X.push_back(0);
	X.push_back(1);
	X.push_back(1);
	X.push_back(3);

	vector<int> Y;
	Y.push_back(0);
	Y.push_back(1);
	Y.push_back(2);
	Y.push_back(1);

	cout << "The min step count required is : " << coverPointsSoln(X, Y);
	_getch();
	return 0;
}
