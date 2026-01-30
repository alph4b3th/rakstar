#include "main.h"

struct OMPAPI_t api;

struct ComponentVersion componentVersion;
char *componentName = NULL;

char *constToNonConst(const char *text) { return (char *)text; }

const char *nonConstToConst(char *text) { return (const char *)text; }

void _onReady() { printf("onReady\n"); }
void _onReset() { printf("onReset\n"); }
void _onFree() {
  printf("onFree\n");

  if (componentName != NULL) {
    free(componentName);
  }
}

bool _onPlayerConnect(struct EventArgs_onPlayerConnect *args) {
  int playerid = api.Player.GetID(*args->list->player);

  return onPlayerConnect(playerid);
}

bool _onPlayerDisconnect(struct EventArgs_onPlayerDisconnect *args) {
  int playerid = api.Player.GetID(*args->list->player);
  int reason = *args->list->reason;

  return onPlayerDisconnect(playerid, reason);
}

bool _onPlayerRequestClass(struct EventArgs_onPlayerRequestClass *args) {
  int playerId = api.Player.GetID(*args->list->player);
  int classId = -1;

  if (args->list->classId != NULL) {
    classId = *args->list->classId;
  }

  return onPlayerRequestClass(playerId, classId);
}

bool _onPlayerRequestSpawn(struct EventArgs_onPlayerRequestSpawn *args) {
  int playerId = api.Player.GetID(*args->list->player);

  return onPlayerRequestSpawn(playerId);
}

bool _onPlayerSpawn(struct EventArgs_onPlayerSpawn *args) {
  int playerId = api.Player.GetID(*args->list->player);

  return onPlayerSpawn(playerId);
}

bool _onPlayerDeath(struct EventArgs_onPlayerDeath *args) {
  int playerId = api.Player.GetID(*args->list->player);
  int killerId = api.Player.GetID(*args->list->killer);
  int reason = *args->list->reason;

  return onPlayerDeath(playerId, killerId, reason);
}

bool _onPlayerUpdate(struct EventArgs_onPlayerUpdate *args) {
  int playerId = api.Player.GetID(*args->list->player);

  return onPlayerUpdate(playerId);
}

bool _onPlayerText(struct EventArgs_onPlayerText *args) {
  int playerId = api.Player.GetID(*args->list->player);
  char *text = (char *)args->list->text->data;

  return onPlayerText(playerId, text);
}

bool _onPlayerCommandText(struct EventArgs_onPlayerCommandText *args) {
  int playerId = api.Player.GetID(*args->list->player);
  char *command = (char *)args->list->command->data;

  return onPlayerCommandText(playerId, command);
}

bool _onPlayerInteriorChange(struct EventArgs_onPlayerInteriorChange *args) {
  int playerId = api.Player.GetID(*args->list->player);
  int newInteriorId = *args->list->newInterior;
  int oldInteriorId = *args->list->oldInterior;

  return onPlayerInteriorChange(playerId, newInteriorId, oldInteriorId);
}

bool _onPlayerStateChange(struct EventArgs_onPlayerStateChange *args) {
  int playerId = api.Player.GetID(*args->list->player);
  int newState = *args->list->newState;
  int oldState = *args->list->oldState;

  return onPlayerStateChange(playerId, newState, oldState);
}

bool _onPlayerKeyStateChange(struct EventArgs_onPlayerKeyStateChange *args) {
  int playerId = api.Player.GetID(*args->list->player);
  int newKeys = *args->list->newKeys;
  int oldKeys = *args->list->oldKeys;

  return onPlayerKeyStateChange(playerId, newKeys, oldKeys);
}

bool _onPlayerEnterVehicle(struct EventArgs_onPlayerEnterVehicle *args) {
  int playerId = api.Player.GetID(*args->list->player);
  int vehicleId = api.Vehicle.GetID(*args->list->vehicle);
  bool isPassenger = *args->list->passenger;

  return onPlayerEnterVehicle(playerId, vehicleId, isPassenger);
}

bool _onPlayerExitVehicle(struct EventArgs_onPlayerExitVehicle *args) {
  int playerId = api.Player.GetID(*args->list->player);
  int vehicleId = api.Vehicle.GetID(*args->list->vehicle);

  return onPlayerExitVehicle(playerId, vehicleId);
}

