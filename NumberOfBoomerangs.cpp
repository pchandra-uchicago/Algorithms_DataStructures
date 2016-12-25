#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

int numberOfBoomerangs(vector<pair<int, int>>& points) {
	int count = 0; 
	for (int i = 0; i < points.size(); i++) {
		unordered_map<long, int> pairs;
		for (int j = 0; j < points.size(); j++) {
			if (i != j) {
				int dist = pow((points[i].second - points[j].second), 2) + 
										pow((points[i].first - points[j].first), 2);
				pairs[dist]++;
			}
		}
		for (auto i : pairs) {
			if (i.second > 1)	
				count += (i.second) * (i.second - 1);		
		}
	}	
	return count;
}

int main()
{
	vector<pair<int, int>> points;
	points.insert(points.end(), { make_pair(0,0), make_pair(1,0), make_pair(-1,0),
											make_pair(0,1), make_pair(0,-1) });
	cout<< "Number of Boomerangs are : " << numberOfBoomerangs(points);
	_getch();
	return 0;
}