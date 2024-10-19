cmake_minimum_required(VERSION 3.29)

project(LutandoComDragons)

add_executable (LutandoComDragons "LutandoComDragons.cpp")

set_property(TARGET LutandoComDragons PROPERTY CXX_STANDARD 20)

target_compile_options(LutandoComDragons PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -pedantic -pedantic-errors -Werror -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-private-field -Wno-unused-const-variable -Wno-unused-value -Wno-unused-local-typedefs -Wno-unknown-attributes -Wno-ignored-attributes -Wno-c99-extensions -Wno-overlength-strings -Wno-missing-field-initializers -Wno-missing-braces -Wno-c++11-narrowing -Wno-address-of-packed-member -Wno-dollar-in-identifier-extension -ftemplate-depth=1024 -fconstexpr-depth=512>
)

add_subdirectory(test)
add_subdirectory(lib)