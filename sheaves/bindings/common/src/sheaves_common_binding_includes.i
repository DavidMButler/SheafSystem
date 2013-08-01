
//
//
//
// Copyright (c) 2013 Limit Point Systems, Inc. 

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//   http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

//
//
// Common SWIG interface to sheaves cluster
//
//=============================================================================

//$$SCRIBBLE: This file contains only the part of the Swig interface which
//            is to be inserted directly into the generated code.
//            We have to break the interface into two parts because
//            of the way Swig handles "%import" versus "%include".
//            If you change this file make sure you also change
//            "sheaves_common_binding.i" as well.

//=============================================================================

%{

#include "std_string.h"

#include "sheaf_dll_spec.h"
#include "sheaf.h"
#include "poset_type.h"
#include "pod_types.h"
#include "primitive_attributes.h"
#include "primitive_value.h"
#include "primitive_type.h"
#include "standard_dof_tuple_index.h"
#include "standard_member_index.h"
#include "standard_subposet_index.h"
#include "standard_version_index.h"
#include "dof_tuple_type.h"
#include "namespace_relative_member_index.h"
#include "namespace_relative_subposet_index.h"
#include "rc_ptr.h"

#include "any.h"
#include       "abstract_product_structure.h"
#include             "ij_product_structure.h"
#include             "ijk_product_structure.h"
#include       "data_converter.h"
#include       "data_type_map.h"
#include             "file_data_type_map.h"
#include             "poset_data_type_map.h"
#include       "depth_first_iterator.h"
#include             "filtered_depth_first_iterator.h"
#include                   "biorder_iterator.h"
#include                   "linkorder_iterator.h"
#include                   "postorder_iterator.h"
#include                   "preorder_iterator.h"
#include                   "triorder_iterator.h"
#include       "depth_first_itr.h"
#include             "filtered_depth_first_itr.h"
#include                   "biorder_itr.h"
#include                   "linkorder_itr.h"
#include                   "postorder_itr.h"
#include                   "preorder_itr.h"
#include                   "triorder_itr.h"
#include       "error_message.h"
#include       "filtered_depth_first_member_iterator.h"
#include             "postorder_member_iterator.h"
#include             "preorder_member_iterator.h"
#include       "index_equivalence_class.h"
#include       "index_equivalence_iterator.h"
#include       "index_space_collection.h"
#include             "explicit_index_space_collection.h"
#include             "index_space_interval.h"
#include                   "array_index_space_interval.h"
#include                   "explicit_index_space_interval.h"
#include                   "ragged_array_index_space_interval.h"
#include                   "singleton_index_space_interval.h"
#include       "index_space_family.h"
#include       "index_space_family_iterator.h"
#include       "index_space_handle.h"
#include             "forwarding_index_space_handle.h"
#include             "explicit_index_space_handle.h"
#include                   "sum_index_space_handle.h"
#include                         "hub_index_space_handle.h"
#include                   "mutable_index_space_handle.h"
#include                         "interval_index_space_handle.h"
#include                   "primary_index_space_handle.h"
#include                         "offset_index_space_handle.h"
#include       "explicit_index_space_state.h"
#include             "mutable_index_space_state.h"
#include                   "array_index_space_state.h"
#include                   "hash_index_space_state.h"
#include                   "interval_index_space_state.h"
#include             "primary_index_space_state.h"
#include                   "offset_index_space_state.h"
#include             "sum_index_space_state.h"
#include                   "primary_sum_index_space_state.h"
#include             "primitives_index_space_state.h"
#include       "index_space_interval_iterator.h"
#include       "index_space_iterator.h"
#include             "explicit_index_space_iterator.h"
#include                   "array_index_space_iterator.h"
#include                   "hash_index_space_iterator.h"
#include                   "hub_index_space_iterator.h"
#include                   "interval_index_space_iterator.h"
#include                   "offset_index_space_iterator.h"
#include                   "primitives_index_space_iterator.h"
#include             "implicit_index_space_iterator.h"
#include                   "array_implicit_index_space_iterator.h"
#include                   "ragged_array_implicit_index_space_iterator.h"
#include                   "singleton_implicit_index_space_iterator.h"
#include       "name_multimap.h"
#include       "poset_bounds.h"
#include       "poset_bounds_descriptor.h"
#include       "poset_crg_state.h"
#include       "poset_dof_iterator.h"
#include       "poset_dof_map.h"
#include             "array_poset_dof_map.h"
#include             "namespace_poset_dof_map.h"
#include             "primitives_poset_dof_map.h"
#include       "poset_joiner.h"
#include       "poset_powerset_state.h"
#include       "poset_scaffold.h"
#include       "poset_table_state.h"
#include       "poset_traverser.h"
#include             "poset_dft.h"
#include                   "poset_orderer.h"
#include                   "poset_slicer.h"
#include       "rc_any.h"
#include             "ragged_array.h"
#include       "read_write_monitor.h"
#include             "poset_state.h"
#include       "read_write_monitor_handle.h"
#include             "poset_component.h"
#include                   "abstract_poset_member.h"
#include                         "partial_poset_member.h"
#include                               "poset_member.h"
#include                         "total_poset_member.h"
#include                               "namespace_poset_member.h"
#include                               "poset_member_iterator.h"
//#include                                     "filtered_iterator.h"
#include                                     "subposet_member_iterator.h"
#include                               "schema_poset_member.h"
#include                   "subposet.h"
#include             "poset_state_handle.h"
#include                   "namespace_poset.h"
#include                         "sheaves_namespace.h"
#include                   "namespace_poset_schema.h"
#include                   "poset.h"
#include                         "refinable_poset.h"
#include                   "primitives_poset.h"
#include                   "primitives_poset_schema.h"
#include       "record.h"
#include             "variable_length_record.h"
#include                   "attributes_record.h"
#include                         "dof_tuple_class_names_record.h"
#include                         "dof_tuple_col_bounds_record.h"
#include                         "dof_tuple_domain_offsets_record.h"
#include                         "dof_tuple_schema_ids_record.h"
#include                         "dof_tuple_schema_versions_record.h"
#include                         "dof_tuple_types_record.h"
#include                         "id_space_names_record.h"
#include                         "member_names_record.h"
#include                         "poset_general_record.h"
#include                         "subposet_names_record.h"
#include                         "table_dof_tuple_record.h"
#include                   "member_record.h"
#include       "record_queue.h"
#include       "record_set.h"
#include             "attributes_record_set.h"
#include             "dof_tuple_record_set.h"
#include             "member_record_set.h"
#include       "schema_descriptor.h"
#include       "sheaf_file.h"
#include       "storage_agent.h"
#include "arg_list.h"
#include "auto_block.h"
#include       "block.h"
#include             "binary_index_block.h"
#include             "id_block.h"
#include             "wsv_block.h"
#include "dof_descriptor_array.h"
#include "dof_map_factory.h"
//#include "factory.h"
#include "index_iterator.h"
#include "int_set.h"
#include "plot.h"
#include "pool.h"
#include "poset_handle_factory.h"
#include "poset_path.h"
#include "ptr_linked_pool.h"
#include "record_map.h"
#include "runnable.h"
#include "scoped_index.h"
#include "stop_watch.h"
#include "subposet_state.h"
#include "tern.h"
#include "thread.h"
#include "thread_condition_variable.h"
#include "thread_mutex.h"
#include "zn_to_bool.h"

#include "deep_size.h"

using namespace sheaf;

%}
