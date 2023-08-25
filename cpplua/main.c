#include <stdlib.h>
#include <stdio.h>

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"



int main(int argc, char** argv)
{
	if(argc != 2)
	{
		printf("Usage: %s <lua file>\n", argv[0]);
		exit(0);
	}

	lua_State* L = luaL_newstate();

	if(luaL_dofile(L, argv[1]) != LUA_OK)
    {
        printf("There was an error reading %s\n", argv[0]);
    }


	lua_close(L);

	exit(0);
}
