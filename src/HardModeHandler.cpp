#include "HardModeHandler.h"
#include "HardModeTypes.h"

#include "DatabaseEnv.h"
#include "Log.h"

void HardModeHandler::LoadHardModes()
{
    QueryResult qResult = WorldDatabase.Query("SELECT `id`, `name`, `description`, `restrictions`, `enabled` FROM `hardmode_modes`");

    if (qResult)
    {
        uint32 count = 0;

        do
        {
            Field* fields = qResult->Fetch();

            uint32 id = fields[0].Get<int32>();
            std::string name = fields[1].Get<std::string>();
            std::string description = fields[2].Get<std::string>();
            uint64 restrictions = fields[3].Get<uint64>();
            bool enabled = fields[4].Get<bool>();

            HardModeInfo mode;
            mode.Id = id;
            mode.Name = name;
            mode.Description = description;
            mode.Restrictions = restrictions;
            mode.Enabled = enabled;

            _hardModes.push_back(mode);

            count++;
        } while (qResult->NextRow());

        LOG_INFO("module", "Loaded '{}' rows from 'hardmode_modes' table.", count);
    }
    else
    {
        LOG_INFO("module", "Loaded '0' rows from 'hardmode_modes' table.");
    }
}

void HardModeHandler::ClearHardModes()
{
    _hardModes.clear();
}

std::vector<HardModeInfo>* HardModeHandler::GetHardModes()
{
    return &_hardModes;
}

bool HardModeHandler::IsModeEnabledForPlayer(Player* player, uint8 mode)
{
    return player->GetPlayerSetting("HardMode", mode).value > 0;
}

void HardModeHandler::UpdateModeForPlayer(Player* player, uint8 mode, bool state)
{
    player->UpdatePlayerSetting("HardMode", mode, state);
}

bool HardModeHandler::IsPlayerTainted(Player* player)
{
    return player->GetPlayerSetting("HardModeTainted", 0).value > 0;
}

void HardModeHandler::UpdatePlayerTainted(Player* player, bool state)
{
    player->UpdatePlayerSetting("HardModeTainted", 0, state);
}

bool HardModeHandler::IsPlayerShadowBanned(Player* player)
{
    return player->GetPlayerSetting("HardModeShadowBanned", 0).value > 0;
}

void HardModeHandler::UpdatePlayerShadowBanned(Player* player, bool state)
{
    player->UpdatePlayerSetting("HardModeShadowBanned", 0, state);
}

std::string HardModeHandler::GetNamesFromEnabledModes(Player* player)
{
    std::stringstream ss;
    std::vector<HardModeInfo> modes;

    auto hardModes = sHardModeHandler->GetHardModes();
    for (auto mode = hardModes->begin(); mode != hardModes->end(); ++mode)
    {
        if (sHardModeHandler->IsModeEnabledForPlayer(player, mode->Id))
        {
            modes.push_back(*mode);
        }
    }

    for (uint8 i = 0; i < modes.size(); ++i)
    {
        ss << modes[i].Name;

        if (i != modes.size() - 1)
        {
            ss << ", ";
        }
    }

    return ss.str();
}

std::string HardModeHandler::GetNameFromMode(uint8 mode)
{
    auto hardModes = sHardModeHandler->GetHardModes();
    for (auto it = hardModes->begin(); it != hardModes->end(); ++it)
    {
        if (it->Id == mode)
        {
            return it->Name;
        }
    }

    return "Unknown";
}
