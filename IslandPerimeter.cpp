/*You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected 
horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more 
connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a 
square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]
Answer: 16  */
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int islandPerimeter(vector<vector<int>>& grid) {
	int perimeter = 0; int extras = 0;
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[0].size(); j++) {
			if (grid[i][j] != 0) {
				perimeter++;
				if (i != 0 && grid[i - 1][j] == 1) extras++;
				if (j != 0 && grid[i][j - 1] == 1) extras++;
			}			
		}
	}
	return (perimeter*4 - 2*extras);
}

int main()
{
	vector<int> a, b, c, d;
	a.insert(a.end(), {0,1,0,0});
	b.insert(b.end(), {1,1,1,0});
	c.insert(c.end(), {0,1,0,0});
	d.insert(d.end(), {1,1,0,0});
	vector<vector<int>> input;
	input.insert(input.end(), { a,b,c,d });
	cout << "Perimeter of the island is :" << islandPerimeter(input);
	_getch();
	return 0;
}
