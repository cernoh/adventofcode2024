#include <cstddef>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::vector<int>> readFileToVector(const std::string &filename) {
  std::ifstream file(filename);
  std::vector<std::vector<int>> result;
  std::string line;

  while (std::getline(file, line)) {
    std::istringstream iss(line);
    std::vector<int> row;
    int number;
    while (iss >> number) {
      row.push_back(number);
    }
    result.push_back(row);
  }

  return result;
}

int part1(std::string &filename) {
  std::vector<std::vector<int>> data = readFileToVector(filename);

  int total = 0;

  for (const auto &row : data) {
    bool readable = true;
    bool incrementing = row[0] < row[1];
    int prev_number = row[0];

    for (size_t i = 1; i < row.size(); ++i) {
      int number = row[i];
      if ((incrementing && number <= prev_number) ||
          (!incrementing && number >= prev_number) ||
          abs(number - prev_number) > 3) {
        readable = false;
        break;
      }
      prev_number = number;
    }

    if (readable) {
      total++;
    }
  }

  return total;
}

int part2(std::string &filename) {
  std::vector<std::vector<int>> data = readFileToVector(filename);

  int total = 0;

  for (const auto &row : data) {
    bool readable = true;
    bool safety = true;
    bool incrementing = row[0] < row[1];
    int prev_number = row[0];

    for (size_t i = 1; i < row.size(); ++i) {
      int number = row[i];
      if ((incrementing && number <= prev_number) ||
          (!incrementing && number >= prev_number) ||
          abs(number - prev_number) > 3) {
        if (!safety) {
          readable = false;
          break;
        } else {
          safety = false;
        }
      }
      prev_number = number;
    }

    if (readable) {
      total++;
    }
  }

  return total;
}

int main() {
  std::string filename = "input.txt";
  int total = part1(filename);
  int total2 = part2(filename);
  std::cout << "part 1:" << total << "\n part 2: " << total2 << std::endl;
  return 0;
}
