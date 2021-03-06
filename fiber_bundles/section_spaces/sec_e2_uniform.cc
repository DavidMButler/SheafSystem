
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
/// Implementation for class sec_e2_uniform.

#include "sec_e2_uniform.h"

#include "assert_contract.h"
#include "base_space_poset.h"
#include "binary_section_space_schema_member.impl.h"
#include "at0_space.h"
#include "at1_space.h"
#include "e2.h"
#include "fiber_bundles_namespace.h"
#include "sec_at0.h"
#include "sec_at0_space.h"
#include "sec_at1_space.h"
#include "structured_block_2d.h"
#include "sec_tuple.impl.h"
#include "sec_tuple_space.impl.h"
#include "sec_vd.impl.h"

using namespace std;
using namespace fiber_bundle; // Workaround for MS C++ bug.

//==============================================================================
// CLASS SEC_E2_UNIFORM
//==============================================================================


// ===========================================================
// HOST FACTORY FACET OF CLASS SEC_E2_UNIFORM
// ===========================================================

// PUBLIC MEMBER FUNCTIONS

fiber_bundle::sec_e2_uniform::host_type&
fiber_bundle::sec_e2_uniform::
new_host(namespace_type& xns, 
         const poset_path& xhost_path, 
         const poset_path& xschema_path, 
         const poset_path& xscalar_space_path, 
         bool xauto_access)
{
  // cout << endl << "Entering sec_e2_uniform::new_host." << endl;

  // Preconditions:

  require(xns.state_is_auto_read_write_accessible(xauto_access));

  require(!xhost_path.empty());
  require(!xns.contains_path(xhost_path, xauto_access));

  require(xschema_path.full());
  require(xns.path_is_auto_read_accessible<schema_type::host_type>(xschema_path, xauto_access));
  require(host_type::fiber_space_conforms<fiber_type::host_type>(xns, xschema_path, xauto_access));

  require(xns.path_is_auto_read_accessible<scalar_type::host_type>(xscalar_space_path, xauto_access));

  require(host_type::same_scalar_fiber_space(xns, xschema_path, xscalar_space_path, xauto_access));

  // Body:

  host_type& result = host_type::new_table(xns, xhost_path, xschema_path, xscalar_space_path, xauto_access);

  // Postconditions:

  ensure(xns.owns(result, xauto_access));
  ensure(result.path(true) == xhost_path);
  ensure(result.state_is_not_read_accessible());
  ensure(result.schema(true).path(xauto_access) == xschema_path);

  ensure(result.factor_ct(true) == result.schema(true).fiber_space<fiber_type::host_type>().factor_ct(xauto_access));
  ensure(result.d(true) == result.schema(true).fiber_space<fiber_type::host_type>().d(xauto_access));
  ensure(result.d(true) == result.dd(true));
  ensure(result.scalar_space_path(true) == xscalar_space_path);
  ensure(result.p(true) == result.schema(true).fiber_space<fiber_type::host_type>().p(xauto_access));
  ensure(result.p(true) == 1);
  ensure(result.dd(true) == result.schema(true).fiber_space<fiber_type::host_type>().dd(xauto_access));
  ensure(result.vector_space_path(true) == xhost_path);

  // Exit:

  // cout << "Leaving sec_e2_uniform::new_host." << endl;
  return result;
}

