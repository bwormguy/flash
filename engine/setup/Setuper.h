//
// Created by roman on 23.08.2020.
//

#ifndef FLASH_SETUPER_H
#define FLASH_SETUPER_H

#include <string>

#include "../main/data/manager/DataManager.h"

namespace Setup {

    /**
     * @brief The base class of the Setuper class hierarchy.
     * @namespace Setup
     *
     * This class defines base Setuper interface and fields.
    */
    class Setuper {
    public:
        explicit Setuper(const std::string &filename)
                : _config(filename) {}

        /**
         * @brief Method reads config and returns data managers in DataManager facade class.
         * @return Managers::DataManager*
         */
        virtual DataManagers::DataManager *load() const = 0;

        virtual ~Setuper() = default;

    protected:
        const std::string _config;
    };
}

#endif //FLASH_SETUPER_H