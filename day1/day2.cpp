#include <fstream>
#include <initializer_list>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

string INPUT = "puzzle_input.txt";

template <typename T> int text_to_num(T start, const T end) {
  unordered_map<string, int> numbers = {
      {"zero", 0}, {"one", 1}, {"two", 2},   {"three", 3}, {"four", 4},
      {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};
  string curr = "";
  for (int i = 0; i < 5; i++) {
    if (start == end) {
      return -1;
    }
    curr.append(*start);
    start++;
  }
  return -1;
}

template <typename T> int getFirstNum(T start, T end) {

  while (start != end) {
    if (isdigit(*start)) {
      return *start - '0';
    }
    int potential_num = text_to_num(start, end);
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
