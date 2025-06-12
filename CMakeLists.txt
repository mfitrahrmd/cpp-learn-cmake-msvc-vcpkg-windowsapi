cmake_minimum_required(VERSION 3.10)
project(test_cpp)

# Enable FetchContent
include(FetchContent)

# when library also uses the same library you are using, in this case "spdlog" uses "fmt"
# Tell spdlog to use the external fmt before fetching it
set(SPDLOG_FMT_EXTERNAL ON)

find_package(fmt CONFIG REQUIRED)

add_executable(main main.cpp)

add_subdirectory(person)

# --- Fetch nlohmann/json ---
FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.12.0
)
FetchContent_MakeAvailable(json)

# --- Fetch spdlog ---
FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG v1.15.3
)
FetchContent_MakeAvailable(spdlog)

target_link_libraries(main PRIVATE person fmt::fmt nlohmann_json::nlohmann_json spdlog::spdlog)