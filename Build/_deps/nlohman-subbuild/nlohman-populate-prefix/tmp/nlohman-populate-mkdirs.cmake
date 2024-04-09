# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/fedorkolotilin/TP_Project/tp_project_fiodorkolotilin/Build/_deps/nlohman-src"
  "/home/fedorkolotilin/TP_Project/tp_project_fiodorkolotilin/Build/_deps/nlohman-build"
  "/home/fedorkolotilin/TP_Project/tp_project_fiodorkolotilin/Build/_deps/nlohman-subbuild/nlohman-populate-prefix"
  "/home/fedorkolotilin/TP_Project/tp_project_fiodorkolotilin/Build/_deps/nlohman-subbuild/nlohman-populate-prefix/tmp"
  "/home/fedorkolotilin/TP_Project/tp_project_fiodorkolotilin/Build/_deps/nlohman-subbuild/nlohman-populate-prefix/src/nlohman-populate-stamp"
  "/home/fedorkolotilin/TP_Project/tp_project_fiodorkolotilin/Build/_deps/nlohman-subbuild/nlohman-populate-prefix/src"
  "/home/fedorkolotilin/TP_Project/tp_project_fiodorkolotilin/Build/_deps/nlohman-subbuild/nlohman-populate-prefix/src/nlohman-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/fedorkolotilin/TP_Project/tp_project_fiodorkolotilin/Build/_deps/nlohman-subbuild/nlohman-populate-prefix/src/nlohman-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/fedorkolotilin/TP_Project/tp_project_fiodorkolotilin/Build/_deps/nlohman-subbuild/nlohman-populate-prefix/src/nlohman-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
