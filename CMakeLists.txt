cmake_minimum_required(VERSION 3.22)
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

include(FetchContent)

FetchContent_Declare(nlohman URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(nlohman)


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
        ${H_UILOGIC_PATH}/Game/TutorialActivity.h
        ${H_UILOGIC_PATH}/Game/GameInfoWidget.h
        ${H_UILOGIC_PATH}/Game/GameFieldWidget.h
        ${H_UILOGIC_PATH}/Application.h
        headers/Model/Game/GameManager.h
        headers/Model/Game/Player.h
        headers/Model/Game/GameField.h
        headers/Model/DataTypes/File.h
        headers/Model/DataTypes/FieldStructure.h
        headers/Model/Game/Hex.h
        headers/UILogic/Game/TutorialWidget.h
        headers/my_geometry.h
        headers/UILogic/Game/HexView.h
        headers/UILogic/Game/VertexView.h
        headers/UILogic/Game/EdgeView.h
        headers/Model/Game/Room.h
        headers/UILogic/Hub/RoomChooseMenu.h
        headers/UIClasses/RoomItem.h
        sources/UILogic/Hub/RoomChooseMenu.cpp
        headers/Model/DataTypes/RoomFile.h
        headers/UIClasses/ScrollArea.h
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
        ${S_UILOGIC_PATH}/Game/TutorialActivity.cpp
        ${S_UILOGIC_PATH}/Game/GameInfoWidget.cpp
        ${S_UILOGIC_PATH}/Game/GameFieldWidget.cpp
        ${S_UILOGIC_PATH}/Application.cpp
        sources/Model/Game/GameManager.cpp
        sources/Model/Game/Player.cpp
        sources/Model/DataTypes/FieldStructure.cpp
        sources/Model/DataTypes/File.cpp
        sources/Model/Game/Hex.cpp
        sources/UILogic/Game/TutorialWidget.cpp
        sources/Model/Game/GameField.cpp
        sources/UILogic/Game/VertexView.cpp
        sources/Model/my_geometry.cpp
        sources/UILogic/Game/EdgeView.cpp
        sources/UILogic/Game/HexView.cpp
        sources/Model/Game/Room.cpp
        sources/UIClasses/RoomItem.cpp
        sources/Model/DataTypes/RoomFile.cpp
        sources/UILogic/Hub/RoomChooseMenu.cpp
        sources/UIClasses/ScrollArea.cpp
        sources/UILogic/Game/GameMenuWidget.cpp
)
add_executable( tp_project_fiodorkolotilin
        main.cpp
        ${SOURCE_FILES}
        ${HEADER_FILES}
)

#add_library(sources_lib ${SOURCES_FILES})
#add_library(headers_lib ${HEADER_FILES})
#set(RAPID_XML_PATH rapidxml-1.13)
#set(RAPID_XML
#        RAPID_XML_PATH/rapidxml.hpp
#        RAPID_XML_PATH/rapidxml_print.hpp
#)
#add_library(rapid_xml RAPID_XML_PATH/)

target_include_directories(tp_project_fiodorkolotilin PUBLIC
        rapidxml-1.13
        headers
        headers/UIClasses
        headers/Model
        headers/Model/AppData
        headers/Model/DataTypes
        headers/Model/Game
        headers/UILogic/Hub
        headers/UILogic/Game
        headers/UILogic/
        sources
        sources/UIClasses
        sources/Model
        sources/Model/DataTypes
        sources/Model/Game
        sources/Model/AppData
        sources/UILogic/Hub
        sources/UILogic/Game
        sources/UILogic/
)

#target_include_directories(sources_lib PUBLIC
#        headers
#        headers/UIClasses
#        headers/Model
#        headers/UILogic/Hub
#        headers/UILogic/Game
#        sources
#        sources/UIClasses
#        sources/Model
#        sources/UILogic/Hub
#        sources/UILogic/Game
#)
#target_include_directories(headers_lib PUBLIC
#        headers
#        headers/UIClasses
#        headers/Model
#        headers/Model/AppData
#        headers/Model/Game
#        headers/Model/DataTypes
#        headers/UILogic/Hub
#        headers/UILogic/Game
#        sources
#        sources/UIClasses
#        sources/Model
#        sources/Model/AppData
#        sources/Model/Game
#        sources/Model/DataTypes
#        sources/UILogic/Hub
#        sources/UILogic/Game
#)

target_link_libraries(tp_project_fiodorkolotilin PRIVATE
        nlohmann_json::nlohmann_json
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
#        sources_lib
#        headers_lib
#        rapid_xml
)

#target_link_libraries(foo PRIVATE nlohmann_json::nlohmann_json)
#target_link_libraries(headers_lib PRIVATE
#        nlohmann_json::nlohmann_json
#        Qt5::Core
#        Qt5::Gui
#        Qt5::Widgets
#)
