#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <vector>

int convertStrToDigit (std::string digit) {
  if (digit == "one" || digit == "1") return 1;
  if (digit == "two"|| digit == "2") return 2;
  if (digit == "three"|| digit == "3") return 3;
  if (digit == "four"|| digit == "4") return 4;
  if (digit == "five"|| digit == "5") return 5;
  if (digit == "six"|| digit == "6") return 6;
  if (digit == "seven"|| digit == "7") return 7;
  if (digit == "eight"|| digit == "8") return 8;
  if (digit == "nine"|| digit == "9") return 9;

  return 0;
}

bool isDigit (char x) {
  if (x - '0' >= 0 && x - '0' <= 9)
    return true;
  return false;
}

int solution (const std::string& fileName) {
     std::vector<std::string> digitsAsWords = {"one","two","three","four","five","six","seven","eight","nine"};
     std::fstream input(fileName, std::fstream::in);
     std::string line;
     int sum = 0;
    
    while(std::getline(input, line)) { 
    
    std::vector<int> digits;
    for (int i = 0; i < line.length(); i++ ) { 
      if (!isDigit(line.at(i))) {
      for (const auto& word : digitsAsWords) {
        if (line.substr(i, word.length()) == word)
          digits.push_back(convertStrToDigit(line.substr(i, word.length())));
      }
      }
      else {
        digits.push_back(line.at(i) - '0');
      }
    }

    sum += digits.front() * 10 + digits.back(); 
    
    
    }
    return sum;      
}

int main () { 

  std::string fileName = "aoc1_input.txt";

  std::cout << solution(fileName) << std::endl;
 
  return 0;

}