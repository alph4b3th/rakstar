#include "api.h"

bool SetVehicleParamsForPlayer(int vehicleid, int playerid, int objective,
                               int doorslocked) {
  return api.Vehicle.SetParamsForPlayer(api.Vehicle.FromID(vehicleid),
                                        api.Player.FromID(playerid), objective,
                                        doorslocked);
}

bool ManualVehicleEngineAndLights() {
  return api.Vehicle.UseManualEngineAndLights();
}

bool SetVehicleParamsEx(int vehicleid, int engine, int lights, int alarm,
                        int doors, int bonnet, int boot, int objective) {
  return api.Vehicle.SetParamsEx(api.Vehicle.FromID(vehicleid), engine, lights,
                                 alarm, doors, bonnet, boot, objective);
}

bool GetVehicleParamsEx(int vehicleid, int *engine, int *lights, int *alarm,
                        int *doors, int *bonnet, int *boot, int *objective) {
  return api.Vehicle.GetParamsEx(api.Vehicle.FromID(vehicleid), engine, lights,
                                 alarm, doors, bonnet, boot, objective);
}

int GetVehicleParamsSirenState(int vehicleid) {
  return api.Vehicle.GetParamsSirenState(api.Vehicle.FromID(vehicleid));
}

bool SetVehicleParamsCarDoors(int vehicleid, int driver, int passenger,
                              int backleft, int backright) {
  return api.Vehicle.SetParamsCarDoors(api.Vehicle.FromID(vehicleid), driver,
                                       passenger, backleft, backright);
}

bool GetVehicleParamsCarDoors(int vehicleid, int *driver, int *passenger,
                              int *backleft, int *backright) {
  return api.Vehicle.GetParamsCarDoors(api.Vehicle.FromID(vehicleid), driver,
                                       passenger, backleft, backright);
}

bool SetVehicleParamsCarWindows(int vehicleid, int driver, int passenger,
                                int backleft, int backright) {
  return api.Vehicle.SetParamsCarWindows(api.Vehicle.FromID(vehicleid), driver,
                                         passenger, backleft, backright);
}

bool GetVehicleParamsCarWindows(int vehicleid, int *driver, int *passenger,
                                int *backleft, int *backright) {
  return api.Vehicle.GetParamsCarWindows(api.Vehicle.FromID(vehicleid), driver,
                                         passenger, backleft, backright);
}

bool SetVehicleToRespawn(int vehicleid) {
  return api.Vehicle.SetToRespawn(api.Vehicle.FromID(vehicleid));
}

bool LinkVehicleToInterior(int vehicleid, int interiorid) {
  return api.Vehicle.LinkToInterior(api.Vehicle.FromID(vehicleid), interiorid);
}

bool AddVehicleComponent(int vehicleid, int componentid) {
  return api.Vehicle.AddComponent(api.Vehicle.FromID(vehicleid), componentid);
}

bool RemoveVehicleComponent(int vehicleid, int componentid) {
  return api.Vehicle.RemoveComponent(api.Vehicle.FromID(vehicleid),
                                     componentid);
}

bool ChangeVehicleColor(int vehicleid, int color1, int color2) {
  return api.Vehicle.ChangeColor(api.Vehicle.FromID(vehicleid), color1, color2);
}

bool ChangeVehiclePaintjob(int vehicleid, int paintjobid) {
  return api.Vehicle.ChangePaintjob(api.Vehicle.FromID(vehicleid), paintjobid);
}

bool SetVehicleHealth(int vehicleid, float health) {
  return api.Vehicle.SetHealth(api.Vehicle.FromID(vehicleid), health);
}

bool GetVehicleHealth(int vehicleid, float *health) {
  return api.Vehicle.GetHealth(api.Vehicle.FromID(vehicleid));
}

bool AttachTrailerToVehicle(int trailerid, int vehicleid) {
  return api.Vehicle.AttachTrailer(api.Vehicle.FromID(trailerid),
                                   api.Vehicle.FromID(vehicleid));
}

bool DetachTrailerFromVehicle(int vehicleid) {
  return api.Vehicle.DetachTrailer(api.Vehicle.FromID(vehicleid));
}

bool IsTrailerAttachedToVehicle(int vehicleid) {
  return api.Vehicle.IsTrailerAttached(api.Vehicle.FromID(vehicleid));
}

int GetVehicleTrailer(int vehicleid) {
  void *t = api.Vehicle.GetTrailer(api.Vehicle.FromID(vehicleid));
  return t ? api.Vehicle.GetID(t) : 0;
}

bool SetVehicleNumberPlate(int vehicleid, const char *numberplate) {
  return api.Vehicle.SetNumberPlate(api.Vehicle.FromID(vehicleid), numberplate);
}

int GetVehicleModel(int vehicleid) {
  return api.Vehicle.GetModel(api.Vehicle.FromID(vehicleid));
}

int GetVehicleComponentInSlot(int vehicleid, int slot) {
  return api.Vehicle.GetComponentInSlot(api.Vehicle.FromID(vehicleid), slot);
}

int GetVehicleComponentType(int component) {
  return api.Vehicle.GetComponentType(component);
}

bool RepairVehicle(int vehicleid) {
  return api.Vehicle.Repair(api.Vehicle.FromID(vehicleid));
}

bool GetVehicleVelocity(int vehicleid, float *X, float *Y, float *Z) {
  return api.Vehicle.GetVelocity(api.Vehicle.FromID(vehicleid), X, Y, Z);
}

bool SetVehicleVelocity(int vehicleid, float X, float Y, float Z) {
  return api.Vehicle.SetVelocity(api.Vehicle.FromID(vehicleid), X, Y, Z);
}

bool SetVehicleAngularVelocity(int vehicleid, float X, float Y, float Z) {
  return api.Vehicle.SetAngularVelocity(api.Vehicle.FromID(vehicleid), X, Y, Z);
}

bool GetVehicleDamageStatus(int vehicleid, int *panels, int *doors, int *lights,
                            int *tires) {
  return api.Vehicle.GetDamageStatus(api.Vehicle.FromID(vehicleid), panels,
                                     doors, lights, tires);
}

bool UpdateVehicleDamageStatus(int vehicleid, int panels, int doors, int lights,
                               int tires) {
  return api.Vehicle.UpdateDamageStatus(api.Vehicle.FromID(vehicleid), panels,
                                        doors, lights, tires);
}

bool SetVehicleVirtualWorld(int vehicleid, int worldid) {
  return api.Vehicle.SetVirtualWorld(api.Vehicle.FromID(vehicleid), worldid);
}

int GetVehicleVirtualWorld(int vehicleid) {
  return api.Vehicle.GetVirtualWorld(api.Vehicle.FromID(vehicleid));
}

bool GetVehicleModelInfo(int model, int infotype, float *X, float *Y,
                         float *Z) {
  return api.Vehicle.GetModelInfo(model, infotype, X, Y, Z);
}

int CreateObject(int modelid, float x, float y, float z, float rX, float rY,
                 float rZ, float DrawDistance) {
  int id = 0;
  api.Object.Create(modelid, x, y, z, rX, rY, rZ, DrawDistance, &id);
  return id;
}

bool AttachObjectToVehicle(int objectid, int vehicleid, float fOffsetX,
                           float fOffsetY, float fOffsetZ, float fRotX,
                           float fRotY, float fRotZ) {
  return api.Object.AttachToVehicle(api.Object.FromID(objectid),
                                    api.Vehicle.FromID(vehicleid), fOffsetX,
                                    fOffsetY, fOffsetZ, fRotX, fRotY, fRotZ);
}

bool AttachObjectToObject(int objectid, int attachtoid, float fOffsetX,
                          float fOffsetY, float fOffsetZ, float fRotX,
                          float fRotY, float fRotZ, bool SyncRotation) {
  return api.Object.AttachToObject(
      api.Object.FromID(objectid), api.Object.FromID(attachtoid), fOffsetX,
      fOffsetY, fOffsetZ, fRotX, fRotY, fRotZ, SyncRotation);
}

