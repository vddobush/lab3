#include <iostream>
#include <vector>
#include "need.h"

//forward iterator
template <class Iter, class Type>
bool allOf(Iter first, const Iter& last, const Type& value) {
    while (first != last) {
        if (*first == value) {
            first++;
        }
        else {
            return false;
        }
    }
    return true;
}


template <class Iter, class Type>
bool anyOf (Iter first, const Iter &last, const Type& value) {
    for (auto i = first; i <= last-2; i++) {
        if (*i == value) {
            return true;
        }
    }
    return false;
}

template <class Iter, class Type>
bool noneOf (Iter first, const Iter &last, const Type& value) {
    while (first != last) {
        if (*first != value) {
            first++;
        }
        else {
            return false;
        }
    }
    return true;
}

template <class Iter, class Type>
bool oneOf (Iter first, const Iter& last, const Type& value) {
    auto counter = 0;
    while (first != last) {
        if (*first == value) {
            counter++;
        }
        first++;
    }
    if (counter == 1) {
        return true;
    }
    else {
        return false;
    }
}

template <class Iter, class UnaryPredicate>
bool isPartitioned(Iter first, Iter last, UnaryPredicate p) {
    for (; first != last; ++first)
        if (!p(*first))
            break;
    for (; first != last; ++first)
        if (p(*first))
            return false;
    return true;
}

template <class Iter, class Predicat>
bool isSorted(Iter first, Iter last, Predicat p) {
    for (auto i = first; i < last; i++) {
        if (!p(*i, *(i + 1))) {
            return false;
        }
    }
    return true;
}

template <class Iter, class Predicate>
bool isPalindrome(Iter first, Iter last, Predicate p) {
    last--;
    while (first != last) {
        if(!p(*first, *last))
            return false;
        first++;
        if(!(first != last))
            break;
        last--;
    }
    return true;
}

template<class Iter, class Type>
Type find_not (Iter first, const Iter &last, const Type &value) {
    while (first != last) {
        if (*first != value) {
            return *first;
        }
        first++;
    }
    return -1;
}

template<class Iter, class Type>
Type findBackward (const Iter& first, Iter last, const Type &value) {
    while (last != first) {
        if (*last == value) {
            return *last;
        }
        last--;
    }
    return -1;
}

template <class Type, int N>
class Predicate {

public:
    bool operator() (const Type a) {
        return a % N == 0;
    }
};

template <class Type>
class SecondPredicate {

public:
    bool operator() (const Type a, const Type b) {
        return a == b;
    }
};

template <class Type>
class IsLess {
public:
    bool operator() (const Type a, const Type b) {
        return a < b;
    }
};

template <class Type>
class IsMore {
public:
    bool operator() (const Type a, const Type b) {
        return a > b;
    }
};


