# 🚀 构建中文版 OpenVINO AI Plugins for Audacity

## 📋 系统要求

### 必需软件

1. **Visual Studio 2019 或 2022**
   - 下载：https://visualstudio.microsoft.com/downloads/
   - 需要安装 "使用 C++ 的桌面开发" 工作负载

2. **CMake 3.21+**
   - ✅ 已安装：cmake version 3.31.4

3. **Python 3.8+**
   - ✅ 已安装：Python 3.13.1

4. **Git**
   - 下载：https://git-scm.com/download/win

5. **Inno Setup 6**
   - 下载：https://jrsoftware.org/isdl.php#stable
   - 安装后添加到 PATH：
     ```cmd
     set Path="C:\Program Files (x86)\Inno Setup 6";%Path%
     ```

## 🔧 构建步骤

### 方法 1: 自动构建（推荐）

```cmd
cd tools\windows
fetch_build_package.bat
```

这个脚本会：
1. 下载所有依赖（约 3-4 GB）
2. 克隆 Audacity 和 whisper.cpp
3. 编译所有组件
4. 生成安装程序

**预计时间**: 1-2 小时（取决于网络速度和电脑性能）

### 方法 2: 手动构建

#### 步骤 1: 准备环境

```cmd
cd tools\windows
```

#### 步骤 2: 下载依赖

运行 `prereq.bat` 会自动下载：
- OpenVINO 2024.6
- LibTorch 2.4.1
- OpenCL SDK
- Audacity 3.7.1 源码
- whisper.cpp v1.6.0 源码

```cmd
prereq.bat
```

#### 步骤 3: 编译

```cmd
build.bat
```

#### 步骤 4: 打包

```cmd
package.bat
```

## 📦 构建输出

构建完成后，会在 `BuildArtifacts-YYYYMMDD_HHMMSS` 目录下生成：

```
BuildArtifacts-20241229_143022/
├── audacity-win-3.7.1-R4.2-64bit-OpenVINO-AI-Plugins-YYYYMMDD_HHMMSS.exe
├── audacity/                    # Audacity 源码
├── whisper.cpp/                 # whisper.cpp 源码
├── audacity-build/              # Audacity 编译输出
├── whisper-build-avx/           # whisper.cpp 编译输出（AVX）
├── whisper-build-no-avx/        # whisper.cpp 编译输出（无AVX）
├── libtorch/                    # LibTorch 库
├── w_openvino_toolkit_*/        # OpenVINO 工具包
└── OpenCL-SDK-*/                # OpenCL SDK
```

## 🌏 启用中文界面（可选）

如果你想在插件界面中也显示中文（不仅仅是安装程序），需要修改代码：

### 1. 修改 CMakeLists.txt

在 `mod-openvino/CMakeLists.txt` 中添加：

```cmake
# 启用中文本地化
add_definitions(-DENABLE_CHINESE_LOCALIZATION=1)
```

### 2. 修改源代码

在每个 `.cpp` 文件开头添加：

```cpp
#include "OVLocalization.h"
```

将字符串宏替换：

```cpp
// 原来的
XO("OpenVINO Music Separation")

// 改为
OV_XO("OpenVINO Music Separation")
```

详细说明请查看：`doc/汉化集成示例.md`

## 🐛 常见问题

### Q: 下载依赖失败？

A: 检查网络连接，或手动下载依赖包：
- LibTorch: https://download.pytorch.org/libtorch/cpu/libtorch-win-shared-with-deps-2.4.1%2Bcpu.zip
- OpenVINO: https://storage.openvinotoolkit.org/repositories/openvino/packages/2024.6/windows/

### Q: 编译失败？

A: 确保：
1. Visual Studio 已正确安装
2. 所有依赖都已下载
3. 有足够的磁盘空间（至少 20GB）

### Q: 找不到 Visual Studio？

A: 打开 "Developer Command Prompt for VS 2022"，然后在其中运行构建脚本。

### Q: Inno Setup 错误？

A: 确保 Inno Setup 已添加到 PATH：
```cmd
where iscc
```
应该显示 Inno Setup 的路径。

## 📊 构建资源需求

- **磁盘空间**: 至少 20GB
- **内存**: 建议 16GB+
- **网络**: 需要下载约 3-4GB
- **时间**: 1-2 小时

## 🎯 快速测试构建

如果你只想测试编译是否成功，可以：

1. 只编译 whisper.cpp：
   ```cmd
   cd BuildArtifacts-xxx\whisper-build-avx
   cmake --build . --config Release
   ```

2. 只编译 Audacity 插件：
   ```cmd
   cd BuildArtifacts-xxx\audacity-build
   cmake --build . --config Release
   ```

## 📝 构建日志

构建过程中的所有输出都会显示在控制台。如果需要保存日志：

```cmd
fetch_build_package.bat > build.log 2>&1
```

## 🔗 相关链接

- **官方构建说明**: tools/windows/README.md
- **中文用户指南**: doc/中文用户指南.md
- **汉化技术文档**: doc/CHINESE_LOCALIZATION.md
- **Intel 官方发布**: https://github.com/intel/openvino-plugins-ai-audacity/releases

## 💡 提示

1. **首次构建**: 需要下载大量依赖，请确保网络稳定
2. **增量构建**: 如果只修改了插件代码，可以只重新编译 Audacity
3. **清理构建**: 删除 `BuildArtifacts-*` 目录可以完全重新开始

## 🎉 构建成功后

1. 在 `BuildArtifacts-*` 目录找到生成的 `.exe` 安装程序
2. 运行安装程序，选择"简体中文"
3. 按照提示完成安装
4. 在 Audacity 中启用 mod-openvino 模块

---

**祝构建顺利！** 🚀

如有问题，请查看 `doc/中文用户指南.md` 或在 GitHub 提交 Issue。
