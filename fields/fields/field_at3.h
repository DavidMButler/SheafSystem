
//
// Copyright (c) 2014 Limit Point Systems, Inc. 
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
/// Interface for class field_at3.
///
/// CAUTION: Normally this file should NOT be edited.  It is machine
///          generated.  If you need to make permanent changes,
///          edit the code template and rerun the generator instead.

#ifndef COM_LIMITPOINT_FIELDS_FIELD_AT3_H
#define COM_LIMITPOINT_FIELDS_FIELD_AT3_H

#ifndef COM_LIMITPOINT_SHEAF_SHEAF_DLL_SPEC_H
#include "ComLimitPoint/sheaf/sheaf_dll_spec.h"
#endif

#ifndef COM_LIMITPOINT_FIELDS_FIELD_ATP_H
#include "ComLimitPoint/fields/field_atp.h"
#endif

namespace fiber_bundle
{
class SHEAF_DLL_SPEC sec_ed;
class SHEAF_DLL_SPEC sec_at3;
class SHEAF_DLL_SPEC at3;
class SHEAF_DLL_SPEC at3_lite;
}

namespace fields
{

///
/// A property of type sec_at3 as a function of global coordinates.
///
class SHEAF_DLL_SPEC field_at3 : public field_atp
{
  //===========================================================================
  /// @name FIELD_VD FACET OF CLASS FIELD_AT3
  //===========================================================================
  //@{
public:

  /// Typedefs:

  /// The property section type.
  ///
  typedef sec_at3 property_section_type;

  ///
  /// The coordinates section type.
  ///
  typedef sec_ed coordinates_section_type;

  ///
  /// Default constructor.
  ///
  field_at3();

  ///
  /// Copy constructor.
  ///
  field_at3(const field_at3& xother, bool xauto_access);

  ///
  /// Create an instance with coordinates xcoordinates and property xproperty.
  ///
  field_at3(const sec_ed& xcoordinates, const sec_at3& xproperty,
           bool xauto_access);

  ///
  /// Create an instance with coordinates specified by xcoordinates_path
  /// and property specified by xproperty_path in name space xns.
  ///
  field_at3(namespace_poset& xns,
           const poset_path& xcoordinates_path,
           const poset_path& xproperty_path,
           bool xauto_access);

  ///
  /// Assignment operator.
  ///
  virtual field_at3& operator=(const field_vd& xother);

  ///
  /// Assignment operator.
  ///
  field_at3& operator=(const field_at3& xother);

  ///
  /// Assignment operator.
  ///
  field_at3& operator=(const sec_at3& xsection);

  ///
  /// Assignment operator.
  ///
  field_at3& operator=(const at3& xfiber);

  ///
  /// Assignment operator.
  ///
  field_at3& operator=(const at3_lite& xfiber);

  ///
  /// Destructor.
  ///
  virtual ~field_at3();

  ///
  /// The dependent variable of this field.
  ///
  sec_at3& property() const;

  ///
  /// True if this has the same property fiber as xother.
  ///
  bool same_property_fiber_schema(const field_at3& xother,
                                  bool xauto_access) const;

protected:

  ///
  /// Covariant constructor.
  ///
  field_at3(sec_at3* xproperty,
         sec_ed_invertible* xcoordinates,
         base_space_member* xbase_space);

private:

  //@}

  //===========================================================================
  /// @name ANY FACET OF CLASS FIELD_AT3
  //===========================================================================
  //@{

public:

  ///
  /// The name of this class.
  ///
  virtual const std::string& class_name() const;

  ///
  /// The name of this class.
  ///
  static const std::string& static_class_name();

  ///
  /// Conformance test; true if xother conforms to this.
  ///
  virtual bool is_ancestor_of(const any* xother) const;

  ///
  /// Virtual constructor, makes a new instance of the same type as this.
  ///
  virtual field_at3* clone() const;

  ///
  /// Class invariant.
  ///
  virtual bool invariant() const;

protected:
private:

  //@}
};

//=============================================================================
// NON-MEMBER FUNCTIONS OF CLASS FIELD_AT3
//=============================================================================

///
/// Pushes xsrc.property() to xdst.property().
///
SHEAF_DLL_SPEC field_at3& operator>>(const field_at3& xsrc, field_at3& xdst);

///
/// Inserts field_at3 xfield into ostream xos.
///
SHEAF_DLL_SPEC std::ostream& operator<<(std::ostream& xos, const field_at3& xfield);

} // namespace fields

//==============================================================================

/// Include field_vd algebra function declarations.

//...


#endif // ifndef COM_LIMITPOINT_FIELDS_FIELD_AT3_H