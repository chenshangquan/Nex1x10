#include "nvstruct.pb.h"
#include "nvmacro.h"

NVCBB_API u32 RPC_AddSwitch(nv::TNVNetAddr &tRcvAddr, u32 dwInLocalIP, nv::TNVNetAddr &tSndAddr, u32 dwOutLocalIP);
NVCBB_API u32 RPC_RemoveSwitch(nv::TNVNetAddr &tSndAddr);
NVCBB_API u32 RPC_AddSrcSwitch(nv::TNVNetAddr & tRcvAddr, u32 dwInLocalIP,nv::TNVNetAddr & tSrcAddr ,nv::TNVNetAddr &tSndAddr, u32 dwOutLocalIP);
NVCBB_API u32 RPC_RemoveSrcSwitch(nv::TNVNetAddr & tRcvAddr, nv::TNVNetAddr & tSrcAddr ,nv::TNVNetAddr &tSndAddr);
NVCBB_API u32 RPC_AddDump(nv::TNVNetAddr &tRcvAddr, u32 dwInLocalIP);
NVCBB_API u32 RPC_RemoveDump(nv::TNVNetAddr &tRcvAddr);
NVCBB_API u32 RPC_AddMultiSwitch(nv::TNVNetAddr &tRcvAddr, u32 dwInLocalIP, nv::TNVRpNetAddr &tSndAddrs, u32 dwOutLocalIP);
NVCBB_API u32 RPC_RemoveMultiSwitch(nv::TNVRpNetAddr &tSndAddrs);
NVCBB_API u32 RPC_AddMany2OneSwitch(nv::TNVNetAddr &tRcvAddr, u32 dwInLocalIP, nv::TNVNetAddr &tSndAddr, u32 dwOutLocalIP, BOOL32 bUseMapAddr, nv::TNVNetAddr &tMapAddr);
NVCBB_API u32 RPC_RemoveMany2OneSwitch(nv::TNVNetAddr &tRcvAddr, nv::TNVNetAddr &tSndAddr);