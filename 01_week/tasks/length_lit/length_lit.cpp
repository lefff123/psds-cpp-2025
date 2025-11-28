constexpr long double operator""_m_to_cm(long double value){
    return value *100.;
};
constexpr long double operator""_cm_to_m(long double value){
    return value * 0.01;
};

constexpr long double operator""_m_to_ft(long double value) {
    return value *3.28084;
};

constexpr long double operator""_m_to_in(long double value) {
    return value *39.3701;
};
constexpr long double operator""_in_to_m(long double value) {
    return value*0.0254;
};
constexpr long double operator""_ft_to_m(long double value) {
    return value *0.3048;
};
constexpr long double operator""_ft_to_in(long double value) {
    return value *12.;
};

constexpr long double operator""_in_to_ft(long double value) {
    return value /12.;
};

constexpr long double operator""_cm_to_ft(long double value) {
    return value *0.0328084;
};

constexpr long double operator""_cm_to_in(long double value) {
    return value *0.393701;
};
constexpr long double operator""_in_to_cm(long double value) {
    return value* 2.54;
};
constexpr long double operator""_ft_to_cm(long double value) {
    return value *30.48;
};