bool _onPlayerEnterCheckpoint(struct EventArgs_onPlayerEnterCheckpoint *args) {
  int playerId = api.Player.GetID(*args->list->player);

  return onPlayerEnterCheckpoint(playerId);
}

bool _onPlayerLeaveCheckpoint(struct EventArgs_onPlayerLeaveCheckpoint *args) {
  int playerId = api.Player.GetID(*args->list->player);

  return onPlayerLeaveCheckpoint(playerId);
}

bool _onPlayerEnterRaceCheckpoint(
    struct EventArgs_onPlayerEnterRaceCheckpoint *args) {
  int playerId = api.Player.GetID(*args->list->player);

  return onPlayerEnterRaceCheckpoint(playerId);
}

bool _onPlayerLeaveRaceCheckpoint(
    struct EventArgs_onPlayerLeaveRaceCheckpoint *args) {
  int playerId = api.Player.GetID(*args->list->player);

  return onPlayerLeaveRaceCheckpoint(playerId);
}

bool _onPlayerGiveDamage(struct EventArgs_onPlayerGiveDamage *args) {
  int playerId = api.Player.GetID(*args->list->player);
  int damagedId = api.Player.GetID(*args->list->to);
  int amount = *args->list->amount;
  int weaponId = *args->list->weapon;
  int bodyPart = *args->list->bodypart;

  return onPlayerGiveDamage(playerId, damagedId, amount, weaponId, bodyPart);
}

bool _onPlayerTakeDamage(struct EventArgs_onPlayerTakeDamage *args) {
  int playerId = api.Player.GetID(*args->list->player);
  int issuerId = api.Player.GetID(*args->list->from);
  int amount = *args->list->amount;
  int weaponId = *args->list->weapon;
  int bodyPart = *args->list->bodypart;

  return onPlayerTakeDamage(playerId, issuerId, amount, weaponId, bodyPart);
}

bool _onPlayerGiveDamageActor(struct EventArgs_onPlayerGiveDamageActor *args) {
  int playerId = api.Player.GetID(*args->list->player);
  int damagedActorId = api.Player.GetID(*args->list->actor);
  int amount = *args->list->amount;
  int weaponId = *args->list->weapon;
  int bodyPart = *args->list->part;

  return onPlayerGiveDamageActor(playerId, damagedActorId, amount, weaponId,
                                 bodyPart);
}

// bool _onPlayerWeaponShot(void *args) {
//   return onPlayerWeaponShot(playerId, weaponId, hitType, hitId, fX, fY, fZ);
// }

bool _onPlayerPickUpPickup(struct EventArgs_onPlayerPickUpPickup *args) {
  int playerId = api.Player.GetID(*args->list->player);
  int pickupId = api.Pickup.GetID(*args->list->pickup);

  return onPlayerPickUpPickup(playerId, pickupId);
}

bool _onPlayerObjectMoved(struct EventArgs_onPlayerObjectMove *args) {
  int playerId = api.Player.GetID(*args->list->player);
  int objectId = api.Object.GetID(*args->list->object);

  return onPlayerObjectMoved(playerId, objectId);
}

bool _onPlayerEditObject(struct EventArgs_onPlayerEditObject *args) {
  int playerId = api.Player.GetID(*args->list->player);
  bool playerObject =
      api.PlayerObject.IsValid(*args->list->player, *args->list->object);
  int objectId = api.Object.GetID(*args->list->object);
  int response = *args->list->response;
  float offsetX = *args->list->offsetX;
  float offsetY = *args->list->offsetY;
  float offsetZ = *args->list->offsetZ;
  float rotationX = *args->list->rotationX;
  float rotationY = *args->list->rotationY;
  float rotationZ = *args->list->rotationZ;

  return onPlayerEditObject(playerId, playerObject, objectId, response, offsetX,
                            offsetY, offsetZ, rotationX, rotationY, rotationZ);
}

// bool _onPlayerEditAttachedObject(
//     struct EventArgs_onPlayerEditAttachedObject *args) {
//   return onPlayerEditAttachedObject(playerId, response, index, modelId,
//   boneId,
//                                     fOffsetX, fOffsetY, fOffsetZ, fRotX,
//                                     fRotY, fRotZ, fScaleX, fScaleY, fScaleZ);
// }

