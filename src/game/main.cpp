#include <iostream>

#include <engine/gameplay/Applicaion.hpp>
#include <engine/component/Component.hpp>
#include <engine/gameplay/Actor.hpp>

class MyComponent
: public engine::component::Component
{
	using Parent = engine::component::Component;

public:
    MyComponent(std::weak_ptr<engine::gameplay::Actor> owner, int value)
    : Parent(owner)
	, m_value(value)
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
: public engine::component::Component
{
	using Parent = engine::component::Component;

public:
	MyWrongComponent(std::weak_ptr<engine::gameplay::Actor> owner)
		: Parent(owner)
	{

	}

    GENERATE_COMPONENT_METADATA(MyWrongComponent)
};

class Foo
{
    
};

int main(int _argc, char** _argv)
{
    auto actor = std::make_shared<engine::gameplay::Actor>();
    actor->addComponent<MyComponent>(700);
    
    auto component = actor->getComponent<MyComponent>();
    component->foo();
    
    auto wrong = actor->getComponent<MyWrongComponent>();
    
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
