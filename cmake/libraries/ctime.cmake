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

target_compile_options(ctime-test-c PRIVATE ${flags})
target_link_libraries(ctime-test-c ctime)
add_test(NAME CtimeTestC COMMAND ctime-test-c)