#include "camera/goldpcoordsys.h"

#include "camera/jadeorbit0x220.h"

DECOMP_SIZE_ASSERT(GolDPCoordSys, 0xd0)
DECOMP_SIZE_ASSERT(JadeOrbit0x220, 0x220)

// FUNCTION: GOLDP 0x10002890
GolDPCoordSys::GolDPCoordSys()
{
	m_unk0x50.m_m[0][0] = 1.0f;
	m_unk0x50.m_m[0][1] = 0.0f;
	m_unk0x50.m_m[0][2] = 0.0f;
	m_unk0x50.m_m[0][3] = 0.0f;
	m_unk0x50.m_m[1][0] = 0.0f;
	m_unk0x50.m_m[1][1] = 1.0f;
	m_unk0x50.m_m[1][2] = 0.0f;
	m_unk0x50.m_m[1][3] = 0.0f;
	m_unk0x50.m_m[2][0] = 0.0f;
	m_unk0x50.m_m[2][1] = 0.0f;
	m_unk0x50.m_m[2][2] = 1.0f;
	m_unk0x50.m_m[2][3] = 0.0f;
	m_unk0x50.m_m[3][0] = 0.0f;
	m_unk0x50.m_m[3][1] = 0.0f;
	m_unk0x50.m_m[3][2] = 0.0f;
	m_unk0x50.m_m[3][3] = 1.0f;
	m_unk0x90.m_m[0][1] = 0.0f;
	m_unk0x90.m_m[0][2] = 0.0f;
	m_unk0x90.m_m[0][3] = 0.0f;
	m_unk0x90.m_m[1][0] = 0.0f;
	m_unk0x90.m_m[1][2] = 0.0f;
	m_unk0x90.m_m[1][3] = 0.0f;
	m_unk0x90.m_m[2][0] = 0.0f;
	m_unk0x90.m_m[2][1] = 0.0f;
	m_unk0x90.m_m[2][3] = 0.0f;
	m_unk0x90.m_m[3][0] = 0.0f;
	m_unk0x90.m_m[3][1] = 0.0f;
	m_unk0x90.m_m[3][2] = 0.0f;
	m_localTransform.m_m[0][1] = 0.0f;
	m_localTransform.m_m[0][2] = 0.0f;
	m_localTransform.m_m[0][3] = 0.0f;
	m_localTransform.m_m[1][0] = 0.0f;
	m_localTransform.m_m[1][2] = 0.0f;
	m_localTransform.m_m[1][3] = 0.0f;
	m_localTransform.m_m[2][0] = 0.0f;
	m_localTransform.m_m[2][1] = 0.0f;
	m_localTransform.m_m[2][3] = 0.0f;
	m_localTransform.m_m[3][0] = 0.0f;
	m_localTransform.m_m[3][1] = 0.0f;
	m_localTransform.m_m[3][2] = 0.0f;
	m_unk0x90.m_m[0][0] = 1.0f;
	m_unk0x90.m_m[1][1] = 1.0f;
	m_unk0x90.m_m[2][2] = 1.0f;
	m_unk0x90.m_m[3][3] = 1.0f;
	m_localTransform.m_m[0][0] = 1.0f;
	m_localTransform.m_m[1][1] = 1.0f;
	m_localTransform.m_m[2][2] = 1.0f;
	m_localTransform.m_m[3][3] = 1.0f;
}

// FUNCTION: GOLDP 0x10002980
void GolDPCoordSys::GetBasis(GolVec3* p_forward, GolVec3* p_up, GolVec3* p_right)
{
	p_right->m_x = m_localTransform.m_m[0][0];
	p_right->m_y = m_localTransform.m_m[0][1];
	p_right->m_z = m_localTransform.m_m[0][2];
	p_up->m_x = m_localTransform.m_m[1][0];
	p_up->m_y = m_localTransform.m_m[1][1];
	p_up->m_z = m_localTransform.m_m[1][2];
	p_forward->m_x = m_localTransform.m_m[2][0];
	p_forward->m_y = m_localTransform.m_m[2][1];
	p_forward->m_z = m_localTransform.m_m[2][2];
}

