
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

// Explicit instantiations for class binary_section_space_schema_member.

#include "binary_section_space_schema_member.impl.h"

#include "ComLimitPoint/fiber_bundle/at0.h"
#include "ComLimitPoint/fiber_bundle/at0_space.h"
#include "ComLimitPoint/fiber_bundle/at1.h"
#include "ComLimitPoint/fiber_bundle/at1_space.h"
#include "ComLimitPoint/fiber_bundle/at2.h"
#include "ComLimitPoint/fiber_bundle/at2_e2.h"
#include "ComLimitPoint/fiber_bundle/at2_e3.h"
#include "ComLimitPoint/fiber_bundle/at3.h"
#include "ComLimitPoint/fiber_bundle/at3_e3.h"
#include "ComLimitPoint/fiber_bundle/atp.h"
#include "ComLimitPoint/fiber_bundle/atp_space.h"
#include "ComLimitPoint/fiber_bundle/e1.h"
#include "ComLimitPoint/fiber_bundle/e2.h"
#include "ComLimitPoint/fiber_bundle/e3.h"
#include "ComLimitPoint/fiber_bundle/e4.h"
#include "ComLimitPoint/fiber_bundle/ed.h"
#include "ComLimitPoint/fiber_bundle/jcb.h"
#include "ComLimitPoint/fiber_bundle/jcb_e13.h"
#include "ComLimitPoint/fiber_bundle/jcb_e23.h"
#include "ComLimitPoint/fiber_bundle/jcb_e33.h"
#include "ComLimitPoint/fiber_bundle/jcb_ed.h"
#include "ComLimitPoint/fiber_bundle/jcb_space.h"
#include "ComLimitPoint/fiber_bundle/met.h"
#include "ComLimitPoint/fiber_bundle/met_e1.h"
#include "ComLimitPoint/fiber_bundle/met_e2.h"
#include "ComLimitPoint/fiber_bundle/met_e3.h"
#include "ComLimitPoint/fiber_bundle/met_ed.h"
#include "ComLimitPoint/fiber_bundle/st2.h"
#include "ComLimitPoint/fiber_bundle/st2_e2.h"
#include "ComLimitPoint/fiber_bundle/st2_e3.h"
#include "ComLimitPoint/fiber_bundle/st3.h"
#include "ComLimitPoint/fiber_bundle/st3_e3.h"
#include "ComLimitPoint/fiber_bundle/st4.h"
#include "ComLimitPoint/fiber_bundle/st4_e2.h"
#include "ComLimitPoint/fiber_bundle/st4_e3.h"
#include "ComLimitPoint/fiber_bundle/stp.h"
#include "ComLimitPoint/fiber_bundle/stp_space.h"
#include "ComLimitPoint/fiber_bundle/t2.h"
#include "ComLimitPoint/fiber_bundle/t2_e2.h"
#include "ComLimitPoint/fiber_bundle/t2_e3.h"
#include "ComLimitPoint/fiber_bundle/t3.h"
#include "ComLimitPoint/fiber_bundle/t3_e3.h"
#include "ComLimitPoint/fiber_bundle/t4.h"
#include "ComLimitPoint/fiber_bundle/t4_e2.h"
#include "ComLimitPoint/fiber_bundle/t4_e3.h"
#include "ComLimitPoint/fiber_bundle/tp.h"
#include "ComLimitPoint/fiber_bundle/tp_space.h"
#include "ComLimitPoint/fiber_bundle/tuple.h"
#include "ComLimitPoint/fiber_bundle/tuple_space.h"
#include "ComLimitPoint/fiber_bundle/vd.h"
#include "ComLimitPoint/fiber_bundle/vd_space.h"

