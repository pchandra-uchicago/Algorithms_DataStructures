#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<iterator>

using namespace std;

vector<vector<int> > anagrams_indexAsVectors(const vector<string> &A) {
	unordered_map<string, vector<int> > anagrams; int indexCount = 1;
	for (auto i = A.begin(); i != A.end(); i++) {
		string str = *i;
		sort(str.begin(), str.end()); vector<int> index;		
		if (!anagrams.count(str)) {			
			index.push_back(indexCount);
			anagrams.insert(pair<string, vector<int>>(str, index));
		}
		else
			anagrams[str].push_back(indexCount);				
		indexCount++;
	}
	vector<vector<int>> result;
	for (auto it = anagrams.begin(); it != anagrams.end(); it++) {
		if (it->second.size() > 1) 
			result.push_back(it->second);		
		else if (it->second.size() == 1 && A.size() == 1)
			result.push_back(it->second);
	}
	return result;
}

vector<string> anagrams_string(vector<string> &strs) {
	unordered_map<string, vector<string> > sortedToString;
	for (auto it = strs.begin(); it != strs.end(); it++) {
		string copy = *it;
		sort(copy.begin(), copy.end());
		vector<string> v = sortedToString[copy];
		v.push_back(*it);
		sortedToString[copy] = v;
	}
	vector<string> res;
	for (auto it = sortedToString.begin(); it != sortedToString.end(); it++) {
		if (it->second.size()>1) {
			res.insert(res.end(), it->second.begin(), it->second.end());
		}
	}
	return res;
}

int main()
{
	vector<string> input;
	input.push_back("dog");	
	input.push_back("cat");	
	input.push_back("bears");
	input.push_back("bulls");
	input.push_back("god");
	input.push_back("tca");

	anagrams_indexAsVectors(input);
	_getch();
	return 0;
}