// bool _onPlayerSelectObject(struct EventArgs_onPlayerSelectObject *args) {
//   return onPlayerSelectObject(playerId, type, objectId, modelId, fX, fY, fZ);
// }

bool _onPlayerClickMap(struct EventArgs_onPlayerClickMap *args) {
  int playerId = api.Player.GetID(*args->list->player);
  float x = *args->list->x;
  float y = *args->list->y;
  float z = *args->list->z;

  return onPlayerClickMap(playerId, x, y, z);
}

bool _onPlayerClickTextDraw(struct EventArgs_onPlayerClickTextDraw *args) {
  int playerId = api.Player.GetID(*args->list->player);
  int clickedId = api.TextDraw.GetID(*args->list->textdraw);

  return onPlayerClickTextDraw(playerId, clickedId);
}

bool _onPlayerClickPlayerTextDraw(
    struct EventArgs_onPlayerClickPlayerTextDraw *args) {
  int playerId = api.Player.GetID(*args->list->player);
  int playerTextId =
      api.PlayerTextDraw.GetID(*args->list->player, *args->list->textdraw);

  return onPlayerClickPlayerTextDraw(playerId, playerTextId);
}

bool _onPlayerClickPlayer(struct EventArgs_onPlayerClickPlayer *args) {
  int playerId = api.Player.GetID(*args->list->player);
  int clickedPlayerId =
      api.PlayerTextDraw.GetID(*args->list->player, *args->list->clicked);
  int source = *args->list->source;

  return onPlayerClickPlayer(playerId, clickedPlayerId, source);
}

bool _onPlayerStreamIn(struct EventArgs_onPlayerStreamIn *args) {
  int playerId = api.Player.GetID(*args->list->player);
  int forPlayerId = api.Player.GetID(*args->list->forPlayer);

  return onPlayerStreamIn(playerId, forPlayerId);
}

bool _onPlayerStreamOut(struct EventArgs_onPlayerStreamOut *args) {
  int playerId = api.Player.GetID(*args->list->player);
  int forPlayerId = api.Player.GetID(*args->list->forPlayer);

  return onPlayerStreamOut(playerId, forPlayerId);
}

bool _onPlayerExitedMenu(struct EventArgs_onPlayerExitedMenu *args) {
  int playerId = api.Player.GetID(*args->list->player);

  return onPlayerExitedMenu(playerId);
}

bool _onPlayerSelectedMenuRow(struct EventArgs_onPlayerSelectedMenuRow *args) {
  int playerId = api.Player.GetID(*args->list->player);
  int row = *args->list->row;

  printf("Ground control\n");

  return onPlayerSelectedMenuRow(playerId, row);
}

bool _onPlayerRequestDownload(struct EventArgs_onPlayerRequestDownload *args) {
  int playerId = api.Player.GetID(*args->list->player);
  int type = *args->list->type;
  int checksum = *args->list->checksum;

  return onPlayerRequestDownload(playerId, type, checksum);
}

void _onTick(struct EventArgs_onTick *args) { onTick(); }

bool _onIncomingConnection(struct EventArgs_onIncomingConnection *args) {
  int playerId = api.Player.GetID(*args->list->player);
  char *ipAddress = (char *)args->list->ipAddress->data;
  int port = *args->list->port;

  return onIncomingConnection(playerId, ipAddress, port);
}

bool _onRconLoginAttempt(struct EventArgs_onRconLoginAttempt *args) {
  char *address = (char *)args->list->address->data;
  char *password = (char *)args->list->password->data;
  bool success = *args->list->success;

  return onRconLoginAttempt(address, password, success);
}

bool _onConsoleText(struct EventArgs_onConsoleText *args) {
  char *cmd = (char *)args->list->command->data;

  return onRconCommand(cmd);
}

bool _onDialogResponse(struct EventArgs_onDialogResponse *args) {
  int playerId = api.Player.GetID(*args->list->player);
  int dialogId = *args->list->dialogId;
  int response = *args->list->response;
  int listItem = *args->list->listItem;
  char *inputText = (char *)args->list->inputText->data;

  return onDialogResponse(playerId, dialogId, response, listItem, inputText);
}

bool _onVehicleSpawn(struct EventArgs_onVehicleSpawn *args) {
  int vehicleId = api.Vehicle.GetID(*args->list->vehicle);

  return onVehicleSpawn(vehicleId);
}

