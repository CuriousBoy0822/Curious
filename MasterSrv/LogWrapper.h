#ifndef LOGWRAPPER_H
#define LOGWRAPPER_H

#include <log4cplus/logger.h>
#include <log4cplus/configurator.h>
#include <log4cplus/helpers/loglog.h>
#include <log4cplus/helpers/stringhelper.h>
#include <iostream>
#include "tc_singleton.h"

class LogWrapper : public taf::TC_Singleton<LogWrapper>
{
public:
    bool initialize(const char *config)
    {
        m_Logger = log4cplus::Logger::getRoot();
        try
        {
            log4cplus::PropertyConfigurator::doConfigure(LOG4CPLUS_TEXT(config));
            m_Logger = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("filelogger"));
        }
        catch(...)
        {
            std::cerr << "initialize log4cplus failed!" << std::endl;
            return false;
        }
        return true;
    }

    inline const log4cplus::Logger& getLogger() const
    {
        return m_Logger;
    }

private:
    log4cplus::Logger   m_Logger;
};

#define LOG_FATAL(fields) LOG4CPLUS_FATAL(LogWrapper::getInstance()->getLogger(),fields)
#define LOG_ERROR(fields) LOG4CPLUS_ERROR(LogWrapper::getInstance()->getLogger(),fields)
#define LOG_WARN(fields)  LOG4CPLUS_WARN(LogWrapper::getInstance()->getLogger(),fields)
#define LOG_INFO(fields)  LOG4CPLUS_INFO(LogWrapper::getInstance()->getLogger(),fields)
#define LOG_DEBUG(fields) LOG4CPLUS_DEBUG(LogWrapper::getInstance()->getLogger(),fields)
#define LOG_TRACE(fields) LOG4CPLUS_TRACE(LogWrapper::getInstance()->getLogger(),fields)

#endif

