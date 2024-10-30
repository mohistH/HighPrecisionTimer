cmake_minimum_required(VERSION 3.20)
project(HighPrecisionTimerDemo)

# 1. 打开允许创建文件夹的开关
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# 调用cmake的一些环境配置
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/environment.cmake)
CHECK_EXISTS(${QT_INSTALL_ROOT})

# 有这么多的第三方库需要设置到 CMAKE_PREFIX_PATH, 这里， QT_INSTALL_ROOT 来自 local.cmake文件中
set(CMAKE_PREFIX_PATH ${QT_INSTALL_ROOT})
# 设置开启QT所必须的开关
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# 设置项目输出路径
SET_PROJECT_OUTPUT(${CMAKE_SOURCE_DIR}/publish)

# 第三方库路径
set(CMAKE_PREFIX_PATH
${CMAKE_PREFIX_PATH} 
)

add_subdirectory("HighPrecisionTimerDemo")


# 2. 把工程加到文件夹中
# set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "CMakeTargets")
# 3. 给 cmake 自动创建的工程重新命名, 默认名为 "CMakePredefinedTargets" 
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMakeTargets")
