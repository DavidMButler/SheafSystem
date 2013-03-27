// $RCSfile: member_names_record.h,v $ $Revision: 1.19 $ $Date: 2013/01/12 17:17:36 $

//
// Copyright (c) 2013 Limit Point Systems, Inc.
//

// Interface for class member_names_record

#ifndef MEMBER_NAMES_RECORD_H
#define MEMBER_NAMES_RECORD_H

#ifndef SHEAF_DLL_SPEC_H
#include "sheaf_dll_spec.h"
#endif

#ifndef STD_UTILITY_H
#include "std_utility.h"
#endif

#ifndef ATTRIBUTES_RECORD_H
#include "attributes_record.h"
#endif

namespace sheaf
{

class poset_data_type_map;
  
///
/// A wrapper/adapter for the member names record.
/// Intended for transferring index-name map data
/// between the kernel and the i/o subsystem.
///
///
class SHEAF_DLL_SPEC member_names_record : public attributes_record
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
  virtual member_names_record* clone() const;

  ///
  /// Class invariant.
  ///
  virtual bool invariant() const;

  ///
  /// Conformance test; true if other conforms to this
  ///
  virtual bool is_ancestor_of(const any* other) const;


  // =============================================================================
  // MEMBER_NAMES_RECORD FACET
  // =============================================================================

  ///
  /// Creates an instance with type map xtype_map
  ///
  member_names_record(poset_scaffold& xscaffold);

  ///
  /// Copy constructor
  ///
  ///
  member_names_record(const member_names_record& xother);

  ///
  /// Destructor
  ///
  virtual ~member_names_record();

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

#endif // ifndef MEMBER_NAMES_RECORD_H






