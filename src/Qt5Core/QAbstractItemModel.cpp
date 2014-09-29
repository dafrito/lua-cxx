#include "QAbstractItemModel.hpp"
#include "../convert/callable.hpp"
#include "../thread.hpp"

#include <QAbstractItemModel>

void lua::QAbstractItemModel_metatable(const lua::index& mt)
{
    // TODO Set up metatable methods for this class
}

int luaopen_luacxx_QAbstractItemModel(lua_State* const state)
{
    lua::thread env(state);

    env["QAbstractItemModel"] = lua::value::table;
    auto t = env["QAbstractItemModel"];

    return 0;
}