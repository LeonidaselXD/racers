#ifndef GOLICOORDSYS_H
#define GOLICOORDSYS_H

#include "decomp.h"
#include "golworldentity.h"
#include "types.h"

// VTABLE: GOLDP 0x10056cf0
// SIZE 0x10
class GolICoordSys {
public:
	GolICoordSys();
	virtual void VTable0x00() = 0;                                      // vtable+0x00
	virtual void LocalToWorld(const GolVec3* p_src, GolVec3* p_dest) = 0; // vtable+0x04
	virtual void WorldToLocal(const GolVec3* p_src, GolVec3* p_dest) = 0; // vtable+0x08
	virtual void LocalToWorldOrient(const GolVec3* p_src, GolVec3* p_dest) = 0; // vtable+0x0c
	virtual void WorldToLocalOrient(const GolVec3* p_src, GolVec3* p_dest) = 0; // vtable+0x10
	virtual void GetOrientation(GolQuat* p_orientation) = 0;                   // vtable+0x14
	virtual void GetBasis(GolVec3* p_forward, GolVec3* p_up, GolVec3* p_right) = 0;  // vtable+0x18
	virtual void GetYZAxis(GolVec3* p_forward, GolVec3* p_up) = 0; // vtable+0x1c
	virtual void GetXZAxis(GolVec3* p_right, GolVec3* p_forward) = 0; // vtable+0x20
	virtual void YZOrthoNormalize(GolVec3* p_forward, GolVec3* p_up) = 0; // vtable+0x24
	virtual void XZOrthoNormalize(GolVec3* p_right, GolVec3* p_forward) = 0; // vtable+0x28
	virtual void SetOrientation(GolQuat* p_orientation) = 0;                   // vtable+0x2c
	virtual void GetRight(GolVec3* p_right) = 0;                               // vtable+0x30
	virtual void GetUp(GolVec3* p_up) = 0;                     // vtable+0x34
	virtual void GetForward(GolVec3* p_forward) = 0;                         // vtable+0x38
	virtual LegoFloat DistanceSqrTo(GolVec3* p_position) = 0;               // vtable+0x3c
	virtual void GetPosition(GolVec3* p_position) = 0;                   // vtable+0x40
	virtual void SetPosition(GolVec3* p_position) = 0;                   // vtable+0x44
	virtual void CopyFrom(GolICoordSys* p_source) = 0;             // vtable+0x48

	void SetChild(GolICoordSys* p_child);

	GolICoordSys* m_parent; // 0x04
	GolICoordSys* m_prev; // 0x08
	GolICoordSys* m_next; // 0x0c
};

#endif // GOLICOORDSYS_H
