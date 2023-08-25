
#ifdef __cplusplus
extern "C" {
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}
#include <iostream>
#endif

int main(int argc, char* argv[])
{

    if(argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <lua file>" << std::endl;
        return 0;
    }

    lua_State* L = luaL_newstate();
    if(luaL_dofile(L, argv[1]) != LUA_OK)
    {
        std::cerr << "Something went wrong reading " << argv[1] << std::endl;
    }
    return 0;
}