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
} // namespace bit_flip::logic
