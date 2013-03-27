/**
 *  Classname: MouseReleasedEvent
 *
 *  @author $Author: jebutler $
 *
 *  @version $RCSfile: MouseReleasedEvent.java,v $ $Revision: 1.7 $
 *
 *  $Date: 2013/01/12 17:17:58 $
 *
 *  Copyright (c) 2013 Limit Point Systems, Inc.
 */

package tools.viewer.event;

import tools.viewer.render.*;

import java.awt.event.*;

/**
 *
 * Implementation <code>RenderThreadEvent</code> for
 * processing a mouse released event.
 *
 */
public class MouseReleasedEvent extends RenderThreadEvent
{
  /**
   * The <code>MouseEvent</code>
   */
  protected MouseEvent mouseEvent;

  /**
   * The constructor
   */
  public MouseReleasedEvent(MouseEvent xmouseEvent)
  {
    mouseEvent = xmouseEvent;
  }

  /**
   * Handle this <code>MouseReleasedEvent</code>
   */
  public void handle(RenderThread xrenderThread)
  {
    if(abort)
      return;

    xrenderThread.mouseReleased(mouseEvent);
  }
}
