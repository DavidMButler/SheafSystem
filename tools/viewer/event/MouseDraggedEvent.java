
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

package tools.viewer.event;

import tools.viewer.render.*;

import java.awt.event.*;

/**
 *
 * Implementation <code>RenderThreadEvent</code> for
 * processing a mouse dragged event.
 *
 */
public class MouseDraggedEvent extends RenderThreadEvent
{
  /**
   * The <code>MouseEvent</code>
   */
  protected MouseEvent mouseEvent;

  /**
   * The constructor
   */
  public MouseDraggedEvent(MouseEvent xmouseEvent)
  {
    mouseEvent = xmouseEvent;
  }

  /**
   * Handle this <code>MouseDraggedEvent</code>
   */
  public void handle(RenderThread xrenderThread)
  {
    if(abort)
      return;

    xrenderThread.mouseDragged(mouseEvent);
  }
}
