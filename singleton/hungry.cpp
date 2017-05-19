#include<iostream>
#include<mutex>
#include<thread>

class Hungry {
  public:
    static Hungry* getObject() {
      if (hungry == NULL) {
        lock.lock();
        if (hungry == NULL) {
          hungry = new Hungry();
        }
        lock.unlock();
      }
      return hungry;
    }
  private:
    Hungry() {}
  private:
    static Hungry* hungry;
    static std::mutex lock;
};
Hungry* Hungry::hungry = NULL;
std::mutex Hungry::lock;


int main() {
  Hungry* hungry1 = Hungry::getObject();
  Hungry* hungry2 = Hungry::getObject();
  if (hungry1 == hungry2) 
    std::cout << "ok" << std::endl;
  else std::cout << "no" << std::endl;
  delete hungry1;
  return 0;
}
