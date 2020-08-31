//
// Created by roman on 02.08.2020.
//

#include "Engine.h"
#include "../setup/EngineSetuper.h"
#include "../main/general/exceptions/Exception.h"
#include "../main/view/create/window/PrimaryWindowFactory.h"

Program::Engine::Engine(const std::string &filename) {
    Setup::EngineSetuper setuper(filename);
    _dataManager = std::unique_ptr<DataManagers::DataManager>(setuper.load());
}

int Program::Engine::start() const {
    try {
        ViewCreate::PrimaryWindowFactory factory;
        std::shared_ptr<WindowView::Window> window = factory.createWindow(_dataManager.get(), "primary.ini");
        window->start();
    }
    catch (PreferredExceptions::Exception &exception) {
        std::shared_ptr<LoggerUtil::Logger> logger = _dataManager->getLogManager()->createLoggerForFile("crash.log");
        logger->critical("Exception code: " + std::to_string(exception.getCode()) + ". " + exception.getMessage());
        return exception.getCode();
    }
    //todo: Split this method with usage of two objects - Starter and Process. They need to be in engine/init directory.
    return EXIT_SUCCESS;
}
