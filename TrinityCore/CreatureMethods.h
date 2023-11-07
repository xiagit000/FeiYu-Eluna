/*
* Copyright (C) 2010 - 2016 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

#ifndef CREATUREMETHODS_H
#define CREATUREMETHODS_H

/***
 * Non-[Player] controlled [Unit]s (i.e. NPCs).
 *
 * Inherits all methods from: [Object], [WorldObject], [Unit]
 */
namespace LuaCreature
{
    /**
     * Returns `true` if the [Creature] can regenerate health,
     *   and returns `false` otherwise.
     *
     * @return bool isRegenerating
     */
    int IsRegeneratingHealth(lua_State* L, Creature* creature)
    {
#ifdef CATA
        Eluna::Push(L, creature->isRegeneratingHealth());
#else
        Eluna::Push(L, creature->CanRegenerateHealth());
#endif
        return 1;
    }

    /**
     * Sets whether the [Creature] can regenerate health or not.
     *
     * @param bool enable = true : `true` to enable health regeneration, `false` to disable it
     */
    int SetRegeneratingHealth(lua_State* L, Creature* creature)
    {
        bool enable = Eluna::CHECKVAL<bool>(L, 2, true);

        creature->SetRegenerateHealth(enable);
        return 0;
    }

    /**
     * Returns `true` if the [Creature] is set to not give reputation when killed,
     *   and returns `false` otherwise.
     *
     * @return bool reputationDisabled
     */
    int IsReputationGainDisabled(lua_State* L, Creature* creature)
    {
        Eluna::Push(L, creature->IsReputationGainDisabled());
        return 1;
    }

