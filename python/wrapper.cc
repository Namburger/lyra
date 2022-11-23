#include <filesystem>

#include "decoder_main_lib.h"
#include "encoder_main_lib.h"
#include "pybind11/pybind11.h"

namespace chromemedia {
namespace codec {
namespace py = pybind11;

PYBIND11_MODULE(_pywrap_lyra, m) {
  m.def("EncodeFile", [](const std::string& wav_path,
                         const std::string& output_dir, int bitrate,
                         bool enable_preprocessing, bool enable_dtx,
                         const std::string& model_path) {
    const ghc::filesystem::path input_path(wav_path);
    std::error_code error_code;
    if (!ghc::filesystem::is_directory(output_dir, error_code)) {
      LOG(INFO) << "Creating non existent output dir " << output_dir;
      if (!ghc::filesystem::create_directories(output_dir, error_code)) {
        throw std::runtime_error("Failed to create output dir");
      }
    }
    LOG(INFO) << "Original size: " << ghc::filesystem::file_size(input_path)
              << " bytes";

    const auto output_path =
        ghc::filesystem::path(output_dir) / input_path.stem().concat(".lyra");
    if (EncodeFile(wav_path, output_path, bitrate, enable_preprocessing,
                   enable_dtx, model_path)) {
      LOG(INFO) << "Output: " << output_path.string() << " compressed size: "
                << ghc::filesystem::file_size(output_path.string()) << " bytes";
      return true;
    }
    return false;
  });
}
}  // namespace codec
}  // namespace chromemedia
