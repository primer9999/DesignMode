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
  Lazy* lazy = Lazy::getObject();
  if (lazy) 
    std::cout << "ok!" << std::endl;
  delete lazy;
  return 0;
}
