//
// Created by roman on 27.09.2020.
//

#include "DataManager.h"

Managers::DataManager::DataManager(Managers::AudioManager *audioManager, Managers::ConfigManager *configManager,
                                   Managers::FontManager *fontManager, Managers::LogManager *logManager,
                                   Managers::TextureManager *textureManager)
        : m_audioManager(audioManager), m_configManager(configManager), m_fontManager(fontManager),
          m_logManager(logManager), m_textureManager(textureManager) {}

Managers::DataManager::DataManager(const std::shared_ptr<AudioManager> &audioManager, const std::shared_ptr<ConfigManager> &configManager,
                                   const std::shared_ptr<FontManager> &fontManager, const std::shared_ptr<LogManager> &logManager,
                                   const std::shared_ptr<TextureManager> &textureManager)
        : m_audioManager(audioManager), m_configManager(configManager), m_fontManager(fontManager),
          m_logManager(logManager), m_textureManager(textureManager) {}

std::shared_ptr<Managers::AudioManager> Managers::DataManager::getAudioManager() const noexcept {
    return m_audioManager;
}

std::shared_ptr<Managers::ConfigManager> Managers::DataManager::getConfigManager() const noexcept {
    return m_configManager;
}

std::shared_ptr<Managers::FontManager> Managers::DataManager::getFontManager() const noexcept {
    return m_fontManager;
}

std::shared_ptr<Managers::LogManager> Managers::DataManager::getLogManager() const noexcept {
    return m_logManager;
}

std::shared_ptr<Managers::TextureManager> Managers::DataManager::getTextureManager() const noexcept {
    return m_textureManager;
}