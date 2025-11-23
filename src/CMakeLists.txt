file(GLOB ENGINE_SRC
    core/*.cpp
)

add_executable(motor
    ${ENGINE_SRC}
    main.cpp
)

target_include_directories(motor PUBLIC
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/external/glad/include
    ${CMAKE_SOURCE_DIR}/external/imgui
    ${CMAKE_SOURCE_DIR}/external/imgui/backends
)

target_link_libraries(motor
    glfw
    glad
    imgui
    dl
    pthread
    GL
)
