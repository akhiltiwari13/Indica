#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  vector<string> postfixExpression;

  /*------------takes a string from user and save to a vector of
   * strings---------*/
  cout << "enter postfix expression (No validity checks are in place)" << endl;
  getline(cin >> ws, str);
  stringstream obj(str);
  while (getline(obj, str, ' ')) {
    postfixExpression.push_back(str);
  }

  stack<int> cal_stack;
  bool isoperand;
  int result = 0, x = 0, y = 0;
  for (auto itr : postfixExpression) {
    isoperand = false;
    for (auto iitr : itr) {
      if (!isdigit(iitr)) {
        isoperand = true;
        break;
      }
    }
    if (isoperand) {
      switch (itr[0]) {
      case '*':
        x = cal_stack.top();
        cal_stack.pop();
        y = cal_stack.top();
        cal_stack.pop();
        result = y * x;
        cal_stack.push(result);
        break;
      case '+':
        x = cal_stack.top();
        cal_stack.pop();
        y = cal_stack.top();
        cal_stack.pop();
        result = y + x;
        cal_stack.push(result);
        break;
      case '-':
        x = cal_stack.top();
        cal_stack.pop();
        y = cal_stack.top();
        cal_stack.pop();
        result = y - x;
        cal_stack.push(result);
        break;
      default:
        break;
      }
    } else {
      int element = stoi(itr);
      cal_stack.push(element);
    }
  }
  while (!cal_stack.empty()) {
    cout << cal_stack.top() << endl;
    cal_stack.pop();
  }
}
