cmake_minimum_required(VERSION 3.14)

if (WIN32)
    project(CompetitionUI LANGUAGES CXX)
elseif(UNIX)
    project(CompetitionUI)
endif()

#======================= INCLUSION OF Qt =======================#
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH $ENV{QTDIR})
find_package(Qt6Core REQUIRED)
find_package(Qt6Widgets REQUIRED)
find_package(Qt6Gui REQUIRED)

#=================== INCLUSION OF Project Files ====================#
set(FORMS_DIR "${CMAKE_SOURCE_DIR}/Libs")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")

include_directories(${FORMS_DIR})
include_directories(${INCLUDE_DIR})
include_directories(${SOURCE_DIR})

file(GLOB_RECURSE SOURCES
    "${FORMS_DIR}/*.ui"
    "${FORMS_DIR}/*.qrc"
    "${INCLUDE_DIR}/*.h"
    "${SOURCE_DIR}/*.cpp"
)

#=================== SETUP EXECTUABLE ====================#

# Add the forms directory to the AUTOUIC search paths
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_AUTOUIC_SEARCH_PATHS} ${FORMS_DIR})

# Add the executable
if (WIN32) 
    add_executable(CompetitionUI WIN32 ${SOURCES})
elseif(UNIX)
    add_executable(CompetitionUI ${SOURCES})
endif()

# Add the target includes for MY_PROJECT 
target_include_directories(CompetitionUI PRIVATE ${FORMS_DIR})
target_include_directories(CompetitionUI PRIVATE ${INCLUDE_DIR})
target_include_directories(CompetitionUI PRIVATE ${SOURCE_DIR})

#===================== LINKING LIBRARIES =======================#
target_link_libraries(CompetitionUI Qt6::Widgets)
target_link_libraries(CompetitionUI Qt6::Core)
target_link_libraries(CompetitionUI Qt6::Gui)