    /**
     * Returns `true` if the [Creature] completes the [Quest] with the ID `questID`,
     *   and returns `false` otherwise.
     *
     * @param uint32 questID : the ID of a [Quest]
     * @return bool completesQuest
     */
    int CanCompleteQuest(lua_State* L, Creature* creature)
    {
        uint32 quest_id = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, creature->hasInvolvedQuest(quest_id));
        return 1;
    }

    /**
     * Returns `true` if the [Creature] can be targeted for attack,
     *   and returns `false` otherwise.
     *
     * @param bool mustBeDead = false : if `true`, only returns `true` if the [Creature] is also dead. Otherwise, it must be alive.
     * @return bool targetable
     */
    int IsTargetableForAttack(lua_State* L, Creature* creature)
    {
        bool mustBeDead = Eluna::CHECKVAL<bool>(L, 2, false);

        Eluna::Push(L, creature->isTargetableForAttack(mustBeDead));
        return 1;
    }

    /**
     * Returns `true` if the [Creature] can assist `friend` in combat against `enemy`,
     *   and returns `false` otherwise.
     *
     * @param [Unit] friend : the Unit we will be assisting
     * @param [Unit] enemy : the Unit that we would attack if we assist `friend`
     * @param bool checkFaction = true : if `true`, the [Creature] must be the same faction as `friend` to assist
     * @return bool canAssist
     */
    int CanAssistTo(lua_State* L, Creature* creature)
    {
        Unit* u = Eluna::CHECKOBJ<Unit>(L, 2);
        Unit* enemy = Eluna::CHECKOBJ<Unit>(L, 3);
        bool checkfaction = Eluna::CHECKVAL<bool>(L, 4, true);

        Eluna::Push(L, creature->CanAssistTo(u, enemy, checkfaction));
        return 1;
    }

    /**
     * Returns `true` if the [Creature] has searched for combat assistance already,
     *   and returns `false` otherwise.
     *
     * @return bool searchedForAssistance
     */
    int HasSearchedAssistance(lua_State* L, Creature* creature)
    {
        Eluna::Push(L, creature->HasSearchedAssistance());
        return 1;
    }

    /**
     * Returns `true` if the [Creature] will give its loot to `player`,
     *   and returns `false` otherwise.
     *
     * @return bool tapped
     */
    int IsTappedBy(lua_State* L, Creature* creature)
    {
        Player* player = Eluna::CHECKOBJ<Player>(L, 2);

        Eluna::Push(L, creature->isTappedBy(player));
        return 1;
    }

    /**
     * Returns `true` if the [Creature] will give its loot to a [Player] or [Group],
     *   and returns `false` otherwise.
     *
     * @return bool hasLootRecipient
     */
    int HasLootRecipient(lua_State* L, Creature* creature)
    {
        Eluna::Push(L, creature->hasLootRecipient());
        return 1;
    }

    /**
     * Returns `true` if the [Creature] can start attacking nearby hostile [Unit]s,
     *   and returns `false` otherwise.
     *
     * @return bool canAggro
     */
    int CanAggro(lua_State* L, Creature* creature)
    {
        Eluna::Push(L, !creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC));
        return 1;
    }

    /**
     * Returns `true` if the [Creature] can move through deep water,
     *   and returns `false` otherwise.
     *
     * @return bool canSwim
     */
    int CanSwim(lua_State* L, Creature* creature)
    {
        Eluna::Push(L, creature->CanSwim());
        return 1;
    }

    /**
     * Returns `true` if the [Creature] can move on land,
     *   and returns `false` otherwise.
     *
     * @return bool canWalk
     */
    int CanWalk(lua_State* L, Creature* creature)
    {
        Eluna::Push(L, creature->CanWalk());
        return 1;
    }

    /**
     * Returns `true` if the [Creature] is returning to its spawn position from combat,
     *   and returns `false` otherwise.
     *
     * @return bool inEvadeMode
     */
    int IsInEvadeMode(lua_State* L, Creature* creature)
    {
        Eluna::Push(L, creature->IsInEvadeMode());
        return 1;
    }

    /**
     * Returns `true` if the [Creature]'s rank is Elite or Rare Elite,
     *   and returns `false` otherwise.
     *
     * @return bool isElite
     */
    int IsElite(lua_State* L, Creature* creature)
    {
        Eluna::Push(L, creature->isElite());
        return 1;
    }

    /**
     * Returns `true` if the [Creature] is a city guard,
     *   and returns `false` otherwise.
     *
     * @return bool isGuard
     */
    int IsGuard(lua_State* L, Creature* creature)
    {
        Eluna::Push(L, creature->IsGuard());
        return 1;
    }

    /**
     * Returns `true` if the [Creature] is a civilian,
     *   and returns `false` otherwise.
     *
     * @return bool isCivilian
     */
    int IsCivilian(lua_State* L, Creature* creature)
    {
        Eluna::Push(L, creature->IsCivilian());
        return 1;
    }

    /**
     * Returns `true` if the [Creature] is the leader of a player faction,
     *   and returns `false` otherwise.
     *
     * @return bool isLeader
     */
    int IsRacialLeader(lua_State* L, Creature* creature)
    {
        Eluna::Push(L, creature->IsRacialLeader());
        return 1;
    }

    /**
     * Returns `true` if the [Creature]'s flags_extra includes Dungeon Boss (0x1000000),
     *   and returns `false` otherwise.
     *
     * @return bool isDungeonBoss
     */
    int IsDungeonBoss(lua_State* L, Creature* creature)
    {
        Eluna::Push(L, creature->IsDungeonBoss());
        return 1;
    }


    /**
     * Returns `true` if the [Creature]'s rank is Boss,
     *   and returns `false` otherwise.
     *
     * @return bool isWorldBoss
     */
    int IsWorldBoss(lua_State* L, Creature* creature)
    {
        Eluna::Push(L, creature->isWorldBoss());
        return 1;
    }

    /**
     * Returns `true` if the [Creature] cannot cast `spellId` due to a category cooldown,
     *   and returns `false` otherwise.
     *
     * @param uint32 spellId : the ID of a [Spell]
     * @return bool hasCooldown
     */
    int HasCategoryCooldown(lua_State* L, Creature* creature)
    {
        uint32 spell = Eluna::CHECKVAL<uint32>(L, 2);

        if (const SpellInfo* info = sSpellMgr->GetSpellInfo(spell))
            Eluna::Push(L, info->GetCategory() && creature->GetSpellHistory()->HasCooldown(spell));
        else
            Eluna::Push(L, false);

        return 1;
    }

    /**
     * Returns `true` if the [Creature] can cast `spellId` when mind-controlled,
     *   and returns `false` otherwise.
     *
     * @param uint32 spellId : the ID of a [Spell]
     * @return bool hasSpell
     */
    int HasSpell(lua_State* L, Creature* creature)
    {
        uint32 id = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, creature->HasSpell(id));
        return 1;
    }

    /**
     * Returns `true` if the [Creature] starts the [Quest] `questId`,
     *   and returns `false` otherwise.
     *
     * @param uint32 questId : the ID of a [Quest]
     * @return bool hasQuest
     */
    int HasQuest(lua_State* L, Creature* creature)
    {
        uint32 questId = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, creature->hasQuest(questId));
        return 1;
    }

    /**
     * Returns `true` if the [Creature] has `spellId` on cooldown,
     *   and returns `false` otherwise.
     *
     * @param uint32 spellId : the ID of a [Spell]
     * @return bool hasCooldown
     */
    int HasSpellCooldown(lua_State* L, Creature* creature)
    {
        uint32 spellId = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, creature->GetSpellHistory()->HasCooldown(spellId));
        return 1;
    }

    /**
     * Returns `true` if the [Creature] can fly,
     *   and returns `false` otherwise.
     *
     * @return bool canFly
     */
    int CanFly(lua_State* L, Creature* creature)
    {
        Eluna::Push(L, creature->CanFly());
        return 1;
    }

    /**
     * Returns `true` if the [Creature] is an invisible trigger,
     *   and returns `false` otherwise.
     *
     * @return bool canFly
     */
    int IsTrigger(lua_State* L, Creature* creature)
    {
        Eluna::Push(L, creature->IsTrigger());
        return 1;
    }

    /**
     * Returns true if the [Creature] is damaged enough for looting
     *
     * @return bool isDamagedEnough
     */
    int IsDamageEnoughForLootingAndReward(lua_State* L, Creature* creature)
    {
        Eluna::Push(L, creature->IsDamageEnoughForLootingAndReward());
        return 1;
    }

    /**
     * Returns true if the [Creature] can start attacking specified target
     *
     * Does not work on most targets
     *
     * @param [Unit] target
     * @param bool force = true : force [Creature] to attack
     */
    int CanStartAttack(lua_State* L, Creature* creature)
    {
        Unit* target = Eluna::CHECKOBJ<Unit>(L, 2);
        bool force = Eluna::CHECKVAL<bool>(L, 3, true);

        Eluna::Push(L, creature->CanStartAttack(target, force));
        return 1;
    }

    /**
     * Returns true if [Creature] has the specified loot mode
     *
     * @param uint16 lootMode
     * @return bool hasLootMode
     */
    int HasLootMode(lua_State* L, Creature* creature)
    {
        uint16 lootMode = Eluna::CHECKVAL<uint16>(L, 2);

        Eluna::Push(L, creature->HasLootMode(lootMode));
        return 1;
    }

    /**
     * Returns the time it takes for this [Creature] to respawn once killed.
     *
     * This value does not usually change over a [Creature]'s lifespan,
     *   but can be modified by [Creature:SetRespawnDelay].
     *
     * @return uint32 respawnDelay : the respawn delay, in seconds
     */
    int GetRespawnDelay(lua_State* L, Creature* creature)
    {
        Eluna::Push(L, creature->GetRespawnDelay());
        return 1;
    }

    /**
     * Returns the radius the [Creature] is permitted to wander from its
     *   respawn point.
     *
     * @return float wanderRadius
     */
    int GetWanderRadius(lua_State* L, Creature* creature)
    {
        Eluna::Push(L, creature->GetWanderDistance());
        return 1;
    }

    /**
     * Returns the current waypoint path ID of the [Creature].
     *
     * @return uint32 pathId
     */
    int GetWaypointPath(lua_State* L, Creature* creature)
    {
        Eluna::Push(L, creature->GetWaypointPath());
        return 1;
    }

    /**
     * Returns the current waypoint ID of the [Creature].
     *
     * @return uint32 wpId
     */
    int GetCurrentWaypointId(lua_State* L, Creature* creature)
    {
        Eluna::Push(L, creature->GetCurrentWaypointInfo().first);
        return 1;
    }

    /**
     * Returns the default movement type for this [Creature].
     *
     * @return [MovementGeneratorType] defaultMovementType
     */
    int GetDefaultMovementType(lua_State* L, Creature* creature)
    {
        Eluna::Push(L, creature->GetDefaultMovementType());
        return 1;
    }

    /**
     * Returns the aggro range of the [Creature] for `target`.
     *
     * @param [Unit] target
     * @return float aggroRange
     */
    int GetAggroRange(lua_State* L, Creature* creature)
    {
        Unit* target = Eluna::CHECKOBJ<Unit>(L, 2);

        Eluna::Push(L, creature->GetAggroRange(target));
        return 1;
    }

    /**
     * Returns the effective aggro range of the [Creature] for `target`.
     *
     * If this is smaller than the minimum aggro range set in the config file,
     *   that is used as the aggro range instead.
     *
     * @param [Unit] target
     * @return float attackDistance
     */
    int GetAttackDistance(lua_State* L, Creature* creature)
    {
        Unit* target = Eluna::CHECKOBJ<Unit>(L, 2);

        Eluna::Push(L, creature->GetAttackDistance(target));
        return 1;
    }


    /**
     * Returns the [Group] that can loot this [Creature].
     *
     * @return [Group] lootRecipientGroup : the group or `nil`
     */
    int GetLootRecipientGroup(lua_State* L, Creature* creature)
    {
        Eluna::Push(L, creature->GetLootRecipientGroup());
        return 1;
    }

    /**
     * Returns the [Player] that can loot this [Creature].
     *
     * @return [Player] lootRecipient : the player or `nil`
     */
    int GetLootRecipient(lua_State* L, Creature* creature)
    {
        Eluna::Push(L, creature->GetLootRecipient());
        return 1;
    }

    /**
     * Returns the [Creature]'s script name.
     *
     * This is used by the core to apply C++ scripts to the Creature.
     *
     * It is not used by Eluna. Eluna will override AI scripts.
     *
     * @return string scriptName
     */
    int GetScriptName(lua_State* L, Creature* creature)
    {
        Eluna::Push(L, creature->GetScriptName());
        return 1;
    }

    /**
     * Returns the [Creature]'s AI name.
     *
     * This is used by the core to assign the Creature's default AI.
     *
     * If the Creature is scripted by Eluna, the AI is overriden.
     *
     * @return string AIName
     */
    int GetAIName(lua_State* L, Creature* creature)
    {
        Eluna::Push(L, creature->GetAIName());
        return 1;
    }

    /**
     * Returns the [Creature]'s script ID.
     *
     * Every C++ script name is assigned a unique ID by the core.
     *   This returns the ID for this [Creature]'s script name.
     *
     * @return uint32 scriptID
     */
    int GetScriptId(lua_State* L, Creature* creature)
    {
        Eluna::Push(L, creature->GetScriptId());
        return 1;
    }

    /**
     * Returns the [Creature]'s cooldown for `spellID`.
     *
     * @param uint32 spellID
     * @return uint32 cooldown : the cooldown, in milliseconds
     */
    int GetCreatureSpellCooldownDelay(lua_State* L, Creature* creature)
    {
        uint32 spell = Eluna::CHECKVAL<uint32>(L, 2);

        if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spell))
            Eluna::Push(L, creature->GetSpellHistory()->GetRemainingCooldown(spellInfo));
        else
            Eluna::Push(L, 0);

        return 1;
    }

    /**
     * Returns the delay between when the [Creature] dies and when its body despawns.
     *
     * @return uint32 corpseDelay : the delay, in seconds
     */
    int GetCorpseDelay(lua_State* L, Creature* creature)
    {
        Eluna::Push(L, creature->GetCorpseDelay());
        return 1;
    }

    /**
     * Returns position the [Creature] returns to when evading from combat
     *   or respawning.
     *
     * @return float x
     * @return float y
     * @return float z
     * @return float o
     */
    int GetHomePosition(lua_State* L, Creature* creature)
    {
        float x, y, z, o;
        creature->GetHomePosition(x, y, z, o);

        Eluna::Push(L, x);
        Eluna::Push(L, y);
        Eluna::Push(L, z);
        Eluna::Push(L, o);
        return 4;
    }

    /**
     * Sets the position the [Creature] returns to when evading from combat
     *   or respawning.
     *
     * @param float x
     * @param float y
     * @param float z
     * @param float o
     */
    int SetHomePosition(lua_State* L, Creature* creature)
    {
        float x = Eluna::CHECKVAL<float>(L, 2);
        float y = Eluna::CHECKVAL<float>(L, 3);
        float z = Eluna::CHECKVAL<float>(L, 4);
        float o = Eluna::CHECKVAL<float>(L, 5);

        creature->SetHomePosition(x, y, z, o);
        return 0;
    }

    enum SelectAggroTarget
    {
        SELECT_TARGET_RANDOM = 0,   // Just selects a random target
        SELECT_TARGET_TOPAGGRO,     // Selects targes from top aggro to bottom
        SELECT_TARGET_BOTTOMAGGRO,  // Selects targets from bottom aggro to top
        SELECT_TARGET_NEAREST,
        SELECT_TARGET_FARTHEST
    };

    /**
    * Returns a target from the [Creature]'s threat list based on the
    *   supplied arguments.
    *
    *     enum SelectAggroTarget
    *     {
    *         SELECT_TARGET_RANDOM = 0,  //Just selects a random target
    *         SELECT_TARGET_TOPAGGRO,    //Selects targets from top aggro to bottom
    *         SELECT_TARGET_BOTTOMAGGRO, //Selects targets from bottom aggro to top
    *         SELECT_TARGET_NEAREST,
    *         SELECT_TARGET_FARTHEST
    *     };
    *
    * For example, if you wanted to select the third-farthest [Player]
    *   within 50 yards that has the [Aura] "Corrupted Blood" (ID 24328),
    *   you could use this function like so:
    *
    *     target = creature:GetAITarget(4, true, 3, 50, 24328)
    *
    * @param [SelectAggroTarget] targetType : how the threat list should be sorted
    * @param bool playerOnly = false : if `true`, skips targets that aren't [Player]s
    * @param uint32 position = 0 : used as an offset into the threat list. If `targetType` is random, used as the number of players from top of aggro to choose from
    * @param float distance = 0.0 : if positive, the maximum distance for the target. If negative, the minimum distance
    * @param int32 aura = 0 : if positive, the target must have this [Aura]. If negative, the the target must not have this Aura
    * @return [Unit] target : the target, or `nil`
    */
    int GetAITarget(lua_State* L, Creature* creature)
    {
        uint32 targetType = Eluna::CHECKVAL<uint32>(L, 2);
        bool playerOnly = Eluna::CHECKVAL<bool>(L, 3, false);
        uint32 position = Eluna::CHECKVAL<uint32>(L, 4, 0);
        float dist = Eluna::CHECKVAL<float>(L, 5, 0.0f);
        int32 aura = Eluna::CHECKVAL<int32>(L, 6, 0);

        auto const& threatlist = creature->GetThreatManager().GetSortedThreatList();
        std::list<Unit*> targetList;
        for (ThreatReference const* itr : threatlist)
            {
            Unit* target = itr->GetVictim();
            if (!target)
                continue;
            if (playerOnly && target->GetTypeId() != TYPEID_PLAYER)
                continue;
            if (aura > 0 && !target->HasAura(aura))
                continue;
            else if (aura < 0 && target->HasAura(-aura))
                continue;
            if (dist > 0.0f && !creature->IsWithinDist(target, dist))
                continue;
            else if (dist < 0.0f && creature->IsWithinDist(target, -dist))
                continue;
            targetList.push_back(target);
        }

        if (targetList.empty())
            return 1;
        if (position >= targetList.size())
            return 1;

        if (targetType == SELECT_TARGET_NEAREST || targetType == SELECT_TARGET_FARTHEST)
            targetList.sort(ElunaUtil::ObjectDistanceOrderPred(creature));

        switch (targetType)
        {
            case SELECT_TARGET_NEAREST:
            case SELECT_TARGET_TOPAGGRO:
                {
                    std::list<Unit*>::const_iterator itr = targetList.begin();
                    if (position)
                        std::advance(itr, position);
                    Eluna::Push(L, *itr);
                }
                break;
            case SELECT_TARGET_FARTHEST:
            case SELECT_TARGET_BOTTOMAGGRO:
                {
                    std::list<Unit*>::reverse_iterator ritr = targetList.rbegin();
                    if (position)
                        std::advance(ritr, position);
                    Eluna::Push(L, *ritr);
                }
                break;
            case SELECT_TARGET_RANDOM:
                {
                    std::list<Unit*>::const_iterator itr = targetList.begin();
                    if (position)
                        std::advance(itr, urand(0, position));
                    else
                        std::advance(itr, urand(0, targetList.size() - 1));
                    Eluna::Push(L, *itr);
                }
                break;
            default:
                luaL_argerror(L, 2, "SelectAggroTarget expected");
                break;
        }

        return 1;
    }

    /**
     * Returns all [Unit]s in the [Creature]'s threat list.
     *
     * @return table targets
     */
    int GetAITargets(lua_State* L, Creature* creature)
    {
        auto const& threatlist = creature->GetThreatManager().GetSortedThreatList();

        lua_createtable(L, creature->GetThreatManager().GetThreatListSize(), 0);
        int tbl = lua_gettop(L);

        uint32 i = 0;
        for (ThreatReference const* itr : threatlist)
        {
            Unit* target = itr->GetVictim();
            if (!target)
                continue;
            Eluna::Push(L, target);
            lua_rawseti(L, tbl, ++i);
        }

        lua_settop(L, tbl);
        return 1;
    }

    /**
     * Returns the number of [Unit]s in this [Creature]'s threat list.
     *
     * @return double targetsCount
     */
    int GetAITargetsCount(lua_State* L, Creature* creature)
    {
        Eluna::Push(L, (double)creature->GetThreatManager().GetThreatListSize());
        return 1;
    }

    /**
     * Returns the [Creature]'s NPC flags.
     *
     * These are used to control whether the NPC is a vendor, can repair items,
     *   can give quests, etc.
     *
     * @return [NPCFlags] npcFlags
     */
    int GetNPCFlags(lua_State* L, Creature* creature)
    {
        Eluna::Push(L, creature->GetUInt32Value(UNIT_NPC_FLAGS));
        return 1;
    }

    /**
     * Returns the [Creature]'s Extra flags.
     *
     * These are used to control whether the NPC is a civilian, uses pathfinding,
     *   if it's a guard, etc.
     *
     * @return [ExtraFlags] extraFlags
     */
    int GetExtraFlags(lua_State* L, Creature* creature)
    {
        Eluna::Push(L, creature->GetCreatureTemplate()->flags_extra);
        return 1;
    }

