/*
* Copyright (C) 2010 - 2016 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

#ifndef GUILDMETHODS_H
#define GUILDMETHODS_H

/***
 * Inherits all methods from: none
 */
namespace LuaGuild
{
    /**
     * Returns a table with the [Player]s in this [Guild]
     *
     * Only the players that are online and on some map.
     *
     * @return table guildPlayers : table of [Player]s
     */
    int GetMembers(lua_State* L, Guild* guild)
    {
        lua_newtable(L);
        int tbl = lua_gettop(L);
        uint32 i = 0;

        std::shared_lock<std::shared_mutex> lock(*HashMapHolder<Player>::GetLock());
        const HashMapHolder<Player>::MapType& m = eObjectAccessor()GetPlayers();
        for (HashMapHolder<Player>::MapType::const_iterator it = m.begin(); it != m.end(); ++it)
        {
            if (Player* player = it->second)
            {
                if (player->IsInWorld() && player->GetGuildId() == guild->GetId())
                {
                    Eluna::Push(L, player);
                    lua_rawseti(L, tbl, ++i);
                }
            }
        }

        lua_settop(L, tbl); // push table to top of stack
        return 1;
    }

    /**
     * Returns the member count of this [Guild]
     *
     * @return uint32 memberCount
     */
    int GetMemberCount(lua_State* L, Guild* guild)
    {
        Eluna::Push(L, guild->GetMemberCount());
        return 1;
    }

    /**
     * Finds and returns the [Guild] leader by their GUID if logged in
     *
     * @return [Player] leader
     */
    int GetLeader(lua_State* L, Guild* guild)
    {
        Eluna::Push(L, eObjectAccessor()FindPlayer(guild->GetLeaderGUID()));
        return 1;
    }

    /**
     * Returns [Guild] leader GUID
     *
     * @return ObjectGuid leaderGUID
     */
    int GetLeaderGUID(lua_State* L, Guild* guild)
    {
        Eluna::Push(L, guild->GetLeaderGUID());
        return 1;
    }

    /**
     * Returns the [Guild]s entry ID
     *
     * @return uint32 entryId
     */
    int GetId(lua_State* L, Guild* guild)
    {
        Eluna::Push(L, guild->GetId());
        return 1;
    }

    /**
     * Returns the [Guild]s name
     *
     * @return string guildName
     */
    int GetName(lua_State* L, Guild* guild)
    {
        Eluna::Push(L, guild->GetName());
        return 1;
    }

    /**
     * Returns the [Guild]s current Message Of The Day
     *
     * @return string guildMOTD
     */
    int GetMOTD(lua_State* L, Guild* guild)
    {
        Eluna::Push(L, guild->GetMOTD());
        return 1;
    }

    /**
     * Returns the [Guild]s current info
     *
     * @return string guildInfo
     */
    int GetInfo(lua_State* L, Guild* guild)
    {
        Eluna::Push(L, guild->GetInfo());
        return 1;
    }

#ifndef CATA
    /**
     * Sets the leader of this [Guild]
     *
     * @param [Player] leader : the [Player] leader to change
     */
    int SetLeader(lua_State* L, Guild* guild)
    {
        Player* player = Eluna::CHECKOBJ<Player>(L, 2);

        guild->HandleSetLeader(player->GetSession(), player->GetName());
        return 0;
    }
#endif

    /**
     * Sets the information of the bank tab specified
     *
     * @param uint8 tabId : the ID of the tab specified
     * @param string info : the information to be set to the bank tab
     */
    int SetBankTabText(lua_State* L, Guild* guild)
    {
        uint8 tabId = Eluna::CHECKVAL<uint8>(L, 2);
        const char* text = Eluna::CHECKVAL<const char*>(L, 3);

        guild->SetBankTabText(tabId, text);
        return 0;
    }

    // SendPacketToGuild(packet)
    /**
     * Sends a [WorldPacket] to all the [Player]s in the [Guild]
     *
     * @param [WorldPacket] packet : the [WorldPacket] to be sent to the [Player]s
     */
    int SendPacket(lua_State* L, Guild* guild)
    {
        WorldPacket* data = Eluna::CHECKOBJ<WorldPacket>(L, 2);

        guild->BroadcastPacket(data);
        return 0;
    }