fiber_bundle::sec_e2_uniform::host_type&
fiber_bundle::sec_e2_uniform::
standard_host(namespace_type& xns, 
              const poset_path& xbase_path, 
              const poset_path& xrep_path, 
              const std::string& xsection_suffix, 
              const std::string& xfiber_suffix, 
              bool xauto_access)
{
  // cout << endl << "Entering sec_e2_uniform::new_host." << endl;

  // Preconditions:

  require(xns.state_is_auto_read_write_accessible(xauto_access));

  require(xbase_path.full());
  require(xns.path_is_auto_read_accessible<base_space_poset>(xbase_path, xauto_access));

  require(xrep_path.empty() || xrep_path.full());
  require(xrep_path.empty() || xns.path_is_auto_read_accessible<sec_rep_descriptor_poset>(xrep_path, xauto_access));  

  require(xsection_suffix.empty() || poset_path::is_valid_name(xsection_suffix));

  require(xfiber_suffix.empty() || poset_path::is_valid_name(xfiber_suffix));

  require(standard_host_is_available<sec_e2_uniform>(xns, xbase_path, xrep_path, xsection_suffix, xfiber_suffix, xauto_access));
  require(fiber_type::standard_host_is_available<fiber_type>(xns, xfiber_suffix, xauto_access));
  require(schema_type::standard_host_is_available<sec_e2_uniform>(xns, xbase_path, xrep_path, xfiber_suffix, xauto_access));

  // Body:

  poset_path lstd_path = standard_host_path<sec_e2_uniform>(xbase_path, xrep_path, xsection_suffix, xfiber_suffix);
  
  host_type* lresult_ptr;
  
  if(xns.contains_path(lstd_path, xauto_access))
  {
    // Standard host already exists, just return it.

    lresult_ptr = &xns.member_poset<host_type>(lstd_path, xauto_access);
  }
  else
  {
    // Standard host doesn't exist, have to create it.

    // Apply default for rep path if needed.

    poset_path lrep_path = (!xrep_path.empty() ? xrep_path : standard_rep_path());

    // Find or create the standard schema member.

    poset_path lstd_schema_path = 
      schema_type::standard_member<sec_e2_uniform>(xns, xbase_path, lrep_path, xfiber_suffix, xauto_access);

    // Find or create the standard scalar space.

    poset_path lscalar_space_path = 
      scalar_type::standard_host(xns, xbase_path, lrep_path, xsection_suffix, xfiber_suffix, xauto_access).path(xauto_access);
    
    // Create the standard host.

    lresult_ptr = &new_host(xns, lstd_path, lstd_schema_path, lscalar_space_path, xauto_access);
  }

  host_type& result = *lresult_ptr;

  // Postconditions:

  ensure(xns.owns(result, xauto_access));
  ensure(result.path(true) == standard_host_path<sec_e2_uniform>(xbase_path, xrep_path, xsection_suffix, xfiber_suffix));
  ensure(result.state_is_not_read_accessible());
  ensure(result.schema(true).path(xauto_access) == 
         schema_type::standard_member_path<sec_e2_uniform>(xbase_path, xrep_path, xfiber_suffix));

  ensure(result.factor_ct(true) == result.schema(true).fiber_space<fiber_type::host_type>().factor_ct(xauto_access));
  ensure(result.d(true) == result.schema(true).fiber_space<fiber_type::host_type>().d(xauto_access));
  ensure(result.d(true) == result.dd(true));
  ensure(result.scalar_space_path(true) == 
         scalar_type::standard_host_path<scalar_type>(xbase_path, result.rep().path(xauto_access), xsection_suffix, xfiber_suffix));
  ensure(result.p(true) == result.schema(true).fiber_space<fiber_type::host_type>().p(xauto_access));
  ensure(result.p(true) == 1);
  ensure(result.dd(true) == result.schema(true).fiber_space<fiber_type::host_type>().dd(xauto_access));
  ensure(result.vector_space_path(true) == result.path(true));

  // Exit:

  // cout << "Leaving sec_e2_uniform::new_host." << endl;
  return result;
}

// PROTECTED MEMBER FUNCTIONS

// PRIVATE MEMBER FUNCTIONS


//==============================================================================
// E2_UNIFORM FACET OF CLASS SEC_E2_UNIFORM
//==============================================================================

// PUBLIC MEMBER FUNCTIONS

fiber_bundle::sec_e2_uniform::
sec_e2_uniform()
{

  // Preconditions:

  // Body:

  // Postconditions:

  ensure(invariant());
}


