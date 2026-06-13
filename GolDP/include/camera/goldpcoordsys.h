#ifndef GOLDPCOORDSYS_H
#define GOLDPCOORDSYS_H

#include "compat.h"
#include "golicoordsys.h"
#include "types.h"

// VTABLE: GOLDP 0x1005622c
// SIZE 0xd0
class GolDPCoordSys : public GolICoordSys {
public:
	GolDPCoordSys();
	void VTable0x00() override;                                      // vtable+0x00
	void LocalToWorld(const GolVec3* p_src, GolVec3* p_dest) override; // vtable+0x04
	void WorldToLocal(const GolVec3* p_src, GolVec3* p_dest) override; // vtable+0x08
	void LocalToWorldOrient(const GolVec3* p_src, GolVec3* p_dest) override; // vtable+0x0c
	void WorldToLocalOrient(const GolVec3* p_src, GolVec3* p_dest) override; // vtable+0x10
	void GetOrientation(GolQuat* p_rotation) override;                   // vtable+0x14
	void GetBasis(GolVec3* p_forward, GolVec3* p_up, GolVec3* p_right) override;  // vtable+0x18
	void GetYZAxis(GolVec3* p_forward, GolVec3* p_up) override; // vtable+0x1c
	void GetXZAxis(GolVec3* p_right, GolVec3* p_forward) override; // vtable+0x20
	void YZOrthoNormalize(GolVec3* p_forward, GolVec3* p_up) override; // vtable+0x24
	void XZOrthoNormalize(GolVec3* p_right, GolVec3* p_forward) override; // vtable+0x28
	void SetOrientation(GolQuat* p_orientation) override;                   // vtable+0x2c
	void GetRight(GolVec3* p_right) override;                               // vtable+0x30
	void GetUp(GolVec3* p_up) override;                     // vtable+0x34
	void GetForward(GolVec3* p_forward) override;                         // vtable+0x38
	LegoFloat DistanceSqrTo(GolVec3* p_position) override;               // vtable+0x3c
	void GetPosition(GolVec3* p_position) override;                   // vtable+0x40
	void SetPosition(GolVec3* p_position) override;                   // vtable+0x44
	void CopyFrom(GolICoordSys* p_source) override;             // vtable+0x48

	GolMatrix4 m_localTransform; // 0x10
	// GolVec3 m_right;        // 0x10
	// LegoFloat m_unk0x1c; // 0x1c
	// GolVec3 m_up;   // 0x20
	// LegoFloat m_unk0x2c; // 0x2c
	// GolVec3 m_forward;     // 0x30
	// LegoFloat m_unk0x3c; // 0x3c
	// GolVec3 m_position;  // 0x40
	// LegoFloat m_unk0x4c; // 0x4c
	GolMatrix4 m_unk0x50; // 0x50
	GolMatrix4 m_unk0x90; // 0x90
};

#endif // GOLDPCOORDSYS_H
