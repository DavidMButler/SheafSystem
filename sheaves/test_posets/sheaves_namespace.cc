
// $RCSfile: sheaves_namespace.cc,v $ $Revision: 1.30 $ $Date: 2013/03/13 00:59:08 $

//
// Copyright (c) 2013 Limit Point Systems, Inc.
//

// Implementation for class sheaves_namespace

#include "abstract_poset_member.h"
#include "arg_list.h"
#include "assert_contract.h"
#include "index_iterator.h"
#include "namespace_poset_member.h"
#include "poset_member_iterator.h"
#include "postorder_iterator.h"
#include "primitives_poset.h"
#include "primitives_poset_schema.h"
#include "schema_poset_member.h"
#include "sheaves_namespace.h"
#include "refinable_poset.h"

///
sheaf::poset_type
sheaf::sheaves_namespace::
type_id() const
{
  return SHEAVES_NAMESPACE_ID;
}

///
const char*
sheaf::sheaves_namespace::
class_name() const
{
  // Preconditions:


  // Body:

  static const char* result = "sheaves_namespace";

  // Postconditions:

  // Exit:

  return result;
}

///
sheaf::sheaves_namespace::
sheaves_namespace()
{
  // Preconditions:


  // Body:

  // Nothing to do.

  // Postconditions:

  // Exit:

  return;
}

///
sheaf::sheaves_namespace::
sheaves_namespace(const sheaves_namespace& xother)
    : namespace_poset(xother)
{
  // Preconditions:

  require(precondition_of(namespace_poset(xother)));

  // Body:

  // Nothing to do.

  // Postconditions

  require(postcondition_of(namespace_poset(xother)));

  // Exit:

  return;
}

///
sheaf::sheaves_namespace::
sheaves_namespace(const string& xname)
    : namespace_poset(xname)
{
  // Preconditions:

  // Pre- and poscondtions repeated here from namespace_poset::new_state
  // for convenience of Programmer's Guide tutorial.

  require(poset_path::is_valid_name(xname));

  // Body:

  // Postconditions:

  get_read_access();

  ensure(invariant());
  ensure(name() == xname);
  ensure(!in_jim_edit_mode());
  ensure(host() == 0);
  ensure(!index().is_valid());
  ensure(index().same_scope(member_hub_id_space(false)));
  ensure(has_standard_subposet_ct());
  ensure(current_namespace() == this);

  release_access();

  ensure(state_is_not_read_accessible());

  // Exit

  return;

}

///
sheaf::sheaves_namespace::
~sheaves_namespace()
{

  // Preconditions:

  require(is_attached() ? state_is_read_write_accessible() : true);

  // Body:

  // Postconditions:
}

///
void
sheaf::sheaves_namespace::
make_triangle(sheaves_namespace* xns)
{
  // Preconditions:

  require(xns != 0);

  // Body:

  // make a triangle


  //       t
  //       *
  //      ***
  //     * * *
  //    *  *  *
  //   *   *   *
  // e0    e1   e2
  // *     *     *
  // **   ***   **
  // * * * * * * *
  // *  *  *  *  *
  // * * * * * * *
  // **   ***   **
  // *     *     *
  // v0    v1   v2

  // Get read-write access to the namespace

  xns->get_read_write_access(true);

  primitives_poset& primitives = xns->primitives();

  abstract_poset_member& ref_type = primitives.int_type();

  poset& cells = xns->new_member_poset<refinable_poset>("cells",
							ref_type.path(),
							refinable_poset::make_args(),
							true);

  cells.begin_jim_edit_mode();

  total_poset_member* t  = new total_poset_member(&cells, 0, false, false);
  t->put_name("standard triangle", true, false);
  int dof = 4;
  t->put_dof_tuple(&dof,sizeof(dof));

  total_poset_member* e0 = new total_poset_member(&cells, 0, false, false);
  e0->put_name("e0", true, false);
  dof = 3;
  e0->put_dof_tuple(&dof,sizeof(dof));

  total_poset_member* e1 = new total_poset_member(&cells, 0, false, false);
  e1->put_name("e1", true, false);
  dof = 3;
  e1->put_dof_tuple(&dof,sizeof(dof));

  total_poset_member* e2 = new total_poset_member(&cells, 0, false, false);
  e2->put_name("e2", true, false);
  dof = 3;
  e2->put_dof_tuple(&dof,sizeof(dof));

  total_poset_member* v0 = new total_poset_member(&cells, 0, false, false);
  v0->put_name("v0", true, false);
  dof = 2;
  v0->put_dof_tuple(&dof,sizeof(dof));

  total_poset_member* v1 = new total_poset_member(&cells, 0, false, false);
  v1->put_name("v1", true, false);
  dof = 2;
  v1->put_dof_tuple(&dof,sizeof(dof));

  total_poset_member* v2 = new total_poset_member(&cells, 0, false, false);
  v2->put_name("v2", true, false);
  dof = 2;
  v2->put_dof_tuple(&dof,sizeof(dof));

  t->create_cover_link(e0);
  t->create_cover_link(e1);
  t->create_cover_link(e2);

  e0->create_cover_link(v0);
  e0->create_cover_link(v1);

  e1->create_cover_link(v0);
  e1->create_cover_link(v2);

  e2->create_cover_link(v1);
  e2->create_cover_link(v2);

  cells.end_jim_edit_mode();

  // Output the cells poset.

  //cout << cells << endl;

  // release access to namespace

  xns->release_access();


  // Postconditions:

  // Exit

  return;
}

// =============================================================================
// PROTECTED MEMBER FUNCTIONS
// =============================================================================

///
sheaf::sheaves_namespace::
sheaves_namespace(namespace_poset_member* xtop, namespace_poset_member* xbottom)
    :  namespace_poset(xtop, xbottom)
{
  // Preconditions:

  require(precondition_of(namespace_poset(xtop, xbottom)));

  // Body:

  // Nothing to do.

  // Postconditions:

  ensure(postcondition_of(namespace_poset(xtop, xbottom)));

  // Exit:

  return;
}