bool AttachObjectToPlayer(int objectid, int playerid, float fOffsetX,
                          float fOffsetY, float fOffsetZ, float fRotX,
                          float fRotY, float fRotZ) {
  return api.Object.AttachToPlayer(api.Object.FromID(objectid),
                                   api.Player.FromID(playerid), fOffsetX,
                                   fOffsetY, fOffsetZ, fRotX, fRotY, fRotZ);
}

bool SetObjectPos(int objectid, float x, float y, float z) {
  return api.Object.SetPos(api.Object.FromID(objectid), x, y, z);
}

bool GetObjectPos(int objectid, float *x, float *y, float *z) {
  return api.Object.GetPos(api.Object.FromID(objectid), x, y, z);
}

bool SetObjectRot(int objectid, float rotX, float rotY, float rotZ) {
  return api.Object.SetRot(api.Object.FromID(objectid), rotX, rotY, rotZ);
}

bool GetObjectRot(int objectid, float *rotX, float *rotY, float *rotZ) {
  return api.Object.GetRot(api.Object.FromID(objectid), rotX, rotY, rotZ);
}

int GetObjectModel(int objectid) {
  return api.Object.GetModel(api.Object.FromID(objectid));
}

bool SetObjectNoCameraCol(int objectid) {
  return api.Object.SetNoCameraCollision(api.Object.FromID(objectid));
}

bool IsValidObject(int objectid) {
  return api.Object.IsValid(api.Object.FromID(objectid));
}

bool DestroyObject(int objectid) {
  return api.Object.Destroy(api.Object.FromID(objectid));
}

int MoveObject(int objectid, float X, float Y, float Z, float Speed, float RotX,
               float RotY, float RotZ) {
  return api.Object.Move(api.Object.FromID(objectid), X, Y, Z, Speed, RotX,
                         RotY, RotZ);
}

bool StopObject(int objectid) {
  return api.Object.Stop(api.Object.FromID(objectid));
}

bool IsObjectMoving(int objectid) {
  return api.Object.IsMoving(api.Object.FromID(objectid));
}

bool EditObject(int playerid, int objectid) {
  return api.Object.BeginEditing(api.Player.FromID(playerid),
                                 api.Object.FromID(objectid));
}

bool EditPlayerObject(int playerid, int objectid) {
  return api.PlayerObject.BeginEditing(
      api.Player.FromID(playerid),
      api.PlayerObject.FromID(api.Player.FromID(playerid), objectid));
}

bool SelectObject(int playerid) {
  return api.Object.BeginSelecting(api.Player.FromID(playerid));
}

bool CancelEdit(int playerid) {
  return api.Object.EndEditing(api.Player.FromID(playerid));
}

int CreatePlayerObject(int playerid, int modelid, float x, float y, float z,
                       float rX, float rY, float rZ, float DrawDistance) {
  int id = 0;
  api.PlayerObject.Create(api.Player.FromID(playerid), modelid, x, y, z, rX, rY,
                          rZ, DrawDistance, &id);
  return id;
}

bool AttachPlayerObjectToPlayer(int objectplayer, int objectid,
                                int attachplayer, float OffsetX, float OffsetY,
                                float OffsetZ, float rX, float rY, float rZ) {
  return api.PlayerObject.AttachToPlayer(
      api.Player.FromID(objectplayer),
      api.PlayerObject.FromID(api.Player.FromID(objectplayer), objectid),
      api.Player.FromID(attachplayer), OffsetX, OffsetY, OffsetZ, rX, rY, rZ);
}

bool AttachPlayerObjectToVehicle(int playerid, int objectid, int vehicleid,
                                 float fOffsetX, float fOffsetY, float fOffsetZ,
                                 float fRotX, float fRotY, float RotZ) {
  return api.PlayerObject.AttachToVehicle(
      api.Player.FromID(playerid),
      api.PlayerObject.FromID(api.Player.FromID(playerid), objectid),
      api.Vehicle.FromID(vehicleid), fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY,
      RotZ);
}

bool SetPlayerObjectPos(int playerid, int objectid, float x, float y, float z) {
  return api.PlayerObject.SetPos(
      api.Player.FromID(playerid),
      api.PlayerObject.FromID(api.Player.FromID(playerid), objectid), x, y, z);
}

bool GetPlayerObjectPos(int playerid, int objectid, float *x, float *y,
                        float *z) {
  return api.PlayerObject.GetPos(
      api.Player.FromID(playerid),
      api.PlayerObject.FromID(api.Player.FromID(playerid), objectid), x, y, z);
}

bool SetPlayerObjectRot(int playerid, int objectid, float rotX, float rotY,
                        float rotZ) {
  return api.PlayerObject.SetRot(
      api.Player.FromID(playerid),
      api.PlayerObject.FromID(api.Player.FromID(playerid), objectid), rotX,
      rotY, rotZ);
}

bool GetPlayerObjectRot(int playerid, int objectid, float *rotX, float *rotY,
                        float *rotZ) {
  return api.PlayerObject.GetRot(
      api.Player.FromID(playerid),
      api.PlayerObject.FromID(api.Player.FromID(playerid), objectid), rotX,
      rotY, rotZ);
}

int GetPlayerObjectModel(int playerid, int objectid) {
  return api.PlayerObject.GetModel(
      api.Player.FromID(playerid),
      api.PlayerObject.FromID(api.Player.FromID(playerid), objectid));
}

bool SetPlayerObjectNoCameraCol(int playerid, int objectid) {
  return api.PlayerObject.SetNoCameraCollision(
      api.Player.FromID(playerid),
      api.PlayerObject.FromID(api.Player.FromID(playerid), objectid));
}

bool IsValidPlayerObject(int playerid, int objectid) {
  return api.PlayerObject.IsValid(
      api.Player.FromID(playerid),
      api.PlayerObject.FromID(api.Player.FromID(playerid), objectid));
}

bool DestroyPlayerObject(int playerid, int objectid) {
  return api.PlayerObject.Destroy(
      api.Player.FromID(playerid),
      api.PlayerObject.FromID(api.Player.FromID(playerid), objectid));
}

int MovePlayerObject(int playerid, int objectid, float x, float y, float z,
                     float Speed, float RotX, float RotY, float RotZ) {
  return api.PlayerObject.Move(
      api.Player.FromID(playerid),
      api.PlayerObject.FromID(api.Player.FromID(playerid), objectid), x, y, z,
      Speed, RotX, RotY, RotZ);
}

bool StopPlayerObject(int playerid, int objectid) {
  return api.PlayerObject.Stop(
      api.Player.FromID(playerid),
      api.PlayerObject.FromID(api.Player.FromID(playerid), objectid));
}

bool IsPlayerConnected(int playerid) {
  void *player = api.Player.FromID(playerid);
  int pId = api.Player.GetID(player);

  if (player == NULL || pId < 0 || pId > 1000) {
    return false;
  }

  return true;
}

bool IsPlayerObjectMoving(int playerid, int objectid) {
  return api.PlayerObject.IsMoving(
      api.Player.FromID(playerid),
      api.PlayerObject.FromID(api.Player.FromID(playerid), objectid));
}

bool SetObjectMaterial(int objectid, int materialindex, int modelid,
                       const char *txdname, const char *texturename,
                       int materialcolor) {
  return api.Object.SetMaterial(api.Object.FromID(objectid), materialindex,
                                modelid, txdname, texturename, materialcolor);
}

bool SetPlayerObjectMaterial(int playerid, int objectid, int materialindex,
                             int modelid, const char *txdname,
                             const char *texturename, int materialcolor) {
  return api.PlayerObject.SetMaterial(
      api.Player.FromID(playerid),
      api.PlayerObject.FromID(api.Player.FromID(playerid), objectid),
      materialindex, modelid, txdname, texturename, materialcolor);
}

