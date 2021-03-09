#include <vector>
#include <string>
#include <memory>

struct pqueue {
    // Можете изменить следующую строку
    using handle = size_t*;

    auto insert(int priority, std::string const& name) -> handle;
    auto erase(handle it) -> void;
    auto update_priority(handle const& it, int new_priority) -> void;
    auto extract_min() -> std::string;
    auto get(handle const& it) const -> std::string const&;
    auto get_priority(handle const& it) const -> int;
    auto size() const -> size_t;

    // Можете изменить последующие строки
    struct heap_element {
        int priority;
        std::unique_ptr<size_t> iter;
        std::string payload;
    };
    std::vector<heap_element> heap; // Куча, в которой хранятся строки и итераторы
};
