
#include "Globals.h"

#include <functional>
#include "OSSupport/SharedLibrary.h"
#include "PluginC.h"





cPluginC::cPluginC(const AString & a_FolderName) :
	super(a_FolderName)
{
}





cPluginC::~cPluginC()
{
	cCSLock Lock(m_CriticalSection);

	ClearTabs();
	ClearCommands();
	ClearConsoleCommands();

	m_Module.Close();
}





bool cPluginC::Load()
{
	cCSLock Lock(m_CriticalSection);

	if (m_Module.Load(FILE_IO_PREFIX + GetLocalFolder() + "/lib" + m_Name + ".so"))
	{
		std::function<int(void)> PluginInit = m_Module.RetrieveSymbol<int(void)>("Init");
		if (PluginInit)
		{
			m_Status = cPluginManager::psLoaded;
			return PluginInit() == 0;
		}

		SetLoadError("Function bool Init(void) was not found in this module.");
		return false;
	}

	SetLoadError("Failed to load module " + m_Name + ".");
	return false;
}





void cPluginC::Unload()
{
	cCSLock Lock(m_CriticalSection);

	ClearTabs();
	super::Unload();

	m_Module.Close();
}





void cPluginC::OnDisable()
{
	cCSLock Lock(m_CriticalSection);

	if (m_Module.IsLoaded())
	{
		std::function<void(void)> PluginOnDisable = m_Module.RetrieveSymbol<void(void)>("OnDisable");
		if (PluginOnDisable)
		{
			PluginOnDisable();
		}
	}
}





void cPluginC::Tick(float a_Dt)
{

}





bool cPluginC::OnBlockSpread(cWorld & a_World, int a_BlockX, int a_BlockY, int a_BlockZ, eSpreadSource a_Source)
{
	return false;
}





bool cPluginC::OnBlockToPickups(cWorld & a_World, cEntity * a_Digger, int a_BlockX, int a_BlockY, int a_BlockZ, BLOCKTYPE a_BlockType, NIBBLETYPE a_BlockMeta, cItems & a_Pickups)
{
	return false;
}





bool cPluginC::OnBrewingCompleting(cWorld & a_World, cBrewingstandEntity & a_BrewingstandEntity)
{
	return false;
}





bool cPluginC::OnBrewingCompleted(cWorld & a_World, cBrewingstandEntity & a_BrewingstandEntity)
{
	return false;
}





bool cPluginC::OnChat(cPlayer & a_Player, AString & a_Message)
{
	return false;
}





bool cPluginC::OnChunkAvailable(cWorld & a_World, int a_ChunkX, int a_ChunkZ)
{
	return false;
}





bool cPluginC::OnChunkGenerated(cWorld & a_World, int a_ChunkX, int a_ChunkZ, cChunkDesc * a_ChunkDesc)
{
	return false;
}





bool cPluginC::OnChunkGenerating(cWorld & a_World, int a_ChunkX, int a_ChunkZ, cChunkDesc * a_ChunkDesc)
{
	return false;
}





bool cPluginC::OnChunkUnloaded(cWorld & a_World, int a_ChunkX, int a_ChunkZ)
{
	return false;
}





bool cPluginC::OnChunkUnloading(cWorld & a_World, int a_ChunkX, int a_ChunkZ)
{
	return false;
}





bool cPluginC::OnCollectingPickup(cPlayer & a_Player, cPickup & a_Pickup)
{
	return false;
}





bool cPluginC::OnCraftingNoRecipe(cPlayer & a_Player, cCraftingGrid & a_Grid, cCraftingRecipe & a_Recipe)
{
	return false;
}





bool cPluginC::OnDisconnect(cClientHandle & a_Client, const AString & a_Reason)
{
	return false;
}





bool cPluginC::OnEntityAddEffect(cEntity & a_Entity, int a_EffectType, int a_EffectDurationTicks, int a_EffectIntensity, double a_DistanceModifier)
{
	return false;
}





bool cPluginC::OnEntityTeleport(cEntity & a_Entity, const Vector3d & a_OldPosition, const Vector3d & a_NewPosition)
{
	return false;
}





bool cPluginC::OnEntityChangingWorld(cEntity & a_Entity, cWorld & a_World)
{
	return false;
}





bool cPluginC::OnEntityChangedWorld(cEntity & a_Entity, cWorld & a_World)
{
	return false;
}





bool cPluginC::OnExecuteCommand(cPlayer * a_Player, const AStringVector & a_Split, const AString & a_EntireCommand, cPluginManager::CommandResult & a_Result)
{
	return false;
}





