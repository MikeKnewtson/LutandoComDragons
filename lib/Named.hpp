#pragma once

template <typename BaseType, const char* name>
struct Named : public BaseType {
    static constexpr auto get_name() { return name; }
};