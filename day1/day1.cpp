#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

void readfile(std::string filename, std::vector<int> &left_numbers,
              std::vector<int> &right_numbers) {
  std::ifstream infile(filename);
  std::vector<int> leftnum;
  std::vector<int> rightnum;
  int left, right;

  while (infile >> left >> right) {
    left_numbers.push_back(left);
    right_numbers.push_back(right);
  }

  infile.close();
}

int main() {
  std::vector<int> left_numbers;
  std::vector<int> right_numbers;
  readfile("input.txt", left_numbers, right_numbers);

  std::sort(left_numbers.begin(), left_numbers.end());
  std::sort(right_numbers.begin(), right_numbers.end());

  double total = 0;
  for (int i = 0; i < left_numbers.size(); i++) {
    total += std::abs(left_numbers[i] - right_numbers[i]);
  }

  std::ofstream outfile("output.txt");
  outfile << std::fixed << std::setprecision(0) << total << std::endl;
  outfile.close();

  return 0;
}