// =============================================================================
// NEW HANDLE, NEW STATE CONSTRUCTORS
// =============================================================================

fiber_bundle::sec_e2_uniform::
sec_e2_uniform(sec_rep_space* xhost,
               const block<dof_type>& xmin,
               const block<dof_type>& xmax,
               bool xauto_access)
{
  // Preconditions:

  require(precondition_of(new_jim_state(xhost, xmin, xmax, xauto_access)));

  // Body:

  new_jim_state(xhost, xmin, xmax, xauto_access);

  // Postconditions:

  ensure(postcondition_of(new_jim_state(xhost, xmin, xmax, xauto_access)));

  // Exit:

  return;
}


fiber_bundle::sec_e2_uniform::
sec_e2_uniform(sec_rep_space* xhost, section_dof_map* xdof_map, bool xauto_access)
{
  // Preconditions:

  require(precondition_of(new_jim_state(xhost, xdof_map, false, xauto_access)));

  // Body:

  new_jim_state(xhost, xdof_map, false, xauto_access);

  // Postconditions:

  ensure(postcondition_of(new_jim_state(xhost, xdof_map, false, xauto_access)));

  // Exit:

  return;
}

fiber_bundle::sec_e2_uniform::
sec_e2_uniform(sec_rep_space* xhost,
               abstract_poset_member& xbase_mbr,
               int xbase_version,
               bool xauto_access)
{

  // Preconditions:

  require(precondition_of(new_jim_state(xhost, xbase_mbr, xbase_version, xauto_access)));

  // Body:

  new_jim_state(xhost, xbase_mbr, xbase_version, xauto_access);

  // Postconditions:

  ensure(postcondition_of(new_jim_state(xhost, xbase_mbr, xbase_version, xauto_access)));

  // Exit:

  return;
}

fiber_bundle::sec_e2_uniform::
sec_e2_uniform(sec_rep_space* xhost, const subposet& xbase_parts, bool xauto_access)
{
  // Preconditions:

  require(precondition_of(new_jim_state(xhost, xbase_parts, xauto_access)));

  // Body:

  new_jrm_state(xhost, xbase_parts, xauto_access);

  // Postconditions:

  require(postcondition_of(new_jim_state(xhost, xbase_parts, xauto_access)));

  // Exit:

  return;
}

// =============================================================================
// NEW HANDLE, EXISTING STATE CONSTRUCTORS
// =============================================================================

fiber_bundle::sec_e2_uniform::
sec_e2_uniform(const sec_rep_space* xhost, pod_index_type xindex)
{
  // Preconditions:

  require(xhost != 0);
  require(xhost->state_is_read_accessible());
  require(xhost->contains_member(xindex));

  // Body:

  attach_to_state(xhost, xindex);

  // Postconditions:

  ensure(invariant());
  //ensure(host() == xhost);
  ensure(index() == xindex);
  ensure(is_attached());
  ensure(!is_restricted());
}

fiber_bundle::sec_e2_uniform::
sec_e2_uniform(const sec_rep_space* xhost, const scoped_index& xindex)
{

  // Preconditions:

  require(xhost != 0);
  require(xhost->state_is_read_accessible());
  require(xhost->contains_member(xindex));

  // Body:

  attach_to_state(xhost, xindex.hub_pod());

  // Postconditions:

  ensure(invariant());
  //ensure(host() == xhost);
  ensure(index() ==~ xindex);
  ensure(is_attached());
  ensure(!is_restricted());

}

fiber_bundle::sec_e2_uniform::
sec_e2_uniform(const sec_rep_space* xhost, const std::string& xname)
{

  // Preconditions:

  require(xhost != 0);
  require(xhost->state_is_read_accessible());
  require(!xname.empty());
  require(xhost->contains_member(xname));

  // Body:

  attach_to_state(xhost, xname);

  // Postconditions:

  ensure(invariant());
  //ensure(host() == xhost);
  ensure(name() == xname);
  ensure(is_attached());
  ensure(!is_restricted());

}


