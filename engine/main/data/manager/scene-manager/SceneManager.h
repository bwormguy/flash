//
// Created by roman on 29.09.2020.
//

#ifndef FLASH_SCENEMANAGER_H
#define FLASH_SCENEMANAGER_H

#include <string>
#include "../../../../utils/Ini/analyzer/Analyzer.h"

namespace Managers {

    /**
     * @brief The class provides easy access to scene configuration data.
     * @namespace Managers
     *
     * This class defines SceneManager realization.
     */
    class SceneManager {
    public:
        explicit SceneManager(const std::string &sceneDirectory)
                : SCENE_DIRECTORY(sceneDirectory) {}

        explicit SceneManager(const char *sceneDirectory)
                : SCENE_DIRECTORY(sceneDirectory) {}

        /**
         * @brief Method loads and analizes scene ini config file.
         * @param filename File in scene directory.
         * @return IniUtil::Analyzer::IniData
         */
        IniUtil::Analyzer::IniData load(const std::string &filename) const;

        ~SceneManager() = default;

    private:
        const std::string SCENE_DIRECTORY;
    };
}

#endif //FLASH_SCENEMANAGER_H
