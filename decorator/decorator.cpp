#include <iostream>
//动态地将责任附加到对象上



class Component {
  public:
    Component() {}
    virtual ~Component() {}
    virtual void DoSomething() = 0;
};

class ConcreteComponentA : public Component {
  public:
    ConcreteComponentA() {}
    ~ConcreteComponentA() {}
    virtual void DoSomething() {
      std::cout << "objectA" << std::endl;
    }
};
class ConcreteComponentB : public Component {
  public:
    ConcreteComponentB() {}
    ~ConcreteComponentB() {}
    virtual void DoSomething() {
      std::cout << "objectB" << std::endl;
    }
};
class Decorator : public Component {
  public:
    Decorator() {}
    virtual ~Decorator() {}
    virtual void DoOtherthing() = 0;
};
class ConcreteDecoratorA : public Decorator {
  public:
    ConcreteDecoratorA(Component* c) {
      component = c;
    }
    ~ConcreteDecoratorA() {}
    virtual void DoSomething() {
      component->DoSomething();
    }
    virtual void DoOtherthing() {
      std::cout << "do other A thing" << std::endl;
    }
  private:
    Component* component;
};
class ConcreteDecoratorB : public Decorator {
  public:
    ConcreteDecoratorB(Component* c) {
      component = c;
    }
    ~ConcreteDecoratorB() {}
    virtual void DoSomething() {
      component->DoSomething();
    }
    virtual void DoOtherthing() {
      std::cout << " do other B thing" << std::endl;
    }
  private:
    Component* component;
};

int main() {
  Component* componentA = new ConcreteComponentA();
  Decorator* decoratorB = new ConcreteDecoratorB(componentA);
  decoratorB->DoSomething();
  decoratorB->DoOtherthing();
  delete componentA;
  delete decoratorB;
  return 0;
}
