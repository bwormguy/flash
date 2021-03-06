//
// Created by roman on 23.08.2020.
//

#ifndef FLASH_WINDOWFACTORY_H
#define FLASH_WINDOWFACTORY_H

#include "../windows/common/window/Window.h"
#include "../../data/manager/DataManager.h"

namespace View {

    class WindowFactory {
    public:
        WindowFactory() = default;

        /**
         * @brief Window factory method. You can add any additional logic to it.
         * @param filename Window config filename.
         * @param manager Resource data manager.
         * @return New Window.
         */
        std::shared_ptr<View::Window> create(const std::string &filename, Managers::DataManager *manager);

        ~WindowFactory() = default;
    };
}
#endif //FLASH_WINDOWFACTORY_H
