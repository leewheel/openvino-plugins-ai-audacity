# OpenVINO™ AI Plugins for Audacity* 🎵

![updated_audacity_top_level](https://github.com/user-attachments/assets/f7c911db-fb98-43ff-972d-f66473b4c921)

[![License: GPL v3](https://img.shields.io/badge/License-GPL%20v3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0) [![Mentioned in Awesome OpenVINO](https://awesome.re/mentioned-badge-flat.svg)](https://github.com/openvinotoolkit/awesome-openvino)

[English](README.md) | 简体中文

为 [Audacity®](https://www.audacityteam.org/) 提供的一套 AI 功能插件。这些 AI 功能 100% 在您的电脑上本地运行 💻 —— 无需互联网连接！使用 [OpenVINO™](https://github.com/openvinotoolkit/openvino) 在用户系统上的 CPU、GPU 和 NPU 等支持的加速器上运行 AI 模型。

## ✨ 功能特性

- [**音乐分离**](doc/feature_doc/music_separation/README.md) 🎵 —— 将单声道或立体声音轨分离成独立的音轨：鼓、贝斯、人声和其他乐器
- [**噪声抑制**](doc/feature_doc/noise_suppression/README.md) 🧹 —— 从音频样本中去除背景噪声
- [**音乐生成与续写**](doc/feature_doc/music_generation/README.md) 🎼 —— 使用 MusicGen LLM 生成音乐片段，或生成现有音乐片段的续写
- [**Whisper 转录**](doc/feature_doc/whisper_transcription/README.md) 🎤 —— 使用 [whisper.cpp](https://github.com/ggerganov/whisper.cpp) 为选定的语音音频或人声生成包含转录或翻译的标签轨道
- [**超分辨率**](doc/feature_doc/super_resolution/README.md) ✨ —— 升频和增强音频，提升清晰度和细节

## 📥 安装

前往[这里](https://github.com/intel/openvino-plugins-ai-audacity/releases)查找最新 Windows 版本的安装包和说明。

### 快速安装步骤

1. 下载最新的安装程序
2. 运行安装程序，选择**简体中文**语言
3. 选择要安装的 AI 模型
4. 安装完成后，打开 Audacity
5. 进入：编辑 → 首选项 → 模块
6. 将 "mod-openvino" 设置为 "已启用"
7. 重启 Audacity

详细的中文安装和使用指南请查看：[中文用户指南](doc/中文用户指南.md)

## 🔧 构建说明

- [Windows 构建说明](doc/build_doc/windows/README.md)
- [Linux 构建说明](doc/build_doc/linux/README.md)

## 🌏 中文本地化

本项目已添加简体中文支持！

- **安装程序**: 支持中文界面
- **用户文档**: 提供完整的中文用户指南
- **翻译资源**: 包含所有功能模块的中文翻译

详细信息请查看：[中文本地化指南](doc/CHINESE_LOCALIZATION.md)

## 💡 使用示例

### 音乐分离
```
1. 选择一段音频
2. 效果 → OpenVINO Music Separation
3. 选择分离模式（2轨或4轨）
4. 点击"应用"
```

### 噪声抑制
```
1. 选择包含噪声的音频
2. 效果 → OpenVINO Noise Suppression
3. 选择模型（推荐 DeepFilterNet2）
4. 点击"应用"
```

### 音乐生成
```
1. 生成 → OpenVINO Music Generation
2. 输入提示词，例如："欢快的钢琴曲"
3. 设置时长和参数
4. 点击"生成"
```

### Whisper 转录
```
1. 选择语音音频
2. 分析 → OpenVINO Whisper Transcription
3. 选择模型和语言（支持中文）
4. 点击"应用"
```

### 超分辨率
```
1. 选择要增强的音频
2. 效果 → OpenVINO Super Resolution
3. 选择模型类型
4. 点击"应用"
```

## 🎯 系统要求

- **操作系统**: Windows 10/11 (64位)
- **Audacity**: 3.4.0 或更高版本
- **内存**: 至少 8GB RAM（推荐 16GB）
- **硬件加速器**: CPU、GPU 或 NPU

## 📚 文档

- [中文用户指南](doc/中文用户指南.md) - 完整的中文使用说明
- [中文本地化指南](doc/CHINESE_LOCALIZATION.md) - 汉化技术文档
- [功能文档](doc/feature_doc/) - 各功能的详细说明
- [构建文档](doc/build_doc/) - 编译和构建指南

## 🙋‍♂️ 帮助、反馈和问题报告

欢迎在[这里](https://github.com/intel/openvino-plugins-ai-audacity/issues)提交问题：
* 提问
* 错误报告
* 功能请求
* 任何类型的反馈 —— 我们如何改进这个项目？

## 🤝 贡献

欢迎您的贡献，无论大小！请随时提交 Pull Request！

详见：[贡献指南](CONTRIBUTING.md)

## 🙏 致谢与引用

* Audacity® 开发团队和 Muse Group —— 感谢您的支持！
* Audacity® GitHub —— https://github.com/audacity/audacity
* Whisper 转录和翻译分析器使用 whisper.cpp（带 OpenVINO™ 后端）：https://github.com/ggerganov/whisper.cpp
* 音乐生成和续写使用 Meta 的 MusicGen 模型
  - 我们目前支持 [MusicGen-Small](https://huggingface.co/facebook/musicgen-small) 和 [MusicGen-Small-Stereo](https://huggingface.co/facebook/musicgen-stereo-small)
  - 文本转音乐管道从 Python 移植到 C++，参考了 Hugging Face transformers 项目的逻辑：https://github.com/huggingface/transformers
* 音乐分离效果使用 Meta 的 Demucs v4 模型（https://github.com/facebookresearch/demucs），已移植以支持 OpenVINO™
* 噪声抑制：
  * noise-suppression-denseunet-ll：来自 OpenVINO™ 的 Open Model Zoo：https://github.com/openvinotoolkit/open_model_zoo
  * DeepFilterNet2 和 DeepFilterNet3：
    * 从这里移植模型和管道：https://github.com/Rikorose/DeepFilterNet
    * 我们还使用了 @grazder 的分支（https://github.com/grazder/DeepFilterNet/tree/torchDF-changes）来更好地理解 Rust 实现
    * 引用：
      ```bibtex
      @inproceedings{schroeter2022deepfilternet2,
      title = {{DeepFilterNet2}: Towards Real-Time Speech Enhancement on Embedded Devices for Full-Band Audio},
      author = {Schröter, Hendrik and Escalante-B., Alberto N. and Rosenkranz, Tobias and Maier, Andreas},
      booktitle={17th International Workshop on Acoustic Signal Enhancement (IWAENC 2022)},
      year = {2022},
      }
        
      @inproceedings{schroeter2023deepfilternet3,
      title = {{DeepFilterNet}: Perceptually Motivated Real-Time Speech Enhancement},
      author = {Schröter, Hendrik and Rosenkranz, Tobias and Escalante-B., Alberto N. and Maier, Andreas},
      booktitle={INTERSPEECH},
      year = {2023},
      }
      ```
* 超分辨率功能是此项目的移植（Python → C++，PyTorch → OpenVINO IR）：https://github.com/haoheliu/versatile_audio_super_resolution
  * 引用：
    ```bibtex
    @article{liu2023audiosr,
    title={{AudioSR}: Versatile Audio Super-resolution at Scale},
    author={Liu, Haohe and Chen, Ke and Tian, Qiao and Wang, Wenwu and Plumbley, Mark D},
    journal={arXiv preprint arXiv:2309.07314},
    year={2023}
    }
    ```
* [OpenVINO™ Notebooks](https://github.com/openvinotoolkit/openvino_notebooks) —— 我们从这个出色的 Python notebook 集合中学到了很多，并且仍在使用它来学习使用 OpenVINO™ 实现 AI 管道的最新/最佳实践！

## 📄 许可证

本项目采用 [GPL v3.0](LICENSE.txt) 许可证。

## 🌟 Star History

如果这个项目对您有帮助，请给我们一个 Star！⭐

---

**注意**: Audacity® 是 Audacity Team 的注册商标。本项目不隶属于 Audacity Team。
