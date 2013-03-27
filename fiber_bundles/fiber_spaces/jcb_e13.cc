
// $RCSfile: jcb_e13.cc,v $ $Revision: 1.47 $ $Date: 2013/03/13 00:58:44 $

//
// Copyright (c) 2013 Limit Point Systems, Inc.
//

/// @file
/// Implementation for class jcb_e13.

#include "jcb_e13.impl.h"

#include "abstract_poset_member.impl.h"
#include "assert_contract.h"
#include "namespace_poset.h"
#include "schema_poset_member.h"
#include "wsv_block.h"

using namespace fiber_bundle; // Workaround for MS C++ bug.


//==============================================================================
// CLASS JCB_E13_LITE
//==============================================================================


//============================================================================
// JCB_E13 FACET OF CLASS JCB_E13_LITE
//============================================================================

// PUBLIC MEMBER FUNCTIONS

fiber_bundle::jcb_e13_lite::
jcb_e13_lite()
{

  // Preconditions:

  // Body:

  // Postconditions:

  ensure(invariant());

  // Exit:
}

fiber_bundle::jcb_e13_lite::
jcb_e13_lite(const jcb_e13_lite& xother)
{
  // Preconditions:

  // Body:

  *this = xother;

  // Postconditions:

  ensure(invariant());

  // Exit:
}

fiber_bundle::jcb_e13_lite&
fiber_bundle::jcb_e13_lite::
operator=(const jcb_e13_lite& xother)
{

  // Preconditions:

  // Body:

  if(this == &xother)
    return *this;

  int ld = d();
  for(int i=0; i<ld; ++i)
  {
    put_component(i, xother[i]);
  }

  // Postconditions:

  ensure(invariant());
  ensure_for_all(i, 0, d(), component(i) == xother[i]); 

  // Exit:

  return *this;
}

fiber_bundle::jcb_e13_lite::
~jcb_e13_lite()
{
  // Preconditions:

  // Body:

  // Postconditions:

  // Exit:

}

fiber_bundle::jcb_e13_lite::
jcb_e13_lite(const row_dofs_type& xrow_dofs)
{
  // Preconditions:

  // Body:

  *this = xrow_dofs;

  // Postconditions:

  ensure(invariant());

  // Exit:
}

fiber_bundle::jcb_e13_lite&
fiber_bundle::jcb_e13_lite::
operator=(const row_dofs_type& xrow_dofs)
{
  // Preconditions:

  // Body:

  _row_dofs = xrow_dofs;
  
  // Postconditions:

  ensure(invariant());

  // Exit:

  return *this;

}

fiber_bundle::jcb_e13_lite::
jcb_e13_lite(const matrix_type& xmatrix)
{
  // Preconditions:

  // Body:

  *this = xmatrix;

  // Postconditions:

  ensure(invariant());

  // Exit:
}

fiber_bundle::jcb_e13_lite& 
fiber_bundle::jcb_e13_lite::
operator=(const matrix_type& xmatrix)
{
  // Preconditions:

  // Body:

    //_row_dofs = xmatrix;
  _row_dofs = reinterpret_cast<const row_dofs_type&>(xmatrix);

  // Postconditions:

  ensure(invariant());

  // Exit:

  return *this;

}

fiber_bundle::jcb_e13_lite::
operator jcb_e13_lite::matrix_type& ()
{
  // Preconditions:

  // Body:

  matrix_type& result = _row_dofs;

  // Postconditions:

  // Exit:

  return result;
}

fiber_bundle::jcb_e13_lite::
operator const jcb_e13_lite::matrix_type& () const
{
  // Preconditions:

  // Body:

  const matrix_type& result = _row_dofs;

  // Postconditions:

  // Exit:

  return result;
}

fiber_bundle::jcb_e13_lite::
operator jcb_e13_lite::row_dofs_type& ()
{
  // Preconditions:

  // Body:

  row_dofs_type& result = _row_dofs;

  // Postconditions:

  // Exit:

  return result;
}

fiber_bundle::jcb_e13_lite::
operator const jcb_e13_lite::row_dofs_type& () const
{
  // Preconditions:

  // Body:

  const row_dofs_type& result = _row_dofs;

  // Postconditions:

  // Exit:

  return result;
}


