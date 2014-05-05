#ifndef MODULELOADER_HEADER
#define MODULELOADER_HEADER

#include "state.hpp"
#include <string>

class ModuleLoader
{
public:
    virtual bool search(const std::string& module)=0;
    virtual void load(lua::state* const state, const std::string& module)=0;
    virtual ~ModuleLoader() {}
};

#endif // MODULELOADER_HEADER