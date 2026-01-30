#ifndef API_H
#define API_H

#include "main.h"
#include "ompcapi.h"
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

bool SetSpawnInfo(int playerid, int team, int skin, float x, float y, float z,
                  float rotation, int weapon1, int weapon1_ammo, int weapon2,
                  int weapon2_ammo, int weapon3, int weapon3_ammo);
bool SpawnPlayer(int playerid);
bool SetPlayerPos(int playerid, float x, float y, float z);
bool SetPlayerPosFindZ(int playerid, float x, float y, float z);
bool GetPlayerPos(int playerid, float *x, float *y, float *z);
bool SetPlayerFacingAngle(int playerid, float angle);
bool GetPlayerFacingAngle(int playerid, float *angle);
bool IsPlayerInRangeOfPoint(int playerid, float range, float x, float y,
                            float z);
float GetPlayerDistanceFromPoint(int playerid, float x, float y, float z);
bool IsPlayerStreamedIn(int playerid, int forplayerid);
bool SetPlayerInterior(int playerid, int interiorid);
int GetPlayerInterior(int playerid);
bool SetPlayerHealth(int playerid, float health);
bool GetPlayerHealth(int playerid, float *health);
bool SetPlayerArmour(int playerid, float armour);
bool GetPlayerArmour(int playerid, float *armour);
bool SetPlayerAmmo(int playerid, int weaponid, int ammo);
int GetPlayerAmmo(int playerid);
int GetPlayerWeaponState(int playerid);
int GetPlayerTargetPlayer(int playerid);
int GetPlayerTargetActor(int playerid);
bool SetPlayerTeam(int playerid, int teamid);
int GetPlayerTeam(int playerid);
bool SetPlayerScore(int playerid, int score);
int GetPlayerScore(int playerid);
int GetPlayerDrunkLevel(int playerid);
bool SetPlayerDrunkLevel(int playerid, int level);
bool SetPlayerColor(int playerid, int color);
int GetPlayerColor(int playerid);
bool SetPlayerSkin(int playerid, int skinid);
int GetPlayerSkin(int playerid);
bool GivePlayerWeapon(int playerid, int weaponid, int ammo);
bool ResetPlayerWeapons(int playerid);
bool SetPlayerArmedWeapon(int playerid, int weaponid);
bool GetPlayerWeaponData(int playerid, int slot, int *weapon, int *ammo);
bool GivePlayerMoney(int playerid, int money);
bool ResetPlayerMoney(int playerid);
int SetPlayerName(int playerid, const char *name);
int GetPlayerMoney(int playerid);
int GetPlayerState(int playerid);
bool GetPlayerIp(int playerid, char *ip, int size);
int GetPlayerPing(int playerid);
int GetPlayerWeapon(int playerid);
bool GetPlayerKeys(int playerid, int *keys, int *updown, int *leftright);
int GetPlayerName(int playerid, char *name, int size);
bool SetPlayerTime(int playerid, int hour, int minute);
bool GetPlayerTime(int playerid, int *hour, int *minute);
bool TogglePlayerClock(int playerid, bool toggle);
bool SetPlayerWeather(int playerid, int weather);
bool ForceClassSelection(int playerid);
bool SetPlayerWantedLevel(int playerid, int level);
int GetPlayerWantedLevel(int playerid);
bool SetPlayerFightingStyle(int playerid, int style);
int GetPlayerFightingStyle(int playerid);
bool SetPlayerVelocity(int playerid, float x, float y, float z);
bool GetPlayerVelocity(int playerid, float *x, float *y, float *z);
bool PlayCrimeReportForPlayer(int playerid, int suspectid, int crime);
bool PlayAudioStreamForPlayer(int playerid, const char *url, float posX,
                              float posY, float posZ, float distance,
                              bool usepos);
bool StopAudioStreamForPlayer(int playerid);
bool SetPlayerShopName(int playerid, const char *shopname);
bool SetPlayerSkillLevel(int playerid, int skill, int level);
int GetPlayerSurfingVehicleID(int playerid);
int GetPlayerSurfingObjectID(int playerid);
bool RemoveBuildingForPlayer(int playerid, int modelid, float fX, float fY,
                             float fZ, float fRadius);
bool GetPlayerLastShotVectors(int playerid, float *fOriginX, float *fOriginY,
                              float *fOriginZ, float *fHitPosX, float *fHitPosY,
                              float *fHitPosZ);
bool SetPlayerAttachedObject(int playerid, int index, int modelid, int bone,
                             float fOffsetX, float fOffsetY, float fOffsetZ,
                             float fRotX, float fRotY, float fRotZ,
                             float fScaleX, float fScaleY, float fScaleZ,
                             int materialcolor1, int materialcolor2);
