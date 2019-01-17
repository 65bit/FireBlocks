#include "engine/renderer/rendererBase/Renderer.hpp"

namespace engine
{
	namespace render
	{
		class OpenglRenderer : public Renderer
		{
		public:
			OpenglRenderer() {}
			virtual ~OpenglRenderer() {}
		};
	}
}