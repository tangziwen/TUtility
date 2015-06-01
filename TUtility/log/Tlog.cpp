#include "Tlog.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

namespace tzw {

TlogSystem * TlogSystem::system = NULL;

static char tmpStr[512];

static void writeToScreen(const char * str, TlogLevel level =TlogLevel::VERBOSE)
{
    if(TlogSystem::get ()->getPolicy () ==TlogPolicy::CONSOLE || TlogSystem::get ()->getPolicy () ==TlogPolicy::CONSOLE_FILE)
    {
        if((int)level >= (int)TlogSystem::get ()->getLevel ())
        {
            printf(str);
        }
    }
}
static void writeToFile(const char * str, TlogLevel level =TlogLevel::VERBOSE)
{
    if(TlogSystem::get ()->getPolicy () ==TlogPolicy::FILE || TlogSystem::get ()->getPolicy () ==TlogPolicy::CONSOLE_FILE)
    {
        if((int)level >= (int)TlogSystem::get ()->getLevel ())
        {
            fprintf(TlogSystem::get ()->getFileHandle (),str);
        }

    }
}

Tlog::Tlog(TlogLevel level)
    :m_level(level)
{

}

const Tlog &Tlog::operator <<(const char *str) const
{

    sprintf(tmpStr,"%s",str);
    writeToScreen(tmpStr,m_level);
    writeToFile(tmpStr,m_level);
    return (* this);
}

const Tlog &Tlog::operator <<(const float f) const
{
    sprintf(tmpStr,"%g",f);
    writeToScreen(tmpStr,m_level);
    writeToFile(tmpStr,m_level);
    return (* this);
}

const Tlog &Tlog::operator <<(const int i) const
{
    sprintf(tmpStr,"%d",i);
    writeToScreen(tmpStr,m_level);
    writeToFile(tmpStr,m_level);
    return (* this);
}

const Tlog &Tlog::operator <<(const char c) const
{
    sprintf(tmpStr,"%c",c);
    writeToScreen(tmpStr,m_level);
    writeToFile(tmpStr,m_level);
    return (* this);
}

const Tlog &Tlog::operator <<(const double d) const
{
    sprintf(tmpStr,"%g",d);
    writeToScreen(tmpStr,m_level);
    writeToFile(tmpStr,m_level);
    return (* this);
}

const Tlog &Tlog::operator <<(const long l) const
{
    sprintf(tmpStr,"%ld",l);
    writeToScreen(tmpStr,m_level);
    writeToFile(tmpStr,m_level);
    return (* this);
}

const Tlog &Tlog::operator <<(const bool b) const
{
    if(b)
    {
        sprintf (tmpStr,"true");
    }else
    {
        sprintf (tmpStr,"false");
    }
    writeToScreen(tmpStr,m_level);
    writeToFile(tmpStr,m_level);
    return (* this);
}

const Tlog &Tlog::operator <<(const std::string &str) const
{
    sprintf (tmpStr,"%s",str.c_str ());
    writeToScreen(tmpStr,m_level);
    writeToFile(tmpStr,m_level);
    return (* this);
}

const Tlog &Tlog::operator <<(const Tstring &str) const
{
    sprintf(tmpStr,"%s",str.data ());
    writeToScreen(tmpStr,m_level);
    writeToFile(tmpStr,m_level);
    return (* this);
}

const Tlog &Tlog::operator <<(const TlogTitleEnd &el) const
{
    sprintf (tmpStr,"\n---*\n");
    writeToScreen(tmpStr,m_level);
    writeToFile(tmpStr,m_level);
    return (* this);
}

const Tlog &Tlog::operator <<(const TlogTitleBegin &begin) const
{
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    sprintf (tmpStr,"\n--- %s",asctime (timeinfo));
    writeToScreen(tmpStr,m_level);
    writeToFile(tmpStr,m_level);
    return (* this);
}

const Tlog &Tlog::operator <<(const TlogEndLine &el) const
{
    sprintf (tmpStr,"\n");
    writeToScreen(tmpStr,m_level);
    writeToFile(tmpStr,m_level);
    return (* this);
}

TlogSystem *TlogSystem::get()
{
    if(!TlogSystem::system)
    {
        TlogSystem::system = new TlogSystem();
    }
    return TlogSystem::system;
}

TlogPolicy TlogSystem::getPolicy() const
{
    return m_policy;
}

void TlogSystem::setPolicy(const TlogPolicy &policy)
{
    m_policy = policy;
}

TlogSystem::TlogSystem()
    :m_policy(TlogPolicy::CONSOLE),m_level(TlogLevel::VERBOSE)
{
    m_fileHandle = fopen("log/log.txt","w+");

}
TlogLevel TlogSystem::getLevel() const
{
    return m_level;
}

void TlogSystem::setLevel(const TlogLevel &level)
{
    m_level = level;
}

FILE *TlogSystem::getFileHandle() const
{
    return m_fileHandle;
}

void TlogSystem::setFileHandle(FILE *fileHandle)
{
    m_fileHandle = fileHandle;
}

} // namespace tzw

