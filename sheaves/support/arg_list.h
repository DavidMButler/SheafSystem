// $RCSfile: arg_list.h,v $ $Revision: 1.25 $ $Date: 2013/01/12 17:17:45 $

//
// Copyright (c) 2013 Limit Point Systems, Inc.
//

// Interface for class arg_list

#ifndef ARG_LIST_H
#define ARG_LIST_H

#ifndef SHEAF_DLL_SPEC_H
#include "sheaf_dll_spec.h"
#endif

#ifndef BLOCK_H
#include "block.h"
#endif

#ifndef PRIMITIVE_VALUE_H
#include "primitive_value.h"
#endif

namespace sheaf
{

// Forward declarations to enable friend declaration.

class arg_list;
class namespace_poset;
class poset_path;
class schema_poset_member;

///
/// Insert arg_list p into ostream os.
///
SHEAF_DLL_SPEC ostream& operator << (ostream &os, const arg_list& p);

///
/// Extract arg_list p from istream is.
///
SHEAF_DLL_SPEC istream& operator >> (istream &is, arg_list& p);

///
/// A whitespace separated list of arguments.  Insertion operaters are used to
/// insert arguments into the list. C++ strings are treated as string literals.
/// The value of the string is inserted into arg_list.
///
/// @todo Need some way to reset this list and
///       a way to easily iterate through the list.
///
class SHEAF_DLL_SPEC arg_list
{

  friend SHEAF_DLL_SPEC ostream& operator << (ostream &os, const arg_list& xf);
  friend SHEAF_DLL_SPEC istream& operator >> (istream &is, arg_list& xf);

public:

  // The following must be public to support stream insertion operator.

  ///
  /// The internal argument type.
  ///
  struct SHEAF_DLL_SPEC arg_type
  {
    ///
    /// The name of the argument.
    ///
    string name;

    ///
    /// The type of the argument.
    ///
    primitive_type type() const
    {
      return value.id();
    };

    ///
    /// Sets the type of the argument to xid.
    ///
    void put_type(primitive_type xid)
    {
      value.id() = xid;
    };

    ///
    /// Sets the type of the argument to xid.
    ///
    void put_type(int xid);

    ///
    /// The value of the argument.
    ///
    primitive_value value;

    ///
    /// Create an instance with empty name.
    ///
    arg_type() {} ;

    ///
    /// Create an instance with name == xname and default value.
    ///
    arg_type(const string& xname)
        : name(xname)
    {} ;

    ///
    /// Create an instance with name == xname and default value.
    ///
    arg_type(const char* xname)
        : name(xname)
    {};

    ///
    /// True if and only if name and value of this
    /// are identical to name and value, respectively,
    /// of xother.
    ///
    bool operator==(const arg_type& xother) const
    {
      return (name == xother.name) && (value == xother.value);
    };

    ///
    /// True if and only if name is empty.
    ///
    bool empty() const
    {
      return name.empty();
    };


  };

  ///
  /// Default constructor
  ///
  arg_list();

  ///
  /// Copy constructor
  ///
  arg_list(const arg_list& xinput);

  ///
  /// Creates an instance with arg xarg.
  ///
  arg_list(const arg_type& xarg);

  ///
  /// Creates an instance with one arg with name xarg_name;
  /// if xarg_name is empty, creates an empty arg_list.
  /// Intended for initializing empty arg_lists with string literal "".
  ///
  arg_list(const char* xarg_name);

  ///
  /// The number of arguments.
  ///
  unsigned int ct() const;

  ///
  /// True if and only if there are no arguments in the list.
  ///
  bool empty() const;

  ///
  /// The index of the argument with name xname.
  ///
  int index(const string& xname) const;

  ///
  /// The name of the xi-th argument.
  ///
  const string& name(int xi) const;

  ///
  /// The type of the xi-th argument.
  ///
  int type(int xi) const;
  //  const int& type(int xi) const;

  ///
  /// The type of the argument with name xname.
  ///
  int type(const string& xname) const;
  //  const int& type(const string& xname) const;

  ///
  /// The value of the xi-th argument.
  ///
  primitive_value& value(int xi);

  ///
  /// The value of the xi-th argument, const version.
  ///
  const primitive_value& value(int xi) const;

  ///
  /// The value of argument with name xname.
  ///
  primitive_value& value(const string& xname);