// FUNCTION: GOLDP 0x100029d0
void GolDPCoordSys::GetYZAxis(GolVec3* p_forward, GolVec3* p_up)
{
	p_up->m_x = m_localTransform.m_m[1][0];
	p_up->m_y = m_localTransform.m_m[1][1];
	p_up->m_z = m_localTransform.m_m[1][2];
	p_forward->m_x = m_localTransform.m_m[2][0];
	p_forward->m_y = m_localTransform.m_m[2][1];
	p_forward->m_z = m_localTransform.m_m[2][2];
}

// FUNCTION: GOLDP 0x10002a00
void GolDPCoordSys::GetXZAxis(GolVec3* p_right, GolVec3* p_forward)
{
	p_right->m_x = m_localTransform.m_m[0][0];
	p_right->m_y = m_localTransform.m_m[0][1];
	p_right->m_z = m_localTransform.m_m[0][2];
	p_forward->m_x = m_localTransform.m_m[2][0];
	p_forward->m_y = m_localTransform.m_m[2][1];
	p_forward->m_z = m_localTransform.m_m[2][2];
}

// FUNCTION: GOLDP 0x10002a30
void GolDPCoordSys::YZOrthoNormalize(GolVec3* p_forward, GolVec3* p_up)
{
	GolVec3 forward;
	GolMath::NormalizeVector3(*p_forward, &forward);

	LegoFloat dot = p_up->m_y;
	dot *= forward.m_y;
	dot += forward.m_z * p_up->m_z;
	dot += forward.m_x * p_up->m_x;

	GolVec3 up;
	up.m_x = p_up->m_x - (forward.m_x * dot);
	up.m_y = p_up->m_y - (forward.m_y * dot);
	up.m_z = p_up->m_z - (forward.m_z * dot);
	GolMath::NormalizeVector3(up, &up);

	GolVec3 right;
	right.m_x = forward.m_z;
	right.m_x *= up.m_y;
	right.m_x -= up.m_z * forward.m_y;
	right.m_y = up.m_z * forward.m_x;
	LegoFloat rightZForwardX = forward.m_z;
	rightZForwardX *= up.m_x;
	right.m_y -= rightZForwardX;
	right.m_z = forward.m_y;
	right.m_z *= up.m_x;
	right.m_z -= up.m_y * forward.m_x;

	// TODO: This is behaviorally complete, but the final member-store schedule
	// remains 92.65% in reccmp.
	m_localTransform.m_m[0][0] = right.m_x;
	m_localTransform.m_m[0][1] = right.m_y;
	m_localTransform.m_m[0][2] = right.m_z;
	m_localTransform.m_m[1][0] = up.m_x;
	m_localTransform.m_m[1][1] = up.m_y;
	m_localTransform.m_m[1][2] = up.m_z;
	m_localTransform.m_m[2][0] = forward.m_x;
	m_localTransform.m_m[2][1] = forward.m_y;
	m_localTransform.m_m[2][2] = forward.m_z;
}

// FUNCTION: GOLDP 0x10002b20
void GolDPCoordSys::XZOrthoNormalize(GolVec3* p_right, GolVec3* p_forward)
{
	GolVec3 right;
	GolMath::NormalizeVector3(*p_right, &right);

	LegoFloat dot = p_forward->m_y;
	dot *= right.m_y;
	dot += right.m_z * p_forward->m_z;
	dot += right.m_x * p_forward->m_x;

	GolVec3 forward;
	forward.m_x = p_forward->m_x - (right.m_x * dot);
	forward.m_y = p_forward->m_y - (right.m_y * dot);
	forward.m_z = p_forward->m_z - (right.m_z * dot);
	GolMath::NormalizeVector3(forward, &forward);

	GolVec3 up;
	up.m_x = right.m_z;
	up.m_x *= forward.m_y;
	up.m_x -= forward.m_z * right.m_y;
	up.m_y = forward.m_z * right.m_x;
	LegoFloat upZRightX = right.m_z;
	upZRightX *= forward.m_x;
	up.m_y -= upZRightX;
	up.m_z = right.m_y;
	up.m_z *= forward.m_x;
	up.m_z -= forward.m_y * right.m_x;

	m_localTransform.m_m[0][0] = right.m_x;
	m_localTransform.m_m[0][1] = right.m_y;
	m_localTransform.m_m[0][2] = right.m_z;
	m_localTransform.m_m[1][0] = up.m_x;
	m_localTransform.m_m[1][1] = up.m_y;
	m_localTransform.m_m[1][2] = up.m_z;
	m_localTransform.m_m[2][0] = forward.m_x;
	m_localTransform.m_m[2][1] = forward.m_y;
	m_localTransform.m_m[2][2] = forward.m_z;
}

