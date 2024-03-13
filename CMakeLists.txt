cmake_minimum_required(VERSION 3.27)
project(tp_project_fiodorkolotilin)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)


set(H_UICLASSES_PATH headers/UIClasses)
set(H_UILOGIC_PATH headers/UILogic)
set(S_UICLASSES_PATH sources/UIClasses)
set(S_UILOGIC_PATH sources/UILogic)

set(HEADER_FILES
        ${H_UICLASSES_PATH}/View.h
        ${H_UICLASSES_PATH}/Widget.h
        ${H_UICLASSES_PATH}/TextWidget.h
        ${H_UICLASSES_PATH}/Button.h
        ${H_UICLASSES_PATH}/Activity.h
        ${H_UILOGIC_PATH}/Hub/MainMenu.h
        ${H_UILOGIC_PATH}/Hub/StartActivity.h
        ${H_UILOGIC_PATH}/Hub/PlayMenu.h
)
set(SOURCE_FILES
        ${S_UICLASSES_PATH}/View.cpp
        ${S_UICLASSES_PATH}/Widget.cpp
        ${S_UICLASSES_PATH}/TextWidget.cpp
        ${S_UICLASSES_PATH}/Button.cpp
        ${S_UICLASSES_PATH}/Activity.cpp
        ${S_UILOGIC_PATH}/Hub/MainMenu.cpp
        ${S_UILOGIC_PATH}/Hub/StartActivity.cpp
        ${S_UILOGIC_PATH}/Hub/PlayMenu.cpp
)
add_executable(tp_project_fiodorkolotilin
        main.cpp
)

add_library(sources_lib ${SOURCES_FILES})
add_library(headers_lib ${HEADER_FILES})

target_include_directories(tp_project_fiodorkolotilin PUBLIC
        headers
        headers/UIClasses
        headers/Model
        headers/UILogic/Hub
        headers/UILogic/Game
        sources
        sources/UIClasses
        sources/Model
        sources/UILogic/Hub
        sources/UILogic/Game
)

target_include_directories(sources_lib PUBLIC
        headers
        headers/UIClasses
        headers/Model
        headers/UILogic/Hub
        headers/UILogic/Game
        sources
        sources/UIClasses
        sources/Model
        sources/UILogic/Hub
        sources/UILogic/Game
)
target_include_directories(headers_lib PUBLIC
        headers
        headers/UIClasses
        headers/Model
        headers/UILogic/Hub
        headers/UILogic/Game
        sources
        sources/UIClasses
        sources/Model
        sources/UILogic/Hub
        sources/UILogic/Game
)

target_link_libraries(tp_project_fiodorkolotilin
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        sources_lib
        headers_lib
)
target_link_libraries(headers_lib
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)
