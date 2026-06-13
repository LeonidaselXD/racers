#include "golicoordsys.h"

DECOMP_SIZE_ASSERT(GolICoordSys, 0x10)

// FUNCTION: GOLDP 0x1001ce90
GolICoordSys::GolICoordSys()
{
	m_parent = NULL;
	m_prev = 0;
	m_next = 0;
}

// FUNCTION: GOLDP 0x1001ceb0
void GolICoordSys::SetChild(GolICoordSys* p_child)
{
	if (p_child->m_parent != this) {
		p_child->m_parent = this;
		p_child->m_prev = m_next;
		m_next = p_child;
	}
}
