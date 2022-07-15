#include "Foo.hh"
#include <type_traits>

int main() {
    Type<Integer> type_integer(ValueType::INTEGER, Integer(15));
    std::cout << type_integer.get_val().get_val() << std::endl;
    return 0;
}