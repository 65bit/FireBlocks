#pragma once

#include <map>
#include <memory>
#include <vector>

#include "engine/component/Component.hpp"

namespace engine 
{
	namespace gameplay
	{
		class Actor
			: public std::enable_shared_from_this<Actor>
		{
		public:
			using ComponentPtr = std::shared_ptr<component::Component>;
			using Components = std::map<component::Component::Id, ComponentPtr>;
			using Childs = std::vector<std::shared_ptr<Actor>>;

		public:
			virtual ~Actor() = default;

			virtual bool init() { return true; }
			virtual void deinit() {}
			virtual void update(F32 delta);

			void addChild(std::shared_ptr<Actor> actor);
			void removeChild(std::shared_ptr<Actor> actor);

			const Childs& getChilds() const;

			template<typename T, typename... Args>
			void addComponent(Args&&... args)
			{
				const auto id = T::ComponentIdStatic();

				if (m_components.count(id))
				{
					return;
				}

				m_components[id] = std::make_shared<T>(shared_from_this(), std::forward<Args>(args)...);
			}

			template<typename T>
			std::shared_ptr<T> getComponent()
			{
				const auto id = T::ComponentIdStatic();

				if (!m_components.count(id))
				{
					return nullptr;
				}

				auto component = m_components.at(id);

				if (component->componentId() != id)
				{
					return nullptr;
				}

				return std::static_pointer_cast<T>(component);
			}

		private:
			Components m_components;
			Childs m_children;
		};
	}
}
