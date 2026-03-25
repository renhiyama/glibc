/* RunixOS: override ld.so.cache path to use LibKit.cache */
#define LD_SO_CACHE SYSCONFDIR "/LibKit.cache"

#include_next <dl-cache.h>
