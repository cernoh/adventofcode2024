#include <cstddef>
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

int main() {
  std::string filename = "test.txt";
  std::vector<std::vector<int>> data = readFileToVector(filename);

  int total = 0;

  for (const auto &row : data) {
    bool readable = true;
    bool incrementing = false;
    if (row[0] < row[1]) {
      incrementing = true;
    }
    int prev_number = -1;
    for (const auto &number : row) {
      if (prev_number == -1) {
        prev_number = number;
        continue;
      }
      if (incrementing && number < prev_number ||
          !incrementing && number > prev_number) {
        readable = false;
        break;
      }
      if ((incrementing &&
           (number - prev_number <= 0 || number - prev_number > 3)) ||
          (!incrementing &&
           (prev_number - number <= 0 || prev_number - number > 3)) ||
          (abs(number - prev_number) < 1)) {
        readable = false;
        break;
      }
    }
    if (readable) {
      total++;
    }
  }

  std::cout << "Total readable: " << total << std::endl;
  return 0;
}
