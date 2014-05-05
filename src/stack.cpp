#include "stack.hpp"

template <>
void lua::get<void>(const lua::index& source)
{
}

// Allow noop invocations from variadic templates
lua::index lua::push(lua::state* const state)
{
    return lua::index(state, -1);
}

int lua::__gc(lua::state* const state)
{
    char* block = static_cast<char*>(lua_touserdata(state, 1));
    auto userdata = reinterpret_cast<lua::userdata*>(block);
    auto value = block + sizeof(lua::userdata);

    userdata->destroy(value);
    userdata->~userdata();

    return 0;
}
