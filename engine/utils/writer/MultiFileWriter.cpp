//
// Created by roman on 07.08.2020.
//

#include <fstream>

#include "MultiFileWriter.h"
#include "../../main/support/exceptions/custom/FileCannotBeOpened.h"

WriterUtil::MultiFileWriter::MultiFileWriter(const std::list<std::string> &filenames) {
    this->add(filenames);
}

WriterUtil::MultiFileWriter::MultiFileWriter(const std::vector<std::string> &filenames) {
    this->add(filenames);
}

bool WriterUtil::MultiFileWriter::write(const char *message, const std::ios::openmode &mode) const {
    bool result = true;
    for (const std::string &path : m_filenames) {
        std::ofstream out(path.c_str(), mode);
        bool isOpen = out.is_open();
        if (isOpen) {
            out << message;
        }
        out.close();
        result = result && isOpen;
    }
    return result;
}

bool WriterUtil::MultiFileWriter::write(const std::string &message, const std::ios::openmode &mode) const {
    return write(message.c_str(), mode);
}

void WriterUtil::MultiFileWriter::add(const std::list<std::string> &filenames) {
    for (const std::string &path : filenames) {
        this->add(path);
    }
}

void WriterUtil::MultiFileWriter::add(const std::vector<std::string> &filenames) {
    for (const std::string &path : filenames) {
        this->add(path);
    }
}

void WriterUtil::MultiFileWriter::add(const std::string &filename) {
    std::ofstream out(filename, std::ios::app);
    if (out.is_open()) {
        m_filenames.push_back(filename);
    } else {
        throw Exceptions::FileCannotBeOpened("File " + filename + " cannot be opened.");
    }
}

void WriterUtil::MultiFileWriter::remove(const std::string &filename) noexcept {
    m_filenames.remove(filename);
}
