#pragma once

#ifdef SYNERGYCORE_EXPORTS
#define SYNERGYCORE_API __declspec(dllexport)
#else
#define SYNERGYCORE_API __declspec(dllimport)
#endif

#define SYNERGYCORE_UDP_PORT 19810
#define SYNERGYCORE_TCP_PORT 19811