  ///
  /// The value of argument with name xname, const version.
  ///
  const primitive_value& value(const string& xname) const;

//   ///
//   /// Insert another arg_list.
//   ///
//   arg_list& operator<<(const arg_list& xinput);

  ///
  /// Append arg_list xother.
  ///
  arg_list& operator+=(const arg_list& xother);

  ///
  /// Insert a primitive value.
  ///
  arg_list& operator<<(const primitive_value& xinput);

  ///
  /// True if next token should be an argument name.
  ///
  bool parsing_name() const;

  ///
  /// True if next token should be an argument value.
  ///
  bool parsing_value() const;

  ///
  /// True if argument input has found an error.
  ///
  bool parsing_error() const;

  ///
  /// True if the values in this conform to the
  /// table schema (xuse_table_schema true) or
  /// row schema (xuse_table_schema false)
  /// specified by xschema_path.
  ///
  bool conforms_to(const namespace_poset& xns,
                   const poset_path& xschema_path,
                   bool xuse_table_schema,
                   bool xauto_access) const;
  ///
  /// True if the values in this conform to the
  /// table schema (xuse_table_schema true) or
  /// row schema (xuse_table_schema false)
  /// specified by xschema.
  ///
  bool conforms_to(const schema_poset_member& xschema,
                   bool xuse_table_schema,
                   bool xauto_access) const;


  ///
  /// True if the values in this conform to the
  /// table schema (xuse_table_schema true) or
  /// row schema (xuse_table_schema false)
  /// specified by the part of xschema_path
  /// that is not contained in xstd_schema_path.
  ///
  bool conforms_to_extension(const namespace_poset& xns,
                             const poset_path& xschema_path,
                             const poset_path& xstd_schema_path,
                             bool xuse_table_schema,
                             bool xauto_access) const;

  ///
  /// True if the values in this conform to the
  /// table schema (xuse_table_schema true) or
  /// row schema (xuse_table_schema false)
  /// specified by the part of xschema
  /// that is not contained in xstd_schema.
  ///
  bool conforms_to_extension(const schema_poset_member& xschema,
                             const schema_poset_member& xstd_schema,
                             bool xuse_table_schema,
                             bool xauto_access) const;

  ///
  /// Removes all arguments.
  ///
  void clear();

  ///
  /// The xi-th arg.
  ///
  arg_type& arg(int xi);

  ///
  /// The xi-th arg.
  ///
  const arg_type& arg(int xi) const;

  ///
  /// True if and only if this contains an arg with name xname.
  ///
  bool contains_arg(const string& xname) const;

  ///
  /// True if and only if this contains all the args of xother.
  ///
  bool contains_args(const arg_list& xother) const;

  ///
  /// The arg with name xname.
  ///
  arg_type& arg(const string& xname);

  ///
  /// The arg with name xname.
  ///
  const arg_type& arg(const string& xname) const;

  ///
  /// The last arg.
  ///
  arg_type& back();

  ///
  /// The last arg, const version.
  ///
  const arg_type& back() const;

  //*
  // Put xarg at the back of the list.
  //*/
  void push_back(const arg_type& xarg);


private:

  ///
  /// The "list" of arguments.
  ///
  block<arg_type> _args;

  ///
  /// Type of state variable for parsing input.
  ///
  enum parse_state_type {GET_NAME, GET_VALUE, ERROR};

  ///
  /// State variable for parsing input.
  ///
  parse_state_type _parse_state;

  ///
  /// True if the arg with name xschema.name() conforms to xschema.type().
  ///
  bool arg_conforms_to(const schema_poset_member& xschema) const;


};

// ===========================================================
// NON-MEMBER FUNCTIONS
// ===========================================================

///
/// Insert arg_list::arg_type& p into ostream& os.
///
SHEAF_DLL_SPEC
ostream& operator << (ostream &os, const arg_list::arg_type& p);

///
/// Extract arg_list::arg_type& p from ostream& os.
///
SHEAF_DLL_SPEC
istream& operator >> (istream &os, arg_list::arg_type& p);

///
/// The deep size of the referenced object of type arg_list::arg_type.
/// if xinclude_shallow, add the sizeof xtype to the result.
///
size_t
SHEAF_DLL_SPEC
deep_size(const arg_list::arg_type& xtype, bool xinclude_shallow = true);


} // namespace sheaf

#endif // ifndef ARG_LIST_H