// FUNCTION: GOLDP 0x10002c10
void GolDPCoordSys::LocalToWorld(const GolVec3* p_src, GolVec3* p_dest)
{
	p_dest->m_x = m_localTransform.m_m[0][0] * p_src->m_x;
	p_dest->m_y = m_localTransform.m_m[0][1] * p_src->m_x;
	p_dest->m_z = m_localTransform.m_m[0][2] * p_src->m_x;

	p_dest->m_x += m_localTransform.m_m[1][0] * p_src->m_y;
	p_dest->m_y += m_localTransform.m_m[1][1] * p_src->m_y;
	p_dest->m_z += m_localTransform.m_m[1][2] * p_src->m_y;

	p_dest->m_x += m_localTransform.m_m[2][0] * p_src->m_z;
	p_dest->m_y += m_localTransform.m_m[2][1] * p_src->m_z;
	p_dest->m_z += m_localTransform.m_m[2][2] * p_src->m_z;

	p_dest->m_x += m_localTransform.m_m[3][0];
	p_dest->m_y += m_localTransform.m_m[3][1];
	p_dest->m_z += m_localTransform.m_m[3][2];
}

// FUNCTION: GOLDP 0x10002c90
void GolDPCoordSys::LocalToWorldOrient(const GolVec3* p_src, GolVec3* p_dest)
{
	p_dest->m_x = m_localTransform.m_m[0][0] * p_src->m_x;
	p_dest->m_y = m_localTransform.m_m[0][1] * p_src->m_x;
	p_dest->m_z = m_localTransform.m_m[0][2] * p_src->m_x;

	p_dest->m_x += m_localTransform.m_m[1][0] * p_src->m_y;
	p_dest->m_y += m_localTransform.m_m[1][1] * p_src->m_y;
	p_dest->m_z += m_localTransform.m_m[1][2] * p_src->m_y;

	p_dest->m_x += m_localTransform.m_m[2][0] * p_src->m_z;
	p_dest->m_y += m_localTransform.m_m[2][1] * p_src->m_z;
	p_dest->m_z += m_localTransform.m_m[2][2] * p_src->m_z;
}

// FUNCTION: GOLDP 0x10002d00
void GolDPCoordSys::WorldToLocal(const GolVec3* p_src, GolVec3* p_dest)
{
	LegoFloat product = m_localTransform.m_m[0][0];
	product *= p_src->m_x;
	p_dest->m_x = product;
	p_dest->m_y = m_localTransform.m_m[1][0] * p_src->m_x;
	product = m_localTransform.m_m[2][0];
	product *= p_src->m_x;
	p_dest->m_z = product;

	p_dest->m_x = (p_src->m_y * m_localTransform.m_m[0][1]) + p_dest->m_x;
	p_dest->m_y = (p_src->m_y * m_localTransform.m_m[1][1]) + p_dest->m_y;
	product = m_localTransform.m_m[2][1];
	product *= p_src->m_y;
	p_dest->m_z = product + p_dest->m_z;

	p_dest->m_x = (p_src->m_z * m_localTransform.m_m[0][2]) + p_dest->m_x;
	p_dest->m_y = (p_src->m_z * m_localTransform.m_m[1][2]) + p_dest->m_y;
	product = m_localTransform.m_m[2][2];
	product *= p_src->m_z;
	p_dest->m_z = product + p_dest->m_z;

	LegoFloat offset = m_localTransform.m_m[3][0] * m_localTransform.m_m[0][0];
	product = m_localTransform.m_m[0][1];
	product *= m_localTransform.m_m[3][1];
	offset += product;
	offset += m_localTransform.m_m[3][2] * m_localTransform.m_m[0][2];
	p_dest->m_x -= offset;

	offset = m_localTransform.m_m[3][2] * m_localTransform.m_m[1][2];
	product = m_localTransform.m_m[1][1];
	product *= m_localTransform.m_m[3][1];
	offset += product;
	product = m_localTransform.m_m[3][0];
	product *= m_localTransform.m_m[1][0];
	offset += product;
	p_dest->m_y -= offset;

	offset = m_localTransform.m_m[2][2];
	offset *= m_localTransform.m_m[3][2];
	product = m_localTransform.m_m[2][1];
	product *= m_localTransform.m_m[3][1];
	offset += product;
	product = m_localTransform.m_m[3][0];
	product *= m_localTransform.m_m[2][0];
	offset += product;
	p_dest->m_z -= offset;
}

