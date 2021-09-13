#ifndef BIT_FLIP_SRC_LOGIC_FLIPPER_H
#define BIT_FLIP_SRC_LOGIC_FLIPPER_H

#include <filesystem>

namespace bit_flip::logic {
class Flipper {
public:
  using path_type = std::filesystem::path;

  explicit Flipper(const path_type &inPath, const path_type &outPath,
                   std::size_t bufferSize);

  void operator()() const;

private:
  void flipRegular() const;
  void flipDirectory() const;

  const path_type _inPath;
  const path_type _outPath;
  const std::size_t _bufferSize;

  static constexpr std::size_t _defaultBufferSize = 1024;
};
} // namespace bit_flip::logic

#endif // BIT_FLIP_SRC_LOGIC_FLIPPER_H
