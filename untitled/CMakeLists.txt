project(untitled)
cmake_minimum_required(VERSION 2.8)

find_package(Qt4 REQUIRED QtCore QtGui)
include(${QT_USE_FILE})

SET(ENV{PKG_CONFIG_PATH} ${CMAKE_BINARY_DIR}:$ENV{PKG_CONFIG_PATH})

find_package(PkgConfig)
pkg_check_modules(${PROJECT_NAME}_PKGCONFIG REQUIRED
widgets-plotter
register_qt
protolog
math
widgets-charlie
widgets-controls
NDLCom
RobotConfig
NDLCom-Qt
kinematics-charlie
register_qt
widgets-controls
widgets-common
widgets-plotter
serialcom
udpcom
representations
protolog
WalkingWidgetPlugin
)

include_directories(${${PROJECT_NAME}_PKGCONFIG_INCLUDE_DIRS})
link_directories(${${PROJECT_NAME}_PKGCONFIG_LIBRARY_DIRS})
add_definitions(${${PROJECT_NAME}_PKGCONFIG_CFLAGS_OTHER})

aux_source_directory(. SRC_LIST)
#qt4_wrap_cpp(HEADERS_lib_MOC ${SRC_LIST})

add_executable(${PROJECT_NAME} ${SRC_LIST})
TARGET_LINK_LIBRARIES(${PROJECT_NAME}
${QT_LIBRARIES}
#${${PROJECT_NAME}_PKGCONFIG_LIBRARIES}
${${PROJECT_NAME}_PKGCONFIG_STATIC_LIBRARIES}
#${${PROJECT_NAME}_PKGCONFIG_STATIC_LIBRARY}
)

