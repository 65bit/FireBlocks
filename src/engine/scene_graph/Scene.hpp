#pragma once

#include "engine/scene_graph/Actor.hpp"
#include "engine/Types.hpp"

namespace engine {

class Scene final {
public:
    Scene() = default;
    ~Scene() = default;

    void setRoot(std::shared_ptr<Actor> root) {
        m_root = root;
    }

    std::shared_ptr<Actor> getRoot() const {
        return m_root;
    }

    std::shared_ptr<Actor> getRoot() {
        return m_root;
    }

    void update(F32 delta) {
        if (m_root) {
            m_root->update(delta);
        }
    }

    void setCamera() {}

private:
    std::shared_ptr<Actor> m_root;
};
}
