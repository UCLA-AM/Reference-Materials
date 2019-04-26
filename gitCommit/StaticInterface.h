/*
 * Simple class to test performance of CRTP.  Compare with "DynamicInterface.h".
 */
template <typename Implementation>
class CRTPInterface {
public:
  void tick(unsigned n) {
    impl().tick(n);
  }

  unsigned getvalue() {
    return impl().getvalue();
  }
private:
  Implementation& impl() {
    return *static_cast<Implementation*>(this);
  }
};

class CRTPImplementation : public CRTPInterface<CRTPImplementation> {
public:
  CRTPImplementation()
    : counter(0) {
  }

  void tick(unsigned n) {
    counter += n;
  }

  unsigned getvalue() {
    return counter;
  }
private:
  unsigned counter;
};
