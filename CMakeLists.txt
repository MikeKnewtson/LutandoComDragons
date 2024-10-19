# CMakeList.txt : CMake project for LutandoDragon, include source and define
# project specific logic here.
#
cmake_minimum_required(VERSION 3.29)

project(LutandoDragon)

# Add source to this project's executable.
add_executable (LutandoDragon "LutandoDragon.cpp")

set_property(TARGET LutandoDragon PROPERTY CXX_STANDARD 20)

target_compile_options(LutandoDragon PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -pedantic -pedantic-errors -Werror -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-private-field -Wno-unused-const-variable -Wno-unused-value -Wno-unused-local-typedefs -Wno-unknown-attributes -Wno-ignored-attributes -Wno-c99-extensions -Wno-overlength-strings -Wno-missing-field-initializers -Wno-missing-braces -Wno-c++11-narrowing -Wno-address-of-packed-member -Wno-dollar-in-identifier-extension -ftemplate-depth=1024 -fconstexpr-depth=512>
)

add_subdirectory(test)
add_subdirectory(lib)