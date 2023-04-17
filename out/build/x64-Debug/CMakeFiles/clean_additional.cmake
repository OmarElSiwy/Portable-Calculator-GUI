# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\DesktopPortfolio_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\DesktopPortfolio_autogen.dir\\ParseCache.txt"
  "DesktopPortfolio_autogen"
  )
endif()
