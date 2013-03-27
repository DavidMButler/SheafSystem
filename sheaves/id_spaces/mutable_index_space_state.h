// $RCSfile: mutable_index_space_state.h,v $ $Revision: 1.3 $ $Date: 2013/03/13 00:59:02 $

// $Name: HEAD $
//
// Copyright (c) 2011 Limit Point Systems, Inc. 
//

/// @file
/// Interface for class mutable_index_space_state.

#ifndef MUTABLE_INDEX_SPACE_STATE_H
#define MUTABLE_INDEX_SPACE_STATE_H

#ifndef SHEAF_DLL_SPEC_H
#include "sheaf_dll_spec.h"
#endif

#ifndef EXPLICIT_INDEX_SPACE_STATE_H
#include "explicit_index_space_state.h"
#endif

#ifndef LIST_POOL_H
#include "list_pool.h"
#endif

namespace sheaf
{

class mutable_index_space_handle;

///
/// An implementation class explicit_index_space_state that adds an abstract
/// mutable interface.
///
class SHEAF_DLL_SPEC mutable_index_space_state : public explicit_index_space_state
{

  // ===========================================================
  /// @name MUTABLE_INDEX_SPACE_STATE FACET
  // ===========================================================
  //@{

public:

protected:

  ///
  /// Default constructor
  ///
  mutable_index_space_state();

  ///
  /// Copy constructor; disabled.
  ///
  mutable_index_space_state(const mutable_index_space_state& xother) { };

  ///
  /// Constructor: Creates an instance from arguments xargs.
  ///
  mutable_index_space_state(const arg_list& xargs);

  ///
  /// Destructor
  ///
  virtual ~mutable_index_space_state();

private:

  //@}


  // ===========================================================
  /// @name MUTABLE INDEX SPACE FACET
  // ===========================================================
  //@{

public:

  ///
  /// Make id xid in this id space equivalent to xhub_id in the hub id space.
  /// synonym for insert(xid, xhub_id.hub_pod()).
  ///
  void insert(pod_type xid, const scoped_index& xhub_id);

  ///
  /// Make id xid in this id space equivalent to xhub_id in the hub id space.
  ///
  void insert(pod_type xid, pod_type xhub_id);

  ///
  /// Make the next id in this space equivalent to xhub_id in the hub id space.
  /// synonym for push_back(xhub_id.hub_pod()).
  ///
  void push_back(const scoped_index& xhub_id);

  ///
  /// Make the next id in this space equivalent to xhub_id in the hub id space.
  ///
  void push_back(pod_type xid);

  ///
  /// Makes id xitr.id() in this id space equivalent to xhub_id in the hub
  /// id space.  Increments all ids greater than xitr.id() by one, if any.
  /// Xitr will be set to the entry with id, xitr.id()+1.
  /// synonym for push(xitr, xhub_id.pod()).
  ///
  void push(index_space_iterator& xitr, const scoped_index& xhub_id);

  ///
  /// Makes id xitr.id() in this id space equivalent to xhub_id in the hub
  /// id space.  Increments all ids greater than xitr.id() if any by one.
  /// Xitr will be set to the entry with id, xitr.id()+1.
  ///
  void push(index_space_iterator& xitr, pod_type xhub_id);

  ///
  /// The id inserted by the next call to push_back.
  ///
  pod_type next_id() const;

  ///
  /// Removes the equivalence associated with xid.hub_pod().
  /// synonym for remove_hub(xid.hub_pod(), xupdate_extrema).
  /// Returns the number of entries actually removed, either 0 or 1.
  ///
  size_type remove(const scoped_index& xid, bool update_extrema);

  ///
  /// Removes the equivalence associated with id xid.
  /// Returns the number of entries actually removed, either 0 or 1.
  ///
  size_type remove(pod_type xid, bool update_extrema);

  ///
  /// Removes the equivalence associated with hub id xhub_id.
  /// Returns the number of entries actually removed, either 0 or 1.
  ///
  size_type remove_hub(pod_type xhub_id, bool update_extrema);

