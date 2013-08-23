
//
// Copyright (c) 2013 Limit Point Systems, Inc. 
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
/// Interface for class binary_section_space_schema_poset.

#ifndef BINARY_SECTION_SPACE_SCHEMA_POSET_H
#define BINARY_SECTION_SPACE_SCHEMA_POSET_H

#ifndef SHEAF_DLL_SPEC_H
#include "sheaf_dll_spec.h"
#endif

#ifndef SECTION_SPACE_SCHEMA_POSET_H
#include "section_space_schema_poset.h"
#endif

#ifndef ARRAY_POSET_DOF_MAP_H
#include "array_poset_dof_map.h"
#endif

namespace sheaf
{
class namespace_poset;
class namespace_poset_member;
}

namespace fiber_bundle
{

class sec_rep_descriptor;

///
/// A schema poset for a section space. A binary Cartesian
/// product subspace of the binary tensor product of a
/// base space lattice and a fiber schema lattice.
/// The tensor product of two lattices B and F is the
/// finite distributive lattice generated by the poset
/// J(B) x J(F), where J(B) is the poset of jims of B
/// and similarly for J(F). The jims of the tensor product
/// are thus pairs (jB, jF) and the general member of the
/// tensor product lattice is equivalent to a subset (in
/// fact a down set) of J(B) x J(F). This class only
/// represents those members of the tensor product which
/// are equivalent to pairs (pB, pF), where pB and pF are
/// arbitrary members of B and F, respectively. Members of this Cartesian
/// product subspace of the tensor product can be represented
/// more efficiently than the general members, since we do not
/// to store the subset defines the member.
///
class SHEAF_DLL_SPEC binary_section_space_schema_poset : public section_space_schema_poset
{
  friend class fiber_bundles_namespace;
  friend class sheaf::namespace_poset; // Qualification needed by g++ 4.2.2
  
  // ===========================================================
  /// @name BINARY_SECTION_SPACE_SCHEMA_POSET FACET
  // ===========================================================
  //@{

public:

  ///
  /// Creates an arg list which conforms to the schema of this.
  ///
  static arg_list make_arg_list(const poset_path& xrep_path, 
				const poset_path& xbase_space_path, 
				const poset_path& xfiber_space_path);

  ///
  /// Creates a new handle attached to a new poset state in namespace xhost,
  /// schema specified by xschema_path,  name xname, and
  /// table dofs initialized by xargs.
  ///
  binary_section_space_schema_poset(namespace_poset& xhost,
				    const string& xname,
				    const arg_list& xargs,
				    const poset_path& xschema_path,
				    bool xauto_access);

protected:

  ///
  /// Default constructor; creates a new binary_section_space_schema_poset handle not attached to any state.
  ///
  binary_section_space_schema_poset();

  ///
  /// Copy constructor; attaches this to the same state as xother
  ///
  binary_section_space_schema_poset(const binary_section_space_schema_poset& xother);

  ///
  /// Destructor
  ///
  virtual ~binary_section_space_schema_poset();

  ///
  /// Creates a new handle attached to a new binary_section_space_schema_poset state
  /// in namespace xns with name xname, representation xrep, base xbase, and
  /// fiber space xfiber_space.
  ///
  binary_section_space_schema_poset(namespace_poset* xns,
                                    const string& xname,
                                    const sec_rep_descriptor& xrep,
                                    poset_state_handle& xbase_space,
                                    const poset_state_handle& xfiber_space,
                                    bool xauto_access = true);

  ///
  /// Creates a new handle and attaches it to a new state in namespace xns,
  /// with name xname, representation specified by xrep_path,
  /// base specified by xbase_path, and fiber space specified by xfiber_path.
  ///
  binary_section_space_schema_poset(namespace_poset& xns,
                                    const string& xname,
                                    const poset_path& xrep_path,
                                    const poset_path& xbase_path,
                                    const poset_path& xfiber_path,
                                    bool xauto_access = true);

  ///
  /// Creates a new handle attached to the binary_section_space_schema_poset with
  /// index xindex in namespace xhost.
  ///
  binary_section_space_schema_poset(const namespace_poset* xhost, pod_index_type xindex);

