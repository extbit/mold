/**
 *  \file value.hpp
 *
 *  Copyright 2016~2019 Duzy Chan <code@extbit.io>, ExtBit Limited
 *  
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */ 
#ifndef _BOOST_MOLD_VALUE_HPP_
#define _BOOST_MOLD_VALUE_HPP_ 1
# include <boost/spirit/home/x3/support/ast/variant.hpp>
# include <string>
# include <vector>
# include <unordered_map>
namespace mold
{

  //template <typename Type>
  //using forward = boost::spirit::x3::forward_ast<Type>;

  //template <typename ...Types>
  //using variant = boost::spirit::x3::variant<Types...>;
  
  struct value;

  using nil = std::monostate;
  using string = std::string;
  using array = std::vector<value>;
  using object = std::unordered_map<string,value>;

  struct value : boost::spirit::x3::variant<nil, string, object, array>
  {
    value() : base_type() {}
#if false&&0
    template<typename T> value(T&& t) : base_type(std::move(t)) {}
#endif
    template<typename T> value(const T& t) : base_type(t) {}

    // Explicitly define non-move operator= to avoid "T&&" alternative.
    template<typename T>
    value& operator=(const T& t)
    {
      base_type::operator=(t);
      return *this;
    }
  };

} // namespace mold

#endif//_BOOST_MOLD_VALUE_HPP_
