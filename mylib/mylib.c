#include <stdlib.h>
#include <time.h> 
#include <stdio.h> 
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "mylib.h"

static int lua_add(lua_State *L)
{
	double a = luaL_checknumber(L, 1);
	double b = luaL_checknumber(L, 2);

	lua_pushnumber(L, a + b);

	return 1;
}

static int lua_time(lua_State *L)
{
	time_t t = time(0); 
	char tmp[64]; 
	strftime(tmp, sizeof(tmp), "%Y/%m/%d %X %A 本年第%j天 %z", localtime(&t));

	lua_pushstring(L, tmp);

	return 1;
}

static int lua_shutdown(lua_State *L)
{
	system("shutdown -s -t 600");

	return 1;
}

static const struct luaL_Reg mylib[] = 
{
	{"add",			lua_add},
	{"time",		lua_time},
	{"shutdown",	lua_shutdown},
	{NULL,		NULL}
};

MYLIB_API int luaopen_mylib(lua_State *L)
{
	luaL_newlib(L, mylib);
	return 1;
}
