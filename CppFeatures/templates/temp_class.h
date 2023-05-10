template <typename T> class Accum {
private:
  T _state;

public:
  Accum(T initializer) : _state(initializer) {}

  T operator+=(T add) { return _state = _state + add; }

  T getState(){
    return _state;
  }
};