#include "string"
#include "types.hpp"
#include <exception>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>
#include <exception>

namespace atwa {
namespace libconf {
class Parser {
protected:
  std::unordered_map<std::string, std::string> parsedData;
  bool addNullIfNotFound;
  void populateMap() {}
public:
  Parser(bool addNullifNotFound) {
    this->addNullIfNotFound = addNullifNotFound;
    this->populateMap();
  }
  std::string get(std::string key) {
    if(!addNullIfNotFound && this->parsedData.find(key) == this->parsedData.end()) {
      throw "Invalid key, couldn't find a value mapped to '" + key + "'";
    }
    return this->parsedData[key];
  }
};

class EnvFileParser : protected Parser {

  std::string rawString;

  void populateMap() {
    std::vector<std::string> lines = std::vector<std::string>();
    std::string currentLine = "";
    // Get lines...
    // Perhabs, should combine both loops?
    for (char currentChar: rawString) {
      if (currentChar == '\n') {
        lines.push_back(currentLine);
        currentLine = "";
        continue;
      }
      currentLine.push_back(this->rawString.at(i));
    }

    // Split each line around '='
    std::string key = "";
    std::string val = "";
    for (int i = 0; i < lines.size(); i++) {
      currentLine = lines.at(i);
      for (int j = 0; j < lines.at(i).length(); j++) {
        char currentChar = currentLine.at(j);
        if (currentChar == '=') {

          if (j + 1 >= currentLine.length() && !this->addNullIfNotFound) {
            throw &"Invalid Env file found, Cannot get value @ line: " [i+1];
          }

          val = currentLine.substr(j + 1);

          this->parsedData[key] = val;

          val = "";
          key = "";
          continue;
        }
        key.push_back(currentChar);
      }
    }
  }

public:
  EnvFileParser(std::string rawString, bool addNullIfNotFound = false)
      : Parser(addNullIfNotFound) {
        this->rawString = rawString;
      }
};

class EnvProcessParser : protected Parser {
  void populateMap() {
  }

public:
  EnvProcessParser(bool addNullIfNotFound = false)
      : Parser(addNullIfNotFound) {}
};
} // namespace libconf
} // namespace atwa