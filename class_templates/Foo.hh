#include <iostream>
#include <type_traits>

class Values {
public:
    virtual ~Values() {}
};

class Integer : public Values {
public:
    Integer(int val) 
    : val(val) {}

    int get_val() const {
        return val;
    }

    void set_val(int val) {
        this->val = val;
    }

    ~Integer() {}
private:
    int val;
};

class Float : public Values {
public:
    float get_val() const {
        return val;
    }

    void set_val(float val) {
        this->val = val;
    }

    ~Float() {}
private:
    float val;
};

enum class ValueType {INTEGER, STRING, FLOAT, CHAR, VOID};

template <typename T>
class Type {
public:
    // Type(ValueType type, typename std::enable_if<std::is_base_of<Values, T>::value, T>::type  val)
    Type(ValueType type,T  val)
    : type_name(type), val(val) {}

    T get_val() {
        return val;
    }

    ValueType get_type_name() {
        return type_name;
    }

    void set_type_name(ValueType type_name) {
        this->type_name = type_name;
    }

private:
    ValueType type_name;
    typename std::enable_if<std::is_base_of<Values, T>::value, T>::type val;
};

