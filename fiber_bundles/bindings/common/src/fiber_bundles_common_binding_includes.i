
//
// Copyright (c) 2013 Limit Point Systems, Inc. 
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

//
// Common Swig interface for fiber_bundles cluster
//

//=============================================================================

//$$SCRIBBLE: This file contains only the part of the Swig interface which
//            is to be inserted directly into the generated code.
//            We have to break the interface into two parts because
//            of the way Swig handles "%import" versus "%include".
//            If you change this file make sure you also change
//            "fiber_bundles_common_binding.i" as well.

//=============================================================================

%{

#include "fiber_bundle.h"

#include "base_space_factory.h"
#include "base_space_member.h"
#include       "homogeneous_block.h"
#include             "point_block_1d.h"
#include             "point_block_2d.h"
#include             "point_block_3d.h"
#include             "structured_block.h"
#include                   "structured_block_1d.h"
#include                   "structured_block_2d.h"
#include                   "structured_block_3d.h"
#include             "unstructured_block.h"
#include       "local_base_space_member.h"
#include "base_space_poset.h"
#include "binary_index.h"
#include "binary_index_space.h"
#include "block_connectivity.h"
#include       "hex_connectivity.h"
#include       "line_connectivity.h"
#include       "point_connectivity.h"
#include       "quad_connectivity.h"
#include       "tetra_connectivity.h"
#include       "triangle_connectivity.h"
#include "chart_point.h"
#include       "chart_point_1d.h"
#include       "chart_point_2d.h"
#include       "chart_point_3d.h"
#include "discretization_context.h"
#include "discretization_iterator.h"
#include "eval_family.h"
#include       "constant_eval_family.h"
#include       "dlinear_eval_family.h"
#include       "uniform_eval_family.h"
#include "eval_iterator.h"
#include "fiber_bundles_namespace.h"
#include "group.h"
#include       "gln.h"
#include             "gl2.h"
#include             "gl3.h"
#include "gln_space.h"
#include "i_adjacency_implicit_index_space_iterator.h"
#include "i_adjacency_index_space_interval.h"
#include "i_connectivity_implicit_index_space_iterator.h"
#include "i_connectivity_index_space_interval.h"
#include "ij_adjacency_implicit_index_space_iterator.h"
#include "ij_adjacency_index_space_interval.h"
#include "ij_connectivity_implicit_index_space_iterator.h"
#include "ij_connectivity_index_space_interval.h"
#include "ijk_adjacency_implicit_index_space_iterator.h"
#include "ijk_adjacency_index_space_interval.h"
#include "ijk_connectivity_implicit_index_space_iterator.h"
#include "ijk_connectivity_index_space_interval.h"
#include "sec_rep_descriptor.h"
#include "sec_rep_space.h"
#include       "sec_tuple_space.h"
#include             "sec_vd_space.h"
#include                   "sec_jcb_space.h"
#include                   "sec_tp_space.h"
#include                         "sec_atp_space.h"
#include                              "sec_at0_space.h"
#include                              "sec_at1_space.h"
#include                         "sec_stp_space.h"
#include "sec_rep_space_member.h"
#include       "sec_tuple.h"
#include       "sec_vd.h"
#include             "sec_jcb.h"
#include                   "sec_jcb_ed.h"
#include                         "sec_jcb_e13.h"
#include                         "sec_jcb_e23.h"
#include                         "sec_jcb_e33.h"
#include             "sec_tp.h"
#include                   "sec_atp.h"
#include                         "sec_at0.h"
#include                         "sec_at1.h"
#include                               "sec_ed.h"
#include                                     "sec_e1.h"
#include                                           "sec_e1_uniform.h"
#include                                     "sec_e2.h"
#include                                           "sec_e2_uniform.h"
#include                                     "sec_e3.h"
#include                                           "sec_e3_uniform.h"
#include                                     "sec_e4.h"
#include                         "sec_at2.h"
#include                               "sec_at2_e2.h"
#include                               "sec_at2_e3.h"
#include                         "sec_at3.h"
#include                               "sec_at3_e3.h"
#include                   "sec_stp.h"
#include                         "sec_st2.h"
#include                               "sec_met.h"
#include                                     "sec_met_ed.h"
#include                                           "sec_met_e1.h"
#include                                           "sec_met_e2.h"
#include                                           "sec_met_e3.h"
#include                               "sec_st2_e2.h"
#include                               "sec_st2_e3.h"
#include                         "sec_st3.h"
#include                               "sec_st3_e3.h"
#include                         "sec_st4.h"
#include                               "sec_st4_e2.h"
#include                               "sec_st4_e3.h"
#include                   "sec_t2.h"
#include                         "sec_t2_e2.h"
#include                         "sec_t2_e3.h"
#include                   "sec_t3.h"
#include                         "sec_t3_e3.h"
#include                   "sec_t4.h"
#include                         "sec_t4_e2.h"
#include                         "sec_t4_e3.h"
#include "section_component_iterator.h"
#include       "binary_section_component_iterator.h"
#include "section_dof_iterator.h"
#include 	"binary_section_dof_iterator.h"
#include "section_dof_map.h"
#include        "array_section_dof_map.h"
#include        "sparse_section_dof_map.h"
#include "section_eval_iterator.h"
#include "section_evaluator.h"
#include       "differentiable_section_evaluator.h"
#include       "integrable_section_evaluator.h"
#include       "linear_fcn_space.h"
#include             "bilinear_2d.h"
#include             "constant_fcn_space.h"
#include                   "constant_hex.h"
#include                   "constant_point.h"
#include                   "constant_quad.h"
#include                   "constant_segment.h"
#include                   "constant_tet.h"
#include                   "constant_triangle.h"
#include             "linear_1d.h"
#include             "linear_2d.h"
#include             "linear_3d.h"
#include             "quadratic_1d.h"
#include             "quadratic_2d.h"
#include             "quadratic_3d.h"
#include             "trilinear_3d.h"
#include             "uniform_1d.h"
#include             "uniform_2d.h"
#include             "uniform_3d.h"
#include "section_iteration_state.h"
#include "section_space_schema_jims_index_space_handle.h"
#include "section_space_schema_jims_index_space_iterator.h"
#include "section_space_schema_jims_index_space_state.h"
#include "section_space_schema_member.h"
#include       "binary_section_space_schema_member.h"
#include "section_space_schema_poset.h"
#include       "binary_section_space_schema_poset.h"
#include "ternary_index.h"
#include "ternary_index_space.h"
#include "tuple.h"
#include       "vd.h"
#include             "jcb.h"
#include                   "jcb_ed.h"
#include                         "jcb_e13.h"
#include                         "jcb_e23.h"
#include                         "jcb_e33.h"
#include             "tp.h"
#include                   "atp.h"
#include                         "at0.h"
#include                         "at1.h"
#include                               "ed.h"
#include                                     "e1.h"
#include                                     "e2.h"
#include                                     "e3.h"
#include                                     "e4.h"
#include                         "at2.h"
#include                               "at2_e2.h"
#include                               "at2_e3.h"
#include                         "at3.h"
#include                               "at3_e3.h"
#include                   "stp.h"
#include                         "st2.h"
#include                               "met.h"
#include                                     "met_ed.h"
#include                                           "met_e1.h"
#include                                           "met_e2.h"
#include                                           "met_e3.h"
#include                               "st2_e2.h"
#include                               "st2_e3.h"
#include                         "st3.h"
#include                               "st3_e3.h"
#include                         "st4.h"
#include                               "st4_e2.h"
#include                               "st4_e3.h"
#include                   "t2.h"
#include                         "t2_e2.h"
#include                         "t2_e3.h"
#include                   "t3.h"
#include                         "t3_e3.h"
#include                   "t4.h"
#include                         "t4_e2.h"
#include                         "t4_e3.h"
#include "tuple_space.h"
#include       "vd_space.h"
#include             "jcb_space.h"
#include             "tp_space.h"
#include                   "atp_space.h"
#include                         "at0_space.h"
#include                         "at1_space.h"
#include                   "stp_space.h"
#include "unary_index_space.h"
#include "unstructured_block_builder.h"

using namespace std;
using namespace fiber_bundle;

%}

//=============================================================================
