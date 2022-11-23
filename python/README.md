## Python wrapper for lyra

Caveat: Currently only has "EncodeFile" but can be extended for more stuffs.

Build:
```
cd python
bazel build -c opt //python:_pywrap_lyra.so
cp ../bazel-bin/python/_pywrap_lyra.so ./
```

Encode a file:
```
python3                
Python 3.10.7 (main, Sep  8 2022, 14:34:29) [GCC 12.2.0] on linux
Type "help", "copyright", "credits" or "license" for more information.
>>> import _pywrap_lyra as lyra
>>> lyra.EncodeFile('../testdata/sample1_16kHz.wav', '/tmp', 3200, False, False, '../model_coeffs')
WARNING: Logging before InitGoogleLogging() is written to STDERR
I20221123 16:05:44.926478 1435867 wrapper.cc:24] Original size: 110398 bytes
INFO: Created TensorFlow Lite XNNPACK delegate for CPU.
I20221123 16:05:45.044263 1435867 encoder_main_lib.cc:91] Elapsed seconds : 0
I20221123 16:05:45.044293 1435867 encoder_main_lib.cc:92] Samples per second : 676098
I20221123 16:05:45.044700 1435867 wrapper.cc:31] Output: /tmp/sample1_16kHz.lyra compressed size: 1376 bytes
True
>>> exit() 
```

Check the size diffference:
```
ll ../testdata/sample1_16kHz.wav 
-rw-r--r-- 1 user primarygroup 108K Nov 23 15:43 ../testdata/sample1_16kHz.wav
ll /tmp/sample1_16kHz.lyra 
-rw-r--r-- 1 user primarygroup 1.4K Nov 23 16:05 /tmp/sample1_16kHz.lyra

```
