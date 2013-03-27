// $RCSfile: record_queue.h,v $ $Revision: 1.19 $ $Date: 2013/01/12 17:17:36 $

// $Name@
//
// Copyright (c) 2013 Limit Point Systems, Inc.
//

/// @file
/// Interface for class record_queue

#ifndef RECORD_QUEUE_H
#define RECORD_QUEUE_H

#ifndef SHEAF_DLL_SPEC_H
#include "sheaf_dll_spec.h"
#endif

#ifndef ANY_H
#include "any.h"
#endif

#ifndef POD_TYPES_H
#include "pod_types.h"
#endif

#ifndef STD_QUEUE_H
#include "std_queue.h"
#endif


namespace sheaf
{
  
///
/// A queue for record read requests.
///
/// @todo replace this representation with something
/// more sophisticated that supports hyperslices.
///
class SHEAF_DLL_SPEC record_queue : public any
{

  // ===========================================================
  /// @name RECORD_QUEUE FACET
  // ===========================================================
  //@{

public:

  ///
  /// Default constructor.
  ///
  record_queue();

  ///
  /// Copy constructor
  ///
  record_queue(const record_queue& xother);

  ///
  /// Destructor
  ///
  virtual ~record_queue();

  ///
  /// Inserts xindex at the end of the record queue.
  ///
  void enqueue(pod_index_type xindex);

  ///
  /// Removes and returns the index
  /// at the front of the record queue.
  ///
  pod_index_type dequeue();

  ///
  /// The number of requests in the record queue
  ///
  int ct() const;

  ///
  /// True if the record queue is empty.
  ///
  bool is_empty() const;

  ///
  /// Makes the record queue empty.
  ///
  void clear();

protected:

private:

  ///
  /// The queue of member indices waiting to be read.
  ///
  /// @todo replace this representation with something
  /// more sophisticated that supports hyperslices
  ///
  queue<pod_index_type> _record_queue;


  //@}


  // ===========================================================
  /// @name ANY FACET
  // ===========================================================
  //@{

public:

  ///
  /// Virtual constructor;
  /// makes a new instance of
  /// the same type as this
  ///
  virtual record_queue* clone() const;

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
  
} // namespace sheaf

#endif // ifndef RECORD_QUEUE_H






