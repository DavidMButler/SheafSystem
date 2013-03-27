// $RCSfile: constant_index_space_interval.h,v $ $Revision: 1.3 $ $Date: 2013/03/13 00:59:01 $

// $Name: HEAD $
//
// Copyright (c) 2011 Limit Point Systems, Inc. 
//

/// @file
/// Interface for class constant_index_space_interval

#ifndef CONSTANT_INDEX_SPACE_INTERVAL_H
#define CONSTANT_INDEX_SPACE_INTERVAL_H

#ifndef SHEAF_DLL_SPEC_H
#include "sheaf_dll_spec.h"
#endif

#ifndef FORWARDING_INDEX_SPACE_HANDLE_H
#include "forwarding_index_space_handle.h"
#endif

#ifndef INDEX_SPACE_INTERVAL_H
#include "index_space_interval.h"
#endif

#ifndef LIST_POOL_H
#include "list_pool.h"
#endif

#ifndef STD_HASH_MAP_H
#include "std_hash_map.h"
#endif

namespace sheaf
{

class constant_implicit_index_space_iterator;
class index_space_handle;

///
/// An implementation of index_space_interval for an interval of implicit
/// id spaces with a single id and in which the hub ids can be calculated
/// by an offset.
///
class SHEAF_DLL_SPEC constant_index_space_interval : public index_space_interval
{

  friend SHEAF_DLL_SPEC size_t deep_size(const constant_index_space_interval& xn, bool xinclude_shallow);

  // ===========================================================
  /// @name CONSTANT_INDEX_SPACE_INTERVAL FACET
  // ===========================================================
  //@{

public:

  ///
  /// Creates an arg list for constructing an instance of this.
  ///
  static arg_list make_arg_list(pod_type xhub_id);

  ///
  /// Destructor
  ///
  virtual ~constant_index_space_interval();

  ///
  /// The constant hub id.
  ///
  pod_type hub_id() const;

protected:

  ///
  /// Default constructor
  ///
  constant_index_space_interval();

  ///
  /// Constructor: Creates an instance from arguments, xargs.
  ///
  constant_index_space_interval(const arg_list& xargs);

  ///
  /// Copy constructor; disabled.
  ///
  constant_index_space_interval(const constant_index_space_interval& xother) { };

  ///
  /// The constant hub id.
  ///
  pod_type _hub_id;

private:

  //@}


  // ===========================================================
  /// @name INDEX_SPACE_INTERVAL FACET
  // ===========================================================
  //@{

public:

protected:

private:

  //@}


  // ===========================================================
  /// @name FACTORY FACET
  // ===========================================================
  //@}

public:

  ///
  /// The name of this class.
  ///
  virtual const string& class_name() const;

  ///
  /// Virtual constructor; create a new instance of the same type at this
  /// with arguments xargs.
  ///
  virtual constant_index_space_interval* clone(const arg_list& xargs) const;

protected:

private:

  ///
  /// True if prototype for this class has been entered in factory.
  /// Intended to force creation of prototype at initialization.
  ///
  static bool _has_prototype;

  ///
  /// Creates prototype for this class and enters in factory.
  ///
  static bool make_prototype();

  //@}


  // ===========================================================
  /// @name INDEX_SPACE_COLLECTION FACET
  // ===========================================================
  //@{

public:

  ///
  /// True if this is equivalent to xother.
  ///
  virtual bool operator==(const index_space_collection& xother) const;

  ///
  /// The deep size of this.
  ///
  virtual size_type deep_size(bool xinclude_shallow) const;

protected:

  ///
  /// Assignment operator
  ///
  virtual constant_index_space_interval& operator=(const index_space_collection& xother);

  ///
  /// The explicit id space state for id xlocal_id.
  /// Returns null if there is no explicit id space for xlocal_id.
  ///
  virtual explicit_index_space_state* explicit_state(pod_type xlocal_id) const;

private:

  //@}


  // ===========================================================
  /// @name INDEX SPACE FACET
  // ===========================================================
  //@{

public:

  ///
  /// Remove the id space with id xlocal_id.
  ///
  virtual void remove(pod_type xlocal_id);

  ///
  /// The number of members for the id space with id xlocal_id.
  ///
  virtual size_type ct(pod_type xlocal_id) const;

  using index_space_interval::begin;

  ///
  /// Beginning id of the space with id xlocal_id.
  ///
  virtual pod_type begin(pod_type xlocal_id) const;

  using index_space_interval::end;

  ///
  /// Ending id of the space with id xlocal_id.
  ///
  virtual pod_type end(pod_type xlocal_id) const;