bool cPluginC::OnExploded(cWorld & a_World, double a_ExplosionSize, bool a_CanCauseFire, double a_X, double a_Y, double a_Z, eExplosionSource a_Source, void * a_SourceData)
{
	return false;
}





bool cPluginC::OnExploding(cWorld & a_World, double & a_ExplosionSize, bool & a_CanCauseFire, double a_X, double a_Y, double a_Z, eExplosionSource a_Source, void * a_SourceData)
{
	return false;
}





bool cPluginC::OnHandshake(cClientHandle & a_Client, const AString & a_Username)
{
	return false;
}





bool cPluginC::OnHopperPullingItem(cWorld & a_World, cHopperEntity & a_Hopper, int a_DstSlotNum, cBlockEntityWithItems & a_SrcEntity, int a_SrcSlotNum)
{
	return false;
}





bool cPluginC::OnHopperPushingItem(cWorld & a_World, cHopperEntity & a_Hopper, int a_SrcSlotNum, cBlockEntityWithItems & a_DstEntity, int a_DstSlotNum)
{
	return false;
}





bool cPluginC::OnKilled(cEntity & a_Victim, TakeDamageInfo & a_TDI, AString & a_DeathMessage)
{
	return false;
}





bool cPluginC::OnKilling(cEntity & a_Victim, cEntity * a_Killer, TakeDamageInfo & a_TDI)
{
	return false;
}





bool cPluginC::OnLogin(cClientHandle & a_Client, UInt32 a_ProtocolVersion, const AString & a_Username)
{
	return false;
}





bool cPluginC::OnPlayerAnimation(cPlayer & a_Player, int a_Animation)
{
	return false;
}





bool cPluginC::OnPlayerBreakingBlock(cPlayer & a_Player, int a_BlockX, int a_BlockY, int a_BlockZ, char a_BlockFace, BLOCKTYPE a_BlockType, NIBBLETYPE a_BlockMeta)
{
	return false;
}





bool cPluginC::OnPlayerBrokenBlock(cPlayer & a_Player, int a_BlockX, int a_BlockY, int a_BlockZ, char a_BlockFace, BLOCKTYPE a_BlockType, NIBBLETYPE a_BlockMeta)
{
	return false;
}





bool cPluginC::OnPlayerDestroyed(cPlayer & a_Player)
{
	return false;
}





bool cPluginC::OnPlayerEating(cPlayer & a_Player)
{
	return false;
}





bool cPluginC::OnPlayerFished(cPlayer & a_Player, const cItems & a_Reward)
{
	return false;
}





bool cPluginC::OnPlayerFishing(cPlayer & a_Player, cItems & a_Reward)
{
	return false;
}





bool cPluginC::OnPlayerFoodLevelChange(cPlayer & a_Player, int a_NewFoodLevel)
{
	return false;
}





bool cPluginC::OnPlayerJoined(cPlayer & a_Player)
{
	return false;
}





bool cPluginC::OnPlayerLeftClick(cPlayer & a_Player, int a_BlockX, int a_BlockY, int a_BlockZ, char a_BlockFace, char a_Status)
{
	return false;
}





bool cPluginC::OnPlayerMoving(cPlayer & a_Player, const Vector3d & a_OldPosition, const Vector3d & a_NewPosition)
{
	return false;
}





bool cPluginC::OnPlayerPlacedBlock(cPlayer & a_Player, const sSetBlock & a_BlockChange)
{
	return false;
}





bool cPluginC::OnPlayerPlacingBlock(cPlayer & a_Player, const sSetBlock & a_BlockChange)
{
	return false;
}





bool cPluginC::OnPlayerRightClick(cPlayer & a_Player, int a_BlockX, int a_BlockY, int a_BlockZ, char a_BlockFace, int a_CursorX, int a_CursorY, int a_CursorZ)
{
	return false;
}





bool cPluginC::OnPlayerRightClickingEntity(cPlayer & a_Player, cEntity & a_Entity)
{
	return false;
}





bool cPluginC::OnPlayerShooting(cPlayer & a_Player)
{
	return false;
}





bool cPluginC::OnPlayerSpawned(cPlayer & a_Player)
{
	return false;
}





bool cPluginC::OnPlayerTossingItem(cPlayer & a_Player)
{
	return false;
}





bool cPluginC::OnPlayerUsedBlock(cPlayer & a_Player, int a_BlockX, int a_BlockY, int a_BlockZ, char a_BlockFace, int a_CursorX, int a_CursorY, int a_CursorZ, BLOCKTYPE a_BlockType, NIBBLETYPE a_BlockMeta)
{
	return false;
}