fiber_bundle::sec_e2_uniform::
sec_e2_uniform(const namespace_poset* xnamespace,
               const poset_path& xpath,
               bool xauto_access)
{

  // Preconditions:

  require(precondition_of(attach_to_state(same args)));

  // Body:

  attach_to_state(xnamespace, xpath, xauto_access);

  // Postconditions:

  ensure(postcondition_of(attach_to_state(same args)));

  // Exit:

  return;
}


fiber_bundle::sec_e2_uniform::
sec_e2_uniform(const sec_rep_space_member* xother)
{

  // Preconditions:

  require(xother != 0);

  // Body:

  attach_to_state(xother);

  // Postconditions:

  ensure(invariant());
  ensure(is_attached());
  ensure(is_same_state(xother));
  ensure(is_same_restriction(xother));

}

fiber_bundle::sec_e2_uniform::
~sec_e2_uniform()
{

  // Preconditions:

  // Body:

  // Postconditions:

}

// =============================================================================
// EXISTING HANDLE, NEW STATE "CONSTRUCTORS"
// =============================================================================

void
fiber_bundle::sec_e2_uniform::
new_jim_state(sec_rep_space* xhost,
              const block<dof_type>& xmin,
              const block<dof_type>& xmax,
              bool xauto_access)
{
  // Preconditions:

  require(precondition_of(new_jim_state(xhost, 0, false, xauto_access)));
  require(xmin.ct() >= 2);
  require(xmax.ct() >= 2);
  require_for_all(i, 0, 2, xmin[i] <= xmax[i]);

  // Body:

  new_jim_state(xhost, static_cast<poset_dof_map*>(0), false, xauto_access);
  put_bounds(xmin, xmax, xauto_access);

  // Postconditions:

  ensure(min_x(xauto_access) == xmin[0]);
  ensure(min_y(xauto_access) == xmin[1]);
  ensure(max_x(xauto_access) == xmax[0]);
  ensure(max_y(xauto_access) == xmax[1]);

  // Exit:

  return;
}


// ===========================================================================
// OTHER 
// ===========================================================================


fiber_bundle::sec_e2_uniform&
fiber_bundle::sec_e2_uniform::
operator=(const abstract_poset_member& xother)
{
  // Preconditions:

  require(is_ancestor_of(&xother));
  require(precondition_of(attach_to_state(&xother)));

  // Body:

  attach_to_state(&xother);

  // Postconditions:

  ensure(postcondition_of(attach_to_state(&xother)));

  // Exit:

  return *this;
}

fiber_bundle::sec_e2_uniform&
fiber_bundle::sec_e2_uniform::
operator=(const sec_e2_uniform& xother)
{
  // Preconditions:

  require(precondition_of(attach_to_state(&xother)));

  // Body:

  attach_to_state(&xother);

  // Postconditions:

  ensure(postcondition_of(attach_to_state(&xother)));

  // Exit:

  return *this;
}

fiber_bundle::sec_e2_uniform&
fiber_bundle::sec_e2_uniform::
operator=(const e2& xfiber)
{
  // Preconditions:

  require(precondition_of(sec_vd::operator=(xfiber)));

  // Body:

  sec_vd::operator=(xfiber);

  // Postconditions:

  ensure(postcondition_of(sec_vd::operator=(xfiber)));

  // Exit:

  return *this;
}

fiber_bundle::sec_e2_uniform&
fiber_bundle::sec_e2_uniform::
operator=(const e2_lite& xfiber)
{
  // Preconditions:

  require(precondition_of(sec_vd::operator=(xfiber)));

  // Body:

  sec_vd::operator=(xfiber);

  // Postconditions:

  ensure(postcondition_of(sec_vd::operator=(xfiber)));

  // Exit:

  return *this;
}

