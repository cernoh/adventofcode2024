#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> parseFile(const std::string &filename) {
  std::ifstream file(filename);
  std::vector<int> result;
  std::string line;

  while (std::getline(file, line)) {
    size_t i = 0, j = 0;
    bool valid = false;
    while (i < line.size()) {
      if (line.substr(i, 3) == "mul") {
        j = i + 7;
        bool found = false;
        for (int k = j; k <= j + 4; k++) {
          if (line[k] == ')') {
            j = k;
            found = true;
          }
          if (found) {
            break;
          }
        }
        if (found) {
          std::cout << "found: " << line.substr(i, j) << std::endl;
          i = j;
        }
      }
      i++;
    }
  }

  return result;
}

void part1(const std::string &filename) {
  int total = 0;
  std::vector<int> mult_nums = parseFile(filename);
  for (auto &num : mult_nums) {
    total += num;
  }
  std::cout << total << std::endl;
}

int main(int argc, char *argv[]) {
  std::string file = "test.txt";
  parseFile(file);
  return 0;
}
