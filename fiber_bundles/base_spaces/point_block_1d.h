

//
// Copyright (c) 2013 Limit Point Systems, Inc.
//

/// @file
/// Interface for class point_block_1d

#ifndef POINT_BLOCK_1D_H
#define POINT_BLOCK_1D_H

#ifndef SHEAF_DLL_SPEC_H
#include "sheaf_dll_spec.h"
#endif

#ifndef HOMOGENEOUS_BLOCK_H
#include "homogeneous_block.h"
#endif

#ifndef CHART_POINT_1D_H
#include "chart_point_1d.h"
#endif

namespace fiber_bundle
{

using namespace sheaf;
  
  
///
/// A homogeneous collection of i_size() disconnected points;
/// similar to a structured_block_1d, but without the segments.
///
class SHEAF_DLL_SPEC point_block_1d : public homogeneous_block
{

  friend class point_block_crg_interval;

  // ===========================================================
  /// @name HOST FACTORY FACET
  // ===========================================================
  //@{

public:

  ///
  /// The path of the prototype required by this class.
  ///
  static const poset_path& static_prototype_path();

  ///
  /// Creates a new host poset for members of this type.
  /// The poset is created in namespace xns with path xhost_path and schema specified by xschema_path.
  ///
  static host_type& new_host(namespace_type& xns, 
			     const poset_path& xhost_path, 
			     const poset_path& xschema_path, 
			     bool xauto_access);

  ///
  /// Finds or creates a host poset and any prerequisite posets
  /// for members of this type. The poset is created in namespace xns with path xhost_path
  /// and schema specified by standard_schema_path().
  ///
  static host_type& standard_host(namespace_type& xns, const poset_path& xhost_path, bool xauto_access);

protected:

private:

  //@}


  // ===========================================================
  /// @name POINT_BLOCK_1D FACET
  // ===========================================================
  //@{

public:

  ///
  /// Default constructor; creates a new, unattached point_block_1d handle.
  ///
  point_block_1d();

  ///
  /// Copy constructor; creates a new point_block_1d handle.
  /// If xnew_jem is false the handle is attached to the same state as xother.
  /// If xnew_jem is true, the handle is attached to a new state which is a copy
  /// (i.e. is join equivalent to) the state of xother.
  ///
  explicit point_block_1d(const abstract_poset_member& xother,
                          bool xnew_jem = false);

  ///
  /// Destructor; deletes a poset member and its attached state, if any.
  ///
  virtual ~point_block_1d();

  // NEW HANDLE, NEW STATE CONSTRUCTORS:

  ///
  /// Creates a new handle attached to a new state in xhost, with
  /// i_size_() == xi_size.
  //// @issue xi_size argument must be precisely the right type,
  //// in particular not type int, otherwise the wrong version
  //// of the overloaded ctor will be chosen by the compiler.
  //// This near ambiguity will dissappear when relative indexing
  //// is implemented.
  ////
  point_block_1d(poset* xhost,
                 const size_type& xi_size,
                 bool xauto_access);

  // NEW HANDLE, EXISTING STATE CONSTRUCTORS:

  ///
  /// Creates a new point_block_1d handle attached to the member state
  /// with hub id xhub_id in xhost.
  ///
  point_block_1d(poset* xhost, pod_index_type xhub_id);

  ///
  /// Creates a new point_block_1d handle attached to the member state
  /// with id xid in xhost
  ///
  point_block_1d(poset* xhost, const scoped_index& xid);

  ///
  /// Creates a new point_block_1d handle attached to the member state
  /// with name xname in xhost
  ///
  point_block_1d(const poset* xhost, const string& xname);

  ///
  /// Creates a new point_block_1d handle attached to the member state
  /// specified by xpath in namespace xnamespace.
  ///
  point_block_1d(const namespace_poset* xnamespace,
                 const poset_path& xpath,
                 bool xauto_access = true);

  ///
  /// Creates a new point_block_1d handle attached to the member state
  /// with specified by xposet_id, xmember_id in namespace xnamespace.
  ///
  point_block_1d(const namespace_poset* xnamespace,
                 const scoped_index& xposet_id,
                 const scoped_index& xmember_id);

  ///
  /// Creates a new point_block_1d handle attached to the member state
  /// with specified by xposet_id, xmember_id in namespace xnamespace.
  ///
  point_block_1d(const namespace_poset* xnamespace,
                 pod_index_type xposet_id,
                 pod_index_type xmember_id);


  // EXISTING HANDLE, NEW STATE "CONSTRUCTORS":

  ///
  /// Creates a new point_block_1d state in host() with
  /// i_size() == xi_size and attaches this to it.
  /// Synonym for new_state(host(), xi_size).
  ///
  void new_state(const size_type& xi_size, bool xauto_access = true);

  ///
  /// Creates a new point_block_1d state in xhost with
  /// i_size() == xi_size and attaches this to it.
  ///
  void new_state(poset* xhost,
                 const size_type& xi_size,
                 bool xauto_access = true);

  // FEATURES:

  ///
  /// The dimension of this block; static const version.
  /// @hack Inline initialization of static const integral data 
  /// members causes link error in MSC++; use enum instead.
  ///
  enum static_const_int {DB = 0};  

  ///
  /// The number of vertices in this block;
  ///
  const size_type& i_size() const;

