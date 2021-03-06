//
// Created by roman on 01.09.2020.
//

#ifndef FLASH_STATECHANGEABLE_H
#define FLASH_STATECHANGEABLE_H

#include "../states/common-base/ScreenState.h"

namespace View {

    class ScreenState;

    /**
     * @brief This class is an interface for dynamic change of scene state by context.
     * @namespace View
     *
     * This class defines base StateChangeable interface.
    */
    class StateChangeable {
    public:
        StateChangeable() = default;

        /**
         * @brief ScreenState setter. Uses for dynamic content changing.
         * @param state New ScreenState.
         */
        virtual void setScreenState(View::ScreenState *state) = 0;

        virtual ~StateChangeable() = default;
    };
}

#endif //FLASH_STATECHANGEABLE_H
