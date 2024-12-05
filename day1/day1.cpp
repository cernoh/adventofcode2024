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

void edit_map(std::map<int, int> &map, std::vector<int> &opposite_vector) {

  for (auto &nums : opposite_vector) {
    if (map.find(nums) != map.end()) {
      map[nums] += 1;
    }
  }
}

std::map<int, int> return_map(std::vector<int> vector,
                              std::vector<int> opposite_vector) {
  std::map<int, int> map;
  for (auto &num : vector) {
    if (map.find(num) == map.end()) {
      map[num] = 0;
    }
  }
  edit_map(map, opposite_vector);
  return map;
}

int combine_map(std::map<int, int> &map, std::vector<int> &vec) {
  int total = 0;
  for (const auto &num : vec) {
    if (map.find(num) != map.end()) {
      total += map[num] * num;
    }
  }
  return total;
}

void part2() {
  std::vector<int> left_numbers;
  std::vector<int> right_numbers;
  readfile("input.txt", left_numbers, right_numbers);

  std::sort(left_numbers.begin(), left_numbers.end());
  std::sort(right_numbers.begin(), right_numbers.end());
  std::map<int, int> left_numbers_map = return_map(left_numbers, right_numbers);

  int total = combine_map(left_numbers_map, left_numbers);
  std::cout << std::fixed << std::setprecision(0) << total << std::endl;
}

int main() {
  part2();
  return 0;
}
