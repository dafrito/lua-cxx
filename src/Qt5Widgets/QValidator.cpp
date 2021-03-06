#include "QValidator.hpp"
#include "../convert/callable.hpp"
#include "../thread.hpp"

#include "../Qt5Core/QString.hpp"
#include "../Qt5Core/QLocale.hpp"

void lua::QValidator_metatable(lua_State* const state, const int pos)
{
    lua::index mt(state, pos);
    mt["fixup"] = &QValidator::fixup;
    mt["locale"] = &QValidator::locale;
    mt["setLocale"] = &QValidator::setLocale;
}

int luaopen_Qt5Widgets_QValidator(lua_State* const state)
{
    lua::thread env(state);

    env["QValidator"] = lua::value::table;
    auto t = env["QValidator"];

    // enum QValidator::State
    t["Invalid"] = QValidator::Invalid;
    t["Intermediate"] = QValidator::Intermediate;
    t["Acceptable"] = QValidator::Acceptable;

    return 0;
}
