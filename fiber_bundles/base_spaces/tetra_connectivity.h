// $RCSfile: tetra_connectivity.h,v $ $Revision: 1.16 $ $Date: 2013/01/12 17:16:52 $

//
// Copyright (c) 2013 Limit Point Systems, Inc.
//

// Interface for class tetra_connectivity

#ifndef TETRA_CONNECTIVITY_H
#define TETRA_CONNECTIVITY_H

#ifndef SHEAF_DLL_SPEC_H
#include "sheaf_dll_spec.h"
#endif

#ifndef BASE_CONNECTIVITY_H
#include "block_connectivity.h"
#endif

namespace fiber_bundle
{
  
  using namespace sheaf;

///
/// Connectivity for a tetrahedral mesh with elements arranged
/// so that the vertices form a regular cubical array
///
class SHEAF_DLL_SPEC tetra_connectivity : public block_connectivity
{

public:

  // ===========================================================
  /// @name TETRA_CONNECTIVITY FACET
  // ===========================================================
  //@{

public:
  ///
  /// Default constructor.
  /// Equivalent to tetra_connectivity(1, 1, 1)
  ///
  tetra_connectivity();

  ///
  /// Copy constructor
  ///
  tetra_connectivity(const tetra_connectivity& xother);

  ///
  /// Destructor.
  ///
  virtual ~tetra_connectivity();
 
  ///
  /// Creates an instance with node_ids() == xnode_ids,
  /// and node_id_ct() == xnode_id_ct. If xnode_ct == 0,
  /// node_ct() will be computed from node_ids(), otherwise,
  /// node_ct() == xnode_ct.
  ///
  tetra_connectivity(const pod_index_type* xnode_ids, size_type xnode_id_ct, size_type xnode_ct);

  ///
  /// Creates an instance with i_size() == xi_size, j_size() == x_jsize,
  /// k_size() == xk_size.
  ///
  tetra_connectivity(size_type xi_size,
                     size_type xj_size,
                     size_type xk_size,
                     pod_index_type xstart_id = 0);

  ///
  /// Static const integral data members.
  /// @hack Inline initialization of static const integral data 
  /// members causes link error in MSC++; use enum instead.
  ///
  enum static_const_int {NODES_PER_ELEMENT = 4}; 

protected:

  ///
  /// Allocates and initializes the connectivity array.
  ///
  void create_connectivity(size_type xi_size,
                   size_type xj_size,
                   size_type xk_size,
                   pod_index_type xstart_id = 0);

  ///
  /// The number of vertices in the i-direction.
  ///
  size_type _i_vertex_size;

  ///
  /// The number of vertices in the j-direction.
  ///
  size_type _j_vertex_size;

  ///
  /// The number of vertices in the k-direction.
  ///
  size_type _k_vertex_size;

  ///
  /// The node id associated with (xi,xj,xk).
  ///
  size_type node_id(size_type xi, size_type xj, size_type xk) const;
  

private:

  //@}

  // ===========================================================
  /// @name BLOCK_RELATION FACET
  // ===========================================================
  //@{

public:
  ///
  /// The element type.
  ///
  virtual cell_type element_type() const;

protected:

private:

  //@}

  // ===========================================================
  /// @name ANY FACET
  // ===========================================================
  //@{

public:
  ///
  /// Virtual constructor, makes a new
  /// instance of the same type as this
  ///
  virtual tetra_connectivity* clone() const;

  ///
  /// Class invariant.
  ///
  virtual bool invariant() const;

  ///
  /// Conformance test; true if other conforms to this
  ///
  virtual bool is_ancestor_of(const any* other) const;

protected:

private:

  //@}

};
  
} // namespace fiber_bundle

#endif // ifndef TETRA_CONNECTIVITY_H
