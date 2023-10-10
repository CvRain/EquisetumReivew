# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/appEquisetumReview_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/appEquisetumReview_autogen.dir/ParseCache.txt"
  "appEquisetumReview_autogen"
  )
endif()
