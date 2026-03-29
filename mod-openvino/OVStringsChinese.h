// Copyright (C) 2024 Intel Corporation
// SPDX-License-Identifier: GPL-3.0-only
// 简体中文翻译文件

#pragma once

#include <map>
#include <string>

// 简体中文翻译映射表
namespace OVChinese {

    // 通用翻译
    inline const std::map<std::string, std::string> CommonStrings = {
        // 设备相关
        {"OpenVINO Inference Device:", "OpenVINO 推理设备:"},
        {"Device Details...", "设备详情..."},
        {"OpenVINO Device Details", "OpenVINO 设备详情"},
        {"Compiling AI Model...", "正在编译 AI 模型..."},
        {"Loading", "正在加载"},
        {"AI Model", "AI 模型"},
        {"AI Models", "AI 模型"},
        
        // 高级选项
        {"&Advanced Options", "高级选项(&A)"},
        {"Advanced Options", "高级选项"},
        
        // 按钮
        {"Unload Models", "卸载模型"},
        {"Apply", "应用"},
        {"Cancel", "取消"},
        {"OK", "确定"},
        
        // 错误信息
        {"Error", "错误"},
        {"failed", "失败"},
        {"See details in Help->Diagnostics->Show Log...", "详情请查看 帮助->诊断->显示日志..."},
        
        // 供应商
        {"OpenVINO AI Effects", "OpenVINO AI 特效"},
        
        // 设备加载消息
        {"This could take a while if this is the first time running this feature with this device", 
         "如果这是首次在此设备上运行此功能，可能需要一些时间"}
    };

    // 音乐分离翻译
    inline const std::map<std::string, std::string> MusicSeparationStrings = {
        {"OpenVINO Music Separation", "OpenVINO 音乐分离"},
        {"Splits a stereo track into 4 new tracks -- Bass, Drums, Vocals, Others", 
         "将立体声音轨分离为 4 个新音轨 -- 贝斯、鼓、人声、其他乐器"},
        {"Separation Mode:", "分离模式:"},
        {"(2 Stem) Instrumental, Vocals", "(2 轨) 伴奏、人声"},
        {"(4 Stem) Drums, Bass, Vocals, Others", "(4 轨) 鼓、贝斯、人声、其他"},
        {"Shifts", "偏移次数"},
        {"Applying Music Separation using OpenVINO", "正在使用 OpenVINO 进行音乐分离"},
        {"Loading Music Separation AI Model to", "正在加载音乐分离 AI 模型到"},
        {"Music Separation failed", "音乐分离失败"},
        {"-Drums", "-鼓"},
        {"-Bass", "-贝斯"},
        {"-Vocals", "-人声"},
        {"-Other Instruments", "-其他乐器"},
        {"-Instrumental", "-伴奏"}
    };

    // 噪声抑制翻译
    inline const std::map<std::string, std::string> NoiseSuppressionStrings = {
        {"OpenVINO Noise Suppression", "OpenVINO 噪声抑制"},
        {"Applies AI Background Noise Suppression using OpenVINO", 
         "使用 OpenVINO 应用 AI 背景噪声抑制"},
        {"Noise Suppression Model:", "噪声抑制模型:"},
        {"Attenuation Limit(dB)", "衰减限制(分贝)"},
        {"100 means no attenuation limit (full noise suppression)\nFor little noise reduction, set to 6 - 12.\nFor medium, 18 - 24.",
         "100 表示无衰减限制（完全噪声抑制）\n轻度降噪，设置为 6 - 12\n中度降噪，设置为 18 - 24"},
        {"Post Filter Beta", "后置滤波器 Beta"},
        {"Noise Suppression failed", "噪声抑制失败"}
    };

