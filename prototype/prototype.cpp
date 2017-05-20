#include <iostream>
#include <string.h>

class ProtoType {
  public:
    virtual ProtoType* clone() = 0;
    virtual void print() = 0;
    virtual ~ProtoType() {}
};
class ConcretePrototype : public ProtoType {
  public:
    ConcretePrototype(int value,char* str) {
      this->value = value;
      this->str = new char[strlen(str)+1];
      strcpy(this->str,str);
    }
    ~ConcretePrototype() {
      if (str != NULL)
        delete[] str;
    }
    ProtoType* clone() {
      return  new ConcretePrototype(*this);
    }
    void print() {
      std::cout << value << " " << str << std::endl;
    }
  private:
    ConcretePrototype(const ConcretePrototype &pt) {
      this->value = pt.value;
      this->str = new char[strlen(pt.str)+1];
      strcpy(this->str,pt.str);
    }
  private:
    int value;
    char* str;
};
int main() {
  ProtoType* pt = new ConcretePrototype(2,"prototype");
  pt->print();
  ProtoType* pt2 = pt->clone();
  pt2->print();
  delete pt;
  delete pt2;
  return 0;
}
