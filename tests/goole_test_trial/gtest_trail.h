#include "gtest/gtest.h"

namespace v1 {
class base {
    public:
        bool operator==(const base& ) const { return true;}
};

}
