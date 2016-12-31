/* You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what 
the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret 
number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position
(called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.
For example : Secret number:  "1807" Friend's guess: "7810"  Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)*/
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
