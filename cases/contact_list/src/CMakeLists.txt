add_library(ContactListLib STATIC
    lib/menu.cpp
    lib/contact.cpp
)

target_include_directories(ContactListLib PUBLIC ${CMAKE_SOURCE_DIR}/src/include)

add_executable(ContactListExecutable main.cpp)

target_link_libraries(ContactListExecutable PRIVATE ContactListLib)
