//
// Created by roman on 07.08.2020.
//

#ifndef FLASH_MULTIFILEWRITER_H
#define FLASH_MULTIFILEWRITER_H

#include "Writer.h"

#include <list>
#include <vector>

namespace WriterUtil {

    class MultiFileWriter : public Writer {
    public:
        MultiFileWriter() = default;

        explicit MultiFileWriter(const std::list<std::string> &filenames);

        explicit MultiFileWriter(const std::vector<std::string> &filenames);

        void add(const std::string &filename);

        void add(const std::list<std::string> &filenames);

        void add(const std::vector<std::string> &filenames);

        void remove(const std::string &filename) noexcept;

        bool write(const std::string &message, const std::ios::openmode &mode) const override;

        bool write(const char *message, const std::ios::openmode &mode) const override;

    protected:
        std::list<std::string> m_filenames;
    };
}

#endif //FLASH_MULTIFILEWRITER_H
