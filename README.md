# Learn Modern C++ Project with CMake, FetchContent, and External Libraries

This project demonstrates a modern C++ setup using CMake, with proper support for:

- Internal project libraries (e.g., `person`)
- Header-only third-party libraries (e.g., `nlohmann/json`)
- Compiled third-party libraries (e.g., `spdlog`)
- Automatic dependency fetching using `FetchContent`
- Clean structure and modern CMake practices

---

## 📁 Project Structure

```
test-cpp/
│
├── CMakeLists.txt
├── main.cpp
├── person/
│ ├── CMakeLists.txt
│ ├── person.h
│ └── person.cpp
```

---

## 🛠️ Dependencies

This project uses the following third-party libraries:

| Library       | Type        | Method       | Description                        |
| ------------- | ----------- | ------------ | ---------------------------------- |
| nlohmann/json | Header-only | FetchContent | JSON serialization/deserialization |
| spdlog        | Compiled    | FetchContent | Fast logging for C++               |

---

## 🧩 How Libraries Are Included

We use [`FetchContent`](https://cmake.org/cmake/help/latest/module/FetchContent.html) to automatically download and configure libraries at configure time.

```cmake
include(FetchContent)

# Header-only: nlohmann/json
FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.11.2  # or latest stable version
)
FetchContent_MakeAvailable(json)

# Compiled lib: spdlog
FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG v1.13.0  # or latest stable version
)
FetchContent_MakeAvailable(spdlog)
```

---

| Scenario                           | How to Include in CMake                           |
| ---------------------------------- | ------------------------------------------------- |
| Header-only library                | target_include_directories() only                 |
|                                    |                                                   |
| Has CMakeLists.txt                 | add_subdirectory() + target_link_libraries()      |
| (internal or 3rd-party)            |                                                   |
|                                    |                                                   |
| 3rd-party library via FetchContent | FetchContent_Declare + FetchContent_MakeAvailable |
|                                    | + target_link_libraries()                         |
|                                    |                                                   |
| Library that depends on other      | Just include the main library (its CMake will     |
| libraries                          | fetch its dependencies)                           |

---

# **Building**

**This project uses vcpkg to manage dependencies**

1. "Clone vcpkg :"

```cpp
git clone https://github.com/microsoft/vcpkg.git & .\vcpkg\bootstrap-vcpkg.bat    # or ./vcpkg/bootstrap-vcpkg.sh on Linux
```

2. "Install dependencies :"

```cpp
.\vcpkg\vcpkg.exe install
```

## MSBuild-style via CMake

```cpp
cmake . -B build -DCMAKE_TOOLCHAIN_FILE=.\vcpkg\scripts\buildsystems\vcpkg.cmake
```

```cpp
cmake --build build
```

## Traditional nmake

```cpp
cmake . -B build -G "NMake Makefiles" -DCMAKE_TOOLCHAIN_FILE=.\vcpkg\scripts\buildsystems\vcpkg.cmake
```

```cpp
cd build & nmake & cd ..
```
