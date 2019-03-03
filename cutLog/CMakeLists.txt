set(SOURCES main.cpp)

add_executable(cutLog ${SOURCES})

add_custom_command(TARGET cutLog POST_BUILD COMMAND bash test.sh)