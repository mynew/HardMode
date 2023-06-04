#ifndef MODULE_HARDMODE_TYPES_H
#define MODULE_HARDMODE_TYPES_H

#include "Common.h"

#include <vector>

enum HardModeConstants
{
    HARDMODE_MAIL_SENDER = 441102,
    HARDMODE_AURA_SHADOWBAN = 45681,
    HARDMODE_AREA_AZSHARACRATER = 37,
    HARDMODE_AREA_SHADOWTOMB = 3888,
    HARDMODE_AREA_UNKNOWN = 4988,
    HARDMODE_AREA_EBONHOLD = 609,
    HARDMODE_QUEST_DK_INITIAL = 12593,
    HARDMODE_AURA_PACIFIST_FAIL = 46221
};

constexpr float SMALLFISH_SCALE = 0.5f;

struct HardModeInfo
{
    uint8 Id;
    std::string Name;
    std::string Description;
    uint64 Restrictions;
    bool Enabled;
};

struct HardModePlayerSettings
{
    std::vector<uint8> Modes;
    bool Tainted;
    bool ShadowBanned;
};

enum HardModeRestrictions
{
	HARDMODE_RESTRICT_NONE =                        0,  // 用于内部，不要使用
	HARDMODE_RESTRICT_RETAIL_XP =                   1,  // 2: 玩家只能从击杀、任务等获得1倍的经验值
	HARDMODE_RESTRICT_SELFCRAFTED =                 2,  // 4: 玩家只能使用自己制作的物品（装备，武器，消耗品等）
	HARDMODE_RESTRICT_INTERACT_AUCTION =            3,  // 8: 玩家不能与拍卖行互动
	HARDMODE_RESTRICT_INTERACT_GUILDBANK =          4,  // 16: 玩家不能与公会银行互动
	HARDMODE_RESTRICT_INTERACT_MAIL_SEND =          5,  // 32: 玩家不能发送邮件
	HARDMODE_RESTRICT_INTERACT_MAIL_RECEIVE =       6,  // 64: 玩家不能接收邮件
	HARDMODE_RESTRICT_INTERACT_TRADE =              7,  // 128: 玩家不能进行交易/被交易
	HARDMODE_RESTRICT_PERMADEATH =                  8,  // 256: 玩家死亡后将被送到阴影墓地
	HARDMODE_RESTRICT_HIDE_WHOLIST =                9,  // 512: 玩家的位置在谁名单上被隐藏
	HARDMODE_RESTRICT_HIDE_FRIENDS =                10, // 1024, 玩家的位置在好友名单上被隐藏
	HARDMODE_RESTRICT_HIDE_GUILD =                  11, // 2048, 玩家的位置在公会名册上被隐藏
	HARDMODE_RESTRICT_INTERACT_LFG =                12, // 4096, 玩家不能排队LFG
	HARDMODE_RESTRICT_INTERACT_GROUP =              13, // 8192, 玩家不能加入团队
	HARDMODE_RESTRICT_INTERACT_GROUP_CROSSPLAY =    14, // 16384 玩家只能与相同模式的玩家组队
	HARDMODE_RESTRICT_BAD_LUCK =                    15, // 32768 玩家在战利品掉落上运气不好
	HARDMODE_RESTRICT_PACIFIST =                    16, // 65536 如果玩家伤害或杀死单位，他们会失去模式
	HARDMODE_RESTRICT_INTERACT_GROUP_RANGE =        17, // 131072 玩家只能与他们自己的x（默认为3）级别范围内的其他玩家组队
	HARDMODE_RESTRICT_INTERACT_TALENTS =            18, // 262144 玩家不能使用天赋点
	HARDMODE_RESTRICT_SMALLFISH =                   19, // 524288 玩家的体型，速度和伤害都减半
	HARDMODE_RESTRICT_COUNT =                       20,  // 用于内部。不要使用
};

enum HardModeRewardType
{
    HARDMODE_REWARD_TYPE_ITEM = 0,
    HARDMODE_REWARD_TYPE_TITLE = 1,
    HARDMODE_REWARD_TYPE_SPELL = 2
};

struct HardModeReward
{
    uint32 Mode;
    uint32 Level;
    uint32 Type;
    uint32 RewardId;
    uint32 RewardCount;
};

#endif // MODULE_HARDMODE_TYPES_H
