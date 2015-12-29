
#pragma once

#include "Plugin.h"
#include "WebPlugin.h"





class cSharedLibrary;





class cPluginC :
	public cPlugin,
	public cWebPlugin
{
	typedef cPlugin super;

public:
	cPluginC(const AString &);
	~cPluginC() override;
	
	void OnDisable() override;

	bool Load() override;
	void Unload() override;

	void Tick(float) override;

	bool OnBlockSpread(cWorld &, int, int, int, eSpreadSource) override;
	bool OnBlockToPickups(cWorld &, cEntity *, int, int, int, BLOCKTYPE, NIBBLETYPE, cItems &) override;
	bool OnBrewingCompleting(cWorld &, cBrewingstandEntity &) override;
	bool OnBrewingCompleted(cWorld &, cBrewingstandEntity &) override;
	bool OnChat(cPlayer &, AString &) override;
	bool OnChunkAvailable(cWorld &, int, int) override;
	bool OnChunkGenerated(cWorld &, int, int, cChunkDesc *) override;
	bool OnChunkGenerating(cWorld &, int, int, cChunkDesc *) override;
	bool OnChunkUnloaded(cWorld &, int, int) override;
	bool OnChunkUnloading(cWorld &, int, int) override;
	bool OnCollectingPickup(cPlayer &, cPickup &) override;
	bool OnCraftingNoRecipe(cPlayer &, cCraftingGrid &, cCraftingRecipe &) override;
	bool OnDisconnect(cClientHandle &, const AString &) override;
	bool OnEntityAddEffect(cEntity &, int, int, int, double) override;
	bool OnEntityTeleport(cEntity &, const Vector3d &, const Vector3d &) override;
	bool OnEntityChangingWorld(cEntity &, cWorld &) override;
	bool OnEntityChangedWorld(cEntity &, cWorld &) override;
	bool OnExecuteCommand(cPlayer *, const AStringVector &, const AString &, cPluginManager::CommandResult &) override;
	bool OnExploded(cWorld &, double, bool, double, double, double, eExplosionSource, void *) override;
	bool OnExploding(cWorld &, double &, bool &, double, double, double, eExplosionSource, void *) override;
	bool OnHandshake(cClientHandle &, const AString &) override;
	bool OnHopperPullingItem(cWorld &, cHopperEntity &, int, cBlockEntityWithItems &, int) override;
	bool OnHopperPushingItem(cWorld &, cHopperEntity &, int, cBlockEntityWithItems &, int) override;
	bool OnKilled(cEntity &, TakeDamageInfo &, AString &) override;
	bool OnKilling(cEntity &, cEntity *, TakeDamageInfo &) override;
	bool OnLogin(cClientHandle &, UInt32, const AString &) override;
	bool OnPlayerAnimation(cPlayer &, int) override;
	bool OnPlayerBreakingBlock(cPlayer &, int, int, int, char, BLOCKTYPE, NIBBLETYPE) override;
	bool OnPlayerBrokenBlock(cPlayer &, int, int, int, char, BLOCKTYPE, NIBBLETYPE) override;
	bool OnPlayerDestroyed(cPlayer &) override;
	bool OnPlayerEating(cPlayer &) override;
	bool OnPlayerFished(cPlayer &, const cItems &) override;
	bool OnPlayerFishing(cPlayer &, cItems &) override;
	bool OnPlayerFoodLevelChange(cPlayer &, int) override;
	bool OnPlayerJoined(cPlayer &) override;
	bool OnPlayerLeftClick(cPlayer &, int, int, int, char, char) override;
	bool OnPlayerMoving(cPlayer &, const Vector3d &, const Vector3d &) override;
	bool OnPlayerPlacedBlock(cPlayer &, const sSetBlock &) override;
	bool OnPlayerPlacingBlock(cPlayer &, const sSetBlock &) override;
	bool OnPlayerRightClick(cPlayer &, int, int, int, char, int, int, int) override;
	bool OnPlayerRightClickingEntity(cPlayer &, cEntity &) override;
	bool OnPlayerShooting(cPlayer &) override;
	bool OnPlayerSpawned(cPlayer &) override;
	bool OnPlayerTossingItem(cPlayer &) override;
	bool OnPlayerUsedBlock(cPlayer &, int, int, int, char, int, int, int, BLOCKTYPE, NIBBLETYPE) override;
	bool OnPlayerUsedItem(cPlayer &, int, int, int, char, int, int, int) override;
	bool OnPlayerUsingBlock(cPlayer &, int, int, int, char, int, int, int, BLOCKTYPE, NIBBLETYPE) override;
	bool OnPlayerUsingItem(cPlayer &, int, int, int, char, int, int, int) override;
	bool OnPluginMessage(cClientHandle &, const AString &, const AString &) override;
	bool OnPluginsLoaded() override;
	bool OnPostCrafting(cPlayer &, cCraftingGrid &, cCraftingRecipe &) override;
	bool OnPreCrafting(cPlayer &, cCraftingGrid &, cCraftingRecipe &) override;
	bool OnProjectileHitBlock(cProjectileEntity &, int, int, int, eBlockFace, const Vector3d &) override;
	bool OnProjectileHitEntity(cProjectileEntity &, cEntity &) override;
	bool OnServerPing(cClientHandle &, AString &, int &, int &, AString &) override;
	bool OnSpawnedEntity(cWorld &, cEntity &) override;
	bool OnSpawnedMonster(cWorld &, cMonster &) override;
	bool OnSpawningEntity(cWorld &, cEntity &) override;
	bool OnSpawningMonster(cWorld &, cMonster &) override;
	bool OnTakeDamage(cEntity &, TakeDamageInfo &) override;
	bool OnUpdatedSign(cWorld &, int, int, int, const AString &, const AString &, const AString &, const AString &, cPlayer *) override;
	bool OnUpdatingSign(cWorld &, int, int, int, AString &, AString &, AString &, AString &, cPlayer *) override;
	bool OnWeatherChanged(cWorld &) override;
	bool OnWeatherChanging(cWorld &, eWeather &) override;
	bool OnWorldStarted(cWorld &) override;
	bool OnWorldTick(cWorld &, std::chrono::milliseconds, std::chrono::milliseconds) override;
	
	bool HandleCommand(const AStringVector &, cPlayer &, const AString &) override;
	bool HandleConsoleCommand(const AStringVector &, cCommandOutputCallback &, const AString &) override;
	
	void ClearCommands() override;
	void ClearConsoleCommands() override;

	const AString GetWebTitle() const override;
	AString HandleWebRequest(const HTTPRequest &) override;
private:
	cCriticalSection m_CriticalSection;

	cSharedLibrary m_Module;
};