fiber_bundle::jcb_e13_lite::
jcb_e13_lite(const value_type& dxdu,
             const value_type& dydu,
             const value_type& dzdu)
{
  // Preconditions:

  // Body:

  put_components(dxdu, dydu, dzdu);

  // Postconditions:

  ensure(invariant());
  ensure(isunordered_or_equals(component(0), dxdu));
  ensure(isunordered_or_equals(component(1), dydu));
  ensure(isunordered_or_equals(component(2), dzdu));

  // Exit:
}

void
fiber_bundle::jcb_e13_lite::
put_components(const value_type& dxdu,
               const value_type& dydu,
               const value_type& dzdu)
{
  // Preconditions:

  // Body:

  put_component(0, dxdu);
  put_component(1, dydu);
  put_component(2, dzdu);

  // Postconditions:

  ensure(invariant());

  ensure(isunordered_or_equals(component(0), dxdu));
  ensure(isunordered_or_equals(component(1), dydu));
  ensure(isunordered_or_equals(component(2), dzdu));

  // Exit:
}

// PROTECTED MEMBER FUNCTIONS

// PRIVATE MEMBER FUNCTIONS


//============================================================================
// JCB_ED FACET OF CLASS JCB_E13_LITE
//============================================================================

// PUBLIC MEMBER FUNCTIONS

// PROTECTED MEMBER FUNCTIONS

// PRIVATE MEMBER FUNCTIONS


//============================================================================
// JACOBIAN (JCB) FACET OF CLASS JCB_E13_LITE
//============================================================================

// PUBLIC MEMBER FUNCTIONS

int
fiber_bundle::jcb_e13_lite::
dd() const
{
  // Preconditions:

  // Body:

  int result = 1;

  // Postconditions:

  ensure(invariant());
  ensure(result == 1);

  // Exit:

  return result;
}

int
fiber_bundle::jcb_e13_lite::
dr() const
{
  // Preconditions:

  // Body:

  int result = 3;

  // Postconditions:

  ensure(invariant());
  ensure(result == 3);

  // Exit:

  return result;
}

// PROTECTED MEMBER FUNCTIONS

// PRIVATE MEMBER FUNCTIONS


//============================================================================
// VECTOR ALGEBRA (VD) FACET OF CLASS JCB_E13_LITE
//============================================================================

// PUBLIC MEMBER FUNCTIONS


// PROTECTED MEMBER FUNCTIONS

// PRIVATE MEMBER FUNCTIONS


//============================================================================
// CARTESIAN ALGEBRA (TUPLE) FACET OF CLASS JCB_E13_LITE
//============================================================================

// PUBLIC MEMBER FUNCTIONS

// PROTECTED MEMBER FUNCTIONS

// PRIVATE MEMBER FUNCTIONS


//============================================================================
// ABSTRACT POSET MEMBER FACET OF CLASS JCB_E13_LITE
//============================================================================

// PUBLIC MEMBER FUNCTIONS

const string&
fiber_bundle::jcb_e13_lite::
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

const string&
fiber_bundle::jcb_e13_lite::
static_class_name()
{
  // Preconditions:

  // Body:

  static const string result("jcb_e13_lite");

  // Postconditions:

  ensure(!result.empty());

  // Exit:

  return result;
}

fiber_bundle::jcb_e13_lite*
fiber_bundle::jcb_e13_lite::
clone() const
{
  jcb_e13_lite* result = 0;

  // Preconditions:

  // Body:

  result = new jcb_e13_lite();

  // Postconditions:

  ensure(result != 0);
  ensure(is_same_type(*result));

  // Exit:

  return result;
}

// PROTECTED MEMBER FUNCTIONS

// PRIVATE MEMBER FUNCTIONS


//============================================================================
// ANY FACET OF CLASS JCB_E13_LITE
//============================================================================

// PUBLIC MEMBER FUNCTIONS

bool
fiber_bundle::jcb_e13_lite::
is_ancestor_of(const any_lite& xother) const
{
  // Preconditions:

  require(&xother != 0);

  // Body:

  // True if other conforms to this.

  bool result = dynamic_cast<const jcb_e13_lite*>(&xother) != 0;

  // Postconditions:

  return result;
}