#include "sec_at0.h"
#include "sec_at0_space.h"
#include "sec_at1.h"
#include "sec_at1_space.h"
#include "sec_at2.h"
#include "sec_at2_e2.h"
#include "sec_at2_e3.h"
#include "sec_at3.h"
#include "sec_at3_e3.h"
#include "sec_atp.h"
#include "sec_atp_space.h"
#include "sec_e1.h"
#include "sec_e1_uniform.h"
#include "sec_e2.h"
#include "sec_e2_uniform.h"
#include "sec_e3.h"
#include "sec_e3_uniform.h"
#include "sec_e4.h"
#include "sec_ed.h"
#include "sec_jcb.h"
#include "sec_jcb_e13.h"
#include "sec_jcb_e23.h"
#include "sec_jcb_e33.h"
#include "sec_jcb_ed.h"
#include "ComLimitPoint/fiber_bundle/sec_jcb_space.h"
#include "sec_met.h"
#include "sec_met_e1.h"
#include "sec_met_e2.h"
#include "sec_met_e3.h"
#include "sec_met_ed.h"
#include "ComLimitPoint/fiber_bundle/sec_rep_descriptor.h"
#include "ComLimitPoint/fiber_bundle/sec_rep_descriptor_poset.h"
#include "sec_rep_descriptor_table_dofs_type.h"
#include "ComLimitPoint/fiber_bundle/sec_rep_space.h"
#include "sec_rep_space_member.h"
#include "sec_st2.h"
#include "sec_st2_e2.h"
#include "sec_st2_e3.h"
#include "sec_st3.h"
#include "sec_st3_e3.h"
#include "sec_st4.h"
#include "sec_st4_e2.h"
#include "sec_st4_e3.h"
#include "sec_stp.h"
#include "ComLimitPoint/fiber_bundle/sec_stp_space.h"
#include "sec_t2.h"
#include "sec_t2_e2.h"
#include "sec_t2_e3.h"
#include "sec_t3.h"
#include "sec_t3_e3.h"
#include "sec_t4.h"
#include "sec_t4_e2.h"
#include "sec_t4_e3.h"
#include "sec_tp.h"
#include "sec_tp_space.h"
#include "sec_tuple.h"
#include "sec_tuple_space.h"
#include "ComLimitPoint/fiber_bundle/sec_vd.h"
#include "ComLimitPoint/fiber_bundle/sec_vd_space.h"

using namespace std;

//==============================================================================
// EXPLICIT INSTANTIATIONS
//==============================================================================