const fiber_bundle::sec_e2_uniform::fiber_type&
fiber_bundle::sec_e2_uniform::
fiber_prototype() const
{
  // Preconditions:

  // Body:

  static const fiber_type result;

  // Postconditions:

  // Exit:

  return result;
}

void
fiber_bundle::sec_e2_uniform::
put_bounds(const block<dof_type>& xmin,
           const block<dof_type>& xmax,
           bool xauto_access)
{
  // Preconditions:

  require(xmin.ct() >= 2);
  require(xmax.ct() >= 2);
  require_for_all(i, 0, 2, xmin[i] <= xmax[i]);
  require(xauto_access || state_is_read_write_accessible());

  // Body:

  if(xauto_access)
  {
    get_read_write_access(true);
  }

  // Set the coordinates dofs;
  // uniform coordinates have only 8 dofs in 2d,
  // the x,y coordinates at the corners of the domain.
  // (Even these aren't all independent).

  sec_e2_uniform::fiber_type::volatile_type lfiber;

  // Structured_block_2d ctor sets client ids to match the order
  // for a normal quad.

  // xmin, ymin; client id 0.

  lfiber[0] = xmin[0];
  lfiber[1] = xmin[1];
  put_fiber(0, lfiber);

  // xmax, ymin; client id 1:

  lfiber[0] = xmax[0];
  lfiber[1] = xmin[1];
  put_fiber(1, lfiber);

  // xmax, ymax; client id 2.

  lfiber[0] = xmax[0];
  lfiber[1] = xmax[1];
  put_fiber(2, lfiber);

  // xmin, ymax; client id 3.

  lfiber[0] = xmin[0];
  lfiber[1] = xmax[1];
  put_fiber(3, lfiber);

  if(xauto_access)
  {
    release_access();
  }

  // Postconditions:

  ensure(min_x(xauto_access) == xmin[0]);
  ensure(min_y(xauto_access) == xmin[1]);
  ensure(max_x(xauto_access) == xmax[0]);
  ensure(max_y(xauto_access) == xmax[1]);

  // Exit:

  return;
}

void
fiber_bundle::sec_e2_uniform::
get_bounds(block<dof_type>& xmin, block<dof_type>& xmax, bool xauto_access) const
{
  // Preconditions:

  require(xauto_access || state_is_read_accessible());

  // Body:

  if(xauto_access)
  {
    get_read_access();
  }

  xmin.reserve(2);
  xmin.set_ct(2);

  xmax.reserve(2);
  xmax.set_ct(2);

  // Structured_block_2d ctor sets client ids to match the order
  // for a normal quad.

  // xmin, ymin; client id 0.

  get_fiber(0, xmin.base(), xmin.ct()*sizeof(dof_type));

  // xmax, ymax; client id 2.

  get_fiber(2, xmax.base(), xmax.ct()*sizeof(dof_type));

  if(xauto_access)
  {
    release_access();
  }

  // Postconditions:

  ensure(xmin.ct() == 2);
  ensure(xmax.ct() == 2);
  ensure_for_all(i, 0, 2, xmin[i] <= xmax[i]);

  // Exit:

  return;
}

fiber_bundle::sec_e2_uniform::dof_type
fiber_bundle::sec_e2_uniform::
min_x(bool xauto_access) const
{
  dof_type result;

  // Preconditions:

  require(xauto_access || state_is_read_accessible());

  // Body:

  if(xauto_access)
  {
    get_read_access();
  }

  // min_x; client id 0.

  sec_e2_uniform::fiber_type::volatile_type lfiber;
  get_fiber(0, lfiber);

  result = lfiber[0];

  if(xauto_access)
  {
    release_access();
  }

  // Postconditions:


  // Exit:

  return result;
}