bool RemovePlayerAttachedObject(int playerid, int index);
bool IsPlayerAttachedObjectSlotUsed(int playerid, int index);
bool EditAttachedObject(int playerid, int index);
int CreatePlayerTextDraw(int playerid, float x, float y, const char *text);
bool PlayerTextDrawDestroy(int playerid, int text);
bool PlayerTextDrawLetterSize(int playerid, int text, float x, float y);
bool PlayerTextDrawTextSize(int playerid, int text, float x, float y);
bool PlayerTextDrawAlignment(int playerid, int text, int alignment);
bool PlayerTextDrawColor(int playerid, int text, int color);
bool PlayerTextDrawUseBox(int playerid, int text, bool use);
bool PlayerTextDrawBoxColor(int playerid, int text, int color);
bool PlayerTextDrawSetShadow(int playerid, int text, int size);
bool PlayerTextDrawSetOutline(int playerid, int text, int size);
bool PlayerTextDrawBackgroundColor(int playerid, int text, int color);
bool PlayerTextDrawFont(int playerid, int text, int font);
bool PlayerTextDrawSetProportional(int playerid, int text, bool set);
bool PlayerTextDrawSetSelectable(int playerid, int text, bool set);
bool PlayerTextDrawShow(int playerid, int text);
bool PlayerTextDrawHide(int playerid, int text);
bool PlayerTextDrawSetString(int playerid, int text, const char *string);
bool PlayerTextDrawSetPreviewModel(int playerid, int text, int modelindex);
bool PlayerTextDrawSetPreviewRot(int playerid, int text, float fRotX,
                                 float fRotY, float fRotZ, float fZoom);
bool PlayerTextDrawSetPreviewVehCol(int playerid, int text, int color1,
                                    int color2);
bool SetPVarInt(int playerid, const char *varname, int value);
int GetPVarInt(int playerid, const char *varname);
bool SetPVarString(int playerid, const char *varname, const char *value);
bool GetPVarString(int playerid, const char *varname, char *value, int size);
bool SetPVarFloat(int playerid, const char *varname, float value);
float GetPVarFloat(int playerid, const char *varname);
bool DeletePVar(int playerid, const char *varname);
int GetPVarsUpperIndex(int playerid);
bool GetPVarNameAtIndex(int playerid, int index, char *varname, int size);
int GetPVarType(int playerid, const char *varname);
bool SetPlayerChatBubble(int playerid, const char *text, int color,
                         float drawdistance, int expiretime);
bool PutPlayerInVehicle(int playerid, int vehicleid, int seatid);
int GetPlayerVehicleID(int playerid);
int GetPlayerVehicleSeat(int playerid);
bool RemovePlayerFromVehicle(int playerid);
bool TogglePlayerControllable(int playerid, bool toggle);
bool PlayerPlaySound(int playerid, int soundid, float x, float y, float z);
bool ApplyAnimation(int playerid, const char *animlib, const char *animname,
                    float fDelta, bool loop, bool lockx, bool locky,
                    bool freeze, int time, bool forcesync);
bool ClearAnimations(int playerid, bool forcesync);
int GetPlayerAnimationIndex(int playerid);
bool GetAnimationName(int index, char *animlib, int animlib_size,
                      char *animname, int animname_size);
int GetPlayerSpecialAction(int playerid);
bool SetPlayerSpecialAction(int playerid, int actionid);
bool DisableRemoteVehicleCollisions(int playerid, bool disable);
bool SetPlayerCheckpoint(int playerid, float x, float y, float z, float size);
bool DisablePlayerCheckpoint(int playerid);
bool SetPlayerRaceCheckpoint(int playerid, int type, float x, float y, float z,
                             float nextx, float nexty, float nextz, float size);
bool DisablePlayerRaceCheckpoint(int playerid);
bool SetPlayerWorldBounds(int playerid, float x_max, float x_min, float y_max,
                          float y_min);
bool SetPlayerMarkerForPlayer(int playerid, int showplayerid, int color);
bool ShowPlayerNameTagForPlayer(int playerid, int showplayerid, bool show);
bool SetPlayerMapIcon(int playerid, int iconid, float x, float y, float z,
                      int markertype, int color, int style);
bool RemovePlayerMapIcon(int playerid, int iconid);
bool AllowPlayerTeleport(int playerid, bool allow);
bool SetPlayerCameraPos(int playerid, float x, float y, float z);
bool SetPlayerCameraLookAt(int playerid, float x, float y, float z, int cut);
bool SetCameraBehindPlayer(int playerid);
bool GetPlayerCameraPos(int playerid, float *x, float *y, float *z);
bool GetPlayerCameraFrontVector(int playerid, float *x, float *y, float *z);
int GetPlayerCameraMode(int playerid);
bool EnablePlayerCameraTarget(int playerid, bool enable);
int GetPlayerCameraTargetObject(int playerid);
int GetPlayerCameraTargetVehicle(int playerid);
int GetPlayerCameraTargetPlayer(int playerid);
int GetPlayerCameraTargetActor(int playerid);
float GetPlayerCameraAspectRatio(int playerid);
float GetPlayerCameraZoom(int playerid);
bool AttachCameraToObject(int playerid, int objectid);
bool AttachCameraToPlayerObject(int playerid, int playerobjectid);
bool InterpolateCameraPos(int playerid, float FromX, float FromY, float FromZ,
                          float ToX, float ToY, float ToZ, int time, int cut);
bool InterpolateCameraLookAt(int playerid, float FromX, float FromY,
                             float FromZ, float ToX, float ToY, float ToZ,
                             int time, int cut);