    // SendPacketToRankedInGuild(packet, rankId)
    /**
     * Sends a [WorldPacket] to all the [Player]s at the specified rank in the [Guild]
     *
     * @param [WorldPacket] packet : the [WorldPacket] to be sent to the [Player]s
     * @param uint8 rankId : the rank ID
     */
    int SendPacketToRanked(lua_State* L, Guild* guild)
    {
        WorldPacket* data = Eluna::CHECKOBJ<WorldPacket>(L, 2);
        uint8 ranked = Eluna::CHECKVAL<uint8>(L, 3);

        guild->BroadcastPacketToRank(data, ranked);
        return 0;
    }

    /**
     * Disbands the [Guild]
     */
    int Disband(lua_State* /*L*/, Guild* guild)
    {
        guild->Disband();
        return 0;
    }

    /**
     * Adds the specified [Player] to the [Guild] at the specified rank.
     *
     * If no rank is specified, defaults to none.
     *
     * @param [Player] player : the [Player] to be added to the guild
     * @param uint8 rankId : the rank ID
     */
    int AddMember(lua_State* L, Guild* guild)
    {
        Player* player = Eluna::CHECKOBJ<Player>(L, 2);
        uint8 rankId = Eluna::CHECKVAL<uint8>(L, 3, GUILD_RANK_NONE);

        CharacterDatabaseTransaction trans(nullptr);

        guild->AddMember(trans, player->GET_GUID(), rankId);
        return 0;
    }

    /**
     * Removes the specified [Player] from the [Guild].
     *
     * @param [Player] player : the [Player] to be removed from the guild
     * @param bool isDisbanding : default 'false', should only be set to 'true' if the guild is triggered to disband
     */
    int DeleteMember(lua_State* L, Guild* guild)
    {
        Player* player = Eluna::CHECKOBJ<Player>(L, 2);
        bool isDisbanding = Eluna::CHECKVAL<bool>(L, 3, false);

        CharacterDatabaseTransaction trans(nullptr);

        guild->DeleteMember(trans, player->GET_GUID(), isDisbanding);
        return 0;
    }

    /**
     * Promotes/demotes the [Player] to the specified rank.
     *
     * @param [Player] player : the [Player] to be promoted/demoted
     * @param uint8 rankId : the rank ID
     */
    int SetMemberRank(lua_State* L, Guild* guild)
    {
        Player* player = Eluna::CHECKOBJ<Player>(L, 2);
        uint8 newRank = Eluna::CHECKVAL<uint8>(L, 3);

        CharacterDatabaseTransaction trans(nullptr);

        guild->ChangeMemberRank(trans, player->GET_GUID(), newRank);
        return 0;
    }
    
    ElunaRegister<Guild> GuildMethods[] =
    {
        // Getters
        { "GetMembers", &LuaGuild::GetMembers },
        { "GetLeader", &LuaGuild::GetLeader },
        { "GetLeaderGUID", &LuaGuild::GetLeaderGUID },
        { "GetId", &LuaGuild::GetId },
        { "GetName", &LuaGuild::GetName },
        { "GetMOTD", &LuaGuild::GetMOTD },
        { "GetInfo", &LuaGuild::GetInfo },
        { "GetMemberCount", &LuaGuild::GetMemberCount },

        // Setters
        { "SetBankTabText", &LuaGuild::SetBankTabText },
        { "SetMemberRank", &LuaGuild::SetMemberRank },
#ifndef CATA
        { "SetLeader", &LuaGuild::SetLeader },
#endif

        // Other
        { "SendPacket", &LuaGuild::SendPacket },
        { "SendPacketToRanked", &LuaGuild::SendPacketToRanked },
        { "Disband", &LuaGuild::Disband },
        { "AddMember", &LuaGuild::AddMember },
        { "DeleteMember", &LuaGuild::DeleteMember },

#ifdef CATA //Not implemented in TCPP
        { "SetLeader", nullptr },
#endif

        { NULL, NULL }
    };
};
#endif
