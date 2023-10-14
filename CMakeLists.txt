cmake_minimum_required(VERSION 3.16)

project(EquisetumReview VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
#set(CMAKE_TOOLCHAIN_FILE /mnt/Workspace/DevKit/vcpkg/scripts/buildsystems/vcpkg.cmake)

find_package(Qt6 6 REQUIRED COMPONENTS Quick)
find_package(jsoncpp CONFIG REQUIRED)
find_package(leveldb CONFIG REQUIRED)
find_package(loguru CONFIG REQUIRED)

qt_standard_project_setup(REQUIRES 6.5)

set(QML_MODULE modules/Main.qml
        modules/SlideIcon.qml
        modules/MenuButton.qml
        modules/SlideBar.qml
        modules/SlideContext.qml
)

set(SRC src/main.cpp
        src/json_maker.cpp
        src/json_maker.h
        src/base_db_operator.cpp
        src/base_db_operator.h
        src/db_notice_operator.cpp
        src/db_notice_operator.h
        src/db_todo_operator.cpp
        src/db_todo_operator.h
        src/id_generator.cpp
        src/id_generator.h)


set(QRC_FILES res/resource.qrc)

qt_add_executable(appEquisetumReview
        ${SRC}
        ${QRC_FILES}
)

qt_add_resources(appEquisetumReview
        FILES ${QRC_FILES}
)

qt_add_qml_module(appEquisetumReview
        URI EquisetumReview
        VERSION 1.0
        QML_FILES ${QML_MODULE}
        RESOURCES ${QRC_FILES}
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appEquisetumReview PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appEquisetumReview
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appEquisetumReview
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS ${RPOJECT_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

target_link_libraries(appEquisetumReview PRIVATE JsonCpp::JsonCpp leveldb::leveldb loguru)
target_compile_features(appEquisetumReview PRIVATE cxx_std_20)
