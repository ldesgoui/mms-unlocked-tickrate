#include <ISmmPlugin.h>

PLUGIN_GLOBALVARS();
SH_DECL_HOOK0(IServerGameDLL, GetTickInterval, const, 0, float);

#ifndef TICK_INTERVAL
# ifdef TICK_RATE
#  define TICK_INTERVAL (1.0f/TICK_RATE)
# else
#  define TICK_INTERVAL 0.008
# endif
#endif

float Hook_GetTickInterval()
{
    RETURN_META_VALUE(MRES_SUPERCEDE, TICK_INTERVAL);
}

class TickRatePlugin : public ISmmPlugin
{
    public:
        bool Load(PluginId id, ISmmAPI *ismm, char *error, size_t maxlen, bool late);
        bool Unload(char *error, size_t maxlen);
    public:
        const char *GetAuthor();
        const char *GetName();
        const char *GetDescription();
        const char *GetURL();
        const char *GetLicense();
        const char *GetVersion();
        const char *GetDate();
        const char *GetLogTag();
};

TickRatePlugin g_TickRatePlugin;
PLUGIN_EXPOSE(TickRatePlugin, g_TickRatePlugin);

IServerGameDLL *server = NULL;

bool TickRatePlugin::Load(PluginId id, ISmmAPI *ismm, char *error, size_t maxlen, bool late)
{
    PLUGIN_SAVEVARS();
#if defined METAMOD_PLAPI_VERSION
    GET_V_IFACE_ANY(GetServerFactory, server, IServerGameDLL, INTERFACEVERSION_SERVERGAMEDLL);
#else
    GET_V_IFACE_ANY(serverFactory, server, IServerGameDLL, INTERFACEVERSION_SERVERGAMEDLL);
#endif
    SH_ADD_HOOK_STATICFUNC(IServerGameDLL, GetTickInterval, server, Hook_GetTickInterval, false);
    return true;
}

bool TickRatePlugin::Unload(char *error, size_t maxlen)
{
    SH_REMOVE_HOOK_STATICFUNC(IServerGameDLL, GetTickInterval, server, Hook_GetTickInterval, false);
    return true;
}

const char *TickRatePlugin::GetLicense()        { return "MIT"; }
const char *TickRatePlugin::GetVersion()        { return "0.1.0"; }
const char *TickRatePlugin::GetDate()           { return __DATE__; }
const char *TickRatePlugin::GetLogTag()         { return "mms-unlocked-tickrate"; }
const char *TickRatePlugin::GetAuthor()         { return "ldesgoui"; }
const char *TickRatePlugin::GetDescription()    { return "Force a server's tickrate"; }
const char *TickRatePlugin::GetName()           { return "Unlocked Tickrate"; }
const char *TickRatePlugin::GetURL()            { return "https://github.com/ldesgoui/mms-unlocked-tickrate"; }
