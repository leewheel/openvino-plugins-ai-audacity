# OpenVINO AI Plugins for Audacity 简体中文汉化指南

## 概述

本文档说明如何为 OpenVINO AI Plugins for Audacity 项目添加简体中文支持。

## 汉化内容

### 1. 安装程序汉化

安装程序已添加简体中文支持：

- **文件位置**: `tools/windows/ChineseSimplified.isl`
- **配置文件**: `tools/windows/audacity_ai_plugins.iss`

安装程序现在支持两种语言：
- English (英语)
- 简体中文

用户在安装时可以选择界面语言。

### 2. 插件界面汉化

#### 方案说明

由于 Audacity 插件使用 C++ 开发，并且使用 Audacity 的国际化框架（`XO()` 和 `XXO()` 宏），完整的界面汉化需要：

1. **创建翻译头文件** (已完成)
   - 文件位置：`mod-openvino/OVStringsChinese.h`
   - 包含所有功能模块的中文翻译映射

2. **修改源代码以使用翻译** (需要进一步实施)
   - 在每个 `.cpp` 文件中包含翻译头文件
   - 使用翻译函数替换硬编码字符串

#### 翻译内容覆盖

`OVStringsChinese.h` 包含以下模块的翻译：

1. **通用字符串** (`CommonStrings`)
   - 设备选择
   - 按钮文本
   - 错误消息
   - 加载提示

2. **音乐分离** (`MusicSeparationStrings`)
   - 分离模式选项
   - 音轨标签
   - 进度消息

3. **噪声抑制** (`NoiseSuppressionStrings`)
   - 模型选择
   - 参数说明
   - 状态消息

4. **Whisper 转录** (`WhisperTranscriptionStrings`)
   - 模型和模式选择
   - 语言选项
   - 高级参数

5. **音乐生成** (`MusicGenerationStrings`)
   - 生成参数
   - 设备配置
   - 续写选项

6. **超分辨率** (`SuperResolutionStrings`)
   - 模型类型
   - 设备配置
   - 处理参数

## 实施步骤

### 阶段 1: 安装程序汉化 ✅ (已完成)

- [x] 创建简体中文语言文件
- [x] 修改安装程序配置
- [x] 添加语言选择功能

### 阶段 2: 创建翻译资源 ✅ (已完成)

- [x] 创建 `OVStringsChinese.h` 翻译头文件
- [x] 翻译所有用户界面字符串
- [x] 翻译错误和状态消息

### 阶段 3: 集成翻译到源代码 (待实施)

要完全启用界面汉化，需要修改以下文件：

#### 3.1 音乐分离 (`OVMusicSeparation.cpp`)

```cpp
// 在文件开头添加
#include "OVStringsChinese.h"

// 修改字符串使用翻译
// 例如：
XO("OpenVINO Music Separation") 
// 改为：
XO(OVChinese::GetTranslation("OpenVINO Music Separation").c_str())
```

#### 3.2 噪声抑制 (`OVNoiseSuppression.cpp`)

类似的修改模式，使用 `OVChinese::GetTranslation()` 函数。

#### 3.3 Whisper 转录 (`OVWhisperTranscription.cpp`)

特别注意语言列表的翻译。

#### 3.4 音乐生成 (`OVMusicGenerationLLM.cpp`)

包含大量用户提示和状态消息。

#### 3.5 超分辨率 (`OVAudioSR.cpp`)

设备和参数配置界面。

### 阶段 4: 添加语言切换功能 (可选)

可以添加一个配置选项让用户选择界面语言：

```cpp
// 在配置文件中添加
enum class UILanguage {
    English,
    ChineseSimplified
};

// 根据用户选择返回相应翻译
```

## 使用方法

### 编译时启用中文支持

1. 确保 `OVStringsChinese.h` 在包含路径中
2. 在需要翻译的源文件中包含头文件：
   ```cpp
   #include "OVStringsChinese.h"
   ```
3. 使用翻译函数：
   ```cpp
   auto translated = OVChinese::GetTranslation("Original English Text");
   ```

### 安装程序语言选择

运行安装程序时，会提示选择语言：
- English
- 简体中文

选择简体中文后，安装界面将显示中文。

## 翻译质量保证

### 术语一致性

| 英文术语 | 中文翻译 | 说明 |
|---------|---------|------|
| Device | 设备 | 硬件设备 |
| Model | 模型 | AI 模型 |
| Inference | 推理 | AI 推理过程 |
| Encoder | 编码器 | 编码组件 |
| Decoder | 解码器 | 解码组件 |
| Stem | 轨 | 音轨分离 |
| Chunk | 块 | 数据块 |
| Seed | 随机种子 | 随机数生成器种子 |
| Guidance Scale | 引导比例 | AI 生成参数 |

### 翻译原则

1. **准确性**: 确保技术术语翻译准确
2. **一致性**: 相同术语在不同位置使用相同翻译
3. **简洁性**: 界面文本保持简洁明了
4. **本地化**: 符合中文用户习惯

## 测试

### 安装程序测试

1. 运行安装程序
2. 选择"简体中文"语言
3. 验证所有界面文本显示正确
4. 检查模型下载提示是否为中文

### 插件界面测试 (待实施后)

1. 在 Audacity 中启用插件
2. 测试每个功能模块：
   - 音乐分离
   - 噪声抑制
   - Whisper 转录
   - 音乐生成
   - 超分辨率
3. 验证所有界面元素显示中文
4. 检查错误消息是否正确翻译

## 贡献

欢迎改进翻译质量！如果您发现翻译问题或有更好的翻译建议：

1. 编辑 `mod-openvino/OVStringsChinese.h`
2. 更新相应的翻译映射
3. 提交 Pull Request

## 已知限制

1. **Audacity 核心界面**: 本汉化仅针对 OpenVINO 插件，Audacity 主程序界面需要单独汉化
2. **动态语言切换**: 当前需要重启 Audacity 才能切换语言
3. **部分硬编码文本**: 某些日志消息可能仍为英文

## 未来改进

- [ ] 实现运行时语言切换
- [ ] 添加繁体中文支持
- [ ] 创建自动化翻译测试
- [ ] 支持更多语言（日语、韩语等）
- [ ] 集成到 Audacity 的语言设置系统

## 技术细节

### 翻译系统架构

```
OVStringsChinese.h
├── CommonStrings (通用翻译)
├── MusicSeparationStrings (音乐分离)
├── NoiseSuppressionStrings (噪声抑制)
├── WhisperTranscriptionStrings (语音转录)
├── MusicGenerationStrings (音乐生成)
├── SuperResolutionStrings (超分辨率)
└── GetTranslation() (翻译查找函数)
```

### 集成方式

```cpp
// 原始代码
XO("OpenVINO Music Separation")

// 汉化后代码
#ifdef ENABLE_CHINESE_LOCALIZATION
    XO(OVChinese::GetTranslation("OpenVINO Music Separation").c_str())
#else
    XO("OpenVINO Music Separation")
#endif
```

## 联系方式

如有问题或建议，请在 GitHub 仓库提交 Issue：
https://github.com/intel/openvino-plugins-ai-audacity/issues

---

**最后更新**: 2024年
**维护者**: OpenVINO AI Plugins 社区
