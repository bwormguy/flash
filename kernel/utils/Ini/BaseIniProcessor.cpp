//
// Created by roman on 10.08.2020.
//

#include "BaseIniProcessor.h"

IniProcessorUtil::Analyzer::IniData IniProcessorUtil::BaseIniProcessor::fullparse() const noexcept {
    return _analyzer->fullparse(_reader->readlines());
}

IniProcessorUtil::Analyzer::IniData IniProcessorUtil::BaseIniProcessor::fullparse(ReaderUtil::Reader *reader) const noexcept {
    Analyzer::IniData result = _analyzer->fullparse(reader->readlines());
    delete reader;
    return std::move(result);
}

IniProcessorUtil::Analyzer::IniData
IniProcessorUtil::BaseIniProcessor::fullparse(const std::shared_ptr<ReaderUtil::Reader> &reader) const noexcept {
    return _analyzer->fullparse(reader->readlines());
}

void IniProcessorUtil::BaseIniProcessor::createIni(const IniProcessorUtil::Analyzer::IniData &data,
                                                   const std::shared_ptr<WriterUtil::Writer> &writer,
                                                   const std::ios::openmode &mode) const noexcept {
    this->createIni(data, writer.get(), mode);
}

void IniProcessorUtil::BaseIniProcessor::createIni(const IniProcessorUtil::Analyzer::IniData &data,
                                                   WriterUtil::Writer *writer, const std::ios::openmode &mode) const noexcept {
    std::string inidata;
    for (Analyzer::IniData::const_iterator section = data.cbegin(); section != data.cend(); ++section) {

        if (section->first != NO_BLOCK_CONFIG_LINES)
            inidata.append("[" + section->first + "]\n");

        for (std::map<std::string, std::string>::const_iterator line = section->second.cbegin();
             line != section->second.cend(); ++line) {
            inidata.append(line->first + " = " + line->second + "\n");
        }
    }
    writer->write(inidata, mode);
}