int main() {
    //AllOf
    std::vector<CPoint> v;
    CPoint point;
    point.x = 4.0;
    point.y = 5.0;
    v.push_back(point);
    point.x = 4.0;
    point.y = 5.0;
    v.push_back(point);
    point.x = 4.0;
    point.y = 5.0;
    v.push_back(point);
    std::cout << "AllOf Check:\n";
    point.x = 4.0;
    point.y = 89.991;
//    point.x = 4.0;
//    point.y = 5.0;
    std::cout << allOf(v.begin(), v.end(), point) << std::endl; //Might be 1
    std::vector<CPoint> vect;
    CPoint need;
    need.x = 1.0;
    need.y = 5.2;
    vect.push_back(need);
    need.x = 3.1;
    need.y = 3.1;
    vect.push_back(need);
    need.x = 3.1;
    need.y = 3.1;
    vect.push_back(need);
    std::cout << "Another AllOf Check:\n";
    std::cout << allOf(vect.begin(), vect.end(), need) << std::endl; //Might be 0

    //AnyOf
    std::vector<CPoint> v1;
    CPoint point1;
    point1.x = 4.0;
    point1.y = 5.0;
    v1.push_back(point1);
    point1.x = 4.0;
    point1.y = 5.0;
    v1.push_back(point1);
    point1.x = 4.0;
    point1.y = 5.0;
    v1.push_back(point1);
    std::cout << "anyOf Check:\n";
    std::cout << anyOf(v1.begin(), v1.end(), point1) << std::endl; //Might be 1
    std::vector<CPoint> v2;
    CPoint p2;
    p2.x = 1.5;
    p2.y = 2.0;
    v2.push_back(p2);
    p2.x = 3.1;
    p2.y = 5.2;
    v2.push_back(p2);
    p2.x = 4.9;
    p2.y = 7.4;
    v2.push_back(p2);
    std::cout << "Another anyOf Check:\n";
    std::cout << anyOf(v2.begin(), v2.end(), p2) << std::endl; //Might be 0

    //noneOf
    std::cout << "NoneOf Check:\n";
    p2.x = 555.32;
    p2.y = 342.2;
    std::cout << noneOf(v2.begin(), v2.end(), p2) << std::endl; //Might be 1
    std::vector<CPoint> v3;
    CPoint p3;
    p3.x = 1.5;
    p3.y = 2.0;
    v3.push_back(p3);
    p3.x = 1.5;
    p3.y = 2.0;
    v3.push_back(p3);
    p3.x = 4.1;
    p3.y = 3.8;
    v3.push_back(p3);
    std::cout << "Another NoneOf Check:\n";
    std::cout << noneOf(v3.begin(), v3.end(), p3) << std::endl; //Might be 0

    //oneOf
    std::vector<CPoint> oneOfCheck;
    CPoint p4;
    p4.x = 15.0;
    p4.y = 3.0;
    oneOfCheck.push_back(p4);
    p4.x = 15.0;
    p4.y = 3.0;
    oneOfCheck.push_back(p4);
    p4.x = 3.8;
    p4.y = 5.2;
    oneOfCheck.push_back(p4);
    std::cout << "OneOf Check:\n";
    std::cout << oneOf(oneOfCheck.begin(), oneOfCheck.end(), p4) << std::endl; //Might be 1
    p4.x = 15.0;
    p4.y = 3.0;
    std::cout << "Another OneOf Check:\n";
    std::cout << oneOf(oneOfCheck.begin(), oneOfCheck.end(), p4) << std::endl; // Might be 0

    //Sorted
    std::vector<int> vector = {1, 5, 8};
    std::cout << "is_Sorted Check:\n";
    std::cout << isSorted(vector.begin(), vector.end(), IsLess<int>()) << std::endl;
    std::cout << "Another is_Sorted Check:\n";
    std::cout << isSorted(vector.begin(), vector.end(), IsMore<int>()) << std::endl;

    //isPartitioned
    std::cout << "isPartitioned Check:\n";
    std::cout << isPartitioned(vector.begin(), vector.end(), Predicate<int, 3>()) << std::endl;
    std::cout << "Another isPartitioned Check:\n";
    std::cout << isPartitioned(vector.begin(), vector.end(), Predicate<int, 8>()) << std::endl;

    //findNot
    std::vector<int> vct = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "findNot Check:\n";
    std::cout << find_not(vct.begin(), vct.end(), 1) << std::endl;
    std::vector<int> vct2 = {2, 2, 2, 2, 2, 2};
    std::cout << "Another findNot Check:\n";
    std::cout << find_not(vct2.begin(), vct2.end(), 2) << std::endl;

    //findBackward
    std::vector<int> backw = {1, 2, 3, 4, 5, 6, 7, 8};
    std::cout << "findBackward Check:\n";
    std::cout << findBackward(backw.begin(), backw.end(), 5) << std::endl;

    //isPalindrome
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(1);
    std::cout << "isPalindrome Check:\n";
    std::cout << isPalindrome(vec.begin(), vec.end(), SecondPredicate<int>()) << std::endl;

}