bool SetObjectMaterialText(int objectid, const char *text, int materialindex,
                           int materialsize, const char *fontface, int fontsize,
                           bool bold, int fontcolor, int backcolor,
                           int textalignment) {
  return api.Object.SetMaterialText(
      api.Object.FromID(objectid), text, materialindex, materialsize, fontface,
      fontsize, bold, fontcolor, backcolor, textalignment);
}

bool SetPlayerObjectMaterialText(int playerid, int objectid, const char *text,
                                 int materialindex, int materialsize,
                                 const char *fontface, int fontsize, bool bold,
                                 int fontcolor, int backcolor,
                                 int textalignment) {
  return api.PlayerObject.SetMaterialText(
      api.Player.FromID(playerid),
      api.PlayerObject.FromID(api.Player.FromID(playerid), objectid), text,
      materialindex, materialsize, fontface, fontsize, bold, fontcolor,
      backcolor, textalignment);
}

bool SetObjectsDefaultCameraCol(bool disable) {
  return api.Object.SetDefaultCameraCollision(disable);
}

bool IsValidVehicle(int vehicleid) {
  return api.Vehicle.IsValid(api.Vehicle.FromID(vehicleid));
}

float GetVehicleDistanceFromPoint(int vehicleid, float x, float y, float z) {
  return api.Vehicle.GetDistanceFromPoint(api.Vehicle.FromID(vehicleid), x, y,
                                          z);
}

int CreateActor(int modelid, float x, float y, float z, float rotation) {
  int id = -1;
  api.Actor.Create(modelid, x, y, z, rotation, &id);
  return id;
}

bool DestroyActor(int actorid) {
  return api.Actor.Destroy(api.Actor.FromID(actorid));
}

bool IsActorStreamedIn(int actorid, int forplayerid) {
  return api.Actor.IsStreamedInFor(api.Actor.FromID(actorid),
                                   api.Player.FromID(forplayerid));
}

bool SetActorVirtualWorld(int actorid, int vworld) {
  return api.Actor.SetVirtualWorld(api.Actor.FromID(actorid), vworld);
}

int GetActorVirtualWorld(int actorid) {
  return api.Actor.GetVirtualWorld(api.Actor.FromID(actorid));
}

bool ApplyActorAnimation(int actorid, const char *animlib, const char *animname,
                         float fDelta, bool loop, bool lockx, bool locky,
                         bool freeze, int time) {
  return api.Actor.ApplyAnimation(api.Actor.FromID(actorid), animlib, animname,
                                  fDelta, loop, lockx, locky, freeze, time);
}

bool ClearActorAnimations(int actorid) {
  return api.Actor.ClearAnimations(api.Actor.FromID(actorid));
}

bool SetActorPos(int actorid, float x, float y, float z) {
  return api.Actor.SetPos(api.Actor.FromID(actorid), x, y, z);
}

bool GetActorPos(int actorid, float *x, float *y, float *z) {
  return api.Actor.GetPos(api.Actor.FromID(actorid), x, y, z);
}

bool SetActorFacingAngle(int actorid, float angle) {
  return api.Actor.SetFacingAngle(api.Actor.FromID(actorid), angle);
}

bool GetActorFacingAngle(int actorid, float *angle) {
  void *actor = api.Actor.FromID(actorid);
  if (!api.Actor.IsValid(actor))
    return false;
  if (angle)
    *angle = api.Actor.GetFacingAngle(actor);
  return true;
}

bool SetActorHealth(int actorid, float health) {
  return api.Actor.SetHealth(api.Actor.FromID(actorid), health);
}

bool GetActorHealth(int actorid, float *health) {
  void *actor = api.Actor.FromID(actorid);
  if (!api.Actor.IsValid(actor))
    return false;
  if (health)
    *health = api.Actor.GetHealth(actor);
  return true;
}

bool SetActorInvulnerable(int actorid, bool toggle) {
  return api.Actor.SetInvulnerable(api.Actor.FromID(actorid), toggle);
}

bool IsActorInvulnerable(int actorid) {
  return api.Actor.IsInvulnerable(api.Actor.FromID(actorid));
}

bool IsValidActor(int actorid) {
  return api.Actor.IsValid(api.Actor.FromID(actorid));
}

bool SetActorSkin(int actorid, int skin) {
  return api.Actor.SetSkin(api.Actor.FromID(actorid), skin);
}

int GetActorSkin(int actorid) {
  return api.Actor.GetSkin(api.Actor.FromID(actorid));
}

bool GetActorAnimation(int actorid, char *library, int lib_size, char *name,
                       int name_size, float *delta, bool *loop, bool *lockx,
                       bool *locky, bool *freeze, int *time) {
  struct CAPIStringView lib_view = {0}, name_view = {0};
  bool result =
      api.Actor.GetAnimation(api.Actor.FromID(actorid), &lib_view, &name_view,
                             delta, loop, lockx, locky, freeze, time);
  if (result) {
    if (library && lib_size > 0 && lib_view.data) {
      strncpy(library, lib_view.data, lib_size);
      library[lib_size - 1] = '\0';
    }
    if (name && name_size > 0 && name_view.data) {
      strncpy(name, name_view.data, name_size);
      name[name_size - 1] = '\0';
    }
  }
  return result;
}

bool GetActorSpawnInfo(int actorid, float *x, float *y, float *z, float *angle,
                       int *skin) {
  return api.Actor.GetSpawnInfo(api.Actor.FromID(actorid), x, y, z, angle,
                                skin);
}

bool IsPlayerInAnyCheckpoint(int playerid) {
  return api.Checkpoint.IsActive(api.Player.FromID(playerid));
}

bool CheckpointIsActive(int playerid) {
  return api.Checkpoint.IsActive(api.Player.FromID(playerid));
}

bool GetPlayerCheckpoint(int playerid, float *x, float *y, float *z,
                         float *radius) {
  return api.Checkpoint.Get(api.Player.FromID(playerid), x, y, z, radius);
}

bool RaceCheckpointIsActive(int playerid) {
  return api.RaceCheckpoint.IsActive(api.Player.FromID(playerid));
}

bool GetPlayerRaceCheckpoint(int playerid, float *x, float *y, float *z,
                             float *nextX, float *nextY, float *nextZ,
                             float *radius) {
  return api.RaceCheckpoint.Get(api.Player.FromID(playerid), x, y, z, nextX,
                                nextY, nextZ, radius);
}

int GetClassID(int classid) {
  return api.Class.GetID(api.Class.FromID(classid));
}

int GetClassCount() { return api.Class.Count(); }

bool GetClassData(int classid, int *team, int *skin, float *x, float *y,
                  float *z, float *angle, int *weapon1, int *ammo1,
                  int *weapon2, int *ammo2, int *weapon3, int *ammo3) {
  uint8_t t, w1, w2, w3;
  uint32_t a1, a2, a3;
  bool res = api.Class.GetData(api.Class.FromID(classid), &t, skin, x, y, z,
                               angle, &w1, &a1, &w2, &a2, &w3, &a3);
  if (res) {
    if (team)
      *team = t;
    if (weapon1)
      *weapon1 = w1;
    if (ammo1)
      *ammo1 = a1;
    if (weapon2)
      *weapon2 = w2;
    if (ammo2)
      *ammo2 = a2;
    if (weapon3)
      *weapon3 = w3;
    if (ammo3)
      *ammo3 = a3;
  }
  return res;
}

bool EditClass(int classid, int team, int skin, float x, float y, float z,
               float angle, int weapon1, int ammo1, int weapon2, int ammo2,
               int weapon3, int ammo3) {
  return api.Class.Edit(api.Class.FromID(classid), (uint8_t)team, skin, x, y, z,
                        angle, (uint8_t)weapon1, (uint32_t)ammo1,
                        (uint8_t)weapon2, (uint32_t)ammo2, (uint8_t)weapon3,
                        (uint32_t)ammo3);
}

