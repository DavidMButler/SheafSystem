// $RCSfile: triorder_iterator.cc,v $ $Revision: 1.17 $ $Date: 2013/01/12 17:17:39 $

//
// Copyright (c) 2013 Limit Point Systems, Inc.
//

// Implementation for class triorder_iterator

#include "triorder_iterator.h"
#include "assert_contract.h"

sheaf::triorder_iterator::
triorder_iterator()
    : filtered_depth_first_iterator()
{

  // Preconditions:

  // Body:

  initialize_order(TRIORDER);

  // Postconditions:

  ensure(invariant());
  ensure(!is_initialized());

  // Exit

  return;
}

sheaf::triorder_iterator::
triorder_iterator(const triorder_iterator& xother)
    : filtered_depth_first_iterator(xother)
{

  // Preconditions:

  // Body:

  // Postconditions:

  ensure(invariant());

  // Exit

  return;
}

sheaf::triorder_iterator::
~triorder_iterator()
{
  // Preconditions:

  // Body:

  // Postconditions:

}






bool
sheaf::triorder_iterator::
is_ancestor_of(const any* xother) const
{
  bool result;

  // Preconditions:

  // Body:

  result = dynamic_cast<const triorder_iterator*>(xother) != 0;

  // Postconditions:

  // Exit

  return result;
}

sheaf::triorder_iterator*
sheaf::triorder_iterator::
clone() const
{
  triorder_iterator* result;

  // Preconditions:

  // Body:

  result = new triorder_iterator;

  // Postconditions:

  ensure(result != 0);
  ensure(is_same_type(result));
  ensure(!result->is_initialized());

  // Exit

  return result;
}

bool
sheaf::triorder_iterator::
invariant() const
{
  bool result = true;

  // Preconditions:

  // Body:

  invariance(filtered_depth_first_iterator::invariant());
  invariance(order()==TRIORDER);

  // Postconditions:

  // Exit

  return result;
}

// OTHER CONSTRUCTORS


sheaf::triorder_iterator::
triorder_iterator(const abstract_poset_member& xanchor,
                  bool xdown,
                  bool xstrict)
    : filtered_depth_first_iterator(xanchor, xdown, xstrict, TRIORDER)
{

  // Preconditions:

  // Body:

  // Postconditions:

  ensure(invariant());

  // Exit:

  return;
}

sheaf::triorder_iterator::
triorder_iterator(const abstract_poset_member& xanchor,
                  const subposet& xfilter,
                  bool xdown,
                  bool xstrict)
    : filtered_depth_first_iterator(xanchor, xfilter, xdown, xstrict, TRIORDER)
{

  // Preconditions:

  // Body:

  // Postconditions:

  ensure(invariant());

  // Exit:

  return;
}

sheaf::triorder_iterator::
triorder_iterator(const abstract_poset_member& xanchor,
                  pod_index_type xfilter_index,
                  bool xdown,
                  bool xstrict)
    : filtered_depth_first_iterator(xanchor, xfilter_index, xdown, xstrict, TRIORDER)
{

  // Preconditions:

  // Body:

  // Postconditions:

  ensure(invariant());

  // Exit:

  return;
}

sheaf::triorder_iterator::
triorder_iterator(const abstract_poset_member& xanchor,
                  const scoped_index& xfilter_index,
                  bool xdown,
                  bool xstrict)
    : filtered_depth_first_iterator(xanchor, xfilter_index, xdown, xstrict, TRIORDER)
{

  // Preconditions:

  // Body:

  // Postconditions:

  ensure(invariant());

  // Exit:

  return;
}

sheaf::triorder_iterator::
triorder_iterator(const abstract_poset_member& xanchor,
                  const string& xfilter_name,
                  bool xdown,
                  bool xstrict)
    : filtered_depth_first_iterator(xanchor, xfilter_name, xdown, xstrict, TRIORDER)
{

  // Preconditions:

  // Body:

  // Postconditions:

  ensure(invariant());

  // Exit:

  return;
}
