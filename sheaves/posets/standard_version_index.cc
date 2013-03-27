// $RCSfile: standard_version_index.cc,v $ $Revision: 1.7 $ $Date: 2013/01/12 17:17:43 $

//
// Copyright (c) 2013 Limit Point Systems, Inc.
//

// Definitions for standard_version_index facet of namespace sheaf.


#include "standard_version_index.h"

#include "assert_contract.h"
#include "std_string.h"

namespace
{
const int STANDARD_VERSION_INDEX_CT =
  sheaf::STANDARD_VERSION_INDEX_END - sheaf::STANDARD_VERSION_INDEX_BEGIN;
}

///
sheaf::standard_version_index&
sheaf::
operator++(standard_version_index& x)
{
  return x =
           (x == STANDARD_VERSION_INDEX_END) ?
           STANDARD_VERSION_INDEX_BEGIN :
           standard_version_index(x+1);
};

///
const string&
sheaf::
standard_version_index_to_name(standard_version_index xpt)
{
  // Preconditions:

  // Body:

  static const string names[STANDARD_VERSION_INDEX_CT+1] =
    {
      "CURRENT_MEMBER_VERSION",
      "CURRENT_HOST_VERSION",
      "COARSEST_COMMON_REFINEMENT_VERSION",
      "NOT_A_STANDARD_VERSION_INDEX" // Must be one more than last std id.
    };

  const string* lresult_ptr = &names[STANDARD_VERSION_INDEX_CT];

  pod_index_type lpt = xpt;
  if(is_standard_version_index(lpt))
  {
    lresult_ptr = &names[lpt - STANDARD_VERSION_INDEX_BEGIN];
  }

  const string& result = *lresult_ptr;

  // Postconditions:

  ensure(!result.empty());

  // Exit:

  return result;
}

///
sheaf::standard_version_index
sheaf::
standard_version_index_from_name(const string& xname)
{
  standard_version_index result = NOT_A_STANDARD_VERSION_INDEX;
  for(standard_version_index i=STANDARD_VERSION_INDEX_BEGIN;
      i< STANDARD_VERSION_INDEX_END;
      ++i)
  {
    if(standard_version_index_to_name(i) == xname)
    {
      result = i;
      break;
    }
  }

  return result;
}

///
sheaf::standard_version_index
sheaf::
standard_version_index_from_index(pod_index_type xindex)
{
  // Preconditions:

  // Body:

  static const standard_version_index ids[STANDARD_VERSION_INDEX_CT+1] =
    {
      CURRENT_MEMBER_VERSION,
      CURRENT_HOST_VERSION,
      COARSEST_COMMON_REFINEMENT_VERSION,
      NOT_A_STANDARD_VERSION_INDEX
    };

  standard_version_index result = ids[STANDARD_VERSION_INDEX_CT];
  if(is_standard_version_index(xindex))
  {
    result = ids[xindex - STANDARD_VERSION_INDEX_BEGIN];
  }

  // Postconditions:

  // Exit:

  return result;
}

///
bool
sheaf::
is_standard_version_index(pod_index_type xindex)
{
  bool result;

  // Preconditions:

  // Body:

  result =
    (STANDARD_VERSION_INDEX_BEGIN <= xindex) && (xindex < STANDARD_VERSION_INDEX_END);

  // Postconditions:

  // Exit

  return result;
}

