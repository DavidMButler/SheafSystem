
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
/// Implementation for class edge_centered_refiner_family


#include "ComLimitPoint/fields/edge_centered_refiner_family.h"

#include "ComLimitPoint/sheaf/assert_contract.h"
#include "ComLimitPoint/fields/barycentric_quad_refiner.h"
#include "ComLimitPoint/fields/barycentric_triangle_refiner.h"
#include "ComLimitPoint/fiber_bundle/base_space_member.h"
#include "ComLimitPoint/fiber_bundle/base_space_poset.h"
#include "ComLimitPoint/sheaf/block.impl.h"
#include "ComLimitPoint/fields/edge_centered_triangle_refiner.h"
#include "ComLimitPoint/sheaf/factory.impl.h"
#include "ComLimitPoint/fiber_bundle/fiber_bundle_namespace.h"
#include "ComLimitPoint/sheaf/poset.h"
#include "ComLimitPoint/fields/zone_centered_segment_refiner.h"

using namespace std;
using namespace fields; // Workaround for MS C++ bug.

// ===========================================================
// EDGE_CENTERED_REFINER_FAMILY FACET
// ===========================================================

// PUBLIC MEMBER FUNCTIONS

fields::edge_centered_refiner_family::
edge_centered_refiner_family(const base_space_poset& xbase_space,
                             const field_refinement_policy& xpolicy)
{
  // Preconditions:

  require(xbase_space.state_is_read_accessible());

  // Body:

  initialize(xbase_space, xpolicy);

  // Postconditions:

  ensure(invariant());
  ensure(postcondition_of(initialize(xbase_space, xpolicy)));

  // Exit:

  return;
}

fields::edge_centered_refiner_family::
edge_centered_refiner_family(const edge_centered_refiner_family& xother)
    : field_refiner_family(xother)
{

  // Preconditions:

  // Body:

  // Nothing to do; base class does it all.

  // Postconditions:

  ensure(invariant());

  // Exit:

  return;
}


fields::edge_centered_refiner_family::
~edge_centered_refiner_family()
{

  // Preconditions:

  // Body:

  // Nothing to do; base class does it all.

  // Postconditions:

  // Exit:

  return;
}

const std::string&
fields::edge_centered_refiner_family::
class_name() const
{
  // Preconditions:

  // Body:

  const string& result = static_class_name();

  // Postconditions:

  ensure(!result.empty());

  // Exit:

  return result;
}

const std::string&
fields::edge_centered_refiner_family::
static_class_name()
{
  // Preconditions:

  // Body:

  static const string result("edge_centered_refiner_family");

  // Postconditions:

  ensure(!result.empty());
  ensure(result == "edge_centered_refiner_family");

  // Exit:

  return result;
}


// PRIVATE MEMBER FUNCTIONS

fields::edge_centered_refiner_family::
edge_centered_refiner_family()
{

  // Preconditions:

  // Body:

  // Nothing to do; base class does it all.

  // Postconditions:

  ensure(invariant());

  // Exit:

  return;
}


bool
fields::edge_centered_refiner_family::
_has_prototype = make_prototype();

bool
fields::edge_centered_refiner_family::
make_prototype()
{
  bool result = true;

  // Preconditions:


  // Body:

  field_refiner_family* lproto = new edge_centered_refiner_family();

  family_factory().insert_prototype(lproto);

  // Postconditions:


  // Exit:

  return result;
}


// ===========================================================
// FIELD_REFINER_FAMILY FACET
// ===========================================================

// PUBLIC MEMBER FUNCTIONS

//
void
fields::edge_centered_refiner_family::
initialize(const base_space_poset& xbase_space, const field_refinement_policy& xpolicy)
{
  // Preconditions:

  require(!is_initialized());
  require(xbase_space.state_is_read_accessible());

  // Body:

  // Initialize the base class data members.

  field_refiner_family::initialize(xbase_space, xpolicy);

  // Get the type id of each member of the family and
  // and create the appropriate entry in _members.

  local_field_refiner* lref;

  // Cell type "segment"; same as zone-centered.

  lref = new zone_centered_segment_refiner(policy());
  _members.force_item(xbase_space.prototype_type_id("segment"), lref);

  // Cell type "segment_complex"; same as zone-centered.

  lref = new zone_centered_segment_refiner(policy());
  _members.force_item(xbase_space.prototype_type_id("segment_complex"), lref);

  // Cell type "triangle".

  lref = new edge_centered_triangle_refiner(policy());
  _members.force_item(xbase_space.prototype_type_id("triangle"), lref);

  // Cell type "triangle_nodes".

  lref = new edge_centered_triangle_refiner(policy());
  _members.force_item(xbase_space.prototype_type_id("triangle_nodes"), lref);

  /// @todo uncomment the following lines as the refiners they refer to
  /// become available.

  // Cell type "quad"

  lref = new barycentric_quad_refiner(policy());
  _members.force_item(xbase_space.prototype_type_id("quad"), lref);

  // Cell type "quad_nodes"

  lref = new barycentric_quad_refiner(policy());
  _members.force_item(xbase_space.prototype_type_id("quad_nodes"), lref);

  //   // Cell type "hex".

  //   lref = new barycentric_hex_refiner(policy());
  //   _members.force_item(xbase_space.prototype_type_id("hex"), lref);

  //   // Cell type "hex_nodes".

  //   lref = new barycentric_hex_refiner(policy());
  //   _members.force_item(xbase_space.prototype_type_id("hex_nodes"), lref);

  //   // Cell type "tetra".

  //   lref = new barycentric_tet_refiner(policy());
  //   _members.force_item(xbase_space.prototype_type_id("tetra"), lref);

  //   // Cell type "tetra_nodes".

  //   lref = new barycentric_tet_refiner(policy());
  //   _members.force_item(xbase_space.prototype_type_id("tetra_nodes"), lref);

  // Postconditions:

  ensure(invariant());
  ensure(is_initialized());
  ensure_for_all(i, 0, size(), (member(i) != 0) ? (&member(i)->policy() == &policy()) : true);

  // Exit:

  return;
}


// ===========================================================
// ANY FACET
// ===========================================================

// PUBLIC MEMBER FUNCTIONS

fields::edge_centered_refiner_family*
fields::edge_centered_refiner_family::
clone() const
{
  edge_centered_refiner_family* result;

  // Preconditions:

  // Body:

  result = new edge_centered_refiner_family(*this);

  // Postconditions:

  ensure(result != 0);
  ensure(is_same_type(result));

  // Exit:

  return result;
}


bool
fields::edge_centered_refiner_family::
invariant() const
{
  bool result = true;

  // Preconditions:

  // Body:

  // Must satisfy base class invariant

  result = result && field_refiner_family::invariant();

  if(invariant_check())
  {
    // Prevent recursive calls to invariant

    disable_invariant_check();

    // Finished, turn invariant checking back on.

    enable_invariant_check();
  }

  // Postconditions:

  // Exit

  return result;
}

bool
fields::edge_centered_refiner_family::
is_ancestor_of(const any* xother) const
{

  // Preconditions:

  require(xother != 0);

  // Body:

  // True if other conforms to this

  bool result = dynamic_cast<const edge_centered_refiner_family*>(xother) != 0;

  // Postconditions:

  return result;

}

