#pragma once
#include <string>
#include <variant>

struct NilValue
{
};

using Value = std::variant<NilValue, bool, double, std::string>;