  ///
  /// Creates a new handle attached to the binary_section_space_schema_poset with
  /// index xindex in namespace xhost.
  ///
  binary_section_space_schema_poset(const namespace_poset* xhost, const scoped_index& xindex);

  ///
  /// Creates a new handle attached to the binary_section_space_schema_poset with
  /// name xname in namespace xhost.
  ///
  binary_section_space_schema_poset(const namespace_poset* xhost, const string& xname);

  ///
  /// Creates a new handle attached to the binary_section_space_schema_poset associated
  /// with namespace member xmbr
  ///
  binary_section_space_schema_poset(const namespace_poset_member* xmbr);

  ///
  /// Initializes xarg to satisfy class invariants.
  ///
  virtual void initialize_arg_list(const namespace_poset& xns,
				   const string& xname,
				   arg_list& xargs,
				   const poset_path& xschema_path,
				   bool xauto_access);

  ///
  /// Creates prototype for this class and enters in in factory.
  ///
  static bool make_prototype();



private:

  //@}


  // ===========================================================
  /// @name SECTION_SPACE_SCHEMA_POSET FACET
  // ===========================================================
  //@{

public:

  ///
  /// The path to the standard schema for this class.
  ///
  static const poset_path& standard_schema_path();

  ///
  /// Creates standard schema for this class in namespace xns.
  ///
  static void make_standard_schema(namespace_poset& xns);

  using section_space_schema_poset::get_index_from_components;

  ///
  /// Computes the index associated with component ids
  /// xbase_space_id, xfiber_schema_id, and xlocal_schema_id.
  ///
  virtual pod_index_type
  get_index_from_components(pod_index_type xbase_space_id,
                            pod_index_type xfiber_schema_id) const;

protected:

private:

  //@}


  // ===========================================================
  /// @name STATE FACET
  // ===========================================================
  //@{

public:

  ///
  /// Identifier for the type of this poset.
  ///
  virtual poset_type type_id() const;

  ///
  /// The name of this class.
  ///
  virtual const char* class_name() const;

protected:

  using section_space_schema_poset::new_state;

  ///
  /// Attaches this to a new binary_section_space_schema_poset state
  /// in namespace xns with name xname, representation xrep, base xbase,
  /// and fiber space xfiber_space.
  ///
  void new_state(namespace_poset* xns,
                 const string& xname,
                 const sec_rep_descriptor& xrep,
                 poset_state_handle& xbase_space,
                 const poset_state_handle& xfiber_space,
                 bool xauto_access = true);

  ///
  /// Attaches this to a new binary_section_space_schema_poset state in namespace xns with name xname,
  /// representation the member with index xrep_member_id in the poset with index xrep_poset_id,
  /// base the poset with index xbase_space_poset_id, and
  /// fiber space the poset with index xfiber_space_poset_id.
  ///
  virtual void new_state(namespace_poset* xns,
                         const string& xname,
                         pod_index_type xrep_poset_id,
                         pod_index_type xrep_member_id,
                         pod_index_type xbase_space_poset_id,
                         pod_index_type xfiber_space_poset_id,
                         bool xauto_access = true);

  ///
  /// Attaches this to a new binary_section_space_schema_poset state in namespace xns with name xname,
  /// representation the member with index xrep_member_id in the poset with index xrep_poset_id,
  /// base the poset with index xbase_space_poset_id, and
  /// fiber space the poset with index xfiber_space_poset_id.
  ///
  void new_state(namespace_poset* xns,
		 const string& xname,
		 const scoped_index& xrep_poset_id,
		 const scoped_index& xrep_member_id,
		 const scoped_index& xbase_space_poset_id,
		 const scoped_index& xfiber_space_poset_id,
		 bool xauto_access = true);

  ///
  /// Attaches this to a new state in namespace xns, with name xname,
  /// representation specified by xrep_path, base specified by xbase_path,
  /// and fiber space specified by xfiber_path.
  ///
  void new_state(namespace_poset& xns,
                 const string& xname,
                 const poset_path& xrep_path,
                 const poset_path& xbase_path,
                 const poset_path& xfiber_path,
                 bool xauto_access = true);

