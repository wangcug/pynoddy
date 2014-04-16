/*
	This file was generated by XVT-Design 4.5, a product of:

		XVT Software Inc.
		4900 Pearl East Circle
		Boulder, CO USA 80301
		303-443-4223, fax 303-443-0969

	Generated on Tue Sep 02 10:34:59 1997
*/
/* TAG BEGIN SPCL:Pre_Header */
/* TAG END SPCL:Pre_Header */

#include "xvt.h"
#include "xvtcm.h"
#include "nodInc.h"

/* 
	Information about the window
*/
#define WIN_RES_ID BLOCK_CONVERT_WINDOW
#define WIN_FLAGS 0x810L
#define WIN_CLASS ""
#define WIN_BORDER W_DOC
/* TAG BEGIN SPCL:Obj_Decl */
/* TAG END SPCL:Obj_Decl */

/*
	Handler for window BLOCK_CONVERT_WINDOW ("Block Conversion Options")
*/
long XVT_CALLCONV1
#if XVT_CC_PROTO
BLOCK_CONVERT_WINDOW_eh XVT_CALLCONV2 (WINDOW xdWindow, EVENT *xdEvent)
#else
BLOCK_CONVERT_WINDOW_eh XVT_CALLCONV2 (xdWindow, xdEvent)
WINDOW xdWindow;
EVENT *xdEvent;
#endif
{
	short xdControlId = xdEvent->v.ctl.id;
	/* TAG BEGIN SPCL:Var_Decl */
	/* TAG END SPCL:Var_Decl */

	switch (xdEvent->type) {
	case E_CREATE:
		/*
			Window has been created; first event sent to newly-created
			window.
		*/
		{
		/* TAG BEGIN EVNT:Create */
		/* TAG END EVNT:Create */
		}
		break;
	case E_DESTROY:
		/*
			Window has been closed; last event sent to window.
		*/
		xdRemoveHelpAssoc( xdWindow );
		{
		/* TAG BEGIN EVNT:Destroy */
		/* TAG END EVNT:Destroy */
		}
		break;
	case E_FOCUS:
		{
		/* TAG BEGIN EVNT:Focus */
		      /*
		         Window has lost or gained focus.
		      */
		      if (xdEvent->v.active) {
		         /*
		            Window has gained focus
		         */
		      } else {
		         /*
		            Window has lost focus
		         */
		      }
		/* TAG END EVNT:Focus */
		}
		break;
	case E_SIZE:
		/*
			Size of window has been set or changed; sent when window is
			created or subsequently resized by user or via xvt_vobj_move.
		*/
		{
		/* TAG BEGIN EVNT:Size */
		/* TAG END EVNT:Size */
		}
		break;
	case E_UPDATE:
		/*
			Window requires updating.
		*/
		{
		/* TAG BEGIN EVNT:Update */
		      xvt_dwin_clear(xdWindow, (COLOR)xvt_vobj_get_attr(xdWindow, ATTR_BACK_COLOR));
		/* TAG END EVNT:Update */
		}
		break;
	case E_CLOSE:
		/*
			Request to close window; user operated "close" menu item on
			window system menu, or operated "close" control on window
			frame. Not sent if Close on File menu is issued. Window not
			closed unless xvt_vobj_destroy is called.
		*/
		{
		/* TAG BEGIN EVNT:Close */
		      xvt_vobj_destroy(xdWindow);
		/* TAG END EVNT:Close */
		}
		break;
	case E_CHAR:
		/*
			Character typed.
		*/
		{
		/* TAG BEGIN EVNT:Char */
		         /* *********************************************** */
		         /* make a RETURN key activate the window OK Button */
		      if (xdEvent->v.chr.ch == '\r')
		      {
		         xdEvent->type = E_CONTROL;
		         xdEvent->v.ctl.id = BLOCK_CONVERT_WINDOW_OK;
		         xvt_win_dispatch_event (xdWindow, xdEvent);
		      }
		/* TAG END EVNT:Char */
		}
		break;
	case E_MOUSE_UP:
		/*
			Mouse was released
		*/
		{
		/* TAG BEGIN EVNT:Mouse_Up */
		/* TAG END EVNT:Mouse_Up */
		}
		break;
	case E_MOUSE_DOWN:
		/*
			Mouse was pressed
		*/
		{
		/* TAG BEGIN EVNT:Mouse_Down */
		/* TAG END EVNT:Mouse_Down */
		}
		break;
	case E_MOUSE_DBL:
		/*
			Mouse was double clicked
		*/
		{
		/* TAG BEGIN EVNT:Mouse_Dbl */
		/* TAG END EVNT:Mouse_Dbl */
		}
		break;
	case E_MOUSE_MOVE:
		/*
			Mouse was moved
		*/
		{
		/* TAG BEGIN EVNT:Mouse_Move */
		/* TAG END EVNT:Mouse_Move */
		}
		break;
	case E_HSCROLL:
		{
		/* TAG BEGIN EVNT:Hscroll */
		      /*
		         Horizontal scrollbar on frame was operated
		      */
		      switch (xdEvent->v.scroll.what) {
		      case SC_LINE_UP:
		         break;
		      case SC_LINE_DOWN:
		         break;
		      case SC_PAGE_UP:
		         break;
		      case SC_PAGE_DOWN:
		         break;
		      case SC_THUMB:
		         break;
		      case SC_THUMBTRACK:
		         break;
		      default:
		         break;
		      }
		/* TAG END EVNT:Hscroll */
		}
		break;
	case E_VSCROLL:
		{
		/* TAG BEGIN EVNT:Vscroll */
		      /*
		         Vertical scrollbar on frame was operated
		      */
		      switch (xdEvent->v.scroll.what) {
		      case SC_LINE_UP:
		         break;
		      case SC_LINE_DOWN:
		         break;
		      case SC_PAGE_UP:
		         break;
		      case SC_PAGE_DOWN:
		         break;
		      case SC_THUMB:
		         break;
		      case SC_THUMBTRACK:
		         break;
		      default:
		         break;
		      }
		/* TAG END EVNT:Vscroll */
		}
		break;
	case E_COMMAND:
		/*
			User issued command on window menu bar (menu bar at top of
			screen for Mac/CH).
		*/
		{
		/* TAG BEGIN EVNT:Command */
		      /*
		         No menubar was associated with this window
		      */
		/* TAG END EVNT:Command */
		}
		break;
	case E_CONTROL:
		/*
			User operated control in window.
		*/
		{
		/* TAG BEGIN SPCL:Control_Decl */
		/* TAG END SPCL:Control_Decl */

		switch(xdControlId) {
		case BLOCK_CONVERT_FLIP_X: /* "Flip About X Axis" */
			{
			/* TAG BEGIN BLOCK_CONVERT_FLIP_X EVNT:Control */
			         WINDOW ctl_win = xvt_win_get_ctl(xdWindow, BLOCK_CONVERT_FLIP_X);
			         xvt_ctl_set_checked(ctl_win, (BOOLEAN) (!xvt_ctl_is_checked(ctl_win)));
			/* TAG END BLOCK_CONVERT_FLIP_X EVNT:Control */
			}
			break;
		case BLOCK_CONVERT_FLIP_Y: /* "Flip About Y Axis" */
			{
			/* TAG BEGIN BLOCK_CONVERT_FLIP_Y EVNT:Control */
			         WINDOW ctl_win = xvt_win_get_ctl(xdWindow, BLOCK_CONVERT_FLIP_Y);
			         xvt_ctl_set_checked(ctl_win, (BOOLEAN) (!xvt_ctl_is_checked(ctl_win)));
			/* TAG END BLOCK_CONVERT_FLIP_Y EVNT:Control */
			}
			break;
		case BLOCK_CONVERT_FLIP_Z: /* "Flip About Z Axis" */
			{
			/* TAG BEGIN BLOCK_CONVERT_FLIP_Z EVNT:Control */
			         WINDOW ctl_win = xvt_win_get_ctl(xdWindow, BLOCK_CONVERT_FLIP_Z);
			         xvt_ctl_set_checked(ctl_win, (BOOLEAN) (!xvt_ctl_is_checked (ctl_win)));
			/* TAG END BLOCK_CONVERT_FLIP_Z EVNT:Control */
			}
			break;
		case BLOCK_CONVERT_WINDOW_OK: /* "OK" */
			{
			/* TAG BEGIN BLOCK_CONVERT_WINDOW_OK EVNT:Control */
			         FILE_SPEC vulcanBlock, oldNodBlock, noddyBlock;
			         int gotVulcanFile = FALSE, gotOldNodFile = FALSE;
			         int flipX, flipY, flipZ;
			         WINDOW win;
			         int fileType;
			         
			         fileType = (int)  xvt_vobj_get_data (xdWindow);
			         
			         win =  xvt_win_get_ctl(xdWindow, BLOCK_CONVERT_FLIP_X);
			         flipX = xvt_ctl_is_checked(win);
			         win =  xvt_win_get_ctl(xdWindow, BLOCK_CONVERT_FLIP_Y);
			         flipY = xvt_ctl_is_checked(win);
			         win =  xvt_win_get_ctl(xdWindow, BLOCK_CONVERT_FLIP_Z);
			         flipZ = xvt_ctl_is_checked(win);
			         if (fileType == 1)
			         {
#if (XVTWS == MACWS)
			            strcpy (vulcanBlock.type, "TEXT");
#else
			            strcpy (vulcanBlock.type, "vul");
#endif
			            strcpy (vulcanBlock.name, "");
			            getDefaultDirectory(&(vulcanBlock.dir));
			            switch (xvt_dm_post_file_open(&vulcanBlock, "Vulvan Block to Convert...")) {
			            case FL_OK:
			               if (strlen(vulcanBlock.name) == 0)
			                  xvt_dm_post_error ("Error, No file Specified");
			               else
			               {
			                  setDefaultDirectory(&(vulcanBlock.dir));
			                  gotVulcanFile = TRUE;
			               }
			               break;
			            case FL_BAD:
			               break;
			            case FL_CANCEL:
			               break;
			            }
			            if (gotVulcanFile)
			            {
#if (XVTWS == MACWS)
			               strcpy (noddyBlock.type, "TEXT");
#else
			               strcpy (noddyBlock.type, "g00");
#endif
			               strcpy (noddyBlock.name, vulcanBlock.name);
			               addFileExtention(noddyBlock.name, ".g00");
			               getDefaultDirectory(&(noddyBlock.dir));
			               switch (xvt_dm_post_file_save(&noddyBlock, "Noddy Block to Save as...")) {
			               case FL_OK:
			                  if (strlen(noddyBlock.name) == 0)
			                  {
			                     xvt_dm_post_error ("Error, No file Specified");
			                     break;
			                  }
			         
			                  setDefaultDirectory(&(noddyBlock.dir));
			                  convertVulcanBlockToNoddy (&vulcanBlock, &noddyBlock,
			                        flipX, flipY, flipZ);
			                  break;
			               case FL_BAD:
			                  break;
			               case FL_CANCEL:
			                  break;
			               }
			            }
			         }
			         if (fileType == 2)
			         {
#if (XVTWS == MACWS)
			            strcpy (oldNodBlock.type, "TEXT");
#else
			            strcpy (oldNodBlock.type, "blk");
#endif
			            strcpy (oldNodBlock.name, "");
			            getDefaultDirectory(&(oldNodBlock.dir));
			            switch (xvt_dm_post_file_open(&oldNodBlock, "Old Noddy Block to Convert...")) {
			            case FL_OK:
			               if (strlen(oldNodBlock.name) == 0)
			                  xvt_dm_post_error ("Error, No file Specified");
			               else
			               {
			                  setDefaultDirectory(&(oldNodBlock.dir));
			                  gotOldNodFile = TRUE;
			               }
			               break;
			            case FL_BAD:
			               break;
			            case FL_CANCEL:
			               break;
			            }
			            if (gotOldNodFile)
			            {
#if (XVTWS == MACWS)
			               strcpy (noddyBlock.type, "TEXT");
#else
			               strcpy (noddyBlock.type, "g00");
#endif
			               strcpy (noddyBlock.name, "");
			               strcpy (noddyBlock.name, oldNodBlock.name);
			               addFileExtention(noddyBlock.name, ".g00");
			               getDefaultDirectory(&(noddyBlock.dir));
			               switch (xvt_dm_post_file_save(&noddyBlock, "Noddy Block to Save as...")) {
			               case FL_OK:
			                  if (strlen(noddyBlock.name) == 0)
			                  {
			                     xvt_dm_post_error ("Error, No file Specified");
			                     break;
			                  }
			         
			                  setDefaultDirectory(&(noddyBlock.dir));
			                  convertOldBlkToNewBlk (&oldNodBlock, &noddyBlock,
			                           flipX, flipY, flipZ);
			                  break;
			               case FL_BAD:
			                  break;
			               case FL_CANCEL:
			                  break;
			               }
			            }
			         }
			         xvt_vobj_destroy(xdWindow);  /* Close the flip Window */
			/* TAG END BLOCK_CONVERT_WINDOW_OK EVNT:Control */
			}
			break;
		case BLOCK_CONVERT_WINDOW_P_C2: /* "Cancel" */
			{
			/* TAG BEGIN BLOCK_CONVERT_WINDOW_P_C2 EVNT:Control */
			         xvt_vobj_destroy(xdWindow);
			/* TAG END BLOCK_CONVERT_WINDOW_P_C2 EVNT:Control */
			}
			break;
		case BLOCK_CONVERT_WINDOW_P_C3: /* "Help..." */
			{
			/* TAG BEGIN BLOCK_CONVERT_WINDOW_P_C3 EVNT:Control */
			displayHelp("expg00.htm");
			/* TAG END BLOCK_CONVERT_WINDOW_P_C3 EVNT:Control */
			}
			break;
		default:
			break;
		}
		}
		break;
	case E_FONT:
		/*
			User issued font command on window menu bar (menu bar at top of
			screen for Mac/CH).
		*/
		{
		/* TAG BEGIN EVNT:Font */
		/* TAG END EVNT:Font */
		}
		break;
	case E_TIMER:
		/*
			Timer associated with window went off.
		*/
		{
		/* TAG BEGIN EVNT:Timer */
		/* TAG END EVNT:Timer */
		}
		break;
	case E_USER:
		/*
			Application initiated.
		*/
		{
		/* TAG BEGIN EVNT:User */
		      switch (xdEvent->v.user.id) {
		      case -1:
		      default:
		         break;
		      }
		/* TAG END EVNT:User */
		}
		break;
	default:
		break;
	}
	/* TAG BEGIN SPCL:Bottom */
#ifdef XVT_R40_TXEDIT_BEHAVIOR
	   xvt_tx_process_event(xdWindow, xdEvent);
#endif
	/* TAG END SPCL:Bottom */
	return 0L;
}