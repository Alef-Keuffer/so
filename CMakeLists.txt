cmake_minimum_required(VERSION 3.17)
project(so C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_STATIC_LIBRARY_PREFIX "")

add_library(Lib SHARED Lib/pid.c)
file(GLOB LIB "Lib/*.h" "Lib/*.c")
include_directories(Lib)
# ---------------------------------------------------------------------------------------------------
# From https://stackoverflow.com/questions/52666330/cmake-for-each-source-file-one-executable
file(GLOB_RECURSE my_c_list RELATIVE ${CMAKE_SOURCE_DIR} "src/*/*.c")

foreach(file_path ${my_c_list})
    string( REPLACE ".c" "" new_name ${file_path} )
    get_filename_component(filename ${new_name} NAME)
    add_executable( ${filename} ${file_path} ${LIB})
endforeach()
# ---------------------------------------------------------------------------------------------------
# ---------------------------------------------------------------------------------------------------
# From https://stackoverflow.com/questions/1706346/file-macro-manipulation-handling-at-compile-time
function(define_file_basename_for_sources targetname)
    get_target_property(source_files "${targetname}" SOURCES)
    foreach (sourcefile ${source_files})
        # Add the FILE_BASENAME=filename compile definition to the list.
        get_filename_component(basename "${sourcefile}" NAME_WE) #Was NAME before
        # Set the updated compile definitions on the source file.
        set_property(
                SOURCE "${sourcefile}" APPEND
                PROPERTY COMPILE_DEFINITIONS "__FILENAME__=${basename}")
    endforeach ()
endfunction()
# ---------------------------------------------------------------------------------------------------
function(add_library_avoid_main_name_conflict target_name mode)
    add_library(${target_name} ${mode} ${ARGN})
    define_file_basename_for_sources(${target_name})
    target_compile_definitions(${target_name} PRIVATE -Dmain=__FILENAME__)
endfunction()

file(GLOB FICHA2 "src/Ficha2/*.c" "src/Ficha2/*.h")
file(GLOB FICHA3 "src/Ficha3/*.c" "src/Ficha3/*.h")
file(GLOB FICHA4 "src/Ficha4/*.c" "src/Ficha4/*.h")


# Main
add_executable(so1 main.c ficha2.c ${LIB})

add_library_avoid_main_name_conflict(fichas SHARED ${FICHA2} ${FICHA3} ${LIB})