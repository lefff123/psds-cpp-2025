#include <memory>

template <class T, class... Args>
std::unique_ptr<T> MakeUnique(Args&& ...args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}
