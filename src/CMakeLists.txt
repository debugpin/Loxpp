add_executable(loxpp
		lox.cpp
    scanner.cpp
    token.cpp
)

target_include_directories(loxpp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
