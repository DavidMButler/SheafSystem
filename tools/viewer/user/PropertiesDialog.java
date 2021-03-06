
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

import tools.common.gui.*;
import tools.viewer.render.*;

import java.awt.event.*;
import javax.swing.*;
import java.util.*;

/**
 *  A non modal dialog for actor properties editing.
 */
public class PropertiesDialog extends LPSDialog
{
  /**
   * The properties panel
   */
  public PropertiesPanel panel;

  /**
   * Default constructor
   */
  public PropertiesDialog(JFrame xowner, String xtitle, PropertiesPanel xpanel)
  {
    super(xowner, xtitle);

    setModal(true);

    panel = xpanel;
    this.add(panel);

    panel.setDialog(this);

    pack();
    setLocationRelativeTo(xowner);

    // Use a WindowListener to handle hiding this dialog.

    setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
    addWindowListener(
      new WindowAdapter()
      {
        public void windowClosing(WindowEvent e)
        {
          setVisible(false);
        }
      }
    );
  }

  /**
   * Accessor for the properties panel.
   */
  public PropertiesPanel getPropertiesPanel()
  {
    return panel;
  }
}
