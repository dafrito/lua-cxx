#include "QSet.hpp"
#include "../luacxx/convert/callable.hpp"
#include "../luacxx/thread.hpp"

#include <QSet>
/*

void lua::QSet_metatable(const lua::index& mt)
{
    // TODO Set up metatable methods for this class
}

int QSet_new(lua_State* const state)
{
    lua::make<QSet>(state);
    // TODO Set up object-specific methods

    return 1;
}

int luaopen_Qt5Core_QSet(lua_State* const state)
{
    lua::thread env(state);

    env["QSet"] = lua::value::table;
    env["QSet"]["new"] = QSet_new;

    return 0;
}
*/