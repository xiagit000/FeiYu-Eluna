/*
* Copyright (C) 2010 - 2016 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

#ifndef ITEMMETHODS_H
#define ITEMMETHODS_H

/***
 * Inherits all methods from: [Object]
 */
namespace LuaItem
{
    /**
     * Returns 'true' if the [Item] is soulbound, 'false' otherwise
     *
     * @return bool isSoulBound
     */
    int IsSoulBound(lua_State* L, Item* item)
    {
        Eluna::Push(L, item->IsSoulBound());
        return 1;
    }

    /**
     * Returns 'true' if the [Item] is account bound, 'false' otherwise
     *
     * @return bool isAccountBound
     */
    int IsBoundAccountWide(lua_State* L, Item* item)
    {
        Eluna::Push(L, item->IsBoundAccountWide());
        return 1;
    }

    /**
     * Returns 'true' if the [Item] is bound to a [Player] by an enchant, 'false' otehrwise
     *
     * @return bool isBoundByEnchant
     */
    int IsBoundByEnchant(lua_State* L, Item* item)
    {
        Eluna::Push(L, item->IsBoundByEnchant());
        return 1;
    }

    /**
     * Returns 'true' if the [Item] is not bound to the [Player] specified, 'false' otherwise
     *
     * @param [Player] player : the [Player] object to check the item against
     * @return bool isNotBound
     */
    int IsNotBoundToPlayer(lua_State* L, Item* item)
    {
        Player* player = Eluna::CHECKOBJ<Player>(L, 2);

        Eluna::Push(L, item->IsBindedNotWith(player));
        return 1;
    }

    /**
     * Returns 'true' if the [Item] is locked, 'false' otherwise
     *
     * @return bool isLocked
     */
    int IsLocked(lua_State* L, Item* item)
    {
        Eluna::Push(L, item->IsLocked());
        return 1;
    }

    /**
     * Returns 'true' if the [Item] is a bag, 'false' otherwise
     *
     * @return bool isBag
     */
    int IsBag(lua_State* L, Item* item)
    {
        Eluna::Push(L, item->IsBag());
        return 1;
    }

    /**
     * Returns 'true' if the [Item] is a currency token, 'false' otherwise
     *
     * @return bool isCurrencyToken
     */
    int IsCurrencyToken(lua_State* L, Item* item)
    {
        Eluna::Push(L, item->IsCurrencyToken());
        return 1;
    }

    /**
     * Returns 'true' if the [Item] is a not an empty bag, 'false' otherwise
     *
     * @return bool isNotEmptyBag
     */
    int IsNotEmptyBag(lua_State* L, Item* item)
    {
        Eluna::Push(L, item->IsNotEmptyBag());
        return 1;
    }

    /**
     * Returns 'true' if the [Item] is broken, 'false' otherwise
     *
     * @return bool isBroken
     */
    int IsBroken(lua_State* L, Item* item)
    {
        Eluna::Push(L, item->IsBroken());
        return 1;
    }

    /**
     * Returns 'true' if the [Item] can be traded, 'false' otherwise
     *
     * @return bool isTradeable
     */
    int CanBeTraded(lua_State* L, Item* item)
    {
        bool mail = Eluna::CHECKVAL<bool>(L, 2, false);

        Eluna::Push(L, item->CanBeTraded(mail));
        return 1;
    }

    /**
     * Returns 'true' if the [Item] is currently in a trade window, 'false' otherwise
     *
     * @return bool isInTrade
     */
    int IsInTrade(lua_State* L, Item* item)
    {
        Eluna::Push(L, item->IsInTrade());
        return 1;
    }

    /**
     * Returns 'true' if the [Item] is currently in a bag, 'false' otherwise
     *
     * @return bool isInBag
     */
    int IsInBag(lua_State* L, Item* item)
    {
        Eluna::Push(L, item->IsInBag());
        return 1;
    }

    /**
     * Returns 'true' if the [Item] is currently equipped, 'false' otherwise
     *
     * @return bool isEquipped
     */
    int IsEquipped(lua_State* L, Item* item)
    {
        Eluna::Push(L, item->IsEquipped());
        return 1;
    }

    /**
     * Returns 'true' if the [Item] has the [Quest] specified tied to it, 'false' otherwise
     *
     * @param uint32 questId : the [Quest] id to be checked
     * @return bool hasQuest
     */
    int HasQuest(lua_State* L, Item* item)
    {
        uint32 quest = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, item->hasQuest(quest));
        return 1;
    }

    /**
     * Returns 'true' if the [Item] is a potion, 'false' otherwise
     *
     * @return bool isPotion
     */
    int IsPotion(lua_State* L, Item* item)
    {
        Eluna::Push(L, item->IsPotion());
        return 1;
    }

