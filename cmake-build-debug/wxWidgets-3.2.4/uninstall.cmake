#############################################################################
# Name:        build/cmake/uninstall.cmake.in
# Purpose:     CMake uinstall template
# Author:      Tobias Taschner
# Created:     2016-10-18
# Copyright:   (c) 2016 wxWidgets development team
# Licence:     wxWindows licence
#############################################################################

if(NOT EXISTS "/Users/briankapusta/Documents/GitHub/Minesweeper Project/Minesweeper-Project/cmake-build-debug/wxWidgets-3.2.4/install_manifest.txt")
  message(FATAL_ERROR "Cannot find install manifest: /Users/briankapusta/Documents/GitHub/Minesweeper Project/Minesweeper-Project/cmake-build-debug/wxWidgets-3.2.4/install_manifest.txt")
endif()

file(READ "/Users/briankapusta/Documents/GitHub/Minesweeper Project/Minesweeper-Project/cmake-build-debug/wxWidgets-3.2.4/install_manifest.txt" files)
string(REGEX REPLACE "\n" ";" files "${files}")
list(APPEND files /usr/local/bin/wx-config;/usr/local/bin/wxrc)
foreach(file ${files})
  message(STATUS "Uninstalling $ENV{DESTDIR}${file}")
  if(IS_SYMLINK "$ENV{DESTDIR}${file}" OR EXISTS "$ENV{DESTDIR}${file}")
    exec_program(
      "/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake" ARGS "-E remove \"$ENV{DESTDIR}${file}\""
      OUTPUT_VARIABLE rm_out
      RETURN_VALUE rm_retval
      )
    if(NOT "${rm_retval}" STREQUAL 0)
      message(FATAL_ERROR "Problem when removing $ENV{DESTDIR}${file}")
    endif(NOT "${rm_retval}" STREQUAL 0)
  else()
    message(STATUS "File $ENV{DESTDIR}${file} does not exist.")
  endif()
endforeach(file)
