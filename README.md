# Jinja2C
C API for Jinja2Cpp. 

This is the C++ library component of the [jinja2cppwrapper_jll.jl](https://github.com/JuliaBinaryWrappers/jinja2cppwrapper_jll.jl) package.

# Prerequisites

Before building Jinja2C, you need to install Jinja2Cpp. You can do this by following the installation instructions from the [Jinja2Cpp](https://github.com/jinja2cpp/Jinja2Cpp) repository or [documentation](https://jinja2cpp.github.io/docs/build_and_install.html).

# Building

To build Jinja2C, follow these steps:

1. Clone the repository:
```
git clone https://github.com/AlexKlo/Jinja2C.git
cd Jinja2C
```

2. Create a build director and Run CMake to configure the build system. If Jinja2Cpp is not installed in a standard location, you need to specify its path using -DCMAKE_PREFIX_PATH:
```
mkdir build && cd build
cmake .. -DCMAKE_PREFIX_PATH=/path/to/Jinja2Cpp
```

3. Build the project:
```
cmake --build . --parallel ${nproc}
```

# Installation 

After building, you can install Jinja2C using:

```
cmake --install .
```

By default, this will install Jinja2C in `/usr/local/` and headers in `/usr/local/include/jinja2cppwrapper`. You can change the installation prefix by adding `-DCMAKE_INSTALL_PREFIX=/your/install/path` to the cmake command.

# Usage

To use **jinja2cppwrapper** in your C project, include `jinja2cpp_wrap.h` and link against `ljinja2cppwrapper`.

## Example

The following example from `examples/` demonstrates how to compile a program using **jinja2cppwrapper**:

```sh
g++ -std=c++14 -o simple_example simple_example.c -I/path/to/include -L/path/to/lib -ljinja2cppwrapper
```

### Notes:
- Replace `/path/to/include` with the directory where the header files are installed.
- Replace `/path/to/lib` with the directory where the compiled library is located.