#if defined(WOTLK)
    /**
     * Returns 'true' if the [Item] is a weapon vellum, 'false' otherwise
     *
     * @return bool isWeaponVellum
     */
    int IsWeaponVellum(lua_State* L, Item* item)
    {
        Eluna::Push(L, item->IsWeaponVellum());
        return 1;
    }

    /**
     * Returns 'true' if the [Item] is an armor vellum, 'false' otherwise
     *
     * @return bool isArmorVellum
     */
    int IsArmorVellum(lua_State* L, Item* item)
    {
        Eluna::Push(L, item->IsArmorVellum());
        return 1;
    }
#endif

    /**
     * Returns 'true' if the [Item] is a conjured consumable, 'false' otherwise
     *
     * @return bool isConjuredConsumable
     */
    int IsConjuredConsumable(lua_State* L, Item* item)
    {
        Eluna::Push(L, item->IsConjuredConsumable());
        return 1;
    }

#ifndef CATA
    int IsRefundExpired(lua_State* L, Item* item)
    {
        Eluna::Push(L, item->IsRefundExpired());
        return 1;
    }
#endif

    /**
     * Returns the chat link of the [Item]
     *
     * <pre>
     * enum LocaleConstant
     * {
     *     LOCALE_enUS = 0,
     *     LOCALE_koKR = 1,
     *     LOCALE_frFR = 2,
     *     LOCALE_deDE = 3,
     *     LOCALE_zhCN = 4,
     *     LOCALE_zhTW = 5,
     *     LOCALE_esES = 6,
     *     LOCALE_esMX = 7,
     *     LOCALE_ruRU = 8
     * };
     * </pre>
     *
     * @param [LocaleConstant] locale = DEFAULT_LOCALE : locale to return the [Item]'s name in
     * @return string itemLink
     */
    int GetItemLink(lua_State* L, Item* item)
    {
        uint8 locale = Eluna::CHECKVAL<uint8>(L, 2, DEFAULT_LOCALE);
        if (locale >= TOTAL_LOCALES)
            return luaL_argerror(L, 2, "valid LocaleConstant expected");

        const ItemTemplate* temp = item->GetTemplate();
#ifdef CATA
        std::string name = temp->ExtendedData->Display1->Str[locale];
        if (ItemLocale const* il = eObjectMgr->GetItemLocale(temp->BasicData->ID))
#else
        std::string name = temp->Name1;
        if (ItemLocale const* il = eObjectMgr->GetItemLocale(temp->ItemId))
#endif
            ObjectMgr::GetLocaleString(il->Name, static_cast<LocaleConstant>(locale), name);

        if (int32 itemRandPropId = item->GetItemRandomPropertyId())
        {
#ifndef CATA
            std::array<char const*, 16> const* suffix = NULL;
#else
            char* const* suffix = NULL;
#endif
            if (itemRandPropId < 0)
            {
                const ItemRandomSuffixEntry* itemRandEntry = sItemRandomSuffixStore.LookupEntry(-item->GetItemRandomPropertyId());
                if (itemRandEntry)
                    suffix = &itemRandEntry->Name;
            }
            else
            {
                const ItemRandomPropertiesEntry* itemRandEntry = sItemRandomPropertiesStore.LookupEntry(item->GetItemRandomPropertyId());
                if (itemRandEntry)
                    suffix = &itemRandEntry->Name;
            }
            if (suffix)
            {
                name += ' ';
#ifndef CATA
                name += (*suffix)[(name != temp->Name1) ? locale : uint8(DEFAULT_LOCALE)];
#else
                name += (*suffix)[(name != temp->ExtendedData->Display->Str[locale]) ? locale : uint8(DEFAULT_LOCALE)];
#endif
            }
        }

        std::ostringstream oss;
#ifdef CATA
        oss << "|c" << std::hex << ItemQualityColors[temp->ExtendedData->Quality] << std::dec <<
            "|Hitem:" << temp->BasicData->ID << ":" <<
#else
        oss << "|c" << std::hex << ItemQualityColors[temp->Quality] << std::dec <<
            "|Hitem:" << temp->ItemId << ":" <<
#endif
            item->GetEnchantmentId(PERM_ENCHANTMENT_SLOT) << ":" <<
            item->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT) << ":" <<
            item->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2) << ":" <<
            item->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3) << ":" <<
            item->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT) << ":" <<
            item->GetItemRandomPropertyId() << ":" << item->GetItemSuffixFactor() << ":" <<
            (uint32)item->GetOwner()->GetLevel() << "|h[" << name << "]|h|r";

        Eluna::Push(L, oss.str());
        return 1;
    }

    int GetOwnerGUID(lua_State* L, Item* item)
    {
        Eluna::Push(L, item->GetOwnerGUID());
        return 1;
    }

    /**
     * Returns the [Player] who currently owns the [Item]
     *
     * @return [Player] player : the [Player] who owns the [Item]
     */
    int GetOwner(lua_State* L, Item* item)
    {
        Eluna::Push(L, item->GetOwner());
        return 1;
    }

    /**
     * Returns the [Item]s stack count
     *
     * @return uint32 count
     */
    int GetCount(lua_State* L, Item* item)
    {
        Eluna::Push(L, item->GetCount());
        return 1;
    }

    /**
     * Returns the [Item]s max stack count
     *
     * @return uint32 maxCount
     */
    int GetMaxStackCount(lua_State* L, Item* item)
    {
        Eluna::Push(L, item->GetMaxStackCount());
        return 1;
    }

    /**
     * Returns the [Item]s current slot
     *
     * @return uint8 slot
     */
    int GetSlot(lua_State* L, Item* item)
    {
        Eluna::Push(L, item->GetSlot());
        return 1;
    }

    /**
     * Returns the [Item]s current bag slot
     *
     * @return uint8 bagSlot
     */
    int GetBagSlot(lua_State* L, Item* item)
    {
        Eluna::Push(L, item->GetBagSlot());
        return 1;
    }

    /**
     * Returns the [Item]s enchantment ID by enchant slot specified
     *
     * @param [EnchantmentSlot] enchantSlot : the enchant slot specified
     * @return uint32 enchantId : the id of the enchant slot specified
     */
    int GetEnchantmentId(lua_State* L, Item* item)
    {
        uint32 enchant_slot = Eluna::CHECKVAL<uint32>(L, 2);

        if (enchant_slot >= MAX_INSPECTED_ENCHANTMENT_SLOT)
            return luaL_argerror(L, 2, "valid EnchantmentSlot expected");

        Eluna::Push(L, item->GetEnchantmentId(EnchantmentSlot(enchant_slot)));
        return 1;
    }

    /**
     * Returns the spell ID tied to the [Item] by spell index
     *
     * @param uint32 spellIndex : the spell index specified
     * @return uint32 spellId : the id of the spell
     */
    int GetSpellId(lua_State* L, Item* item)
    {
        uint32 index = Eluna::CHECKVAL<uint32>(L, 2);
        if (index >= MAX_ITEM_PROTO_SPELLS)
            return luaL_argerror(L, 2, "valid SpellIndex expected");

#ifdef CATA
        Eluna::Push(L, item->GetTemplate()->ExtendedData->SpellID[index]);
#else
        Eluna::Push(L, item->GetTemplate()->Spells[index].SpellId);
#endif
        return 1;
    }

    /**
     * Returns the spell trigger tied to the [Item] by spell index
     *
     * @param uint32 spellIndex : the spell index specified
     * @return uint32 spellTrigger : the spell trigger of the specified index
     */
    int GetSpellTrigger(lua_State* L, Item* item)
    {
        uint32 index = Eluna::CHECKVAL<uint32>(L, 2);
        if (index >= MAX_ITEM_PROTO_SPELLS)
            return luaL_argerror(L, 2, "valid SpellIndex expected");

#ifdef CATA
        Eluna::Push(L, item->GetTemplate()->ExtendedData->SpellTrigger[index]);
#else
        Eluna::Push(L, item->GetTemplate()->Spells[index].SpellTrigger);
#endif
        return 1;
    }

    /**
     * Returns class of the [Item]
     *
     * @return uint32 class
     */
    int GetClass(lua_State* L, Item* item)
    {
#ifdef CATA
        Eluna::Push(L, item->GetTemplate()->GetClass());
#else
        Eluna::Push(L, item->GetTemplate()->Class);
#endif
        return 1;
    }

    /**
     * Returns subclass of the [Item]
     *
     * @return uint32 subClass
     */
    int GetSubClass(lua_State* L, Item* item)
    {
#ifdef CATA
        Eluna::Push(L, item->GetTemplate()->GetSubClass());
#else
        Eluna::Push(L, item->GetTemplate()->SubClass);
#endif
        return 1;
    }

    /**
     * Returns the name of the [Item]
     *
     * @return string name
     */
    int GetName(lua_State* L, Item* item)
    {
#ifdef CATA
        Eluna::Push(L, item->GetTemplate()->GetDefaultLocaleName());
#else
        Eluna::Push(L, item->GetTemplate()->Name1);
#endif
        return 1;
    }

    /**
     * Returns the display ID of the [Item]
     *
     * @return uint32 displayId
     */
    int GetDisplayId(lua_State* L, Item* item)
    {
#ifdef CATA
        Eluna::Push(L, item->GetTemplate()->GetDisplayID());
#else
        Eluna::Push(L, item->GetTemplate()->DisplayInfoID);
#endif
        return 1;
    }

    /**
     * Returns the quality of the [Item]
     *
     * @return uint32 quality
     */
    int GetQuality(lua_State* L, Item* item)
    {
#ifdef CATA
        Eluna::Push(L, item->GetTemplate()->GetQuality());
#else
        Eluna::Push(L, item->GetTemplate()->Quality);
#endif
        return 1;
    }

    /**
     * Returns the default purchase count of the [Item]
     *
     * @return uint32 count
     */
    int GetBuyCount(lua_State* L, Item* item)
    {
#ifdef CATA
        Eluna::Push(L, item->GetTemplate()->GetBuyCount());
#else
        Eluna::Push(L, item->GetTemplate()->BuyCount);
#endif
        return 1;
    }

    /**
     * Returns the purchase price of the [Item]
     *
     * @return uint32 price
     */
    int GetBuyPrice(lua_State* L, Item* item)
    {
#ifdef CATA
        Eluna::Push(L, item->GetTemplate()->GetBuyPrice());
#else
        Eluna::Push(L, item->GetTemplate()->BuyPrice);
#endif
        return 1;
    }

    /**
     * Returns the sell price of the [Item]
     *
     * @return uint32 price
     */
    int GetSellPrice(lua_State* L, Item* item)
    {
#ifdef CATA
        Eluna::Push(L, item->GetTemplate()->GetSellPrice());
#else
        Eluna::Push(L, item->GetTemplate()->SellPrice);
#endif
        return 1;
    }

    /**
     * Returns the inventory type of the [Item]
     *
     * @return uint32 inventoryType
     */
    int GetInventoryType(lua_State* L, Item* item)
    {
#ifdef CATA
        Eluna::Push(L, item->GetTemplate()->GetInventoryType());
#else
        Eluna::Push(L, item->GetTemplate()->InventoryType);
#endif
        return 1;
    }

    /**
     * Returns the [Player] classes allowed to use this [Item]
     *
     * @return uint32 allowableClass
     */
    int GetAllowableClass(lua_State* L, Item* item)
    {
#ifdef CATA
        Eluna::Push(L, item->GetTemplate()->GetAllowableClass());
#else
        Eluna::Push(L, item->GetTemplate()->AllowableClass);
#endif
        return 1;
    }

    /**
     * Returns the [Player] races allowed to use this [Item]
     *
     * @return uint32 allowableRace
     */
    int GetAllowableRace(lua_State* L, Item* item)
    {
#ifdef CATA
        Eluna::Push(L, item->GetTemplate()->GetAllowableRace());
#else
        Eluna::Push(L, item->GetTemplate()->AllowableRace);
#endif
        return 1;
    }

    /**
     * Returns the [Item]s level
     *
     * @return uint32 itemLevel
     */
    int GetItemLevel(lua_State* L, Item* item)
    {
#ifdef CATA
        Eluna::Push(L, item->GetTemplate()->GetBaseItemLevel());
#else
        Eluna::Push(L, item->GetTemplate()->ItemLevel);
#endif
        return 1;
    }

    /**
     * Returns the minimum level required to use this [Item]
     *
     * @return uint32 requiredLevel
     */
    int GetRequiredLevel(lua_State* L, Item* item)
    {
#ifdef CATA
        Eluna::Push(L, item->GetTemplate()->GetRequiredLevel());
#else
        Eluna::Push(L, item->GetTemplate()->RequiredLevel);
#endif
        return 1;
    }

