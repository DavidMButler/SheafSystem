
// $RCSfile: at0.impl.h,v $ $Revision: 1.9 $ $Date: 2013/01/12 17:17:00 $

//
// Copyright (c) 2013 Limit Point Systems, Inc.
//

/// @file
/// Implementation for at0 facet function templates.

#ifndef AT0_IMPL_H
#define AT0_IMPL_H

#ifndef SHEAF_DLL_SPEC_H
#include "sheaf_dll_spec.h"
#endif

#ifndef AT0_H
#include "at0.h"
#endif

namespace fiber_bundle
{

//==============================================================================
// CLASS AT0_ROW_DOFS_TYPE
//==============================================================================

template <typename T>
const string&
at0_row_dofs_type<T>::
static_class_name()
{
  // Preconditions:

  // Body:

  static const string result("at0_row_dofs_type");

  // Postconditions:

  ensure(!result.empty());

  // Exit:

  return result;
}

template <typename T>
int
at0_row_dofs_type<T>::
d()
{
  // Preconditions:

  // Body:

  int result = 1;

  // Postconditions:

  ensure(result == 1);

  // Exit:

  return result;
}

template <typename T>
T&
at0_row_dofs_type<T>::
operator[] (int xindex)
{
  // Preconditions:

  require(xindex>=0 && xindex<d());

  // Body:

  T& result = components[xindex];

  // Postconditions:

  // Exit:

  return result;
}

template <typename T>
const T&
at0_row_dofs_type<T>::
operator[] (int xindex) const
{
  // Preconditions:

  require(xindex>=0 && xindex<d());

  // Body:

  const T& result = components[xindex];

  // Postconditions:

  // Exit:

  return result;
}

template <typename T>
T&
at0_row_dofs_type<T>::
component()
{
  // Preconditions:

  // Body:

  T& result = components[0];

  // Postconditions:

  // Exit:

  return result;

}

template <typename T>
const T&
at0_row_dofs_type<T>::
component() const
{
  // Preconditions:

  // Body:

  T& result = const_cast<T&>(components[0]);

  // Postconditions:

  // Exit:

  return result;

}

template <typename T>
void
at0_row_dofs_type<T>::
put_component(const T& xcomp)
{
  // Preconditions:

  // Body:

  components[0] = xcomp;

  // Postconditions:

  // Exit:

}

template <typename T>
at0_row_dofs_type<T>* 
at0_row_dofs_type<T>::clone() const
{
  // Preconditions:

  // Body:

  at0_row_dofs_type<T>* result = new at0_row_dofs_type<T>();

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
ostream& operator<<(ostream& xos, const at0_row_dofs_type<T>& xrdt)
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

#endif // ifndef AT0_IMPL_H