bool
fiber_bundle::jcb_e13_lite::
invariant() const
{
  bool result = true;

  if(invariant_check())
  {
    // Prevent recursive calls to invariant.

    disable_invariant_check();

    // Must satisfy base class invariant.

    invariance(jcb_ed_lite::invariant());

    // Invariances for this class:

    // Finished, turn invariant checking back on.

    enable_invariant_check();
  }

  // Exit

  return result;
}

void*
fiber_bundle::jcb_e13_lite::
row_dofs()
{
  return &_row_dofs;
}

const void*
fiber_bundle::jcb_e13_lite::
row_dofs() const
{
  return &_row_dofs;
}

// PROTECTED MEMBER FUNCTIONS

// PRIVATE MEMBER FUNCTIONS


//==============================================================================
// CLASS JCB_E13
//==============================================================================


//============================================================================
// JCB_E13 FACET OF CLASS JCB_E13
//============================================================================

// PUBLIC MEMBER FUNCTIONS

fiber_bundle::jcb_e13::
jcb_e13()
{

  // Preconditions:

  // Body:

  // Postconditions:

  ensure(invariant());
}

fiber_bundle::jcb_e13::
jcb_e13(const poset_state_handle* xhost, pod_index_type xhub_id)
{
  // Preconditions:

  require(xhost != 0);
  require(xhost->state_is_read_accessible());
  require(xhost->contains_member(xhub_id));

  // Body:

  attach_to_state(xhost, xhub_id);

  // Postconditions:

  ensure(invariant());
  // ensure(host() == xhost);
  ensure(index() == xhub_id);
  ensure(is_attached());
}

fiber_bundle::jcb_e13::
jcb_e13(const poset_state_handle* xhost, const scoped_index& xid)
{
  // Preconditions:

  require(xhost != 0);
  require(xhost->state_is_read_accessible());
  require(xhost->contains_member(xid));

  // Body:

  attach_to_state(xhost, xid.hub_pod());

  // Postconditions:

  ensure(invariant());
  // ensure(host() == xhost);
  ensure(index() ==~ xid);
  ensure(is_attached());
}

fiber_bundle::jcb_e13::
jcb_e13(const poset_state_handle* xhost, const string& xname)
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
  // ensure(host() == xhost);
  ensure(name() == xname);
  ensure(is_attached());

}

fiber_bundle::jcb_e13::
jcb_e13(abstract_poset_member* xother)
{

  // Preconditions:

  require(xother != 0);

  // Body:

  attach_to_state(xother);

  // Postconditions:

  ensure(invariant());
  ensure(is_attached());
  ensure(is_same_state(xother));

}

fiber_bundle::jcb_e13::
jcb_e13(poset_state_handle* xhost, bool xauto_access)
{

  // Preconditions:

  require(precondition_of(new_jim_state(xhost, 0, false, xauto_access)));

  // Body:

  new_jim_state(xhost, 0, false, xauto_access);

  // Postconditions:

  ensure(postcondition_of(new_jim_state(xhost, 0, false, xauto_access)));

  // Exit:

  return;
}

fiber_bundle::jcb_e13::
jcb_e13(poset_state_handle& xhost,
       const row_dofs_type& xrdt,
       bool xauto_access)
{

  // Preconditions:

  require(precondition_of(new_jim_state(&xhost, 0, false, xauto_access)));

  // Body:

  new_jim_state(&xhost, 0, false, xauto_access);

  if(xauto_access)
  {
    xhost.get_read_write_access();
  }

  *this = xrdt;

  if(xauto_access)
  {
    xhost.release_access();
  }

  // Postconditions:

  ensure(postcondition_of(new_jim_state(&xhost, 0, false, xauto_access)));

  // Exit:

  return;
}

fiber_bundle::jcb_e13&
fiber_bundle::jcb_e13::
operator=(const row_dofs_type& xrdt)
{
  // Preconditions:

  require(state_is_read_write_accessible());

  // Body:

  int ld = d();
  for(int i=0; i<ld; ++i)
  {
    put_component(i, xrdt.components[i]);
  }

  // Postconditions:

  ensure_for_all(i, 0, d(), component(i) == xrdt.components[i]);

  // Exit:

  return *this;

}

