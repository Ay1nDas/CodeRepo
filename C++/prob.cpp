class car {
public:
  virtual void speed() = 0;
};

class bike: public car {
};

class truck: public car {
  void speed() override {
    
  }
};