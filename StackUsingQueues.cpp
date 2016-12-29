#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<queue>
#include<algorithm>

using namespace std;

class Stack {
public:
    queue<int> q1;
    // Push element x onto stack.
    void push(int x) {
        q1.push(x);
    }

   // Removes the element on top of the stack.
    void pop() {
        if(q1.empty()) return;
        if (q1.size() == 1) {
			q1.pop(); 
			return;
	}
        queue<int> q2; int count = 0;
        while(count < q1.size()) {
            q2.push(q1.front());
            q1.pop();
            count++;
        }
        q1.pop();
        q1 = q2;
    }

    // Get the top element.
    int top() {
        if(q1.empty()) return 0;
        if (q1.size() == 1) return q1.front();
        queue<int> q2; int count = 0;
        while(count < q1.size()) {
            q2.push(q1.front());
            q1.pop();
            count++;
        }
        int top = q1.front();
        q2.push(top);
		q1.pop();
		q1 = q2;
        return top;
    }

    // Return whether the stack is empty.
    bool empty() {
        if(q1.empty())
            return true;
        else
            return false;
    }
};

int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.pop();
	s.push(3);
	cout << " Top element is : " << s.top();
	_getch();
	return 0;
}