  ///
  /// Removes the equivalence associated with id xitr.pod().
  /// Increments xitr to the next entry if any.
  ///
  void remove(index_space_iterator& xitr, bool update_extrema);

  ///
  /// Gathers this id space into an interval.
  ///
  void gather();
  
  ///
  /// Update the id extrema.
  ///
  virtual void update_extrema() = 0;

  ///
  /// Reserve enough memory for xcapacity number of ids.
  ///
  virtual void reserve(size_type xcapacity) = 0;

  ///
  /// The number of ids reserved in memory.
  ///
  virtual size_type capacity() const = 0;

  ///
  /// Delete all ids.
  ///
  void clear();

protected:

private:

  //@}


  // ===========================================================
  /// @name MAP REPRESENTATION FACET
  // ===========================================================
  //@{

public:

protected:

  ///
  /// Inserts entry (xdomain_id, xrange_id) into the map representation.
  ///
  virtual void map_rep_insert_entry(pod_type xdomain_id, pod_type xrange_id) = 0;

  ///
  /// Inserts entry (next_id(), xrange_id) into the map representation.
  ///
  virtual void map_rep_push_back(pod_type xrange_id) = 0;

  ///
  /// Inserts entry (xitr.pod(), xrange_id) into the map representation.
  /// Increments all domain ids greater than xitr.pod() by one.  Sets
  /// xitr to the entry at xitr.pod()+1.
  ///
  virtual void map_rep_push(index_space_iterator& xitr, pod_type xrange_id) = 0;

  ///
  /// Removes the entry containing range id xid (xis_range_id true) or
  /// domain id xid (xis_range_id false) from the map representation;
  /// returns the number of entries actully removed, either 0 or 1.
  ///
  virtual size_type map_rep_remove_entry(pod_type xid, bool xis_range_id) = 0;

  ///
  /// Removes the equivalence associated with id xitr.pod()/
  /// Increments xitr to the next entry if any.
  ///
  virtual void map_rep_remove_entry(index_space_iterator& xitr) = 0;

  ///
  /// Removes all entrires from the map representation.
  ///
  virtual void map_rep_clear() = 0;

  ///
  /// Gathers the map representation into an interval.
  ///
  virtual void map_rep_gather() = 0;

  ///
  /// Update the extrema for the inserted id xid.
  ///
  void update_extrema(pod_type xid);

private:

  //@}


  // ===========================================================
  /// @name EXPLICIT_INDEX_SPACE_STATE FACET
  // ===========================================================
  //@{

public:

  ///
  /// True if this is equivalent to xother.
  ///
  virtual bool operator==(const explicit_index_space_state& xother) const;

protected:

  ///
  /// Assignment operator
  ///
  virtual mutable_index_space_state& operator=(const explicit_index_space_state& xother);

private:

  //@}


  // ===========================================================
  /// @name HANDLE POOL FACET
  // ===========================================================
  //@{

public:

  ///
  /// The number of handles in the pool.
  ///
  static size_type handle_pool_ct();

  ///
  /// The deep size of the handle pool.
  ///
  static size_type handle_pool_deep_size();

  ///
  /// The id space handle with this state.
  ///
  virtual index_space_handle& get_id_space() const;

  ///
  /// Release the id space handle xid_space.
  ///
  virtual void release_id_space(index_space_handle& xid_space) const;

  ///
  /// True if and only if id space handle xid_space was allocated by
  /// the handle pool.
  ///
  virtual bool allocated_id_space(const index_space_handle& xid_space) const;

protected:

private:

  ///
  /// The handle pool.
  ///
  static list_pool<mutable_index_space_handle>& handles();

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

protected:

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
/// The deep size of mutable_index_space_state& xn.
///
SHEAF_DLL_SPEC 
size_t deep_size(const mutable_index_space_state& xn, bool xinclude_shallow = true);
  
} // end namespace sheaf

#endif // ifndef MUTABLE_INDEX_SPACE_STATE_H