fiber_bundle::sec_e2_uniform::dof_type
fiber_bundle::sec_e2_uniform::
min_y(bool xauto_access) const
{
  dof_type result;

  // Preconditions:

  require(xauto_access || state_is_read_accessible());

  // Body:

  if(xauto_access)
  {
    get_read_access();
  }

  // min_x; client id 0.

  sec_e2_uniform::fiber_type::volatile_type lfiber;
  get_fiber(0, lfiber);

  result = lfiber[1];

  if(xauto_access)
  {
    release_access();
  }

  // Postconditions:


  // Exit:

  return result;
}

fiber_bundle::sec_e2_uniform::dof_type
fiber_bundle::sec_e2_uniform::
max_x(bool xauto_access) const
{
  dof_type result;

  // Preconditions:

  require(xauto_access || state_is_read_accessible());

  // Body:

  if(xauto_access)
  {
    get_read_access();
  }

  // max_x; client id 2.

  sec_e2_uniform::fiber_type::volatile_type lfiber;
  get_fiber(2, lfiber);

  result = lfiber[0];

  if(xauto_access)
  {
    release_access();
  }

  // Postconditions:


  // Exit:

  return result;
}

fiber_bundle::sec_e2_uniform::dof_type
fiber_bundle::sec_e2_uniform::
max_y(bool xauto_access) const
{
  dof_type result;

  // Preconditions:

  require(xauto_access || state_is_read_accessible());

  // Body:

  if(xauto_access)
  {
    get_read_access();
  }

  // max_x; client id 2.

  sec_e2_uniform::fiber_type::volatile_type lfiber;
  get_fiber(2, lfiber);

  result = lfiber[1];

  if(xauto_access)
  {
    release_access();
  }

  // Postconditions:


  // Exit:

  return result;
}

fiber_bundle::sec_e2_uniform::dof_type
fiber_bundle::sec_e2_uniform::
inc_x(bool xauto_access) const
{
  dof_type result;

  // Preconditions:

  require(xauto_access || state_is_read_accessible());

  // Body:

  if(xauto_access)
  {
    get_read_access();
  }

  // Get the number of zones in the x direction.

  base_space_poset& lbase_host = schema().host()->base_space();
  pod_index_type lbase_id = schema().base_space_id();
  base_space_poset::row_dof_tuple_type ltuple;
  lbase_host.member_dof_tuple(lbase_id, &ltuple, sizeof(ltuple), false);
  
  if(ltuple.i_size == 0)
  {
    result = 0;
  }
  else
  {
    result = (max_x(false) - min_x(false))/ltuple.i_size;
  }

  if(xauto_access)
  {
    release_access();
  }

  // Postconditions:


  // Exit:

  return result;
}

fiber_bundle::sec_e2_uniform::dof_type
fiber_bundle::sec_e2_uniform::
inc_y(bool xauto_access) const
{
  dof_type result;

  // Preconditions:

  require(xauto_access || state_is_read_accessible());

  // Body:

  if(xauto_access)
  {
    get_read_access();
  }

  // Get the number of zones in the x direction.

  base_space_poset& lbase_host = schema().host()->base_space();
  pod_index_type lbase_id = schema().base_space_id();
  base_space_poset::row_dof_tuple_type ltuple;
  lbase_host.member_dof_tuple(lbase_id, &ltuple, sizeof(ltuple), false);
  
  if(ltuple.j_size == 0)
  {
    result = 0;
  }
  else
  {
    result = (max_y(false) - min_y(false))/ltuple.j_size;
  }

  if(xauto_access)
  {
    release_access();
  }

  // Postconditions:


  // Exit:

  return result;
}

// PROTECTED MEMBER FUNCTIONS

// PRIVATE MEMBER FUNCTIONS


//==============================================================================
// E2 FACET OF CLASS SEC_E2_UNIFORM
//==============================================================================

// PUBLIC MEMBER FUNCTIONS

// PROTECTED MEMBER FUNCTIONS

// PRIVATE MEMBER FUNCTIONS


//==============================================================================
// ED FACET OF CLASS SEC_E2_UNIFORM
//==============================================================================

// PUBLIC MEMBER FUNCTIONS

