#include "engine/gameplay/Scene.hpp"

namespace engine
{
	namespace gameplay
	{
		Scene::Scene()
		{
			m_root = std::make_shared<Actor>();
		}

		std::shared_ptr<Actor> Scene::getRoot() const 
		{
			return m_root;
		}

		std::shared_ptr<Actor> Scene::getRoot() 
		{
			return m_root;
		}

		void Scene::update(F32 delta) 
		{
			if (m_root) 
			{
				m_root->update(delta);
			}
		}
	}
}