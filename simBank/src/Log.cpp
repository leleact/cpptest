#include "Log.hpp"

namespace simBank { namespace log {

std::string log_name = "va.log";

Log& Log::getInstance() {
    static Log log(log_name);
    return log;
}

Log::Log(const std::string &filename) {
    m_ostream.open(filename.c_str(), std::fstream::app);
}

Log::~Log() {
    if (m_ostream.is_open() ) {
        m_ostream.close(); 
    }
}

Log& Log::operator<<(std::ostream &os) {
    m_ostream << os.rdbuf();
    return *this;
}

}}

