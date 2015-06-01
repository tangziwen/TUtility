#ifndef TZW_TLOG_H
#define TZW_TLOG_H
#include <string>
#include "string/Tstring.h"
#include <stdio.h>
namespace tzw {

class TlogTitleEnd
{
};

class TlogTitleBegin
{
};

class TlogEndLine
{

};

enum class TlogPolicy
{
    CONSOLE,
    CONSOLE_FILE,
    FILE
};

enum class TlogLevel
{
    VERBOSE,
    WARNING,
    ERROR,
    CRITICAL_ERROR,
};

class TlogSystem
{
public:
    static TlogSystem * get();
    TlogPolicy getPolicy() const;
    void setPolicy(const TlogPolicy &policy);
    FILE *getFileHandle() const;
    void setFileHandle(FILE *fileHandle);
    TlogLevel getLevel() const;
    void setLevel(const TlogLevel &level);

private:
    TlogSystem();
    static TlogSystem * system;
    TlogPolicy m_policy;
    FILE * m_fileHandle;
    TlogLevel m_level;
};

class Tlog
{
public:
    Tlog(TlogLevel level =TlogLevel::VERBOSE);
    const Tlog &operator <<(const char * str) const;
    const Tlog &operator <<(const float f) const;
    const Tlog &operator <<(const int i) const;
    const Tlog &operator <<(const char c) const;
    const Tlog &operator <<(const double d) const;
    const Tlog &operator <<(const long l) const;
    const Tlog &operator <<(const bool b) const;
    const Tlog &operator <<(const std::string & str) const;
    const Tlog &operator <<(const Tstring & str) const;
    const Tlog &operator <<(const TlogTitleEnd & el) const;
    const Tlog &operator <<(const TlogTitleBegin & begin) const;
    const Tlog &operator <<(const TlogEndLine & el) const;
private:
    TlogLevel m_level;
};

//global variable for log  begin end
static TlogTitleBegin TlogBegin;
static TlogTitleEnd TlogEnd;
static TlogEndLine TlogEL;
} // namespace tzw

#define T_Log_CRASH_NOW(A) (Tlog()<<TlogBegin<<"crash at "<<__FILE__<<" lines "<<__LINE__<<", in function: "<<__func__<<TlogEL<<A<<TlogEnd,abort())

#define T_Log_EXIT_NOW(A) (Tlog()<<TlogBegin<<"crash at "<<__FILE__<<" lines "<<__LINE__<<", in function: "<<__func__<<TlogEL<<A<<TlogEnd,exit(0))

#define T_Log_AT(A) (Tlog()<<TlogBegin<<"log at "<<__FILE__<<" lines "<<__LINE__<<", in function: "<<__func__<<TlogEL<<A<<TlogEnd)
#endif // TZW_TLOG_H

