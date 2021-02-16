#include <gtest/gtest.h>

#include <set>
#include <map>
#include <unordered_set>
#include <string.h>

TEST(SetString, RemoveElements) {

    std::set<std::string> set = {"A", "B", "C"};
    ASSERT_EQ(3u, set.size());
    EXPECT_EQ(1u, set.count("A"));
    EXPECT_EQ(1u, set.count("B"));
    EXPECT_EQ(1u, set.count("C"));

    set.erase("B");
    ASSERT_EQ(2u, set.size());
    EXPECT_EQ(1u, set.count("A"));
    EXPECT_EQ(0u, set.count("B"));
    EXPECT_EQ(1u, set.count("C"));
}

TEST(SetFloat, ElementsSortedWhenIterating) {

    std::set<float> set;
    ASSERT_TRUE(set.empty());
    set.insert(3.2);

    ASSERT_EQ(1u, set.size());
    EXPECT_EQ(1u, set.count(3.2f));

    set.insert(4.1);
    set.insert(1.1);

    ASSERT_EQ(3u, set.size());
    EXPECT_EQ(1u, set.count(3.2f));
    EXPECT_EQ(1u, set.count(4.1f));
    EXPECT_EQ(1u, set.count(1.1f));

    set.insert(0.3);
    auto iter = set.begin();
    EXPECT_FLOAT_EQ(0.3f, *iter++);
    EXPECT_FLOAT_EQ(1.1f, *iter++);
    EXPECT_FLOAT_EQ(3.2f, *iter++);
    EXPECT_FLOAT_EQ(4.1f, *iter++);
    EXPECT_EQ(set.end(), iter);
}

TEST(SetInt, ElementsSortedInDecreasingOrderWhenIterating) {


    struct Comparator {
        bool operator()(const int& lhs, const int& rhs) const {
            return lhs > rhs;
        }
    };

    std::set<int, Comparator> set {};
    set.insert(1);
    set.insert(2);
    set.insert(3);
    auto iter = set.begin();
    EXPECT_EQ(3, *iter++);
    EXPECT_EQ(2, *iter++);
    EXPECT_EQ(1, *iter++);
    EXPECT_EQ(set.end(), iter);

    set.insert(4);
    iter = set.begin();
    EXPECT_EQ(4, *iter++);
    EXPECT_EQ(3, *iter++);
    EXPECT_EQ(2, *iter++);
    EXPECT_EQ(1, *iter++);
    EXPECT_EQ(set.end(), iter);
}

TEST(SetChar, InvalidComparatorThatCausesOnlyOneElementToBeInserted) {

    struct Comparator {
        bool operator()(const char &lhs, const char &rhs) const {
            return lhs == rhs;
        }
    };

    std::set<char, Comparator> set{};
    ASSERT_TRUE(set.empty());

    set.insert('a');
    ASSERT_EQ(1u, set.size());

    set.insert('b');
    ASSERT_EQ(1u, set.size());
}

TEST(SetChar, InvalidComparatorThatCausesMultipleCopiesOfTheSameElementToBeInserted) {

    struct Comparator {
        bool operator()(const char &lhs, const char &rhs) const {
            return lhs == rhs;
        }
    };

    std::set<char, Comparator> set{};

    ASSERT_TRUE(set.empty());

    set.insert('a');

    ASSERT_EQ(1u, set.size());

    set.insert('a');

    ASSERT_EQ(2u, set.size());
}

TEST(SetValue, CustomTypeAndComparator) {

    struct Value {
        int a;
        int b;
    };

    struct Comparator {
        bool operator()(const Value &lhs, const Value &rhs) const {
            if (lhs.a == rhs.a)
                return lhs.b < rhs.b;
            else
                return lhs.a < rhs.a;
        }
    };

    std::set<Value, Comparator> set{};
    ASSERT_TRUE(set.empty());

    set.insert(Value{1, 0});

    ASSERT_EQ(1u, set.size());
    EXPECT_EQ(1u, set.count(Value{1, 0}));

    set.insert(Value{2, 0});

    ASSERT_EQ(2u, set.size());
    EXPECT_EQ(1u, set.count(Value{1, 0}));
    EXPECT_EQ(1u, set.count(Value{2, 0}));

    set.insert(Value{1, 1});

    ASSERT_EQ(3u, set.size());
    EXPECT_EQ(1u, set.count(Value{1, 0}));
    EXPECT_EQ(1u, set.count(Value{2, 0}));
    EXPECT_EQ(1u, set.count(Value{1, 1}));

    set.insert(Value{2, 2});

    ASSERT_EQ(4u, set.size());
    EXPECT_EQ(1u, set.count(Value{1, 0}));
    EXPECT_EQ(1u, set.count(Value{2, 0}));
    EXPECT_EQ(1u, set.count(Value{1, 1}));
    EXPECT_EQ(1u, set.count(Value{2, 2}));
}

