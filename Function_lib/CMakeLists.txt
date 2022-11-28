project(Function_lib)

set(HEADER_FILES
        Function.h
        )

set(SOURCE_FILES
        Function.cpp
        )

add_library(Function_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})