bool _onVehicleDeath(struct EventArgs_onVehicleDeath *args) {
  int vehicleId = api.Vehicle.GetID(*args->list->vehicle);
  int killerId = api.Player.GetID(*args->list->player);

  return onVehicleDeath(vehicleId, killerId);
}

bool _onVehicleMod(struct EventArgs_onVehicleMod *args) {
  int playerId = api.Player.GetID(*args->list->player);
  int vehicleId = api.Vehicle.GetID(*args->list->vehicle);
  int componentId = *args->list->component;

  return onVehicleMod(playerId, vehicleId, componentId);
}

bool _onVehiclePaintjob(struct EventArgs_onVehiclePaintJob *args) {
  int playerId = api.Player.GetID(*args->list->player);
  int vehicleId = api.Vehicle.GetID(*args->list->vehicle);
  int paintjobId = *args->list->paintJob;

  return onVehiclePaintjob(playerId, vehicleId, paintjobId);
}

bool _onVehicleRespray(struct EventArgs_onVehicleRespray *args) {
  int playerId = api.Player.GetID(*args->list->player);
  int vehicleId = api.Vehicle.GetID(*args->list->vehicle);
  int color1 = *args->list->color1;
  int color2 = *args->list->color2;

  return onVehicleRespray(playerId, vehicleId, color1, color2);
}

bool _onVehicleDamageStatusUpdate(
    struct EventArgs_onVehicleDamageStatusUpdate *args) {
  int vehicleId = api.Vehicle.GetID(*args->list->vehicle);
  int playerId = api.Player.GetID(*args->list->player);

  return onVehicleDamageStatusUpdate(vehicleId, playerId);
}

bool _onVehicleSirenStateChange(
    struct EventArgs_onVehicleSirenStateChange *args) {
  int vehicleId = api.Vehicle.GetID(*args->list->vehicle);
  int playerId = api.Player.GetID(*args->list->player);
  int sirenState = *args->list->sirenState;

  return onVehicleSirenStateChange(playerId, vehicleId, sirenState);
}

bool _onVehicleStreamIn(struct EventArgs_onVehicleStreamIn *args) {
  int vehicleId = api.Vehicle.GetID(*args->list->vehicle);
  int forPlayerId = api.Player.GetID(*args->list->player);

  return onVehicleStreamIn(vehicleId, forPlayerId);
}

bool _onVehicleStreamOut(struct EventArgs_onVehicleStreamOut *args) {
  int vehicleId = api.Vehicle.GetID(*args->list->vehicle);
  int forPlayerId = api.Player.GetID(*args->list->player);

  return onVehicleStreamOut(vehicleId, forPlayerId);
}

bool _onUnoccupiedVehicleUpdate(
    struct EventArgs_onUnoccupiedVehicleUpdate *args) {
  int vehicleId = api.Vehicle.GetID(*args->list->vehicle);
  int playerId = api.Player.GetID(*args->list->player);
  int passengerSeat = *args->list->seat;
  float newX = *args->list->posX;
  float newY = *args->list->posY;
  float newZ = *args->list->posZ;
  float velocityX = *args->list->velocityX;
  float velocityY = *args->list->velocityY;
  float velocityZ = *args->list->velocityZ;

  return onUnoccupiedVehicleUpdate(vehicleId, playerId, passengerSeat, newX,
                                   newY, newZ, velocityX, velocityY, velocityZ);
}

bool _onTrailerUpdate(struct EventArgs_onTrailerUpdate *args) {
  int playerId = api.Player.GetID(*args->list->player);
  int trailerId = api.Vehicle.GetID(*args->list->trailer);

  return onTrailerUpdate(playerId, trailerId);
}

bool _onActorStreamIn(struct EventArgs_onActorStreamIn *args) {
  int actorId = api.Actor.GetID(*args->list->actor);
  int forPlayerId = api.Player.GetID(*args->list->forPlayer);

  return onActorStreamIn(actorId, forPlayerId);
}

bool _onActorStreamOut(struct EventArgs_onActorStreamOut *args) {
  int actorId = api.Actor.GetID(*args->list->actor);
  int forPlayerId = api.Player.GetID(*args->list->forPlayer);

  return onActorStreamOut(actorId, forPlayerId);
}