bool GetConsoleVarAsBool(const char *cvar) {
  return api.Config.GetAsBool(cvar);
}

int GetConsoleVarAsInt(const char *cvar) { return api.Config.GetAsInt(cvar); }

float GetConsoleVarAsFloat(const char *cvar) {
  return api.Config.GetAsFloat(cvar);
}

int GetConsoleVarAsString(const char *cvar, char *buffer, int size) {
  struct CAPIStringBuffer buf = {(unsigned int)size, 0, buffer};
  return api.Config.GetAsString(cvar, &buf);
}

bool Log(const char *text) { return api.Core.Log(text); }

bool IsAdminTeleportAllowed() { return api.Core.IsAdminTeleportAllowed(); }

bool AreAllAnimationsEnabled() { return api.Core.AreAllAnimationsEnabled(); }

bool EnableAllAnimations(bool enable) {
  return api.Core.EnableAllAnimations(enable);
}

bool IsAnimationLibraryValid(const char *name) {
  return api.Core.IsAnimationLibraryValid(name);
}

bool AreInteriorWeaponsAllowed() {
  return api.Core.AreInteriorWeaponsAllowed();
}

int GetWeaponSlot(int weaponid) {
  return api.Core.GetWeaponSlot((uint8_t)weaponid);
}

bool AddRule(const char *name, const char *value) {
  return api.Core.AddRule(name, value);
}

bool IsValidRule(const char *name) { return api.Core.IsValidRule(name); }

bool RemoveRule(const char *name) { return api.Core.RemoveRule(name); }

bool GetMenuPos(int menuid, float *x, float *y) {
  return api.Menu.GetPos(api.Menu.FromID(menuid), x, y);
}

bool GetMenuColumnWidth(int menuid, float *col1_width, float *col2_width) {
  return api.Menu.GetColumnWidth(api.Menu.FromID(menuid), col1_width,
                                 col2_width);
}

bool GetMenuColumnHeader(int menuid, int column, char *header,
                         int header_size) {
  struct CAPIStringView view = {0};
  bool res = api.Menu.GetColumnHeader(api.Menu.FromID(menuid), column, &view);
  if (res && header && header_size > 0 && view.data) {
    strncpy(header, view.data, header_size);
    header[header_size - 1] = '\0';
  }
  return res;
}

bool GetMenuItem(int menuid, int column, int row, char *item, int item_size) {
  struct CAPIStringView view = {0};
  bool res = api.Menu.GetItem(api.Menu.FromID(menuid), column, row, &view);
  if (res && item && item_size > 0 && view.data) {
    strncpy(item, view.data, item_size);
    item[item_size - 1] = '\0';
  }
  return res;
}

int GetMenuColumns(int menuid) {
  return api.Menu.GetColumns(api.Menu.FromID(menuid));
}

int CreateMenu(const char *title, int columns, float x, float y,
               float col1width, float col2width) {
  int id = -1;
  api.Menu.Create(title, (uint32_t)columns, x, y, col1width, col2width, &id);
  return id;
}

bool DestroyMenu(int menuid) {
  return api.Menu.Destroy(api.Menu.FromID(menuid));
}

bool SendClientMessage(int playerid, int color, char *message) {
  return api.Player.SendClientMessage(api.Player.FromID(playerid), color,
                                      (const char *)message);
}

bool SendClientMessageToAll(int color, char *message) {
  return api.All.SendClientMessage(color, (const char *)message);
}

bool SendPlayerMessageToPlayer(int playerid, int senderid, char *message) {
  return api.Player.SendMessageToPlayer(api.Player.FromID(playerid),
                                        api.Player.FromID(senderid),
                                        (const char *)message);
}

// bool SendPlayerMessageToAll(int senderid, char *message) {
//   return api.All.SendClientMessage(api.Player.FromID(playerid), color,
//                                       (const char *)message);
// }

bool SendDeathMessage(int playerid, int killerid, int weapon) {
  return api.All.SendDeathMessage(api.Player.FromID(killerid),
                                  api.Player.FromID(playerid), weapon);
}

bool SendDeathMessageToPlayer(int playerid, int killerid, int killeeid,
                              int weapon) {
  return api.Player.SendDeathMessage(api.Player.FromID(playerid),
                                     api.Player.FromID(killerid),
                                     api.Player.FromID(killeeid), weapon);
}

int GetTickCount() { return (int)api.Core.TickCount(); }

int CreateNPC(const char *name) {
  int id = -1;
  void *npc = api.NPC.Create((char *)name, &id);
  return id;
}

bool DestroyNPC(int npcid) { return api.NPC.Destroy(api.NPC.FromID(npcid)); }

bool SpawnNPC(int npcid) { return api.NPC.Spawn(api.NPC.FromID(npcid)); }

bool RespawnNPC(int npcid) { return api.NPC.Respawn(api.NPC.FromID(npcid)); }

bool SetNPCPos(int npcid, float x, float y, float z) {
  return api.NPC.SetPos(api.NPC.FromID(npcid), x, y, z);
}

bool GetNPCPos(int npcid, float *x, float *y, float *z) {
  return api.NPC.GetPos(api.NPC.FromID(npcid), x, y, z);
}

bool SetNPCRot(int npcid, float rx, float ry, float rz) {
  return api.NPC.SetRot(api.NPC.FromID(npcid), rx, ry, rz);
}

bool GetNPCRot(int npcid, float *rx, float *ry, float *rz) {
  return api.NPC.GetRot(api.NPC.FromID(npcid), rx, ry, rz);
}

bool SetNPCFacingAngle(int npcid, float angle) {
  return api.NPC.SetFacingAngle(api.NPC.FromID(npcid), angle);
}

bool GetNPCFacingAngle(int npcid, float *angle) {
  return api.NPC.GetFacingAngle(api.NPC.FromID(npcid), angle);
}

bool SetNPCVirtualWorld(int npcid, int virtualWorld) {
  return api.NPC.SetVirtualWorld(api.NPC.FromID(npcid), virtualWorld);
}

int GetNPCVirtualWorld(int npcid) {
  return api.NPC.GetVirtualWorld(api.NPC.FromID(npcid));
}

bool SetNPCInterior(int npcid, int interior) {
  return api.NPC.SetInterior(api.NPC.FromID(npcid), interior);
}

int GetNPCInterior(int npcid) {
  return api.NPC.GetInterior(api.NPC.FromID(npcid));
}

bool NPCMove(int npcid, float x, float y, float z, int moveType,
             float moveSpeed, float stopRange) {
  return api.NPC.Move(api.NPC.FromID(npcid), x, y, z, moveType, moveSpeed,
                      stopRange);
}

bool NPCMoveToPlayer(int npcid, int playerid, int moveType, float moveSpeed,
                     float stopRange, int posCheckUpdateDelay,
                     bool autoRestart) {
  return api.NPC.MoveToPlayer(api.NPC.FromID(npcid),
                              api.Player.FromID(playerid), moveType, moveSpeed,
                              stopRange, posCheckUpdateDelay, autoRestart);
}

bool NPCStopMove(int npcid) { return api.NPC.StopMove(api.NPC.FromID(npcid)); }

bool NPCIsMoving(int npcid) { return api.NPC.IsMoving(api.NPC.FromID(npcid)); }

bool SetNPCSkin(int npcid, int model) {
  return api.NPC.SetSkin(api.NPC.FromID(npcid), model);
}

bool IsNPCStreamedIn(int npcid, int playerid) {
  return api.NPC.IsStreamedIn(api.NPC.FromID(npcid),
                              api.Player.FromID(playerid));
}

bool IsNPCAnyStreamedIn(int npcid) {
  return api.NPC.IsStreamedIn(api.NPC.FromID(npcid), NULL);
}

