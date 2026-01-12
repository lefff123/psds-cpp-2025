constexpr long double operator""_m_to_cm(long double value){
    return value *100.00L;
};
constexpr long double operator""_cm_to_m(long double value){
    return value * 0.01L;
};

constexpr long double operator""_m_to_ft(long double value) {
    return value *3.280839895013123L;
};

constexpr long double operator""_m_to_in(long double value) {
    return value *39.37007874015748031496062992L;
};
constexpr long double operator""_in_to_m(long double value) {
    return value*0.0254L;
};
constexpr long double operator""_ft_to_m(long double value) {
    return value *0.3048L;
};
constexpr long double operator""_ft_to_in(long double value) {
    return value *12.0L;
};

constexpr long double operator""_in_to_ft(long double value) {
    return value /12.0L;
};

constexpr long double operator""_cm_to_ft(long double value) {
    return value *0.03280839895013123359580052493L;
};

constexpr long double operator""_cm_to_in(long double value) {
    return value *0.39370078740157480314L;
};
constexpr long double operator""_in_to_cm(long double value) {
    return value* 2.54L;
};
constexpr long double operator""_ft_to_cm(long double value) {
    return value *30.48L;
};