///
fiber_bundle::jcb_e13&
fiber_bundle::jcb_e13::
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

///
fiber_bundle::jcb_e13&
fiber_bundle::jcb_e13::
operator=(const jcb_e13& xother)
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

fiber_bundle::jcb_e13::
~jcb_e13()
{

  // Preconditions:

  // Body:

  // Postconditions:

}

const fiber_bundle::jcb_e13::volatile_type&
fiber_bundle::jcb_e13::
lite_prototype() const
{
  // Preconditions:

  // Body:

  static const volatile_type result;

  // Postconditions:

  // Exit:

  return result;
}

///
fiber_bundle::jcb_e13::volatile_type*
fiber_bundle::jcb_e13::
lite_type() const
{
  // Preconditions:

  // Body:

  volatile_type* result = new volatile_type(sheaf::row_dofs(*this));

  // Postconditions:

  // Exit:

  return result;
}

//============================================================================
// ROW DOF RELATED MEMBER FUNCTIONS
//============================================================================

void
fiber_bundle::jcb_e13::
put_components(dof_type dxdu_comp,
               dof_type dydu_comp,
               dof_type dzdu_comp)
{
  // Preconditions:

  require(state_is_read_write_accessible());

  // Body:

  (*this)[0] = dxdu_comp;
  (*this)[1] = dydu_comp;
  (*this)[2] = dzdu_comp;

  // Postconditions:

  ensure(invariant());

  ensure(isunordered_or_equals(component(0), dxdu_comp));
  ensure(isunordered_or_equals(component(1), dydu_comp));
  ensure(isunordered_or_equals(component(2), dzdu_comp));

  // Exit:

  return;
}

fiber_bundle::jcb_e13::
operator jcb_e13::row_dofs_type& ()
{
  // Preconditions:

  // Body:

  row_dofs_type& result = sheaf::row_dofs(*this);

  // Postconditions:

  // Exit:

  return result;
}

fiber_bundle::jcb_e13::
operator const jcb_e13::row_dofs_type& () const
{
  // Preconditions:

  // Body:

  const row_dofs_type& result = sheaf::row_dofs(*this);

  // Postconditions:

  // Exit:

  return result;
}

// PROTECTED MEMBER FUNCTIONS

// PRIVATE MEMBER FUNCTIONS


//============================================================================
// JCB_ED FACET OF CLASS JCB_E13
//============================================================================

// PUBLIC MEMBER FUNCTIONS

// PROTECTED MEMBER FUNCTIONS

// PRIVATE MEMBER FUNCTIONS


//============================================================================
// JCB FACET OF CLASS JCB_E13
//============================================================================

// PUBLIC MEMBER FUNCTIONS

// PROTECTED MEMBER FUNCTIONS

// PRIVATE MEMBER FUNCTIONS


//============================================================================
// VD FACET OF CLASS JCB_E13
//============================================================================

// PUBLIC MEMBER FUNCTIONS

// PROTECTED MEMBER FUNCTIONS

// PRIVATE MEMBER FUNCTIONS


//============================================================================
// TUPLE FACET OF CLASS JCB_E13
//============================================================================

// PUBLIC MEMBER FUNCTIONS

const sheaf::poset_path&
fiber_bundle::jcb_e13::
standard_schema_path()
{
  // Preconditions:


  // Body:

  static const poset_path result(standard_schema_poset_name(), "jcb_e13_schema");

  // Postconditions:

  // Exit:

  return result;
}

void
fiber_bundle::jcb_e13::
make_standard_schema(namespace_poset& xns)
{
  // Preconditions:

  require(xns.state_is_read_write_accessible());
  require(xns.contains_poset(standard_schema_poset_name()));
  require(!xns.contains_poset_member(standard_schema_path()));

  // Body:

  string lmember_names = "dxdu DOUBLE false ";
  lmember_names       += "dydu DOUBLE false ";
  lmember_names       += "dzdu DOUBLE false";

  schema_poset_member lschema(xns,
                              standard_schema_path().member_name(),
                              jcb_ed::standard_schema_path(),
                              lmember_names,
                              false);

  lschema.detach_from_state();

  // Postconditions:

  ensure(xns.contains_poset_member(standard_schema_path()));

  // Exit:

  return;
}

