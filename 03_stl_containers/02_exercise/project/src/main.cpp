#include <iostream>

#include <set>
#include <unordered_set>

int main() {

//    struct Foo {
//        int a;
//        int b;
//    };
//
//    struct FooLess {
//        bool operator()(const Foo& lhs, const Foo& rhs) const {
//            return lhs.a < rhs.a;
//        }
//    };
//
//    std::set<Foo, FooLess> set{};
//
//    set.insert(Foo{1, 2});
//    set.insert(Foo{1, 2});
//
//    std::cout << set.size() << std::endl;
//
//    set.insert(Foo{2, 3});
//    set.insert(Foo{2, 3});
//
//    std::cout << set.size() << std::endl;
//
//    set.insert(Foo{1, 3});
//    set.insert(Foo{1, 3});
//
//    std::cout << set.size() << std::endl;
//
//    struct FooHash {
//        std::size_t operator()(const Foo& foo) const {
//            std::hash<int> hash{};
//            return hash(foo.a);
//        }
//    };
//
//    struct FooEqual {
//        bool operator()(const Foo& lhs, const Foo& rhs) const {
//            return lhs.a == rhs.a;
//        }
//    };
//
//    std::unordered_set<Foo, FooHash, FooEqual> unordered_set{};
//
//    unordered_set.insert(Foo{1, 2});
//    unordered_set.insert(Foo{1, 2});
//
//    std::cout << unordered_set.size() << std::endl;
//
//    unordered_set.insert(Foo{2, 3});
//    unordered_set.insert(Foo{2, 3});
//
//    std::cout << unordered_set.size() << std::endl;
//
//    unordered_set.insert(Foo{1, 3});
//    unordered_set.insert(Foo{1, 3});
//
//    std::cout << unordered_set.size() << std::endl;

    std::unordered_set<int> unorderedSet;
    unorderedSet.insert(1);
    std::cout<<"size: "<<unorderedSet.size()<<std::endl;
    std::cout<<"buckets: "<<unorderedSet.bucket_count()<<std::endl;
    std::cout<<"load factor: "<<unorderedSet.load_factor()<<std::endl;
    std::cout<<"max_load_factor: "<<unorderedSet.max_load_factor()<<std::endl;
}