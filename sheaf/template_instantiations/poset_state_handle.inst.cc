
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

// Explicit instantiations for class poset_state_handle.

#include "ComLimitPoint/sheaf/poset_state_handle.impl.h"

#include "ComLimitPoint/sheaf/array_index_space_handle.h"
#include "ComLimitPoint/sheaf/hash_index_space_handle.h"
#include "ComLimitPoint/sheaf/hub_index_space_handle.h"
#include "ComLimitPoint/sheaf/list_index_space_handle.h"
#include "ComLimitPoint/sheaf/mutable_index_space_handle.h"
#include "ComLimitPoint/sheaf/offset_index_space_handle.h"
#include "ComLimitPoint/sheaf/singleton_index_space_handle.h"
#include "ComLimitPoint/sheaf/set_filter.h"
#include "ComLimitPoint/sheaf/unordered_set_filter.h"
#include "ComLimitPoint/sheaf/zn_to_bool_filter.h"

using namespace sheaf; // Workaround for MS C++ bug.

//============================================================
// EXPLICIT INSTANTIATIONS
//============================================================


template 
SHEAF_DLL_SPEC
sheaf::array_index_space_handle& 
sheaf::poset_state_handle::
get_cover_id_space<sheaf::array_index_space_handle>(bool xlower, pod_index_type xmbr_index) const;

template 
SHEAF_DLL_SPEC
sheaf::hash_index_space_handle& 
sheaf::poset_state_handle::
get_cover_id_space<sheaf::hash_index_space_handle>(bool xlower, pod_index_type xmbr_index) const;

template 
SHEAF_DLL_SPEC
sheaf::hub_index_space_handle& 
sheaf::poset_state_handle::
get_cover_id_space<sheaf::hub_index_space_handle>(bool xlower, pod_index_type xmbr_index) const;

template 
SHEAF_DLL_SPEC
sheaf::list_index_space_handle& 
sheaf::poset_state_handle::
get_cover_id_space<sheaf::list_index_space_handle>(bool xlower, pod_index_type xmbr_index) const;

template 
SHEAF_DLL_SPEC
sheaf::mutable_index_space_handle& 
sheaf::poset_state_handle::
get_cover_id_space<sheaf::mutable_index_space_handle>(bool xlower, pod_index_type xmbr_index) const;

template 
SHEAF_DLL_SPEC
sheaf::offset_index_space_handle& 
sheaf::poset_state_handle::
get_cover_id_space<sheaf::offset_index_space_handle>(bool xlower, pod_index_type xmbr_index) const;

template 
SHEAF_DLL_SPEC
sheaf::singleton_index_space_handle& 
sheaf::poset_state_handle::
get_cover_id_space<sheaf::singleton_index_space_handle>(bool xlower, pod_index_type xmbr_index) const;

template 
SHEAF_DLL_SPEC
void 
sheaf::poset_state_handle::
remove_cover_members<sheaf::unordered_set_filter>(const sheaf::unordered_set_filter& xfilter,
					     bool xlower,
					     const sheaf::scoped_index& xmbr_index);

template 
SHEAF_DLL_SPEC
void 
sheaf::poset_state_handle::
remove_cover_members<sheaf::unordered_set_filter>(const sheaf::unordered_set_filter& xfilter,
					     bool xlower,
					     pod_index_type xmbr_hub_id);

template
SHEAF_DLL_SPEC
void
sheaf::poset_state_handle::
remove_cover_members<sheaf::set_filter>(const sheaf::set_filter& xfilter,
					bool xlower,
					const sheaf::scoped_index& xmbr_index);

template
SHEAF_DLL_SPEC
void
sheaf::poset_state_handle::
remove_cover_members<sheaf::set_filter>(const sheaf::set_filter& xfilter,
					bool xlower,
					 pod_index_type xmbr_hub_id);

template 
SHEAF_DLL_SPEC
void 
sheaf::poset_state_handle::
remove_cover_members<sheaf::zn_to_bool_filter>(const sheaf::zn_to_bool_filter& xfilter,
					       bool xlower,
					       const sheaf::scoped_index& xmbr_index);
 
template <typename filter_type>
void remove_cover_members(const filter_type& xfilter,
			    bool xlower,
			    pod_index_type xmbr_hub_id);
