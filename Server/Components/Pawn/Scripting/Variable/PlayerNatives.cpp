#include "../Types.hpp"
#include "sdk.hpp"
#include <iostream>

#define GET_PLAYER_VAR_COMP(comp, ret)                                  \
    IPlayerVariableData* comp = queryData<IPlayerVariableData>(player); \
    if (comp == nullptr)                                                \
        return ret;

SCRIPT_API(SetPVarInt, bool(IPlayer& player, const std::string& varname, int value))
{
    GET_PLAYER_VAR_COMP(component, false);
    component->setInt(varname, value);
    return true;
}

SCRIPT_API(GetPVarInt, int(IPlayer& player, const std::string& varname))
{
    GET_PLAYER_VAR_COMP(component, 0);
    return component->getInt(varname);
}

SCRIPT_API(SetPVarString, bool(IPlayer& player, const std::string& varname, const std::string& value))
{
    GET_PLAYER_VAR_COMP(component, false);
    component->setString(varname, value);
    return true;
}

SCRIPT_API(GetPVarString, int(IPlayer& player, const std::string& varname, std::string& output))
{
    GET_PLAYER_VAR_COMP(component, 0);

    // If string is empty, output will not be updated or set to anything and will remain with old data.
    StringView var = component->getString(varname);
    if (var.empty()) {
        return 0;
    }
    output = String(var);
    return output.length();
}

SCRIPT_API(SetPVarFloat, bool(IPlayer& player, const std::string& varname, float value))
{
    GET_PLAYER_VAR_COMP(component, false);
    component->setFloat(varname, value);
    return true;
}

SCRIPT_API(GetPVarFloat, float(IPlayer& player, const std::string& varname))
{
    GET_PLAYER_VAR_COMP(component, 0.0f);
    return component->getFloat(varname);
}

SCRIPT_API(DeletePVar, bool(IPlayer& player, const std::string& varname))
{
    GET_PLAYER_VAR_COMP(component, false);
    return component->erase(varname);
}

SCRIPT_API(GetPVarsUpperIndex, int(IPlayer& player))
{
    GET_PLAYER_VAR_COMP(component, 0);
    return component->size();
}

SCRIPT_API(GetPVarNameAtIndex, bool(IPlayer& player, int index, std::string& varname))
{
    GET_PLAYER_VAR_COMP(component, false);
    return component->getKeyAtIndex(index, StringView(varname));
}

SCRIPT_API(GetPVarType, int(IPlayer& player, const std::string& varname))
{
    GET_PLAYER_VAR_COMP(component, 0);
    return component->getType(varname);
}
