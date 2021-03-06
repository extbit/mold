/**
 *  \file unescape_html.hpp
 *
 *  Copyright 2016~2019 Duzy Chan <code@extbit.io>, ExtBit Limited
 *  
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */ 
#ifndef _BOOST_MOLD_EDIT_UNESCAPE_HTML_HPP_
#define _BOOST_MOLD_EDIT_UNESCAPE_HTML_HPP_ 1
#include <mold/edit/encoder.hpp>
namespace mold { namespace edit
{
  struct unescape_html : encoder
  {
    template <typename String>
    void operator()(String &s)
    {
      encode(s, '&', "&amp;", 3);
      encode(s, '<', "&lt;", 2);
      encode(s, '>', "&gt;", 2);
      encode(s, '\r', "\\r", 1);
      encode(s, '\n', "\\n", 1);
    }
  };
}}
#endif//_BOOST_MOLD_EDIT_UNESCAPE_HTML_HPP_
