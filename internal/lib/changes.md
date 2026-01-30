bool GetPlayerArmour(int playerid, float *armour) {
  *armour = api.Player.GetArmor(api.Player.FromID(playerid));
  return true;
}


bool GetPlayerHealth(int playerid, float *health) {
  *health = api.Player.GetHealth(api.Player.FromID(playerid));

  return true;
}
