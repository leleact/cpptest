#ifndef _LOG_H
#define _LOG_H

#include <fstream>
#include <sstream>

namespace simBank { namespace log {

const int LOG_LEVEL_FATAL = 0;
const int LOG_LEVEL_ERROR = 1;
const int LOG_LEVEL_WARN  = 2;
const int LOG_LEVEL_DEBUG = 3;
const int LOG_LEVEL_INFO  = 4;

class Log {
public:
    static Log& getInstance();
    Log &operator << (std::ostream &);
    virtual ~Log();
private:
    std::fstream m_ostream;
    Log (const std::string &filename);
    Log(const Log&) = delete;
    Log& operator=(const Log&) = delete;
};

}}

using simBank::log::Log;

#define ERR(msg) \
    do {\
        std::stringstream os;\
        os << msg ;\
        Log::getInstance() << os; \
    }while(0);

#endif
