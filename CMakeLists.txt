cmake_minimum_required(VERSION 3.14)

if (WIN32)
    project(MY_PROJECT LANGUAGES CXX)
elseif(UNIX)
    project(DesktopPortfolio)
endif()

set(CMAKE_CONFIGURATION_TYPES "Release;RelWithDebInfo" CACHE STRING "" FORCE)

#======================= INCLUSION OF Qt =======================#
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH $ENV{QTDIR})
find_package(Qt6 COMPONENTS REQUIRED Core Widgets Gui)

if(NOT Qt6_FOUND)
  include(ExternalProject)
  ExternalProject_Add(qt-libraries
    GIT_REPOSITORY https://github.com/qt/qtbase.git
    GIT_TAG 6.2.0
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/third_party/qt
  )
  set(CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR}/third_party/qt/lib/cmake/Qt6)
  find_package(Qt6 COMPONENTS Gui Core REQUIRED)
endif()

#=================== INCLUSION OF Project Files ====================#
set(FORMS_DIR "${CMAKE_SOURCE_DIR}/Assets")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/CPP/include")
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/CPP/src")

include_directories(${FORMS_DIR})
include_directories(${INCLUDE_DIR})
include_directories(${SOURCE_DIR})

file(GLOB_RECURSE SOURCES
    "${FORMS_DIR}/*.ui"
    "${FORMS_DIR}/*.qss"
    "${FORMS_DIR}/*.qrc"
    "${INCLUDE_DIR}/*.h"
    "${SOURCE_DIR}/*.cpp"
)

#=================== SETUP EXECTUABLE ====================#
# Enable debug logging on RELWITHDEBINFO configuration
set_property(DIRECTORY APPEND PROPERTY COMPILE_DEFINITIONS
    $<$<CONFIG:RELWITHDEBINFO>:QT_MESSAGELOGCONTEXT>
)

# Add the forms directory to the AUTOUIC search paths
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_AUTOUIC_SEARCH_PATHS} ${FORMS_DIR})

# Add the executable
if (WIN32)
    add_executable(DesktopPortfolio WIN32 ${SOURCES})
elseif(UNIX)
    add_executable(DesktopPortfolio ${SOURCES})
endif()

# Add the target includes for MY_PROJECT
target_include_directories(DesktopPortfolio PRIVATE ${FORMS_DIR})
target_include_directories(DesktopPortfolio PRIVATE ${INCLUDE_DIR})
target_include_directories(DesktopPortfolio PRIVATE ${SOURCE_DIR})

#===================== LINKING LIBRARIES =======================#
target_link_libraries(DesktopPortfolio Qt6::Widgets Qt6::Core Qt6::Gui)
