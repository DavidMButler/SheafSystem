
//
// Copyright (c) 2014 Limit Point Systems, Inc. 
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/// @file
/// Implementation for class e4.

#ifndef E4_IMPL_H
#define E4_IMPL_H

#ifndef SHEAF_DLL_SPEC_H
#include "sheaf_dll_spec.h"
#endif

#ifndef E4_H
#include "e4.h"
#endif

namespace fiber_bundle
{

//==============================================================================
// CLASS E4_ROW_DOFS_TYPE
//==============================================================================

template <typename T>
const std::string&
e4_row_dofs_type<T>::
static_class_name()
{
  // Preconditions:

  // Body:

  static const std::string result("e4_row_dofs_type");

  // Postconditions:

  ensure(!result.empty());

  // Exit:

  return result;
}

template <typename T>
int
e4_row_dofs_type<T>::
d()
{
  // Preconditions:

  // Body:

  int result = 4;

  // Postconditions:

  ensure(result == 4);

  // Exit:

  return result;
}

template <typename T>
T&
e4_row_dofs_type<T>::
operator[] (int xindex)
{
  // Preconditions:

  require(xindex>=0 && xindex<d());

  // Body:

  T& result = components[xindex];

  // Postconditions:

  //ensure(result == components[xindex]);

  // Exit:

  return result;
}

template <typename T>
const T&
e4_row_dofs_type<T>::
operator[] (int xindex) const
{
  // Preconditions:

  require(xindex>=0 && xindex<d());

  // Body:

  const T& result = components[xindex];

  // Postconditions:

  //ensure(result == components[xindex]);

  // Exit:

  return result;
}

template <typename T>
e4_row_dofs_type<T>* 
e4_row_dofs_type<T>::clone() const
{
  // Preconditions:

  // Body:

  e4_row_dofs_type<T>* result = new e4_row_dofs_type<T>();

  // Postconditions:

  ensure(result != 0);

  // Exit:

  return result;
}

//==============================================================================
// NON-MEMBER FUNCTIONS
//==============================================================================

#ifndef DOXYGEN_SKIP_IMPLEMENTATIONS
template <typename T>
std::ostream& operator<<(std::ostream& xos, const e4_row_dofs_type<T>& xrdt)
{
  int ld = xrdt.d();
  for(int i=0; i<ld; ++i)
  {
    xos << " " << xrdt.components[i];
  }

  return xos;
}
#endif // ifndef DOXYGEN_SKIP_IMPLEMENTATIONS
 
} // namespace fiber_bundle

#endif // ifndef E4_IMPL_H
