#include <initializer_list>
#include <cstring>
#include <utility>
template <typename T, size_t N>
class Array {
    private:
    T data_[N];
    public:
        
    Array() = default;
    Array(std::initializer_list<T> list){
        std::move(list.begin(), list.end(), data_);
    }
    Array(Array& other) = default;
    Array(Array&& other) = default;
    ~Array() = default;

    Array& operator=(const Array& other){
        if (this != &other){
            std::copy(other.cbegin(), other.cend(), data_);
        }
        return *this;
    }

    Array& operator=(Array&& other){
        if (this != &other){
        std::move(other.begin(), other.end(), data_);
        }
        return *this;
    }

    T& operator[](size_t pos){
        return data_[pos];
    }
    const T& operator[](size_t pos)const{
        return data_[pos];
    }

    T& Front(){
        return *data_;
    }
    T& Back(){
        return *(data_ + N - 1);
    }
    const T& Front() const{
        return *data_;
    }
    const T& Back() const{
        return *(data_ + N - 1);
    }
    T* Data(){
        return data_;
    }
    const T* Data() const{
        return data_;
    }
    bool Empty(){
        return N == 0;
    }
    size_t Size()const{
        return N;
    }
    void Fill(T&& element){
        for (size_t i = 0; i < N; ++i){
            data_[i] = element;
        }
    }
    void Swap(Array& other){
        std::swap(*this, other);
    }

    T* begin(){
        return data_;
    }
    T* end(){
        return data_ + N;
    }
    const T* cbegin() const{
        return data_;
    }
    const T* cend() const{
        return data_ + N;
    }

};
//OPERATOR < > =< >= ==
template <typename T, size_t s_fst, size_t s_snd>
bool operator==(const Array<T, s_fst>& first, const Array<T, s_snd>& second){
    if (s_fst == s_snd){
        bool is_eq = true;
        for (size_t i = 0; i< s_fst; ++i){
            if (first[i] != second[i])
                is_eq = false;
        }
        return is_eq;
    }
    return false;
}
template <typename T, size_t s_fst, size_t s_snd>
bool operator!=(const Array<T, s_fst>& first, const Array<T, s_snd>& second){
    return !(first == second);
}

template <typename T, size_t s_fst, size_t s_snd>
    bool operator<(const Array<T, s_fst>& first, const Array<T, s_snd>& second){
        if (first.Size() == second.Size()){
            for (size_t i = first.Size(); i != 0; --i){
                if (first[i - 1] != second[i - 1])
                    return first[i - 1] < second[i - 1] ? true : false;
            }
            return false;
        }
        else{
            return first.Size() < second.Size() ? true : false;
        }
        
    }
    template <typename T, size_t s_fst, size_t s_snd>
    bool operator>(const Array<T, s_fst>& first, const Array<T, s_snd>& second){
        if (first.Size() == second.Size()){
            for (size_t i = first.Size(); i != 0; --i){
                if (first[i - 1] != second[i - 1])
                    return first[i - 1] > second[i - 1] ? true : false;
            }
            return false;
        }
        else{
            return first.Size() > second.Size() ? true : false;
        }
    }
    template <typename T, size_t s_fst, size_t s_snd>
    bool operator>=(const Array<T, s_fst>& first, const Array<T, s_snd>& second){
        return first > second || first == second;
    }
    template <typename T, size_t s_fst, size_t s_snd>
    bool operator<=(const Array<T, s_fst>& first, const Array<T, s_snd>& second){
        return first < second || first == second;
    }

//SWAP
template <typename T, size_t N>
void swap(Array<T, N>& first, Array<T, N>& second){
    first.Swap(second);
}
//GET
template<size_t I, typename T, size_t N>
T& get(Array<T, N>& data) noexcept{
    return data[I];
}

template<size_t I, typename T, size_t N>
const T& get (const Array<T, N>& data){
    return data[I];
}

template<size_t I, typename T, size_t N>
T&& get (Array<T, N>&& data) noexcept{
    return std::move(data[I]);
}
