#include "libconf/parser.hpp"
#include <string>
#include <unordered_map>

namespace atwa {
namespace libconf {

class Libconf {
private:
  ConfigSource source;
  std::string filename;
public:
  Libconf(ConfigSource source) {
    this->source = source;
    this->filename = nullptr;
  }
  Libconf(ConfigSource source, std::string filename) {
    this->filename = filename;
    this->source = source;
  }
  void parse() {

  }
};

} // namespace libconf

} // namespace atwa
