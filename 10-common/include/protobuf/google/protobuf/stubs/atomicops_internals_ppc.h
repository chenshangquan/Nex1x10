/*****************************************************************************
模块名      : protobuf
文件名      : atomicops_internals_ppc.h
相关文件    : 无
文件实现功能: ppc平台原子操作头文件
作者        : 
版本        : V1.0  Copyright(C) 2015 KDC, All rights reserved.
-----------------------------------------------------------------------------
修改记录:
日  期      版本        修改人      修改内容
2015/3/10  1.0         田丽平      Create
******************************************************************************/
#ifndef GOOGLE_PROTOBUF_ATOMICOPS_INTERNALS_PPC_H_
#define GOOGLE_PROTOBUF_ATOMICOPS_INTERNALS_PPC_H_

namespace google {
namespace protobuf {
namespace internal {

Atomic32 NoBarrier_CompareAndSwap(volatile Atomic32* ptr, Atomic32 old_value, Atomic32 new_value);

Atomic32 NoBarrier_AtomicExchange(volatile Atomic32* ptr, Atomic32 new_value);

Atomic32 NoBarrier_AtomicIncrement(volatile Atomic32* ptr, Atomic32 increment);


Atomic32 Barrier_AtomicIncrement(volatile Atomic32* ptr, Atomic32 increment);

Atomic32 Acquire_CompareAndSwap(volatile Atomic32* ptr, Atomic32 old_value, Atomic32 new_value);

Atomic32 Release_CompareAndSwap(volatile Atomic32* ptr, Atomic32 old_value, Atomic32 new_value);

void NoBarrier_Store(volatile Atomic32* ptr, Atomic32 value);

void MemoryBarrier();

void Acquire_Store(volatile Atomic32* ptr, Atomic32 value);

void Release_Store(volatile Atomic32* ptr, Atomic32 value);

Atomic32 NoBarrier_Load(volatile const Atomic32* ptr);

Atomic32 Acquire_Load(volatile const Atomic32* ptr);

Atomic32 Release_Load(volatile const Atomic32* ptr);

}  // namespace internal
}  // namespace protobuf
}  // namespace google

#endif  // GOOGLE_PROTOBUF_ATOMICOPS_INTERNALS_PPC_H_

