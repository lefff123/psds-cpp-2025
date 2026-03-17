#include <string>

class UniquePtr
{
    friend void Swap(UniquePtr& ptr1, UniquePtr& ptr2);
private:
    std::string* data_;

public:
    UniquePtr() : data_(nullptr) {}
    UniquePtr(std::string& init) : data_(&init){}
    UniquePtr(std::string* init) : data_(init){}
    UniquePtr(const UniquePtr& init) = delete;
    UniquePtr(UniquePtr&& init) : data_(init.data_){
        init.data_ = nullptr;
    }
    ~UniquePtr(){
        delete data_;
    }
    UniquePtr& operator=(UniquePtr& other) = delete;
    UniquePtr& operator=(UniquePtr&& other){
        if (!other.data_ || other.data_ == data_)
            return *this;
        delete data_;
        data_ = other.data_;
        other.data_ = nullptr;
        return *this;
    }
    explicit operator bool() const {
        return data_ != nullptr;
    }
    bool operator!()const{
        return data_ == nullptr;
    }
    std::string* operator->(){
        return data_;
    }
    std::string& operator*(){
        return *data_;
    }
    char& operator[](int pos){
        return data_->operator[](pos);
    }
    std::string* Get()const{
        return data_;
    }
    std::string* Release(){
        std::string* temp = data_;
        data_ = nullptr;
        return temp;
    }
    void Reset(std::string* new_ptr = nullptr){
        delete data_;
        data_ = new_ptr;
    }
    void Swap(UniquePtr& other){
        std::string* temp = other.data_;
        other.data_ = this->data_;
        this->data_ = temp;
    }
};

UniquePtr MakeUnique(const std::string& data)
{
    auto temp = new std::string();
    temp->reserve(data.size());
    temp->insert(temp->begin(), data.begin(), data.end());
    return UniquePtr(temp);
}
UniquePtr MakeUnique(std::string&& data)
{
    auto temp = new std::string();
    *temp = std::move(data);
    data.clear();
    return UniquePtr(temp);
}
void Swap(UniquePtr& ptr1, UniquePtr& ptr2){
        std::string* temp = ptr1.data_;
        ptr1.data_ = ptr2.data_;
        ptr2.data_ = temp;
}