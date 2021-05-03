#include "libconf/parser.hpp"
#include <string>

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
};

} // namespace libconf

} // namespace atwa
