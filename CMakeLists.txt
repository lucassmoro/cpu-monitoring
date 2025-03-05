cmake_minimum_required(VERSION 3.10)
project(cpu-monitoring)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(cpu-monitoring
    WIN32 MACOSX_BUNDLE
    src/main.cpp
    src/monitor.cpp
    src/mainwindow.ui
)

target_link_libraries(cpu-monitoring
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS cpu-monitoring
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET cpu-monitoring
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})