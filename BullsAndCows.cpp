#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<vector>
#include<utility>

using namespace std;

string getHint1(string secret, string guess) {
	if (secret.size() != guess.size() || secret.empty()) return "0A0B"; 
	string result; unordered_map<char, vector<int>> order; 
	for (int i = 0; i < secret.size(); i++) {
		vector<int> positions;
		if (order.count(secret[i]))
			order[secret[i]].push_back(i);
		else			
			positions.push_back(i);
			order.insert(pair<char, vector<int>>(secret[i], positions));
	}
	vector<int> pos;  int bulls = 0, cows = 0;
	for (int i = 0; i < guess.size(); i++) {
		if (order.count(guess[i])) {
			pos = order.find(guess[i])->second;
			if ((std::find(pos.begin(), pos.end(), i) != pos.end())) {
				bulls++;
				pos.erase(std::remove(pos.begin(), pos.end(), i), pos.end());
				order[guess[i]] = pos;
			}				
			else
				cows++;			
		}
	}
	result = to_string(bulls) + "A" + to_string(cows) + "B";
	return result;
}

string getHint(string secret, string guess) {
	int aCnt = 0;
	int bCnt = 0;
	vector<int> sVec(10, 0); // 0 ~ 9 for secret
	vector<int> gVec(10, 0); // 0 ~ 9 for guess 
	if (secret.size() != guess.size() || secret.empty()) { return "0A0B"; }
	for (int i = 0; i < secret.size(); ++i) {
		char c1 = secret[i]; char c2 = guess[i];
		if (c1 == c2) {
			++aCnt;
		}
		else {
			++sVec[c1 - '0'];
			++gVec[c2 - '0'];
		}
	}
	// count b 
	for (int i = 0; i < sVec.size(); ++i) {
		bCnt += min(sVec[i], gVec[i]);
	}
	return to_string(aCnt) + 'A' + to_string(bCnt) + 'B';
}

int main()
{
	string result = getHint1("1123", "0111");
	cout << " Hint is : " << result;
	_getch();
	return 0;
}
