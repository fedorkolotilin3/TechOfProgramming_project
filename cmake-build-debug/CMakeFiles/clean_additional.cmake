# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/sources_lib_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/sources_lib_autogen.dir/ParseCache.txt"
  "CMakeFiles/tp_project_fiodorkolotilin_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/tp_project_fiodorkolotilin_autogen.dir/ParseCache.txt"
  "sources_lib_autogen"
  "tp_project_fiodorkolotilin_autogen"
  )
endif()
