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
  std::string filename = "input.txt";
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

  std::cout << "Total readable: " << total << std::endl;
  return 0;
}