bool IsPlayerConnected(int playerid);
bool IsPlayerInVehicle(int playerid, int vehicleid);
bool IsPlayerInAnyVehicle(int playerid);
bool IsPlayerInCheckpoint(int playerid);
bool IsPlayerInRaceCheckpoint(int playerid);
bool SetPlayerVirtualWorld(int playerid, int worldid);
int GetPlayerVirtualWorld(int playerid);
bool EnableStuntBonusForPlayer(int playerid, bool enable);
bool EnableStuntBonusForAll(bool enable);
bool TogglePlayerSpectating(int playerid, bool toggle);
bool PlayerSpectatePlayer(int playerid, int targetplayerid, int mode);
bool PlayerSpectateVehicle(int playerid, int targetvehicleid, int mode);
bool StartRecordingPlayerData(int playerid, int recordtype, char *recordname);
bool StopRecordingPlayerData(int playerid);
bool CreateExplosionForPlayer(int playerid, float X, float Y, float Z, int type,
                              float Radius);
bool SendClientMessage(int playerid, int color, char *message);
bool SendClientMessageToAll(int color, char *message);
bool SendPlayerMessageToPlayer(int playerid, int senderid, char *message);
bool SendPlayerMessageToAll(int senderid, char *message);
bool SendDeathMessage(int playerid, int killer, int weapon);
bool SendDeathMessageToPlayer(int playerid, int killer, int killee, int weapon);
bool GameTextForAll(char *text, int time, int style);
bool GameTextForPlayer(int playerid, char *text, int time, int style);
int GetTickCount();
int GetMaxPlayers();
float VectorSize(float x, float y, float z);
int GetPlayerPoolSize();
int GetVehiclePoolSize();
int GetActorPoolSize();
bool SetGameModeText(const char *text);
bool SetTeamCount(int count);
int AddPlayerClass(int modelid, float spawn_x, float spawn_y, float spawn_z,
                   float z_angle, int weapon1, int weapon1_ammo, int weapon2,
                   int weapon2_ammo, int weapon3, int weapon3_ammo);
int AddPlayerClassEx(int teamid, int modelid, float spawn_x, float spawn_y,
                     float spawn_z, float z_angle, int weapon1,
                     int weapon1_ammo, int weapon2, int weapon2_ammo,
                     int weapon3, int weapon3_ammo);
int AddStaticVehicle(int modelid, float spawn_x, float spawn_y, float spawn_z,
                     float z_angle, int color1, int color2);
int AddStaticVehicleEx(int modelid, float spawn_x, float spawn_y, float spawn_z,
                       float z_angle, int color1, int color2, int respawn_delay,
                       bool addsiren);
int AddStaticPickup(int model, int type, float x, float y, float z,
                    int virtualworld);
int CreatePickup(int model, int type, float x, float y, float z,
                 int virtualworld);
bool DestroyPickup(int pickup);
bool ShowNameTags(bool show);
bool ShowPlayerMarkers(int mode);
// bool GameModeExit();
bool SetWorldTime(int hour);
bool GetWeaponName(int weaponid, char *name, int size);
bool EnableTirePopping(bool enable);
bool EnableVehicleFriendlyFire();
bool AllowInteriorWeapons(bool allow);
bool SetWeather(int weatherid);
bool SetGravity(float gravity);
float GetGravity();
bool AllowAdminTeleport(bool allow);
bool SetDeathDropAmount(int amount);
bool CreateExplosion(float x, float y, float z, int type, float radius);
bool EnableZoneNames(bool enable);
bool UsePlayerPedAnims();
bool DisableInteriorEnterExits();
bool SetNameTagDrawDistance(float distance);
bool DisableNameTagLOS();
bool LimitGlobalChatRadius(float chat_radius);
bool LimitPlayerMarkerRadius(float marker_radius);
bool ConnectNPC(const char *name, const char *script);
bool IsPlayerNPC(int playerid);
bool IsPlayerAdmin(int playerid);
bool Kick(int playerid);
bool Ban(int playerid);
bool BanEx(int playerid, const char *reason);
bool SendRconCommand(const char *command);
bool GetPlayerNetworkStats(int playerid, char *retstr, int size);
bool GetNetworkStats(char *retstr, int size);
bool GetPlayerVersion(int playerid, char *version, int len);
bool BlockIpAddress(const char *ip_address, int timems);
bool UnBlockIpAddress(const char *ip_address);
int GetServerTickRate();
int NetStats_GetConnectedTime(int playerid);
int NetStats_MessagesReceived(int playerid);
int NetStats_BytesReceived(int playerid);
int NetStats_MessagesSent(int playerid);
int NetStats_BytesSent(int playerid);
int NetStats_MessagesRecvPerSecond(int playerid);
float NetStats_PacketLossPercent(int playerid);
int NetStats_ConnectionStatus(int playerid);
bool NetStats_GetIpPort(int playerid, char *ip_port, int ip_port_len);
int CreateMenu(const char *title, int columns, float x, float y,
               float col1width, float col2width);