int GetNPCs(int *npcsArr, int maxNPCs) {
  return api.NPC.GetAll(npcsArr, maxNPCs);
}

bool SetNPCHealth(int npcid, float health) {
  return api.NPC.SetHealth(api.NPC.FromID(npcid), health);
}

float GetNPCHealth(int npcid) {
  return api.NPC.GetHealth(api.NPC.FromID(npcid));
}

bool SetNPCArmour(int npcid, float armour) {
  return api.NPC.SetArmour(api.NPC.FromID(npcid), armour);
}

float GetNPCArmour(int npcid) {
  return api.NPC.GetArmour(api.NPC.FromID(npcid));
}

bool IsNPCDead(int npcid) { return api.NPC.IsDead(api.NPC.FromID(npcid)); }

bool SetNPCInvulnerable(int npcid, bool toggle) {
  return api.NPC.SetInvulnerable(api.NPC.FromID(npcid), toggle);
}

bool IsNPCInvulnerable(int npcid) {
  return api.NPC.IsInvulnerable(api.NPC.FromID(npcid));
}

bool SetNPCWeapon(int npcid, int weapon) {
  return api.NPC.SetWeapon(api.NPC.FromID(npcid), weapon);
}

int GetNPCWeapon(int npcid) { return api.NPC.GetWeapon(api.NPC.FromID(npcid)); }

bool SetNPCAmmo(int npcid, int ammo) {
  return api.NPC.SetAmmo(api.NPC.FromID(npcid), ammo);
}

int GetNPCAmmo(int npcid) { return api.NPC.GetAmmo(api.NPC.FromID(npcid)); }

bool SetNPCAmmoInClip(int npcid, int ammo) {
  return api.NPC.SetAmmoInClip(api.NPC.FromID(npcid), ammo);
}

int GetNPCAmmoInClip(int npcid) {
  return api.NPC.GetAmmoInClip(api.NPC.FromID(npcid));
}

bool EnableNPCReloading(int npcid, bool enable) {
  return api.NPC.EnableReloading(api.NPC.FromID(npcid), enable);
}

bool IsNPCReloadEnabled(int npcid) {
  return api.NPC.IsReloadEnabled(api.NPC.FromID(npcid));
}

bool IsNPCReloading(int npcid) {
  return api.NPC.IsReloading(api.NPC.FromID(npcid));
}

bool EnableNPCInfiniteAmmo(int npcid, bool enable) {
  return api.NPC.EnableInfiniteAmmo(api.NPC.FromID(npcid), enable);
}

bool IsNPCInfiniteAmmoEnabled(int npcid) {
  return api.NPC.IsInfiniteAmmoEnabled(api.NPC.FromID(npcid));
}

int GetNPCWeaponState(int npcid) {
  return api.NPC.GetWeaponState(api.NPC.FromID(npcid));
}

bool SetNPCKeys(int npcid, int upAndDown, int leftAndRight, int keys) {
  return api.NPC.SetKeys(api.NPC.FromID(npcid), upAndDown, leftAndRight, keys);
}

bool GetNPCKeys(int npcid, int *upAndDown, int *leftAndRight, int *keys) {
  uint16_t ud = 0, lr = 0, k = 0;
  bool res = api.NPC.GetKeys(api.NPC.FromID(npcid), &ud, &lr, &k);
  if (res) {
    if (upAndDown)
      *upAndDown = (int)ud;
    if (leftAndRight)
      *leftAndRight = (int)lr;
    if (keys)
      *keys = (int)k;
  }
  return res;
}

bool SetNPCWeaponSkillLevel(int npcid, int skill, int level) {
  return api.NPC.SetWeaponSkillLevel(api.NPC.FromID(npcid), skill, level);
}

int GetNPCWeaponSkillLevel(int npcid, int skill) {
  return api.NPC.GetWeaponSkillLevel(api.NPC.FromID(npcid), skill);
}

bool NPCMeleeAttack(int npcid, int time, bool secondaryAttack) {
  return api.NPC.MeleeAttack(api.NPC.FromID(npcid), time, secondaryAttack);
}

bool NPCStopMeleeAttack(int npcid) {
  return api.NPC.StopMeleeAttack(api.NPC.FromID(npcid));
}

bool NPCIsMeleeAttacking(int npcid) {
  return api.NPC.IsMeleeAttacking(api.NPC.FromID(npcid));
}

bool SetNPCFightingStyle(int npcid, int style) {
  return api.NPC.SetFightingStyle(api.NPC.FromID(npcid), style);
}

int GetNPCFightingStyle(int npcid) {
  return api.NPC.GetFightingStyle(api.NPC.FromID(npcid));
}

bool NPCShoot(int npcid, int weapon, int hitId, int hitType, float endX,
              float endY, float endZ, float offsetX, float offsetY,
              float offsetZ, bool isHit, int checkInBetweenFlags) {
  return api.NPC.Shoot(api.NPC.FromID(npcid), weapon, hitId, hitType, endX,
                       endY, endZ, offsetX, offsetY, offsetZ, isHit,
                       checkInBetweenFlags);
}

bool NPCIsShooting(int npcid) {
  return api.NPC.IsShooting(api.NPC.FromID(npcid));
}

bool NPCAimAt(int npcid, float x, float y, float z, bool shoot, int shootDelay,
              bool updateAngle, float offsetFromX, float offsetFromY,
              float offsetFromZ, int checkInBetweenFlags) {
  return api.NPC.AimAt(api.NPC.FromID(npcid), x, y, z, shoot, shootDelay,
                       updateAngle, offsetFromX, offsetFromY, offsetFromZ,
                       checkInBetweenFlags);
}

bool NPCAimAtPlayer(int npcid, int atPlayer, bool shoot, int shootDelay,
                    bool updateAngle, float offsetX, float offsetY,
                    float offsetZ, float offsetFromX, float offsetFromY,
                    float offsetFromZ, int checkInBetweenFlags) {
  return api.NPC.AimAtPlayer(api.NPC.FromID(npcid), api.Player.FromID(atPlayer),
                             shoot, shootDelay, updateAngle, offsetX, offsetY,
                             offsetZ, offsetFromX, offsetFromY, offsetFromZ,
                             checkInBetweenFlags);
}

bool NPCStopAim(int npcid) { return api.NPC.StopAim(api.NPC.FromID(npcid)); }

bool NPCIsAiming(int npcid) { return api.NPC.IsAiming(api.NPC.FromID(npcid)); }

bool NPCIsAimingAtPlayer(int npcid, int atPlayer) {
  return api.NPC.IsAimingAtPlayer(api.NPC.FromID(npcid),
                                  api.Player.FromID(atPlayer));
}

bool SetNPCWeaponAccuracy(int npcid, int weapon, float accuracy) {
  return api.NPC.SetWeaponAccuracy(api.NPC.FromID(npcid), weapon, accuracy);
}

float GetNPCWeaponAccuracy(int npcid, int weapon) {
  return api.NPC.GetWeaponAccuracy(api.NPC.FromID(npcid), weapon);
}

bool SetNPCWeaponReloadTime(int npcid, int weapon, int time) {
  return api.NPC.SetWeaponReloadTime(api.NPC.FromID(npcid), weapon, time);
}

int GetNPCWeaponReloadTime(int npcid, int weapon) {
  return api.NPC.GetWeaponReloadTime(api.NPC.FromID(npcid), weapon);
}

int GetNPCWeaponActualReloadTime(int npcid, int weapon) {
  return api.NPC.GetWeaponActualReloadTime(api.NPC.FromID(npcid), weapon);
}

bool SetNPCWeaponShootTime(int npcid, int weapon, int time) {
  return api.NPC.SetWeaponShootTime(api.NPC.FromID(npcid), weapon, time);
}

