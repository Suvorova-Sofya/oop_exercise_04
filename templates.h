#ifndef D_TEMPLATES_H_
#define D_TEMPLATES_H_ 1

#include <tuple>
#include <type_traits>

#include "five_angles.h"
#include "six_angles.h"
#include "eight_angles.h"
#include "point.h"

template<class T>
struct is_point : std::false_type {};

template<class T>
struct is_point<point<T>> : std::true_type {};

template<class T>
struct is_figurelike_tuple : std::false_type {};

template<class Head, class... Tail>
struct is_figurelike_tuple<std::tuple<Head, Tail...>> :
    std::conjunction<is_point<Head>,
      std::is_same<Head, Tail>...> {};

template<class Type, size_t SIZE>
struct is_figurelike_tuple<std::array<Type, SIZE>> :
    is_point<Type> {};

template<class T>
inline constexpr bool is_figurelike_tuple_v =
  is_figurelike_tuple<T>::value;

template<class T, class = void>
struct has_print_method : std::false_type {};

template<class T>
struct has_print_method<T,
  std::void_t<decltype(std::declval<const T>().print())>> :
    std::true_type {};

template<class T>
inline constexpr bool has_print_method_v =
  has_print_method<T>::value;

template<class T>
std::enable_if_t<has_print_method_v<T>, void>
    print(const T& figure) {
        figure.print();
}

template<size_t ID, class T>
void single_print(const T& t) {
    std::cout << std::get<ID>(t);
    return ;
}

template<size_t ID, class T>
void recursive_print(const T& t) {
    if constexpr (ID < std::tuple_size_v<T>){
        single_print<ID>(t);
        recursive_print<ID+1>(t);
        return ;
    }else{
        return ;
    }
}

template<class T>
std::enable_if_t<is_figurelike_tuple_v<T>, void>
    print(const T& fake) {
    return recursive_print<0>(fake);
}

//center

template<class T, class = void>
struct has_center_method : std::false_type {};

template<class T>
struct has_center_method<T,
        std::void_t<decltype(std::declval<const T>().center())>> :
        std::true_type {};

template<class T>
inline constexpr bool has_center_method_v =
        has_center_method<T>::value;

template<class T>
std::enable_if_t<has_center_method_v<T>, point<double>>
center(const T& figure) {
    return figure.center();
}

template<class T>
inline constexpr const int tuple_size_v =
        std::tuple_size<T>::value;

template<size_t ID, class T>
point<double> single_center(const T& t) {
    point<double> p;
    p=std::get<ID>(t);
    p/=tuple_size_v<T>;
    return p;
}

template<size_t ID, class T>
point<double> recursive_center(const T& t) {
    if constexpr (ID < std::tuple_size_v<T>){
        return  single_center<ID>(t) + recursive_center<ID+1>(t);
    }else{
        point<double> p;
        p=p.point_1(0,0);
        return p;
    }
}

template<class T>
std::enable_if_t<is_figurelike_tuple_v<T>, point<double>>
center(const T& fake) {
    return recursive_center<0>(fake);
}

//square

template<class T, class = void>
struct has_square_method : std::false_type {};

template<class T>
struct has_square_method<T,
        std::void_t<decltype(std::declval<const T>().square())>> :
        std::true_type {};

template<class T>
inline constexpr bool has_square_method_v =
        has_square_method<T>::value;

template<class T>
std::enable_if_t<has_square_method_v<T>, double>
square(const T& figure) {
    return figure.square();
}

template<size_t ID, class T>
double single_square(const T& t) {
    const auto& a = std::get<0>(t);
    const auto& b = std::get<ID - 1>(t);
    const auto& c = std::get<ID>(t);
    const double dx1 = b.x - a.x;
    const double dy1 = b.y - a.y;
    const double dx2 = c.x - a.x;
    const double dy2 = c.y - a.y;
    return std::abs(dx1 * dy2 - dy1 * dx2) * 0.5;
}

template<size_t ID, class T>
double recursive_square(const T& t) {
    if constexpr (ID < std::tuple_size_v<T>){
        return single_square<ID>(t) + recursive_square<ID + 1>(t);
    }else{
        return 0;
    }
}

template<class T>
std::enable_if_t<is_figurelike_tuple_v<T>, double>
square(const T& fake) {
    return recursive_square<2>(fake);
}

#endif // D_TEMPLATES_H_