// bool _onObjectMoved(struct EventArgs_onObjectMoved *args) {
//   int objectId = api.Object.GetID(*args->list->object);
//
//   return onObjectMoved(objectId);
// }

bool _onEnterExitModShop(struct EventArgs_onEnterExitModShop *args) {
  int playerId = api.Player.GetID(*args->list->player);
  int enterExit = *args->list->enterexit;
  int interiorId = *args->list->interiorId;

  return onEnterExitModShop(playerId, enterExit, interiorId);
}

OMP_API_EXPORT void *ComponentEntryPoint() {
  entryPoint();

  if (!omp_initialize_capi(&api)) {
    printf("Failed to initialize open.mp C API\n");
    return NULL;
  }

  if (componentName == NULL) {
    componentName = strdup("Rakstar");
  }

  void *comp =
      api.Component.Create(0x913B89092F8F6A68, componentName, componentVersion,
                           &_onReady, &_onReset, &_onFree);

  api.Event.AddHandler("onPlayerConnect", EventPriorityType_Highest,
                       &_onPlayerConnect);
  api.Event.AddHandler("onPlayerDisconnect", EventPriorityType_Highest,
                       &_onPlayerDisconnect);
  api.Event.AddHandler("onPlayerRequestClass", EventPriorityType_Highest,
                       &_onPlayerRequestClass);
  api.Event.AddHandler("onPlayerRequestSpawn", EventPriorityType_Highest,
                       &_onPlayerRequestSpawn);
  api.Event.AddHandler("onPlayerSpawn", EventPriorityType_Highest,
                       &_onPlayerSpawn);
  api.Event.AddHandler("onPlayerDeath", EventPriorityType_Highest,
                       &_onPlayerDeath);
  api.Event.AddHandler("onPlayerUpdate", EventPriorityType_Highest,
                       &_onPlayerUpdate);
  api.Event.AddHandler("onPlayerText", EventPriorityType_Highest,
                       &_onPlayerText);
  api.Event.AddHandler("onPlayerCommandText", EventPriorityType_Highest,
                       &_onPlayerCommandText);
  api.Event.AddHandler("onPlayerInteriorChange", EventPriorityType_Highest,
                       &_onPlayerInteriorChange);
  api.Event.AddHandler("onPlayerStateChange", EventPriorityType_Highest,
                       &_onPlayerStateChange);
  api.Event.AddHandler("onPlayerKeyStateChange", EventPriorityType_Highest,
                       &_onPlayerKeyStateChange);
  api.Event.AddHandler("onPlayerEnterVehicle", EventPriorityType_Highest,
                       &_onPlayerEnterVehicle);
  api.Event.AddHandler("onPlayerExitVehicle", EventPriorityType_Highest,
                       &_onPlayerExitVehicle);
  api.Event.AddHandler("onPlayerEnterCheckpoint", EventPriorityType_Highest,
                       &_onPlayerEnterCheckpoint);
  api.Event.AddHandler("onPlayerLeaveCheckpoint", EventPriorityType_Highest,
                       &_onPlayerLeaveCheckpoint);
  api.Event.AddHandler("onPlayerEnterRaceCheckpoint", EventPriorityType_Highest,
                       &_onPlayerEnterRaceCheckpoint);
  api.Event.AddHandler("onPlayerLeaveRaceCheckpoint", EventPriorityType_Highest,
                       &_onPlayerLeaveRaceCheckpoint);
  api.Event.AddHandler("onPlayerGiveDamage", EventPriorityType_Highest,
                       &_onPlayerGiveDamage);
  api.Event.AddHandler("onPlayerTakeDamage", EventPriorityType_Highest,
                       &_onPlayerTakeDamage);
  api.Event.AddHandler("onPlayerGiveDamageActor", EventPriorityType_Highest,
                       &_onPlayerGiveDamageActor);
  // api.Event.AddHandler("onPlayerWeaponShot", EventPriorityType_Highest,
  //                      &_onPlayerWeaponShot);
  api.Event.AddHandler("onPlayerPickUpPickup", EventPriorityType_Highest,
                       &_onPlayerPickUpPickup);
  api.Event.AddHandler("onPlayerObjectMoved", EventPriorityType_Highest,
                       &_onPlayerObjectMoved);
  api.Event.AddHandler("onPlayerEditObject", EventPriorityType_Highest,
                       &_onPlayerEditObject);
  // api.Event.AddHandler("onPlayerEditAttachedObject",
  // EventPriorityType_Highest,
  //                      &_onPlayerEditAttachedObject);
  // api.Event.AddHandler("onPlayerSelectObject", EventPriorityType_Highest,
  //                      &_onPlayerSelectObject);
  api.Event.AddHandler("onPlayerClickMap", EventPriorityType_Highest,
                       &_onPlayerClickMap);
  api.Event.AddHandler("onPlayerClickTextDraw", EventPriorityType_Highest,
                       &_onPlayerClickTextDraw);
  api.Event.AddHandler("onPlayerClickPlayerTextDraw", EventPriorityType_Highest,
                       &_onPlayerClickPlayerTextDraw);
  api.Event.AddHandler("onPlayerClickPlayer", EventPriorityType_Highest,
                       &_onPlayerClickPlayer);
  api.Event.AddHandler("onPlayerStreamIn", EventPriorityType_Highest,
                       &_onPlayerStreamIn);
  api.Event.AddHandler("onPlayerStreamOut", EventPriorityType_Highest,
                       &_onPlayerStreamOut);
  api.Event.AddHandler("onPlayerExitedMenu", EventPriorityType_Highest,
                       &_onPlayerExitedMenu);
  api.Event.AddHandler("onPlayerSelectedMenuRow", EventPriorityType_Highest,
                       &_onPlayerSelectedMenuRow);
  api.Event.AddHandler("onPlayerRequestDownload", EventPriorityType_Highest,
                       &_onPlayerRequestDownload);
  api.Event.AddHandler("onTick", EventPriorityType_Highest, &_onTick);
  api.Event.AddHandler("onIncomingConnection", EventPriorityType_Highest,
                       &_onIncomingConnection);
  api.Event.AddHandler("onRconLoginAttempt", EventPriorityType_Highest,
                       &_onRconLoginAttempt);
  api.Event.AddHandler("onConsoleText", EventPriorityType_Highest,
                       &_onConsoleText);
  api.Event.AddHandler("onDialogResponse", EventPriorityType_Highest,
                       &_onDialogResponse);
  api.Event.AddHandler("onVehicleSpawn", EventPriorityType_Highest,
                       &_onVehicleSpawn);
  api.Event.AddHandler("onVehicleDeath", EventPriorityType_Highest,
                       &_onVehicleDeath);
  api.Event.AddHandler("onVehicleMod", EventPriorityType_Highest,
                       &_onVehicleMod);
  // api.Event.AddHandler("onVehiclePaintjob", EventPriorityType_Highest,
  //                      &_onVehiclePaintjob);
  api.Event.AddHandler("onVehicleRespray", EventPriorityType_Highest,
                       &_onVehicleRespray);
  api.Event.AddHandler("onVehicleDamageStatusUpdate", EventPriorityType_Highest,
                       &_onVehicleDamageStatusUpdate);
  api.Event.AddHandler("onVehicleSirenStateChange", EventPriorityType_Highest,
                       &_onVehicleSirenStateChange);
  api.Event.AddHandler("onVehicleStreamIn", EventPriorityType_Highest,
                       &_onVehicleStreamIn);
  api.Event.AddHandler("onVehicleStreamOut", EventPriorityType_Highest,
                       &_onVehicleStreamOut);
  api.Event.AddHandler("onUnoccupiedVehicleUpdate", EventPriorityType_Highest,
                       &_onUnoccupiedVehicleUpdate);
  api.Event.AddHandler("onTrailerUpdate", EventPriorityType_Highest,
                       &_onTrailerUpdate);
  api.Event.AddHandler("onActorStreamIn", EventPriorityType_Highest,
                       &_onActorStreamIn);
  api.Event.AddHandler("onActorStreamOut", EventPriorityType_Highest,
                       &_onActorStreamOut);
  // api.Event.AddHandler("onObjectMoved", EventPriorityType_Highest,
  //                      &_onObjectMoved);
  api.Event.AddHandler("onEnterExitModShop", EventPriorityType_Highest,
                       &_onEnterExitModShop);
  return comp;
}