// PROTECTED MEMBER FUNCTIONS

// PRIVATE MEMBER FUNCTIONS


//============================================================================
// ABSTRACT POSET MEMBER FACET OF CLASS JCB_E13
//============================================================================

// PUBLIC MEMBER FUNCTIONS

const string&
fiber_bundle::jcb_e13::
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

const string&
fiber_bundle::jcb_e13::
static_class_name()
{
  // Preconditions:

  // Body:

  static const string result("jcb_e13");

  // Postconditions:

  ensure(!result.empty());

  // Exit:

  return result;
}

fiber_bundle::jcb_e13*
fiber_bundle::jcb_e13::
clone() const
{

  // Preconditions:

  // Body:

  // Create new handle of the current class.

  jcb_e13* result = new jcb_e13();

  // Postconditions:

  ensure(result != 0);
  ensure(result->invariant());

  // Exit:

  return result;

}

// PROTECTED MEMBER FUNCTIONS

// PRIVATE MEMBER FUNCTIONS


//============================================================================
// ANY FACET OF CLASS JCB_E13
//============================================================================

// PUBLIC MEMBER FUNCTIONS

bool
fiber_bundle::jcb_e13::
is_ancestor_of(const any* xother) const
{

  // Preconditions:

  require(xother != 0);

  // Body:

  // If xother may be dynamically cast to the type of this then this is an
  // ancestor of xother.

  bool result = dynamic_cast<const jcb_e13*>(xother) != 0;

  // Postconditions:

  //  ensure(invariant());

  // Exit:

  return result;

}

