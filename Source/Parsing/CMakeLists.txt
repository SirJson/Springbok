set(H_FILES ConfigFile.h UTF8.h UTF8_Templates.hpp Unicode.h StringParser.h StringParser_Templates.hpp)
set(CPP_FILES ConfigFile.cpp UTF8.cpp StringParser.cpp)
add_library(sbParsing OBJECT ${H_FILES} ${CPP_FILES})

set_property(TARGET sbParsing PROPERTY OBJ_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set_property(TARGET sbParsing PROPERTY OBJ_INSTALL_HEADERS ${H_FILES})
set_property(TARGET sbParsing PROPERTY OBJ_INSTALL_LOCATION Parsing)

ADD_SSTEST_FILE(SpringbokTest UTF8_Tests.cpp StringParser_Tests.cpp ConfigFile_Tests.cpp)