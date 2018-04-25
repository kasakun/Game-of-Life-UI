
if (NOT EXISTS "/home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/include/glfw/install_manifest.txt")
  message(FATAL_ERROR "Cannot find install manifest: \"/home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/include/glfw/install_manifest.txt\"")
endif()

file(READ "/home/chenzy/Desktop/Code/C++/Game-of-Life-UI/cmake-build-debug/include/glfw/install_manifest.txt" files)
string(REGEX REPLACE "\n" ";" files "${files}")

foreach (file ${files})
  message(STATUS "Uninstalling \"$ENV{DESTDIR}${file}\"")
  if (EXISTS "$ENV{DESTDIR}${file}")
    exec_program("/home/chenzy/clion/bin/cmake/bin/cmake" ARGS "-E remove \"$ENV{DESTDIR}${file}\""
                 OUTPUT_VARIABLE rm_out
                 RETURN_VALUE rm_retval)
    if (NOT "${rm_retval}" STREQUAL 0)
      MESSAGE(FATAL_ERROR "Problem when removing \"$ENV{DESTDIR}${file}\"")
    endif()
  elseif (IS_SYMLINK "$ENV{DESTDIR}${file}")
    EXEC_PROGRAM("/home/chenzy/clion/bin/cmake/bin/cmake" ARGS "-E remove \"$ENV{DESTDIR}${file}\""
                 OUTPUT_VARIABLE rm_out
                 RETURN_VALUE rm_retval)
    if (NOT "${rm_retval}" STREQUAL 0)
      message(FATAL_ERROR "Problem when removing symlink \"$ENV{DESTDIR}${file}\"")
    endif()
  else()
    message(STATUS "File \"$ENV{DESTDIR}${file}\" does not exist.")
  endif()
endforeach()