bool cPluginC::OnPlayerUsedItem(cPlayer & a_Player, int a_BlockX, int a_BlockY, int a_BlockZ, char a_BlockFace, int a_CursorX, int a_CursorY, int a_CursorZ)
{
	return false;
}





bool cPluginC::OnPlayerUsingBlock(cPlayer & a_Player, int a_BlockX, int a_BlockY, int a_BlockZ, char a_BlockFace, int a_CursorX, int a_CursorY, int a_CursorZ, BLOCKTYPE a_BlockType, NIBBLETYPE a_BlockMeta)
{
	return false;
}





bool cPluginC::OnPlayerUsingItem(cPlayer & a_Player, int a_BlockX, int a_BlockY, int a_BlockZ, char a_BlockFace, int a_CursorX, int a_CursorY, int a_CursorZ)
{
	return false;
}





bool cPluginC::OnPluginMessage(cClientHandle & a_Client, const AString & a_Channel, const AString & a_Message)
{
	return false;
}





bool cPluginC::OnPluginsLoaded()
{
	return false;
}





bool cPluginC::OnPostCrafting(cPlayer & a_Player, cCraftingGrid & a_Grid, cCraftingRecipe & a_Recipe)
{
	return false;
}





bool cPluginC::OnPreCrafting(cPlayer & a_Player, cCraftingGrid & a_Grid, cCraftingRecipe & a_Recipe)
{
	return false;
}





bool cPluginC::OnProjectileHitBlock(cProjectileEntity & a_Projectile, int a_BlockX, int a_BlockY, int a_BlockZ, eBlockFace a_Face, const Vector3d & a_BlockHitPos)
{
	return false;
}





bool cPluginC::OnProjectileHitEntity(cProjectileEntity & a_Projectile, cEntity & a_HitEntity)
{
	return false;
}





bool cPluginC::OnServerPing(cClientHandle & a_ClientHandle, AString & a_ServerDescription, int & a_OnlinePlayersCount, int & a_MaxPlayersCount, AString & a_Favicon)
{
	return false;
}





bool cPluginC::OnSpawnedEntity(cWorld & a_World, cEntity & a_Entity)
{
	return false;
}





bool cPluginC::OnSpawnedMonster(cWorld & a_World, cMonster & a_Monster)
{
	return false;
}





bool cPluginC::OnSpawningEntity(cWorld & a_World, cEntity & a_Entity)
{
	return false;
}





bool cPluginC::OnSpawningMonster(cWorld & a_World, cMonster & a_Monster)
{
	return false;
}





bool cPluginC::OnTakeDamage(cEntity & a_Receiver, TakeDamageInfo & a_TakeDamageInfo)
{
	return false;
}





bool cPluginC::OnUpdatedSign(cWorld & a_World, int a_BlockX, int a_BlockY, int a_BlockZ, const AString & a_Line1, const AString & a_Line2, const AString & a_Line3, const AString & a_Line4, cPlayer * a_Player)
{
	return false;
}





bool cPluginC::OnUpdatingSign(cWorld & a_World, int a_BlockX, int a_BlockY, int a_BlockZ, AString & a_Line1, AString & a_Line2, AString & a_Line3, AString & a_Line4, cPlayer * a_Player)
{
	return false;
}





bool cPluginC::OnWeatherChanged(cWorld & a_World)
{
	return false;
}





bool cPluginC::OnWeatherChanging(cWorld & a_World, eWeather & a_NewWeather)
{
	return false;
}





bool cPluginC::OnWorldStarted(cWorld & a_World)
{
	return false;
}





bool cPluginC::OnWorldTick(cWorld & a_World, std::chrono::milliseconds a_Dt, std::chrono::milliseconds a_LastTickDurationMSec)
{
	return false;
}





bool cPluginC::HandleCommand(const AStringVector & a_Split, cPlayer & a_Player, const AString & a_FullCommand)
{
	return false;
}





bool cPluginC::HandleConsoleCommand(const AStringVector & a_Split, cCommandOutputCallback & a_Output, const AString & a_FullCommand)
{
	return false;
}





void cPluginC::ClearCommands()
{

}





void cPluginC::ClearConsoleCommands()
{

}





const AString cPluginC::GetWebTitle() const
{
	return m_Name;
}





AString cPluginC::HandleWebRequest(const HTTPRequest & a_Request)
{
	return "";
}