bool DestroyMenu(int menuid);
int AddMenuItem(int menuid, int column, const char *menutext);
bool SetMenuColumnHeader(int menuid, int column, const char *columnheader);
bool ShowMenuForPlayer(int menuid, int playerid);
bool HideMenuForPlayer(int menuid, int playerid);
bool IsValidMenu(int menuid);
bool DisableMenu(int menuid);
bool DisableMenuRow(int menuid, int row);
int GetPlayerMenu(int playerid);
int TextDrawCreate(float x, float y, const char *text);
bool TextDrawDestroy(int text);
bool TextDrawLetterSize(int text, float x, float y);
bool TextDrawTextSize(int text, float x, float y);
bool TextDrawAlignment(int text, int alignment);
bool TextDrawColor(int text, int color);
bool TextDrawUseBox(int text, bool use);
bool TextDrawBoxColor(int text, int color);
bool TextDrawSetShadow(int text, int size);
bool TextDrawSetOutline(int text, int size);
bool TextDrawBackgroundColor(int text, int color);
bool TextDrawFont(int text, int font);
bool TextDrawSetProportional(int text, bool set);
bool TextDrawSetSelectable(int text, bool set);
bool TextDrawShowForPlayer(int playerid, int text);
bool TextDrawHideForPlayer(int playerid, int text);
bool TextDrawShowForAll(int text);
bool TextDrawHideForAll(int text);
bool TextDrawSetString(int text, const char *string);
bool TextDrawSetPreviewModel(int text, int modelindex);
bool TextDrawSetPreviewRot(int text, float fRotX, float fRotY, float fRotZ,
                           float fZoom);
bool TextDrawSetPreviewVehCol(int text, int color1, int color2);
bool SelectTextDraw(int playerid, int hovercolor);
bool CancelSelectTextDraw(int playerid);
int GangZoneCreate(float minx, float miny, float maxx, float maxy);
bool GangZoneDestroy(int zone);
bool GangZoneShowForPlayer(int playerid, int zone, int color);
bool GangZoneShowForAll(int zone, int color);
bool GangZoneHideForPlayer(int playerid, int zone);
bool GangZoneHideForAll(int zone);
bool GangZoneFlashForPlayer(int playerid, int zone, int flashcolor);
bool GangZoneFlashForAll(int zone, int flashcolor);
bool GangZoneStopFlashForPlayer(int playerid, int zone);
bool GangZoneStopFlashForAll(int zone);
int Create3DTextLabel(const char *text, int color, float x, float y, float z,
                      float DrawDistance, int virtualworld, bool testLOS);
bool Delete3DTextLabel(int id);
bool Attach3DTextLabelToPlayer(int id, int playerid, float OffsetX,
                               float OffsetY, float OffsetZ);
bool Attach3DTextLabelToVehicle(int id, int vehicleid, float OffsetX,
                                float OffsetY, float OffsetZ);
bool Update3DTextLabelText(int id, int color, const char *text);
int CreatePlayer3DTextLabel(int playerid, const char *text, int color, float x,
                            float y, float z, float DrawDistance,
                            int attachedplayer, int attachedvehicle,
                            bool testLOS);
bool DeletePlayer3DTextLabel(int playerid, int id);
bool UpdatePlayer3DTextLabelText(int playerid, int id, int color,
                                 const char *text);
bool ShowPlayerDialog(int playerid, int dialogid, int style,
                      const char *caption, const char *info,
                      const char *button1, const char *button2);
bool gpci(int playerid, char *buffer, int size);
int CreateVehicle(int vehicletype, float x, float y, float z, float rotation,
                  int color1, int color2, int respawn_delay, bool addsiren);
bool DestroyVehicle(int vehicleid);
bool IsVehicleStreamedIn(int vehicleid, int forplayerid);
bool GetVehiclePos(int vehicleid, float *x, float *y, float *z);
bool SetVehiclePos(int vehicleid, float x, float y, float z);
bool GetVehicleZAngle(int vehicleid, float *z_angle);
bool GetVehicleRotationQuat(int vehicleid, float *w, float *x, float *y,
                            float *z);
bool SetVehicleZAngle(int vehicleid, float z_angle);
bool SetVehicleParamsForPlayer(int vehicleid, int playerid, int objective,
                               int doorslocked);
bool ManualVehicleEngineAndLights();
bool SetVehicleParamsEx(int vehicleid, int engine, int lights, int alarm,
                        int doors, int bonnet, int boot, int objective);
bool GetVehicleParamsEx(int vehicleid, int *engine, int *lights, int *alarm,
                        int *doors, int *bonnet, int *boot, int *objective);
int GetVehicleParamsSirenState(int vehicleid);
bool SetVehicleParamsCarDoors(int vehicleid, int driver, int passenger,
                              int backleft, int backright);
bool GetVehicleParamsCarDoors(int vehicleid, int *driver, int *passenger,
                              int *backleft, int *backright);
bool SetVehicleParamsCarWindows(int vehicleid, int driver, int passenger,
                                int backleft, int backright);
bool GetVehicleParamsCarWindows(int vehicleid, int *driver, int *passenger,
                                int *backleft, int *backright);
