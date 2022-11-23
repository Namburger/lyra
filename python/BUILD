load("@pybind11_bazel//:build_defs.bzl", "pybind_extension")

pybind_extension(
  name = "_pywrap_lyra",
  srcs = [
    "wrapper.cc"
  ],
  deps = [
    "//:encoder_main_lib",
    "//:decoder_main_lib",
  ]
)
