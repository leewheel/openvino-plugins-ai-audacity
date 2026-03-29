// Copyright (C) 2024 Intel Corporation
// SPDX-License-Identifier: GPL-3.0-only
// 本地化支持头文件

#pragma once

#include <string>

// 定义是否启用中文本地化
// 可以通过编译选项控制：-DENABLE_CHINESE_LOCALIZATION
#ifndef ENABLE_CHINESE_LOCALIZATION
    // 默认禁用，保持英文界面
    #define ENABLE_CHINESE_LOCALIZATION 0
#endif

#if ENABLE_CHINESE_LOCALIZATION
    #include "OVStringsChinese.h"
    
    // 本地化宏 - 自动查找翻译
    #define OV_LOCALIZE(str) OVChinese::GetTranslation(str)
    
    // 用于 TranslatableString 的本地化宏
    #define OV_XO(str) XO(OVChinese::GetTranslation(str).c_str())
    #define OV_XXO(str) XXO(OVChinese::GetTranslation(str).c_str())
#else
    // 不启用本地化时，直接返回原字符串
    #define OV_LOCALIZE(str) (str)
    #define OV_XO(str) XO(str)
    #define OV_XXO(str) XXO(str)
#endif

// 本地化辅助类
class OVLocalization {
public:
    // 获取当前语言设置
    static std::string GetCurrentLanguage() {
#if ENABLE_CHINESE_LOCALIZATION
        return "zh-CN";
#else
        return "en-US";
#endif
    }
    
    // 检查是否启用了本地化
    static bool IsLocalizationEnabled() {
#if ENABLE_CHINESE_LOCALIZATION
        return true;
#else
        return false;
#endif
    }
    
    // 翻译字符串
    static std::string Translate(const std::string& text) {
#if ENABLE_CHINESE_LOCALIZATION
        return OVChinese::GetTranslation(text);
#else
        return text;
#endif
    }
};
