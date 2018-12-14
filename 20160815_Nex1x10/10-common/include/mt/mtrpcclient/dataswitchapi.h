#include "struct.pb.h"
#include "mtmacro.h"

MTCBB_API u32 RPC_AddSwitch(mt::TNetAddr &tRcvAddr, u32 dwInLocalIP, mt::TNetAddr &tSndAddr, u32 dwOutLocalIP);
MTCBB_API u32 RPC_RemoveSwitch(mt::TNetAddr &tSndAddr);
MTCBB_API u32 RPC_AddSrcSwitch(mt::TNetAddr & tRcvAddr, u32 dwInLocalIP,mt::TNetAddr & tSrcAddr ,mt::TNetAddr &tSndAddr, u32 dwOutLocalIP);
MTCBB_API u32 RPC_RemoveSrcSwitch(mt::TNetAddr & tRcvAddr, mt::TNetAddr & tSrcAddr ,mt::TNetAddr &tSndAddr);
MTCBB_API u32 RPC_AddDump(mt::TNetAddr &tRcvAddr, u32 dwInLocalIP);
MTCBB_API u32 RPC_RemoveDump(mt::TNetAddr &tRcvAddr);
MTCBB_API u32 RPC_AddMultiSwitch(mt::TNetAddr &tRcvAddr, u32 dwInLocalIP, mt::TRpNetAddr &tSndAddrs, u32 dwOutLocalIP);
MTCBB_API u32 RPC_RemoveMultiSwitch(mt::TRpNetAddr &tSndAddrs);
MTCBB_API u32 RPC_AddMany2OneSwitch(mt::TNetAddr &tRcvAddr, u32 dwInLocalIP, mt::TNetAddr &tSndAddr, u32 dwOutLocalIP, BOOL32 bUseMapAddr, mt::TNetAddr &tMapAddr);
MTCBB_API u32 RPC_RemoveMany2OneSwitch(mt::TNetAddr &tRcvAddr, mt::TNetAddr &tSndAddr);