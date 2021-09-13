#include "Flipper.h"
#include <stdexcept>
#include <utility>

namespace fs = std::filesystem;

namespace bit_flip::logic {
Flipper::Flipper(const path_type &inPath, const path_type &outPath,
                 std::size_t bufferSize)
    : _inPath(fs::absolute(inPath)), _outPath(fs::absolute(outPath)),
      _bufferSize(bufferSize != 0 ? bufferSize : _defaultBufferSize) {
  if (_inPath == _outPath)
    throw std::invalid_argument("input and output path can't be same");
}

void Flipper::operator()() const {
  auto inStatus = fs::status(_inPath);
  switch (auto t = inStatus.type()) {
  case fs::file_type::regular:
    flipRegular();
    break;
  case fs::file_type::directory:
    flipDirectory();
    break;
  default:
    auto v = std::underlying_type_t<fs::file_type>(t);
    auto s = std::to_string(v);
    throw std::runtime_error("error file type: " + s);
  }
}

void Flipper::flipRegular() const {}
void Flipper::flipDirectory() const {}
} // namespace bit_flip::logic
