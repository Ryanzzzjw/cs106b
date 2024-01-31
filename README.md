## CS106b 2022 winter

平台： MacBook M1 pro

环境配置：QT 6.2.4 (6.6编译旧的cs106b报错，最新的cs106b不兼容旧的课程)

出现问题：

1. 在Mac上编译cs106b库时出现failed to parse default search paths from compiler output错误。解决方法：前往https://codereview.qt-project.org/c/qt/qtbase/+/506653/2/mkspecs/features/toolchain.prf 下载新的toolchain.prf替换原文件(Qt/6.2.4/macos/mkspecs/features)
2. 若编译使用Apple Clang会报错，使用clang arm64解决