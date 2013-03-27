/**
 *  Classname: PropertyRolePanel
 *
 *  @author $Author: jebutler $
 *
 *  @version $RCSfile: PropertyRolePanel.java,v $ $Revision: 1.7 $
 *
 *  $Date: 2013/01/12 17:17:56 $
 *
 *  Copyright (c) 2013 Limit Point Systems, Inc.
 */

package tools.viewer.application;

import bindings.java.*;

import javax.swing.*;

/**
 * Implementation of <code>RolePanel</code> for a property section.
 */
public class PropertyRolePanel extends RolePanel
{
  /**
   * The constructor
   */
  public PropertyRolePanel()
  {
    super();
  }

  /**
   * Return the role text
   */
  protected String getRole()
  {
    return "Property Section";
  }

  /**
   * True, if the role can be filled by xsection
   */
  protected boolean canFillRole(sec_vd xsection)
  {
    try
    {
      int df = xsection.df();

      if(df >= 1 && df <= 6)
        return true;
    }
    catch(Exception e)
    {
      // $$HACK: Need better error handling.

      e.printStackTrace();
    }

    return false;
  }
}
