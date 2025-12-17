#pragma once
#include <cstdint>

using Entity = uint32_t;

class EntityManager
{
public:
	Entity createEntity()
	{
		return m_nextId++;
	}

private:
	static Entity m_nextId;
};