  using index_space_interval::contains;

  ///
  /// True if the space with id xlocal_id contains id xid.
  ///
  virtual bool contains(pod_type xlocal_id, pod_type xid) const;

  ///
  /// True if the space with id xlocal_id contains an id equivalent
  /// to xid in the unglued hub id space.
  ///
  virtual bool contains_unglued_hub(pod_type xlocal_id, pod_type xid) const;

  ///
  /// True if the space with id xlocal_id contains an id xid equivalent
  /// to xhub_id in the hub id space.
  ///
  virtual bool contains(pod_type xlocal_id, pod_type xid, pod_type xhub_id) const;

  ///
  /// The pod index in the space with id xlocal_id equivalent to
  /// xid in the hub id space.
  ///
  virtual pod_type pod(pod_type xlocal_id, pod_type xid) const;

  ///
  /// The pod index in the unglued hub id space equivalent to xid in the id space
  /// with id xlocal_id.
  ///
  virtual pod_type unglued_hub_pod(pod_type xlocal_id, pod_type xid) const;

  ///
  /// True if the id space with id xlocal_id should be written to disk.
  ///
  virtual bool is_persistent(pod_type xlocal_id) const;

protected:

private:

  //@}


   // ===========================================================
  /// @name PRODUCT STRUCTURE FACET
  // ===========================================================
  //@{

public:

  ///
  /// Creates a new product structure for the id space with id xlocal_id
  /// by cloning the product structure, xproduct.
  ///
  virtual void new_product_structure(pod_type xlocal_id,
				     const abstract_product_structure& xproduct);

  ///
  /// Deletes the product structure for the id space with id xlocal_id.
  ///
  virtual void delete_product_structure(pod_type xlocal_id);

  ///
  /// The product structure for the id space with id xlocal_id (const version).
  ///
  virtual const abstract_product_structure& product_structure(pod_type xlocal_id) const;

  ///
  /// The product structure for the id space with id xlocal_id (mutable version).
  ///
  virtual abstract_product_structure& product_structure(pod_type xlocal_id);

  ///
  /// True if the id space with id xlocal_id has a product structure.
  ///
  virtual bool has_product_structure(pod_type xlocal_id) const;

protected:

private:

  //@}


 // ===========================================================
  /// @name HANDLE POOL FACET
  // ===========================================================
  //@{

public:

  ///
  /// Allocates an id space handle from the handle pool attached to state
  /// with id xlocal_id.
  ///
  virtual index_space_handle& get_id_space(pod_type xlocal_id) const;

  ///
  /// Returns the id space handle xid_space to the handle pool.
  ///
  virtual void release_id_space(index_space_handle& xid_space) const;

  ///
  /// True if and only if id space handle xid_space was allocated by
  /// the handle pool.
  ///
  virtual bool allocated_id_space(const index_space_handle& xid_space) const;

protected:

  ///
  /// The handle pool.
  ///
  mutable list_pool<forwarding_index_space_handle> _handles;

private:

  //@}


  // ===========================================================
  /// @name ITERATOR POOL FACET
  // ===========================================================
  //@{

public:

  ///
  /// Allocates an id space iterator from the iterator pool attached
  /// to state with id xlocal_id.
  ///
  virtual index_space_iterator& get_id_space_iterator(pod_type xlocal_id) const;

  ///
  /// Returns the id space iterator xitr to the iterator pool.
  ///
  virtual void release_id_space_iterator(index_space_iterator& xitr) const;

  ///
  /// True if and only if id space iterator xitr was allocated by
  /// the iterator pool.
  ///
  virtual bool allocated_id_space_iterator(const index_space_iterator& xitr) const;

protected:

  ///
  /// The iterator pool.
  ///
  mutable list_pool<constant_implicit_index_space_iterator> _iterators;

private:

  //@}


  // ===========================================================
  /// @name ANY FACET
  // ===========================================================
  //@{

public:

  ///
  /// Conformance test; true if other conforms to this
  ///
  virtual bool is_ancestor_of(const any *other) const;

  ///
  /// Class invariant.
  ///
  virtual bool invariant() const;

protected:

private:

  //@}

};

// ===========================================================
// NON-MEMBER FUNCTIONS
// ===========================================================
 
///
/// The deep size of constant_index_space_interval& xn.
///
SHEAF_DLL_SPEC 
size_t deep_size(const constant_index_space_interval& xn, bool xinclude_shallow = true);
  
} // end namespace sheaf

#endif // ifndef CONSTANT_INDEX_SPACE_INTERVAL_H
