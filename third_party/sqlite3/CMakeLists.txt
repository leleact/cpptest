add_library(sqlite3 src/sqlite3.c)
if(UNIX)
    target_link_libraries(sqlite3 pthread dl)
endif(UNIX)

add_executable(sqlite3-bin src/shell.c)
set_target_properties(sqlite3-bin PROPERTIES OUTPUT_NAME sqlite3)
target_link_libraries(sqlite3-bin sqlite3)

add_library(sqlite3_header INTERFACE)
target_include_directories(sqlite3_header INTERFACE src)
