set(SOURCES main.cpp)

add_executable(square ${SOURCES})

add_custom_command(TARGET square POST_BUILD COMMAND bash test.sh)