int GetNPCWeaponShootTime(int npcid, int weapon) {
  return api.NPC.GetWeaponShootTime(api.NPC.FromID(npcid), weapon);
}

bool SetNPCWeaponClipSize(int npcid, int weapon, int size) {
  return api.NPC.SetWeaponClipSize(api.NPC.FromID(npcid), weapon, size);
}

int GetNPCWeaponClipSize(int npcid, int weapon) {
  return api.NPC.GetWeaponClipSize(api.NPC.FromID(npcid), weapon);
}

int GetNPCWeaponActualClipSize(int npcid, int weapon) {
  return api.NPC.GetWeaponActualClipSize(api.NPC.FromID(npcid), weapon);
}

bool NPCEnterVehicle(int npcid, int vehicleid, int seatId, int moveType) {
  return api.NPC.EnterVehicle(api.NPC.FromID(npcid),
                              api.Vehicle.FromID(vehicleid), seatId, moveType);
}

bool NPCExitVehicle(int npcid) {
  return api.NPC.ExitVehicle(api.NPC.FromID(npcid));
}

bool NPCPutInVehicle(int npcid, int vehicleid, int seatId) {
  return api.NPC.PutInVehicle(api.NPC.FromID(npcid),
                              api.Vehicle.FromID(vehicleid), seatId);
}

bool NPCRemoveFromVehicle(int npcid) {
  return api.NPC.RemoveFromVehicle(api.NPC.FromID(npcid));
}

int GetNPCVehicleID(int npcid) {
  return api.Vehicle.GetID(api.NPC.GetVehicle(api.NPC.FromID(npcid)));
}

int GetNPCEnteringVehicleID(int npcid) {
  return api.Vehicle.GetID(api.NPC.GetEnteringVehicle(api.NPC.FromID(npcid)));
}

int GetNPCVehicleSeat(int npcid) {
  return api.NPC.GetVehicleSeat(api.NPC.FromID(npcid));
}

int GetNPCEnteringVehicleSeat(int npcid) {
  return api.NPC.GetEnteringVehicleSeat(api.NPC.FromID(npcid));
}

bool NPCIsEnteringVehicle(int npcid) {
  return api.NPC.IsEnteringVehicle(api.NPC.FromID(npcid));
}

bool NPCUseVehicleSiren(int npcid, bool use) {
  return api.NPC.UseVehicleSiren(api.NPC.FromID(npcid), use);
}

bool NPCIsVehicleSirenUsed(int npcid) {
  return api.NPC.IsVehicleSirenUsed(api.NPC.FromID(npcid));
}

bool SetNPCVehicleHealth(int npcid, float health) {
  return api.NPC.SetVehicleHealth(api.NPC.FromID(npcid), health);
}

float GetNPCVehicleHealth(int npcid) {
  return api.NPC.GetVehicleHealth(api.NPC.FromID(npcid));
}

bool SetNPCVehicleHydraThrusters(int npcid, int direction) {
  return api.NPC.SetVehicleHydraThrusters(api.NPC.FromID(npcid), direction);
}

int GetNPCVehicleHydraThrusters(int npcid) {
  return api.NPC.GetVehicleHydraThrusters(api.NPC.FromID(npcid));
}

bool SetNPCVehicleGearState(int npcid, int gearState) {
  return api.NPC.SetVehicleGearState(api.NPC.FromID(npcid), gearState);
}

int GetNPCVehicleGearState(int npcid) {
  return api.NPC.GetVehicleGearState(api.NPC.FromID(npcid));
}

bool SetNPCVehicleTrainSpeed(int npcid, float speed) {
  return api.NPC.SetVehicleTrainSpeed(api.NPC.FromID(npcid), speed);
}

float GetNPCVehicleTrainSpeed(int npcid) {
  return api.NPC.GetVehicleTrainSpeed(api.NPC.FromID(npcid));
}

int NPCCreatePath() { return api.NPC.CreatePath(); }

bool NPCDestroyPath(int pathId) { return api.NPC.DestroyPath(pathId); }

bool NPCDestroyAllPath() { return api.NPC.DestroyAllPath(); }

int NPCGetPathCount() { return api.NPC.GetPathCount(); }

bool NPCAddPointToPath(int pathId, float x, float y, float z, float stopRange) {
  return api.NPC.AddPointToPath(pathId, x, y, z, stopRange);
}

bool NPCRemovePointFromPath(int pathId, int pointIndex) {
  return api.NPC.RemovePointFromPath(pathId, pointIndex);
}

bool NPCClearPath(int pathId) { return api.NPC.ClearPath(pathId); }

int NPCGetPathPointCount(int pathId) {
  return api.NPC.GetPathPointCount(pathId);
}

bool NPCGetPathPoint(int pathId, int pointIndex, float *x, float *y, float *z,
                     float *stopRange) {
  return api.NPC.GetPathPoint(pathId, pointIndex, x, y, z, stopRange);
}

int NPCGetCurrentPathPointIndex(int npcid) {
  return api.NPC.GetCurrentPathPointIndex(api.NPC.FromID(npcid));
}

bool NPCIsValidPath(int pathId) { return api.NPC.IsValidPath(pathId); }

bool NPCHasPathPointInRange(int pathId, float x, float y, float z,
                            float radius) {
  return api.NPC.HasPathPointInRange(pathId, x, y, z, radius);
}

bool NPCMoveByPath(int npcid, int pathId, int moveType, float moveSpeed,
                   bool reverse) {
  return api.NPC.MoveByPath(api.NPC.FromID(npcid), pathId, moveType, moveSpeed,
                            reverse);
}

bool NPCResetAnimation(int npcid) {
  return api.NPC.ResetAnimation(api.NPC.FromID(npcid));
}

bool SetNPCAnimation(int npcid, int animationId, float delta, bool loop,
                     bool lockX, bool lockY, bool freeze, int time) {
  return api.NPC.SetAnimation(api.NPC.FromID(npcid), animationId, delta, loop,
                              lockX, lockY, freeze, time);
}

bool GetNPCAnimation(int npcid, int *animationId, float *delta, bool *loop,
                     bool *lockX, bool *lockY, bool *freeze, int *time) {
  return api.NPC.GetAnimation(api.NPC.FromID(npcid), animationId, delta, loop,
                              lockX, lockY, freeze, time);
}

bool ApplyNPCAnimation(int npcid, const char *animlib, const char *animname,
                       float delta, bool loop, bool lockX, bool lockY,
                       bool freeze, int time) {
  return api.NPC.ApplyAnimation(api.NPC.FromID(npcid), (char *)animlib,
                                (char *)animname, delta, loop, lockX, lockY,
                                freeze, time);
}

bool ClearNPCAnimations(int npcid) {
  return api.NPC.ClearAnimations(api.NPC.FromID(npcid));
}

bool SetNPCSpecialAction(int npcid, int action) {
  return api.NPC.SetSpecialAction(api.NPC.FromID(npcid), action);
}

int GetNPCSpecialAction(int npcid) {
  return api.NPC.GetSpecialAction(api.NPC.FromID(npcid));
}

bool NPCStartPlayback(int npcid, const char *recordName, bool autoUnload,
                      float startPosX, float startPosY, float startPosZ,
                      float startRotX, float startRotY, float startRotZ) {
  return api.NPC.StartPlayback(api.NPC.FromID(npcid), (char *)recordName,
                               autoUnload, startPosX, startPosY, startPosZ,
                               startRotX, startRotY, startRotZ);
}

bool NPCStartPlaybackEx(int npcid, int recordId, bool autoUnload,
                        float startPosX, float startPosY, float startPosZ,
                        float startRotX, float startRotY, float startRotZ) {
  return api.NPC.StartPlaybackEx(api.NPC.FromID(npcid), recordId, autoUnload,
                                 startPosX, startPosY, startPosZ, startRotX,
                                 startRotY, startRotZ);
}

