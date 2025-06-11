#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include <person.h>
#include <fmt/core.h>
#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // spdlog example usage
    spdlog::info("Hello from spdlog!");

    // nlohmann json example usage
    nlohmann::json j;
    j["language"] = "C++";
    j["version"] = 20;
    std::cout << j.dump(4) << std::endl;

    auto *rama = new Person("Rama");

    // fmt example usage
    fmt::print(rama->name);

    // windows API example usage
    MessageBoxA(NULL, rama->name.c_str(), "MSVC Demo", MB_OK);

    return 0;
}
