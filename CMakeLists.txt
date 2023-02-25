cmake_minimum_required(VERSION 3.5)

project(OtusHomework_6_Matrix- LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(OtusHomework_6_Matrix-
    main.cpp
    Matrix.hpp
)

install(TARGETS OtusHomework_6_Matrix-
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_FILE_NAME   "${CMAKE_PROJECT_NAME}")
set(CPACK_PACKAGE_CONTACT 9mrsmit6@gmail.com)
include(CPack)