TEST(SetInt, ElementsNotLessThanGivenValue) {

    std::set<int> set;
    set.insert(1);
    set.insert(2);
    set.insert(3);
    set.insert(4);
    set.insert(5);

    ASSERT_EQ(5u, set.size());
    EXPECT_EQ(1u, set.count(1));
    EXPECT_EQ(1u, set.count(2));
    EXPECT_EQ(1u, set.count(3));
    EXPECT_EQ(1u, set.count(4));
    EXPECT_EQ(1u, set.count(5));

    auto iter = set.upper_bound(2);

    EXPECT_EQ(3, *iter++);
    EXPECT_EQ(4, *iter++);
    EXPECT_EQ(5, *iter++);
    EXPECT_EQ(set.end(), iter);
}

TEST(MapStringString, CreateUsingInitializerList) {

    std::map<std::string, std::string> map;
    map.insert({"PL", "Poland"});
    map.insert({"JP", "Japan"});
    map.insert({"DE", "Germany"});

    ASSERT_EQ(3u, map.size());
    EXPECT_EQ("Poland", map["PL"]);
    EXPECT_EQ("Japan", map["JP"]);
    EXPECT_EQ("Germany", map["DE"]);
}

TEST(MapSetString, NestedCollections) {

    std::map<std::string, std::set<std::string>> map;
    ASSERT_TRUE(map.empty());

    map["digits"].insert("1");
    ASSERT_EQ(1u, map.size());
    ASSERT_EQ(1u, map.count("digits"));

    map["digits"].insert("2");
    map["digits"].insert("3");
    map["digits"].insert("4");
    ASSERT_EQ(4u, map["digits"].size());
    EXPECT_EQ(1u, map["digits"].count("1"));
    EXPECT_EQ(1u, map["digits"].count("2"));
    EXPECT_EQ(1u, map["digits"].count("3"));
    EXPECT_EQ(1u, map["digits"].count("4"));
}

TEST(MultimapIntInt, RemoveRangeOfElements) {

    std::multimap<int, int> multimap = {{1, 2}, {2, 1}, {2, 2}, {2, 3}, {2, 4},
                                        {3, 1}, {3, 2}, {3, 3}};

    ASSERT_EQ(8, multimap.size());
    EXPECT_EQ(1, multimap.count(1));
    EXPECT_EQ(4, multimap.count(2));
    EXPECT_EQ(3, multimap.count(3));

    multimap.erase(2);

    ASSERT_EQ(4, multimap.size());
    EXPECT_EQ(1, multimap.count(1));
    EXPECT_EQ(3, multimap.count(3));
}

TEST(UnorderedSetValue, CustomTypeHashAndComparator) {

    struct Value {
        int a;
        int b;
    };

    struct Hash {
        std::size_t operator()(const Value& v) const {
            std::hash<int> hash{};
            return hash(v.a + v.b);
        }
    };

    struct Equal {
        bool operator()(const Value& lhs, const Value& rhs) const {
            return lhs.a == rhs.a;
        }
    };

    std::unordered_set<Value, Hash, Equal> unordered_set;
    ASSERT_TRUE(unordered_set.empty());

    unordered_set.insert(Value{1, 1});

    ASSERT_EQ(1u, unordered_set.size());
    EXPECT_EQ(1u, unordered_set.count(Value{1, 1}));

    ASSERT_EQ(1u, unordered_set.size());
    EXPECT_EQ(1u, unordered_set.count(Value{1, 1}));

    unordered_set.insert(Value{1, 2});
    unordered_set.insert(Value{2, 1});
    unordered_set.insert(Value{2, 2});


    ASSERT_EQ(4u, unordered_set.size());
    EXPECT_EQ(1u, unordered_set.count(Value{1, 1}));
    EXPECT_EQ(1u, unordered_set.count(Value{1, 2}));
    EXPECT_EQ(1u, unordered_set.count(Value{2, 1}));
    EXPECT_EQ(1u, unordered_set.count(Value{2, 2}));
}

TEST(UnorderedSetInt, BucketsAndLoadFactor) {

    std::unordered_set<int> unordered_set = {1};

    ASSERT_EQ(1u, unordered_set.size());
    EXPECT_EQ(2u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(1.0 / 2.0, unordered_set.load_factor());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.max_load_factor());

    unordered_set.insert(2);
    ASSERT_EQ(2u, unordered_set.size());
    EXPECT_EQ(2u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.load_factor());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.max_load_factor());

    unordered_set.insert(3);
    ASSERT_EQ(3u, unordered_set.size());
    EXPECT_EQ(5u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(3.0 / 5.0, unordered_set.load_factor());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.max_load_factor());

    unordered_set.insert(4);
    ASSERT_EQ(4u, unordered_set.size());
    EXPECT_EQ(5u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(4.0 / 5.0, unordered_set.load_factor());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.max_load_factor());

    unordered_set.insert(5);
    ASSERT_EQ(5u, unordered_set.size());
    EXPECT_EQ(5u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.load_factor());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.max_load_factor());

    unordered_set.insert(6);
    unordered_set.insert(7);
    unordered_set.insert(8);
    unordered_set.insert(9);
    unordered_set.insert(10);
    ASSERT_EQ(10u, unordered_set.size());
    EXPECT_EQ(11u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(10.0 / 11.0, unordered_set.load_factor());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.max_load_factor());


    unordered_set.insert(11);
    ASSERT_EQ(11u, unordered_set.size());
    EXPECT_EQ(11u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(11.0 / 11.0, unordered_set.load_factor());
}
