#include <iostream>

#include <engine/gameplay/Applicaion.hpp>
#include <engine/Component.hpp>
#include <engine/scene_graph/Actor.hpp>

class MyComponent
: public engine::Component
{
public:
    MyComponent(int value)
    : m_value(value)
    {
        
    }
    
    GENERATE_COMPONENT_METADATA(MyComponent)
    
    void foo()
    {
        std::cout << m_value;
    }
    
private:
    const int m_value;
};

class MyWrongComponent
: public engine::Component
{
public:
    GENERATE_COMPONENT_METADATA(MyWrongComponent)
};

class Foo
{
    
};

int main(int _argc, char** _argv)
{
    engine::Actor actor;
    actor.addComponent<MyComponent>(700);
    
    auto component = actor.getComponent<MyComponent>();
    component->foo();
    
    auto wrong = actor.getComponent<MyWrongComponent>();
    
    // This line will not compile because Foo is not a component
    //actor.getComponent<Foo>();
    
    if(!wrong)
    {
        std::cout << "Component doesn't exist" << std::endl;
    }
    
    engine::gameplay::Application application;
    application.run();

    return 0;
}
