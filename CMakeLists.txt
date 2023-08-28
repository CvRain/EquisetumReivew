cmake_minimum_required(VERSION 3.16)

project(EquisetumReivew VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

set(QML_MODULE  modules/Main.qml
                modules/SlideIcon.qml
            modules/MenuButton.qml)
set(SRC src/main.cpp)

qt6_add_resources(QRC_FILES res/resource.qrc)

qt_add_executable(appEquisetumReivew
    ${SRC} ${QRC_FILES}
)

qt_add_qml_module(appEquisetumReivew
    URI EquisetumReivew
    VERSION 1.0
    QML_FILES ${QML_MODULE}
    RESOURCES res/resource.qrc

)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appEquisetumReivew PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appEquisetumReivew
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appEquisetumReivew
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appEquisetumReivew
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

target_compile_features(appEquisetumReivew PRIVATE cxx_std_20)
