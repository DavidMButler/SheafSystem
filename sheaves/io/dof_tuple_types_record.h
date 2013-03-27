// $RCSfile: dof_tuple_types_record.h,v $ $Revision: 1.17 $ $Date: 2013/01/12 17:17:36 $

//
// Copyright (c) 2013 Limit Point Systems, Inc.
//

// Interface for class dof_tuple_types_record

#ifndef DOF_TUPLE_TYPES_RECORD_H
#define DOF_TUPLE_TYPES_RECORD_H

#ifndef SHEAF_DLL_SPEC_H
#include "sheaf_dll_spec.h"
#endif

#ifndef ATTRIBUTES_RECORD_H
#include "attributes_record.h"
#endif

namespace sheaf
{
  
///
/// A wrapper/adapter for the dof type types record.
/// Intended for transferring dof tuple type id data
/// between the kernel and the i/o subsystem.
///
///
class SHEAF_DLL_SPEC dof_tuple_types_record : public attributes_record
{
public:

  // =============================================================================
  // ANY FACET
  // =============================================================================

  // CANONICAL MEMBERS

  ///
  /// Virtual constructor;
  /// makes a new instance of
  /// the same type as this
  ///
  virtual dof_tuple_types_record* clone() const;

  ///
  /// Class invariant.
  ///
  virtual bool invariant() const;

  ///
  /// Conformance test; true if other conforms to this
  ///
  virtual bool is_ancestor_of(const any* other) const;


  // =============================================================================
  // DOF_TUPLE_TYPES_RECORD FACET
  // =============================================================================

  ///
  /// Creates an instance with type map xtype_map
  ///
  dof_tuple_types_record(poset_scaffold& xscaffold);

  ///
  /// Copy constructor
  ///
  ///
  dof_tuple_types_record(const dof_tuple_types_record& xother);

  ///
  /// Destructor
  ///
  virtual ~dof_tuple_types_record();

protected:

  ///
  /// Initializes the poset from the internal buffer.
  ///
  void transfer_internal_buffer_to_poset();

  ///
  /// Initializes the internal buffer from the poset.
  ///
  void transfer_poset_to_internal_buffer();

};
  
} // namespace sheaf

#endif // ifndef DOF_TUPLE_TYPES_RECORD_H






