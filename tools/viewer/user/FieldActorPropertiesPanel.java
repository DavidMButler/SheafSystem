
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

package tools.viewer.user;

import tools.viewer.render.*;
import tools.common.gui.*;

import java.awt.*;
import java.awt.event.*;
import java.util.*;
import javax.swing.*;
import javax.swing.event.*;
import javax.swing.border.*;
import java.text.*;
import vtk.*;

/**
 * Abstract implementation of <code>PropertiesPanel</code> for editing the
 * values of a <code>FieldActorDescriptor</code>.
 */
public abstract class FieldActorPropertiesPanel extends PropertiesPanel
{
  // DEFAULT VALUE FACET

  protected static final String[] SHOW_HIDE = {"Show", "Hide"};

  // DESCRIPTOR FACET

  /**
   * The field actor descriptors to edit.
   */
  protected FieldActorDescriptor[] descriptors;

  // CONSTRUCTORS

  /**
   * Constructor
   */
  protected FieldActorPropertiesPanel(Viewer xviewer,
				      FieldActorDescriptor[] xdescriptors)
  {
    super(xviewer);

    descriptors = xdescriptors;
  }

  // INIT FACET

  /**
   * Set the field actor descriptors
   */
  public void setDescriptors(FieldActorDescriptor[] xdescriptors)
  {
    descriptors = xdescriptors;
    initValues();
  }
}
