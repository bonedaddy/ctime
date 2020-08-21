file(GLOB_RECURSE CTIME_SOURCES
    ./include/*.h
    ./src/*.c
)
add_library(ctime 
    SHARED 
        ${CTIME_SOURCES}
)
target_compile_options(ctime PRIVATE ${flags})

add_executable(ctime-test-c ./tests/ctime_test.c)
add_executable(ctime-test-cpp ./tests/ctime_test.cpp)

target_compile_options(ctime-test-c PRIVATE ${flags})
target_link_libraries(ctime-test-c ctime)
target_link_libraries(ctime-test-c cmocka)
add_test(NAME CtimeTestC COMMAND ctime-test-c)

target_compile_options(ctime-test-cpp PRIVATE ${cxx-flags})
target_link_libraries(ctime-test-cpp ctime)
add_test(NAME CtimeTestCpp COMMAND ctime-test-cpp)