# Unlocked Tickrate

Quite self-explanatory, bypass forced tickrate in TF2 by hooking in Server methods.

## Usage

Download latest release from https://github.com/ldesgoui/mms-unlocked-tickrate/releases to steam/steamapps/common/Team Fortress 2 Dedicated Server/tf and unzip it.  
Check if it loaded properly with `rcon meta list`  
**Reload the map with `changelevel <map>`**

## Suggested config

```
sv_minrate <20000 * tickrate * 0.015>
sv_maxrate <80000 * tickrate * 0.015>
sv_minupdaterate <tickrate>
sv_mincmdrate <tickrate>
sv_maxupdaterate <tickrate>
sv_maxcmdrate <tickrate>
```
