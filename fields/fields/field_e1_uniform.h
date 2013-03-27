
// $RCSfile: field_e1_uniform.h,v $ $Revision: 1.15 $ $Date: 2013/03/21 17:40:18 $

//
// Copyright (c) 2013 Limit Point Systems, Inc.
//

/// @file
/// Interface for class field_e1_uniform.
///
/// CAUTION: Normally this file should NOT be edited.  It is machine
///          generated.  If you need to make permanent changes,
///          edit the code template and rerun the generator instead.

#ifndef FIELD_E1_UNIFORM_H
#define FIELD_E1_UNIFORM_H

#ifndef SHEAF_DLL_SPEC_H
#include "sheaf_dll_spec.h"
#endif

#ifndef FIELD_E1_H
#include "field_e1.h"
#endif

namespace fiber_bundle
{
class SHEAF_DLL_SPEC sec_ed;
class SHEAF_DLL_SPEC sec_e1_uniform;
class SHEAF_DLL_SPEC e1;
class SHEAF_DLL_SPEC e1_lite;
}

namespace fields
{

///
/// A property of type sec_e1_uniform as a function of global coordinates.
///
class SHEAF_DLL_SPEC field_e1_uniform : public field_e1
{
  //===========================================================================
  /// @name FIELD_VD FACET OF CLASS FIELD_E1_UNIFORM
  //===========================================================================
  //@{
public:

  /// Typedefs:

  /// The property section type.
  ///
  typedef sec_e1_uniform property_section_type;

  ///
  /// The coordinates section type.
  ///
  typedef sec_ed coordinates_section_type;

  ///
  /// Default constructor.
  ///
  field_e1_uniform();

  ///
  /// Copy constructor.
  ///
  field_e1_uniform(const field_e1_uniform& xother, bool xauto_access);

  ///
  /// Create an instance with coordinates xcoordinates and property xproperty.
  ///
  field_e1_uniform(const sec_ed& xcoordinates, const sec_e1_uniform& xproperty,
           bool xauto_access);

  ///
  /// Create an instance with coordinates specified by xcoordinates_path
  /// and property specified by xproperty_path in name space xns.
  ///
  field_e1_uniform(namespace_poset& xns,
           const poset_path& xcoordinates_path,
           const poset_path& xproperty_path,
           bool xauto_access);

  ///
  /// Assignment operator.
  ///
  virtual field_e1_uniform& operator=(const field_vd& xother);

  ///
  /// Assignment operator.
  ///
  field_e1_uniform& operator=(const field_e1_uniform& xother);

  ///
  /// Assignment operator.
  ///
  field_e1_uniform& operator=(const sec_e1_uniform& xsection);

  ///
  /// Assignment operator.
  ///
  field_e1_uniform& operator=(const e1& xfiber);

  ///
  /// Assignment operator.
  ///
  field_e1_uniform& operator=(const e1_lite& xfiber);

  ///
  /// Destructor.
  ///
  virtual ~field_e1_uniform();

  ///
  /// The dependent variable of this field.
  ///
  sec_e1_uniform& property() const;

  ///
  /// True if this has the same property fiber as xother.
  ///
  bool same_property_fiber_schema(const field_e1_uniform& xother,
                                  bool xauto_access) const;

protected:

  ///
  /// Covariant constructor.
  ///
  field_e1_uniform(sec_e1_uniform* xproperty,
         sec_ed_invertible* xcoordinates,
         base_space_member* xbase_space);

private:

  //@}

  //===========================================================================
  /// @name ANY FACET OF CLASS FIELD_E1_UNIFORM
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
  virtual field_e1_uniform* clone() const;

  ///
  /// Class invariant.
  ///
  virtual bool invariant() const;

protected:
private:

  //@}
};

//=============================================================================
// NON-MEMBER FUNCTIONS OF CLASS FIELD_E1_UNIFORM
//=============================================================================

///
/// Pushes xsrc.property() to xdst.property().
///
SHEAF_DLL_SPEC
field_e1_uniform& operator>>(const field_e1_uniform& xsrc, field_e1_uniform& xdst);

///
/// Inserts field_e1_uniform xfield into ostream xos.
///
SHEAF_DLL_SPEC
ostream& operator<<(ostream& xos, const field_e1_uniform& xfield);

} // namespace fields

//==============================================================================

/// Include field_vd algebra function declarations.

//...


#endif // ifndef FIELD_E1_UNIFORM_H
