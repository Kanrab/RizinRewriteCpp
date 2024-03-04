cmake_minimum_required(VERSION 3.25)
project(RizinRewriteCpp CXX)

find_package(fmt REQUIRED)
find_package(capstone REQUIRED)

add_executable(rizin_rewrite_cpp)

add_subdirectory(RizinRewriteCpp)

target_include_directories(rizin_rewrite_cpp PUBLIC ${CMAKE_SOURCE_DIR}/BinaryLoader/include)

target_compile_options(rizin_rewrite_cpp PRIVATE
    $<$<CONFIG:Debug>:
        -fsanitize=address,leak,undefined 
        -pedantic 
        -Wall 
        -Wextra 
        -Wconversion 
        -Wundef 
        -Werror  
        -Wno-unused-parameter
        -Wno-unused-variable
    >
)

target_link_options(rizin_rewrite_cpp PRIVATE
    $<$<CONFIG:Debug>:
        -fsanitize=address,leak,undefined
    >
)

set_target_properties(rizin_rewrite_cpp PROPERTIES 
    CXX_STANDARD 20
)

target_link_libraries(rizin_rewrite_cpp PRIVATE
    fmt::fmt
    capstone::capstone
    gvc
    cgraph
    cdt
)
