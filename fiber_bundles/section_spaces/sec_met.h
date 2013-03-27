
// $RCSfile: sec_met.h,v $ $Revision: 1.25 $ $Date: 2013/03/13 00:58:50 $

// $Name: HEAD $
//
// Copyright (c) 2013 Limit Point Systems, Inc.
//

/// @file
/// Interface for class sec_met.

#ifndef SEC_MET_H
#define SEC_MET_H

#ifndef SHEAF_DLL_SPEC_H
#include "sheaf_dll_spec.h"
#endif

#ifndef SEC_ST2_H
#include "sec_st2.h"
#endif

#ifndef MET_H
#include "met.h"
#endif

namespace fiber_bundle
{

//==============================================================================
// CLASS SEC_MET
//==============================================================================

///
/// A section of a bundle with fiber type met.
///
class SHEAF_DLL_SPEC sec_met : public sec_st2
{
  //============================================================================
  /// @name MET FACET OF CLASS SEC_MET
  //============================================================================
  //@{

public:

  ///
  /// The fiber type.
  ///
  typedef met fiber_type;

  ///
  /// Default constructor.
  ///
  sec_met();

  ///
  /// Creates a new sec_met handle attached to the member state with hub id
  /// xhub_id in xhost.
  ///
  sec_met(const sec_rep_space* xhost, pod_index_type xhub_id);

  ///
  /// Creates a new sec_met handle attached to the member state with id
  /// xid in* xhost.
  ///
  sec_met(const sec_rep_space* xhost, const scoped_index& xid);

  ///
  /// Creates a new sec_met handle attached to the member state with name xname
  /// in* xhost.
  ///
  sec_met(const sec_rep_space* xhost, const string& xname);

  ///
  /// Creates a new handle attached to the member state
  /// with path xpath in namespace xnamespace.
  ///
  sec_met(const namespace_poset* xnamespace,
          const poset_path& xpath,
          bool xauto_access = true);

  ///
  /// Creates a new sec_met handle attached to the same state as xother.
  ///
  explicit sec_met(const sec_rep_space_member* xother);

  ///
  /// New handle/new state constructor.
  ///
  sec_met(sec_rep_space* xhost,
          section_dof_map* xdof_map = 0,
          bool xauto_access = true);

  ///
  /// Assignment operator; synonym for attach_to_state(&xother).
  ///
  virtual sec_met& operator=(const abstract_poset_member& xother);

  ///
  /// Assignment operator; synonym for attach_to_state(&xother).
  ///
  sec_met& operator=(const sec_met& xother);

  ///
  /// Assignment operator.
  ///
  sec_met& operator=(const met& xfiber);

  ///
  /// Assignment operator.
  ///
  sec_met& operator=(const met_lite& xfiber);

  ///
  /// Destructor.
  ///
  ~sec_met();

  ///
  /// Virtual constructor for the associated fiber type.
  ///
  virtual const fiber_type& fiber_prototype() const;

protected:

private:

  //@}


  //============================================================================
  /// @name ST2 FACET OF CLASS SEC_MET
  //============================================================================

public:
protected:
private:

  //============================================================================
  /// @name STP FACET OF CLASS SEC_MET
  //============================================================================
  //@{

public:

protected:

private:

  //@}


  //============================================================================
  /// @name TP FACET OF CLASS SEC_MET
  //============================================================================
  //@{

public:

protected:

private:

  //@}


  //============================================================================
  /// @name VD FACET OF CLASS SEC_MET
  //============================================================================
  //@{

public:

protected:

private:

  //@}


  //============================================================================
  /// @name TUPLE FACET OF CLASS SEC_MET
  //============================================================================
  //@{

public:

protected:

private:

  //@}


  //============================================================================
  /// @name ABSTRACT POSET MEMBER FACET OF CLASS SEC_MET
  //============================================================================
  //@{

public:

  ///
  /// The name of this class.
  ///
  virtual const string& class_name() const;

  ///
  /// The name of this class.
  ///
  static const string& static_class_name();

  ///
  /// Make a new handle, no state instance of current
  ///
  virtual sec_met* clone() const;

  ///
  /// Make a new handle instance of current.  Attach the new instance to
  /// a new state if xnew_state is true.  Otherwise, attach the new instance
  /// to the current state.
  ///
  inline sec_met* clone(bool xnew_state, bool xauto_access = true) const
  {
    return static_cast<sec_met*>(sec_st2::clone(xnew_state, xauto_access));
  }

protected:

private:

  //@}


  //============================================================================
  /// @name ANY FACET OF CLASS SEC_MET
  //============================================================================
  //@{

public:

  ///
  /// True if xother conforms to an instance of the fiber of current.
  ///
  bool fiber_is_ancestor_of(const any* xother) const;

  ///
  /// True if xother conforms to current.
  ///
  bool is_ancestor_of(const any* xother) const;

  ///
  /// Class invariant.
  ///
  bool invariant() const;

protected:

private:

  //@}


  //############################################################################

public:

//   ///
//   /// component indexed by row and col
//   ///
//   scalar_type* comp2(int row, int col);

//   ///
//   /// set component indexed by row and col
//   ///
//   void set_comp2(int row, int col, scalar_type* new_comp);


};


//==============================================================================
// NON-MEMBER FUNCTIONS
//==============================================================================

class sec_ed;

///
/// Namespace containing the algrebra functions for a a section 
/// of a fiber bundle with a fiber type met.
///
namespace sec_met_algebra
{

///
/// Lower vector (pre-allocated version).
///
SHEAF_DLL_SPEC void lower(const sec_met& xmetric, const sec_ed& xvector, sec_ed& xresult,
			  bool xauto_access);

///
/// Raise covector (pre-allocated version).
///
SHEAF_DLL_SPEC void raise(const sec_met& xmetric, const sec_ed& xcovector, sec_ed& xresult,
			  bool xauto_access);

} // namespace sec_met_algebra

} // namespace fiber_bundle

#endif // ifndef SEC_MET_H