  ///
  /// Attaches this to a new poset state in namespace xhost,
  /// schema specified by xschema_path,  name xname, and
  /// table dofs initialized by xargs.
  ///
  void new_state(namespace_poset& xhost,
                 const string& xname,
                 const arg_list& xargs,
                 const poset_path& xschema_path,
                 bool xauto_access);

  ///
  /// Attaches this external poset to a new poset state with schema
  /// given by xschema and table dofs by xdof_map.
  /// Intended for use by i/o subsystem.
  ///
  virtual void new_state(const schema_poset_member& xschema,
                         array_poset_dof_map& xdof_map);


private:

  //@}


  // ===========================================================
  /// @name COVER RELATION FACET
  // ===========================================================
  //@{

public:

  using poset_state_handle::contains_link;

  ///
  /// True if there is a cover link between hub id xlesser and hub id xgreater
  ///
  virtual bool contains_link(pod_index_type xgreater,
			     pod_index_type xlesser) const;

  using poset_state_handle::cover_ct;

  ///
  /// The number of members in the lower cover (xlower true)
  /// or upper cover (xlower false) of the member with hub id xhub_id.
  ///
  virtual size_type cover_ct(bool xlower, pod_index_type xhub_id) const;

  using poset_state_handle::le;

  ///
  /// True if xlesser is less than or equal to hub id xgreater.
  ///
  virtual bool le(pod_index_type xgreater, pod_index_type xlesser) const;

  using poset_state_handle::leqv;

  ///
  /// True if xlesser is less than or equivalent to hub id xgreater.
  ///
  virtual bool leqv(pod_index_type xgreater, pod_index_type xlesser) const;

  using poset_state_handle::is_jem;

  ///
  /// True if xother is join equivalent to hub id xhub_id
  ///
  virtual bool is_jem(pod_index_type xhub_id, pod_index_type xother) const;

  using poset_state_handle::greatest_jem;

  ///
  /// The index of the largest member which is join-equivalent to hub id xhub_id
  ///
  virtual pod_index_type greatest_jem(pod_index_type xhub_id) const;

  using poset_state_handle::least_jem;

  ///
  /// The index of the smallest member which is join-equivalent to hub id xhub_id
  ///
  virtual pod_index_type least_jem(pod_index_type xhub_id) const;

  using poset_state_handle::merge_jems;

  ///
  /// Merge the join-equivalence class of xjem2 under that of xjem1
  ///
  virtual void merge_jems(pod_index_type xjem1, pod_index_type xjem2);

protected:

private:

  //@}


  // ===========================================================
  /// @name I/O SUPPORT FACET
  // ===========================================================
  //@{

public:

  ///
  /// Creates a member handle of the type appropriate for members of this
  /// when used as a schema. Intended for use only by the i/o subsystem.
  //// @hack the product subposet hack, version 2.
  //// This member exists only to encapsulate the hack.
  ////
  virtual schema_poset_member*
  new_schema_handle(const string& xid_space_name,
                    pod_index_type xschema_member_ext_id,
                    pod_index_type xbase_space_ext_id,
                    pod_index_type xfiber_schema_ext_id,
                    pod_index_type xlocal_schema_ext_id);

  // Note that we can not covariantly redefine the return type
  // of new_schema_handle without including binary_section_space_schema_member.h,
  // which causes a cyclic dependency between the poset and member classes.

protected:

private:

  //@}


  // ===========================================================
  /// @name ANY FACET
  // ===========================================================
  //@{

public:

  ///
  /// True if other conforms to this
  ///
  virtual bool is_ancestor_of(const any* other) const;

  ///
  /// Class invariant
  ///
  virtual bool invariant() const;

protected:

  ///
  /// Virtual constructor; creates a new handle of the same
  /// actual type as this, attached to the same state as this.
  ///
  virtual binary_section_space_schema_poset* clone() const;

  ///
  /// Assignment operator; attaches this to the same state as xother
  ///
  binary_section_space_schema_poset& operator=(const poset_state_handle& xother);

private:

  //@}
};

} // namespace fiber_bundle

#endif // BINARY_SECTION_SPACE_SCHEMA_POSET_H
