
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

// Interface for class sheaf_namespace

#ifndef COM_LIMITPOINT_SHEAF_SHEAF_NAMESPACE_H
#define COM_LIMITPOINT_SHEAF_SHEAF_NAMESPACE_H

#ifndef COM_LIMITPOINT_SHEAF_SHEAF_DLL_SPEC_H
#include "ComLimitPoint/sheaf/sheaf_dll_spec.h"
#endif

#ifndef COM_LIMITPOINT_SHEAF_NAMESPACE_POSET_H
#include "ComLimitPoint/sheaf/namespace_poset.h"
#endif

namespace sheaf
{
  
///
/// The standard sheaves name space.
///
class SHEAF_DLL_SPEC sheaf_namespace : public namespace_poset
{

  // ===========================================================
  /// @name sheaf_namespace FACET
  // ===========================================================
  //@{

public:

  ///
  /// Creates a sheaves namespace with name xname.
  ///
  sheaf_namespace(const std::string& xname);

  ///
  /// Destructor
  ///
  virtual ~sheaf_namespace();

  ///
  /// Creates a triangle schema using the primatives poset;
  /// used for test drivers.
  ///
  static void make_triangle(sheaf_namespace* xns);

protected:

  ///
  /// Default constructor; creates an unattached handle.
  ///
  sheaf_namespace();

  ///
  /// Covariant constructor.
  ///
  sheaf_namespace(namespace_poset_member* xtop, namespace_poset_member* xbottom);

  ///
  /// Copy constructor; disabled.
  ///
  sheaf_namespace(const sheaf_namespace& xother) { };

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

private:

  //@}    

};
  
} // namespace sheaf

#endif // ifndef COM_LIMITPOINT_SHEAF_SHEAF_NAMESPACE_H