bool NPCStopPlayback(int npcid) {
  return api.NPC.StopPlayback(api.NPC.FromID(npcid));
}

bool NPCPausePlayback(int npcid, bool paused) {
  return api.NPC.PausePlayback(api.NPC.FromID(npcid), paused);
}

bool NPCIsPlayingPlayback(int npcid) {
  return api.NPC.IsPlayingPlayback(api.NPC.FromID(npcid));
}

bool NPCIsPlaybackPaused(int npcid) {
  return api.NPC.IsPlaybackPaused(api.NPC.FromID(npcid));
}

int NPCLoadRecord(const char *filePath) {
  return api.NPC.LoadRecord((char *)filePath);
}

bool NPCUnloadRecord(int recordId) { return api.NPC.UnloadRecord(recordId); }

bool NPCIsValidRecord(int recordId) { return api.NPC.IsValidRecord(recordId); }

int NPCGetRecordCount() { return api.NPC.GetRecordCount(); }

bool NPCUnloadAllRecords() { return api.NPC.UnloadAllRecords(); }

bool NPCOpenNode(int nodeId) { return api.NPC.OpenNode(nodeId); }

bool NPCCloseNode(int nodeId) { return api.NPC.CloseNode(nodeId); }

bool NPCIsNodeOpen(int nodeId) { return api.NPC.IsNodeOpen(nodeId); }

int NPCGetNodeType(int nodeId) { return api.NPC.GetNodeType(nodeId); }

bool NPCSetNodePoint(int nodeId, int pointId) {
  return api.NPC.SetNodePoint(nodeId, pointId);
}

bool NPCGetNodePointPosition(int nodeId, float *x, float *y, float *z) {
  return api.NPC.GetNodePointPosition(nodeId, x, y, z);
}

int NPCGetNodePointCount(int nodeId) {
  return api.NPC.GetNodePointCount(nodeId);
}

bool NPCGetNodeInfo(int nodeId, uint32_t *vehicleNodes, uint32_t *pedNodes,
                    uint32_t *naviNodes) {
  return api.NPC.GetNodeInfo(nodeId, vehicleNodes, pedNodes, naviNodes);
}

bool NPCPlayNode(int npcid, int nodeId, int moveType, float moveSpeed,
                 float radius, bool setAngle) {
  return api.NPC.PlayNode(api.NPC.FromID(npcid), nodeId, moveType, moveSpeed,
                          radius, setAngle);
}

bool NPCStopPlayingNode(int npcid) {
  return api.NPC.StopPlayingNode(api.NPC.FromID(npcid));
}

bool NPCPausePlayingNode(int npcid) {
  return api.NPC.PausePlayingNode(api.NPC.FromID(npcid));
}

bool NPCResumePlayingNode(int npcid) {
  return api.NPC.ResumePlayingNode(api.NPC.FromID(npcid));
}

bool NPCIsPlayingNodePaused(int npcid) {
  return api.NPC.IsPlayingNodePaused(api.NPC.FromID(npcid));
}

bool NPCIsPlayingNode(int npcid) {
  return api.NPC.IsPlayingNode(api.NPC.FromID(npcid));
}

int NPCChangeNode(int npcid, int nodeId, int linkId) {
  return api.NPC.ChangeNode(api.NPC.FromID(npcid), nodeId, linkId);
}

bool NPCUpdateNodePoint(int npcid, int pointId) {
  return api.NPC.UpdateNodePoint(api.NPC.FromID(npcid), pointId);
}

bool SetNPCSurfingOffset(int npcid, float x, float y, float z) {
  return api.NPC.SetSurfingOffset(api.NPC.FromID(npcid), x, y, z);
}

bool GetNPCSurfingOffset(int npcid, float *x, float *y, float *z) {
  return api.NPC.GetSurfingOffset(api.NPC.FromID(npcid), x, y, z);
}

bool SetNPCSurfingVehicle(int npcid, int vehicleid) {
  return api.NPC.SetSurfingVehicle(api.NPC.FromID(npcid),
                                   api.Vehicle.FromID(vehicleid));
}

int GetNPCSurfingVehicle(int npcid) {
  return api.NPC.GetSurfingVehicle(api.NPC.FromID(npcid));
}

bool SetNPCSurfingObject(int npcid, int objectid) {
  return api.NPC.SetSurfingObject(api.NPC.FromID(npcid),
                                  api.Object.FromID(objectid));
}

int GetNPCSurfingObject(int npcid) {
  return api.NPC.GetSurfingObject(api.NPC.FromID(npcid));
}

bool SetNPCSurfingPlayerObject(int npcid, int playerid, int objectid) {
  return api.NPC.SetSurfingPlayerObject(api.NPC.FromID(npcid),
                                        api.Player.FromID(playerid), objectid);
}

int GetNPCSurfingPlayerObject(int npcid) {
  return api.NPC.GetSurfingPlayerObject(api.NPC.FromID(npcid));
}

int AddCharModel(int baseid, int newid, const char *dff,
                 const char *textureLibrary) {
  return api.CustomModel.AddCharModel(baseid, newid, (char *)dff,
                                      (char *)textureLibrary);
}

int AddSimpleModel(int virtualWorld, int baseid, int newid, const char *dff,
                   const char *textureLibrary) {
  return api.CustomModel.AddSimpleModel(virtualWorld, baseid, newid,
                                        (char *)dff, (char *)textureLibrary);
}

int AddSimpleModelTimed(int virtualWorld, int baseid, int newid,
                        const char *dff, const char *textureLibrary, int timeOn,
                        int timeOff) {
  return api.CustomModel.AddSimpleModelTimed(
      virtualWorld, baseid, newid, (char *)dff, (char *)textureLibrary, timeOn,
      timeOff);
}

bool RedirectDownload(int playerid, const char *url) {
  return api.CustomModel.RedirectDownload(api.Player.FromID(playerid),
                                          (char *)url);
}

bool FindModelFileNameFromCRC(int crc, char *output, int size) {
  struct CAPIStringView view = {0};
  int res = api.CustomModel.FindModelFileNameFromCRC(crc, &view);

  if (res && output && size > 0 && view.data) {
    strncpy(output, view.data, size);
    output[size - 1] = '\0';
  }

  return res;
}

bool IsValidCustomModel(int modelId) {
  return api.CustomModel.IsValid(modelId);
}

bool GetCustomModelPath(int modelId, char *dffPath, int dffPathSize,
                        char *txdPath, int txdPathSize) {
  struct CAPIStringView dffView = {0};
  struct CAPIStringView txdView = {0};
  bool res = api.CustomModel.GetPath(modelId, &dffView, &txdView);
  if (res) {
    if (dffPath && dffPathSize > 0 && dffView.data) {
      strncpy(dffPath, dffView.data, dffPathSize);
      dffPath[dffPathSize - 1] = '\0';
    }
    if (txdPath && txdPathSize > 0 && txdView.data) {
      strncpy(txdPath, txdView.data, txdPathSize);
      txdPath[txdPathSize - 1] = '\0';
    }
  }
  return res;
}

bool IsPickupStreamedIn(int playerid, int pickupid) {
  return api.Pickup.IsStreamedIn(api.Player.FromID(playerid),
                                 api.Pickup.FromID(pickupid));
}

bool GetPickupPos(int pickupid, float *x, float *y, float *z) {
  return api.Pickup.GetPos(api.Pickup.FromID(pickupid), x, y, z);
}

int GetPickupModel(int pickupid) {
  return api.Pickup.GetModel(api.Pickup.FromID(pickupid));
}

int GetPickupType(int pickupid) {
  return api.Pickup.GetType(api.Pickup.FromID(pickupid));
}

int GetPickupVirtualWorld(int pickupid) {
  return api.Pickup.GetVirtualWorld(api.Pickup.FromID(pickupid));
}