bool
fiber_bundle::jcb_e13::
invariant() const
{
  bool result = true;

  // Preconditions:

  // Body:

  // Must satisfy base class invariant.

  invariance(jcb_ed::invariant());

  if (invariant_check())
  {
    // Prevent recursive calls to invariant.

    disable_invariant_check();

    invariance((is_attached() ? (dr() == 3) : true));
    invariance((is_attached() ? (dd() == 1) : true));

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


//==============================================================================
// NON-MEMBER FUNCTIONS
//==============================================================================

///
void
fiber_bundle::jcb_algebra::
push(const jcb_e13& xjcb, const e1& xvector, e3& xresult, bool xauto_access)
{
  // Preconditions:

  require(xjcb.state_is_auto_read_accessible(xauto_access));
  require(xvector.state_is_auto_read_accessible(xauto_access));
  require(xresult.state_is_auto_read_write_accessible(xauto_access));
  require(xvector.d(xauto_access) == xjcb.dd(xauto_access));
  require(xresult.d(xauto_access) == xjcb.dr(xauto_access));

  ///@issue What do we want here?

  require(xvector.is_contravariant(0, xauto_access)); // !is_dual

  // Body:

  if(xauto_access)
  {
    xjcb.get_read_access();
    xvector.get_read_access();
    xresult.get_read_write_access(true);
  }

  // Left matrix multiply vector with jacobian.

  int num_rows = xjcb.dr();
  int num_cols = xjcb.dd();

  for(int i=0; i<num_rows; ++i)
  {
    vd_value_type sumi = 0.0;
    for(int j=0; j<num_cols; ++j)
    {
      vd_value_type vj = xvector.component(j);
      vd_value_type cij = xjcb.component(i, j);
      sumi += cij*vj;
    }
    xresult.put_component(i, sumi);
  }    
    
  // Make sure the result is contravariant/p_vector.

  xresult.put_is_p_vector(false);

  if(xauto_access)
  {
    xjcb.release_access();
    xvector.release_access();
    xresult.release_access();
  }

  // Postconditions:

  ensure(xresult.is_contravariant(0, xauto_access)); // !is_dual

  // Exit:
}

///
void
fiber_bundle::jcb_algebra::
push(const jcb_e13_lite& xjcb, const e1_lite& xvector, e3_lite& xresult)
{
  // Preconditions:

  require(xvector.d() == xjcb.dd());
  require(xresult.d() == xjcb.dr());

  ///@issue What do we want here?

  require(unexecutable("xvector.is_contravariant())")); // !is_dual

  // Body:

  // Left matrix multiply vector with jacobian.

  int num_rows = xjcb.dr();
  int num_cols = xjcb.dd();

  for(int i=0; i<num_rows; ++i)
  {
    vd_value_type sumi = 0.0;
    for(int j=0; j<num_cols; ++j)
    {
      vd_value_type vj = xvector.component(j);
      vd_value_type cij = xjcb.component(i, j);
      sumi += cij*vj;
    }
    xresult.put_component(i, sumi);
  }    

  // Postconditions:

  //ensure(unexecutable("???"));
  ensure(unexecutable("xresult.is_contravariant())")); // !is_dual

  // Exit:

}

///
fiber_bundle::e3_lite*
fiber_bundle::jcb_algebra::
push(const jcb_e13_lite& xjcb, const e1_lite& xvector)
{
  // Preconditions:

  require(precondition_of(push(xjcb, xvector, *result)));

  // Body:

  e3_lite* result = new e3_lite();

  push(xjcb, xvector, *result);

  // Postconditions:

  ensure(postcondition_of(push(xjcb, xvector, *result)));

  // Exit:

  return result;

}

///
void
fiber_bundle::jcb_algebra::
pull(const jcb_e13& xjcb, const e3& xcovector, e1& xresult, bool xauto_access)
{
  // Preconditions:

  require(xjcb.state_is_auto_read_accessible(xauto_access));
  require(xcovector.state_is_auto_read_accessible(xauto_access));
  require(xresult.state_is_auto_read_write_accessible(xauto_access));
  require(xcovector.d(xauto_access) == xjcb.dr(xauto_access));
  require(xresult.d(xauto_access) == xjcb.dd(xauto_access));

  ///@issue What do we want here?

  require(xcovector.is_covariant(0, xauto_access)); // is_dual

  // Body:

  if(xauto_access)
  {
    xjcb.get_read_access();
    xcovector.get_read_access();
    xresult.get_read_write_access(true);
  }

  // Right matrix multiply covector with jacobian.

  int num_rows = xjcb.dd();
  int num_cols = xjcb.dr();

  for(int i=0; i<num_rows; ++i)
  {
    vd_value_type sumi = 0.0;
    for(int j=0; j<num_cols; ++j)
    {
      vd_value_type vj = xcovector.component(j);
      vd_value_type cji = xjcb.component(j, i);
      sumi += vj*cji;
    }
    xresult.put_component(i, sumi);
  }

  // Make sure the result is covariant/p_form.

  xresult.put_is_p_form(false);


  if(xauto_access)
  {
    xjcb.release_access();
    xcovector.release_access();
    xresult.release_access();
  }

  // Postconditions:

  ensure(xresult.is_covariant(0, xauto_access));   // is_dual

  // Exit:
}

///
void
fiber_bundle::jcb_algebra::
pull(const jcb_e13_lite& xjcb, const e3_lite& xcovector, e1_lite& xresult)
{
  // Preconditions:

  require(xcovector.d() == xjcb.dr());
  require(xresult.d() == xjcb.dd());

  ///@issue What do we want here?

  require(unexecutable("xcovector.is_covariant())")); // is_dual

  // Body:

  // Right matrix multiply covector with jacobian.

  int num_rows = xjcb.dd();
  int num_cols = xjcb.dr();

  for(int i=0; i<num_rows; ++i)
  {
    vd_value_type sumi = 0.0;
    for(int j=0; j<num_cols; ++j)
    {
      vd_value_type vj = xcovector.component(j);
      vd_value_type cji = xjcb.component(j, i);
      sumi += vj*cji;
    }
    xresult.put_component(i, sumi);
  }    

  // Postconditions:

  ensure(unexecutable("xresult.is_covariant())"));   // is_dual

  // Exit:
}

///
fiber_bundle::e1_lite*
fiber_bundle::jcb_algebra::
pull(const jcb_e13_lite& xjcb, const e3_lite& xcovector)
{
  // Preconditions:

  require(precondition_of(pull(xjcb, xcovector, *result)));

  // Body:

  e1_lite* result = new e1_lite();

  pull(xjcb, xcovector, *result);

  // Postconditions:

  ensure(postcondition_of(pull(xjcb, xcovector, *result)));

  // Exit:

  return result;

}

