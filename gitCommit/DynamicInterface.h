/*
 * Simple class to test the performance of CRTP.  Compare with "StaticInterface.h".
 */
class DynamicInterface {
public:
  virtual void tick(unsigned n) = 0;
  virtual unsigned getvalue() = 0;
};

class DynamicImplementation : public DynamicInterface {
  unsigned counter;

public:
  DynamicImplementation()
    : counter(0) {
  }

  virtual void tick(unsigned n) {
    counter += n;
  }

  virtual unsigned getvalue() {
    return counter;
  }
};