bool SetVehicleToRespawn(int vehicleid);
bool LinkVehicleToInterior(int vehicleid, int interiorid);
bool AddVehicleComponent(int vehicleid, int componentid);
bool RemoveVehicleComponent(int vehicleid, int componentid);
bool ChangeVehicleColor(int vehicleid, int color1, int color2);
bool ChangeVehiclePaintjob(int vehicleid, int paintjobid);
bool SetVehicleHealth(int vehicleid, float health);
bool GetVehicleHealth(int vehicleid, float *health);
bool AttachTrailerToVehicle(int trailerid, int vehicleid);
bool DetachTrailerFromVehicle(int vehicleid);
bool IsTrailerAttachedToVehicle(int vehicleid);
int GetVehicleTrailer(int vehicleid);
bool SetVehicleNumberPlate(int vehicleid, const char *numberplate);
int GetVehicleModel(int vehicleid);
int GetVehicleComponentInSlot(int vehicleid, int slot);
int GetVehicleComponentType(int component);
bool RepairVehicle(int vehicleid);
bool GetVehicleVelocity(int vehicleid, float *X, float *Y, float *Z);
bool SetVehicleVelocity(int vehicleid, float X, float Y, float Z);
bool SetVehicleAngularVelocity(int vehicleid, float X, float Y, float Z);
bool GetVehicleDamageStatus(int vehicleid, int *panels, int *doors, int *lights,
                            int *tires);
bool UpdateVehicleDamageStatus(int vehicleid, int panels, int doors, int lights,
                               int tires);
bool SetVehicleVirtualWorld(int vehicleid, int worldid);
int GetVehicleVirtualWorld(int vehicleid);
bool GetVehicleModelInfo(int model, int infotype, float *X, float *Y, float *Z);
int CreateObject(int modelid, float x, float y, float z, float rX, float rY,
                 float rZ, float DrawDistance);
bool AttachObjectToVehicle(int objectid, int vehicleid, float fOffsetX,
                           float fOffsetY, float fOffsetZ, float fRotX,
                           float fRotY, float fRotZ);
bool AttachObjectToObject(int objectid, int attachtoid, float fOffsetX,
                          float fOffsetY, float fOffsetZ, float fRotX,
                          float fRotY, float fRotZ, bool SyncRotation);
bool AttachObjectToPlayer(int objectid, int playerid, float fOffsetX,
                          float fOffsetY, float fOffsetZ, float fRotX,
                          float fRotY, float fRotZ);
bool SetObjectPos(int objectid, float x, float y, float z);
bool GetObjectPos(int objectid, float *x, float *y, float *z);
bool SetObjectRot(int objectid, float rotX, float rotY, float rotZ);
bool GetObjectRot(int objectid, float *rotX, float *rotY, float *rotZ);
int GetObjectModel(int objectid);
bool SetObjectNoCameraCol(int objectid);
bool IsValidObject(int objectid);
bool DestroyObject(int objectid);
int MoveObject(int objectid, float X, float Y, float Z, float Speed, float RotX,
               float RotY, float RotZ);
bool StopObject(int objectid);
bool IsObjectMoving(int objectid);
bool EditObject(int playerid, int objectid);
bool EditPlayerObject(int playerid, int objectid);
bool SelectObject(int playerid);
bool CancelEdit(int playerid);
int CreatePlayerObject(int playerid, int modelid, float x, float y, float z,
                       float rX, float rY, float rZ, float DrawDistance);
bool AttachPlayerObjectToPlayer(int objectplayer, int objectid,
                                int attachplayer, float OffsetX, float OffsetY,
                                float OffsetZ, float rX, float rY, float rZ);
bool AttachPlayerObjectToVehicle(int playerid, int objectid, int vehicleid,
                                 float fOffsetX, float fOffsetY, float fOffsetZ,
                                 float fRotX, float fRotY, float RotZ);
bool SetPlayerObjectPos(int playerid, int objectid, float x, float y, float z);
bool GetPlayerObjectPos(int playerid, int objectid, float *x, float *y,
                        float *z);
bool SetPlayerObjectRot(int playerid, int objectid, float rotX, float rotY,
                        float rotZ);
bool GetPlayerObjectRot(int playerid, int objectid, float *rotX, float *rotY,
                        float *rotZ);
int GetPlayerObjectModel(int playerid, int objectid);
bool SetPlayerObjectNoCameraCol(int playerid, int objectid);
bool IsValidPlayerObject(int playerid, int objectid);
bool DestroyPlayerObject(int playerid, int objectid);
int MovePlayerObject(int playerid, int objectid, float x, float y, float z,
                     float Speed, float RotX, float RotY, float RotZ);
bool StopPlayerObject(int playerid, int objectid);
bool IsPlayerObjectMoving(int playerid, int objectid);
bool SetObjectMaterial(int objectid, int materialindex, int modelid,
                       const char *txdname, const char *texturename,
                       int materialcolor);
bool SetPlayerObjectMaterial(int playerid, int objectid, int materialindex,
                             int modelid, const char *txdname,
                             const char *texturename, int materialcolor);
bool SetObjectMaterialText(int objectid, const char *text, int materialindex,
                           int materialsize, const char *fontface, int fontsize,
                           bool bold, int fontcolor, int backcolor,
                           int textalignment);
bool SetPlayerObjectMaterialText(int playerid, int objectid, const char *text,
                                 int materialindex, int materialsize,
                                 const char *fontface, int fontsize, bool bold,
                                 int fontcolor, int backcolor,
                                 int textalignment);
bool SetObjectsDefaultCameraCol(bool disable);
bool IsValidVehicle(int vehicleid);
float GetVehicleDistanceFromPoint(int vehicleid, float x, float y, float z);
bool SetActorSkin(int actorid, int skin);
int GetActorSkin(int actorid);
bool GetActorAnimation(int actorid, char *library, int lib_size, char *name,
                       int name_size, float *delta, bool *loop, bool *lockx,
                       bool *locky, bool *freeze, int *time);
