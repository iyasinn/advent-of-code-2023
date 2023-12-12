#include <cctype>
#include <fstream>
#include <iostream>
using namespace std;

string INPUT = "puzzle_input.txt";

template <typename T> int getFirstNum(T start, T end) {

  while (start != end) {
    if (isdigit(*start)) {
      return *start - '0';
    }
    start++;
  }

  return 0;
}

int main() {

  ifstream fin(INPUT);
  string line = "";
  int sum = 0;

  while (fin >> line) {
    int first = getFirstNum(line.begin(), line.end());
    int last = getFirstNum(line.rbegin(), line.rend());
    sum += (first * 10) + last;
  }

  cout << "Sum: " << sum << endl;
}
