cmake_minimum_required(VERSION 3.28)
project(2d-roguelike LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.1.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(${PROJECT_NAME} src/main.cpp "src/Base/GameObjectBase.h" "src/Components/Base/ComponentBase.h" "src/Components/Debug/DebugComp.cpp" "src/Components/Base/ComponentBase.cpp" "src/Components/Base/GameObjectComponent.cpp" "src/Components/Movement/BasicMovement.h" "src/Components/Movement/BasicMovement.cpp" "src/Components/Units/BaseUnit.h" "src/Components/Units/BaseUnit.cpp" "src/Components/Encounters/Encounter.h" "src/Components/Encounters/UnitHolder.h" "src/Components/Encounters/Encounter.cpp" "src/Deprecated/mainDEP.cpp" "src/Components/Drawer/SpriteDrawerBasic.h" "src/Components/Drawer/SpriteDrawerBasic.cpp" "src/Components/Base/UpdateData.h")
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_link_libraries(${PROJECT_NAME} PRIVATE SFML::Graphics)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy_directory
                     "${CMAKE_SOURCE_DIR}/assets" "$<TARGET_FILE_DIR:${PROJECT_NAME}>/assets")