bool GetActorSpawnInfo(int actorid, float *x, float *y, float *z, float *angle,
                       int *skin);
bool IsPlayerInAnyCheckpoint(int playerid);
bool CheckpointIsActive(int playerid);
bool GetPlayerCheckpoint(int playerid, float *x, float *y, float *z,
                         float *radius);
bool RaceCheckpointIsActive(int playerid);
bool GetPlayerRaceCheckpoint(int playerid, float *x, float *y, float *z,
                             float *nextX, float *nextY, float *nextZ,
                             float *radius);
int GetClassID(int classid);
int GetClassCount();
bool GetClassData(int classid, int *team, int *skin, float *x, float *y,
                  float *z, float *angle, int *weapon1, int *ammo1,
                  int *weapon2, int *ammo2, int *weapon3, int *ammo3);
bool EditClass(int classid, int team, int skin, float x, float y, float z,
               float angle, int weapon1, int ammo1, int weapon2, int ammo2,
               int weapon3, int ammo3);
bool GetConsoleVarAsBool(const char *cvar);
int GetConsoleVarAsInt(const char *cvar);
float GetConsoleVarAsFloat(const char *cvar);
int GetConsoleVarAsString(const char *cvar, char *buffer, int size);
bool Log(const char *text);
bool IsAdminTeleportAllowed();
bool AreAllAnimationsEnabled();
bool EnableAllAnimations(bool enable);
bool IsAnimationLibraryValid(const char *name);
bool AreInteriorWeaponsAllowed();
int GetWeaponSlot(int weaponid);
bool AddRule(const char *name, const char *value);
bool IsValidRule(const char *name);
bool RemoveRule(const char *name);
bool GetMenuPos(int menuid, float *x, float *y);
bool GetMenuColumnWidth(int menuid, float *col1_width, float *col2_width);
bool GetMenuColumnHeader(int menuid, int column, char *header, int header_size);
bool GetMenuItem(int menuid, int column, int row, char *item, int item_size);
int GetMenuColumns(int menuid);
int GetMenuItems(int menuid, int column);
int CreateMenu(const char *title, int columns, float x, float y,
               float col1width, float col2width);
bool DestroyMenu(int menuid);
int GetTickCount();
int CreateNPC(const char *name);
bool DestroyNPC(int npcid);
bool SpawnNPC(int npcid);
bool RespawnNPC(int npcid);
bool SetNPCPos(int npcid, float x, float y, float z);
bool GetNPCPos(int npcid, float *x, float *y, float *z);
bool SetNPCRot(int npcid, float rx, float ry, float rz);
bool GetNPCRot(int npcid, float *rx, float *ry, float *rz);
bool SetNPCFacingAngle(int npcid, float angle);
bool GetNPCFacingAngle(int npcid, float *angle);
bool SetNPCVirtualWorld(int npcid, int virtualWorld);
int GetNPCVirtualWorld(int npcid);
bool SetNPCInterior(int npcid, int interior);
int GetNPCInterior(int npcid);
bool NPCMove(int npcid, float x, float y, float z, int moveType,
             float moveSpeed, float stopRange);
bool NPCMoveToPlayer(int npcid, int playerid, int moveType, float moveSpeed,
                     float stopRange, int posCheckUpdateDelay,
                     bool autoRestart);
bool NPCStopMove(int npcid);
bool NPCIsMoving(int npcid);
bool SetNPCSkin(int npcid, int model);
bool IsNPCStreamedIn(int npcid, int playerid);
bool IsNPCAnyStreamedIn(int npcid);
int GetNPCs(int *npcsArr, int maxNPCs);
bool SetNPCHealth(int npcid, float health);
float GetNPCHealth(int npcid);
bool SetNPCArmour(int npcid, float armour);
float GetNPCArmour(int npcid);
bool IsNPCDead(int npcid);
bool SetNPCInvulnerable(int npcid, bool toggle);
bool IsNPCInvulnerable(int npcid);
bool SetNPCWeapon(int npcid, int weapon);
int GetNPCWeapon(int npcid);
bool SetNPCAmmo(int npcid, int ammo);
int GetNPCAmmo(int npcid);
bool SetNPCAmmoInClip(int npcid, int ammo);
int GetNPCAmmoInClip(int npcid);
bool EnableNPCReloading(int npcid, bool enable);
bool IsNPCReloadEnabled(int npcid);
bool IsNPCReloading(int npcid);
bool EnableNPCInfiniteAmmo(int npcid, bool enable);
bool IsNPCInfiniteAmmoEnabled(int npcid);
int GetNPCWeaponState(int npcid);
bool SetNPCKeys(int npcid, int upAndDown, int leftAndRight, int keys);
bool GetNPCKeys(int npcid, int *upAndDown, int *leftAndRight, int *keys);
bool SetNPCWeaponSkillLevel(int npcid, int skill, int level);
int GetNPCWeaponSkillLevel(int npcid, int skill);
bool NPCMeleeAttack(int npcid, int time, bool secondaryAttack);
bool NPCStopMeleeAttack(int npcid);
bool NPCIsMeleeAttacking(int npcid);
bool SetNPCFightingStyle(int npcid, int style);
int GetNPCFightingStyle(int npcid);
bool NPCShoot(int npcid, int weapon, int hitId, int hitType, float endX,
              float endY, float endZ, float offsetX, float offsetY,
              float offsetZ, bool isHit, int checkInBetweenFlags);