// FUNCTION: GOLDP 0x10002dc0
void GolDPCoordSys::WorldToLocalOrient(const GolVec3* p_src, GolVec3* p_dest)
{
	p_dest->m_x = m_localTransform.m_m[0][0] * p_src->m_x;
	p_dest->m_y = m_localTransform.m_m[1][0] * p_src->m_x;
	p_dest->m_z = m_localTransform.m_m[2][0] * p_src->m_x;

	p_dest->m_x += m_localTransform.m_m[0][1] * p_src->m_y;
	p_dest->m_y += m_localTransform.m_m[1][1] * p_src->m_y;
	p_dest->m_z += m_localTransform.m_m[2][1] * p_src->m_y;

	p_dest->m_x += m_localTransform.m_m[0][2] * p_src->m_z;
	p_dest->m_y += m_localTransform.m_m[1][2] * p_src->m_z;
	p_dest->m_z += m_localTransform.m_m[2][2] * p_src->m_z;
}

// FUNCTION: GOLDP 0x10002e30
void GolDPCoordSys::SetOrientation(GolQuat* p_orientation)
{
	LegoFloat scale = 2.0f / ((p_orientation->m_x * p_orientation->m_x) +
							  (p_orientation->m_y * p_orientation->m_y) +
							  (p_orientation->m_z * p_orientation->m_z) +
							  (p_orientation->m_w * p_orientation->m_w));
	LegoFloat v0 = scale * p_orientation->m_x;
	LegoFloat v1 = p_orientation->m_y;
	v1 *= scale;
	LegoFloat v2 = scale * p_orientation->m_z;
	LegoFloat v3 = p_orientation->m_w;
	v3 *= v0;
	LegoFloat v4 = p_orientation->m_w;
	v4 *= v1;
	LegoFloat v5 = p_orientation->m_w;
	v5 *= v2;
	LegoFloat v6 = v0 * p_orientation->m_x;
	LegoFloat v7 = v1 * p_orientation->m_x;
	LegoFloat v8 = v2 * p_orientation->m_x;
	LegoFloat v9 = p_orientation->m_y;
	v9 *= v1;
	LegoFloat v10 = p_orientation->m_y;
	v10 *= v2;
	LegoFloat v11 = v2 * p_orientation->m_z;

	m_localTransform.m_m[0][0] = 1.0f - (v11 + v9);
	m_localTransform.m_m[0][1] = v7 - v5;
	m_localTransform.m_m[0][2] = v8 + v4;
	m_localTransform.m_m[1][0] = v7 + v5;
	m_localTransform.m_m[1][1] = 1.0f - (v11 + v6);
	m_localTransform.m_m[1][2] = v10 - v3;
	m_localTransform.m_m[2][0] = v8 - v4;
	m_localTransform.m_m[2][1] = v10 + v3;
	m_localTransform.m_m[2][2] = 1.0f - (v9 + v6);
}

// FUNCTION: GOLDP 0x10002f50
void GolDPCoordSys::GetRight(GolVec3* p_up)
{
	p_up->m_x = m_localTransform.m_m[0][0];
	p_up->m_y = m_localTransform.m_m[0][1];
	p_up->m_z = m_localTransform.m_m[0][2];
}

