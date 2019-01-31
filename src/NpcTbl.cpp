#include <string>

#include <SDL_rwops.h>

#include "NpcTbl.h"
#include "NpcAct.h"

NPC_TABLE *gNpcTable;

bool LoadNpcTable(const char *path)
{
	SDL_RWops *fp = SDL_RWFromFile(path, "rb");

	if (fp == nullptr)
	{
		printf("LoadNpcTable failed\nSDL Error: %s\n", SDL_GetError());
		return false;
	}

	const size_t tblSize = SDL_RWsize(fp);

	const int npcCount = tblSize / 0x18;
	gNpcTable = (NPC_TABLE*)malloc(npcCount * sizeof(NPC_TABLE));

	for (size_t i = 0; i < npcCount; i++) //bits
		gNpcTable[i].bits = SDL_ReadLE16(fp);
	for (size_t i = 0; i < npcCount; i++) //life
		gNpcTable[i].life = SDL_ReadLE16(fp);
	for (size_t i = 0; i < npcCount; i++) //surf
		fp->read(fp, &gNpcTable[i].surf, 1, 1);
	for (size_t i = 0; i < npcCount; i++) //destroy_voice
		fp->read(fp, &gNpcTable[i].destroy_voice, 1, 1);
	for (size_t i = 0; i < npcCount; i++) //hit_voice
		fp->read(fp, &gNpcTable[i].hit_voice, 1, 1);
	for (size_t i = 0; i < npcCount; i++) //size
		fp->read(fp, &gNpcTable[i].size, 1, 1);
	for (size_t i = 0; i < npcCount; i++) //exp
		gNpcTable[i].exp = SDL_ReadLE32(fp);
	for (size_t i = 0; i < npcCount; i++) //damage
		gNpcTable[i].damage = SDL_ReadLE32(fp);
	for (size_t i = 0; i < npcCount; i++) //hit
		fp->read(fp, &gNpcTable[i].hit, 4, 1);
	for (size_t i = 0; i < npcCount; i++) //view
		fp->read(fp, &gNpcTable[i].view, 4, 1);
		
	SDL_RWclose(fp);	
	return true;
}

void ReleaseNpcTable()
{
	if (gNpcTable)
		free(gNpcTable);
}

//Npc function table
NPCFUNCTION gpNpcFuncTbl[361] =
{
	ActNpc000,
	ActNpc001,
	ActNpc002,
	ActNpc003,
	ActNpc004,
	ActNpc005,
	ActNpc006,
	ActNpc007,
	ActNpc008,
	nullptr,
	nullptr,
	nullptr,
	ActNpc012,
	nullptr,
	nullptr,
	ActNpc015,
	ActNpc016,
	ActNpc017,
	ActNpc018,
	ActNpc019,
	ActNpc020,
	ActNpc021,
	ActNpc022,
	ActNpc023,
	ActNpc024,
	ActNpc025,
	nullptr,
	nullptr,
	ActNpc028,
	ActNpc029,
	ActNpc030,
	nullptr,
	ActNpc032,
	nullptr,
	ActNpc034,
	nullptr,
	nullptr,
	ActNpc037,
	ActNpc038,
	ActNpc039,
	nullptr,
	ActNpc041,
	ActNpc042,
	ActNpc043,
	nullptr,
	nullptr,
	ActNpc046,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	ActNpc058,
	ActNpc059,
	ActNpc060,
	ActNpc061,
	ActNpc062,
	ActNpc063,
	ActNpc064,
	ActNpc065,
	ActNpc066,
	ActNpc067,
	ActNpc068,
	ActNpc069,
	ActNpc070,
	ActNpc071,
	ActNpc072,
	ActNpc073,
	ActNpc074,
	ActNpc075,
	ActNpc076,
	ActNpc077,
	ActNpc078,
	ActNpc079,
	ActNpc080,
	ActNpc081,
	nullptr,
	ActNpc083,
	ActNpc084,
	ActNpc085,
	ActNpc086,
	ActNpc087,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	ActNpc116,
	nullptr,
	nullptr,
	ActNpc119,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	ActNpc125,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	ActNpc145,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	ActNpc150,
	ActNpc151,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	ActNpc211,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	ActNpc278,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	ActNpc298,
	ActNpc299,
	ActNpc300,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	ActNpc355,
	nullptr,
	nullptr,
	nullptr,
	ActNpc359,
	nullptr,
};
