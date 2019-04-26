/*
 * Benchmark file to test the performance of CRTP
 */
#include "StaticInterface.h"

template <typename Implementation>
void run_crtp(CRTPInterface<Implementation>* obj,unsigned N) {
  for (unsigned i = 0; i < N; ++i) {
    for (unsigned j = 0; j < i; ++j) {
      obj->tick(j);
    }
  }
}

int main() {

	unsigned N = 100000;
	CRTPImplementation* crtp_obj = new CRTPImplementation();
	run_crtp(crtp_obj,N);

}
