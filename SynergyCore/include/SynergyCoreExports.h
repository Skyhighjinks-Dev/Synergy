#pragma once

#ifdef SYNERGYCORE_EXPORTS
#define SYNERGYCORE_API __declspec(dllexport)
#else
#define SYNERGYCORE_API __declspec(dllimport)
#endif