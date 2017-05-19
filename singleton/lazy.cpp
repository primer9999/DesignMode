#include<iostream>

class Lazy {
  public:
    static Lazy* getObject() {
      return lazy;
    }
  private:
    Lazy() {}
  private:
    static Lazy* lazy;
};
Lazy* Lazy::lazy = new Lazy();

int main() {
  Lazy* lazy1 = Lazy::getObject();
  Lazy* lazy2 = Lazy::getObject();
  if (lazy1 == lazy2) 
    std::cout << "ok!" << std::endl;
  delete lazy1;
  return 0;
}
