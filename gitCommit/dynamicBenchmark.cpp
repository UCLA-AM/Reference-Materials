/*
 * Benchmark file to test performance of CRTP.
 */
#include "DynamicInterface.h"

void run_dynamic(DynamicInterface* obj,unsigned N) {
  for (unsigned i = 0; i < N; ++i) {
    for (unsigned j = 0; j < i; ++j) {
      obj->tick(j);
    }
  }
}

int main() {

	unsigned N = 100000;
	DynamicImplementation* dynamic_obj = new DynamicImplementation();
	run_dynamic(dynamic_obj,N);

}