#ifdef WOTLK
    int GetStatsCount(lua_State* L, Item* item)
    {
        Eluna::Push(L, item->GetTemplate()->StatsCount);
        return 1;
    }
#endif

    /**
     * Returns the random property ID of this [Item]
     *
     * @return uint32 randomPropertyId
     */
    int GetRandomProperty(lua_State* L, Item* item)
    {
#ifdef CATA
        Eluna::Push(L, item->GetTemplate()->GetRandomProperty());
#else
        Eluna::Push(L, item->GetTemplate()->RandomProperty);
#endif
        return 1;
    }

    int GetRandomSuffix(lua_State* L, Item* item)
    {
#ifdef CATA
        Eluna::Push(L, item->GetTemplate()->GetRandomSuffix());
#else
        Eluna::Push(L, item->GetTemplate()->RandomSuffix);
#endif
        return 1;
    }

    /**
     * Returns the item set ID of this [Item]
     *
     * @return uint32 itemSetId
     */
    int GetItemSet(lua_State* L, Item* item)
    {
#ifdef CATA
        Eluna::Push(L, item->GetTemplate()->GetItemSet());
#else
        Eluna::Push(L, item->GetTemplate()->ItemSet);
#endif
        return 1;
    }

    /**
     * Returns the bag size of this [Item], 0 if [Item] is not a bag
     *
     * @return uint32 bagSize
     */
    int GetBagSize(lua_State* L, Item* item)
    {
        if (Bag* bag = item->ToBag())
            Eluna::Push(L, bag->GetBagSize());
        else
            Eluna::Push(L, 0);
        return 1;
    }

    /**
     * Sets the [Player] specified as the owner of the [Item]
     *
     * @param [Player] player : the [Player] specified
     */
    int SetOwner(lua_State* L, Item* item)
    {
        Player* player = Eluna::CHECKOBJ<Player>(L, 2);

        item->SetOwnerGUID(player->GET_GUID());
        return 0;
    }

    /**
     * Sets the binding of the [Item] to 'true' or 'false'
     *
     * @param bool setBinding
     */
    int SetBinding(lua_State* L, Item* item)
    {
        bool soulbound = Eluna::CHECKVAL<bool>(L, 2);

        item->SetBinding(soulbound);
        item->SetState(ITEM_CHANGED, item->GetOwner());

        return 0;
    }

    /**
     * Sets the stack count of the [Item]
     *
     * @param uint32 count
     */
    int SetCount(lua_State* L, Item* item)
    {
        uint32 count = Eluna::CHECKVAL<uint32>(L, 2);
        item->SetCount(count);
        return 0;
    }

    /**
     * Sets the specified enchantment of the [Item] to the specified slot
     *
     * @param uint32 enchantId : the ID of the enchant to be applied
     * @param uint32 enchantSlot : the slot for the enchant to be applied to
     * @return bool enchantmentSuccess : if enchantment is successfully set to specified slot, returns 'true', otherwise 'false'
     */
    int SetEnchantment(lua_State* L, Item* item)
    {
        Player* owner = item->GetOwner();
        if (!owner)
        {
            Eluna::Push(L, false);
            return 1;
        }

        uint32 enchant = Eluna::CHECKVAL<uint32>(L, 2);
        if (!sSpellItemEnchantmentStore.LookupEntry(enchant))
        {
            Eluna::Push(L, false);
            return 1;
        }

        EnchantmentSlot slot = (EnchantmentSlot)Eluna::CHECKVAL<uint32>(L, 3);
        if (slot >= MAX_INSPECTED_ENCHANTMENT_SLOT)
            return luaL_argerror(L, 2, "valid EnchantmentSlot expected");

        owner->ApplyEnchantment(item, slot, false);
        item->SetEnchantment(slot, enchant, 0, 0);
        owner->ApplyEnchantment(item, slot, true);
        Eluna::Push(L, true);
        return 1;
    }

    /* OTHER */
    /**
     * Removes an enchant from the [Item] by the specified slot
     *
     * @param uint32 enchantSlot : the slot for the enchant to be removed from
     * @return bool enchantmentRemoved : if enchantment is successfully removed from specified slot, returns 'true', otherwise 'false'
     */
    int ClearEnchantment(lua_State* L, Item* item)
    {
        Player* owner = item->GetOwner();
        if (!owner)
        {
            Eluna::Push(L, false);
            return 1;
        }

        EnchantmentSlot slot = (EnchantmentSlot)Eluna::CHECKVAL<uint32>(L, 2);
        if (slot >= MAX_INSPECTED_ENCHANTMENT_SLOT)
            return luaL_argerror(L, 2, "valid EnchantmentSlot expected");

        if (!item->GetEnchantmentId(slot))
        {
            Eluna::Push(L, false);
            return 1;
        }

        owner->ApplyEnchantment(item, slot, false);
        item->ClearEnchantment(slot);
        Eluna::Push(L, true);
        return 1;
    }

    /**
     * Saves the [Item] to the database
     */
    int SaveToDB(lua_State* /*L*/, Item* item)
    {
        CharacterDatabaseTransaction trans = CharacterDatabaseTransaction(nullptr);
        item->SaveToDB(trans);
        return 0;
    }
    
    ElunaRegister<Item> ItemMethods[] =
    {
        // Getters
        { "GetOwnerGUID", &LuaItem::GetOwnerGUID },
        { "GetOwner", &LuaItem::GetOwner },
        { "GetCount", &LuaItem::GetCount },
        { "GetMaxStackCount", &LuaItem::GetMaxStackCount },
        { "GetSlot", &LuaItem::GetSlot },
        { "GetBagSlot", &LuaItem::GetBagSlot },
        { "GetEnchantmentId", &LuaItem::GetEnchantmentId },
        { "GetSpellId", &LuaItem::GetSpellId },
        { "GetSpellTrigger", &LuaItem::GetSpellTrigger },
        { "GetItemLink", &LuaItem::GetItemLink },
        { "GetClass", &LuaItem::GetClass },
        { "GetSubClass", &LuaItem::GetSubClass },
        { "GetName", &LuaItem::GetName },
        { "GetDisplayId", &LuaItem::GetDisplayId },
        { "GetQuality", &LuaItem::GetQuality },
        { "GetBuyCount", &LuaItem::GetBuyCount },
        { "GetBuyPrice", &LuaItem::GetBuyPrice },
        { "GetSellPrice", &LuaItem::GetSellPrice },
        { "GetInventoryType", &LuaItem::GetInventoryType },
        { "GetAllowableClass", &LuaItem::GetAllowableClass },
        { "GetAllowableRace", &LuaItem::GetAllowableRace },
        { "GetItemLevel", &LuaItem::GetItemLevel },
        { "GetRequiredLevel", &LuaItem::GetRequiredLevel },
#ifndef CATA
        { "GetStatsCount", &LuaItem::GetStatsCount },
#endif
        { "GetRandomProperty", &LuaItem::GetRandomProperty },
        { "GetRandomSuffix", &LuaItem::GetRandomSuffix },
        { "GetItemSet", &LuaItem::GetItemSet },
        { "GetBagSize", &LuaItem::GetBagSize },

        // Setters
        { "SetOwner", &LuaItem::SetOwner },
        { "SetBinding", &LuaItem::SetBinding },
        { "SetCount", &LuaItem::SetCount },

        // Boolean
        { "IsSoulBound", &LuaItem::IsSoulBound },
        { "IsBoundAccountWide", &LuaItem::IsBoundAccountWide },
        { "IsBoundByEnchant", &LuaItem::IsBoundByEnchant },
        { "IsNotBoundToPlayer", &LuaItem::IsNotBoundToPlayer },
        { "IsLocked", &LuaItem::IsLocked },
        { "IsBag", &LuaItem::IsBag },
        { "IsCurrencyToken", &LuaItem::IsCurrencyToken },
        { "IsNotEmptyBag", &LuaItem::IsNotEmptyBag },
        { "IsBroken", &LuaItem::IsBroken },
        { "CanBeTraded", &LuaItem::CanBeTraded },
        { "IsInTrade", &LuaItem::IsInTrade },
        { "IsInBag", &LuaItem::IsInBag },
        { "IsEquipped", &LuaItem::IsEquipped },
        { "HasQuest", &LuaItem::HasQuest },
        { "IsPotion", &LuaItem::IsPotion },
#ifndef CATA
        { "IsWeaponVellum", &LuaItem::IsWeaponVellum },
        { "IsArmorVellum", &LuaItem::IsArmorVellum },
        { "IsRefundExpired", &LuaItem::IsRefundExpired },
#endif
        { "IsConjuredConsumable", &LuaItem::IsConjuredConsumable },
        { "SetEnchantment", &LuaItem::SetEnchantment },
        { "ClearEnchantment", &LuaItem::ClearEnchantment },

        // Other
        { "SaveToDB", &LuaItem::SaveToDB },

#ifdef CATA //Not implemented in TCPP
        { "GetStatsCount", nullptr },
        { "IsWeaponVellum", nullptr },
        { "IsArmorVellum", nullptr },
        { "IsRefundExpired", nullptr },
#endif

        { NULL, NULL }
    };
};
#endif