  ///
  /// Sets i_size() to xi_size.
  ///
  void put_i_size(const size_type& xi_size);

protected:

//   ///
//   /// The type of row dof tuple for this.
//   ///
//   struct SHEAF_DLL_SPEC row_dof_tuple_type
//   {
//     ///
//     /// The base space dimension.
//     ///
//     int db;

//     ///
//     /// The cell type id.
//     ///
//     int type_id;

//     ///
//     /// The cell type name.
//     ///
//     const char* type_name;

//     ///
//     /// The refinement depth.
//     ///
//     int refinement_depth;

//     ///
//     /// The local cell type id.
//     ///
//     int local_cell_type_id;

//     ///
//     /// The local cell type name.
//     ///
//     const char * local_cell_type_name;

//     ///
//     /// The number of local cell instances in this block.
//     ///
//     size_type size;

//     ///
//     /// The upper bound for index_0.
//     ///
//     size_type i_size;
//   };

//   ///
//   /// The row dof tuple for this.
//   ///
//   inline row_dof_tuple_type* row_dof_tuple()
//   {
//     return reinterpret_cast<row_dof_tuple_type*>(dof_map().dof_tuple());
//   }

  using homogeneous_block::new_row_dof_map;

  ///
  /// Creates a new row dof map and initializes it.
  ///
  static scoped_index new_row_dof_map(poset_state_handle& xhost,
				      size_type xi_size,
				      bool xauto_access);




private:

  //@}


  // ===========================================================
  /// @name HOMOGENEOUS_BLOCK FACET
  // ===========================================================
  //@{

public:

  ///
  /// The path of the local cell prototype required by this class.
  ///
  static const poset_path& static_local_cell_prototype_path();

protected:

private:

  //@}


  // ===========================================================
  /// @name BASE_SPACE_MEMBER FACET
  // ===========================================================
  //@{

public:

protected:

private:

  //@}


  // ===========================================================
  /// @name TOTAL_POSET_MEMBER FACET
  // ===========================================================
  //@{

public:

protected:

private:

  //@}


  // ===========================================================
  /// @name ABSTRACT_POSET_MEMBER FACET
  // ===========================================================
  //@{

public:

  ///
  /// Make a new handle, no state instance of current
  ///
  virtual point_block_1d* clone() const;

  ///
  /// Make a new handle instance of current.  Attach the new instance to
  /// a new state if xnew_state is true.  Otherwise, attach the new instance
  /// to the current state.
  ///
  inline point_block_1d* clone(bool xnew_state, bool xauto_access = true) const
  {
    return static_cast<point_block_1d*>(homogeneous_block::clone(xnew_state, xauto_access));
  }

protected:

private:

  //@}


  // ===========================================================
  /// @name ORDERING RELATION FACET
  // ===========================================================
  //@{

public:

  ///
  /// The largest member which is join-equivalent to this
  ///
  inline point_block_1d* greatest_jem() const
  {
    return static_cast<point_block_1d*>(base_space_member::greatest_jem());
  };

  ///
  /// The smallest member which is join-equivalent to this
  ///
  inline point_block_1d* least_jem() const
  {
    return static_cast<point_block_1d*>(base_space_member::least_jem());
  };

protected:

private:

  //@}


  // ===========================================================
  /// @name POSET ALGEBRA FACET
  // ===========================================================
  //@{

public:

  ///
  /// poset join of this with other, auto-, pre-, and self-allocated versions
  /// the poset join is the least upper bound in the poset
  ///
  inline point_block_1d* p_join(abstract_poset_member* other) const
  {
    return static_cast<point_block_1d*>(base_space_member::p_join(other));
  };

  ///
  /// poset meet of this with other, auto-, pre-, and self-allocated versions
  /// the poset meet is the greatest lower bound in the poset
  ///
  inline point_block_1d* p_meet(abstract_poset_member* other)
  {
    return static_cast<point_block_1d*>(base_space_member::p_meet(other));
  };

protected:

private:

  //@}


  // ===========================================================
  /// @name LATTICE ALGEBRA FACET
  // ===========================================================
  //@{

public:

  ///
  /// lattice join of this with other, auto-, pre-, and self-allocated versions
  /// the lattice join is the least upper bound in the lattice generated by the
  /// jims in the poset
  ///
  inline point_block_1d* l_join(abstract_poset_member* other, bool xnew_jem = true)
  {
    return static_cast<point_block_1d*>(base_space_member::l_join(other, xnew_jem));
  };

  ///
  /// lattice meet of this with other, auto-, pre-, and self-allocated versions
  /// the lattice meet is the greatest lower bound in the lattice generated by
  /// the jims in the poset
  ///
  inline point_block_1d* l_meet(abstract_poset_member* other, bool xnew_jem = true)
  {
    return static_cast<point_block_1d*>(base_space_member::l_meet(other, xnew_jem));
  };

  ///
  /// lattice pseudo-complement of this, auto-, pre- and self allocated versions
  /// The lattice pseudo-complement is the largest lattice member m for which
  /// this.l_meet(m) = 0
  ///
  inline point_block_1d* l_not(bool xnew_jem = true) const
  {
    return static_cast<point_block_1d*>(base_space_member::l_not(xnew_jem));
  };

protected:

private:

  //@}


  // ===========================================================
  /// @name ANY FACET
  // ===========================================================
  //@{

public:

  ///
  /// Class invariant
  ///
  virtual bool invariant() const;

  ///
  /// True if other conforms to this
  ///
  virtual bool is_ancestor_of(const any* other) const;

  ///
  /// Assignment operator; attaches this to the same state as xother
  ///
  virtual point_block_1d& operator=(const abstract_poset_member& xother);

  ///
  /// Assignment operator
  ///
  point_block_1d& operator=(const point_block_1d& xother);

protected:

private:

  //@}
};
  
} // namespace fiber_bundle

#endif // POINT_BLOCK_1D_H