// FUNCTION: GOLDP 0x10002f70
void GolDPCoordSys::GetUp(GolVec3* p_forward)
{
	p_forward->m_x = m_localTransform.m_m[1][0];
	p_forward->m_y = m_localTransform.m_m[1][1];
	p_forward->m_z = m_localTransform.m_m[1][2];
}

// FUNCTION: GOLDP 0x10002f90
void GolDPCoordSys::GetForward(GolVec3* p_right)
{
	p_right->m_x = m_localTransform.m_m[2][0];
	p_right->m_y = m_localTransform.m_m[2][1];
	p_right->m_z = m_localTransform.m_m[2][2];
}

// FUNCTION: GOLDP 0x10002fb0
LegoFloat GolDPCoordSys::DistanceSqrTo(GolVec3* p_position)
{
	LegoFloat x = m_localTransform.m_m[3][0] - p_position->m_x;
	LegoFloat y = m_localTransform.m_m[3][1] - p_position->m_y;
	LegoFloat z = m_localTransform.m_m[3][2] - p_position->m_z;

	return (x * x) + (y * y) + (z * z);
}

// FUNCTION: GOLDP 0x10002fe0
void GolDPCoordSys::GetPosition(GolVec3* p_position)
{
	p_position->m_x = m_localTransform.m_m[3][0];
	p_position->m_y = m_localTransform.m_m[3][1];
	p_position->m_z = m_localTransform.m_m[3][2];
}

// FUNCTION: GOLDP 0x10003000
void GolDPCoordSys::SetPosition(GolVec3* p_position)
{
	m_localTransform.m_m[3][0] = p_position->m_x;
	m_localTransform.m_m[3][1] = p_position->m_y;
	m_localTransform.m_m[3][2] = p_position->m_z;
}

// FUNCTION: GOLDP 0x10003020
void GolDPCoordSys::GetOrientation(GolQuat* p_rotation)
{
	GolMatrix34 basis;
	basis.m_m[0][0] = m_localTransform.m_m[0][0];
	basis.m_m[0][1] = m_localTransform.m_m[0][1];
	basis.m_m[0][2] = m_localTransform.m_m[0][2];
	basis.m_m[1][0] = m_localTransform.m_m[1][0];
	basis.m_m[1][1] = m_localTransform.m_m[1][1];
	basis.m_m[1][2] = m_localTransform.m_m[1][2];
	basis.m_m[2][0] = m_localTransform.m_m[2][0];
	basis.m_m[2][1] = m_localTransform.m_m[2][1];
	basis.m_m[2][2] = m_localTransform.m_m[2][2];

	GolMath::FUN_1002f5a0(basis, p_rotation);
}

// FUNCTION: GOLDP 0x10003080
void GolDPCoordSys::CopyFrom(GolICoordSys* p_source)
{
	GolDPCoordSys* source = static_cast<GolDPCoordSys*>(p_source);
	m_localTransform.m_m[0][0] = source->m_localTransform.m_m[0][0];
	m_localTransform.m_m[0][1] = source->m_localTransform.m_m[0][1];
	m_localTransform.m_m[0][2] = source->m_localTransform.m_m[0][2];
	m_localTransform.m_m[1][0] = source->m_localTransform.m_m[1][0];
	m_localTransform.m_m[1][1] = source->m_localTransform.m_m[1][1];
	m_localTransform.m_m[1][2] = source->m_localTransform.m_m[1][2];
	m_localTransform.m_m[2][0] = source->m_localTransform.m_m[2][0];
	m_localTransform.m_m[2][1] = source->m_localTransform.m_m[2][1];
	m_localTransform.m_m[2][2] = source->m_localTransform.m_m[2][2];
	m_localTransform.m_m[3][0] = source->m_localTransform.m_m[3][0];
	m_localTransform.m_m[3][1] = source->m_localTransform.m_m[3][1];
	m_localTransform.m_m[3][2] = source->m_localTransform.m_m[3][2];
}

// FUNCTION: GOLDP 0x10029920 FOLDED
void GolDPCoordSys::VTable0x00()
{
	// empty
}
