
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

#ifndef FIELD_JCB_FUNCS_H
#define FIELD_JCB_FUNCS_H

#ifndef SHEAF_DLL_SPEC_H
#include "sheaf_dll_spec.h"
#endif

namespace fields
{

//==============================================================================
/// @name NON-MEMBER FUNCTIONS OF JCB FACET
//==============================================================================
//@{

class SHEAF_DLL_SPEC field_at1;

///
/// Namespace containing the algrebra functions for a field 
/// with a property section of type sec_jcb.
///
namespace field_jcb_algebra
{

///
/// Push vector forward (pre-allocated version).
///
void SHEAF_DLL_SPEC push(const field_jcb& xjcb, const field_at1& xvector, field_at1& xresult,
         bool xauto_access);


///
/// Pull covector back (pre-allocated version).
///
void SHEAF_DLL_SPEC pull(const field_jcb& xjcb, const field_at1& xcovector, field_at1& xresult,
          bool xauto_access);

//@}

} // namespace field_jcb_algebra

} // namespace fields

#endif // ifndef FIELD_JCB_H