bool SetPickupPos(int pickupid, float x, float y, float z, bool update) {
  return api.Pickup.SetPos(api.Pickup.FromID(pickupid), x, y, z, update);
}

bool SetPickupModel(int pickupid, int model, bool update) {
  return api.Pickup.SetModel(api.Pickup.FromID(pickupid), model, update);
}

bool SetPickupType(int pickupid, int type, bool update) {
  return api.Pickup.SetType(api.Pickup.FromID(pickupid), type, update);
}

bool SetPickupVirtualWorld(int pickupid, int virtualworld) {
  return api.Pickup.SetVirtualWorld(api.Pickup.FromID(pickupid), virtualworld);
}

bool ShowPickupForPlayer(int playerid, int pickupid) {
  return api.Pickup.ShowForPlayer(api.Player.FromID(playerid),
                                  api.Pickup.FromID(pickupid));
}

bool HidePickupForPlayer(int playerid, int pickupid) {
  return api.Pickup.HideForPlayer(api.Player.FromID(playerid),
                                  api.Pickup.FromID(pickupid));
}

int GetVehicleMaxPassengerSeats(int modelid) {
  return api.Vehicle.GetMaxPassengerSeats(modelid);
}

bool CanVehicleHaveComponent(int modelid, int componentid) {
  return api.Vehicle.CanHaveComponent(modelid, componentid);
}

bool GetVehicleRandomColorPair(int modelid, int *color1, int *color2,
                               int *color3, int *color4) {
  return api.Vehicle.GetRandomColorPair(modelid, color1, color2, color3,
                                        color4);
}

int VehicleColorIndexToColor(int colorIndex, int alpha) {
  return api.Vehicle.ColorIndexToColor(colorIndex, alpha);
}

int GetVehicleLandingGearState(int vehicleid) {
  return api.Vehicle.GetLandingGearState(api.Vehicle.FromID(vehicleid));
}

bool GetVehicleSpawnInfo(int vehicleid, float *x, float *y, float *z,
                         float *rotation, int *color1, int *color2) {
  return api.Vehicle.GetSpawnInfo(api.Vehicle.FromID(vehicleid), x, y, z,
                                  rotation, color1, color2);
}

bool SetVehicleSpawnInfo(int vehicleid, int modelid, float x, float y, float z,
                         float rotation, int color1, int color2,
                         int respawn_time, int interior) {
  return api.Vehicle.SetSpawnInfo(api.Vehicle.FromID(vehicleid), modelid, x, y,
                                  z, rotation, color1, color2, respawn_time,
                                  interior);
}

int GetVehicleModelCount(int modelid) {
  return api.Vehicle.GetModelCount(modelid);
}

int GetVehicleModelsUsed() { return api.Vehicle.GetModelsUsed(); }

int GetVehiclePaintjob(int vehicleid) {
  return api.Vehicle.GetPaintjob(api.Vehicle.FromID(vehicleid));
}

bool GetVehicleColor(int vehicleid, int *color1, int *color2) {
  return api.Vehicle.GetColor(api.Vehicle.FromID(vehicleid), color1, color2);
}

int GetVehicleInterior(int vehicleid) {
  return api.Vehicle.GetInterior(api.Vehicle.FromID(vehicleid));
}

bool GetVehicleNumberPlate(int vehicleid, char *numberPlate, int size) {
  struct CAPIStringView view = {0};
  bool res = api.Vehicle.GetNumberPlate(api.Vehicle.FromID(vehicleid), &view);
  if (res && numberPlate && size > 0 && view.data) {
    strncpy(numberPlate, view.data, size);
    numberPlate[size - 1] = '\0';
  }
  return res;
}

bool SetVehicleRespawnDelay(int vehicleid, int respawn_delay) {
  return api.Vehicle.SetRespawnDelay(api.Vehicle.FromID(vehicleid),
                                     respawn_delay);
}

int GetVehicleRespawnDelay(int vehicleid) {
  return api.Vehicle.GetRespawnDelay(api.Vehicle.FromID(vehicleid));
}

int GetVehicleCab(int vehicleid) {
  return api.Vehicle.GetID(api.Vehicle.GetCab(api.Vehicle.FromID(vehicleid)));
}

int GetVehicleTower(int vehicleid) {
  return api.Vehicle.GetID(api.Vehicle.GetTower(api.Vehicle.FromID(vehicleid)));
}

int GetVehicleOccupiedTick(int vehicleid) {
  return api.Vehicle.GetOccupiedTick(api.Vehicle.FromID(vehicleid));
}

int GetVehicleRespawnTick(int vehicleid) {
  return api.Vehicle.GetRespawnTick(api.Vehicle.FromID(vehicleid));
}

bool HasVehicleBeenOccupied(int vehicleid) {
  return api.Vehicle.HasBeenOccupied(api.Vehicle.FromID(vehicleid));
}

bool IsVehicleOccupied(int vehicleid) {
  return api.Vehicle.IsOccupied(api.Vehicle.FromID(vehicleid));
}

bool IsVehicleDead(int vehicleid) {
  return api.Vehicle.IsDead(api.Vehicle.FromID(vehicleid));
}

bool SetVehicleParamsSirenState(int vehicleid, bool siren_state) {
  return api.Vehicle.SetParamsSirenState(api.Vehicle.FromID(vehicleid),
                                         siren_state);
}

bool ToggleVehicleSirenEnabled(int vehicleid, bool status) {
  return api.Vehicle.ToggleSirenEnabled(api.Vehicle.FromID(vehicleid), status);
}

bool IsVehicleSirenEnabled(int vehicleid) {
  return api.Vehicle.IsSirenEnabled(api.Vehicle.FromID(vehicleid));
}

int GetVehicleLastDriver(int vehicleid) {
  return api.Player.GetID(
      api.Vehicle.GetLastDriver(api.Vehicle.FromID(vehicleid)));
}

int GetVehicleDriver(int vehicleid) {
  return api.Player.GetID(api.Vehicle.GetDriver(api.Vehicle.FromID(vehicleid)));
}

int GetVehicleSirenState(int vehicleid) {
  return api.Vehicle.GetSirenState(api.Vehicle.FromID(vehicleid));
}

int GetVehicleHydraReactorAngle(int vehicleid) {
  return (int)api.Vehicle.GetHydraReactorAngle(api.Vehicle.FromID(vehicleid));
}

float GetVehicleTrainSpeed(int vehicleid) {
  return api.Vehicle.GetTrainSpeed(api.Vehicle.FromID(vehicleid));
}

bool GetVehicleMatrix(int vehicleid, float *rightX, float *rightY,
                      float *rightZ, float *upX, float *upY, float *upZ,
                      float *atX, float *atY, float *atZ) {
  return api.Vehicle.GetMatrix(api.Vehicle.FromID(vehicleid), rightX, rightY,
                               rightZ, upX, upY, upZ, atX, atY, atZ);
}

int GetVehicleOccupant(int vehicleid, int seat) {
  return api.Player.GetID(
      api.Vehicle.GetOccupant(api.Vehicle.FromID(vehicleid), seat));
}

int CountVehicleOccupants(int vehicleid) {
  return api.Vehicle.CountOccupants(api.Vehicle.FromID(vehicleid));
}

bool GetPlayerPos(int playerid, float *x, float *y, float *z) {
  return api.Player.GetPos(api.Player.FromID(playerid), x, y, z);
}

bool SetPlayerPos(int playerid, float x, float y, float z) {
  return api.Player.SetPos(api.Player.FromID(playerid), x, y, z);
}

bool GetPlayerFacingAngle(int playerid, float *angle) {
  if (angle == false || !IsPlayerConnected(playerid)) {
    return false;
  }

  *angle = api.Player.GetFacingAngle(api.Player.FromID(playerid));

  return true;
}

bool SetPlayerFacingAngle(int playerid, float angle) {
  return api.Player.SetFacingAngle(api.Player.FromID(playerid), angle);
}