//
// sec_at0
//

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_host_path<fiber_bundle::sec_at0>(const poset_path& xbase_path,
                                       const poset_path& xrep_path,
                                       const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member_path<fiber_bundle::sec_at0>(const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
bool
fiber_bundle::binary_section_space_schema_member::
standard_host_is_available<fiber_bundle::sec_at0>(namespace_poset& xns,
                                         const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix,
                                         bool xauto_access);


template
SHEAF_DLL_SPEC
fiber_bundle::binary_section_space_schema_member::host_type&
fiber_bundle::binary_section_space_schema_member::
standard_host<fiber_bundle::sec_at0>(namespace_type& xns,
                                  const poset_path& xbase_path,
                                  const poset_path& xrep_path,
                                  const string& xfiber_suffix,
                                  bool xauto_access);

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member<fiber_bundle::sec_at0>(namespace_type& xns,
                                    const poset_path& xbase_path,
                                    const poset_path& xrep_path,
                                    const string& xfiber_suffix,
                                    bool xauto_access);

//
// sec_at2_e2
//

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_host_path<fiber_bundle::sec_at2_e2>(const poset_path& xbase_path,
                                       const poset_path& xrep_path,
                                       const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member_path<fiber_bundle::sec_at2_e2>(const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
bool
fiber_bundle::binary_section_space_schema_member::
standard_host_is_available<fiber_bundle::sec_at2_e2>(namespace_poset& xns,
                                         const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix,
                                         bool xauto_access);


template
SHEAF_DLL_SPEC
fiber_bundle::binary_section_space_schema_member::host_type&
fiber_bundle::binary_section_space_schema_member::
standard_host<fiber_bundle::sec_at2_e2>(namespace_type& xns,
                                  const poset_path& xbase_path,
                                  const poset_path& xrep_path,
                                  const string& xfiber_suffix,
                                  bool xauto_access);

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member<fiber_bundle::sec_at2_e2>(namespace_type& xns,
                                    const poset_path& xbase_path,
                                    const poset_path& xrep_path,
                                    const string& xfiber_suffix,
                                    bool xauto_access);

//
// sec_at2_e3
//

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_host_path<fiber_bundle::sec_at2_e3>(const poset_path& xbase_path,
                                       const poset_path& xrep_path,
                                       const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member_path<fiber_bundle::sec_at2_e3>(const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
bool
fiber_bundle::binary_section_space_schema_member::
standard_host_is_available<fiber_bundle::sec_at2_e3>(namespace_poset& xns,
                                         const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix,
                                         bool xauto_access);


template
SHEAF_DLL_SPEC
fiber_bundle::binary_section_space_schema_member::host_type&
fiber_bundle::binary_section_space_schema_member::
standard_host<fiber_bundle::sec_at2_e3>(namespace_type& xns,
                                  const poset_path& xbase_path,
                                  const poset_path& xrep_path,
                                  const string& xfiber_suffix,
                                  bool xauto_access);

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member<fiber_bundle::sec_at2_e3>(namespace_type& xns,
                                    const poset_path& xbase_path,
                                    const poset_path& xrep_path,
                                    const string& xfiber_suffix,
                                    bool xauto_access);

//
// sec_at3_e3
//

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_host_path<fiber_bundle::sec_at3_e3>(const poset_path& xbase_path,
                                       const poset_path& xrep_path,
                                       const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member_path<fiber_bundle::sec_at3_e3>(const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
bool
fiber_bundle::binary_section_space_schema_member::
standard_host_is_available<fiber_bundle::sec_at3_e3>(namespace_poset& xns,
                                         const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix,
                                         bool xauto_access);


template
SHEAF_DLL_SPEC
fiber_bundle::binary_section_space_schema_member::host_type&
fiber_bundle::binary_section_space_schema_member::
standard_host<fiber_bundle::sec_at3_e3>(namespace_type& xns,
                                  const poset_path& xbase_path,
                                  const poset_path& xrep_path,
                                  const string& xfiber_suffix,
                                  bool xauto_access);

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member<fiber_bundle::sec_at3_e3>(namespace_type& xns,
                                    const poset_path& xbase_path,
                                    const poset_path& xrep_path,
                                    const string& xfiber_suffix,
                                    bool xauto_access);

//
// sec_e1
//

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_host_path<fiber_bundle::sec_e1>(const poset_path& xbase_path,
                                       const poset_path& xrep_path,
                                       const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member_path<fiber_bundle::sec_e1>(const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
bool
fiber_bundle::binary_section_space_schema_member::
standard_host_is_available<fiber_bundle::sec_e1>(namespace_poset& xns,
                                         const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix,
                                         bool xauto_access);


template
SHEAF_DLL_SPEC
fiber_bundle::binary_section_space_schema_member::host_type&
fiber_bundle::binary_section_space_schema_member::
standard_host<fiber_bundle::sec_e1>(namespace_type& xns,
                                  const poset_path& xbase_path,
                                  const poset_path& xrep_path,
                                  const string& xfiber_suffix,
                                  bool xauto_access);

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member<fiber_bundle::sec_e1>(namespace_type& xns,
                                    const poset_path& xbase_path,
                                    const poset_path& xrep_path,
                                    const string& xfiber_suffix,
                                    bool xauto_access);

//
// sec_e1_uniform
//

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_host_path<fiber_bundle::sec_e1_uniform>(const poset_path& xbase_path,
                                       const poset_path& xrep_path,
                                       const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member_path<fiber_bundle::sec_e1_uniform>(const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
bool
fiber_bundle::binary_section_space_schema_member::
standard_host_is_available<fiber_bundle::sec_e1_uniform>(namespace_poset& xns,
                                         const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix,
                                         bool xauto_access);


template
SHEAF_DLL_SPEC
fiber_bundle::binary_section_space_schema_member::host_type&
fiber_bundle::binary_section_space_schema_member::
standard_host<fiber_bundle::sec_e1_uniform>(namespace_type& xns,
                                  const poset_path& xbase_path,
                                  const poset_path& xrep_path,
                                  const string& xfiber_suffix,
                                  bool xauto_access);

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member<fiber_bundle::sec_e1_uniform>(namespace_type& xns,
                                    const poset_path& xbase_path,
                                    const poset_path& xrep_path,
                                    const string& xfiber_suffix,
                                    bool xauto_access);

//
// sec_e2
//

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_host_path<fiber_bundle::sec_e2>(const poset_path& xbase_path,
                                       const poset_path& xrep_path,
                                       const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member_path<fiber_bundle::sec_e2>(const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
bool
fiber_bundle::binary_section_space_schema_member::
standard_host_is_available<fiber_bundle::sec_e2>(namespace_poset& xns,
                                         const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix,
                                         bool xauto_access);


template
SHEAF_DLL_SPEC
fiber_bundle::binary_section_space_schema_member::host_type&
fiber_bundle::binary_section_space_schema_member::
standard_host<fiber_bundle::sec_e2>(namespace_type& xns,
                                  const poset_path& xbase_path,
                                  const poset_path& xrep_path,
                                  const string& xfiber_suffix,
                                  bool xauto_access);

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member<fiber_bundle::sec_e2>(namespace_type& xns,
                                    const poset_path& xbase_path,
                                    const poset_path& xrep_path,
                                    const string& xfiber_suffix,
                                    bool xauto_access);

//
// sec_e2_uniform
//

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_host_path<fiber_bundle::sec_e2_uniform>(const poset_path& xbase_path,
                                       const poset_path& xrep_path,
                                       const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member_path<fiber_bundle::sec_e2_uniform>(const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
bool
fiber_bundle::binary_section_space_schema_member::
standard_host_is_available<fiber_bundle::sec_e2_uniform>(namespace_poset& xns,
                                         const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix,
                                         bool xauto_access);


template
SHEAF_DLL_SPEC
fiber_bundle::binary_section_space_schema_member::host_type&
fiber_bundle::binary_section_space_schema_member::
standard_host<fiber_bundle::sec_e2_uniform>(namespace_type& xns,
                                  const poset_path& xbase_path,
                                  const poset_path& xrep_path,
                                  const string& xfiber_suffix,
                                  bool xauto_access);

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member<fiber_bundle::sec_e2_uniform>(namespace_type& xns,
                                    const poset_path& xbase_path,
                                    const poset_path& xrep_path,
                                    const string& xfiber_suffix,
                                    bool xauto_access);

//
// sec_e3
//

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_host_path<fiber_bundle::sec_e3>(const poset_path& xbase_path,
                                       const poset_path& xrep_path,
                                       const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member_path<fiber_bundle::sec_e3>(const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
bool
fiber_bundle::binary_section_space_schema_member::
standard_host_is_available<fiber_bundle::sec_e3>(namespace_poset& xns,
                                         const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix,
                                         bool xauto_access);


template
SHEAF_DLL_SPEC
fiber_bundle::binary_section_space_schema_member::host_type&
fiber_bundle::binary_section_space_schema_member::
standard_host<fiber_bundle::sec_e3>(namespace_type& xns,
                                  const poset_path& xbase_path,
                                  const poset_path& xrep_path,
                                  const string& xfiber_suffix,
                                  bool xauto_access);

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member<fiber_bundle::sec_e3>(namespace_type& xns,
                                    const poset_path& xbase_path,
                                    const poset_path& xrep_path,
                                    const string& xfiber_suffix,
                                    bool xauto_access);

//
// sec_e3_uniform
//

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_host_path<fiber_bundle::sec_e3_uniform>(const poset_path& xbase_path,
                                       const poset_path& xrep_path,
                                       const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member_path<fiber_bundle::sec_e3_uniform>(const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
bool
fiber_bundle::binary_section_space_schema_member::
standard_host_is_available<fiber_bundle::sec_e3_uniform>(namespace_poset& xns,
                                         const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix,
                                         bool xauto_access);


template
SHEAF_DLL_SPEC
fiber_bundle::binary_section_space_schema_member::host_type&
fiber_bundle::binary_section_space_schema_member::
standard_host<fiber_bundle::sec_e3_uniform>(namespace_type& xns,
                                  const poset_path& xbase_path,
                                  const poset_path& xrep_path,
                                  const string& xfiber_suffix,
                                  bool xauto_access);

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member<fiber_bundle::sec_e3_uniform>(namespace_type& xns,
                                    const poset_path& xbase_path,
                                    const poset_path& xrep_path,
                                    const string& xfiber_suffix,
                                    bool xauto_access);

//
// sec_e4
//

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_host_path<fiber_bundle::sec_e4>(const poset_path& xbase_path,
                                       const poset_path& xrep_path,
                                       const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member_path<fiber_bundle::sec_e4>(const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
bool
fiber_bundle::binary_section_space_schema_member::
standard_host_is_available<fiber_bundle::sec_e4>(namespace_poset& xns,
                                         const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix,
                                         bool xauto_access);


template
SHEAF_DLL_SPEC
fiber_bundle::binary_section_space_schema_member::host_type&
fiber_bundle::binary_section_space_schema_member::
standard_host<fiber_bundle::sec_e4>(namespace_type& xns,
                                  const poset_path& xbase_path,
                                  const poset_path& xrep_path,
                                  const string& xfiber_suffix,
                                  bool xauto_access);

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member<fiber_bundle::sec_e4>(namespace_type& xns,
                                    const poset_path& xbase_path,
                                    const poset_path& xrep_path,
                                    const string& xfiber_suffix,
                                    bool xauto_access);

//
// sec_jcb_e13
//

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_host_path<fiber_bundle::sec_jcb_e13>(const poset_path& xbase_path,
                                       const poset_path& xrep_path,
                                       const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member_path<fiber_bundle::sec_jcb_e13>(const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
bool
fiber_bundle::binary_section_space_schema_member::
standard_host_is_available<fiber_bundle::sec_jcb_e13>(namespace_poset& xns,
                                         const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix,
                                         bool xauto_access);


template
SHEAF_DLL_SPEC
fiber_bundle::binary_section_space_schema_member::host_type&
fiber_bundle::binary_section_space_schema_member::
standard_host<fiber_bundle::sec_jcb_e13>(namespace_type& xns,
                                  const poset_path& xbase_path,
                                  const poset_path& xrep_path,
                                  const string& xfiber_suffix,
                                  bool xauto_access);

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member<fiber_bundle::sec_jcb_e13>(namespace_type& xns,
                                    const poset_path& xbase_path,
                                    const poset_path& xrep_path,
                                    const string& xfiber_suffix,
                                    bool xauto_access);

//
// sec_jcb_e23
//

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_host_path<fiber_bundle::sec_jcb_e23>(const poset_path& xbase_path,
                                       const poset_path& xrep_path,
                                       const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member_path<fiber_bundle::sec_jcb_e23>(const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
bool
fiber_bundle::binary_section_space_schema_member::
standard_host_is_available<fiber_bundle::sec_jcb_e23>(namespace_poset& xns,
                                         const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix,
                                         bool xauto_access);


template
SHEAF_DLL_SPEC
fiber_bundle::binary_section_space_schema_member::host_type&
fiber_bundle::binary_section_space_schema_member::
standard_host<fiber_bundle::sec_jcb_e23>(namespace_type& xns,
                                  const poset_path& xbase_path,
                                  const poset_path& xrep_path,
                                  const string& xfiber_suffix,
                                  bool xauto_access);

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member<fiber_bundle::sec_jcb_e23>(namespace_type& xns,
                                    const poset_path& xbase_path,
                                    const poset_path& xrep_path,
                                    const string& xfiber_suffix,
                                    bool xauto_access);

//
// sec_jcb_e33
//

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_host_path<fiber_bundle::sec_jcb_e33>(const poset_path& xbase_path,
                                       const poset_path& xrep_path,
                                       const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member_path<fiber_bundle::sec_jcb_e33>(const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
bool
fiber_bundle::binary_section_space_schema_member::
standard_host_is_available<fiber_bundle::sec_jcb_e33>(namespace_poset& xns,
                                         const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix,
                                         bool xauto_access);


template
SHEAF_DLL_SPEC
fiber_bundle::binary_section_space_schema_member::host_type&
fiber_bundle::binary_section_space_schema_member::
standard_host<fiber_bundle::sec_jcb_e33>(namespace_type& xns,
                                  const poset_path& xbase_path,
                                  const poset_path& xrep_path,
                                  const string& xfiber_suffix,
                                  bool xauto_access);

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member<fiber_bundle::sec_jcb_e33>(namespace_type& xns,
                                    const poset_path& xbase_path,
                                    const poset_path& xrep_path,
                                    const string& xfiber_suffix,
                                    bool xauto_access);


//
// sec_met_e1
//

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_host_path<fiber_bundle::sec_met_e1>(const poset_path& xbase_path,
                                       const poset_path& xrep_path,
                                       const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member_path<fiber_bundle::sec_met_e1>(const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
bool
fiber_bundle::binary_section_space_schema_member::
standard_host_is_available<fiber_bundle::sec_met_e1>(namespace_poset& xns,
                                         const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix,
                                         bool xauto_access);


template
SHEAF_DLL_SPEC
fiber_bundle::binary_section_space_schema_member::host_type&
fiber_bundle::binary_section_space_schema_member::
standard_host<fiber_bundle::sec_met_e1>(namespace_type& xns,
                                  const poset_path& xbase_path,
                                  const poset_path& xrep_path,
                                  const string& xfiber_suffix,
                                  bool xauto_access);

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member<fiber_bundle::sec_met_e1>(namespace_type& xns,
                                    const poset_path& xbase_path,
                                    const poset_path& xrep_path,
                                    const string& xfiber_suffix,
                                    bool xauto_access);

//
//  sec_met_e2
//

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_host_path<fiber_bundle::sec_met_e2>(const poset_path& xbase_path,
                                       const poset_path& xrep_path,
                                       const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member_path<fiber_bundle::sec_met_e2>(const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
bool
fiber_bundle::binary_section_space_schema_member::
standard_host_is_available<fiber_bundle::sec_met_e2>(namespace_poset& xns,
                                         const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix,
                                         bool xauto_access);


template
SHEAF_DLL_SPEC
fiber_bundle::binary_section_space_schema_member::host_type&
fiber_bundle::binary_section_space_schema_member::
standard_host<fiber_bundle::sec_met_e2>(namespace_type& xns,
                                  const poset_path& xbase_path,
                                  const poset_path& xrep_path,
                                  const string& xfiber_suffix,
                                  bool xauto_access);

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member<fiber_bundle::sec_met_e2>(namespace_type& xns,
                                    const poset_path& xbase_path,
                                    const poset_path& xrep_path,
                                    const string& xfiber_suffix,
                                    bool xauto_access);

//
//  sec_met_e3
//

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_host_path<fiber_bundle::sec_met_e3>(const poset_path& xbase_path,
                                       const poset_path& xrep_path,
                                       const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member_path<fiber_bundle::sec_met_e3>(const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
bool
fiber_bundle::binary_section_space_schema_member::
standard_host_is_available<fiber_bundle::sec_met_e3>(namespace_poset& xns,
                                         const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix,
                                         bool xauto_access);


template
SHEAF_DLL_SPEC
fiber_bundle::binary_section_space_schema_member::host_type&
fiber_bundle::binary_section_space_schema_member::
standard_host<fiber_bundle::sec_met_e3>(namespace_type& xns,
                                  const poset_path& xbase_path,
                                  const poset_path& xrep_path,
                                  const string& xfiber_suffix,
                                  bool xauto_access);

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member<fiber_bundle::sec_met_e3>(namespace_type& xns,
                                    const poset_path& xbase_path,
                                    const poset_path& xrep_path,
                                    const string& xfiber_suffix,
                                    bool xauto_access);

//
// sec_st2_e2
//

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_host_path<fiber_bundle::sec_st2_e2>(const poset_path& xbase_path,
                                       const poset_path& xrep_path,
                                       const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member_path<fiber_bundle::sec_st2_e2>(const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
bool
fiber_bundle::binary_section_space_schema_member::
standard_host_is_available<fiber_bundle::sec_st2_e2>(namespace_poset& xns,
                                         const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix,
                                         bool xauto_access);


template
SHEAF_DLL_SPEC
fiber_bundle::binary_section_space_schema_member::host_type&
fiber_bundle::binary_section_space_schema_member::
standard_host<fiber_bundle::sec_st2_e2>(namespace_type& xns,
                                  const poset_path& xbase_path,
                                  const poset_path& xrep_path,
                                  const string& xfiber_suffix,
                                  bool xauto_access);

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member<fiber_bundle::sec_st2_e2>(namespace_type& xns,
                                    const poset_path& xbase_path,
                                    const poset_path& xrep_path,
                                    const string& xfiber_suffix,
                                    bool xauto_access);

//
// sec_st2_e3
//

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_host_path<fiber_bundle::sec_st2_e3>(const poset_path& xbase_path,
                                       const poset_path& xrep_path,
                                       const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member_path<fiber_bundle::sec_st2_e3>(const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
bool
fiber_bundle::binary_section_space_schema_member::
standard_host_is_available<fiber_bundle::sec_st2_e3>(namespace_poset& xns,
                                         const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix,
                                         bool xauto_access);


template
SHEAF_DLL_SPEC
fiber_bundle::binary_section_space_schema_member::host_type&
fiber_bundle::binary_section_space_schema_member::
standard_host<fiber_bundle::sec_st2_e3>(namespace_type& xns,
                                  const poset_path& xbase_path,
                                  const poset_path& xrep_path,
                                  const string& xfiber_suffix,
                                  bool xauto_access);

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member<fiber_bundle::sec_st2_e3>(namespace_type& xns,
                                    const poset_path& xbase_path,
                                    const poset_path& xrep_path,
                                    const string& xfiber_suffix,
                                    bool xauto_access);

//
// sec_st3_e3
//

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_host_path<fiber_bundle::sec_st3_e3>(const poset_path& xbase_path,
                                       const poset_path& xrep_path,
                                       const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member_path<fiber_bundle::sec_st3_e3>(const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
bool
fiber_bundle::binary_section_space_schema_member::
standard_host_is_available<fiber_bundle::sec_st3_e3>(namespace_poset& xns,
                                         const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix,
                                         bool xauto_access);


template
SHEAF_DLL_SPEC
fiber_bundle::binary_section_space_schema_member::host_type&
fiber_bundle::binary_section_space_schema_member::
standard_host<fiber_bundle::sec_st3_e3>(namespace_type& xns,
                                  const poset_path& xbase_path,
                                  const poset_path& xrep_path,
                                  const string& xfiber_suffix,
                                  bool xauto_access);

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member<fiber_bundle::sec_st3_e3>(namespace_type& xns,
                                    const poset_path& xbase_path,
                                    const poset_path& xrep_path,
                                    const string& xfiber_suffix,
                                    bool xauto_access);

//
// sec_st4_e2
//

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_host_path<fiber_bundle::sec_st4_e2>(const poset_path& xbase_path,
                                       const poset_path& xrep_path,
                                       const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member_path<fiber_bundle::sec_st4_e2>(const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
bool
fiber_bundle::binary_section_space_schema_member::
standard_host_is_available<fiber_bundle::sec_st4_e2>(namespace_poset& xns,
                                         const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix,
                                         bool xauto_access);


template
SHEAF_DLL_SPEC
fiber_bundle::binary_section_space_schema_member::host_type&
fiber_bundle::binary_section_space_schema_member::
standard_host<fiber_bundle::sec_st4_e2>(namespace_type& xns,
                                  const poset_path& xbase_path,
                                  const poset_path& xrep_path,
                                  const string& xfiber_suffix,
                                  bool xauto_access);

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member<fiber_bundle::sec_st4_e2>(namespace_type& xns,
                                    const poset_path& xbase_path,
                                    const poset_path& xrep_path,
                                    const string& xfiber_suffix,
                                    bool xauto_access);

//
// sec_st4_e3
//

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_host_path<fiber_bundle::sec_st4_e3>(const poset_path& xbase_path,
                                       const poset_path& xrep_path,
                                       const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member_path<fiber_bundle::sec_st4_e3>(const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
bool
fiber_bundle::binary_section_space_schema_member::
standard_host_is_available<fiber_bundle::sec_st4_e3>(namespace_poset& xns,
                                         const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix,
                                         bool xauto_access);


template
SHEAF_DLL_SPEC
fiber_bundle::binary_section_space_schema_member::host_type&
fiber_bundle::binary_section_space_schema_member::
standard_host<fiber_bundle::sec_st4_e3>(namespace_type& xns,
                                  const poset_path& xbase_path,
                                  const poset_path& xrep_path,
                                  const string& xfiber_suffix,
                                  bool xauto_access);

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member<fiber_bundle::sec_st4_e3>(namespace_type& xns,
                                    const poset_path& xbase_path,
                                    const poset_path& xrep_path,
                                    const string& xfiber_suffix,
                                    bool xauto_access);


//
// sec_t2_e2
//

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_host_path<fiber_bundle::sec_t2_e2>(const poset_path& xbase_path,
                                       const poset_path& xrep_path,
                                       const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member_path<fiber_bundle::sec_t2_e2>(const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
bool
fiber_bundle::binary_section_space_schema_member::
standard_host_is_available<fiber_bundle::sec_t2_e2>(namespace_poset& xns,
                                         const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix,
                                         bool xauto_access);


template
SHEAF_DLL_SPEC
fiber_bundle::binary_section_space_schema_member::host_type&
fiber_bundle::binary_section_space_schema_member::
standard_host<fiber_bundle::sec_t2_e2>(namespace_type& xns,
                                  const poset_path& xbase_path,
                                  const poset_path& xrep_path,
                                  const string& xfiber_suffix,
                                  bool xauto_access);

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member<fiber_bundle::sec_t2_e2>(namespace_type& xns,
                                    const poset_path& xbase_path,
                                    const poset_path& xrep_path,
                                    const string& xfiber_suffix,
                                    bool xauto_access);

//
// sec_t2_e3
//

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_host_path<fiber_bundle::sec_t2_e3>(const poset_path& xbase_path,
                                       const poset_path& xrep_path,
                                       const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member_path<fiber_bundle::sec_t2_e3>(const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
bool
fiber_bundle::binary_section_space_schema_member::
standard_host_is_available<fiber_bundle::sec_t2_e3>(namespace_poset& xns,
                                         const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix,
                                         bool xauto_access);


template
SHEAF_DLL_SPEC
fiber_bundle::binary_section_space_schema_member::host_type&
fiber_bundle::binary_section_space_schema_member::
standard_host<fiber_bundle::sec_t2_e3>(namespace_type& xns,
                                  const poset_path& xbase_path,
                                  const poset_path& xrep_path,
                                  const string& xfiber_suffix,
                                  bool xauto_access);

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member<fiber_bundle::sec_t2_e3>(namespace_type& xns,
                                    const poset_path& xbase_path,
                                    const poset_path& xrep_path,
                                    const string& xfiber_suffix,
                                    bool xauto_access);

//
// sec_t3_e3
//

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_host_path<fiber_bundle::sec_t3_e3>(const poset_path& xbase_path,
                                       const poset_path& xrep_path,
                                       const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member_path<fiber_bundle::sec_t3_e3>(const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
bool
fiber_bundle::binary_section_space_schema_member::
standard_host_is_available<fiber_bundle::sec_t3_e3>(namespace_poset& xns,
                                         const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix,
                                         bool xauto_access);


template
SHEAF_DLL_SPEC
fiber_bundle::binary_section_space_schema_member::host_type&
fiber_bundle::binary_section_space_schema_member::
standard_host<fiber_bundle::sec_t3_e3>(namespace_type& xns,
                                  const poset_path& xbase_path,
                                  const poset_path& xrep_path,
                                  const string& xfiber_suffix,
                                  bool xauto_access);

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member<fiber_bundle::sec_t3_e3>(namespace_type& xns,
                                    const poset_path& xbase_path,
                                    const poset_path& xrep_path,
                                    const string& xfiber_suffix,
                                    bool xauto_access);


//
// sec_t4_e2
//

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_host_path<fiber_bundle::sec_t4_e2>(const poset_path& xbase_path,
                                       const poset_path& xrep_path,
                                       const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member_path<fiber_bundle::sec_t4_e2>(const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
bool
fiber_bundle::binary_section_space_schema_member::
standard_host_is_available<fiber_bundle::sec_t4_e2>(namespace_poset& xns,
                                         const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix,
                                         bool xauto_access);


template
SHEAF_DLL_SPEC
fiber_bundle::binary_section_space_schema_member::host_type&
fiber_bundle::binary_section_space_schema_member::
standard_host<fiber_bundle::sec_t4_e2>(namespace_type& xns,
                                  const poset_path& xbase_path,
                                  const poset_path& xrep_path,
                                  const string& xfiber_suffix,
                                  bool xauto_access);

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member<fiber_bundle::sec_t4_e2>(namespace_type& xns,
                                    const poset_path& xbase_path,
                                    const poset_path& xrep_path,
                                    const string& xfiber_suffix,
                                    bool xauto_access);

//
//  sec_t4_e3
//

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_host_path<fiber_bundle::sec_t4_e3>(const poset_path& xbase_path,
                                       const poset_path& xrep_path,
                                       const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member_path<fiber_bundle::sec_t4_e3>(const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix);


template
SHEAF_DLL_SPEC
bool
fiber_bundle::binary_section_space_schema_member::
standard_host_is_available<fiber_bundle::sec_t4_e3>(namespace_poset& xns,
                                         const poset_path& xbase_path,
                                         const poset_path& xrep_path,
                                         const string& xfiber_suffix,
                                         bool xauto_access);


template
SHEAF_DLL_SPEC
fiber_bundle::binary_section_space_schema_member::host_type&
fiber_bundle::binary_section_space_schema_member::
standard_host<fiber_bundle::sec_t4_e3>(namespace_type& xns,
                                  const poset_path& xbase_path,
                                  const poset_path& xrep_path,
                                  const string& xfiber_suffix,
                                  bool xauto_access);

template
SHEAF_DLL_SPEC
sheaf::poset_path
fiber_bundle::binary_section_space_schema_member::
standard_member<fiber_bundle::sec_t4_e3>(namespace_type& xns,
                                    const poset_path& xbase_path,
                                    const poset_path& xrep_path,
                                    const string& xfiber_suffix,
                                    bool xauto_access);