// PROTECTED MEMBER FUNCTIONS

// PRIVATE MEMBER FUNCTIONS


//==============================================================================
// AT1 FACET OF CLASS SEC_E2_UNIFORM
//==============================================================================

// PUBLIC MEMBER FUNCTIONS

// PROTECTED MEMBER FUNCTIONS

// PRIVATE MEMBER FUNCTIONS


//==============================================================================
// ATP FACET OF CLASS SEC_E2_UNIFORM
//==============================================================================

// PUBLIC MEMBER FUNCTIONS

// PROTECTED MEMBER FUNCTIONS

// PRIVATE MEMBER FUNCTIONS


//==============================================================================
// TP FACET OF CLASS SEC_E2_UNIFORM
//==============================================================================

// PUBLIC MEMBER FUNCTIONS

// PROTECTED MEMBER FUNCTIONS

// PRIVATE MEMBER FUNCTIONS


//==============================================================================
// VD FACET OF CLASS SEC_E2_UNIFORM
//==============================================================================

// PUBLIC MEMBER FUNCTIONS

// PROTECTED MEMBER FUNCTIONS

// PRIVATE MEMBER FUNCTIONS


//==============================================================================
// TUPLE FACET OF CLASS SEC_E2_UNIFORM
//==============================================================================

// PUBLIC MEMBER FUNCTIONS

const sheaf::poset_path&
fiber_bundle::sec_e2_uniform::
standard_rep_path()
{

  // Preconditions:


  // Body:

  static const poset_path
    result(sec_rep_descriptor::standard_host_path().poset_name(), "vertex_block_uniform");

  // Postconditions:

  ensure(result.full());

  // Exit:

  return result;
}

// PROTECTED MEMBER FUNCTIONS

// PRIVATE MEMBER FUNCTIONS


//==============================================================================
// ABSTRACT POSET MEMBER FACET OF CLASS SEC_E2_UNIFORM
//==============================================================================

// PUBLIC MEMBER FUNCTIONS

const std::string&
fiber_bundle::sec_e2_uniform::
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
fiber_bundle::sec_e2_uniform::
static_class_name()
{
  // Preconditions:

  // Body:

  static const string result("sec_e2_uniform");

  // Postconditions:

  ensure(!result.empty());

  // Exit:

  return result;
}

fiber_bundle::sec_e2_uniform*
fiber_bundle::sec_e2_uniform::
clone() const
{

  // Preconditions:

  // Body:

  // create new handle of the current class.

  sec_e2_uniform *result = new sec_e2_uniform();

  // Postconditions:

  ensure(result != 0);
  ensure(result->invariant());

  // Exit:

  return result;

}

// PROTECTED MEMBER FUNCTIONS

// PRIVATE MEMBER FUNCTIONS


//==============================================================================
// ANY FACET OF CLASS SEC_E2_UNIFORM
//==============================================================================

// PUBLIC MEMBER FUNCTIONS

bool
fiber_bundle::sec_e2_uniform::
is_ancestor_of(const any* xother) const
{
  // Preconditions:

  require(xother != 0);

  // Body:

  // If other may be dynamically cast to the type of this then this is an
  // ancestor of other.

  bool result = dynamic_cast<const sec_e2_uniform*>(xother) != 0;

  // Postconditions:

  //ensure(invariant());

  // Exit:

  return result;

}

bool
fiber_bundle::sec_e2_uniform::
invariant() const
{
  bool result = true;

  // Preconditions:

  // Body:

  // Must satisfy base class invariant

  invariance(sec_e2::invariant());

  if (invariant_check())
  {
    // Prevent recursive calls to invariant

    disable_invariant_check();

    // Finished, turn invariant checking back on.

    enable_invariant_check();
  }

  // Postconditions:

  ensure(is_derived_query);

  // Exit:

  return result;
}

// PROTECTED MEMBER FUNCTIONS

// PRIVATE MEMBER FUNCTIONS


