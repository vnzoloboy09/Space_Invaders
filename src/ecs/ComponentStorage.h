#pragma once

#include "Entity.h"
#include <unordered_map>

template<typename T>
class ComponentStorage 
{
public:
	void add(Entity e, const T& component) { m_data[e] = component; }

	T& get(Entity e) { return m_data[e]; }

	bool has(Entity e) const { return m_data.find(e) != m_data.end(); }

	std::unordered_map<Entity, T>& all() { return m_data; }
	
private:
	std::unordered_map<Entity, T> m_data;
};