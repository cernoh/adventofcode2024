#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
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

int mapstore(std::map<int, int> &map) {
  int total = 0;
  for (auto it = map.begin(); it != map.end(); it++) {
    total += it->first * it->second;
  }
  return total;
}

void part1() {
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
}

void part2() {
  std::vector<int> left_numbers;
  std::vector<int> right_numbers;
  readfile("test.txt", left_numbers, right_numbers);

  std::sort(left_numbers.begin(), left_numbers.end());
  std::sort(right_numbers.begin(), right_numbers.end());

  std::map<int, int> left_numbers_map;
  std::map<int, int> right_numbers_map;

  for (auto num : left_numbers) {
    if (left_numbers_map.find(num) == left_numbers_map.end()) {
      left_numbers_map[num] = 1;
    } else {
      left_numbers_map[num]++;
    }
  }

  for (auto num : right_numbers) {
    if (right_numbers_map.find(num) == right_numbers_map.end()) {
      right_numbers_map[num] = 1;
    } else {
      right_numbers_map[num]++;
    }
  }

  int total = mapstore(left_numbers_map) + mapstore(right_numbers_map);

  std::ofstream outfile("output.txt");
  outfile << std::fixed << std::setprecision(0) << total << std::endl;
  outfile.close();
}

int main() {
  part2();
  return 0;
}
