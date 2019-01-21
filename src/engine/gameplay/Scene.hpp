#pragma once

#include "engine/gameplay/Actor.hpp"
#include "engine/Types.hpp"

namespace engine 
{
	namespace gameplay
	{
		class Scene final
		{
		public:
			Scene();

			std::shared_ptr<Actor> getRoot() const;
			std::shared_ptr<Actor> getRoot();

			void update(F32 delta);

		private:
			std::shared_ptr<Actor> m_root;
		};
	}
}