bool NPCIsShooting(int npcid);
bool NPCAimAt(int npcid, float x, float y, float z, bool shoot, int shootDelay,
              bool updateAngle, float offsetFromX, float offsetFromY,
              float offsetFromZ, int checkInBetweenFlags);
bool NPCAimAtPlayer(int npcid, int atPlayer, bool shoot, int shootDelay,
                    bool updateAngle, float offsetX, float offsetY,
                    float offsetZ, float offsetFromX, float offsetFromY,
                    float offsetFromZ, int checkInBetweenFlags);
bool NPCStopAim(int npcid);
bool NPCIsAiming(int npcid);
bool NPCIsAimingAtPlayer(int npcid, int atPlayer);
bool SetNPCWeaponAccuracy(int npcid, int weapon, float accuracy);
float GetNPCWeaponAccuracy(int npcid, int weapon);
bool SetNPCWeaponReloadTime(int npcid, int weapon, int time);
int GetNPCWeaponReloadTime(int npcid, int weapon);
int GetNPCWeaponActualReloadTime(int npcid, int weapon);
bool SetNPCWeaponShootTime(int npcid, int weapon, int time);
int GetNPCWeaponShootTime(int npcid, int weapon);
bool SetNPCWeaponClipSize(int npcid, int weapon, int size);
int GetNPCWeaponClipSize(int npcid, int weapon);
int GetNPCWeaponActualClipSize(int npcid, int weapon);
bool NPCEnterVehicle(int npcid, int vehicleid, int seatId, int moveType);
bool NPCExitVehicle(int npcid);
bool NPCPutInVehicle(int npcid, int vehicleid, int seatId);
bool NPCRemoveFromVehicle(int npcid);
int GetNPCVehicleID(int npcid);
int GetNPCEnteringVehicleID(int npcid);
int GetNPCVehicleSeat(int npcid);
int GetNPCEnteringVehicleSeat(int npcid);
bool NPCIsEnteringVehicle(int npcid);
bool NPCUseVehicleSiren(int npcid, bool use);
bool NPCIsVehicleSirenUsed(int npcid);
bool SetNPCVehicleHealth(int npcid, float health);
float GetNPCVehicleHealth(int npcid);
bool SetNPCVehicleHydraThrusters(int npcid, int direction);
int GetNPCVehicleHydraThrusters(int npcid);
bool SetNPCVehicleGearState(int npcid, int gearState);
int GetNPCVehicleGearState(int npcid);
bool SetNPCVehicleTrainSpeed(int npcid, float speed);
float GetNPCVehicleTrainSpeed(int npcid);
int NPCCreatePath();
bool NPCDestroyPath(int pathId);
bool NPCDestroyAllPath();
int NPCGetPathCount();
bool NPCAddPointToPath(int pathId, float x, float y, float z, float stopRange);
bool NPCRemovePointFromPath(int pathId, int pointIndex);
bool NPCClearPath(int pathId);
int NPCGetPathPointCount(int pathId);
bool NPCGetPathPoint(int pathId, int pointIndex, float *x, float *y, float *z,
                     float *stopRange);
int NPCGetCurrentPathPointIndex(int npcid);
bool NPCIsValidPath(int pathId);
bool NPCHasPathPointInRange(int pathId, float x, float y, float z,
                            float radius);
bool NPCMoveByPath(int npcid, int pathId, int moveType, float moveSpeed,
                   bool reverse);
bool NPCResetAnimation(int npcid);
bool SetNPCAnimation(int npcid, int animationId, float delta, bool loop,
                     bool lockX, bool lockY, bool freeze, int time);
bool GetNPCAnimation(int npcid, int *animationId, float *delta, bool *loop,
                     bool *lockX, bool *lockY, bool *freeze, int *time);
bool ApplyNPCAnimation(int npcid, const char *animlib, const char *animname,
                       float delta, bool loop, bool lockX, bool lockY,
                       bool freeze, int time);
bool ClearNPCAnimations(int npcid);
bool SetNPCSpecialAction(int npcid, int action);
int GetNPCSpecialAction(int npcid);
bool NPCStartPlayback(int npcid, const char *recordName, bool autoUnload,
                      float startPosX, float startPosY, float startPosZ,
                      float startRotX, float startRotY, float startRotZ);
bool NPCStartPlaybackEx(int npcid, int recordId, bool autoUnload,
                        float startPosX, float startPosY, float startPosZ,
                        float startRotX, float startRotY, float startRotZ);
bool NPCStopPlayback(int npcid);
bool NPCPausePlayback(int npcid, bool paused);
bool NPCIsPlayingPlayback(int npcid);
bool NPCIsPlaybackPaused(int npcid);
int NPCLoadRecord(const char *filePath);
bool NPCUnloadRecord(int recordId);
bool NPCIsValidRecord(int recordId);
int NPCGetRecordCount();
bool NPCUnloadAllRecords();
bool NPCOpenNode(int nodeId);
bool NPCCloseNode(int nodeId);
bool NPCIsNodeOpen(int nodeId);
int NPCGetNodeType(int nodeId);
bool NPCSetNodePoint(int nodeId, int pointId);
bool NPCGetNodePointPosition(int nodeId, float *x, float *y, float *z);
int NPCGetNodePointCount(int nodeId);
bool NPCGetNodeInfo(int nodeId, uint32_t *vehicleNodes, uint32_t *pedNodes,
                    uint32_t *naviNodes);
