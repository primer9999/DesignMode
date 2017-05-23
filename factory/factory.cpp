#include <iostream>

class Fruit {
  public:
    Fruit() {}
    virtual ~Fruit() {}
    virtual void GetFruit()=0;
};
class NorthApple : public Fruit {
  public:
    NorthApple() {}
    ~NorthApple() {}
    virtual void GetFruit() {
      std::cout << "NorthApple" << std::endl;
    }
};
class NorthBanana : public Fruit {
  public:
    NorthBanana() {}
    ~NorthBanana() {}
    virtual void GetFruit() {
      std::cout << "NorthBanana" << std::endl;
    }
};

class SouthApple : public Fruit {
  public:
    SouthApple() {}
    ~SouthApple() {}
    virtual void GetFruit() {
      std::cout << "SouthApple" << std::endl;
    }
};
class SouthBanana : public Fruit {
  public:
    SouthBanana() {}
    ~SouthBanana() {}
    virtual void GetFruit() {
      std::cout << "SouthBanana" << std::endl;
    }
};
class Factory {
  public:
    Factory() {}
    virtual ~Factory() {}
    virtual Fruit* CreateApple()=0;
    virtual Fruit* CreateBanana()=0;
};

class NorthFactory : public Factory {
  public:
    NorthFactory() {}
    ~NorthFactory() {}
    virtual Fruit* CreateApple() {
      return new NorthApple();
    }
    virtual Fruit* CreateBanana() {
      return new NorthBanana();
    }
};

class SouthFactory : public Factory {
  public:
    SouthFactory() {}
    ~SouthFactory() {}
    virtual Fruit* CreateApple() {
      return new SouthApple();
    }
    virtual Fruit* CreateBanana() {
      return new SouthBanana();
    }
};
int main() {
  Factory* northfactory = new NorthFactory();
  Factory* southfactory = new SouthFactory();
  Fruit* northapple = northfactory->CreateApple();
  Fruit* southbanana = southfactory->CreateBanana();
  northapple->GetFruit();
  southbanana->GetFruit();
  return 0;
}
