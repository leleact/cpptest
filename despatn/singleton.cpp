#include "singleton.h"

static Singleton::Singleton sm_instance;

shared_ptr<Singleton> Singleton::Getinstance() {
  return make_shared(&sm_instance);
}
