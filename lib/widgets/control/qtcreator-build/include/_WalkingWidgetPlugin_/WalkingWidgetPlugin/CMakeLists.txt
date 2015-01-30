find_package(Qt4 REQUIRED QtCore QtGui QtOpengl QtDesigner)
include_directories(${QT_INCLUDE_DIR})
include_directories(${QT_QTCORE_INCLUDE_DIR})
include_directories(${QT_QTGUI_INCLUDE_DIR})
set(CMAKE_INCLUDE_CURRENT_DIR ON)

SET(MOC_HDRS
    WalkingWidgetPlugin.h
    WalkingWidgetPluginPlugin.h
)

SET(HDRS
    WalkingWidgetPlugin.h
)

FILE(GLOB SRCS
    *.cc
)

SET(QtApp_RCCS resources.qrc)
QT4_ADD_RESOURCES(QtApp_RCC_SRCS ${QtApp_RCCS})

rock_vizkit_widget(WalkingWidgetPlugin
    SOURCES ${SRCS} ${QtApp_RCC_SRCS} 
    HEADERS ${HDRS}
    MOC ${MOC_HDRS}
    DEPS_PKGCONFIG base-types base-lib QtCore QtGui widgets-charlie widgets-controls math NDLCom RobotConfig NDLCom-Qt kinematics-charlie register_qt widgets-controls widgets-common widgets-plotter serialcom udpcom representations protolog
    DEPS_CMAKE
    LIBS ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_QTOPENGL_LIBRARY} ${QT_QTDESIGNER_LIBRARY}
)
