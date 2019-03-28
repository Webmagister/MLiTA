set(SOURCES main.cpp)

add_executable(moneyExchange ${SOURCES})

#add_custom_command(TARGET moneyExchange POST_BUILD COMMAND bash test.sh)