#ifndef CATA
    /**
     * Returns the [Creature]'s shield block value.
     *
     * @return uint32 shieldBlockValue
     */
    int GetShieldBlockValue(lua_State* L, Creature* creature)
    {
        Eluna::Push(L, creature->GetShieldBlockValue());
        return 1;
    }
#endif

    int GetLootMode(lua_State* L, Creature* creature)
    {
        Eluna::Push(L, creature->GetLootMode());
        return 1;
    }


    /**
     * Returns the guid of the [Creature] that is used as the ID in the database
     *
     * @return uint32 dbguid
     */
    int GetDBTableGUIDLow(lua_State* L, Creature* creature)
    {
        Eluna::Push(L, creature->GetSpawnId());
        return 1;
    }

    /**
     * Sets the [Creature]'s NPC flags to `flags`.
     *
     * @param [NPCFlags] flags
     */
    int SetNPCFlags(lua_State* L, Creature* creature)
    {
        uint32 flags = Eluna::CHECKVAL<uint32>(L, 2);

        creature->SetUInt32Value(UNIT_NPC_FLAGS, flags);
        return 0;
    }

    /**
     * Sets the [Creature]'s ReactState to `state`.
     *
     * @param [ReactState] state
     */
    int SetReactState(lua_State* L, Creature* creature)
    {
        uint32 state = Eluna::CHECKVAL<uint32>(L, 2);

        creature->SetReactState((ReactStates)state);
        return 0;
    }

    /**
     * Makes the [Creature] able to fly if enabled.
     *
     * @param bool disable
     */
    int SetDisableGravity(lua_State* L, Creature* creature)
    {
        bool disable = Eluna::CHECKVAL<bool>(L, 2);

        creature->SetDisableGravity(disable);
        return 0;
    }

    int SetLootMode(lua_State* L, Creature* creature)
    {
        uint16 lootMode = Eluna::CHECKVAL<uint16>(L, 2);

        creature->SetLootMode(lootMode);
        return 0;
    }

    /**
     * Sets the [Creature]'s death state to `deathState`.
     *
     * @param [DeathState] deathState
     */
    int SetDeathState(lua_State* L, Creature* creature)
    {
        int32 state = Eluna::CHECKVAL<int32>(L, 2);

        creature->setDeathState((DeathState)state);
        return 0;
    }

    /**
     * Sets whether the [Creature] is currently walking or running.
     *
     * @param bool enable = true : `true` to enable walking, `false` for running
     */
    int SetWalk(lua_State* L, Creature* creature)           // TODO: Move same to Player ?
    {
        bool enable = Eluna::CHECKVAL<bool>(L, 2, true);

        creature->SetWalk(enable);
        return 0;
    }

    /**
     * Equips given [Item]s to the [Unit]. Using 0 removes the equipped [Item]
     *
     * @param uint32 main_hand : main hand [Item]'s entry
     * @param uint32 off_hand : off hand [Item]'s entry
     * @param uint32 ranged : ranged [Item]'s entry
     */
    int SetEquipmentSlots(lua_State* L, Creature* creature)
    {
        uint32 main_hand = Eluna::CHECKVAL<uint32>(L, 2);
        uint32 off_hand = Eluna::CHECKVAL<uint32>(L, 3);
        uint32 ranged = Eluna::CHECKVAL<uint32>(L, 4);

        creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 0, main_hand);
        creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 1, off_hand);
        creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 2, ranged);
        return 0;
    }

    /**
     * Sets whether the [Creature] can be aggroed.
     *
     * @param bool allow = true : `true` to allow aggro, `false` to disable aggro
     */
    int SetAggroEnabled(lua_State* L, Creature* creature)
    {
        bool allow = Eluna::CHECKVAL<bool>(L, 2, true);

        if (allow)
            creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
        else
            creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);

        return 0;
    }

    /**
     * Sets whether the [Creature] gives reputation or not.
     *
     * @param bool disable = true : `true` to disable reputation, `false` to enable
     */
    int SetDisableReputationGain(lua_State* L, Creature* creature)
    {
        bool disable = Eluna::CHECKVAL<bool>(L, 2, true);

        creature->SetDisableReputationGain(disable);
        return 0;
    }

    /**
     * Sets the [Creature] as in combat with all [Player]s in the dungeon instance.
     *
     * This is used by raid bosses to prevent Players from using out-of-combat
     *   actions once the encounter has begun.
     */
    int SetInCombatWithZone(lua_State* /*L*/, Creature* creature)
    {
        if (creature->IsAIEnabled())
            creature->AI()->DoZoneInCombat();

        return 0;
    }

    /**
     * Sets the distance the [Creature] can wander from it's spawn point.
     *
     * @param float distance
     */
    int SetWanderRadius(lua_State* L, Creature* creature)
    {
        float dist = Eluna::CHECKVAL<float>(L, 2);

        creature->SetWanderDistance(dist);
        return 0;
    }

    /**
     * Sets the time it takes for the [Creature] to respawn when killed.
     *
     * @param uint32 delay : the delay, in seconds
     */
    int SetRespawnDelay(lua_State* L, Creature* creature)
    {
        uint32 delay = Eluna::CHECKVAL<uint32>(L, 2);

        creature->SetRespawnDelay(delay);
        return 0;
    }

    /**
     * Sets the default movement type of the [Creature].
     *
     * @param [MovementGeneratorType] type
     */
    int SetDefaultMovementType(lua_State* L, Creature* creature)
    {
        int32 type = Eluna::CHECKVAL<int32>(L, 2);

        creature->SetDefaultMovementType((MovementGeneratorType)type);
        return 0;
    }

    /**
     * Sets whether the [Creature] can search for assistance at low health or not.
     *
     * @param bool enable = true : `true` to disable searching, `false` to allow
     */
    int SetNoSearchAssistance(lua_State* L, Creature* creature)
    {
        bool val = Eluna::CHECKVAL<bool>(L, 2, true);

        creature->SetNoSearchAssistance(val);
        return 0;
    }

    /**
     * Sets whether the [Creature] can call nearby enemies for help in combat or not.
     *
     * @param bool enable = true : `true` to disable calling for help, `false` to enable
     */
    int SetNoCallAssistance(lua_State* L, Creature* creature)
    {
        bool val = Eluna::CHECKVAL<bool>(L, 2, true);

        creature->SetNoCallAssistance(val);
        return 0;
    }

    /**
     * Sets whether the creature is hovering / levitating or not.
     *
     * @param bool enable = true : `true` to enable hovering, `false` to disable
     */
    int SetHover(lua_State* L, Creature* creature)
    {
        bool enable = Eluna::CHECKVAL<bool>(L, 2, true);

        creature->SetHover(enable);
        return 0;
    }

    /**
     * Despawn this [Creature].
     *
     * @param uint32 delay = 0 : dely to despawn in milliseconds
     */
    int DespawnOrUnsummon(lua_State* L, Creature* creature)
    {
        uint32 msTimeToDespawn = Eluna::CHECKVAL<uint32>(L, 2, 0);

        creature->DespawnOrUnsummon(Milliseconds(msTimeToDespawn));
        return 0;
    }

    /**
     * Respawn this [Creature].
     */
    int Respawn(lua_State* /*L*/, Creature* creature)
    {
        creature->Respawn();
        return 0;
    }

    /**
     * Remove this [Creature]'s corpse.
     */
    int RemoveCorpse(lua_State* /*L*/, Creature* creature)
    {
        creature->RemoveCorpse();
        return 0;
    }

    /**
     * Make the [Creature] start following its waypoint path.
     */
    int MoveWaypoint(lua_State* /*L*/, Creature* creature)
    {
        creature->GetMotionMaster()->MovePath(creature->GetWaypointPath(), true);
        return 0;
    }

    /**
     * Make the [Creature] call for assistance in combat from other nearby [Creature]s.
     */
    int CallAssistance(lua_State* /*L*/, Creature* creature)
    {
        creature->CallAssistance();
        return 0;
    }

    /**
     * Make the [Creature] call for help in combat from friendly [Creature]s within `radius`.
     *
     * @param float radius
     */
    int CallForHelp(lua_State* L, Creature* creature)
    {
        float radius = Eluna::CHECKVAL<float>(L, 2);

        creature->CallForHelp(radius);
        return 0;
    }

    /**
     * Make the [Creature] flee combat to get assistance from a nearby friendly [Creature].
     */
    int FleeToGetAssistance(lua_State* /*L*/, Creature* creature)
    {
        creature->DoFleeToGetAssistance();
        return 0;
    }

    /**
     * Make the [Creature] attack `target`.
     *
     * @param [Unit] target
     */
    int AttackStart(lua_State* L, Creature* creature)
    {
        Unit* target = Eluna::CHECKOBJ<Unit>(L, 2);

        creature->AI()->AttackStart(target);
        return 0;
    }

    /**
     * Save the [Creature] in the database.
     */
    int SaveToDB(lua_State* /*L*/, Creature* creature)
    {
        creature->SaveToDB();
        return 0;
    }

    /**
     * Make the [Creature] try to find a new target.
     *
     * This should be called every update cycle for the Creature's AI.
     */
    int SelectVictim(lua_State* L, Creature* creature)
    {
        Eluna::Push(L, creature->SelectVictim());
        return 1;
    }

    /**
     * Transform the [Creature] into another Creature.
     *
     * @param uint32 entry : the Creature ID to transform into
     * @param uint32 dataGUIDLow = 0 : use this Creature's model and equipment instead of the defaults
     */
    int UpdateEntry(lua_State* L, Creature* creature)
    {
        uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);
        uint32 dataGuidLow = Eluna::CHECKVAL<uint32>(L, 3, 0);

        creature->UpdateEntry(entry, dataGuidLow ? eObjectMgr->GetCreatureData(dataGuidLow) : NULL);
        return 0;
    }

    /**
     * Resets [Creature]'s loot mode to default
     */
    int ResetLootMode(lua_State* /*L*/, Creature* creature)
    {
        creature->ResetLootMode();
        return 0;
    }

    /**
     * Removes specified loot mode from [Creature]
     *
     * @param uint16 lootMode
     */
    int RemoveLootMode(lua_State* L, Creature* creature)
    {
        uint16 lootMode = Eluna::CHECKVAL<uint16>(L, 2);

        creature->RemoveLootMode(lootMode);
        return 0;
    }

    /**
     * Adds a loot mode to the [Creature]
     *
     * @param uint16 lootMode
     */
    int AddLootMode(lua_State* L, Creature* creature)
    {
        uint16 lootMode = Eluna::CHECKVAL<uint16>(L, 2);

        creature->AddLootMode(lootMode);
        return 0;
    }

    /**
     * Returns the [Creature]'s creature family ID (enumerated in CreatureFamily.dbc).
     *
     * <pre>
     * enum CreatureFamily
     * {
     *     CREATURE_FAMILY_NONE                = 0,    // TrinityCore only
     *     CREATURE_FAMILY_WOLF                = 1,
     *     CREATURE_FAMILY_CAT                 = 2,
     *     CREATURE_FAMILY_SPIDER              = 3,
     *     CREATURE_FAMILY_BEAR                = 4,
     *     CREATURE_FAMILY_BOAR                = 5,
     *     CREATURE_FAMILY_CROCOLISK           = 6,
     *     CREATURE_FAMILY_CARRION_BIRD        = 7,
     *     CREATURE_FAMILY_CRAB                = 8,
     *     CREATURE_FAMILY_GORILLA             = 9,
     *     CREATURE_FAMILY_HORSE_CUSTOM        = 10,   // Does not exist in DBC but used for horse like beasts in DB
     *     CREATURE_FAMILY_RAPTOR              = 11,
     *     CREATURE_FAMILY_TALLSTRIDER         = 12,
     *     CREATURE_FAMILY_FELHUNTER           = 15,
     *     CREATURE_FAMILY_VOIDWALKER          = 16,
     *     CREATURE_FAMILY_SUCCUBUS            = 17,
     *     CREATURE_FAMILY_DOOMGUARD           = 19,
     *     CREATURE_FAMILY_SCORPID             = 20,
     *     CREATURE_FAMILY_TURTLE              = 21,
     *     CREATURE_FAMILY_IMP                 = 23,
     *     CREATURE_FAMILY_BAT                 = 24,
     *     CREATURE_FAMILY_HYENA               = 25,
     *     CREATURE_FAMILY_BIRD_OF_PREY        = 26,   // Named CREATURE_FAMILY_OWL in Mangos
     *     CREATURE_FAMILY_WIND_SERPENT        = 27,
     *     CREATURE_FAMILY_REMOTE_CONTROL      = 28,
     *     CREATURE_FAMILY_FELGUARD            = 29,   // This and below is TBC+
     *     CREATURE_FAMILY_DRAGONHAWK          = 30,
     *     CREATURE_FAMILY_RAVAGER             = 31,
     *     CREATURE_FAMILY_WARP_STALKER        = 32,
     *     CREATURE_FAMILY_SPOREBAT            = 33,
     *     CREATURE_FAMILY_NETHER_RAY          = 34,
     *     CREATURE_FAMILY_SERPENT             = 35,
     *     CREATURE_FAMILY_SEA_LION            = 36,   // TBC only
     *     CREATURE_FAMILY_MOTH                = 37,   // This and below is WotLK+
     *     CREATURE_FAMILY_CHIMAERA            = 38,
     *     CREATURE_FAMILY_DEVILSAUR           = 39,
     *     CREATURE_FAMILY_GHOUL               = 40,
     *     CREATURE_FAMILY_SILITHID            = 41,
     *     CREATURE_FAMILY_WORM                = 42,
     *     CREATURE_FAMILY_RHINO               = 43,
     *     CREATURE_FAMILY_WASP                = 44,
     *     CREATURE_FAMILY_CORE_HOUND          = 45,
     *     CREATURE_FAMILY_SPIRIT_BEAST        = 46
     * };
     * </pre>
     *
     * @return [CreatureFamily] creatureFamily
     */
    int GetCreatureFamily(lua_State* L, Creature* creature)
    {
        uint32 entry = creature->GetEntry();

        CreatureTemplate const* cInfo = sObjectMgr->GetCreatureTemplate(entry);
        if (cInfo)
            Eluna::Push(L, cInfo->family);

        return 1;
    }
    
    ElunaRegister<Creature> CreatureMethods[] =
    {
        // Getters
        { "GetAITarget", &LuaCreature::GetAITarget },
        { "GetAITargets", &LuaCreature::GetAITargets },
        { "GetAITargetsCount", &LuaCreature::GetAITargetsCount },
        { "GetHomePosition", &LuaCreature::GetHomePosition },
        { "GetCorpseDelay", &LuaCreature::GetCorpseDelay },
        { "GetCreatureSpellCooldownDelay", &LuaCreature::GetCreatureSpellCooldownDelay },
        { "GetScriptId", &LuaCreature::GetScriptId },
        { "GetAIName", &LuaCreature::GetAIName },
        { "GetScriptName", &LuaCreature::GetScriptName },
        { "GetAttackDistance", &LuaCreature::GetAttackDistance },
        { "GetAggroRange", &LuaCreature::GetAggroRange },
        { "GetDefaultMovementType", &LuaCreature::GetDefaultMovementType },
        { "GetRespawnDelay", &LuaCreature::GetRespawnDelay },
        { "GetWanderRadius", &LuaCreature::GetWanderRadius },
        { "GetCurrentWaypointId", &LuaCreature::GetCurrentWaypointId },
        { "GetWaypointPath", &LuaCreature::GetWaypointPath },
        { "GetLootMode", &LuaCreature::GetLootMode },
        { "GetLootRecipient", &LuaCreature::GetLootRecipient },
        { "GetLootRecipientGroup", &LuaCreature::GetLootRecipientGroup },
        { "GetNPCFlags", &LuaCreature::GetNPCFlags },
        { "GetExtraFlags", &LuaCreature::GetExtraFlags },
#ifndef CATA
        { "GetShieldBlockValue", &LuaCreature::GetShieldBlockValue },
#endif
        { "GetDBTableGUIDLow", &LuaCreature::GetDBTableGUIDLow },
        { "GetCreatureFamily", &LuaCreature::GetCreatureFamily },

        // Setters
        { "SetRegeneratingHealth", &LuaCreature::SetRegeneratingHealth },
        { "SetHover", &LuaCreature::SetHover },
        { "SetDisableGravity", &LuaCreature::SetDisableGravity },
        { "SetAggroEnabled", &LuaCreature::SetAggroEnabled },
        { "SetNoCallAssistance", &LuaCreature::SetNoCallAssistance },
        { "SetNoSearchAssistance", &LuaCreature::SetNoSearchAssistance },
        { "SetDefaultMovementType", &LuaCreature::SetDefaultMovementType },
        { "SetRespawnDelay", &LuaCreature::SetRespawnDelay },
        { "SetWanderRadius", &LuaCreature::SetWanderRadius },
        { "SetInCombatWithZone", &LuaCreature::SetInCombatWithZone },
        { "SetDisableReputationGain", &LuaCreature::SetDisableReputationGain },
        { "SetLootMode", &LuaCreature::SetLootMode },
        { "SetNPCFlags", &LuaCreature::SetNPCFlags },
        { "SetReactState", &LuaCreature::SetReactState },
        { "SetDeathState", &LuaCreature::SetDeathState },
        { "SetWalk", &LuaCreature::SetWalk },
        { "SetHomePosition", &LuaCreature::SetHomePosition },
        { "SetEquipmentSlots", &LuaCreature::SetEquipmentSlots },

        // Boolean
        { "IsRegeneratingHealth", &LuaCreature::IsRegeneratingHealth },
        { "IsDungeonBoss", &LuaCreature::IsDungeonBoss },
        { "IsWorldBoss", &LuaCreature::IsWorldBoss },
        { "IsRacialLeader", &LuaCreature::IsRacialLeader },
        { "IsCivilian", &LuaCreature::IsCivilian },
        { "IsTrigger", &LuaCreature::IsTrigger },
        { "IsGuard", &LuaCreature::IsGuard },
        { "IsElite", &LuaCreature::IsElite },
        { "IsInEvadeMode", &LuaCreature::IsInEvadeMode },
        { "HasCategoryCooldown", &LuaCreature::HasCategoryCooldown },
        { "CanWalk", &LuaCreature::CanWalk },
        { "CanSwim", &LuaCreature::CanSwim },
        { "CanAggro", &LuaCreature::CanAggro },
        { "CanStartAttack", &LuaCreature::CanStartAttack },
        { "HasSearchedAssistance", &LuaCreature::HasSearchedAssistance },
        { "IsTappedBy", &LuaCreature::IsTappedBy },
        { "HasLootRecipient", &LuaCreature::HasLootRecipient },
        { "CanAssistTo", &LuaCreature::CanAssistTo },
        { "IsTargetableForAttack", &LuaCreature::IsTargetableForAttack },
        { "CanCompleteQuest", &LuaCreature::CanCompleteQuest },
        { "IsReputationGainDisabled", &LuaCreature::IsReputationGainDisabled },
        { "IsDamageEnoughForLootingAndReward", &LuaCreature::IsDamageEnoughForLootingAndReward },
        { "HasLootMode", &LuaCreature::HasLootMode },
        { "HasSpell", &LuaCreature::HasSpell },
        { "HasQuest", &LuaCreature::HasQuest },
        { "HasSpellCooldown", &LuaCreature::HasSpellCooldown },
        { "CanFly", &LuaCreature::CanFly },

        // Other
        { "FleeToGetAssistance", &LuaCreature::FleeToGetAssistance },
        { "CallForHelp", &LuaCreature::CallForHelp },
        { "CallAssistance", &LuaCreature::CallAssistance },
        { "RemoveCorpse", &LuaCreature::RemoveCorpse },
        { "DespawnOrUnsummon", &LuaCreature::DespawnOrUnsummon },
        { "Respawn", &LuaCreature::Respawn },
        { "AttackStart", &LuaCreature::AttackStart },
        { "AddLootMode", &LuaCreature::AddLootMode },
        { "ResetLootMode", &LuaCreature::ResetLootMode },
        { "RemoveLootMode", &LuaCreature::RemoveLootMode },
        { "SaveToDB", &LuaCreature::SaveToDB },
        { "SelectVictim", &LuaCreature::SelectVictim },
        { "MoveWaypoint", &LuaCreature::MoveWaypoint },
        { "UpdateEntry", &LuaCreature::UpdateEntry },

#ifdef CATA //Not implemented in TCPP
        { "GetShieldBlockValue", nullptr },
#endif

        { NULL, NULL }
    };
};
#endif