    // Whisper 转录翻译
    inline const std::map<std::string, std::string> WhisperTranscriptionStrings = {
        {"OpenVINO Whisper Transcription", "OpenVINO Whisper 语音转录"},
        {"Creates a label track with transcribed text from spoken audio", 
         "从语音音频创建带有转录文本的标签轨道"},
        {"Whisper Model:", "Whisper 模型:"},
        {"Mode:", "模式:"},
        {"transcribe", "转录"},
        {"translate", "翻译"},
        {"Source Language:", "源语言:"},
        {"auto", "自动"},
        {"chinese", "中文"},
        {"Initial Prompt:", "初始提示:"},
        {"Max Segment Length", "最大片段长度"},
        {"Beam Size", "束搜索大小"},
        {"Best Of", "最佳候选数"},
        {"Running Whisper Transcription using OpenVINO", "正在使用 OpenVINO 运行 Whisper 转录"},
        {"Resampling to 16khz", "正在重采样到 16khz"},
        {"Whisper Transcription failed", "Whisper 转录失败"},
        {"There doesn't seem to be any whisper models installed", "似乎没有安装任何 whisper 模型"}
    };

    // 音乐生成翻译
    inline const std::map<std::string, std::string> MusicGenerationStrings = {
        {"OpenVINO Music Generation", "OpenVINO 音乐生成"},
        {"Generates an audio track from a set of text prompts", 
         "根据文本提示生成音频轨道"},
        {"Duration", "时长"},
        {"Model:", "模型:"},
        {"Prompt:", "提示词:"},
        {"Seed:", "随机种子:"},
        {"Guidance Scale", "引导比例"},
        {"TopK", "TopK"},
        {"Context Length", "上下文长度"},
        {"5 Seconds", "5 秒"},
        {"10 Seconds", "10 秒"},
        {"Audio Continuation", "音频续写"},
        {"Audio Continuation on New Track", "在新轨道上续写音频"},
        {"Encoder Device:", "编码器设备:"},
        {"Decode Device 0:", "解码器设备 0:"},
        {"Decode Device 1:", "解码器设备 1:"},
        {"Creating MusicGen Pipeline", "正在创建 MusicGen 管道"},
        {"Loading Music Generation AI Models...", "正在加载音乐生成 AI 模型..."},
        {"Running Music Generation", "正在运行音乐生成"},
        {"Music Generation failed", "音乐生成失败"},
        {"There is not enough room available to generate the audio", 
         "没有足够的空间来生成音频"}
    };

    // 超分辨率翻译
    inline const std::map<std::string, std::string> SuperResolutionStrings = {
        {"OpenVINO Super Resolution", "OpenVINO 超分辨率"},
        {"Performs Super Resolution upscaling to 48 khz", 
         "执行超分辨率升频到 48 khz"},
        {"Model:", "模型:"},
        {"Basic (General)", "基础（通用）"},
        {"Speech", "语音"},
        {"Encoder Device:", "编码器设备:"},
        {"DDPM Device:", "DDPM 设备:"},
        {"Decoder Device:", "解码器设备:"},
        {"Normalize Output RMS", "归一化输出 RMS"},
        {"Chunk Size:", "块大小:"},
        {"10.24 Seconds", "10.24 秒"},
        {"5.12 Seconds", "5.12 秒"},
        {"Steps", "步数"},
        {"Guidance Scale", "引导比例"},
        {"Loading Audio Super Resolution AI Models ...", "正在加载音频超分辨率 AI 模型..."},
        {"Applying Super Resolution using OpenVINO", "正在使用 OpenVINO 应用超分辨率"},
        {"Super Resolution failed", "超分辨率失败"}
    };

    // 获取翻译的辅助函数
    inline std::string GetTranslation(const std::string& key) {
        // 按顺序查找各个翻译表
        if (CommonStrings.count(key)) return CommonStrings.at(key);
        if (MusicSeparationStrings.count(key)) return MusicSeparationStrings.at(key);
        if (NoiseSuppressionStrings.count(key)) return NoiseSuppressionStrings.at(key);
        if (WhisperTranscriptionStrings.count(key)) return WhisperTranscriptionStrings.at(key);
        if (MusicGenerationStrings.count(key)) return MusicGenerationStrings.at(key);
        if (SuperResolutionStrings.count(key)) return SuperResolutionStrings.at(key);
        
        // 如果没有找到翻译，返回原文
        return key;
    }
}