bool NPCPlayNode(int npcid, int nodeId, int moveType, float moveSpeed,
                 float radius, bool setAngle);
bool NPCStopPlayingNode(int npcid);
bool NPCPausePlayingNode(int npcid);
bool NPCResumePlayingNode(int npcid);
bool NPCIsPlayingNodePaused(int npcid);
bool NPCIsPlayingNode(int npcid);
int NPCChangeNode(int npcid, int nodeId, int linkId);
bool NPCUpdateNodePoint(int npcid, int pointId);
bool SetNPCSurfingOffset(int npcid, float x, float y, float z);
bool GetNPCSurfingOffset(int npcid, float *x, float *y, float *z);
bool SetNPCSurfingVehicle(int npcid, int vehicleid);
int GetNPCSurfingVehicle(int npcid);
bool SetNPCSurfingObject(int npcid, int objectid);
int GetNPCSurfingObject(int npcid);
bool SetNPCSurfingPlayerObject(int npcid, int playerid, int objectid);
int GetNPCSurfingPlayerObject(int npcid);
bool NPCResetSurfingData(int npcid);
int AddCharModel(int baseid, int newid, const char *dff,
                 const char *textureLibrary);
int AddSimpleModel(int virtualWorld, int baseid, int newid, const char *dff,
                   const char *textureLibrary);
int AddSimpleModelTimed(int virtualWorld, int baseid, int newid,
                        const char *dff, const char *textureLibrary, int timeOn,
                        int timeOff);
bool RedirectDownload(int playerid, const char *url);
bool FindModelFileNameFromCRC(int crc, char *output, int size);
bool IsValidCustomModel(int modelId);
bool GetCustomModelPath(int modelId, char *dffPath, int dffPathSize,
                        char *txdPath, int txdPathSize);
bool IsPickupStreamedIn(int playerid, int pickupid);
bool GetPickupPos(int pickupid, float *x, float *y, float *z);
int GetPickupModel(int pickupid);
int GetPickupType(int pickupid);
int GetPickupVirtualWorld(int pickupid);
bool SetPickupPos(int pickupid, float x, float y, float z, bool update);
bool SetPickupModel(int pickupid, int model, bool update);
bool SetPickupType(int pickupid, int type, bool update);
bool SetPickupVirtualWorld(int pickupid, int virtualworld);
bool ShowPickupForPlayer(int playerid, int pickupid);
bool HidePickupForPlayer(int playerid, int pickupid);
bool IsPickupHiddenForPlayer(int playerid, int pickupid);
int GetVehicleMaxPassengerSeats(int modelid);
bool CanVehicleHaveComponent(int modelid, int componentid);
bool GetVehicleRandomColorPair(int modelid, int *color1, int *color2,
                               int *color3, int *color4);
int VehicleColorIndexToColor(int colorIndex, int alpha);
int GetVehicleLandingGearState(int vehicleid);
bool GetVehicleSpawnInfo(int vehicleid, float *x, float *y, float *z,
                         float *rotation, int *color1, int *color2);
bool SetVehicleSpawnInfo(int vehicleid, int modelid, float x, float y, float z,
                         float rotation, int color1, int color2,
                         int respawn_time, int interior);
int GetVehicleModelCount(int modelid);
int GetVehicleModelsUsed();
int GetVehiclePaintjob(int vehicleid);
bool GetVehicleColor(int vehicleid, int *color1, int *color2);
int GetVehicleInterior(int vehicleid);
bool GetVehicleNumberPlate(int vehicleid, char *numberPlate, int size);
bool SetVehicleRespawnDelay(int vehicleid, int respawn_delay);
int GetVehicleRespawnDelay(int vehicleid);
int GetVehicleCab(int vehicleid);
int GetVehicleTower(int vehicleid);
int GetVehicleOccupiedTick(int vehicleid);
int GetVehicleRespawnTick(int vehicleid);
bool HasVehicleBeenOccupied(int vehicleid);
bool IsVehicleOccupied(int vehicleid);
bool IsVehicleDead(int vehicleid);
bool SetVehicleParamsSirenState(int vehicleid, bool siren_state);
bool ToggleVehicleSirenEnabled(int vehicleid, bool status);
bool IsVehicleSirenEnabled(int vehicleid);
int GetVehicleLastDriver(int vehicleid);
int GetVehicleDriver(int vehicleid);
int GetVehicleSirenState(int vehicleid);
int GetVehicleHydraReactorAngle(int vehicleid);
float GetVehicleTrainSpeed(int vehicleid);
bool GetVehicleMatrix(int vehicleid, float *rightX, float *rightY,
                      float *rightZ, float *upX, float *upY, float *upZ,
                      float *atX, float *atY, float *atZ);
int GetVehicleOccupant(int vehicleid, int seat);
int CountVehicleOccupants(int vehicleid);

#endif
