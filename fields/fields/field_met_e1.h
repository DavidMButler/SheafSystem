
// $RCSfile: field_met_e1.h,v $ $Revision: 1.15 $ $Date: 2013/03/21 17:40:19 $

//
// Copyright (c) 2013 Limit Point Systems, Inc.
//

/// @file
/// Interface for class field_met_e1.
///
/// CAUTION: Normally this file should NOT be edited.  It is machine
///          generated.  If you need to make permanent changes,
///          edit the code template and rerun the generator instead.

#ifndef FIELD_MET_E1_H
#define FIELD_MET_E1_H

#ifndef SHEAF_DLL_SPEC_H
#include "sheaf_dll_spec.h"
#endif

#ifndef FIELD_MET_ED_H
#include "field_met_ed.h"
#endif

namespace fiber_bundle
{
class SHEAF_DLL_SPEC sec_ed;
class SHEAF_DLL_SPEC sec_met_e1;
class SHEAF_DLL_SPEC met_e1;
class SHEAF_DLL_SPEC met_e1_lite;
}

namespace fields
{

///
/// A property of type sec_met_e1 as a function of global coordinates.
///
class SHEAF_DLL_SPEC field_met_e1 : public field_met_ed
{
  //===========================================================================
  /// @name FIELD_VD FACET OF CLASS FIELD_MET_E1
  //===========================================================================
  //@{
public:

  /// Typedefs:

  /// The property section type.
  ///
  typedef sec_met_e1 property_section_type;

  ///
  /// The coordinates section type.
  ///
  typedef sec_ed coordinates_section_type;

  ///
  /// Default constructor.
  ///
  field_met_e1();

  ///
  /// Copy constructor.
  ///
  field_met_e1(const field_met_e1& xother, bool xauto_access);

  ///
  /// Create an instance with coordinates xcoordinates and property xproperty.
  ///
  field_met_e1(const sec_ed& xcoordinates, const sec_met_e1& xproperty,
           bool xauto_access);

  ///
  /// Create an instance with coordinates specified by xcoordinates_path
  /// and property specified by xproperty_path in name space xns.
  ///
  field_met_e1(namespace_poset& xns,
           const poset_path& xcoordinates_path,
           const poset_path& xproperty_path,
           bool xauto_access);

  ///
  /// Assignment operator.
  ///
  virtual field_met_e1& operator=(const field_vd& xother);

  ///
  /// Assignment operator.
  ///
  field_met_e1& operator=(const field_met_e1& xother);

  ///
  /// Assignment operator.
  ///
  field_met_e1& operator=(const sec_met_e1& xsection);

  ///
  /// Assignment operator.
  ///
  field_met_e1& operator=(const met_e1& xfiber);

  ///
  /// Assignment operator.
  ///
  field_met_e1& operator=(const met_e1_lite& xfiber);

  ///
  /// Destructor.
  ///
  virtual ~field_met_e1();

  ///
  /// The dependent variable of this field.
  ///
  sec_met_e1& property() const;

  ///
  /// True if this has the same property fiber as xother.
  ///
  bool same_property_fiber_schema(const field_met_e1& xother,
                                  bool xauto_access) const;

protected:

  ///
  /// Covariant constructor.
  ///
  field_met_e1(sec_met_e1* xproperty,
         sec_ed_invertible* xcoordinates,
         base_space_member* xbase_space);

private:

  //@}

  //===========================================================================
  /// @name ANY FACET OF CLASS FIELD_MET_E1
  //===========================================================================
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
  /// Conformance test; true if xother conforms to this.
  ///
  virtual bool is_ancestor_of(const any* xother) const;

  ///
  /// Virtual constructor, makes a new instance of the same type as this.
  ///
  virtual field_met_e1* clone() const;

  ///
  /// Class invariant.
  ///
  virtual bool invariant() const;

protected:
private:

  //@}
};

//=============================================================================
// NON-MEMBER FUNCTIONS OF CLASS FIELD_MET_E1
//=============================================================================

///
/// Pushes xsrc.property() to xdst.property().
///
SHEAF_DLL_SPEC
field_met_e1& operator>>(const field_met_e1& xsrc, field_met_e1& xdst);

///
/// Inserts field_met_e1 xfield into ostream xos.
///
SHEAF_DLL_SPEC
ostream& operator<<(ostream& xos, const field_met_e1& xfield);

} // namespace fields

//==============================================================================

/// Include field_vd algebra function declarations.

//...


#endif // ifndef FIELD_MET_E1_H
