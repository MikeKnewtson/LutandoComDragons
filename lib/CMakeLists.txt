project(DragonLib)

add_library(DragonLib INTERFACE)
target_include_directories(DragonLib INTERFACE .)

set_property(TARGET DragonLib PROPERTY CXX_STANDARD 20)