project(mylib)

set (HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set (SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(HEADERS
    ${HEADER_DIR}/MyVector.h
    ${HEADER_DIR}/MyArray.h
    ${HEADER_DIR}/MyMatrix.h
    ${HEADER_DIR}/MyList.h
    ${HEADER_DIR}/MyIntrusiveList.h
    ${HEADER_DIR}/MyNDimVector.h
)

set(SOURCES
    ${SOURCE_DIR}/MyAlgo.cpp
)

add_library(${PROJECT_NAME}
STATIC
    ${SOURCES}
    ${HEADERS}
)

target_include_directories(${PROJECT_NAME}
PUBLIC 
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${HEADER_DIR}>
)

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "Libraries")

