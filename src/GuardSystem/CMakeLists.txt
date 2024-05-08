cmake_minimum_required(VERSION 3.5)

project(GuardSystem VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Network)


find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

set(TS_FILES GuardSystem_zh_TW.ts)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        workbench.h
        workbench.cpp
        workbench.ui
        regform.h
        regform.cpp
        regform.ui
        maildialog.h
        maildialog.cpp
        maildialog.ui
        mythread.h
        mythread.cpp
        myserver.h
        myserver.cpp
        serverthread.h
        serverthread.cpp
        ${TS_FILES}
)
find_package(Qt6 REQUIRED COMPONENTS Sql)
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(GuardSystem
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
target_link_libraries(GuardSystem PRIVATE Qt6::Sql)
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET GuardSystem APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(GuardSystem SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(GuardSystem
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(GuardSystem PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(GuardSystem PRIVATE Qt6::Network)
set_target_properties(GuardSystem PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS GuardSystem
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(GuardSystem)
endif()
