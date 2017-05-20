#include<iostream>

class Product {
  public:
    void setFloor(int par) {
      floorpar = par;  
    }
    void setDoor(int par) {
      doorpar = par; 
    }
    void setWall(int par) {
      wallpar = par;
    }
    void show() {
    std::cout << "floorparameter:" << floorpar << "\n" 
      << "doorparameter:" << doorpar << "\n" 
      << "wallparameter:" << wallpar << std::endl;
    }
  private:
    int floorpar;
    int doorpar;
    int wallpar;
};

class AbstractBuilder {
  public:
    virtual void createProduct() = 0;
    virtual void createFloor(int para)= 0;
    virtual void createDoor(int para) = 0;
    virtual void createWall(int para) = 0;
    virtual Product* getProduct()= 0;
};
class Builder : public AbstractBuilder {
  public:
    void createProduct() {
      product = new Product();
    }
    void createFloor(int para) {
      product->setFloor(para);
      std::cout << "build floor" << std::endl;
    }
    void createDoor(int para) {
      product->setDoor(para);
      std::cout << "build door" << std::endl; 
    }
    void createWall(int para) {
      product->setWall(para);
      std::cout << "build wall" << std::endl;
    }
    Product* getProduct() {
      return product;
    }
  private:
    Product* product;
};

class Director {
  public:
    Director(AbstractBuilder* build) {
      builder = build;
    }
    void construct() {
      if (!builder)
         return ;
      builder->createProduct();
      builder->createWall(1);
      builder->createFloor(2);
      builder->createDoor(3);
    }
  private:
    AbstractBuilder *builder;
};

int main() {
  AbstractBuilder *builder = new Builder();
  Director* director = new Director(builder);
  director->construct();
  Product* product = builder->getProduct();
  product->show();
  delete builder;
  delete director;
  delete product;
  return 0;
}
