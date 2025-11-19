// Copyright (c) 2025 渟雲. All rights reserved.
//
// Licensed under the TOSSRCU 2025.9 License (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//  https://raw.githubusercontent.com/M3351AN/M3351AN/9e7630a8511b8306c62952ca1a4f1ce0cc5b784a/LICENSE
//
// -----------------------------------------------------------------------------
// File: dll_proxy.h
// Author: 渟雲(quq[at]outlook.it)
// Date: 2025-11-19
//
// Description:
//   This file includes functions of Dll Proxy.
//
// -----------------------------------------------------------------------------

#pragma once

#ifndef DLL_PROXY_H
#define DLL_PROXY_H
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif  // WIN32_LEAN_AND_MEAN
#include <Windows.h>
#pragma region Proxy
struct user32_dll {
  HMODULE dll;
  FARPROC oActivateKeyboardLayout;
  FARPROC oAddClipboardFormatListener;
  FARPROC oAddVisualIdentifier;
  FARPROC oAdjustWindowRect;
  FARPROC oAdjustWindowRectEx;
  FARPROC oAdjustWindowRectExForDpi;
  FARPROC oAlignRects;
  FARPROC oAllowForegroundActivation;
  FARPROC oAllowSetForegroundWindow;
  FARPROC oAnimateWindow;
  FARPROC oAnyPopup;
  FARPROC oAppendMenuA;
  FARPROC oAppendMenuW;
  FARPROC oApplyWindowAction;
  FARPROC oAreDpiAwarenessContextsEqual;
  FARPROC oArrangeIconicWindows;
  FARPROC oAttachThreadInput;
  FARPROC oBeginDeferWindowPos;
  FARPROC oBeginPaint;
  FARPROC oBlockInput;
  FARPROC oBringWindowToTop;
  FARPROC oBroadcastSystemMessage;
  FARPROC oBroadcastSystemMessageA;
  FARPROC oBroadcastSystemMessageExA;
  FARPROC oBroadcastSystemMessageExW;
  FARPROC oBroadcastSystemMessageW;
  FARPROC oBuildReasonArray;
  FARPROC oCalcMenuBar;
  FARPROC oCalculatePopupWindowPosition;
  FARPROC oCallMsgFilter;
  FARPROC oCallMsgFilterA;
  FARPROC oCallMsgFilterW;
  FARPROC oCallNextHookEx;
  FARPROC oCallWindowProcA;
  FARPROC oCallWindowProcW;
  FARPROC oCancelShutdown;
  FARPROC oCascadeChildWindows;
  FARPROC oCascadeWindows;
  FARPROC oChangeClipboardChain;
  FARPROC oChangeDisplaySettingsA;
  FARPROC oChangeDisplaySettingsExA;
  FARPROC oChangeDisplaySettingsExW;
  FARPROC oChangeDisplaySettingsW;
  FARPROC oChangeMenuA;
  FARPROC oChangeMenuW;
  FARPROC oChangeWindowMessageFilter;
  FARPROC oChangeWindowMessageFilterEx;
  FARPROC oCharLowerA;
  FARPROC oCharLowerBuffA;
  FARPROC oCharLowerBuffW;
  FARPROC oCharLowerW;
  FARPROC oCharNextA;
  FARPROC oCharNextExA;
  FARPROC oCharNextW;
  FARPROC oCharPrevA;
  FARPROC oCharPrevExA;
  FARPROC oCharPrevW;
  FARPROC oCharToOemA;
  FARPROC oCharToOemBuffA;
  FARPROC oCharToOemBuffW;
  FARPROC oCharToOemW;
  FARPROC oCharUpperA;
  FARPROC oCharUpperBuffA;
  FARPROC oCharUpperBuffW;
  FARPROC oCharUpperW;
  FARPROC oCheckBannedOneCoreTransformApi;
  FARPROC oCheckDBCSEnabledExt;
  FARPROC oCheckDlgButton;
  FARPROC oCheckMenuItem;
  FARPROC oCheckMenuRadioItem;
  FARPROC oCheckProcessForClipboardAccess;
  FARPROC oCheckProcessSession;
  FARPROC oCheckRadioButton;
  FARPROC oCheckWindowThreadDesktop;
  FARPROC oChildWindowFromPoint;
  FARPROC oChildWindowFromPointEx;
  FARPROC oCliImmSetHotKey;
  FARPROC oClientThreadSetup;
  FARPROC oClientToScreen;
  FARPROC oClipCursor;
  FARPROC oCloseClipboard;
  FARPROC oCloseDesktop;
  FARPROC oCloseGestureInfoHandle;
  FARPROC oCloseTouchInputHandle;
  FARPROC oCloseWindow;
  FARPROC oCloseWindowStation;
  FARPROC oConsoleControl;
  FARPROC oControlMagnification;
  FARPROC oConvertToInterceptWindow;
  FARPROC oCopyAcceleratorTableA;
  FARPROC oCopyAcceleratorTableW;
  FARPROC oCopyIcon;
  FARPROC oCopyImage;
  FARPROC oCopyRect;
  FARPROC oCountClipboardFormats;
  FARPROC oCreateAcceleratorTableA;
  FARPROC oCreateAcceleratorTableW;
  FARPROC oCreateCaret;
  FARPROC oCreateCursor;
  FARPROC oCreateDCompositionHwndTarget;
  FARPROC oCreateDesktopA;
  FARPROC oCreateDesktopExA;
  FARPROC oCreateDesktopExW;
  FARPROC oCreateDesktopW;
  FARPROC oCreateDialogIndirectParamA;
  FARPROC oCreateDialogIndirectParamAorW;
  FARPROC oCreateDialogIndirectParamW;
  FARPROC oCreateDialogParamA;
  FARPROC oCreateDialogParamW;
  FARPROC oCreateIcon;
  FARPROC oCreateIconFromResource;
  FARPROC oCreateIconFromResourceEx;
  FARPROC oCreateIconIndirect;
  FARPROC oCreateMDIWindowA;
  FARPROC oCreateMDIWindowW;
  FARPROC oCreateMenu;
  FARPROC oCreatePopupMenu;
  FARPROC oCreateSyntheticPointerDevice;
  FARPROC oCreateSyntheticPointerDevice2;
  FARPROC oCreateSystemThreads;
  FARPROC oCreateWindowExA;
  FARPROC oCreateWindowExW;
  FARPROC oCreateWindowInBand;
  FARPROC oCreateWindowInBandEx;
  FARPROC oCreateWindowIndirect;
  FARPROC oCreateWindowStationA;
  FARPROC oCreateWindowStationW;
  FARPROC oCsrBroadcastSystemMessageExW;
  FARPROC oCtxInitUser32;
  FARPROC oDdeAbandonTransaction;
  FARPROC oDdeAccessData;
  FARPROC oDdeAddData;
  FARPROC oDdeClientTransaction;
  FARPROC oDdeCmpStringHandles;
  FARPROC oDdeConnect;
  FARPROC oDdeConnectList;
  FARPROC oDdeCreateDataHandle;
  FARPROC oDdeCreateStringHandleA;
  FARPROC oDdeCreateStringHandleW;
  FARPROC oDdeDisconnect;
  FARPROC oDdeDisconnectList;
  FARPROC oDdeEnableCallback;
  FARPROC oDdeFreeDataHandle;
  FARPROC oDdeFreeStringHandle;
  FARPROC oDdeGetData;
  FARPROC oDdeGetLastError;
  FARPROC oDdeGetQualityOfService;
  FARPROC oDdeImpersonateClient;
  FARPROC oDdeInitializeA;
  FARPROC oDdeInitializeW;
  FARPROC oDdeKeepStringHandle;
  FARPROC oDdeNameService;
  FARPROC oDdePostAdvise;
  FARPROC oDdeQueryConvInfo;
  FARPROC oDdeQueryNextServer;
  FARPROC oDdeQueryStringA;
  FARPROC oDdeQueryStringW;
  FARPROC oDdeReconnect;
  FARPROC oDdeSetQualityOfService;
  FARPROC oDdeSetUserHandle;
  FARPROC oDdeUnaccessData;
  FARPROC oDdeUninitialize;
  FARPROC oDefDlgProcA;
  FARPROC oDefDlgProcW;
  FARPROC oDefFrameProcA;
  FARPROC oDefFrameProcW;
  FARPROC oDefMDIChildProcA;
  FARPROC oDefMDIChildProcW;
  FARPROC oDefRawInputProc;
  FARPROC oDefWindowProcA;
  FARPROC oDefWindowProcW;
  FARPROC oDeferWindowPos;
  FARPROC oDeferWindowPosAndBand;
  FARPROC oDelegateInput;
  FARPROC oDeleteMenu;
  FARPROC oDeregisterShellHookWindow;
  FARPROC oDestroyAcceleratorTable;
  FARPROC oDestroyCaret;
  FARPROC oDestroyCursor;
  FARPROC oDestroyDCompositionHwndTarget;
  FARPROC oDestroyIcon;
  FARPROC oDestroyMenu;
  FARPROC oDestroyReasons;
  FARPROC oDestroySyntheticPointerDevice;
  FARPROC oDestroyWindow;
  FARPROC oDialogBoxIndirectParamA;
  FARPROC oDialogBoxIndirectParamAorW;
  FARPROC oDialogBoxIndirectParamW;
  FARPROC oDialogBoxParamA;
  FARPROC oDialogBoxParamW;
  FARPROC oDisableProcessWindowsGhosting;
  FARPROC oDispatchMessageA;
  FARPROC oDispatchMessageW;
  FARPROC oDisplayConfigGetDeviceInfo;
  FARPROC oDisplayConfigSetDeviceInfo;
  FARPROC oDisplayExitWindowsWarnings;
  FARPROC oDlgDirListA;
  FARPROC oDlgDirListComboBoxA;
  FARPROC oDlgDirListComboBoxW;
  FARPROC oDlgDirListW;
  FARPROC oDlgDirSelectComboBoxExA;
  FARPROC oDlgDirSelectComboBoxExW;
  FARPROC oDlgDirSelectExA;
  FARPROC oDlgDirSelectExW;
  FARPROC oDoSoundConnect;
  FARPROC oDoSoundDisconnect;
  FARPROC oDragDetect;
  FARPROC oDragObject;
  FARPROC oDrawAnimatedRects;
  FARPROC oDrawCaption;
  FARPROC oDrawCaptionTempA;
  FARPROC oDrawCaptionTempW;
  FARPROC oDrawEdge;
  FARPROC oDrawFocusRect;
  FARPROC oDrawFrame;
  FARPROC oDrawFrameControl;
  FARPROC oDrawIcon;
  FARPROC oDrawIconEx;
  FARPROC oDrawMenuBar;
  FARPROC oDrawMenuBarTemp;
  FARPROC oDrawStateA;
  FARPROC oDrawStateW;
  FARPROC oDrawTextA;
  FARPROC oDrawTextExA;
  FARPROC oDrawTextExW;
  FARPROC oDrawTextW;
  FARPROC oDwmGetDxRgn;
  FARPROC oDwmGetDxSharedSurface;
  FARPROC oDwmGetRemoteSessionOcclusionEvent;
  FARPROC oDwmGetRemoteSessionOcclusionState;
  FARPROC oDwmKernelShutdown;
  FARPROC oDwmKernelStartup;
  FARPROC oDwmLockScreenUpdates;
  FARPROC oDwmValidateWindow;
  FARPROC oDwmWindowNotificationsEnabled;
  FARPROC oEditWndProc;
  FARPROC oEmptyClipboard;
  FARPROC oEnableMenuItem;
  FARPROC oEnableMouseInPointer;
  FARPROC oEnableNonClientDpiScaling;
  FARPROC oEnableOneCoreTransformMode;
  FARPROC oEnableScrollBar;
  FARPROC oEnableSessionForMMCSS;
  FARPROC oEnableWindow;
  FARPROC oEnableWindowShellWindowManagementBehavior;
  FARPROC oEndDeferWindowPos;
  FARPROC oEndDeferWindowPosEx;
  FARPROC oEndDialog;
  FARPROC oEndMenu;
  FARPROC oEndPaint;
  FARPROC oEndTask;
  FARPROC oEnterMoveSizeLoop;
  FARPROC oEnterReaderModeHelper;
  FARPROC oEnumChildWindows;
  FARPROC oEnumClipboardFormats;
  FARPROC oEnumDesktopWindows;
  FARPROC oEnumDesktopsA;
  FARPROC oEnumDesktopsW;
  FARPROC oEnumDisplayDevicesA;
  FARPROC oEnumDisplayDevicesW;
  FARPROC oEnumDisplayMonitors;
  FARPROC oEnumDisplaySettingsA;
  FARPROC oEnumDisplaySettingsExA;
  FARPROC oEnumDisplaySettingsExW;
  FARPROC oEnumDisplaySettingsW;
  FARPROC oEnumPropsA;
  FARPROC oEnumPropsExA;
  FARPROC oEnumPropsExW;
  FARPROC oEnumPropsW;
  FARPROC oEnumThreadWindows;
  FARPROC oEnumWindowStationsA;
  FARPROC oEnumWindowStationsW;
  FARPROC oEnumWindows;
  FARPROC oEqualRect;
  FARPROC oEvaluateProximityToPolygon;
  FARPROC oEvaluateProximityToRect;
  FARPROC oExcludeUpdateRgn;
  FARPROC oExitWindowsEx;
  FARPROC oFillRect;
  FARPROC oFindWindowA;
  FARPROC oFindWindowExA;
  FARPROC oFindWindowExW;
  FARPROC oFindWindowW;
  FARPROC oFlashWindow;
  FARPROC oFlashWindowEx;
  FARPROC oFrameRect;
  FARPROC oFreeDDElParam;
  FARPROC oFrostCrashedWindow;
  FARPROC oGetActiveWindow;
  FARPROC oGetAltTabInfo;
  FARPROC oGetAltTabInfoA;
  FARPROC oGetAltTabInfoW;
  FARPROC oGetAncestor;
  FARPROC oGetAppCompatFlags;
  FARPROC oGetAppCompatFlags2;
  FARPROC oGetAsyncKeyState;
  FARPROC oGetAutoRotationState;
  FARPROC oGetAwarenessFromDpiAwarenessContext;
  FARPROC oGetCIMSSM;
  FARPROC oGetCapture;
  FARPROC oGetCaretBlinkTime;
  FARPROC oGetCaretPos;
  FARPROC oGetClassInfoA;
  FARPROC oGetClassInfoExA;
  FARPROC oGetClassInfoExW;
  FARPROC oGetClassInfoW;
  FARPROC oGetClassLongA;
  FARPROC oGetClassLongPtrA;
  FARPROC oGetClassLongPtrW;
  FARPROC oGetClassLongW;
  FARPROC oGetClassNameA;
  FARPROC oGetClassNameW;
  FARPROC oGetClassWord;
  FARPROC oGetClientRect;
  FARPROC oGetClipCursor;
  FARPROC oGetClipboardAccessToken;
  FARPROC oGetClipboardData;
  FARPROC oGetClipboardFormatNameA;
  FARPROC oGetClipboardFormatNameW;
  FARPROC oGetClipboardMetadata;
  FARPROC oGetClipboardOwner;
  FARPROC oGetClipboardSequenceNumber;
  FARPROC oGetClipboardViewer;
  FARPROC oGetComboBoxInfo;
  FARPROC oGetCurrentInputMessageSource;
  FARPROC oGetCurrentMonitorTopologyId;
  FARPROC oGetCursor;
  FARPROC oGetCursorFrameInfo;
  FARPROC oGetCursorInfo;
  FARPROC oGetCursorPos;
  FARPROC oGetDC;
  FARPROC oGetDCEx;
  FARPROC oGetDCompositionHwndBitmap;
  FARPROC oGetDesktopID;
  FARPROC oGetDesktopWindow;
  FARPROC oGetDialogBaseUnits;
  FARPROC oGetDialogControlDpiChangeBehavior;
  FARPROC oGetDialogDpiChangeBehavior;
  FARPROC oGetDisplayAutoRotationPreferences;
  FARPROC oGetDisplayConfigBufferSizes;
  FARPROC oGetDlgCtrlID;
  FARPROC oGetDlgItem;
  FARPROC oGetDlgItemInt;
  FARPROC oGetDlgItemTextA;
  FARPROC oGetDlgItemTextW;
  FARPROC oGetDoubleClickTime;
  FARPROC oGetDpiAwarenessContextForProcess;
  FARPROC oGetDpiForMonitorInternal;
  FARPROC oGetDpiForSystem;
  FARPROC oGetDpiForWindow;
  FARPROC oGetDpiFromDpiAwarenessContext;
  FARPROC oGetExtendedPointerDeviceProperty;
  FARPROC oGetFocus;
  FARPROC oGetForegroundWindow;
  FARPROC oGetGUIThreadInfo;
  FARPROC oGetGestureConfig;
  FARPROC oGetGestureExtraArgs;
  FARPROC oGetGestureInfo;
  FARPROC oGetGuiResources;
  FARPROC oGetIconInfo;
  FARPROC oGetIconInfoExA;
  FARPROC oGetIconInfoExW;
  FARPROC oGetInputDesktop;
  FARPROC oGetInputLocaleInfo;
  FARPROC oGetInputState;
  FARPROC oGetInternalWindowPos;
  FARPROC oGetKBCodePage;
  FARPROC oGetKeyNameTextA;
  FARPROC oGetKeyNameTextW;
  FARPROC oGetKeyState;
  FARPROC oGetKeyboardLayout;
  FARPROC oGetKeyboardLayoutList;
  FARPROC oGetKeyboardLayoutNameA;
  FARPROC oGetKeyboardLayoutNameW;
  FARPROC oGetKeyboardState;
  FARPROC oGetKeyboardType;
  FARPROC oGetLastActivePopup;
  FARPROC oGetLastInputInfo;
  FARPROC oGetLayeredWindowAttributes;
  FARPROC oGetListBoxInfo;
  FARPROC oGetMagnificationDesktopColorEffect;
  FARPROC oGetMagnificationDesktopMagnification;
  FARPROC oGetMagnificationDesktopSamplingMode;
  FARPROC oGetMagnificationLensCtxInformation;
  FARPROC oGetMenu;
  FARPROC oGetMenuBarInfo;
  FARPROC oGetMenuCheckMarkDimensions;
  FARPROC oGetMenuContextHelpId;
  FARPROC oGetMenuDefaultItem;
  FARPROC oGetMenuInfo;
  FARPROC oGetMenuItemCount;
  FARPROC oGetMenuItemID;
  FARPROC oGetMenuItemInfoA;
  FARPROC oGetMenuItemInfoW;
  FARPROC oGetMenuItemRect;
  FARPROC oGetMenuState;
  FARPROC oGetMenuStringA;
  FARPROC oGetMenuStringW;
  FARPROC oGetMessageA;
  FARPROC oGetMessageExtraInfo;
  FARPROC oGetMessagePos;
  FARPROC oGetMessageTime;
  FARPROC oGetMessageW;
  FARPROC oGetMonitorInfoA;
  FARPROC oGetMonitorInfoW;
  FARPROC oGetMouseMovePointsEx;
  FARPROC oGetNextDlgGroupItem;
  FARPROC oGetNextDlgTabItem;
  FARPROC oGetOpenClipboardWindow;
  FARPROC oGetParent;
  FARPROC oGetPhysicalCursorPos;
  FARPROC oGetPointerCursorId;
  FARPROC oGetPointerDevice;
  FARPROC oGetPointerDeviceCursors;
  FARPROC oGetPointerDeviceInputSpace;
  FARPROC oGetPointerDeviceOrientation;
  FARPROC oGetPointerDeviceProperties;
  FARPROC oGetPointerDeviceRects;
  FARPROC oGetPointerDevices;
  FARPROC oGetPointerFrameArrivalTimes;
  FARPROC oGetPointerFrameInfo;
  FARPROC oGetPointerFrameInfoHistory;
  FARPROC oGetPointerFramePenInfo;
  FARPROC oGetPointerFramePenInfoHistory;
  FARPROC oGetPointerFrameTimes;
  FARPROC oGetPointerFrameTouchInfo;
  FARPROC oGetPointerFrameTouchInfoHistory;
  FARPROC oGetPointerFrameTouchpadInfo;
  FARPROC oGetPointerFrameTouchpadInfoHistory;
  FARPROC oGetPointerInfo;
  FARPROC oGetPointerInfoHistory;
  FARPROC oGetPointerInputTransform;
  FARPROC oGetPointerPenInfo;
  FARPROC oGetPointerPenInfoHistory;
  FARPROC oGetPointerTouchInfo;
  FARPROC oGetPointerTouchInfoHistory;
  FARPROC oGetPointerTouchpadInfo;
  FARPROC oGetPointerTouchpadInfoHistory;
  FARPROC oGetPointerType;
  FARPROC oGetPriorityClipboardFormat;
  FARPROC oGetProcessDefaultLayout;
  FARPROC oGetProcessDpiAwarenessInternal;
  FARPROC oGetProcessUIContextInformation;
  FARPROC oGetProcessWindowStation;
  FARPROC oGetProgmanWindow;
  FARPROC oGetPropA;
  FARPROC oGetPropW;
  FARPROC oGetQueueStatus;
  FARPROC oGetRawInputBuffer;
  FARPROC oGetRawInputData;
  FARPROC oGetRawInputDeviceInfoA;
  FARPROC oGetRawInputDeviceInfoW;
  FARPROC oGetRawInputDeviceList;
  FARPROC oGetRawPointerDeviceData;
  FARPROC oGetReasonTitleFromReasonCode;
  FARPROC oGetRegisteredRawInputDevices;
  FARPROC oGetScrollBarInfo;
  FARPROC oGetScrollInfo;
  FARPROC oGetScrollPos;
  FARPROC oGetScrollRange;
  FARPROC oGetSendMessageReceiver;
  FARPROC oGetShellChangeNotifyWindow;
  FARPROC oGetShellWindow;
  FARPROC oGetSubMenu;
  FARPROC oGetSysColor;
  FARPROC oGetSysColorBrush;
  FARPROC oGetSystemDpiForProcess;
  FARPROC oGetSystemMenu;
  FARPROC oGetSystemMetrics;
  FARPROC oGetSystemMetricsForDpi;
  FARPROC oGetTabbedTextExtentA;
  FARPROC oGetTabbedTextExtentW;
  FARPROC oGetTaskmanWindow;
  FARPROC oGetThreadDesktop;
  FARPROC oGetThreadDpiAwarenessContext;
  FARPROC oGetThreadDpiHostingBehavior;
  FARPROC oGetTitleBarInfo;
  FARPROC oGetTopLevelWindow;
  FARPROC oGetTopWindow;
  FARPROC oGetTouchInputInfo;
  FARPROC oGetUnpredictedMessagePos;
  FARPROC oGetUpdateRect;
  FARPROC oGetUpdateRgn;
  FARPROC oGetUpdatedClipboardFormats;
  FARPROC oGetUserObjectInformationA;
  FARPROC oGetUserObjectInformationW;
  FARPROC oGetUserObjectSecurity;
  FARPROC oGetWinStationInfo;
  FARPROC oGetWindow;
  FARPROC oGetWindowBand;
  FARPROC oGetWindowCompositionAttribute;
  FARPROC oGetWindowCompositionInfo;
  FARPROC oGetWindowContextHelpId;
  FARPROC oGetWindowDC;
  FARPROC oGetWindowDisplayAffinity;
  FARPROC oGetWindowDpiAwarenessContext;
  FARPROC oGetWindowDpiHostingBehavior;
  FARPROC oGetWindowFeedbackSetting;
  FARPROC oGetWindowInfo;
  FARPROC oGetWindowLongA;
  FARPROC oGetWindowLongPtrA;
  FARPROC oGetWindowLongPtrW;
  FARPROC oGetWindowLongW;
  FARPROC oGetWindowMinimizeRect;
  FARPROC oGetWindowModuleFileName;
  FARPROC oGetWindowModuleFileNameA;
  FARPROC oGetWindowModuleFileNameW;
  FARPROC oGetWindowPlacement;
  FARPROC oGetWindowProcessHandle;
  FARPROC oGetWindowRect;
  FARPROC oGetWindowRgn;
  FARPROC oGetWindowRgnBox;
  FARPROC oGetWindowRgnEx;
  FARPROC oGetWindowTextA;
  FARPROC oGetWindowTextLengthA;
  FARPROC oGetWindowTextLengthW;
  FARPROC oGetWindowTextW;
  FARPROC oGetWindowThreadProcessId;
  FARPROC oGetWindowWord;
  FARPROC oGhostWindowFromHungWindow;
  FARPROC oGrayStringA;
  FARPROC oGrayStringW;
  FARPROC oHandleDelegatedInput;
  FARPROC oHideCaret;
  FARPROC oHiliteMenuItem;
  FARPROC oHungWindowFromGhostWindow;
  FARPROC oIMPGetIMEA;
  FARPROC oIMPGetIMEW;
  FARPROC oIMPQueryIMEA;
  FARPROC oIMPQueryIMEW;
  FARPROC oIMPSetIMEA;
  FARPROC oIMPSetIMEW;
  FARPROC oImpersonateDdeClientWindow;
  FARPROC oInSendMessage;
  FARPROC oInSendMessageEx;
  FARPROC oInflateRect;
  FARPROC oInheritWindowMonitor;
  FARPROC oInitDManipHook;
  FARPROC oInitializeGenericHidInjection;
  FARPROC oInitializeInputDeviceInjection;
  FARPROC oInitializeLpkHooks;
  FARPROC oInitializePointerDeviceInjection;
  FARPROC oInitializePointerDeviceInjectionEx;
  FARPROC oInitializeTouchInjection;
  FARPROC oInjectDeviceInput;
  FARPROC oInjectGenericHidInput;
  FARPROC oInjectKeyboardInput;
  FARPROC oInjectMouseInput;
  FARPROC oInjectPointerInput;
  FARPROC oInjectSyntheticPointerInput;
  FARPROC oInjectTouchInput;
  FARPROC oInputSpaceRegionFromPoint;
  FARPROC oInsertMenuA;
  FARPROC oInsertMenuItemA;
  FARPROC oInsertMenuItemW;
  FARPROC oInsertMenuW;
  FARPROC oInternalGetWindowIcon;
  FARPROC oInternalGetWindowText;
  FARPROC oIntersectRect;
  FARPROC oInvalidateRect;
  FARPROC oInvalidateRgn;
  FARPROC oInvertRect;
  FARPROC oIsCharAlphaA;
  FARPROC oIsCharAlphaNumericA;
  FARPROC oIsCharAlphaNumericW;
  FARPROC oIsCharAlphaW;
  FARPROC oIsCharLowerA;
  FARPROC oIsCharLowerW;
  FARPROC oIsCharUpperA;
  FARPROC oIsCharUpperW;
  FARPROC oIsChild;
  FARPROC oIsClipboardFormatAvailable;
  FARPROC oIsDialogMessage;
  FARPROC oIsDialogMessageA;
  FARPROC oIsDialogMessageW;
  FARPROC oIsDlgButtonChecked;
  FARPROC oIsGUIThread;
  FARPROC oIsHungAppWindow;
  FARPROC oIsIconic;
  FARPROC oIsImmersiveProcess;
  FARPROC oIsInDesktopWindowBand;
  FARPROC oIsInterceptWindow;
  FARPROC oIsMenu;
  FARPROC oIsMouseInPointerEnabled;
  FARPROC oIsOneCoreTransformMode;
  FARPROC oIsProcessDPIAware;
  FARPROC oIsRectEmpty;
  FARPROC oIsSETEnabled;
  FARPROC oIsServerSideWindow;
  FARPROC oIsThreadDesktopComposited;
  FARPROC oIsThreadMessageQueueAttached;
  FARPROC oIsThreadTSFEventAware;
  FARPROC oIsTopLevelWindow;
  FARPROC oIsTouchWindow;
  FARPROC oIsValidDpiAwarenessContext;
  FARPROC oIsWinEventHookInstalled;
  FARPROC oIsWindow;
  FARPROC oIsWindowArranged;
  FARPROC oIsWindowDisplayChangeSuppressed;
  FARPROC oIsWindowEnabled;
  FARPROC oIsWindowInDestroy;
  FARPROC oIsWindowRedirectedForPrint;
  FARPROC oIsWindowUnicode;
  FARPROC oIsWindowVisible;
  FARPROC oIsWow64Message;
  FARPROC oIsZoomed;
  FARPROC oKillTimer;
  FARPROC oLoadAcceleratorsA;
  FARPROC oLoadAcceleratorsW;
  FARPROC oLoadBitmapA;
  FARPROC oLoadBitmapW;
  FARPROC oLoadCursorA;
  FARPROC oLoadCursorFromFileA;
  FARPROC oLoadCursorFromFileW;
  FARPROC oLoadCursorW;
  FARPROC oLoadIconA;
  FARPROC oLoadIconW;
  FARPROC oLoadImageA;
  FARPROC oLoadImageW;
  FARPROC oLoadKeyboardLayoutA;
  FARPROC oLoadKeyboardLayoutEx;
  FARPROC oLoadKeyboardLayoutW;
  FARPROC oLoadLocalFonts;
  FARPROC oLoadMenuA;
  FARPROC oLoadMenuIndirectA;
  FARPROC oLoadMenuIndirectW;
  FARPROC oLoadMenuW;
  FARPROC oLoadRemoteFonts;
  FARPROC oLoadStringA;
  FARPROC oLoadStringW;
  FARPROC oLockSetForegroundWindow;
  FARPROC oLockWindowStation;
  FARPROC oLockWindowUpdate;
  FARPROC oLockWorkStation;
  FARPROC oLogicalToPhysicalPoint;
  FARPROC oLogicalToPhysicalPointForPerMonitorDPI;
  FARPROC oLookupIconIdFromDirectory;
  FARPROC oLookupIconIdFromDirectoryEx;
  FARPROC oMBToWCSEx;
  FARPROC oMBToWCSExt;
  FARPROC oMB_GetString;
  FARPROC oMITGetCursorUpdateHandle;
  FARPROC oMITSetLastInputRecipient;
  FARPROC oMITSynthesizeTouchInput;
  FARPROC oMakeThreadTSFEventAware;
  FARPROC oMapDialogRect;
  FARPROC oMapPointsByVisualIdentifier;
  FARPROC oMapVirtualKeyA;
  FARPROC oMapVirtualKeyExA;
  FARPROC oMapVirtualKeyExW;
  FARPROC oMapVirtualKeyW;
  FARPROC oMapVisualRelativePoints;
  FARPROC oMapWindowPoints;
  FARPROC oMenuItemFromPoint;
  FARPROC oMenuWindowProcA;
  FARPROC oMenuWindowProcW;
  FARPROC oMessageBeep;
  FARPROC oMessageBoxA;
  FARPROC oMessageBoxExA;
  FARPROC oMessageBoxExW;
  FARPROC oMessageBoxIndirectA;
  FARPROC oMessageBoxIndirectW;
  FARPROC oMessageBoxTimeoutA;
  FARPROC oMessageBoxTimeoutW;
  FARPROC oMessageBoxW;
  FARPROC oModifyMenuA;
  FARPROC oModifyMenuW;
  FARPROC oMonitorFromPoint;
  FARPROC oMonitorFromRect;
  FARPROC oMonitorFromWindow;
  FARPROC oMoveWindow;
  FARPROC oMsgWaitForMultipleObjects;
  FARPROC oMsgWaitForMultipleObjectsEx;
  FARPROC oNotifyOverlayWindow;
  FARPROC oNotifyWinEvent;
  FARPROC oOemKeyScan;
  FARPROC oOemToCharA;
  FARPROC oOemToCharBuffA;
  FARPROC oOemToCharBuffW;
  FARPROC oOemToCharW;
  FARPROC oOffsetRect;
  FARPROC oOpenClipboard;
  FARPROC oOpenDesktopA;
  FARPROC oOpenDesktopW;
  FARPROC oOpenIcon;
  FARPROC oOpenInputDesktop;
  FARPROC oOpenThreadDesktop;
  FARPROC oOpenWindowStationA;
  FARPROC oOpenWindowStationW;
  FARPROC oPackDDElParam;
  FARPROC oPackTouchHitTestingProximityEvaluation;
  FARPROC oPaintDesktop;
  FARPROC oPaintMenuBar;
  FARPROC oPaintMonitor;
  FARPROC oPeekMessageA;
  FARPROC oPeekMessageW;
  FARPROC oPhysicalToLogicalPoint;
  FARPROC oPhysicalToLogicalPointForPerMonitorDPI;
  FARPROC oPostMessageA;
  FARPROC oPostMessageW;
  FARPROC oPostQuitMessage;
  FARPROC oPostThreadMessageA;
  FARPROC oPostThreadMessageW;
  FARPROC oPrintWindow;
  FARPROC oPrivateExtractIconExA;
  FARPROC oPrivateExtractIconExW;
  FARPROC oPrivateExtractIconsA;
  FARPROC oPrivateExtractIconsW;
  FARPROC oPrivateRegisterICSProc;
  FARPROC oPtInRect;
  FARPROC oQueryBSDRWindow;
  FARPROC oQueryDisplayConfig;
  FARPROC oQuerySendMessage;
  FARPROC oRIMAddInputObserver;
  FARPROC oRIMAreSiblingDevices;
  FARPROC oRIMDeviceIoControl;
  FARPROC oRIMEnableMonitorMappingForDevice;
  FARPROC oRIMFreeInputBuffer;
  FARPROC oRIMGetDevicePreparsedData;
  FARPROC oRIMGetDevicePreparsedDataLockfree;
  FARPROC oRIMGetDeviceProperties;
  FARPROC oRIMGetDevicePropertiesLockfree;
  FARPROC oRIMGetPhysicalDeviceRect;
  FARPROC oRIMGetSourceProcessId;
  FARPROC oRIMObserveNextInput;
  FARPROC oRIMOnAsyncPnpWorkNotification;
  FARPROC oRIMOnPnpNotification;
  FARPROC oRIMOnTimerNotification;
  FARPROC oRIMQueryDevicePath;
  FARPROC oRIMReadInput;
  FARPROC oRIMRegisterForInput;
  FARPROC oRIMRegisterForInputEx;
  FARPROC oRIMRemoveInputObserver;
  FARPROC oRIMSetExtendedDeviceProperty;
  FARPROC oRIMSetTestModeStatus;
  FARPROC oRIMUnregisterForInput;
  FARPROC oRIMUpdateInputObserverRegistration;
  FARPROC oRaiseLowerShellWindow;
  FARPROC oRealChildWindowFromPoint;
  FARPROC oRealGetWindowClass;
  FARPROC oRealGetWindowClassA;
  FARPROC oRealGetWindowClassW;
  FARPROC oReasonCodeNeedsBugID;
  FARPROC oReasonCodeNeedsComment;
  FARPROC oRecordShutdownReason;
  FARPROC oRedrawWindow;
  FARPROC oRegisterBSDRWindow;
  FARPROC oRegisterClassA;
  FARPROC oRegisterClassExA;
  FARPROC oRegisterClassExW;
  FARPROC oRegisterClassW;
  FARPROC oRegisterClipboardFormatA;
  FARPROC oRegisterClipboardFormatW;
  FARPROC oRegisterCloakedNotification;
  FARPROC oRegisterDManipHook;
  FARPROC oRegisterDeviceNotificationA;
  FARPROC oRegisterDeviceNotificationW;
  FARPROC oRegisterErrorReportingDialog;
  FARPROC oRegisterForCustomDockTargets;
  FARPROC oRegisterForTooltipDismissNotification;
  FARPROC oRegisterFrostWindow;
  FARPROC oRegisterGhostWindow;
  FARPROC oRegisterHotKey;
  FARPROC oRegisterLogonProcess;
  FARPROC oRegisterMessagePumpHook;
  FARPROC oRegisterPointerDeviceNotifications;
  FARPROC oRegisterPointerInputTarget;
  FARPROC oRegisterPointerInputTargetEx;
  FARPROC oRegisterPowerSettingNotification;
  FARPROC oRegisterRawInputDevices;
  FARPROC oRegisterServicesProcess;
  FARPROC oRegisterSessionPort;
  FARPROC oRegisterShellHookWindow;
  FARPROC oRegisterSuspendResumeNotification;
  FARPROC oRegisterSystemThread;
  FARPROC oRegisterTasklist;
  FARPROC oRegisterTouchHitTestingWindow;
  FARPROC oRegisterTouchWindow;
  FARPROC oRegisterTouchpadCapableThread;
  FARPROC oRegisterTouchpadCapableWindow;
  FARPROC oRegisterUserApiHook;
  FARPROC oRegisterWindowMessageA;
  FARPROC oRegisterWindowMessageW;
  FARPROC oReleaseCapture;
  FARPROC oReleaseDC;
  FARPROC oReleaseDwmHitTestWaiters;
  FARPROC oRemoveClipboardFormatListener;
  FARPROC oRemoveInjectionDevice;
  FARPROC oRemoveMenu;
  FARPROC oRemovePropA;
  FARPROC oRemovePropW;
  FARPROC oRemoveThreadTSFEventAwareness;
  FARPROC oRemoveVisualIdentifier;
  FARPROC oReplyMessage;
  FARPROC oReportInertia;
  FARPROC oResolveDesktopForWOW;
  FARPROC oReuseDDElParam;
  FARPROC oScreenToClient;
  FARPROC oScrollChildren;
  FARPROC oScrollDC;
  FARPROC oScrollWindow;
  FARPROC oScrollWindowEx;
  FARPROC oSendDlgItemMessageA;
  FARPROC oSendDlgItemMessageW;
  FARPROC oSendIMEMessageExA;
  FARPROC oSendIMEMessageExW;
  FARPROC oSendInput;
  FARPROC oSendMessageA;
  FARPROC oSendMessageCallbackA;
  FARPROC oSendMessageCallbackW;
  FARPROC oSendMessageTimeoutA;
  FARPROC oSendMessageTimeoutW;
  FARPROC oSendMessageW;
  FARPROC oSendNotifyMessageA;
  FARPROC oSendNotifyMessageW;
  FARPROC oSetActiveWindow;
  FARPROC oSetAdditionalForegroundBoostProcesses;
  FARPROC oSetCapture;
  FARPROC oSetCaretBlinkTime;
  FARPROC oSetCaretPos;
  FARPROC oSetClassLongA;
  FARPROC oSetClassLongPtrA;
  FARPROC oSetClassLongPtrW;
  FARPROC oSetClassLongW;
  FARPROC oSetClassWord;
  FARPROC oSetClipboardData;
  FARPROC oSetClipboardViewer;
  FARPROC oSetCoalescableTimer;
  FARPROC oSetCoreWindow;
  FARPROC oSetCoveredWindowStates;
  FARPROC oSetCursor;
  FARPROC oSetCursorContents;
  FARPROC oSetCursorPos;
  FARPROC oSetDebugErrorLevel;
  FARPROC oSetDeskWallpaper;
  FARPROC oSetDesktopColorTransform;
  FARPROC oSetDialogControlDpiChangeBehavior;
  FARPROC oSetDialogDpiChangeBehavior;
  FARPROC oSetDisplayAutoRotationPreferences;
  FARPROC oSetDisplayConfig;
  FARPROC oSetDlgItemInt;
  FARPROC oSetDlgItemTextA;
  FARPROC oSetDlgItemTextW;
  FARPROC oSetDoubleClickTime;
  FARPROC oSetFeatureReportResponse;
  FARPROC oSetFocus;
  FARPROC oSetForegroundRedirectionForActivationObject;
  FARPROC oSetForegroundWindow;
  FARPROC oSetFullscreenMagnifierOffsetsDWMUpdated;
  FARPROC oSetGestureConfig;
  FARPROC oSetInternalWindowPos;
  FARPROC oSetKeyboardState;
  FARPROC oSetLastErrorEx;
  FARPROC oSetLayeredWindowAttributes;
  FARPROC oSetMagnificationDesktopColorEffect;
  FARPROC oSetMagnificationDesktopMagnification;
  FARPROC oSetMagnificationDesktopMagnifierOffsetsDWMUpdated;
  FARPROC oSetMagnificationDesktopSamplingMode;
  FARPROC oSetMagnificationLensCtxInformation;
  FARPROC oSetMaxTouchpadSensitivity;
  FARPROC oSetMenu;
  FARPROC oSetMenuContextHelpId;
  FARPROC oSetMenuDefaultItem;
  FARPROC oSetMenuInfo;
  FARPROC oSetMenuItemBitmaps;
  FARPROC oSetMenuItemInfoA;
  FARPROC oSetMenuItemInfoW;
  FARPROC oSetMessageExtraInfo;
  FARPROC oSetMessageQueue;
  FARPROC oSetMirrorRendering;
  FARPROC oSetParent;
  FARPROC oSetPhysicalCursorPos;
  FARPROC oSetPointerDeviceInputSpace;
  FARPROC oSetProcessDPIAware;
  FARPROC oSetProcessDefaultLayout;
  FARPROC oSetProcessDpiAwarenessContext;
  FARPROC oSetProcessDpiAwarenessInternal;
  FARPROC oSetProcessLaunchForegroundPolicy;
  FARPROC oSetProcessRestrictionExemption;
  FARPROC oSetProcessWindowStation;
  FARPROC oSetProgmanWindow;
  FARPROC oSetPropA;
  FARPROC oSetPropW;
  FARPROC oSetRect;
  FARPROC oSetRectEmpty;
  FARPROC oSetScrollInfo;
  FARPROC oSetScrollPos;
  FARPROC oSetScrollRange;
  FARPROC oSetShellChangeNotifyWindow;
  FARPROC oSetShellWindow;
  FARPROC oSetShellWindowEx;
  FARPROC oSetSysColors;
  FARPROC oSetSysColorsTemp;
  FARPROC oSetSystemCursor;
  FARPROC oSetSystemMenu;
  FARPROC oSetTaskmanWindow;
  FARPROC oSetThreadCursorCreationScaling;
  FARPROC oSetThreadDesktop;
  FARPROC oSetThreadDpiAwarenessContext;
  FARPROC oSetThreadDpiHostingBehavior;
  FARPROC oSetThreadInputBlocked;
  FARPROC oSetTimer;
  FARPROC oSetUserObjectCapability;
  FARPROC oSetUserObjectInformationA;
  FARPROC oSetUserObjectInformationW;
  FARPROC oSetUserObjectSecurity;
  FARPROC oSetWinEventHook;
  FARPROC oSetWindowBand;
  FARPROC oSetWindowCompositionAttribute;
  FARPROC oSetWindowCompositionTransition;
  FARPROC oSetWindowContextHelpId;
  FARPROC oSetWindowDisplayAffinity;
  FARPROC oSetWindowFeedbackSetting;
  FARPROC oSetWindowLongA;
  FARPROC oSetWindowLongPtrA;
  FARPROC oSetWindowLongPtrW;
  FARPROC oSetWindowLongW;
  FARPROC oSetWindowMessageCapability;
  FARPROC oSetWindowPlacement;
  FARPROC oSetWindowPos;
  FARPROC oSetWindowRgn;
  FARPROC oSetWindowRgnEx;
  FARPROC oSetWindowStationUser;
  FARPROC oSetWindowTextA;
  FARPROC oSetWindowTextW;
  FARPROC oSetWindowWord;
  FARPROC oSetWindowsHookA;
  FARPROC oSetWindowsHookExA;
  FARPROC oSetWindowsHookExAW;
  FARPROC oSetWindowsHookExW;
  FARPROC oSetWindowsHookW;
  FARPROC oShellForegroundBoostProcess;
  FARPROC oShellHandwritingDelegateInput;
  FARPROC oShellHandwritingHandleDelegatedInput;
  FARPROC oShellHandwritingUndelegateInput;
  FARPROC oShellMigrateWindow;
  FARPROC oShellRegisterHotKey;
  FARPROC oShellSetWindowPos;
  FARPROC oShowCaret;
  FARPROC oShowCursor;
  FARPROC oShowOwnedPopups;
  FARPROC oShowScrollBar;
  FARPROC oShowStartGlass;
  FARPROC oShowSystemCursor;
  FARPROC oShowWindow;
  FARPROC oShowWindowAsync;
  FARPROC oShutdownBlockReasonCreate;
  FARPROC oShutdownBlockReasonDestroy;
  FARPROC oShutdownBlockReasonQuery;
  FARPROC oSignalRedirectionStartComplete;
  FARPROC oSkipPointerFrameMessages;
  FARPROC oSoftModalMessageBox;
  FARPROC oSoundSentry;
  FARPROC oSubtractRect;
  FARPROC oSuppressWindowDisplayChange;
  FARPROC oSwapMouseButton;
  FARPROC oSwitchDesktop;
  FARPROC oSwitchDesktopWithFade;
  FARPROC oSwitchToThisWindow;
  FARPROC oSystemParametersInfoA;
  FARPROC oSystemParametersInfoForDpi;
  FARPROC oSystemParametersInfoW;
  FARPROC oTabbedTextOutA;
  FARPROC oTabbedTextOutW;
  FARPROC oTileChildWindows;
  FARPROC oTileWindows;
  FARPROC oToAscii;
  FARPROC oToAsciiEx;
  FARPROC oToUnicode;
  FARPROC oToUnicodeEx;
  FARPROC oTrackMouseEvent;
  FARPROC oTrackPopupMenu;
  FARPROC oTrackPopupMenuEx;
  FARPROC oTranslateAccelerator;
  FARPROC oTranslateAcceleratorA;
  FARPROC oTranslateAcceleratorW;
  FARPROC oTranslateMDISysAccel;
  FARPROC oTranslateMessage;
  FARPROC oTranslateMessageEx;
  FARPROC oUndelegateInput;
  FARPROC oUnhookWinEvent;
  FARPROC oUnhookWindowsHook;
  FARPROC oUnhookWindowsHookEx;
  FARPROC oUnionRect;
  FARPROC oUnloadKeyboardLayout;
  FARPROC oUnlockWindowStation;
  FARPROC oUnpackDDElParam;
  FARPROC oUnregisterClassA;
  FARPROC oUnregisterClassW;
  FARPROC oUnregisterDeviceNotification;
  FARPROC oUnregisterHotKey;
  FARPROC oUnregisterMessagePumpHook;
  FARPROC oUnregisterPointerInputTarget;
  FARPROC oUnregisterPointerInputTargetEx;
  FARPROC oUnregisterPowerSettingNotification;
  FARPROC oUnregisterSessionPort;
  FARPROC oUnregisterSuspendResumeNotification;
  FARPROC oUnregisterTouchWindow;
  FARPROC oUnregisterUserApiHook;
  FARPROC oUpdateDefaultDesktopThumbnail;
  FARPROC oUpdateLayeredWindow;
  FARPROC oUpdateLayeredWindowIndirect;
  FARPROC oUpdatePerUserSystemParameters;
  FARPROC oUpdateWindow;
  FARPROC oUpdateWindowInputSinkHints;
  FARPROC oUser32InitializeImmEntryTable;
  FARPROC oUserClientDllInitialize;
  FARPROC oUserHandleGrantAccess;
  FARPROC oUserLpkPSMTextOut;
  FARPROC oUserLpkTabbedTextOut;
  FARPROC oUserRealizePalette;
  FARPROC oUserRegisterWowHandlers;
  FARPROC oVRipOutput;
  FARPROC oVTagOutput;
  FARPROC oValidateRect;
  FARPROC oValidateRgn;
  FARPROC oVkKeyScanA;
  FARPROC oVkKeyScanExA;
  FARPROC oVkKeyScanExW;
  FARPROC oVkKeyScanW;
  FARPROC oWCSToMBEx;
  FARPROC oWINNLSEnableIME;
  FARPROC oWINNLSGetEnableStatus;
  FARPROC oWINNLSGetIMEHotkey;
  FARPROC oWaitForInputIdle;
  FARPROC oWaitForRedirectionStartComplete;
  FARPROC oWaitMessage;
  FARPROC oWinHelpA;
  FARPROC oWinHelpW;
  FARPROC oWindowFromDC;
  FARPROC oWindowFromPhysicalPoint;
  FARPROC oWindowFromPoint;
  FARPROC o_UserTestTokenForInteractive;
  FARPROC ogSharedInfo;
  FARPROC ogapfnScSendMessage;
  FARPROC okeybd_event;
  FARPROC omouse_event;
  FARPROC owsprintfA;
  FARPROC owsprintfW;
  FARPROC owvsprintfA;
  FARPROC owvsprintfW;
} user32;

extern "C" {
FARPROC PA = 0;
int runASM();

void fActivateKeyboardLayout() {
  PA = user32.oActivateKeyboardLayout;
  runASM();
}
void fAddClipboardFormatListener() {
  PA = user32.oAddClipboardFormatListener;
  runASM();
}
void fAddVisualIdentifier() {
  PA = user32.oAddVisualIdentifier;
  runASM();
}
void fAdjustWindowRect() {
  PA = user32.oAdjustWindowRect;
  runASM();
}
void fAdjustWindowRectEx() {
  PA = user32.oAdjustWindowRectEx;
  runASM();
}
void fAdjustWindowRectExForDpi() {
  PA = user32.oAdjustWindowRectExForDpi;
  runASM();
}
void fAlignRects() {
  PA = user32.oAlignRects;
  runASM();
}
void fAllowForegroundActivation() {
  PA = user32.oAllowForegroundActivation;
  runASM();
}
void fAllowSetForegroundWindow() {
  PA = user32.oAllowSetForegroundWindow;
  runASM();
}
void fAnimateWindow() {
  PA = user32.oAnimateWindow;
  runASM();
}
void fAnyPopup() {
  PA = user32.oAnyPopup;
  runASM();
}
void fAppendMenuA() {
  PA = user32.oAppendMenuA;
  runASM();
}
void fAppendMenuW() {
  PA = user32.oAppendMenuW;
  runASM();
}
void fApplyWindowAction() {
  PA = user32.oApplyWindowAction;
  runASM();
}
void fAreDpiAwarenessContextsEqual() {
  PA = user32.oAreDpiAwarenessContextsEqual;
  runASM();
}
void fArrangeIconicWindows() {
  PA = user32.oArrangeIconicWindows;
  runASM();
}
void fAttachThreadInput() {
  PA = user32.oAttachThreadInput;
  runASM();
}
void fBeginDeferWindowPos() {
  PA = user32.oBeginDeferWindowPos;
  runASM();
}
void fBeginPaint() {
  PA = user32.oBeginPaint;
  runASM();
}
void fBlockInput() {
  PA = user32.oBlockInput;
  runASM();
}
void fBringWindowToTop() {
  PA = user32.oBringWindowToTop;
  runASM();
}
void fBroadcastSystemMessage() {
  PA = user32.oBroadcastSystemMessage;
  runASM();
}
void fBroadcastSystemMessageA() {
  PA = user32.oBroadcastSystemMessageA;
  runASM();
}
void fBroadcastSystemMessageExA() {
  PA = user32.oBroadcastSystemMessageExA;
  runASM();
}
void fBroadcastSystemMessageExW() {
  PA = user32.oBroadcastSystemMessageExW;
  runASM();
}
void fBroadcastSystemMessageW() {
  PA = user32.oBroadcastSystemMessageW;
  runASM();
}
void fBuildReasonArray() {
  PA = user32.oBuildReasonArray;
  runASM();
}
void fCalcMenuBar() {
  PA = user32.oCalcMenuBar;
  runASM();
}
void fCalculatePopupWindowPosition() {
  PA = user32.oCalculatePopupWindowPosition;
  runASM();
}
void fCallMsgFilter() {
  PA = user32.oCallMsgFilter;
  runASM();
}
void fCallMsgFilterA() {
  PA = user32.oCallMsgFilterA;
  runASM();
}
void fCallMsgFilterW() {
  PA = user32.oCallMsgFilterW;
  runASM();
}
void fCallNextHookEx() {
  PA = user32.oCallNextHookEx;
  runASM();
}
void fCallWindowProcA() {
  PA = user32.oCallWindowProcA;
  runASM();
}
void fCallWindowProcW() {
  PA = user32.oCallWindowProcW;
  runASM();
}
void fCancelShutdown() {
  PA = user32.oCancelShutdown;
  runASM();
}
void fCascadeChildWindows() {
  PA = user32.oCascadeChildWindows;
  runASM();
}
void fCascadeWindows() {
  PA = user32.oCascadeWindows;
  runASM();
}
void fChangeClipboardChain() {
  PA = user32.oChangeClipboardChain;
  runASM();
}
void fChangeDisplaySettingsA() {
  PA = user32.oChangeDisplaySettingsA;
  runASM();
}
void fChangeDisplaySettingsExA() {
  PA = user32.oChangeDisplaySettingsExA;
  runASM();
}
void fChangeDisplaySettingsExW() {
  PA = user32.oChangeDisplaySettingsExW;
  runASM();
}
void fChangeDisplaySettingsW() {
  PA = user32.oChangeDisplaySettingsW;
  runASM();
}
void fChangeMenuA() {
  PA = user32.oChangeMenuA;
  runASM();
}
void fChangeMenuW() {
  PA = user32.oChangeMenuW;
  runASM();
}
void fChangeWindowMessageFilter() {
  PA = user32.oChangeWindowMessageFilter;
  runASM();
}
void fChangeWindowMessageFilterEx() {
  PA = user32.oChangeWindowMessageFilterEx;
  runASM();
}
void fCharLowerA() {
  PA = user32.oCharLowerA;
  runASM();
}
void fCharLowerBuffA() {
  PA = user32.oCharLowerBuffA;
  runASM();
}
void fCharLowerBuffW() {
  PA = user32.oCharLowerBuffW;
  runASM();
}
void fCharLowerW() {
  PA = user32.oCharLowerW;
  runASM();
}
void fCharNextA() {
  PA = user32.oCharNextA;
  runASM();
}
void fCharNextExA() {
  PA = user32.oCharNextExA;
  runASM();
}
void fCharNextW() {
  PA = user32.oCharNextW;
  runASM();
}
void fCharPrevA() {
  PA = user32.oCharPrevA;
  runASM();
}
void fCharPrevExA() {
  PA = user32.oCharPrevExA;
  runASM();
}
void fCharPrevW() {
  PA = user32.oCharPrevW;
  runASM();
}
void fCharToOemA() {
  PA = user32.oCharToOemA;
  runASM();
}
void fCharToOemBuffA() {
  PA = user32.oCharToOemBuffA;
  runASM();
}
void fCharToOemBuffW() {
  PA = user32.oCharToOemBuffW;
  runASM();
}
void fCharToOemW() {
  PA = user32.oCharToOemW;
  runASM();
}
void fCharUpperA() {
  PA = user32.oCharUpperA;
  runASM();
}
void fCharUpperBuffA() {
  PA = user32.oCharUpperBuffA;
  runASM();
}
void fCharUpperBuffW() {
  PA = user32.oCharUpperBuffW;
  runASM();
}
void fCharUpperW() {
  PA = user32.oCharUpperW;
  runASM();
}
void fCheckBannedOneCoreTransformApi() {
  PA = user32.oCheckBannedOneCoreTransformApi;
  runASM();
}
void fCheckDBCSEnabledExt() {
  PA = user32.oCheckDBCSEnabledExt;
  runASM();
}
void fCheckDlgButton() {
  PA = user32.oCheckDlgButton;
  runASM();
}
void fCheckMenuItem() {
  PA = user32.oCheckMenuItem;
  runASM();
}
void fCheckMenuRadioItem() {
  PA = user32.oCheckMenuRadioItem;
  runASM();
}
void fCheckProcessForClipboardAccess() {
  PA = user32.oCheckProcessForClipboardAccess;
  runASM();
}
void fCheckProcessSession() {
  PA = user32.oCheckProcessSession;
  runASM();
}
void fCheckRadioButton() {
  PA = user32.oCheckRadioButton;
  runASM();
}
void fCheckWindowThreadDesktop() {
  PA = user32.oCheckWindowThreadDesktop;
  runASM();
}
void fChildWindowFromPoint() {
  PA = user32.oChildWindowFromPoint;
  runASM();
}
void fChildWindowFromPointEx() {
  PA = user32.oChildWindowFromPointEx;
  runASM();
}
void fCliImmSetHotKey() {
  PA = user32.oCliImmSetHotKey;
  runASM();
}
void fClientThreadSetup() {
  PA = user32.oClientThreadSetup;
  runASM();
}
void fClientToScreen() {
  PA = user32.oClientToScreen;
  runASM();
}
void fClipCursor() {
  PA = user32.oClipCursor;
  runASM();
}
void fCloseClipboard() {
  PA = user32.oCloseClipboard;
  runASM();
}
void fCloseDesktop() {
  PA = user32.oCloseDesktop;
  runASM();
}
void fCloseGestureInfoHandle() {
  PA = user32.oCloseGestureInfoHandle;
  runASM();
}
void fCloseTouchInputHandle() {
  PA = user32.oCloseTouchInputHandle;
  runASM();
}
void fCloseWindow() {
  PA = user32.oCloseWindow;
  runASM();
}
void fCloseWindowStation() {
  PA = user32.oCloseWindowStation;
  runASM();
}
void fConsoleControl() {
  PA = user32.oConsoleControl;
  runASM();
}
void fControlMagnification() {
  PA = user32.oControlMagnification;
  runASM();
}
void fConvertToInterceptWindow() {
  PA = user32.oConvertToInterceptWindow;
  runASM();
}
void fCopyAcceleratorTableA() {
  PA = user32.oCopyAcceleratorTableA;
  runASM();
}
void fCopyAcceleratorTableW() {
  PA = user32.oCopyAcceleratorTableW;
  runASM();
}
void fCopyIcon() {
  PA = user32.oCopyIcon;
  runASM();
}
void fCopyImage() {
  PA = user32.oCopyImage;
  runASM();
}
void fCopyRect() {
  PA = user32.oCopyRect;
  runASM();
}
void fCountClipboardFormats() {
  PA = user32.oCountClipboardFormats;
  runASM();
}
void fCreateAcceleratorTableA() {
  PA = user32.oCreateAcceleratorTableA;
  runASM();
}
void fCreateAcceleratorTableW() {
  PA = user32.oCreateAcceleratorTableW;
  runASM();
}
void fCreateCaret() {
  PA = user32.oCreateCaret;
  runASM();
}
void fCreateCursor() {
  PA = user32.oCreateCursor;
  runASM();
}
void fCreateDCompositionHwndTarget() {
  PA = user32.oCreateDCompositionHwndTarget;
  runASM();
}
void fCreateDesktopA() {
  PA = user32.oCreateDesktopA;
  runASM();
}
void fCreateDesktopExA() {
  PA = user32.oCreateDesktopExA;
  runASM();
}
void fCreateDesktopExW() {
  PA = user32.oCreateDesktopExW;
  runASM();
}
void fCreateDesktopW() {
  PA = user32.oCreateDesktopW;
  runASM();
}
void fCreateDialogIndirectParamA() {
  PA = user32.oCreateDialogIndirectParamA;
  runASM();
}
void fCreateDialogIndirectParamAorW() {
  PA = user32.oCreateDialogIndirectParamAorW;
  runASM();
}
void fCreateDialogIndirectParamW() {
  PA = user32.oCreateDialogIndirectParamW;
  runASM();
}
void fCreateDialogParamA() {
  PA = user32.oCreateDialogParamA;
  runASM();
}
void fCreateDialogParamW() {
  PA = user32.oCreateDialogParamW;
  runASM();
}
void fCreateIcon() {
  PA = user32.oCreateIcon;
  runASM();
}
void fCreateIconFromResource() {
  PA = user32.oCreateIconFromResource;
  runASM();
}
void fCreateIconFromResourceEx() {
  PA = user32.oCreateIconFromResourceEx;
  runASM();
}
void fCreateIconIndirect() {
  PA = user32.oCreateIconIndirect;
  runASM();
}
void fCreateMDIWindowA() {
  PA = user32.oCreateMDIWindowA;
  runASM();
}
void fCreateMDIWindowW() {
  PA = user32.oCreateMDIWindowW;
  runASM();
}
void fCreateMenu() {
  PA = user32.oCreateMenu;
  runASM();
}
void fCreatePopupMenu() {
  PA = user32.oCreatePopupMenu;
  runASM();
}
void fCreateSyntheticPointerDevice() {
  PA = user32.oCreateSyntheticPointerDevice;
  runASM();
}
void fCreateSyntheticPointerDevice2() {
  PA = user32.oCreateSyntheticPointerDevice2;
  runASM();
}
void fCreateSystemThreads() {
  PA = user32.oCreateSystemThreads;
  runASM();
}
void fCreateWindowExA() {
  PA = user32.oCreateWindowExA;
  runASM();
}
void fCreateWindowExW() {
  PA = user32.oCreateWindowExW;
  runASM();
}
void fCreateWindowInBand() {
  PA = user32.oCreateWindowInBand;
  runASM();
}
void fCreateWindowInBandEx() {
  PA = user32.oCreateWindowInBandEx;
  runASM();
}
void fCreateWindowIndirect() {
  PA = user32.oCreateWindowIndirect;
  runASM();
}
void fCreateWindowStationA() {
  PA = user32.oCreateWindowStationA;
  runASM();
}
void fCreateWindowStationW() {
  PA = user32.oCreateWindowStationW;
  runASM();
}
void fCsrBroadcastSystemMessageExW() {
  PA = user32.oCsrBroadcastSystemMessageExW;
  runASM();
}
void fCtxInitUser32() {
  PA = user32.oCtxInitUser32;
  runASM();
}
void fDdeAbandonTransaction() {
  PA = user32.oDdeAbandonTransaction;
  runASM();
}
void fDdeAccessData() {
  PA = user32.oDdeAccessData;
  runASM();
}
void fDdeAddData() {
  PA = user32.oDdeAddData;
  runASM();
}
void fDdeClientTransaction() {
  PA = user32.oDdeClientTransaction;
  runASM();
}
void fDdeCmpStringHandles() {
  PA = user32.oDdeCmpStringHandles;
  runASM();
}
void fDdeConnect() {
  PA = user32.oDdeConnect;
  runASM();
}
void fDdeConnectList() {
  PA = user32.oDdeConnectList;
  runASM();
}
void fDdeCreateDataHandle() {
  PA = user32.oDdeCreateDataHandle;
  runASM();
}
void fDdeCreateStringHandleA() {
  PA = user32.oDdeCreateStringHandleA;
  runASM();
}
void fDdeCreateStringHandleW() {
  PA = user32.oDdeCreateStringHandleW;
  runASM();
}
void fDdeDisconnect() {
  PA = user32.oDdeDisconnect;
  runASM();
}
void fDdeDisconnectList() {
  PA = user32.oDdeDisconnectList;
  runASM();
}
void fDdeEnableCallback() {
  PA = user32.oDdeEnableCallback;
  runASM();
}
void fDdeFreeDataHandle() {
  PA = user32.oDdeFreeDataHandle;
  runASM();
}
void fDdeFreeStringHandle() {
  PA = user32.oDdeFreeStringHandle;
  runASM();
}
void fDdeGetData() {
  PA = user32.oDdeGetData;
  runASM();
}
void fDdeGetLastError() {
  PA = user32.oDdeGetLastError;
  runASM();
}
void fDdeGetQualityOfService() {
  PA = user32.oDdeGetQualityOfService;
  runASM();
}
void fDdeImpersonateClient() {
  PA = user32.oDdeImpersonateClient;
  runASM();
}
void fDdeInitializeA() {
  PA = user32.oDdeInitializeA;
  runASM();
}
void fDdeInitializeW() {
  PA = user32.oDdeInitializeW;
  runASM();
}
void fDdeKeepStringHandle() {
  PA = user32.oDdeKeepStringHandle;
  runASM();
}
void fDdeNameService() {
  PA = user32.oDdeNameService;
  runASM();
}
void fDdePostAdvise() {
  PA = user32.oDdePostAdvise;
  runASM();
}
void fDdeQueryConvInfo() {
  PA = user32.oDdeQueryConvInfo;
  runASM();
}
void fDdeQueryNextServer() {
  PA = user32.oDdeQueryNextServer;
  runASM();
}
void fDdeQueryStringA() {
  PA = user32.oDdeQueryStringA;
  runASM();
}
void fDdeQueryStringW() {
  PA = user32.oDdeQueryStringW;
  runASM();
}
void fDdeReconnect() {
  PA = user32.oDdeReconnect;
  runASM();
}
void fDdeSetQualityOfService() {
  PA = user32.oDdeSetQualityOfService;
  runASM();
}
void fDdeSetUserHandle() {
  PA = user32.oDdeSetUserHandle;
  runASM();
}
void fDdeUnaccessData() {
  PA = user32.oDdeUnaccessData;
  runASM();
}
void fDdeUninitialize() {
  PA = user32.oDdeUninitialize;
  runASM();
}
void fDefDlgProcA() {
  PA = user32.oDefDlgProcA;
  runASM();
}
void fDefDlgProcW() {
  PA = user32.oDefDlgProcW;
  runASM();
}
void fDefFrameProcA() {
  PA = user32.oDefFrameProcA;
  runASM();
}
void fDefFrameProcW() {
  PA = user32.oDefFrameProcW;
  runASM();
}
void fDefMDIChildProcA() {
  PA = user32.oDefMDIChildProcA;
  runASM();
}
void fDefMDIChildProcW() {
  PA = user32.oDefMDIChildProcW;
  runASM();
}
void fDefRawInputProc() {
  PA = user32.oDefRawInputProc;
  runASM();
}
void fDefWindowProcA() {
  PA = user32.oDefWindowProcA;
  runASM();
}
void fDefWindowProcW() {
  PA = user32.oDefWindowProcW;
  runASM();
}
void fDeferWindowPos() {
  PA = user32.oDeferWindowPos;
  runASM();
}
void fDeferWindowPosAndBand() {
  PA = user32.oDeferWindowPosAndBand;
  runASM();
}
void fDelegateInput() {
  PA = user32.oDelegateInput;
  runASM();
}
void fDeleteMenu() {
  PA = user32.oDeleteMenu;
  runASM();
}
void fDeregisterShellHookWindow() {
  PA = user32.oDeregisterShellHookWindow;
  runASM();
}
void fDestroyAcceleratorTable() {
  PA = user32.oDestroyAcceleratorTable;
  runASM();
}
void fDestroyCaret() {
  PA = user32.oDestroyCaret;
  runASM();
}
void fDestroyCursor() {
  PA = user32.oDestroyCursor;
  runASM();
}
void fDestroyDCompositionHwndTarget() {
  PA = user32.oDestroyDCompositionHwndTarget;
  runASM();
}
void fDestroyIcon() {
  PA = user32.oDestroyIcon;
  runASM();
}
void fDestroyMenu() {
  PA = user32.oDestroyMenu;
  runASM();
}
void fDestroyReasons() {
  PA = user32.oDestroyReasons;
  runASM();
}
void fDestroySyntheticPointerDevice() {
  PA = user32.oDestroySyntheticPointerDevice;
  runASM();
}
void fDestroyWindow() {
  PA = user32.oDestroyWindow;
  runASM();
}
void fDialogBoxIndirectParamA() {
  PA = user32.oDialogBoxIndirectParamA;
  runASM();
}
void fDialogBoxIndirectParamAorW() {
  PA = user32.oDialogBoxIndirectParamAorW;
  runASM();
}
void fDialogBoxIndirectParamW() {
  PA = user32.oDialogBoxIndirectParamW;
  runASM();
}
void fDialogBoxParamA() {
  PA = user32.oDialogBoxParamA;
  runASM();
}
void fDialogBoxParamW() {
  PA = user32.oDialogBoxParamW;
  runASM();
}
void fDisableProcessWindowsGhosting() {
  PA = user32.oDisableProcessWindowsGhosting;
  runASM();
}
void fDispatchMessageA() {
  PA = user32.oDispatchMessageA;
  runASM();
}
void fDispatchMessageW() {
  PA = user32.oDispatchMessageW;
  runASM();
}
void fDisplayConfigGetDeviceInfo() {
  PA = user32.oDisplayConfigGetDeviceInfo;
  runASM();
}
void fDisplayConfigSetDeviceInfo() {
  PA = user32.oDisplayConfigSetDeviceInfo;
  runASM();
}
void fDisplayExitWindowsWarnings() {
  PA = user32.oDisplayExitWindowsWarnings;
  runASM();
}
void fDlgDirListA() {
  PA = user32.oDlgDirListA;
  runASM();
}
void fDlgDirListComboBoxA() {
  PA = user32.oDlgDirListComboBoxA;
  runASM();
}
void fDlgDirListComboBoxW() {
  PA = user32.oDlgDirListComboBoxW;
  runASM();
}
void fDlgDirListW() {
  PA = user32.oDlgDirListW;
  runASM();
}
void fDlgDirSelectComboBoxExA() {
  PA = user32.oDlgDirSelectComboBoxExA;
  runASM();
}
void fDlgDirSelectComboBoxExW() {
  PA = user32.oDlgDirSelectComboBoxExW;
  runASM();
}
void fDlgDirSelectExA() {
  PA = user32.oDlgDirSelectExA;
  runASM();
}
void fDlgDirSelectExW() {
  PA = user32.oDlgDirSelectExW;
  runASM();
}
void fDoSoundConnect() {
  PA = user32.oDoSoundConnect;
  runASM();
}
void fDoSoundDisconnect() {
  PA = user32.oDoSoundDisconnect;
  runASM();
}
void fDragDetect() {
  PA = user32.oDragDetect;
  runASM();
}
void fDragObject() {
  PA = user32.oDragObject;
  runASM();
}
void fDrawAnimatedRects() {
  PA = user32.oDrawAnimatedRects;
  runASM();
}
void fDrawCaption() {
  PA = user32.oDrawCaption;
  runASM();
}
void fDrawCaptionTempA() {
  PA = user32.oDrawCaptionTempA;
  runASM();
}
void fDrawCaptionTempW() {
  PA = user32.oDrawCaptionTempW;
  runASM();
}
void fDrawEdge() {
  PA = user32.oDrawEdge;
  runASM();
}
void fDrawFocusRect() {
  PA = user32.oDrawFocusRect;
  runASM();
}
void fDrawFrame() {
  PA = user32.oDrawFrame;
  runASM();
}
void fDrawFrameControl() {
  PA = user32.oDrawFrameControl;
  runASM();
}
void fDrawIcon() {
  PA = user32.oDrawIcon;
  runASM();
}
void fDrawIconEx() {
  PA = user32.oDrawIconEx;
  runASM();
}
void fDrawMenuBar() {
  PA = user32.oDrawMenuBar;
  runASM();
}
void fDrawMenuBarTemp() {
  PA = user32.oDrawMenuBarTemp;
  runASM();
}
void fDrawStateA() {
  PA = user32.oDrawStateA;
  runASM();
}
void fDrawStateW() {
  PA = user32.oDrawStateW;
  runASM();
}
void fDrawTextA() {
  PA = user32.oDrawTextA;
  runASM();
}
void fDrawTextExA() {
  PA = user32.oDrawTextExA;
  runASM();
}
void fDrawTextExW() {
  PA = user32.oDrawTextExW;
  runASM();
}
void fDrawTextW() {
  PA = user32.oDrawTextW;
  runASM();
}
void fDwmGetDxRgn() {
  PA = user32.oDwmGetDxRgn;
  runASM();
}
void fDwmGetDxSharedSurface() {
  PA = user32.oDwmGetDxSharedSurface;
  runASM();
}
void fDwmGetRemoteSessionOcclusionEvent() {
  PA = user32.oDwmGetRemoteSessionOcclusionEvent;
  runASM();
}
void fDwmGetRemoteSessionOcclusionState() {
  PA = user32.oDwmGetRemoteSessionOcclusionState;
  runASM();
}
void fDwmKernelShutdown() {
  PA = user32.oDwmKernelShutdown;
  runASM();
}
void fDwmKernelStartup() {
  PA = user32.oDwmKernelStartup;
  runASM();
}
void fDwmLockScreenUpdates() {
  PA = user32.oDwmLockScreenUpdates;
  runASM();
}
void fDwmValidateWindow() {
  PA = user32.oDwmValidateWindow;
  runASM();
}
void fDwmWindowNotificationsEnabled() {
  PA = user32.oDwmWindowNotificationsEnabled;
  runASM();
}
void fEditWndProc() {
  PA = user32.oEditWndProc;
  runASM();
}
void fEmptyClipboard() {
  PA = user32.oEmptyClipboard;
  runASM();
}
void fEnableMenuItem() {
  PA = user32.oEnableMenuItem;
  runASM();
}
void fEnableMouseInPointer() {
  PA = user32.oEnableMouseInPointer;
  runASM();
}
void fEnableNonClientDpiScaling() {
  PA = user32.oEnableNonClientDpiScaling;
  runASM();
}
void fEnableOneCoreTransformMode() {
  PA = user32.oEnableOneCoreTransformMode;
  runASM();
}
void fEnableScrollBar() {
  PA = user32.oEnableScrollBar;
  runASM();
}
void fEnableSessionForMMCSS() {
  PA = user32.oEnableSessionForMMCSS;
  runASM();
}
void fEnableWindow() {
  PA = user32.oEnableWindow;
  runASM();
}
void fEnableWindowShellWindowManagementBehavior() {
  PA = user32.oEnableWindowShellWindowManagementBehavior;
  runASM();
}
void fEndDeferWindowPos() {
  PA = user32.oEndDeferWindowPos;
  runASM();
}
void fEndDeferWindowPosEx() {
  PA = user32.oEndDeferWindowPosEx;
  runASM();
}
void fEndDialog() {
  PA = user32.oEndDialog;
  runASM();
}
void fEndMenu() {
  PA = user32.oEndMenu;
  runASM();
}
void fEndPaint() {
  PA = user32.oEndPaint;
  runASM();
}
void fEndTask() {
  PA = user32.oEndTask;
  runASM();
}
void fEnterMoveSizeLoop() {
  PA = user32.oEnterMoveSizeLoop;
  runASM();
}
void fEnterReaderModeHelper() {
  PA = user32.oEnterReaderModeHelper;
  runASM();
}
void fEnumChildWindows() {
  PA = user32.oEnumChildWindows;
  runASM();
}
void fEnumClipboardFormats() {
  PA = user32.oEnumClipboardFormats;
  runASM();
}
void fEnumDesktopWindows() {
  PA = user32.oEnumDesktopWindows;
  runASM();
}
void fEnumDesktopsA() {
  PA = user32.oEnumDesktopsA;
  runASM();
}
void fEnumDesktopsW() {
  PA = user32.oEnumDesktopsW;
  runASM();
}
void fEnumDisplayDevicesA() {
  PA = user32.oEnumDisplayDevicesA;
  runASM();
}
void fEnumDisplayDevicesW() {
  PA = user32.oEnumDisplayDevicesW;
  runASM();
}
void fEnumDisplayMonitors() {
  PA = user32.oEnumDisplayMonitors;
  runASM();
}
void fEnumDisplaySettingsA() {
  PA = user32.oEnumDisplaySettingsA;
  runASM();
}
void fEnumDisplaySettingsExA() {
  PA = user32.oEnumDisplaySettingsExA;
  runASM();
}
void fEnumDisplaySettingsExW() {
  PA = user32.oEnumDisplaySettingsExW;
  runASM();
}
void fEnumDisplaySettingsW() {
  PA = user32.oEnumDisplaySettingsW;
  runASM();
}
void fEnumPropsA() {
  PA = user32.oEnumPropsA;
  runASM();
}
void fEnumPropsExA() {
  PA = user32.oEnumPropsExA;
  runASM();
}
void fEnumPropsExW() {
  PA = user32.oEnumPropsExW;
  runASM();
}
void fEnumPropsW() {
  PA = user32.oEnumPropsW;
  runASM();
}
void fEnumThreadWindows() {
  PA = user32.oEnumThreadWindows;
  runASM();
}
void fEnumWindowStationsA() {
  PA = user32.oEnumWindowStationsA;
  runASM();
}
void fEnumWindowStationsW() {
  PA = user32.oEnumWindowStationsW;
  runASM();
}
void fEnumWindows() {
  PA = user32.oEnumWindows;
  runASM();
}
void fEqualRect() {
  PA = user32.oEqualRect;
  runASM();
}
void fEvaluateProximityToPolygon() {
  PA = user32.oEvaluateProximityToPolygon;
  runASM();
}
void fEvaluateProximityToRect() {
  PA = user32.oEvaluateProximityToRect;
  runASM();
}
void fExcludeUpdateRgn() {
  PA = user32.oExcludeUpdateRgn;
  runASM();
}
void fExitWindowsEx() {
  PA = user32.oExitWindowsEx;
  runASM();
}
void fFillRect() {
  PA = user32.oFillRect;
  runASM();
}
void fFindWindowA() {
  PA = user32.oFindWindowA;
  runASM();
}
void fFindWindowExA() {
  PA = user32.oFindWindowExA;
  runASM();
}
void fFindWindowExW() {
  PA = user32.oFindWindowExW;
  runASM();
}
void fFindWindowW() {
  PA = user32.oFindWindowW;
  runASM();
}
void fFlashWindow() {
  PA = user32.oFlashWindow;
  runASM();
}
void fFlashWindowEx() {
  PA = user32.oFlashWindowEx;
  runASM();
}
void fFrameRect() {
  PA = user32.oFrameRect;
  runASM();
}
void fFreeDDElParam() {
  PA = user32.oFreeDDElParam;
  runASM();
}
void fFrostCrashedWindow() {
  PA = user32.oFrostCrashedWindow;
  runASM();
}
void fGetActiveWindow() {
  PA = user32.oGetActiveWindow;
  runASM();
}
void fGetAltTabInfo() {
  PA = user32.oGetAltTabInfo;
  runASM();
}
void fGetAltTabInfoA() {
  PA = user32.oGetAltTabInfoA;
  runASM();
}
void fGetAltTabInfoW() {
  PA = user32.oGetAltTabInfoW;
  runASM();
}
void fGetAncestor() {
  PA = user32.oGetAncestor;
  runASM();
}
void fGetAppCompatFlags() {
  PA = user32.oGetAppCompatFlags;
  runASM();
}
void fGetAppCompatFlags2() {
  PA = user32.oGetAppCompatFlags2;
  runASM();
}
void fGetAsyncKeyState() {
  PA = user32.oGetAsyncKeyState;
  runASM();
}
void fGetAutoRotationState() {
  PA = user32.oGetAutoRotationState;
  runASM();
}
void fGetAwarenessFromDpiAwarenessContext() {
  PA = user32.oGetAwarenessFromDpiAwarenessContext;
  runASM();
}
void fGetCIMSSM() {
  PA = user32.oGetCIMSSM;
  runASM();
}
void fGetCapture() {
  PA = user32.oGetCapture;
  runASM();
}
void fGetCaretBlinkTime() {
  PA = user32.oGetCaretBlinkTime;
  runASM();
}
void fGetCaretPos() {
  PA = user32.oGetCaretPos;
  runASM();
}
void fGetClassInfoA() {
  PA = user32.oGetClassInfoA;
  runASM();
}
void fGetClassInfoExA() {
  PA = user32.oGetClassInfoExA;
  runASM();
}
void fGetClassInfoExW() {
  PA = user32.oGetClassInfoExW;
  runASM();
}
void fGetClassInfoW() {
  PA = user32.oGetClassInfoW;
  runASM();
}
void fGetClassLongA() {
  PA = user32.oGetClassLongA;
  runASM();
}
void fGetClassLongPtrA() {
  PA = user32.oGetClassLongPtrA;
  runASM();
}
void fGetClassLongPtrW() {
  PA = user32.oGetClassLongPtrW;
  runASM();
}
void fGetClassLongW() {
  PA = user32.oGetClassLongW;
  runASM();
}
void fGetClassNameA() {
  PA = user32.oGetClassNameA;
  runASM();
}
void fGetClassNameW() {
  PA = user32.oGetClassNameW;
  runASM();
}
void fGetClassWord() {
  PA = user32.oGetClassWord;
  runASM();
}
void fGetClientRect() {
  PA = user32.oGetClientRect;
  runASM();
}
void fGetClipCursor() {
  PA = user32.oGetClipCursor;
  runASM();
}
void fGetClipboardAccessToken() {
  PA = user32.oGetClipboardAccessToken;
  runASM();
}
void fGetClipboardData() {
  PA = user32.oGetClipboardData;
  runASM();
}
void fGetClipboardFormatNameA() {
  PA = user32.oGetClipboardFormatNameA;
  runASM();
}
void fGetClipboardFormatNameW() {
  PA = user32.oGetClipboardFormatNameW;
  runASM();
}
void fGetClipboardMetadata() {
  PA = user32.oGetClipboardMetadata;
  runASM();
}
void fGetClipboardOwner() {
  PA = user32.oGetClipboardOwner;
  runASM();
}
void fGetClipboardSequenceNumber() {
  PA = user32.oGetClipboardSequenceNumber;
  runASM();
}
void fGetClipboardViewer() {
  PA = user32.oGetClipboardViewer;
  runASM();
}
void fGetComboBoxInfo() {
  PA = user32.oGetComboBoxInfo;
  runASM();
}
void fGetCurrentInputMessageSource() {
  PA = user32.oGetCurrentInputMessageSource;
  runASM();
}
void fGetCurrentMonitorTopologyId() {
  PA = user32.oGetCurrentMonitorTopologyId;
  runASM();
}
void fGetCursor() {
  PA = user32.oGetCursor;
  runASM();
}
void fGetCursorFrameInfo() {
  PA = user32.oGetCursorFrameInfo;
  runASM();
}
void fGetCursorInfo() {
  PA = user32.oGetCursorInfo;
  runASM();
}
void fGetCursorPos() {
  PA = user32.oGetCursorPos;
  runASM();
}
void fGetDC() {
  PA = user32.oGetDC;
  runASM();
}
void fGetDCEx() {
  PA = user32.oGetDCEx;
  runASM();
}
void fGetDCompositionHwndBitmap() {
  PA = user32.oGetDCompositionHwndBitmap;
  runASM();
}
void fGetDesktopID() {
  PA = user32.oGetDesktopID;
  runASM();
}
void fGetDesktopWindow() {
  PA = user32.oGetDesktopWindow;
  runASM();
}
void fGetDialogBaseUnits() {
  PA = user32.oGetDialogBaseUnits;
  runASM();
}
void fGetDialogControlDpiChangeBehavior() {
  PA = user32.oGetDialogControlDpiChangeBehavior;
  runASM();
}
void fGetDialogDpiChangeBehavior() {
  PA = user32.oGetDialogDpiChangeBehavior;
  runASM();
}
void fGetDisplayAutoRotationPreferences() {
  PA = user32.oGetDisplayAutoRotationPreferences;
  runASM();
}
void fGetDisplayConfigBufferSizes() {
  PA = user32.oGetDisplayConfigBufferSizes;
  runASM();
}
void fGetDlgCtrlID() {
  PA = user32.oGetDlgCtrlID;
  runASM();
}
void fGetDlgItem() {
  PA = user32.oGetDlgItem;
  runASM();
}
void fGetDlgItemInt() {
  PA = user32.oGetDlgItemInt;
  runASM();
}
void fGetDlgItemTextA() {
  PA = user32.oGetDlgItemTextA;
  runASM();
}
void fGetDlgItemTextW() {
  PA = user32.oGetDlgItemTextW;
  runASM();
}
void fGetDoubleClickTime() {
  PA = user32.oGetDoubleClickTime;
  runASM();
}
void fGetDpiAwarenessContextForProcess() {
  PA = user32.oGetDpiAwarenessContextForProcess;
  runASM();
}
void fGetDpiForMonitorInternal() {
  PA = user32.oGetDpiForMonitorInternal;
  runASM();
}
void fGetDpiForSystem() {
  PA = user32.oGetDpiForSystem;
  runASM();
}
void fGetDpiForWindow() {
  PA = user32.oGetDpiForWindow;
  runASM();
}
void fGetDpiFromDpiAwarenessContext() {
  PA = user32.oGetDpiFromDpiAwarenessContext;
  runASM();
}
void fGetExtendedPointerDeviceProperty() {
  PA = user32.oGetExtendedPointerDeviceProperty;
  runASM();
}
void fGetFocus() {
  PA = user32.oGetFocus;
  runASM();
}
void fGetForegroundWindow() {
  PA = user32.oGetForegroundWindow;
  runASM();
}
void fGetGUIThreadInfo() {
  PA = user32.oGetGUIThreadInfo;
  runASM();
}
void fGetGestureConfig() {
  PA = user32.oGetGestureConfig;
  runASM();
}
void fGetGestureExtraArgs() {
  PA = user32.oGetGestureExtraArgs;
  runASM();
}
void fGetGestureInfo() {
  PA = user32.oGetGestureInfo;
  runASM();
}
void fGetGuiResources() {
  PA = user32.oGetGuiResources;
  runASM();
}
void fGetIconInfo() {
  PA = user32.oGetIconInfo;
  runASM();
}
void fGetIconInfoExA() {
  PA = user32.oGetIconInfoExA;
  runASM();
}
void fGetIconInfoExW() {
  PA = user32.oGetIconInfoExW;
  runASM();
}
void fGetInputDesktop() {
  PA = user32.oGetInputDesktop;
  runASM();
}
void fGetInputLocaleInfo() {
  PA = user32.oGetInputLocaleInfo;
  runASM();
}
void fGetInputState() {
  PA = user32.oGetInputState;
  runASM();
}
void fGetInternalWindowPos() {
  PA = user32.oGetInternalWindowPos;
  runASM();
}
void fGetKBCodePage() {
  PA = user32.oGetKBCodePage;
  runASM();
}
void fGetKeyNameTextA() {
  PA = user32.oGetKeyNameTextA;
  runASM();
}
void fGetKeyNameTextW() {
  PA = user32.oGetKeyNameTextW;
  runASM();
}
void fGetKeyState() {
  PA = user32.oGetKeyState;
  runASM();
}
void fGetKeyboardLayout() {
  PA = user32.oGetKeyboardLayout;
  runASM();
}
void fGetKeyboardLayoutList() {
  PA = user32.oGetKeyboardLayoutList;
  runASM();
}
void fGetKeyboardLayoutNameA() {
  PA = user32.oGetKeyboardLayoutNameA;
  runASM();
}
void fGetKeyboardLayoutNameW() {
  PA = user32.oGetKeyboardLayoutNameW;
  runASM();
}
void fGetKeyboardState() {
  PA = user32.oGetKeyboardState;
  runASM();
}
void fGetKeyboardType() {
  PA = user32.oGetKeyboardType;
  runASM();
}
void fGetLastActivePopup() {
  PA = user32.oGetLastActivePopup;
  runASM();
}
void fGetLastInputInfo() {
  PA = user32.oGetLastInputInfo;
  runASM();
}
void fGetLayeredWindowAttributes() {
  PA = user32.oGetLayeredWindowAttributes;
  runASM();
}
void fGetListBoxInfo() {
  PA = user32.oGetListBoxInfo;
  runASM();
}
void fGetMagnificationDesktopColorEffect() {
  PA = user32.oGetMagnificationDesktopColorEffect;
  runASM();
}
void fGetMagnificationDesktopMagnification() {
  PA = user32.oGetMagnificationDesktopMagnification;
  runASM();
}
void fGetMagnificationDesktopSamplingMode() {
  PA = user32.oGetMagnificationDesktopSamplingMode;
  runASM();
}
void fGetMagnificationLensCtxInformation() {
  PA = user32.oGetMagnificationLensCtxInformation;
  runASM();
}
void fGetMenu() {
  PA = user32.oGetMenu;
  runASM();
}
void fGetMenuBarInfo() {
  PA = user32.oGetMenuBarInfo;
  runASM();
}
void fGetMenuCheckMarkDimensions() {
  PA = user32.oGetMenuCheckMarkDimensions;
  runASM();
}
void fGetMenuContextHelpId() {
  PA = user32.oGetMenuContextHelpId;
  runASM();
}
void fGetMenuDefaultItem() {
  PA = user32.oGetMenuDefaultItem;
  runASM();
}
void fGetMenuInfo() {
  PA = user32.oGetMenuInfo;
  runASM();
}
void fGetMenuItemCount() {
  PA = user32.oGetMenuItemCount;
  runASM();
}
void fGetMenuItemID() {
  PA = user32.oGetMenuItemID;
  runASM();
}
void fGetMenuItemInfoA() {
  PA = user32.oGetMenuItemInfoA;
  runASM();
}
void fGetMenuItemInfoW() {
  PA = user32.oGetMenuItemInfoW;
  runASM();
}
void fGetMenuItemRect() {
  PA = user32.oGetMenuItemRect;
  runASM();
}
void fGetMenuState() {
  PA = user32.oGetMenuState;
  runASM();
}
void fGetMenuStringA() {
  PA = user32.oGetMenuStringA;
  runASM();
}
void fGetMenuStringW() {
  PA = user32.oGetMenuStringW;
  runASM();
}
void fGetMessageA() {
  PA = user32.oGetMessageA;
  runASM();
}
void fGetMessageExtraInfo() {
  PA = user32.oGetMessageExtraInfo;
  runASM();
}
void fGetMessagePos() {
  PA = user32.oGetMessagePos;
  runASM();
}
void fGetMessageTime() {
  PA = user32.oGetMessageTime;
  runASM();
}
void fGetMessageW() {
  PA = user32.oGetMessageW;
  runASM();
}
void fGetMonitorInfoA() {
  PA = user32.oGetMonitorInfoA;
  runASM();
}
void fGetMonitorInfoW() {
  PA = user32.oGetMonitorInfoW;
  runASM();
}
void fGetMouseMovePointsEx() {
  PA = user32.oGetMouseMovePointsEx;
  runASM();
}
void fGetNextDlgGroupItem() {
  PA = user32.oGetNextDlgGroupItem;
  runASM();
}
void fGetNextDlgTabItem() {
  PA = user32.oGetNextDlgTabItem;
  runASM();
}
void fGetOpenClipboardWindow() {
  PA = user32.oGetOpenClipboardWindow;
  runASM();
}
void fGetParent() {
  PA = user32.oGetParent;
  runASM();
}
void fGetPhysicalCursorPos() {
  PA = user32.oGetPhysicalCursorPos;
  runASM();
}
void fGetPointerCursorId() {
  PA = user32.oGetPointerCursorId;
  runASM();
}
void fGetPointerDevice() {
  PA = user32.oGetPointerDevice;
  runASM();
}
void fGetPointerDeviceCursors() {
  PA = user32.oGetPointerDeviceCursors;
  runASM();
}
void fGetPointerDeviceInputSpace() {
  PA = user32.oGetPointerDeviceInputSpace;
  runASM();
}
void fGetPointerDeviceOrientation() {
  PA = user32.oGetPointerDeviceOrientation;
  runASM();
}
void fGetPointerDeviceProperties() {
  PA = user32.oGetPointerDeviceProperties;
  runASM();
}
void fGetPointerDeviceRects() {
  PA = user32.oGetPointerDeviceRects;
  runASM();
}
void fGetPointerDevices() {
  PA = user32.oGetPointerDevices;
  runASM();
}
void fGetPointerFrameArrivalTimes() {
  PA = user32.oGetPointerFrameArrivalTimes;
  runASM();
}
void fGetPointerFrameInfo() {
  PA = user32.oGetPointerFrameInfo;
  runASM();
}
void fGetPointerFrameInfoHistory() {
  PA = user32.oGetPointerFrameInfoHistory;
  runASM();
}
void fGetPointerFramePenInfo() {
  PA = user32.oGetPointerFramePenInfo;
  runASM();
}
void fGetPointerFramePenInfoHistory() {
  PA = user32.oGetPointerFramePenInfoHistory;
  runASM();
}
void fGetPointerFrameTimes() {
  PA = user32.oGetPointerFrameTimes;
  runASM();
}
void fGetPointerFrameTouchInfo() {
  PA = user32.oGetPointerFrameTouchInfo;
  runASM();
}
void fGetPointerFrameTouchInfoHistory() {
  PA = user32.oGetPointerFrameTouchInfoHistory;
  runASM();
}
void fGetPointerFrameTouchpadInfo() {
  PA = user32.oGetPointerFrameTouchpadInfo;
  runASM();
}
void fGetPointerFrameTouchpadInfoHistory() {
  PA = user32.oGetPointerFrameTouchpadInfoHistory;
  runASM();
}
void fGetPointerInfo() {
  PA = user32.oGetPointerInfo;
  runASM();
}
void fGetPointerInfoHistory() {
  PA = user32.oGetPointerInfoHistory;
  runASM();
}
void fGetPointerInputTransform() {
  PA = user32.oGetPointerInputTransform;
  runASM();
}
void fGetPointerPenInfo() {
  PA = user32.oGetPointerPenInfo;
  runASM();
}
void fGetPointerPenInfoHistory() {
  PA = user32.oGetPointerPenInfoHistory;
  runASM();
}
void fGetPointerTouchInfo() {
  PA = user32.oGetPointerTouchInfo;
  runASM();
}
void fGetPointerTouchInfoHistory() {
  PA = user32.oGetPointerTouchInfoHistory;
  runASM();
}
void fGetPointerTouchpadInfo() {
  PA = user32.oGetPointerTouchpadInfo;
  runASM();
}
void fGetPointerTouchpadInfoHistory() {
  PA = user32.oGetPointerTouchpadInfoHistory;
  runASM();
}
void fGetPointerType() {
  PA = user32.oGetPointerType;
  runASM();
}
void fGetPriorityClipboardFormat() {
  PA = user32.oGetPriorityClipboardFormat;
  runASM();
}
void fGetProcessDefaultLayout() {
  PA = user32.oGetProcessDefaultLayout;
  runASM();
}
void fGetProcessDpiAwarenessInternal() {
  PA = user32.oGetProcessDpiAwarenessInternal;
  runASM();
}
void fGetProcessUIContextInformation() {
  PA = user32.oGetProcessUIContextInformation;
  runASM();
}
void fGetProcessWindowStation() {
  PA = user32.oGetProcessWindowStation;
  runASM();
}
void fGetProgmanWindow() {
  PA = user32.oGetProgmanWindow;
  runASM();
}
void fGetPropA() {
  PA = user32.oGetPropA;
  runASM();
}
void fGetPropW() {
  PA = user32.oGetPropW;
  runASM();
}
void fGetQueueStatus() {
  PA = user32.oGetQueueStatus;
  runASM();
}
void fGetRawInputBuffer() {
  PA = user32.oGetRawInputBuffer;
  runASM();
}
void fGetRawInputData() {
  PA = user32.oGetRawInputData;
  runASM();
}
void fGetRawInputDeviceInfoA() {
  PA = user32.oGetRawInputDeviceInfoA;
  runASM();
}
void fGetRawInputDeviceInfoW() {
  PA = user32.oGetRawInputDeviceInfoW;
  runASM();
}
void fGetRawInputDeviceList() {
  PA = user32.oGetRawInputDeviceList;
  runASM();
}
void fGetRawPointerDeviceData() {
  PA = user32.oGetRawPointerDeviceData;
  runASM();
}
void fGetReasonTitleFromReasonCode() {
  PA = user32.oGetReasonTitleFromReasonCode;
  runASM();
}
void fGetRegisteredRawInputDevices() {
  PA = user32.oGetRegisteredRawInputDevices;
  runASM();
}
void fGetScrollBarInfo() {
  PA = user32.oGetScrollBarInfo;
  runASM();
}
void fGetScrollInfo() {
  PA = user32.oGetScrollInfo;
  runASM();
}
void fGetScrollPos() {
  PA = user32.oGetScrollPos;
  runASM();
}
void fGetScrollRange() {
  PA = user32.oGetScrollRange;
  runASM();
}
void fGetSendMessageReceiver() {
  PA = user32.oGetSendMessageReceiver;
  runASM();
}
void fGetShellChangeNotifyWindow() {
  PA = user32.oGetShellChangeNotifyWindow;
  runASM();
}
void fGetShellWindow() {
  PA = user32.oGetShellWindow;
  runASM();
}
void fGetSubMenu() {
  PA = user32.oGetSubMenu;
  runASM();
}
void fGetSysColor() {
  PA = user32.oGetSysColor;
  runASM();
}
void fGetSysColorBrush() {
  PA = user32.oGetSysColorBrush;
  runASM();
}
void fGetSystemDpiForProcess() {
  PA = user32.oGetSystemDpiForProcess;
  runASM();
}
void fGetSystemMenu() {
  PA = user32.oGetSystemMenu;
  runASM();
}
void fGetSystemMetrics() {
  PA = user32.oGetSystemMetrics;
  runASM();
}
void fGetSystemMetricsForDpi() {
  PA = user32.oGetSystemMetricsForDpi;
  runASM();
}
void fGetTabbedTextExtentA() {
  PA = user32.oGetTabbedTextExtentA;
  runASM();
}
void fGetTabbedTextExtentW() {
  PA = user32.oGetTabbedTextExtentW;
  runASM();
}
void fGetTaskmanWindow() {
  PA = user32.oGetTaskmanWindow;
  runASM();
}
void fGetThreadDesktop() {
  PA = user32.oGetThreadDesktop;
  runASM();
}
void fGetThreadDpiAwarenessContext() {
  PA = user32.oGetThreadDpiAwarenessContext;
  runASM();
}
void fGetThreadDpiHostingBehavior() {
  PA = user32.oGetThreadDpiHostingBehavior;
  runASM();
}
void fGetTitleBarInfo() {
  PA = user32.oGetTitleBarInfo;
  runASM();
}
void fGetTopLevelWindow() {
  PA = user32.oGetTopLevelWindow;
  runASM();
}
void fGetTopWindow() {
  PA = user32.oGetTopWindow;
  runASM();
}
void fGetTouchInputInfo() {
  PA = user32.oGetTouchInputInfo;
  runASM();
}
void fGetUnpredictedMessagePos() {
  PA = user32.oGetUnpredictedMessagePos;
  runASM();
}
void fGetUpdateRect() {
  PA = user32.oGetUpdateRect;
  runASM();
}
void fGetUpdateRgn() {
  PA = user32.oGetUpdateRgn;
  runASM();
}
void fGetUpdatedClipboardFormats() {
  PA = user32.oGetUpdatedClipboardFormats;
  runASM();
}
void fGetUserObjectInformationA() {
  PA = user32.oGetUserObjectInformationA;
  runASM();
}
void fGetUserObjectInformationW() {
  PA = user32.oGetUserObjectInformationW;
  runASM();
}
void fGetUserObjectSecurity() {
  PA = user32.oGetUserObjectSecurity;
  runASM();
}
void fGetWinStationInfo() {
  PA = user32.oGetWinStationInfo;
  runASM();
}
void fGetWindow() {
  PA = user32.oGetWindow;
  runASM();
}
void fGetWindowBand() {
  PA = user32.oGetWindowBand;
  runASM();
}
void fGetWindowCompositionAttribute() {
  PA = user32.oGetWindowCompositionAttribute;
  runASM();
}
void fGetWindowCompositionInfo() {
  PA = user32.oGetWindowCompositionInfo;
  runASM();
}
void fGetWindowContextHelpId() {
  PA = user32.oGetWindowContextHelpId;
  runASM();
}
void fGetWindowDC() {
  PA = user32.oGetWindowDC;
  runASM();
}
void fGetWindowDisplayAffinity() {
  PA = user32.oGetWindowDisplayAffinity;
  runASM();
}
void fGetWindowDpiAwarenessContext() {
  PA = user32.oGetWindowDpiAwarenessContext;
  runASM();
}
void fGetWindowDpiHostingBehavior() {
  PA = user32.oGetWindowDpiHostingBehavior;
  runASM();
}
void fGetWindowFeedbackSetting() {
  PA = user32.oGetWindowFeedbackSetting;
  runASM();
}
void fGetWindowInfo() {
  PA = user32.oGetWindowInfo;
  runASM();
}
void fGetWindowLongA() {
  PA = user32.oGetWindowLongA;
  runASM();
}
void fGetWindowLongPtrA() {
  PA = user32.oGetWindowLongPtrA;
  runASM();
}
void fGetWindowLongPtrW() {
  PA = user32.oGetWindowLongPtrW;
  runASM();
}
void fGetWindowLongW() {
  PA = user32.oGetWindowLongW;
  runASM();
}
void fGetWindowMinimizeRect() {
  PA = user32.oGetWindowMinimizeRect;
  runASM();
}
void fGetWindowModuleFileName() {
  PA = user32.oGetWindowModuleFileName;
  runASM();
}
void fGetWindowModuleFileNameA() {
  PA = user32.oGetWindowModuleFileNameA;
  runASM();
}
void fGetWindowModuleFileNameW() {
  PA = user32.oGetWindowModuleFileNameW;
  runASM();
}
void fGetWindowPlacement() {
  PA = user32.oGetWindowPlacement;
  runASM();
}
void fGetWindowProcessHandle() {
  PA = user32.oGetWindowProcessHandle;
  runASM();
}
void fGetWindowRect() {
  PA = user32.oGetWindowRect;
  runASM();
}
void fGetWindowRgn() {
  PA = user32.oGetWindowRgn;
  runASM();
}
void fGetWindowRgnBox() {
  PA = user32.oGetWindowRgnBox;
  runASM();
}
void fGetWindowRgnEx() {
  PA = user32.oGetWindowRgnEx;
  runASM();
}
void fGetWindowTextA() {
  PA = user32.oGetWindowTextA;
  runASM();
}
void fGetWindowTextLengthA() {
  PA = user32.oGetWindowTextLengthA;
  runASM();
}
void fGetWindowTextLengthW() {
  PA = user32.oGetWindowTextLengthW;
  runASM();
}
void fGetWindowTextW() {
  PA = user32.oGetWindowTextW;
  runASM();
}
void fGetWindowThreadProcessId() {
  PA = user32.oGetWindowThreadProcessId;
  runASM();
}
void fGetWindowWord() {
  PA = user32.oGetWindowWord;
  runASM();
}
void fGhostWindowFromHungWindow() {
  PA = user32.oGhostWindowFromHungWindow;
  runASM();
}
void fGrayStringA() {
  PA = user32.oGrayStringA;
  runASM();
}
void fGrayStringW() {
  PA = user32.oGrayStringW;
  runASM();
}
void fHandleDelegatedInput() {
  PA = user32.oHandleDelegatedInput;
  runASM();
}
void fHideCaret() {
  PA = user32.oHideCaret;
  runASM();
}
void fHiliteMenuItem() {
  PA = user32.oHiliteMenuItem;
  runASM();
}
void fHungWindowFromGhostWindow() {
  PA = user32.oHungWindowFromGhostWindow;
  runASM();
}
void fIMPGetIMEA() {
  PA = user32.oIMPGetIMEA;
  runASM();
}
void fIMPGetIMEW() {
  PA = user32.oIMPGetIMEW;
  runASM();
}
void fIMPQueryIMEA() {
  PA = user32.oIMPQueryIMEA;
  runASM();
}
void fIMPQueryIMEW() {
  PA = user32.oIMPQueryIMEW;
  runASM();
}
void fIMPSetIMEA() {
  PA = user32.oIMPSetIMEA;
  runASM();
}
void fIMPSetIMEW() {
  PA = user32.oIMPSetIMEW;
  runASM();
}
void fImpersonateDdeClientWindow() {
  PA = user32.oImpersonateDdeClientWindow;
  runASM();
}
void fInSendMessage() {
  PA = user32.oInSendMessage;
  runASM();
}
void fInSendMessageEx() {
  PA = user32.oInSendMessageEx;
  runASM();
}
void fInflateRect() {
  PA = user32.oInflateRect;
  runASM();
}
void fInheritWindowMonitor() {
  PA = user32.oInheritWindowMonitor;
  runASM();
}
void fInitDManipHook() {
  PA = user32.oInitDManipHook;
  runASM();
}
void fInitializeGenericHidInjection() {
  PA = user32.oInitializeGenericHidInjection;
  runASM();
}
void fInitializeInputDeviceInjection() {
  PA = user32.oInitializeInputDeviceInjection;
  runASM();
}
void fInitializeLpkHooks() {
  PA = user32.oInitializeLpkHooks;
  runASM();
}
void fInitializePointerDeviceInjection() {
  PA = user32.oInitializePointerDeviceInjection;
  runASM();
}
void fInitializePointerDeviceInjectionEx() {
  PA = user32.oInitializePointerDeviceInjectionEx;
  runASM();
}
void fInitializeTouchInjection() {
  PA = user32.oInitializeTouchInjection;
  runASM();
}
void fInjectDeviceInput() {
  PA = user32.oInjectDeviceInput;
  runASM();
}
void fInjectGenericHidInput() {
  PA = user32.oInjectGenericHidInput;
  runASM();
}
void fInjectKeyboardInput() {
  PA = user32.oInjectKeyboardInput;
  runASM();
}
void fInjectMouseInput() {
  PA = user32.oInjectMouseInput;
  runASM();
}
void fInjectPointerInput() {
  PA = user32.oInjectPointerInput;
  runASM();
}
void fInjectSyntheticPointerInput() {
  PA = user32.oInjectSyntheticPointerInput;
  runASM();
}
void fInjectTouchInput() {
  PA = user32.oInjectTouchInput;
  runASM();
}
void fInputSpaceRegionFromPoint() {
  PA = user32.oInputSpaceRegionFromPoint;
  runASM();
}
void fInsertMenuA() {
  PA = user32.oInsertMenuA;
  runASM();
}
void fInsertMenuItemA() {
  PA = user32.oInsertMenuItemA;
  runASM();
}
void fInsertMenuItemW() {
  PA = user32.oInsertMenuItemW;
  runASM();
}
void fInsertMenuW() {
  PA = user32.oInsertMenuW;
  runASM();
}
void fInternalGetWindowIcon() {
  PA = user32.oInternalGetWindowIcon;
  runASM();
}
void fInternalGetWindowText() {
  PA = user32.oInternalGetWindowText;
  runASM();
}
void fIntersectRect() {
  PA = user32.oIntersectRect;
  runASM();
}
void fInvalidateRect() {
  PA = user32.oInvalidateRect;
  runASM();
}
void fInvalidateRgn() {
  PA = user32.oInvalidateRgn;
  runASM();
}
void fInvertRect() {
  PA = user32.oInvertRect;
  runASM();
}
void fIsCharAlphaA() {
  PA = user32.oIsCharAlphaA;
  runASM();
}
void fIsCharAlphaNumericA() {
  PA = user32.oIsCharAlphaNumericA;
  runASM();
}
void fIsCharAlphaNumericW() {
  PA = user32.oIsCharAlphaNumericW;
  runASM();
}
void fIsCharAlphaW() {
  PA = user32.oIsCharAlphaW;
  runASM();
}
void fIsCharLowerA() {
  PA = user32.oIsCharLowerA;
  runASM();
}
void fIsCharLowerW() {
  PA = user32.oIsCharLowerW;
  runASM();
}
void fIsCharUpperA() {
  PA = user32.oIsCharUpperA;
  runASM();
}
void fIsCharUpperW() {
  PA = user32.oIsCharUpperW;
  runASM();
}
void fIsChild() {
  PA = user32.oIsChild;
  runASM();
}
void fIsClipboardFormatAvailable() {
  PA = user32.oIsClipboardFormatAvailable;
  runASM();
}
void fIsDialogMessage() {
  PA = user32.oIsDialogMessage;
  runASM();
}
void fIsDialogMessageA() {
  PA = user32.oIsDialogMessageA;
  runASM();
}
void fIsDialogMessageW() {
  PA = user32.oIsDialogMessageW;
  runASM();
}
void fIsDlgButtonChecked() {
  PA = user32.oIsDlgButtonChecked;
  runASM();
}
void fIsGUIThread() {
  PA = user32.oIsGUIThread;
  runASM();
}
void fIsHungAppWindow() {
  PA = user32.oIsHungAppWindow;
  runASM();
}
void fIsIconic() {
  PA = user32.oIsIconic;
  runASM();
}
void fIsImmersiveProcess() {
  PA = user32.oIsImmersiveProcess;
  runASM();
}
void fIsInDesktopWindowBand() {
  PA = user32.oIsInDesktopWindowBand;
  runASM();
}
void fIsInterceptWindow() {
  PA = user32.oIsInterceptWindow;
  runASM();
}
void fIsMenu() {
  PA = user32.oIsMenu;
  runASM();
}
void fIsMouseInPointerEnabled() {
  PA = user32.oIsMouseInPointerEnabled;
  runASM();
}
void fIsOneCoreTransformMode() {
  PA = user32.oIsOneCoreTransformMode;
  runASM();
}
void fIsProcessDPIAware() {
  PA = user32.oIsProcessDPIAware;
  runASM();
}
void fIsRectEmpty() {
  PA = user32.oIsRectEmpty;
  runASM();
}
void fIsSETEnabled() {
  PA = user32.oIsSETEnabled;
  runASM();
}
void fIsServerSideWindow() {
  PA = user32.oIsServerSideWindow;
  runASM();
}
void fIsThreadDesktopComposited() {
  PA = user32.oIsThreadDesktopComposited;
  runASM();
}
void fIsThreadMessageQueueAttached() {
  PA = user32.oIsThreadMessageQueueAttached;
  runASM();
}
void fIsThreadTSFEventAware() {
  PA = user32.oIsThreadTSFEventAware;
  runASM();
}
void fIsTopLevelWindow() {
  PA = user32.oIsTopLevelWindow;
  runASM();
}
void fIsTouchWindow() {
  PA = user32.oIsTouchWindow;
  runASM();
}
void fIsValidDpiAwarenessContext() {
  PA = user32.oIsValidDpiAwarenessContext;
  runASM();
}
void fIsWinEventHookInstalled() {
  PA = user32.oIsWinEventHookInstalled;
  runASM();
}
void fIsWindow() {
  PA = user32.oIsWindow;
  runASM();
}
void fIsWindowArranged() {
  PA = user32.oIsWindowArranged;
  runASM();
}
void fIsWindowDisplayChangeSuppressed() {
  PA = user32.oIsWindowDisplayChangeSuppressed;
  runASM();
}
void fIsWindowEnabled() {
  PA = user32.oIsWindowEnabled;
  runASM();
}
void fIsWindowInDestroy() {
  PA = user32.oIsWindowInDestroy;
  runASM();
}
void fIsWindowRedirectedForPrint() {
  PA = user32.oIsWindowRedirectedForPrint;
  runASM();
}
void fIsWindowUnicode() {
  PA = user32.oIsWindowUnicode;
  runASM();
}
void fIsWindowVisible() {
  PA = user32.oIsWindowVisible;
  runASM();
}
void fIsWow64Message() {
  PA = user32.oIsWow64Message;
  runASM();
}
void fIsZoomed() {
  PA = user32.oIsZoomed;
  runASM();
}
void fKillTimer() {
  PA = user32.oKillTimer;
  runASM();
}
void fLoadAcceleratorsA() {
  PA = user32.oLoadAcceleratorsA;
  runASM();
}
void fLoadAcceleratorsW() {
  PA = user32.oLoadAcceleratorsW;
  runASM();
}
void fLoadBitmapA() {
  PA = user32.oLoadBitmapA;
  runASM();
}
void fLoadBitmapW() {
  PA = user32.oLoadBitmapW;
  runASM();
}
void fLoadCursorA() {
  PA = user32.oLoadCursorA;
  runASM();
}
void fLoadCursorFromFileA() {
  PA = user32.oLoadCursorFromFileA;
  runASM();
}
void fLoadCursorFromFileW() {
  PA = user32.oLoadCursorFromFileW;
  runASM();
}
void fLoadCursorW() {
  PA = user32.oLoadCursorW;
  runASM();
}
void fLoadIconA() {
  PA = user32.oLoadIconA;
  runASM();
}
void fLoadIconW() {
  PA = user32.oLoadIconW;
  runASM();
}
void fLoadImageA() {
  PA = user32.oLoadImageA;
  runASM();
}
void fLoadImageW() {
  PA = user32.oLoadImageW;
  runASM();
}
void fLoadKeyboardLayoutA() {
  PA = user32.oLoadKeyboardLayoutA;
  runASM();
}
void fLoadKeyboardLayoutEx() {
  PA = user32.oLoadKeyboardLayoutEx;
  runASM();
}
void fLoadKeyboardLayoutW() {
  PA = user32.oLoadKeyboardLayoutW;
  runASM();
}
void fLoadLocalFonts() {
  PA = user32.oLoadLocalFonts;
  runASM();
}
void fLoadMenuA() {
  PA = user32.oLoadMenuA;
  runASM();
}
void fLoadMenuIndirectA() {
  PA = user32.oLoadMenuIndirectA;
  runASM();
}
void fLoadMenuIndirectW() {
  PA = user32.oLoadMenuIndirectW;
  runASM();
}
void fLoadMenuW() {
  PA = user32.oLoadMenuW;
  runASM();
}
void fLoadRemoteFonts() {
  PA = user32.oLoadRemoteFonts;
  runASM();
}
void fLoadStringA() {
  PA = user32.oLoadStringA;
  runASM();
}
void fLoadStringW() {
  PA = user32.oLoadStringW;
  runASM();
}
void fLockSetForegroundWindow() {
  PA = user32.oLockSetForegroundWindow;
  runASM();
}
void fLockWindowStation() {
  PA = user32.oLockWindowStation;
  runASM();
}
void fLockWindowUpdate() {
  PA = user32.oLockWindowUpdate;
  runASM();
}
void fLockWorkStation() {
  PA = user32.oLockWorkStation;
  runASM();
}
void fLogicalToPhysicalPoint() {
  PA = user32.oLogicalToPhysicalPoint;
  runASM();
}
void fLogicalToPhysicalPointForPerMonitorDPI() {
  PA = user32.oLogicalToPhysicalPointForPerMonitorDPI;
  runASM();
}
void fLookupIconIdFromDirectory() {
  PA = user32.oLookupIconIdFromDirectory;
  runASM();
}
void fLookupIconIdFromDirectoryEx() {
  PA = user32.oLookupIconIdFromDirectoryEx;
  runASM();
}
void fMBToWCSEx() {
  PA = user32.oMBToWCSEx;
  runASM();
}
void fMBToWCSExt() {
  PA = user32.oMBToWCSExt;
  runASM();
}
void fMB_GetString() {
  PA = user32.oMB_GetString;
  runASM();
}
void fMITGetCursorUpdateHandle() {
  PA = user32.oMITGetCursorUpdateHandle;
  runASM();
}
void fMITSetLastInputRecipient() {
  PA = user32.oMITSetLastInputRecipient;
  runASM();
}
void fMITSynthesizeTouchInput() {
  PA = user32.oMITSynthesizeTouchInput;
  runASM();
}
void fMakeThreadTSFEventAware() {
  PA = user32.oMakeThreadTSFEventAware;
  runASM();
}
void fMapDialogRect() {
  PA = user32.oMapDialogRect;
  runASM();
}
void fMapPointsByVisualIdentifier() {
  PA = user32.oMapPointsByVisualIdentifier;
  runASM();
}
void fMapVirtualKeyA() {
  PA = user32.oMapVirtualKeyA;
  runASM();
}
void fMapVirtualKeyExA() {
  PA = user32.oMapVirtualKeyExA;
  runASM();
}
void fMapVirtualKeyExW() {
  PA = user32.oMapVirtualKeyExW;
  runASM();
}
void fMapVirtualKeyW() {
  PA = user32.oMapVirtualKeyW;
  runASM();
}
void fMapVisualRelativePoints() {
  PA = user32.oMapVisualRelativePoints;
  runASM();
}
void fMapWindowPoints() {
  PA = user32.oMapWindowPoints;
  runASM();
}
void fMenuItemFromPoint() {
  PA = user32.oMenuItemFromPoint;
  runASM();
}
void fMenuWindowProcA() {
  PA = user32.oMenuWindowProcA;
  runASM();
}
void fMenuWindowProcW() {
  PA = user32.oMenuWindowProcW;
  runASM();
}
void fMessageBeep() {
  PA = user32.oMessageBeep;
  runASM();
}
void fMessageBoxA() {
  PA = user32.oMessageBoxA;
  runASM();
}
void fMessageBoxExA() {
  PA = user32.oMessageBoxExA;
  runASM();
}
void fMessageBoxExW() {
  PA = user32.oMessageBoxExW;
  runASM();
}
void fMessageBoxIndirectA() {
  PA = user32.oMessageBoxIndirectA;
  runASM();
}
void fMessageBoxIndirectW() {
  PA = user32.oMessageBoxIndirectW;
  runASM();
}
void fMessageBoxTimeoutA() {
  PA = user32.oMessageBoxTimeoutA;
  runASM();
}
void fMessageBoxTimeoutW() {
  PA = user32.oMessageBoxTimeoutW;
  runASM();
}
void fMessageBoxW() {
  PA = user32.oMessageBoxW;
  runASM();
}
void fModifyMenuA() {
  PA = user32.oModifyMenuA;
  runASM();
}
void fModifyMenuW() {
  PA = user32.oModifyMenuW;
  runASM();
}
void fMonitorFromPoint() {
  PA = user32.oMonitorFromPoint;
  runASM();
}
void fMonitorFromRect() {
  PA = user32.oMonitorFromRect;
  runASM();
}
void fMonitorFromWindow() {
  PA = user32.oMonitorFromWindow;
  runASM();
}
void fMoveWindow() {
  PA = user32.oMoveWindow;
  runASM();
}
void fMsgWaitForMultipleObjects() {
  PA = user32.oMsgWaitForMultipleObjects;
  runASM();
}
void fMsgWaitForMultipleObjectsEx() {
  PA = user32.oMsgWaitForMultipleObjectsEx;
  runASM();
}
void fNotifyOverlayWindow() {
  PA = user32.oNotifyOverlayWindow;
  runASM();
}
void fNotifyWinEvent() {
  PA = user32.oNotifyWinEvent;
  runASM();
}
void fOemKeyScan() {
  PA = user32.oOemKeyScan;
  runASM();
}
void fOemToCharA() {
  PA = user32.oOemToCharA;
  runASM();
}
void fOemToCharBuffA() {
  PA = user32.oOemToCharBuffA;
  runASM();
}
void fOemToCharBuffW() {
  PA = user32.oOemToCharBuffW;
  runASM();
}
void fOemToCharW() {
  PA = user32.oOemToCharW;
  runASM();
}
void fOffsetRect() {
  PA = user32.oOffsetRect;
  runASM();
}
void fOpenClipboard() {
  PA = user32.oOpenClipboard;
  runASM();
}
void fOpenDesktopA() {
  PA = user32.oOpenDesktopA;
  runASM();
}
void fOpenDesktopW() {
  PA = user32.oOpenDesktopW;
  runASM();
}
void fOpenIcon() {
  PA = user32.oOpenIcon;
  runASM();
}
void fOpenInputDesktop() {
  PA = user32.oOpenInputDesktop;
  runASM();
}
void fOpenThreadDesktop() {
  PA = user32.oOpenThreadDesktop;
  runASM();
}
void fOpenWindowStationA() {
  PA = user32.oOpenWindowStationA;
  runASM();
}
void fOpenWindowStationW() {
  PA = user32.oOpenWindowStationW;
  runASM();
}
void fPackDDElParam() {
  PA = user32.oPackDDElParam;
  runASM();
}
void fPackTouchHitTestingProximityEvaluation() {
  PA = user32.oPackTouchHitTestingProximityEvaluation;
  runASM();
}
void fPaintDesktop() {
  PA = user32.oPaintDesktop;
  runASM();
}
void fPaintMenuBar() {
  PA = user32.oPaintMenuBar;
  runASM();
}
void fPaintMonitor() {
  PA = user32.oPaintMonitor;
  runASM();
}
void fPeekMessageA() {
  PA = user32.oPeekMessageA;
  runASM();
}
void fPeekMessageW() {
  PA = user32.oPeekMessageW;
  runASM();
}
void fPhysicalToLogicalPoint() {
  PA = user32.oPhysicalToLogicalPoint;
  runASM();
}
void fPhysicalToLogicalPointForPerMonitorDPI() {
  PA = user32.oPhysicalToLogicalPointForPerMonitorDPI;
  runASM();
}
void fPostMessageA() {
  PA = user32.oPostMessageA;
  runASM();
}
void fPostMessageW() {
  PA = user32.oPostMessageW;
  runASM();
}
void fPostQuitMessage() {
  PA = user32.oPostQuitMessage;
  runASM();
}
void fPostThreadMessageA() {
  PA = user32.oPostThreadMessageA;
  runASM();
}
void fPostThreadMessageW() {
  PA = user32.oPostThreadMessageW;
  runASM();
}
void fPrintWindow() {
  PA = user32.oPrintWindow;
  runASM();
}
void fPrivateExtractIconExA() {
  PA = user32.oPrivateExtractIconExA;
  runASM();
}
void fPrivateExtractIconExW() {
  PA = user32.oPrivateExtractIconExW;
  runASM();
}
void fPrivateExtractIconsA() {
  PA = user32.oPrivateExtractIconsA;
  runASM();
}
void fPrivateExtractIconsW() {
  PA = user32.oPrivateExtractIconsW;
  runASM();
}
void fPrivateRegisterICSProc() {
  PA = user32.oPrivateRegisterICSProc;
  runASM();
}
void fPtInRect() {
  PA = user32.oPtInRect;
  runASM();
}
void fQueryBSDRWindow() {
  PA = user32.oQueryBSDRWindow;
  runASM();
}
void fQueryDisplayConfig() {
  PA = user32.oQueryDisplayConfig;
  runASM();
}
void fQuerySendMessage() {
  PA = user32.oQuerySendMessage;
  runASM();
}
void fRIMAddInputObserver() {
  PA = user32.oRIMAddInputObserver;
  runASM();
}
void fRIMAreSiblingDevices() {
  PA = user32.oRIMAreSiblingDevices;
  runASM();
}
void fRIMDeviceIoControl() {
  PA = user32.oRIMDeviceIoControl;
  runASM();
}
void fRIMEnableMonitorMappingForDevice() {
  PA = user32.oRIMEnableMonitorMappingForDevice;
  runASM();
}
void fRIMFreeInputBuffer() {
  PA = user32.oRIMFreeInputBuffer;
  runASM();
}
void fRIMGetDevicePreparsedData() {
  PA = user32.oRIMGetDevicePreparsedData;
  runASM();
}
void fRIMGetDevicePreparsedDataLockfree() {
  PA = user32.oRIMGetDevicePreparsedDataLockfree;
  runASM();
}
void fRIMGetDeviceProperties() {
  PA = user32.oRIMGetDeviceProperties;
  runASM();
}
void fRIMGetDevicePropertiesLockfree() {
  PA = user32.oRIMGetDevicePropertiesLockfree;
  runASM();
}
void fRIMGetPhysicalDeviceRect() {
  PA = user32.oRIMGetPhysicalDeviceRect;
  runASM();
}
void fRIMGetSourceProcessId() {
  PA = user32.oRIMGetSourceProcessId;
  runASM();
}
void fRIMObserveNextInput() {
  PA = user32.oRIMObserveNextInput;
  runASM();
}
void fRIMOnAsyncPnpWorkNotification() {
  PA = user32.oRIMOnAsyncPnpWorkNotification;
  runASM();
}
void fRIMOnPnpNotification() {
  PA = user32.oRIMOnPnpNotification;
  runASM();
}
void fRIMOnTimerNotification() {
  PA = user32.oRIMOnTimerNotification;
  runASM();
}
void fRIMQueryDevicePath() {
  PA = user32.oRIMQueryDevicePath;
  runASM();
}
void fRIMReadInput() {
  PA = user32.oRIMReadInput;
  runASM();
}
void fRIMRegisterForInput() {
  PA = user32.oRIMRegisterForInput;
  runASM();
}
void fRIMRegisterForInputEx() {
  PA = user32.oRIMRegisterForInputEx;
  runASM();
}
void fRIMRemoveInputObserver() {
  PA = user32.oRIMRemoveInputObserver;
  runASM();
}
void fRIMSetExtendedDeviceProperty() {
  PA = user32.oRIMSetExtendedDeviceProperty;
  runASM();
}
void fRIMSetTestModeStatus() {
  PA = user32.oRIMSetTestModeStatus;
  runASM();
}
void fRIMUnregisterForInput() {
  PA = user32.oRIMUnregisterForInput;
  runASM();
}
void fRIMUpdateInputObserverRegistration() {
  PA = user32.oRIMUpdateInputObserverRegistration;
  runASM();
}
void fRaiseLowerShellWindow() {
  PA = user32.oRaiseLowerShellWindow;
  runASM();
}
void fRealChildWindowFromPoint() {
  PA = user32.oRealChildWindowFromPoint;
  runASM();
}
void fRealGetWindowClass() {
  PA = user32.oRealGetWindowClass;
  runASM();
}
void fRealGetWindowClassA() {
  PA = user32.oRealGetWindowClassA;
  runASM();
}
void fRealGetWindowClassW() {
  PA = user32.oRealGetWindowClassW;
  runASM();
}
void fReasonCodeNeedsBugID() {
  PA = user32.oReasonCodeNeedsBugID;
  runASM();
}
void fReasonCodeNeedsComment() {
  PA = user32.oReasonCodeNeedsComment;
  runASM();
}
void fRecordShutdownReason() {
  PA = user32.oRecordShutdownReason;
  runASM();
}
void fRedrawWindow() {
  PA = user32.oRedrawWindow;
  runASM();
}
void fRegisterBSDRWindow() {
  PA = user32.oRegisterBSDRWindow;
  runASM();
}
void fRegisterClassA() {
  PA = user32.oRegisterClassA;
  runASM();
}
void fRegisterClassExA() {
  PA = user32.oRegisterClassExA;
  runASM();
}
void fRegisterClassExW() {
  PA = user32.oRegisterClassExW;
  runASM();
}
void fRegisterClassW() {
  PA = user32.oRegisterClassW;
  runASM();
}
void fRegisterClipboardFormatA() {
  PA = user32.oRegisterClipboardFormatA;
  runASM();
}
void fRegisterClipboardFormatW() {
  PA = user32.oRegisterClipboardFormatW;
  runASM();
}
void fRegisterCloakedNotification() {
  PA = user32.oRegisterCloakedNotification;
  runASM();
}
void fRegisterDManipHook() {
  PA = user32.oRegisterDManipHook;
  runASM();
}
void fRegisterDeviceNotificationA() {
  PA = user32.oRegisterDeviceNotificationA;
  runASM();
}
void fRegisterDeviceNotificationW() {
  PA = user32.oRegisterDeviceNotificationW;
  runASM();
}
void fRegisterErrorReportingDialog() {
  PA = user32.oRegisterErrorReportingDialog;
  runASM();
}
void fRegisterForCustomDockTargets() {
  PA = user32.oRegisterForCustomDockTargets;
  runASM();
}
void fRegisterForTooltipDismissNotification() {
  PA = user32.oRegisterForTooltipDismissNotification;
  runASM();
}
void fRegisterFrostWindow() {
  PA = user32.oRegisterFrostWindow;
  runASM();
}
void fRegisterGhostWindow() {
  PA = user32.oRegisterGhostWindow;
  runASM();
}
void fRegisterHotKey() {
  PA = user32.oRegisterHotKey;
  runASM();
}
void fRegisterLogonProcess() {
  PA = user32.oRegisterLogonProcess;
  runASM();
}
void fRegisterMessagePumpHook() {
  PA = user32.oRegisterMessagePumpHook;
  runASM();
}
void fRegisterPointerDeviceNotifications() {
  PA = user32.oRegisterPointerDeviceNotifications;
  runASM();
}
void fRegisterPointerInputTarget() {
  PA = user32.oRegisterPointerInputTarget;
  runASM();
}
void fRegisterPointerInputTargetEx() {
  PA = user32.oRegisterPointerInputTargetEx;
  runASM();
}
void fRegisterPowerSettingNotification() {
  PA = user32.oRegisterPowerSettingNotification;
  runASM();
}
void fRegisterRawInputDevices() {
  PA = user32.oRegisterRawInputDevices;
  runASM();
}
void fRegisterServicesProcess() {
  PA = user32.oRegisterServicesProcess;
  runASM();
}
void fRegisterSessionPort() {
  PA = user32.oRegisterSessionPort;
  runASM();
}
void fRegisterShellHookWindow() {
  PA = user32.oRegisterShellHookWindow;
  runASM();
}
void fRegisterSuspendResumeNotification() {
  PA = user32.oRegisterSuspendResumeNotification;
  runASM();
}
void fRegisterSystemThread() {
  PA = user32.oRegisterSystemThread;
  runASM();
}
void fRegisterTasklist() {
  PA = user32.oRegisterTasklist;
  runASM();
}
void fRegisterTouchHitTestingWindow() {
  PA = user32.oRegisterTouchHitTestingWindow;
  runASM();
}
void fRegisterTouchWindow() {
  PA = user32.oRegisterTouchWindow;
  runASM();
}
void fRegisterTouchpadCapableThread() {
  PA = user32.oRegisterTouchpadCapableThread;
  runASM();
}
void fRegisterTouchpadCapableWindow() {
  PA = user32.oRegisterTouchpadCapableWindow;
  runASM();
}
void fRegisterUserApiHook() {
  PA = user32.oRegisterUserApiHook;
  runASM();
}
void fRegisterWindowMessageA() {
  PA = user32.oRegisterWindowMessageA;
  runASM();
}
void fRegisterWindowMessageW() {
  PA = user32.oRegisterWindowMessageW;
  runASM();
}
void fReleaseCapture() {
  PA = user32.oReleaseCapture;
  runASM();
}
void fReleaseDC() {
  PA = user32.oReleaseDC;
  runASM();
}
void fReleaseDwmHitTestWaiters() {
  PA = user32.oReleaseDwmHitTestWaiters;
  runASM();
}
void fRemoveClipboardFormatListener() {
  PA = user32.oRemoveClipboardFormatListener;
  runASM();
}
void fRemoveInjectionDevice() {
  PA = user32.oRemoveInjectionDevice;
  runASM();
}
void fRemoveMenu() {
  PA = user32.oRemoveMenu;
  runASM();
}
void fRemovePropA() {
  PA = user32.oRemovePropA;
  runASM();
}
void fRemovePropW() {
  PA = user32.oRemovePropW;
  runASM();
}
void fRemoveThreadTSFEventAwareness() {
  PA = user32.oRemoveThreadTSFEventAwareness;
  runASM();
}
void fRemoveVisualIdentifier() {
  PA = user32.oRemoveVisualIdentifier;
  runASM();
}
void fReplyMessage() {
  PA = user32.oReplyMessage;
  runASM();
}
void fReportInertia() {
  PA = user32.oReportInertia;
  runASM();
}
void fResolveDesktopForWOW() {
  PA = user32.oResolveDesktopForWOW;
  runASM();
}
void fReuseDDElParam() {
  PA = user32.oReuseDDElParam;
  runASM();
}
void fScreenToClient() {
  PA = user32.oScreenToClient;
  runASM();
}
void fScrollChildren() {
  PA = user32.oScrollChildren;
  runASM();
}
void fScrollDC() {
  PA = user32.oScrollDC;
  runASM();
}
void fScrollWindow() {
  PA = user32.oScrollWindow;
  runASM();
}
void fScrollWindowEx() {
  PA = user32.oScrollWindowEx;
  runASM();
}
void fSendDlgItemMessageA() {
  PA = user32.oSendDlgItemMessageA;
  runASM();
}
void fSendDlgItemMessageW() {
  PA = user32.oSendDlgItemMessageW;
  runASM();
}
void fSendIMEMessageExA() {
  PA = user32.oSendIMEMessageExA;
  runASM();
}
void fSendIMEMessageExW() {
  PA = user32.oSendIMEMessageExW;
  runASM();
}
void fSendInput() {
  PA = user32.oSendInput;
  runASM();
}
void fSendMessageA() {
  PA = user32.oSendMessageA;
  runASM();
}
void fSendMessageCallbackA() {
  PA = user32.oSendMessageCallbackA;
  runASM();
}
void fSendMessageCallbackW() {
  PA = user32.oSendMessageCallbackW;
  runASM();
}
void fSendMessageTimeoutA() {
  PA = user32.oSendMessageTimeoutA;
  runASM();
}
void fSendMessageTimeoutW() {
  PA = user32.oSendMessageTimeoutW;
  runASM();
}
void fSendMessageW() {
  PA = user32.oSendMessageW;
  runASM();
}
void fSendNotifyMessageA() {
  PA = user32.oSendNotifyMessageA;
  runASM();
}
void fSendNotifyMessageW() {
  PA = user32.oSendNotifyMessageW;
  runASM();
}
void fSetActiveWindow() {
  PA = user32.oSetActiveWindow;
  runASM();
}
void fSetAdditionalForegroundBoostProcesses() {
  PA = user32.oSetAdditionalForegroundBoostProcesses;
  runASM();
}
void fSetCapture() {
  PA = user32.oSetCapture;
  runASM();
}
void fSetCaretBlinkTime() {
  PA = user32.oSetCaretBlinkTime;
  runASM();
}
void fSetCaretPos() {
  PA = user32.oSetCaretPos;
  runASM();
}
void fSetClassLongA() {
  PA = user32.oSetClassLongA;
  runASM();
}
void fSetClassLongPtrA() {
  PA = user32.oSetClassLongPtrA;
  runASM();
}
void fSetClassLongPtrW() {
  PA = user32.oSetClassLongPtrW;
  runASM();
}
void fSetClassLongW() {
  PA = user32.oSetClassLongW;
  runASM();
}
void fSetClassWord() {
  PA = user32.oSetClassWord;
  runASM();
}
void fSetClipboardData() {
  PA = user32.oSetClipboardData;
  runASM();
}
void fSetClipboardViewer() {
  PA = user32.oSetClipboardViewer;
  runASM();
}
void fSetCoalescableTimer() {
  PA = user32.oSetCoalescableTimer;
  runASM();
}
void fSetCoreWindow() {
  PA = user32.oSetCoreWindow;
  runASM();
}
void fSetCoveredWindowStates() {
  PA = user32.oSetCoveredWindowStates;
  runASM();
}
void fSetCursor() {
  PA = user32.oSetCursor;
  runASM();
}
void fSetCursorContents() {
  PA = user32.oSetCursorContents;
  runASM();
}
void fSetCursorPos() {
  PA = user32.oSetCursorPos;
  runASM();
}
void fSetDebugErrorLevel() {
  PA = user32.oSetDebugErrorLevel;
  runASM();
}
void fSetDeskWallpaper() {
  PA = user32.oSetDeskWallpaper;
  runASM();
}
void fSetDesktopColorTransform() {
  PA = user32.oSetDesktopColorTransform;
  runASM();
}
void fSetDialogControlDpiChangeBehavior() {
  PA = user32.oSetDialogControlDpiChangeBehavior;
  runASM();
}
void fSetDialogDpiChangeBehavior() {
  PA = user32.oSetDialogDpiChangeBehavior;
  runASM();
}
void fSetDisplayAutoRotationPreferences() {
  PA = user32.oSetDisplayAutoRotationPreferences;
  runASM();
}
void fSetDisplayConfig() {
  PA = user32.oSetDisplayConfig;
  runASM();
}
void fSetDlgItemInt() {
  PA = user32.oSetDlgItemInt;
  runASM();
}
void fSetDlgItemTextA() {
  PA = user32.oSetDlgItemTextA;
  runASM();
}
void fSetDlgItemTextW() {
  PA = user32.oSetDlgItemTextW;
  runASM();
}
void fSetDoubleClickTime() {
  PA = user32.oSetDoubleClickTime;
  runASM();
}
void fSetFeatureReportResponse() {
  PA = user32.oSetFeatureReportResponse;
  runASM();
}
void fSetFocus() {
  PA = user32.oSetFocus;
  runASM();
}
void fSetForegroundRedirectionForActivationObject() {
  PA = user32.oSetForegroundRedirectionForActivationObject;
  runASM();
}
void fSetForegroundWindow() {
  PA = user32.oSetForegroundWindow;
  runASM();
}
void fSetFullscreenMagnifierOffsetsDWMUpdated() {
  PA = user32.oSetFullscreenMagnifierOffsetsDWMUpdated;
  runASM();
}
void fSetGestureConfig() {
  PA = user32.oSetGestureConfig;
  runASM();
}
void fSetInternalWindowPos() {
  PA = user32.oSetInternalWindowPos;
  runASM();
}
void fSetKeyboardState() {
  PA = user32.oSetKeyboardState;
  runASM();
}
void fSetLastErrorEx() {
  PA = user32.oSetLastErrorEx;
  runASM();
}
void fSetLayeredWindowAttributes() {
  PA = user32.oSetLayeredWindowAttributes;
  runASM();
}
void fSetMagnificationDesktopColorEffect() {
  PA = user32.oSetMagnificationDesktopColorEffect;
  runASM();
}
void fSetMagnificationDesktopMagnification() {
  PA = user32.oSetMagnificationDesktopMagnification;
  runASM();
}
void fSetMagnificationDesktopMagnifierOffsetsDWMUpdated() {
  PA = user32.oSetMagnificationDesktopMagnifierOffsetsDWMUpdated;
  runASM();
}
void fSetMagnificationDesktopSamplingMode() {
  PA = user32.oSetMagnificationDesktopSamplingMode;
  runASM();
}
void fSetMagnificationLensCtxInformation() {
  PA = user32.oSetMagnificationLensCtxInformation;
  runASM();
}
void fSetMaxTouchpadSensitivity() {
  PA = user32.oSetMaxTouchpadSensitivity;
  runASM();
}
void fSetMenu() {
  PA = user32.oSetMenu;
  runASM();
}
void fSetMenuContextHelpId() {
  PA = user32.oSetMenuContextHelpId;
  runASM();
}
void fSetMenuDefaultItem() {
  PA = user32.oSetMenuDefaultItem;
  runASM();
}
void fSetMenuInfo() {
  PA = user32.oSetMenuInfo;
  runASM();
}
void fSetMenuItemBitmaps() {
  PA = user32.oSetMenuItemBitmaps;
  runASM();
}
void fSetMenuItemInfoA() {
  PA = user32.oSetMenuItemInfoA;
  runASM();
}
void fSetMenuItemInfoW() {
  PA = user32.oSetMenuItemInfoW;
  runASM();
}
void fSetMessageExtraInfo() {
  PA = user32.oSetMessageExtraInfo;
  runASM();
}
void fSetMessageQueue() {
  PA = user32.oSetMessageQueue;
  runASM();
}
void fSetMirrorRendering() {
  PA = user32.oSetMirrorRendering;
  runASM();
}
void fSetParent() {
  PA = user32.oSetParent;
  runASM();
}
void fSetPhysicalCursorPos() {
  PA = user32.oSetPhysicalCursorPos;
  runASM();
}
void fSetPointerDeviceInputSpace() {
  PA = user32.oSetPointerDeviceInputSpace;
  runASM();
}
void fSetProcessDPIAware() {
  PA = user32.oSetProcessDPIAware;
  runASM();
}
void fSetProcessDefaultLayout() {
  PA = user32.oSetProcessDefaultLayout;
  runASM();
}
void fSetProcessDpiAwarenessContext() {
  PA = user32.oSetProcessDpiAwarenessContext;
  runASM();
}
void fSetProcessDpiAwarenessInternal() {
  PA = user32.oSetProcessDpiAwarenessInternal;
  runASM();
}
void fSetProcessLaunchForegroundPolicy() {
  PA = user32.oSetProcessLaunchForegroundPolicy;
  runASM();
}
void fSetProcessRestrictionExemption() {
  PA = user32.oSetProcessRestrictionExemption;
  runASM();
}
void fSetProcessWindowStation() {
  PA = user32.oSetProcessWindowStation;
  runASM();
}
void fSetProgmanWindow() {
  PA = user32.oSetProgmanWindow;
  runASM();
}
void fSetPropA() {
  PA = user32.oSetPropA;
  runASM();
}
void fSetPropW() {
  PA = user32.oSetPropW;
  runASM();
}
void fSetRect() {
  PA = user32.oSetRect;
  runASM();
}
void fSetRectEmpty() {
  PA = user32.oSetRectEmpty;
  runASM();
}
void fSetScrollInfo() {
  PA = user32.oSetScrollInfo;
  runASM();
}
void fSetScrollPos() {
  PA = user32.oSetScrollPos;
  runASM();
}
void fSetScrollRange() {
  PA = user32.oSetScrollRange;
  runASM();
}
void fSetShellChangeNotifyWindow() {
  PA = user32.oSetShellChangeNotifyWindow;
  runASM();
}
void fSetShellWindow() {
  PA = user32.oSetShellWindow;
  runASM();
}
void fSetShellWindowEx() {
  PA = user32.oSetShellWindowEx;
  runASM();
}
void fSetSysColors() {
  PA = user32.oSetSysColors;
  runASM();
}
void fSetSysColorsTemp() {
  PA = user32.oSetSysColorsTemp;
  runASM();
}
void fSetSystemCursor() {
  PA = user32.oSetSystemCursor;
  runASM();
}
void fSetSystemMenu() {
  PA = user32.oSetSystemMenu;
  runASM();
}
void fSetTaskmanWindow() {
  PA = user32.oSetTaskmanWindow;
  runASM();
}
void fSetThreadCursorCreationScaling() {
  PA = user32.oSetThreadCursorCreationScaling;
  runASM();
}
void fSetThreadDesktop() {
  PA = user32.oSetThreadDesktop;
  runASM();
}
void fSetThreadDpiAwarenessContext() {
  PA = user32.oSetThreadDpiAwarenessContext;
  runASM();
}
void fSetThreadDpiHostingBehavior() {
  PA = user32.oSetThreadDpiHostingBehavior;
  runASM();
}
void fSetThreadInputBlocked() {
  PA = user32.oSetThreadInputBlocked;
  runASM();
}
void fSetTimer() {
  PA = user32.oSetTimer;
  runASM();
}
void fSetUserObjectCapability() {
  PA = user32.oSetUserObjectCapability;
  runASM();
}
void fSetUserObjectInformationA() {
  PA = user32.oSetUserObjectInformationA;
  runASM();
}
void fSetUserObjectInformationW() {
  PA = user32.oSetUserObjectInformationW;
  runASM();
}
void fSetUserObjectSecurity() {
  PA = user32.oSetUserObjectSecurity;
  runASM();
}
void fSetWinEventHook() {
  PA = user32.oSetWinEventHook;
  runASM();
}
void fSetWindowBand() {
  PA = user32.oSetWindowBand;
  runASM();
}
void fSetWindowCompositionAttribute() {
  PA = user32.oSetWindowCompositionAttribute;
  runASM();
}
void fSetWindowCompositionTransition() {
  PA = user32.oSetWindowCompositionTransition;
  runASM();
}
void fSetWindowContextHelpId() {
  PA = user32.oSetWindowContextHelpId;
  runASM();
}
void fSetWindowDisplayAffinity() {
  PA = user32.oSetWindowDisplayAffinity;
  runASM();
}
void fSetWindowFeedbackSetting() {
  PA = user32.oSetWindowFeedbackSetting;
  runASM();
}
void fSetWindowLongA() {
  PA = user32.oSetWindowLongA;
  runASM();
}
void fSetWindowLongPtrA() {
  PA = user32.oSetWindowLongPtrA;
  runASM();
}
void fSetWindowLongPtrW() {
  PA = user32.oSetWindowLongPtrW;
  runASM();
}
void fSetWindowLongW() {
  PA = user32.oSetWindowLongW;
  runASM();
}
void fSetWindowMessageCapability() {
  PA = user32.oSetWindowMessageCapability;
  runASM();
}
void fSetWindowPlacement() {
  PA = user32.oSetWindowPlacement;
  runASM();
}
void fSetWindowPos() {
  PA = user32.oSetWindowPos;
  runASM();
}
void fSetWindowRgn() {
  PA = user32.oSetWindowRgn;
  runASM();
}
void fSetWindowRgnEx() {
  PA = user32.oSetWindowRgnEx;
  runASM();
}
void fSetWindowStationUser() {
  PA = user32.oSetWindowStationUser;
  runASM();
}
void fSetWindowTextA() {
  PA = user32.oSetWindowTextA;
  runASM();
}
void fSetWindowTextW() {
  PA = user32.oSetWindowTextW;
  runASM();
}
void fSetWindowWord() {
  PA = user32.oSetWindowWord;
  runASM();
}
void fSetWindowsHookA() {
  PA = user32.oSetWindowsHookA;
  runASM();
}
void fSetWindowsHookExA() {
  PA = user32.oSetWindowsHookExA;
  runASM();
}
void fSetWindowsHookExAW() {
  PA = user32.oSetWindowsHookExAW;
  runASM();
}
void fSetWindowsHookExW() {
  PA = user32.oSetWindowsHookExW;
  runASM();
}
void fSetWindowsHookW() {
  PA = user32.oSetWindowsHookW;
  runASM();
}
void fShellForegroundBoostProcess() {
  PA = user32.oShellForegroundBoostProcess;
  runASM();
}
void fShellHandwritingDelegateInput() {
  PA = user32.oShellHandwritingDelegateInput;
  runASM();
}
void fShellHandwritingHandleDelegatedInput() {
  PA = user32.oShellHandwritingHandleDelegatedInput;
  runASM();
}
void fShellHandwritingUndelegateInput() {
  PA = user32.oShellHandwritingUndelegateInput;
  runASM();
}
void fShellMigrateWindow() {
  PA = user32.oShellMigrateWindow;
  runASM();
}
void fShellRegisterHotKey() {
  PA = user32.oShellRegisterHotKey;
  runASM();
}
void fShellSetWindowPos() {
  PA = user32.oShellSetWindowPos;
  runASM();
}
void fShowCaret() {
  PA = user32.oShowCaret;
  runASM();
}
void fShowCursor() {
  PA = user32.oShowCursor;
  runASM();
}
void fShowOwnedPopups() {
  PA = user32.oShowOwnedPopups;
  runASM();
}
void fShowScrollBar() {
  PA = user32.oShowScrollBar;
  runASM();
}
void fShowStartGlass() {
  PA = user32.oShowStartGlass;
  runASM();
}
void fShowSystemCursor() {
  PA = user32.oShowSystemCursor;
  runASM();
}
void fShowWindow() {
  PA = user32.oShowWindow;
  runASM();
}
void fShowWindowAsync() {
  PA = user32.oShowWindowAsync;
  runASM();
}
void fShutdownBlockReasonCreate() {
  PA = user32.oShutdownBlockReasonCreate;
  runASM();
}
void fShutdownBlockReasonDestroy() {
  PA = user32.oShutdownBlockReasonDestroy;
  runASM();
}
void fShutdownBlockReasonQuery() {
  PA = user32.oShutdownBlockReasonQuery;
  runASM();
}
void fSignalRedirectionStartComplete() {
  PA = user32.oSignalRedirectionStartComplete;
  runASM();
}
void fSkipPointerFrameMessages() {
  PA = user32.oSkipPointerFrameMessages;
  runASM();
}
void fSoftModalMessageBox() {
  PA = user32.oSoftModalMessageBox;
  runASM();
}
void fSoundSentry() {
  PA = user32.oSoundSentry;
  runASM();
}
void fSubtractRect() {
  PA = user32.oSubtractRect;
  runASM();
}
void fSuppressWindowDisplayChange() {
  PA = user32.oSuppressWindowDisplayChange;
  runASM();
}
void fSwapMouseButton() {
  PA = user32.oSwapMouseButton;
  runASM();
}
void fSwitchDesktop() {
  PA = user32.oSwitchDesktop;
  runASM();
}
void fSwitchDesktopWithFade() {
  PA = user32.oSwitchDesktopWithFade;
  runASM();
}
void fSwitchToThisWindow() {
  PA = user32.oSwitchToThisWindow;
  runASM();
}
void fSystemParametersInfoA() {
  PA = user32.oSystemParametersInfoA;
  runASM();
}
void fSystemParametersInfoForDpi() {
  PA = user32.oSystemParametersInfoForDpi;
  runASM();
}
void fSystemParametersInfoW() {
  PA = user32.oSystemParametersInfoW;
  runASM();
}
void fTabbedTextOutA() {
  PA = user32.oTabbedTextOutA;
  runASM();
}
void fTabbedTextOutW() {
  PA = user32.oTabbedTextOutW;
  runASM();
}
void fTileChildWindows() {
  PA = user32.oTileChildWindows;
  runASM();
}
void fTileWindows() {
  PA = user32.oTileWindows;
  runASM();
}
void fToAscii() {
  PA = user32.oToAscii;
  runASM();
}
void fToAsciiEx() {
  PA = user32.oToAsciiEx;
  runASM();
}
void fToUnicode() {
  PA = user32.oToUnicode;
  runASM();
}
void fToUnicodeEx() {
  PA = user32.oToUnicodeEx;
  runASM();
}
void fTrackMouseEvent() {
  PA = user32.oTrackMouseEvent;
  runASM();
}
void fTrackPopupMenu() {
  PA = user32.oTrackPopupMenu;
  runASM();
}
void fTrackPopupMenuEx() {
  PA = user32.oTrackPopupMenuEx;
  runASM();
}
void fTranslateAccelerator() {
  PA = user32.oTranslateAccelerator;
  runASM();
}
void fTranslateAcceleratorA() {
  PA = user32.oTranslateAcceleratorA;
  runASM();
}
void fTranslateAcceleratorW() {
  PA = user32.oTranslateAcceleratorW;
  runASM();
}
void fTranslateMDISysAccel() {
  PA = user32.oTranslateMDISysAccel;
  runASM();
}
void fTranslateMessage() {
  PA = user32.oTranslateMessage;
  runASM();
}
void fTranslateMessageEx() {
  PA = user32.oTranslateMessageEx;
  runASM();
}
void fUndelegateInput() {
  PA = user32.oUndelegateInput;
  runASM();
}
void fUnhookWinEvent() {
  PA = user32.oUnhookWinEvent;
  runASM();
}
void fUnhookWindowsHook() {
  PA = user32.oUnhookWindowsHook;
  runASM();
}
void fUnhookWindowsHookEx() {
  PA = user32.oUnhookWindowsHookEx;
  runASM();
}
void fUnionRect() {
  PA = user32.oUnionRect;
  runASM();
}
void fUnloadKeyboardLayout() {
  PA = user32.oUnloadKeyboardLayout;
  runASM();
}
void fUnlockWindowStation() {
  PA = user32.oUnlockWindowStation;
  runASM();
}
void fUnpackDDElParam() {
  PA = user32.oUnpackDDElParam;
  runASM();
}
void fUnregisterClassA() {
  PA = user32.oUnregisterClassA;
  runASM();
}
void fUnregisterClassW() {
  PA = user32.oUnregisterClassW;
  runASM();
}
void fUnregisterDeviceNotification() {
  PA = user32.oUnregisterDeviceNotification;
  runASM();
}
void fUnregisterHotKey() {
  PA = user32.oUnregisterHotKey;
  runASM();
}
void fUnregisterMessagePumpHook() {
  PA = user32.oUnregisterMessagePumpHook;
  runASM();
}
void fUnregisterPointerInputTarget() {
  PA = user32.oUnregisterPointerInputTarget;
  runASM();
}
void fUnregisterPointerInputTargetEx() {
  PA = user32.oUnregisterPointerInputTargetEx;
  runASM();
}
void fUnregisterPowerSettingNotification() {
  PA = user32.oUnregisterPowerSettingNotification;
  runASM();
}
void fUnregisterSessionPort() {
  PA = user32.oUnregisterSessionPort;
  runASM();
}
void fUnregisterSuspendResumeNotification() {
  PA = user32.oUnregisterSuspendResumeNotification;
  runASM();
}
void fUnregisterTouchWindow() {
  PA = user32.oUnregisterTouchWindow;
  runASM();
}
void fUnregisterUserApiHook() {
  PA = user32.oUnregisterUserApiHook;
  runASM();
}
void fUpdateDefaultDesktopThumbnail() {
  PA = user32.oUpdateDefaultDesktopThumbnail;
  runASM();
}
void fUpdateLayeredWindow() {
  PA = user32.oUpdateLayeredWindow;
  runASM();
}
void fUpdateLayeredWindowIndirect() {
  PA = user32.oUpdateLayeredWindowIndirect;
  runASM();
}
void fUpdatePerUserSystemParameters() {
  PA = user32.oUpdatePerUserSystemParameters;
  runASM();
}
void fUpdateWindow() {
  PA = user32.oUpdateWindow;
  runASM();
}
void fUpdateWindowInputSinkHints() {
  PA = user32.oUpdateWindowInputSinkHints;
  runASM();
}
void fUser32InitializeImmEntryTable() {
  PA = user32.oUser32InitializeImmEntryTable;
  runASM();
}
void fUserClientDllInitialize() {
  PA = user32.oUserClientDllInitialize;
  runASM();
}
void fUserHandleGrantAccess() {
  PA = user32.oUserHandleGrantAccess;
  runASM();
}
void fUserLpkPSMTextOut() {
  PA = user32.oUserLpkPSMTextOut;
  runASM();
}
void fUserLpkTabbedTextOut() {
  PA = user32.oUserLpkTabbedTextOut;
  runASM();
}
void fUserRealizePalette() {
  PA = user32.oUserRealizePalette;
  runASM();
}
void fUserRegisterWowHandlers() {
  PA = user32.oUserRegisterWowHandlers;
  runASM();
}
void fVRipOutput() {
  PA = user32.oVRipOutput;
  runASM();
}
void fVTagOutput() {
  PA = user32.oVTagOutput;
  runASM();
}
void fValidateRect() {
  PA = user32.oValidateRect;
  runASM();
}
void fValidateRgn() {
  PA = user32.oValidateRgn;
  runASM();
}
void fVkKeyScanA() {
  PA = user32.oVkKeyScanA;
  runASM();
}
void fVkKeyScanExA() {
  PA = user32.oVkKeyScanExA;
  runASM();
}
void fVkKeyScanExW() {
  PA = user32.oVkKeyScanExW;
  runASM();
}
void fVkKeyScanW() {
  PA = user32.oVkKeyScanW;
  runASM();
}
void fWCSToMBEx() {
  PA = user32.oWCSToMBEx;
  runASM();
}
void fWINNLSEnableIME() {
  PA = user32.oWINNLSEnableIME;
  runASM();
}
void fWINNLSGetEnableStatus() {
  PA = user32.oWINNLSGetEnableStatus;
  runASM();
}
void fWINNLSGetIMEHotkey() {
  PA = user32.oWINNLSGetIMEHotkey;
  runASM();
}
void fWaitForInputIdle() {
  PA = user32.oWaitForInputIdle;
  runASM();
}
void fWaitForRedirectionStartComplete() {
  PA = user32.oWaitForRedirectionStartComplete;
  runASM();
}
void fWaitMessage() {
  PA = user32.oWaitMessage;
  runASM();
}
void fWinHelpA() {
  PA = user32.oWinHelpA;
  runASM();
}
void fWinHelpW() {
  PA = user32.oWinHelpW;
  runASM();
}
void fWindowFromDC() {
  PA = user32.oWindowFromDC;
  runASM();
}
void fWindowFromPhysicalPoint() {
  PA = user32.oWindowFromPhysicalPoint;
  runASM();
}
void fWindowFromPoint() {
  PA = user32.oWindowFromPoint;
  runASM();
}
void f_UserTestTokenForInteractive() {
  PA = user32.o_UserTestTokenForInteractive;
  runASM();
}
void fgSharedInfo() {
  PA = user32.ogSharedInfo;
  runASM();
}
void fgapfnScSendMessage() {
  PA = user32.ogapfnScSendMessage;
  runASM();
}
void fkeybd_event() {
  PA = user32.okeybd_event;
  runASM();
}
void fmouse_event() {
  PA = user32.omouse_event;
  runASM();
}
void fwsprintfA() {
  PA = user32.owsprintfA;
  runASM();
}
void fwsprintfW() {
  PA = user32.owsprintfW;
  runASM();
}
void fwvsprintfA() {
  PA = user32.owvsprintfA;
  runASM();
}
void fwvsprintfW() {
  PA = user32.owvsprintfW;
  runASM();
}
}

void setupFunctions() {
  user32.oActivateKeyboardLayout =
      GetProcAddress(user32.dll, "ActivateKeyboardLayout");
  user32.oAddClipboardFormatListener =
      GetProcAddress(user32.dll, "AddClipboardFormatListener");
  user32.oAddVisualIdentifier =
      GetProcAddress(user32.dll, "AddVisualIdentifier");
  user32.oAdjustWindowRect = GetProcAddress(user32.dll, "AdjustWindowRect");
  user32.oAdjustWindowRectEx = GetProcAddress(user32.dll, "AdjustWindowRectEx");
  user32.oAdjustWindowRectExForDpi =
      GetProcAddress(user32.dll, "AdjustWindowRectExForDpi");
  user32.oAlignRects = GetProcAddress(user32.dll, "AlignRects");
  user32.oAllowForegroundActivation =
      GetProcAddress(user32.dll, "AllowForegroundActivation");
  user32.oAllowSetForegroundWindow =
      GetProcAddress(user32.dll, "AllowSetForegroundWindow");
  user32.oAnimateWindow = GetProcAddress(user32.dll, "AnimateWindow");
  user32.oAnyPopup = GetProcAddress(user32.dll, "AnyPopup");
  user32.oAppendMenuA = GetProcAddress(user32.dll, "AppendMenuA");
  user32.oAppendMenuW = GetProcAddress(user32.dll, "AppendMenuW");
  user32.oApplyWindowAction = GetProcAddress(user32.dll, "ApplyWindowAction");
  user32.oAreDpiAwarenessContextsEqual =
      GetProcAddress(user32.dll, "AreDpiAwarenessContextsEqual");
  user32.oArrangeIconicWindows =
      GetProcAddress(user32.dll, "ArrangeIconicWindows");
  user32.oAttachThreadInput = GetProcAddress(user32.dll, "AttachThreadInput");
  user32.oBeginDeferWindowPos =
      GetProcAddress(user32.dll, "BeginDeferWindowPos");
  user32.oBeginPaint = GetProcAddress(user32.dll, "BeginPaint");
  user32.oBlockInput = GetProcAddress(user32.dll, "BlockInput");
  user32.oBringWindowToTop = GetProcAddress(user32.dll, "BringWindowToTop");
  user32.oBroadcastSystemMessage =
      GetProcAddress(user32.dll, "BroadcastSystemMessage");
  user32.oBroadcastSystemMessageA =
      GetProcAddress(user32.dll, "BroadcastSystemMessageA");
  user32.oBroadcastSystemMessageExA =
      GetProcAddress(user32.dll, "BroadcastSystemMessageExA");
  user32.oBroadcastSystemMessageExW =
      GetProcAddress(user32.dll, "BroadcastSystemMessageExW");
  user32.oBroadcastSystemMessageW =
      GetProcAddress(user32.dll, "BroadcastSystemMessageW");
  user32.oBuildReasonArray = GetProcAddress(user32.dll, "BuildReasonArray");
  user32.oCalcMenuBar = GetProcAddress(user32.dll, "CalcMenuBar");
  user32.oCalculatePopupWindowPosition =
      GetProcAddress(user32.dll, "CalculatePopupWindowPosition");
  user32.oCallMsgFilter = GetProcAddress(user32.dll, "CallMsgFilter");
  user32.oCallMsgFilterA = GetProcAddress(user32.dll, "CallMsgFilterA");
  user32.oCallMsgFilterW = GetProcAddress(user32.dll, "CallMsgFilterW");
  user32.oCallNextHookEx = GetProcAddress(user32.dll, "CallNextHookEx");
  user32.oCallWindowProcA = GetProcAddress(user32.dll, "CallWindowProcA");
  user32.oCallWindowProcW = GetProcAddress(user32.dll, "CallWindowProcW");
  user32.oCancelShutdown = GetProcAddress(user32.dll, "CancelShutdown");
  user32.oCascadeChildWindows =
      GetProcAddress(user32.dll, "CascadeChildWindows");
  user32.oCascadeWindows = GetProcAddress(user32.dll, "CascadeWindows");
  user32.oChangeClipboardChain =
      GetProcAddress(user32.dll, "ChangeClipboardChain");
  user32.oChangeDisplaySettingsA =
      GetProcAddress(user32.dll, "ChangeDisplaySettingsA");
  user32.oChangeDisplaySettingsExA =
      GetProcAddress(user32.dll, "ChangeDisplaySettingsExA");
  user32.oChangeDisplaySettingsExW =
      GetProcAddress(user32.dll, "ChangeDisplaySettingsExW");
  user32.oChangeDisplaySettingsW =
      GetProcAddress(user32.dll, "ChangeDisplaySettingsW");
  user32.oChangeMenuA = GetProcAddress(user32.dll, "ChangeMenuA");
  user32.oChangeMenuW = GetProcAddress(user32.dll, "ChangeMenuW");
  user32.oChangeWindowMessageFilter =
      GetProcAddress(user32.dll, "ChangeWindowMessageFilter");
  user32.oChangeWindowMessageFilterEx =
      GetProcAddress(user32.dll, "ChangeWindowMessageFilterEx");
  user32.oCharLowerA = GetProcAddress(user32.dll, "CharLowerA");
  user32.oCharLowerBuffA = GetProcAddress(user32.dll, "CharLowerBuffA");
  user32.oCharLowerBuffW = GetProcAddress(user32.dll, "CharLowerBuffW");
  user32.oCharLowerW = GetProcAddress(user32.dll, "CharLowerW");
  user32.oCharNextA = GetProcAddress(user32.dll, "CharNextA");
  user32.oCharNextExA = GetProcAddress(user32.dll, "CharNextExA");
  user32.oCharNextW = GetProcAddress(user32.dll, "CharNextW");
  user32.oCharPrevA = GetProcAddress(user32.dll, "CharPrevA");
  user32.oCharPrevExA = GetProcAddress(user32.dll, "CharPrevExA");
  user32.oCharPrevW = GetProcAddress(user32.dll, "CharPrevW");
  user32.oCharToOemA = GetProcAddress(user32.dll, "CharToOemA");
  user32.oCharToOemBuffA = GetProcAddress(user32.dll, "CharToOemBuffA");
  user32.oCharToOemBuffW = GetProcAddress(user32.dll, "CharToOemBuffW");
  user32.oCharToOemW = GetProcAddress(user32.dll, "CharToOemW");
  user32.oCharUpperA = GetProcAddress(user32.dll, "CharUpperA");
  user32.oCharUpperBuffA = GetProcAddress(user32.dll, "CharUpperBuffA");
  user32.oCharUpperBuffW = GetProcAddress(user32.dll, "CharUpperBuffW");
  user32.oCharUpperW = GetProcAddress(user32.dll, "CharUpperW");
  user32.oCheckBannedOneCoreTransformApi =
      GetProcAddress(user32.dll, "CheckBannedOneCoreTransformApi");
  user32.oCheckDBCSEnabledExt =
      GetProcAddress(user32.dll, "CheckDBCSEnabledExt");
  user32.oCheckDlgButton = GetProcAddress(user32.dll, "CheckDlgButton");
  user32.oCheckMenuItem = GetProcAddress(user32.dll, "CheckMenuItem");
  user32.oCheckMenuRadioItem = GetProcAddress(user32.dll, "CheckMenuRadioItem");
  user32.oCheckProcessForClipboardAccess =
      GetProcAddress(user32.dll, "CheckProcessForClipboardAccess");
  user32.oCheckProcessSession =
      GetProcAddress(user32.dll, "CheckProcessSession");
  user32.oCheckRadioButton = GetProcAddress(user32.dll, "CheckRadioButton");
  user32.oCheckWindowThreadDesktop =
      GetProcAddress(user32.dll, "CheckWindowThreadDesktop");
  user32.oChildWindowFromPoint =
      GetProcAddress(user32.dll, "ChildWindowFromPoint");
  user32.oChildWindowFromPointEx =
      GetProcAddress(user32.dll, "ChildWindowFromPointEx");
  user32.oCliImmSetHotKey = GetProcAddress(user32.dll, "CliImmSetHotKey");
  user32.oClientThreadSetup = GetProcAddress(user32.dll, "ClientThreadSetup");
  user32.oClientToScreen = GetProcAddress(user32.dll, "ClientToScreen");
  user32.oClipCursor = GetProcAddress(user32.dll, "ClipCursor");
  user32.oCloseClipboard = GetProcAddress(user32.dll, "CloseClipboard");
  user32.oCloseDesktop = GetProcAddress(user32.dll, "CloseDesktop");
  user32.oCloseGestureInfoHandle =
      GetProcAddress(user32.dll, "CloseGestureInfoHandle");
  user32.oCloseTouchInputHandle =
      GetProcAddress(user32.dll, "CloseTouchInputHandle");
  user32.oCloseWindow = GetProcAddress(user32.dll, "CloseWindow");
  user32.oCloseWindowStation = GetProcAddress(user32.dll, "CloseWindowStation");
  user32.oConsoleControl = GetProcAddress(user32.dll, "ConsoleControl");
  user32.oControlMagnification =
      GetProcAddress(user32.dll, "ControlMagnification");
  user32.oConvertToInterceptWindow =
      GetProcAddress(user32.dll, "ConvertToInterceptWindow");
  user32.oCopyAcceleratorTableA =
      GetProcAddress(user32.dll, "CopyAcceleratorTableA");
  user32.oCopyAcceleratorTableW =
      GetProcAddress(user32.dll, "CopyAcceleratorTableW");
  user32.oCopyIcon = GetProcAddress(user32.dll, "CopyIcon");
  user32.oCopyImage = GetProcAddress(user32.dll, "CopyImage");
  user32.oCopyRect = GetProcAddress(user32.dll, "CopyRect");
  user32.oCountClipboardFormats =
      GetProcAddress(user32.dll, "CountClipboardFormats");
  user32.oCreateAcceleratorTableA =
      GetProcAddress(user32.dll, "CreateAcceleratorTableA");
  user32.oCreateAcceleratorTableW =
      GetProcAddress(user32.dll, "CreateAcceleratorTableW");
  user32.oCreateCaret = GetProcAddress(user32.dll, "CreateCaret");
  user32.oCreateCursor = GetProcAddress(user32.dll, "CreateCursor");
  user32.oCreateDCompositionHwndTarget =
      GetProcAddress(user32.dll, "CreateDCompositionHwndTarget");
  user32.oCreateDesktopA = GetProcAddress(user32.dll, "CreateDesktopA");
  user32.oCreateDesktopExA = GetProcAddress(user32.dll, "CreateDesktopExA");
  user32.oCreateDesktopExW = GetProcAddress(user32.dll, "CreateDesktopExW");
  user32.oCreateDesktopW = GetProcAddress(user32.dll, "CreateDesktopW");
  user32.oCreateDialogIndirectParamA =
      GetProcAddress(user32.dll, "CreateDialogIndirectParamA");
  user32.oCreateDialogIndirectParamAorW =
      GetProcAddress(user32.dll, "CreateDialogIndirectParamAorW");
  user32.oCreateDialogIndirectParamW =
      GetProcAddress(user32.dll, "CreateDialogIndirectParamW");
  user32.oCreateDialogParamA = GetProcAddress(user32.dll, "CreateDialogParamA");
  user32.oCreateDialogParamW = GetProcAddress(user32.dll, "CreateDialogParamW");
  user32.oCreateIcon = GetProcAddress(user32.dll, "CreateIcon");
  user32.oCreateIconFromResource =
      GetProcAddress(user32.dll, "CreateIconFromResource");
  user32.oCreateIconFromResourceEx =
      GetProcAddress(user32.dll, "CreateIconFromResourceEx");
  user32.oCreateIconIndirect = GetProcAddress(user32.dll, "CreateIconIndirect");
  user32.oCreateMDIWindowA = GetProcAddress(user32.dll, "CreateMDIWindowA");
  user32.oCreateMDIWindowW = GetProcAddress(user32.dll, "CreateMDIWindowW");
  user32.oCreateMenu = GetProcAddress(user32.dll, "CreateMenu");
  user32.oCreatePopupMenu = GetProcAddress(user32.dll, "CreatePopupMenu");
  user32.oCreateSyntheticPointerDevice =
      GetProcAddress(user32.dll, "CreateSyntheticPointerDevice");
  user32.oCreateSyntheticPointerDevice2 =
      GetProcAddress(user32.dll, "CreateSyntheticPointerDevice2");
  user32.oCreateSystemThreads =
      GetProcAddress(user32.dll, "CreateSystemThreads");
  user32.oCreateWindowExA = GetProcAddress(user32.dll, "CreateWindowExA");
  user32.oCreateWindowExW = GetProcAddress(user32.dll, "CreateWindowExW");
  user32.oCreateWindowInBand = GetProcAddress(user32.dll, "CreateWindowInBand");
  user32.oCreateWindowInBandEx =
      GetProcAddress(user32.dll, "CreateWindowInBandEx");
  user32.oCreateWindowIndirect =
      GetProcAddress(user32.dll, "CreateWindowIndirect");
  user32.oCreateWindowStationA =
      GetProcAddress(user32.dll, "CreateWindowStationA");
  user32.oCreateWindowStationW =
      GetProcAddress(user32.dll, "CreateWindowStationW");
  user32.oCsrBroadcastSystemMessageExW =
      GetProcAddress(user32.dll, "CsrBroadcastSystemMessageExW");
  user32.oCtxInitUser32 = GetProcAddress(user32.dll, "CtxInitUser32");
  user32.oDdeAbandonTransaction =
      GetProcAddress(user32.dll, "DdeAbandonTransaction");
  user32.oDdeAccessData = GetProcAddress(user32.dll, "DdeAccessData");
  user32.oDdeAddData = GetProcAddress(user32.dll, "DdeAddData");
  user32.oDdeClientTransaction =
      GetProcAddress(user32.dll, "DdeClientTransaction");
  user32.oDdeCmpStringHandles =
      GetProcAddress(user32.dll, "DdeCmpStringHandles");
  user32.oDdeConnect = GetProcAddress(user32.dll, "DdeConnect");
  user32.oDdeConnectList = GetProcAddress(user32.dll, "DdeConnectList");
  user32.oDdeCreateDataHandle =
      GetProcAddress(user32.dll, "DdeCreateDataHandle");
  user32.oDdeCreateStringHandleA =
      GetProcAddress(user32.dll, "DdeCreateStringHandleA");
  user32.oDdeCreateStringHandleW =
      GetProcAddress(user32.dll, "DdeCreateStringHandleW");
  user32.oDdeDisconnect = GetProcAddress(user32.dll, "DdeDisconnect");
  user32.oDdeDisconnectList = GetProcAddress(user32.dll, "DdeDisconnectList");
  user32.oDdeEnableCallback = GetProcAddress(user32.dll, "DdeEnableCallback");
  user32.oDdeFreeDataHandle = GetProcAddress(user32.dll, "DdeFreeDataHandle");
  user32.oDdeFreeStringHandle =
      GetProcAddress(user32.dll, "DdeFreeStringHandle");
  user32.oDdeGetData = GetProcAddress(user32.dll, "DdeGetData");
  user32.oDdeGetLastError = GetProcAddress(user32.dll, "DdeGetLastError");
  user32.oDdeGetQualityOfService =
      GetProcAddress(user32.dll, "DdeGetQualityOfService");
  user32.oDdeImpersonateClient =
      GetProcAddress(user32.dll, "DdeImpersonateClient");
  user32.oDdeInitializeA = GetProcAddress(user32.dll, "DdeInitializeA");
  user32.oDdeInitializeW = GetProcAddress(user32.dll, "DdeInitializeW");
  user32.oDdeKeepStringHandle =
      GetProcAddress(user32.dll, "DdeKeepStringHandle");
  user32.oDdeNameService = GetProcAddress(user32.dll, "DdeNameService");
  user32.oDdePostAdvise = GetProcAddress(user32.dll, "DdePostAdvise");
  user32.oDdeQueryConvInfo = GetProcAddress(user32.dll, "DdeQueryConvInfo");
  user32.oDdeQueryNextServer = GetProcAddress(user32.dll, "DdeQueryNextServer");
  user32.oDdeQueryStringA = GetProcAddress(user32.dll, "DdeQueryStringA");
  user32.oDdeQueryStringW = GetProcAddress(user32.dll, "DdeQueryStringW");
  user32.oDdeReconnect = GetProcAddress(user32.dll, "DdeReconnect");
  user32.oDdeSetQualityOfService =
      GetProcAddress(user32.dll, "DdeSetQualityOfService");
  user32.oDdeSetUserHandle = GetProcAddress(user32.dll, "DdeSetUserHandle");
  user32.oDdeUnaccessData = GetProcAddress(user32.dll, "DdeUnaccessData");
  user32.oDdeUninitialize = GetProcAddress(user32.dll, "DdeUninitialize");
  user32.oDefDlgProcA = GetProcAddress(user32.dll, "DefDlgProcA");
  user32.oDefDlgProcW = GetProcAddress(user32.dll, "DefDlgProcW");
  user32.oDefFrameProcA = GetProcAddress(user32.dll, "DefFrameProcA");
  user32.oDefFrameProcW = GetProcAddress(user32.dll, "DefFrameProcW");
  user32.oDefMDIChildProcA = GetProcAddress(user32.dll, "DefMDIChildProcA");
  user32.oDefMDIChildProcW = GetProcAddress(user32.dll, "DefMDIChildProcW");
  user32.oDefRawInputProc = GetProcAddress(user32.dll, "DefRawInputProc");
  user32.oDefWindowProcA = GetProcAddress(user32.dll, "DefWindowProcA");
  user32.oDefWindowProcW = GetProcAddress(user32.dll, "DefWindowProcW");
  user32.oDeferWindowPos = GetProcAddress(user32.dll, "DeferWindowPos");
  user32.oDeferWindowPosAndBand =
      GetProcAddress(user32.dll, "DeferWindowPosAndBand");
  user32.oDelegateInput = GetProcAddress(user32.dll, "DelegateInput");
  user32.oDeleteMenu = GetProcAddress(user32.dll, "DeleteMenu");
  user32.oDeregisterShellHookWindow =
      GetProcAddress(user32.dll, "DeregisterShellHookWindow");
  user32.oDestroyAcceleratorTable =
      GetProcAddress(user32.dll, "DestroyAcceleratorTable");
  user32.oDestroyCaret = GetProcAddress(user32.dll, "DestroyCaret");
  user32.oDestroyCursor = GetProcAddress(user32.dll, "DestroyCursor");
  user32.oDestroyDCompositionHwndTarget =
      GetProcAddress(user32.dll, "DestroyDCompositionHwndTarget");
  user32.oDestroyIcon = GetProcAddress(user32.dll, "DestroyIcon");
  user32.oDestroyMenu = GetProcAddress(user32.dll, "DestroyMenu");
  user32.oDestroyReasons = GetProcAddress(user32.dll, "DestroyReasons");
  user32.oDestroySyntheticPointerDevice =
      GetProcAddress(user32.dll, "DestroySyntheticPointerDevice");
  user32.oDestroyWindow = GetProcAddress(user32.dll, "DestroyWindow");
  user32.oDialogBoxIndirectParamA =
      GetProcAddress(user32.dll, "DialogBoxIndirectParamA");
  user32.oDialogBoxIndirectParamAorW =
      GetProcAddress(user32.dll, "DialogBoxIndirectParamAorW");
  user32.oDialogBoxIndirectParamW =
      GetProcAddress(user32.dll, "DialogBoxIndirectParamW");
  user32.oDialogBoxParamA = GetProcAddress(user32.dll, "DialogBoxParamA");
  user32.oDialogBoxParamW = GetProcAddress(user32.dll, "DialogBoxParamW");
  user32.oDisableProcessWindowsGhosting =
      GetProcAddress(user32.dll, "DisableProcessWindowsGhosting");
  user32.oDispatchMessageA = GetProcAddress(user32.dll, "DispatchMessageA");
  user32.oDispatchMessageW = GetProcAddress(user32.dll, "DispatchMessageW");
  user32.oDisplayConfigGetDeviceInfo =
      GetProcAddress(user32.dll, "DisplayConfigGetDeviceInfo");
  user32.oDisplayConfigSetDeviceInfo =
      GetProcAddress(user32.dll, "DisplayConfigSetDeviceInfo");
  user32.oDisplayExitWindowsWarnings =
      GetProcAddress(user32.dll, "DisplayExitWindowsWarnings");
  user32.oDlgDirListA = GetProcAddress(user32.dll, "DlgDirListA");
  user32.oDlgDirListComboBoxA =
      GetProcAddress(user32.dll, "DlgDirListComboBoxA");
  user32.oDlgDirListComboBoxW =
      GetProcAddress(user32.dll, "DlgDirListComboBoxW");
  user32.oDlgDirListW = GetProcAddress(user32.dll, "DlgDirListW");
  user32.oDlgDirSelectComboBoxExA =
      GetProcAddress(user32.dll, "DlgDirSelectComboBoxExA");
  user32.oDlgDirSelectComboBoxExW =
      GetProcAddress(user32.dll, "DlgDirSelectComboBoxExW");
  user32.oDlgDirSelectExA = GetProcAddress(user32.dll, "DlgDirSelectExA");
  user32.oDlgDirSelectExW = GetProcAddress(user32.dll, "DlgDirSelectExW");
  user32.oDoSoundConnect = GetProcAddress(user32.dll, "DoSoundConnect");
  user32.oDoSoundDisconnect = GetProcAddress(user32.dll, "DoSoundDisconnect");
  user32.oDragDetect = GetProcAddress(user32.dll, "DragDetect");
  user32.oDragObject = GetProcAddress(user32.dll, "DragObject");
  user32.oDrawAnimatedRects = GetProcAddress(user32.dll, "DrawAnimatedRects");
  user32.oDrawCaption = GetProcAddress(user32.dll, "DrawCaption");
  user32.oDrawCaptionTempA = GetProcAddress(user32.dll, "DrawCaptionTempA");
  user32.oDrawCaptionTempW = GetProcAddress(user32.dll, "DrawCaptionTempW");
  user32.oDrawEdge = GetProcAddress(user32.dll, "DrawEdge");
  user32.oDrawFocusRect = GetProcAddress(user32.dll, "DrawFocusRect");
  user32.oDrawFrame = GetProcAddress(user32.dll, "DrawFrame");
  user32.oDrawFrameControl = GetProcAddress(user32.dll, "DrawFrameControl");
  user32.oDrawIcon = GetProcAddress(user32.dll, "DrawIcon");
  user32.oDrawIconEx = GetProcAddress(user32.dll, "DrawIconEx");
  user32.oDrawMenuBar = GetProcAddress(user32.dll, "DrawMenuBar");
  user32.oDrawMenuBarTemp = GetProcAddress(user32.dll, "DrawMenuBarTemp");
  user32.oDrawStateA = GetProcAddress(user32.dll, "DrawStateA");
  user32.oDrawStateW = GetProcAddress(user32.dll, "DrawStateW");
  user32.oDrawTextA = GetProcAddress(user32.dll, "DrawTextA");
  user32.oDrawTextExA = GetProcAddress(user32.dll, "DrawTextExA");
  user32.oDrawTextExW = GetProcAddress(user32.dll, "DrawTextExW");
  user32.oDrawTextW = GetProcAddress(user32.dll, "DrawTextW");
  user32.oDwmGetDxRgn = GetProcAddress(user32.dll, "DwmGetDxRgn");
  user32.oDwmGetDxSharedSurface =
      GetProcAddress(user32.dll, "DwmGetDxSharedSurface");
  user32.oDwmGetRemoteSessionOcclusionEvent =
      GetProcAddress(user32.dll, "DwmGetRemoteSessionOcclusionEvent");
  user32.oDwmGetRemoteSessionOcclusionState =
      GetProcAddress(user32.dll, "DwmGetRemoteSessionOcclusionState");
  user32.oDwmKernelShutdown = GetProcAddress(user32.dll, "DwmKernelShutdown");
  user32.oDwmKernelStartup = GetProcAddress(user32.dll, "DwmKernelStartup");
  user32.oDwmLockScreenUpdates =
      GetProcAddress(user32.dll, "DwmLockScreenUpdates");
  user32.oDwmValidateWindow = GetProcAddress(user32.dll, "DwmValidateWindow");
  user32.oDwmWindowNotificationsEnabled =
      GetProcAddress(user32.dll, "DwmWindowNotificationsEnabled");
  user32.oEditWndProc = GetProcAddress(user32.dll, "EditWndProc");
  user32.oEmptyClipboard = GetProcAddress(user32.dll, "EmptyClipboard");
  user32.oEnableMenuItem = GetProcAddress(user32.dll, "EnableMenuItem");
  user32.oEnableMouseInPointer =
      GetProcAddress(user32.dll, "EnableMouseInPointer");
  user32.oEnableNonClientDpiScaling =
      GetProcAddress(user32.dll, "EnableNonClientDpiScaling");
  user32.oEnableOneCoreTransformMode =
      GetProcAddress(user32.dll, "EnableOneCoreTransformMode");
  user32.oEnableScrollBar = GetProcAddress(user32.dll, "EnableScrollBar");
  user32.oEnableSessionForMMCSS =
      GetProcAddress(user32.dll, "EnableSessionForMMCSS");
  user32.oEnableWindow = GetProcAddress(user32.dll, "EnableWindow");
  user32.oEnableWindowShellWindowManagementBehavior =
      GetProcAddress(user32.dll, "EnableWindowShellWindowManagementBehavior");
  user32.oEndDeferWindowPos = GetProcAddress(user32.dll, "EndDeferWindowPos");
  user32.oEndDeferWindowPosEx =
      GetProcAddress(user32.dll, "EndDeferWindowPosEx");
  user32.oEndDialog = GetProcAddress(user32.dll, "EndDialog");
  user32.oEndMenu = GetProcAddress(user32.dll, "EndMenu");
  user32.oEndPaint = GetProcAddress(user32.dll, "EndPaint");
  user32.oEndTask = GetProcAddress(user32.dll, "EndTask");
  user32.oEnterMoveSizeLoop = GetProcAddress(user32.dll, "EnterMoveSizeLoop");
  user32.oEnterReaderModeHelper =
      GetProcAddress(user32.dll, "EnterReaderModeHelper");
  user32.oEnumChildWindows = GetProcAddress(user32.dll, "EnumChildWindows");
  user32.oEnumClipboardFormats =
      GetProcAddress(user32.dll, "EnumClipboardFormats");
  user32.oEnumDesktopWindows = GetProcAddress(user32.dll, "EnumDesktopWindows");
  user32.oEnumDesktopsA = GetProcAddress(user32.dll, "EnumDesktopsA");
  user32.oEnumDesktopsW = GetProcAddress(user32.dll, "EnumDesktopsW");
  user32.oEnumDisplayDevicesA =
      GetProcAddress(user32.dll, "EnumDisplayDevicesA");
  user32.oEnumDisplayDevicesW =
      GetProcAddress(user32.dll, "EnumDisplayDevicesW");
  user32.oEnumDisplayMonitors =
      GetProcAddress(user32.dll, "EnumDisplayMonitors");
  user32.oEnumDisplaySettingsA =
      GetProcAddress(user32.dll, "EnumDisplaySettingsA");
  user32.oEnumDisplaySettingsExA =
      GetProcAddress(user32.dll, "EnumDisplaySettingsExA");
  user32.oEnumDisplaySettingsExW =
      GetProcAddress(user32.dll, "EnumDisplaySettingsExW");
  user32.oEnumDisplaySettingsW =
      GetProcAddress(user32.dll, "EnumDisplaySettingsW");
  user32.oEnumPropsA = GetProcAddress(user32.dll, "EnumPropsA");
  user32.oEnumPropsExA = GetProcAddress(user32.dll, "EnumPropsExA");
  user32.oEnumPropsExW = GetProcAddress(user32.dll, "EnumPropsExW");
  user32.oEnumPropsW = GetProcAddress(user32.dll, "EnumPropsW");
  user32.oEnumThreadWindows = GetProcAddress(user32.dll, "EnumThreadWindows");
  user32.oEnumWindowStationsA =
      GetProcAddress(user32.dll, "EnumWindowStationsA");
  user32.oEnumWindowStationsW =
      GetProcAddress(user32.dll, "EnumWindowStationsW");
  user32.oEnumWindows = GetProcAddress(user32.dll, "EnumWindows");
  user32.oEqualRect = GetProcAddress(user32.dll, "EqualRect");
  user32.oEvaluateProximityToPolygon =
      GetProcAddress(user32.dll, "EvaluateProximityToPolygon");
  user32.oEvaluateProximityToRect =
      GetProcAddress(user32.dll, "EvaluateProximityToRect");
  user32.oExcludeUpdateRgn = GetProcAddress(user32.dll, "ExcludeUpdateRgn");
  user32.oExitWindowsEx = GetProcAddress(user32.dll, "ExitWindowsEx");
  user32.oFillRect = GetProcAddress(user32.dll, "FillRect");
  user32.oFindWindowA = GetProcAddress(user32.dll, "FindWindowA");
  user32.oFindWindowExA = GetProcAddress(user32.dll, "FindWindowExA");
  user32.oFindWindowExW = GetProcAddress(user32.dll, "FindWindowExW");
  user32.oFindWindowW = GetProcAddress(user32.dll, "FindWindowW");
  user32.oFlashWindow = GetProcAddress(user32.dll, "FlashWindow");
  user32.oFlashWindowEx = GetProcAddress(user32.dll, "FlashWindowEx");
  user32.oFrameRect = GetProcAddress(user32.dll, "FrameRect");
  user32.oFreeDDElParam = GetProcAddress(user32.dll, "FreeDDElParam");
  user32.oFrostCrashedWindow = GetProcAddress(user32.dll, "FrostCrashedWindow");
  user32.oGetActiveWindow = GetProcAddress(user32.dll, "GetActiveWindow");
  user32.oGetAltTabInfo = GetProcAddress(user32.dll, "GetAltTabInfo");
  user32.oGetAltTabInfoA = GetProcAddress(user32.dll, "GetAltTabInfoA");
  user32.oGetAltTabInfoW = GetProcAddress(user32.dll, "GetAltTabInfoW");
  user32.oGetAncestor = GetProcAddress(user32.dll, "GetAncestor");
  user32.oGetAppCompatFlags = GetProcAddress(user32.dll, "GetAppCompatFlags");
  user32.oGetAppCompatFlags2 = GetProcAddress(user32.dll, "GetAppCompatFlags2");
  user32.oGetAsyncKeyState = GetProcAddress(user32.dll, "GetAsyncKeyState");
  user32.oGetAutoRotationState =
      GetProcAddress(user32.dll, "GetAutoRotationState");
  user32.oGetAwarenessFromDpiAwarenessContext =
      GetProcAddress(user32.dll, "GetAwarenessFromDpiAwarenessContext");
  user32.oGetCIMSSM = GetProcAddress(user32.dll, "GetCIMSSM");
  user32.oGetCapture = GetProcAddress(user32.dll, "GetCapture");
  user32.oGetCaretBlinkTime = GetProcAddress(user32.dll, "GetCaretBlinkTime");
  user32.oGetCaretPos = GetProcAddress(user32.dll, "GetCaretPos");
  user32.oGetClassInfoA = GetProcAddress(user32.dll, "GetClassInfoA");
  user32.oGetClassInfoExA = GetProcAddress(user32.dll, "GetClassInfoExA");
  user32.oGetClassInfoExW = GetProcAddress(user32.dll, "GetClassInfoExW");
  user32.oGetClassInfoW = GetProcAddress(user32.dll, "GetClassInfoW");
  user32.oGetClassLongA = GetProcAddress(user32.dll, "GetClassLongA");
  user32.oGetClassLongPtrA = GetProcAddress(user32.dll, "GetClassLongPtrA");
  user32.oGetClassLongPtrW = GetProcAddress(user32.dll, "GetClassLongPtrW");
  user32.oGetClassLongW = GetProcAddress(user32.dll, "GetClassLongW");
  user32.oGetClassNameA = GetProcAddress(user32.dll, "GetClassNameA");
  user32.oGetClassNameW = GetProcAddress(user32.dll, "GetClassNameW");
  user32.oGetClassWord = GetProcAddress(user32.dll, "GetClassWord");
  user32.oGetClientRect = GetProcAddress(user32.dll, "GetClientRect");
  user32.oGetClipCursor = GetProcAddress(user32.dll, "GetClipCursor");
  user32.oGetClipboardAccessToken =
      GetProcAddress(user32.dll, "GetClipboardAccessToken");
  user32.oGetClipboardData = GetProcAddress(user32.dll, "GetClipboardData");
  user32.oGetClipboardFormatNameA =
      GetProcAddress(user32.dll, "GetClipboardFormatNameA");
  user32.oGetClipboardFormatNameW =
      GetProcAddress(user32.dll, "GetClipboardFormatNameW");
  user32.oGetClipboardMetadata =
      GetProcAddress(user32.dll, "GetClipboardMetadata");
  user32.oGetClipboardOwner = GetProcAddress(user32.dll, "GetClipboardOwner");
  user32.oGetClipboardSequenceNumber =
      GetProcAddress(user32.dll, "GetClipboardSequenceNumber");
  user32.oGetClipboardViewer = GetProcAddress(user32.dll, "GetClipboardViewer");
  user32.oGetComboBoxInfo = GetProcAddress(user32.dll, "GetComboBoxInfo");
  user32.oGetCurrentInputMessageSource =
      GetProcAddress(user32.dll, "GetCurrentInputMessageSource");
  user32.oGetCurrentMonitorTopologyId =
      GetProcAddress(user32.dll, "GetCurrentMonitorTopologyId");
  user32.oGetCursor = GetProcAddress(user32.dll, "GetCursor");
  user32.oGetCursorFrameInfo = GetProcAddress(user32.dll, "GetCursorFrameInfo");
  user32.oGetCursorInfo = GetProcAddress(user32.dll, "GetCursorInfo");
  user32.oGetCursorPos = GetProcAddress(user32.dll, "GetCursorPos");
  user32.oGetDC = GetProcAddress(user32.dll, "GetDC");
  user32.oGetDCEx = GetProcAddress(user32.dll, "GetDCEx");
  user32.oGetDCompositionHwndBitmap =
      GetProcAddress(user32.dll, "GetDCompositionHwndBitmap");
  user32.oGetDesktopID = GetProcAddress(user32.dll, "GetDesktopID");
  user32.oGetDesktopWindow = GetProcAddress(user32.dll, "GetDesktopWindow");
  user32.oGetDialogBaseUnits = GetProcAddress(user32.dll, "GetDialogBaseUnits");
  user32.oGetDialogControlDpiChangeBehavior =
      GetProcAddress(user32.dll, "GetDialogControlDpiChangeBehavior");
  user32.oGetDialogDpiChangeBehavior =
      GetProcAddress(user32.dll, "GetDialogDpiChangeBehavior");
  user32.oGetDisplayAutoRotationPreferences =
      GetProcAddress(user32.dll, "GetDisplayAutoRotationPreferences");
  user32.oGetDisplayConfigBufferSizes =
      GetProcAddress(user32.dll, "GetDisplayConfigBufferSizes");
  user32.oGetDlgCtrlID = GetProcAddress(user32.dll, "GetDlgCtrlID");
  user32.oGetDlgItem = GetProcAddress(user32.dll, "GetDlgItem");
  user32.oGetDlgItemInt = GetProcAddress(user32.dll, "GetDlgItemInt");
  user32.oGetDlgItemTextA = GetProcAddress(user32.dll, "GetDlgItemTextA");
  user32.oGetDlgItemTextW = GetProcAddress(user32.dll, "GetDlgItemTextW");
  user32.oGetDoubleClickTime = GetProcAddress(user32.dll, "GetDoubleClickTime");
  user32.oGetDpiAwarenessContextForProcess =
      GetProcAddress(user32.dll, "GetDpiAwarenessContextForProcess");
  user32.oGetDpiForMonitorInternal =
      GetProcAddress(user32.dll, "GetDpiForMonitorInternal");
  user32.oGetDpiForSystem = GetProcAddress(user32.dll, "GetDpiForSystem");
  user32.oGetDpiForWindow = GetProcAddress(user32.dll, "GetDpiForWindow");
  user32.oGetDpiFromDpiAwarenessContext =
      GetProcAddress(user32.dll, "GetDpiFromDpiAwarenessContext");
  user32.oGetExtendedPointerDeviceProperty =
      GetProcAddress(user32.dll, "GetExtendedPointerDeviceProperty");
  user32.oGetFocus = GetProcAddress(user32.dll, "GetFocus");
  user32.oGetForegroundWindow =
      GetProcAddress(user32.dll, "GetForegroundWindow");
  user32.oGetGUIThreadInfo = GetProcAddress(user32.dll, "GetGUIThreadInfo");
  user32.oGetGestureConfig = GetProcAddress(user32.dll, "GetGestureConfig");
  user32.oGetGestureExtraArgs =
      GetProcAddress(user32.dll, "GetGestureExtraArgs");
  user32.oGetGestureInfo = GetProcAddress(user32.dll, "GetGestureInfo");
  user32.oGetGuiResources = GetProcAddress(user32.dll, "GetGuiResources");
  user32.oGetIconInfo = GetProcAddress(user32.dll, "GetIconInfo");
  user32.oGetIconInfoExA = GetProcAddress(user32.dll, "GetIconInfoExA");
  user32.oGetIconInfoExW = GetProcAddress(user32.dll, "GetIconInfoExW");
  user32.oGetInputDesktop = GetProcAddress(user32.dll, "GetInputDesktop");
  user32.oGetInputLocaleInfo = GetProcAddress(user32.dll, "GetInputLocaleInfo");
  user32.oGetInputState = GetProcAddress(user32.dll, "GetInputState");
  user32.oGetInternalWindowPos =
      GetProcAddress(user32.dll, "GetInternalWindowPos");
  user32.oGetKBCodePage = GetProcAddress(user32.dll, "GetKBCodePage");
  user32.oGetKeyNameTextA = GetProcAddress(user32.dll, "GetKeyNameTextA");
  user32.oGetKeyNameTextW = GetProcAddress(user32.dll, "GetKeyNameTextW");
  user32.oGetKeyState = GetProcAddress(user32.dll, "GetKeyState");
  user32.oGetKeyboardLayout = GetProcAddress(user32.dll, "GetKeyboardLayout");
  user32.oGetKeyboardLayoutList =
      GetProcAddress(user32.dll, "GetKeyboardLayoutList");
  user32.oGetKeyboardLayoutNameA =
      GetProcAddress(user32.dll, "GetKeyboardLayoutNameA");
  user32.oGetKeyboardLayoutNameW =
      GetProcAddress(user32.dll, "GetKeyboardLayoutNameW");
  user32.oGetKeyboardState = GetProcAddress(user32.dll, "GetKeyboardState");
  user32.oGetKeyboardType = GetProcAddress(user32.dll, "GetKeyboardType");
  user32.oGetLastActivePopup = GetProcAddress(user32.dll, "GetLastActivePopup");
  user32.oGetLastInputInfo = GetProcAddress(user32.dll, "GetLastInputInfo");
  user32.oGetLayeredWindowAttributes =
      GetProcAddress(user32.dll, "GetLayeredWindowAttributes");
  user32.oGetListBoxInfo = GetProcAddress(user32.dll, "GetListBoxInfo");
  user32.oGetMagnificationDesktopColorEffect =
      GetProcAddress(user32.dll, "GetMagnificationDesktopColorEffect");
  user32.oGetMagnificationDesktopMagnification =
      GetProcAddress(user32.dll, "GetMagnificationDesktopMagnification");
  user32.oGetMagnificationDesktopSamplingMode =
      GetProcAddress(user32.dll, "GetMagnificationDesktopSamplingMode");
  user32.oGetMagnificationLensCtxInformation =
      GetProcAddress(user32.dll, "GetMagnificationLensCtxInformation");
  user32.oGetMenu = GetProcAddress(user32.dll, "GetMenu");
  user32.oGetMenuBarInfo = GetProcAddress(user32.dll, "GetMenuBarInfo");
  user32.oGetMenuCheckMarkDimensions =
      GetProcAddress(user32.dll, "GetMenuCheckMarkDimensions");
  user32.oGetMenuContextHelpId =
      GetProcAddress(user32.dll, "GetMenuContextHelpId");
  user32.oGetMenuDefaultItem = GetProcAddress(user32.dll, "GetMenuDefaultItem");
  user32.oGetMenuInfo = GetProcAddress(user32.dll, "GetMenuInfo");
  user32.oGetMenuItemCount = GetProcAddress(user32.dll, "GetMenuItemCount");
  user32.oGetMenuItemID = GetProcAddress(user32.dll, "GetMenuItemID");
  user32.oGetMenuItemInfoA = GetProcAddress(user32.dll, "GetMenuItemInfoA");
  user32.oGetMenuItemInfoW = GetProcAddress(user32.dll, "GetMenuItemInfoW");
  user32.oGetMenuItemRect = GetProcAddress(user32.dll, "GetMenuItemRect");
  user32.oGetMenuState = GetProcAddress(user32.dll, "GetMenuState");
  user32.oGetMenuStringA = GetProcAddress(user32.dll, "GetMenuStringA");
  user32.oGetMenuStringW = GetProcAddress(user32.dll, "GetMenuStringW");
  user32.oGetMessageA = GetProcAddress(user32.dll, "GetMessageA");
  user32.oGetMessageExtraInfo =
      GetProcAddress(user32.dll, "GetMessageExtraInfo");
  user32.oGetMessagePos = GetProcAddress(user32.dll, "GetMessagePos");
  user32.oGetMessageTime = GetProcAddress(user32.dll, "GetMessageTime");
  user32.oGetMessageW = GetProcAddress(user32.dll, "GetMessageW");
  user32.oGetMonitorInfoA = GetProcAddress(user32.dll, "GetMonitorInfoA");
  user32.oGetMonitorInfoW = GetProcAddress(user32.dll, "GetMonitorInfoW");
  user32.oGetMouseMovePointsEx =
      GetProcAddress(user32.dll, "GetMouseMovePointsEx");
  user32.oGetNextDlgGroupItem =
      GetProcAddress(user32.dll, "GetNextDlgGroupItem");
  user32.oGetNextDlgTabItem = GetProcAddress(user32.dll, "GetNextDlgTabItem");
  user32.oGetOpenClipboardWindow =
      GetProcAddress(user32.dll, "GetOpenClipboardWindow");
  user32.oGetParent = GetProcAddress(user32.dll, "GetParent");
  user32.oGetPhysicalCursorPos =
      GetProcAddress(user32.dll, "GetPhysicalCursorPos");
  user32.oGetPointerCursorId = GetProcAddress(user32.dll, "GetPointerCursorId");
  user32.oGetPointerDevice = GetProcAddress(user32.dll, "GetPointerDevice");
  user32.oGetPointerDeviceCursors =
      GetProcAddress(user32.dll, "GetPointerDeviceCursors");
  user32.oGetPointerDeviceInputSpace =
      GetProcAddress(user32.dll, "GetPointerDeviceInputSpace");
  user32.oGetPointerDeviceOrientation =
      GetProcAddress(user32.dll, "GetPointerDeviceOrientation");
  user32.oGetPointerDeviceProperties =
      GetProcAddress(user32.dll, "GetPointerDeviceProperties");
  user32.oGetPointerDeviceRects =
      GetProcAddress(user32.dll, "GetPointerDeviceRects");
  user32.oGetPointerDevices = GetProcAddress(user32.dll, "GetPointerDevices");
  user32.oGetPointerFrameArrivalTimes =
      GetProcAddress(user32.dll, "GetPointerFrameArrivalTimes");
  user32.oGetPointerFrameInfo =
      GetProcAddress(user32.dll, "GetPointerFrameInfo");
  user32.oGetPointerFrameInfoHistory =
      GetProcAddress(user32.dll, "GetPointerFrameInfoHistory");
  user32.oGetPointerFramePenInfo =
      GetProcAddress(user32.dll, "GetPointerFramePenInfo");
  user32.oGetPointerFramePenInfoHistory =
      GetProcAddress(user32.dll, "GetPointerFramePenInfoHistory");
  user32.oGetPointerFrameTimes =
      GetProcAddress(user32.dll, "GetPointerFrameTimes");
  user32.oGetPointerFrameTouchInfo =
      GetProcAddress(user32.dll, "GetPointerFrameTouchInfo");
  user32.oGetPointerFrameTouchInfoHistory =
      GetProcAddress(user32.dll, "GetPointerFrameTouchInfoHistory");
  user32.oGetPointerFrameTouchpadInfo =
      GetProcAddress(user32.dll, "GetPointerFrameTouchpadInfo");
  user32.oGetPointerFrameTouchpadInfoHistory =
      GetProcAddress(user32.dll, "GetPointerFrameTouchpadInfoHistory");
  user32.oGetPointerInfo = GetProcAddress(user32.dll, "GetPointerInfo");
  user32.oGetPointerInfoHistory =
      GetProcAddress(user32.dll, "GetPointerInfoHistory");
  user32.oGetPointerInputTransform =
      GetProcAddress(user32.dll, "GetPointerInputTransform");
  user32.oGetPointerPenInfo = GetProcAddress(user32.dll, "GetPointerPenInfo");
  user32.oGetPointerPenInfoHistory =
      GetProcAddress(user32.dll, "GetPointerPenInfoHistory");
  user32.oGetPointerTouchInfo =
      GetProcAddress(user32.dll, "GetPointerTouchInfo");
  user32.oGetPointerTouchInfoHistory =
      GetProcAddress(user32.dll, "GetPointerTouchInfoHistory");
  user32.oGetPointerTouchpadInfo =
      GetProcAddress(user32.dll, "GetPointerTouchpadInfo");
  user32.oGetPointerTouchpadInfoHistory =
      GetProcAddress(user32.dll, "GetPointerTouchpadInfoHistory");
  user32.oGetPointerType = GetProcAddress(user32.dll, "GetPointerType");
  user32.oGetPriorityClipboardFormat =
      GetProcAddress(user32.dll, "GetPriorityClipboardFormat");
  user32.oGetProcessDefaultLayout =
      GetProcAddress(user32.dll, "GetProcessDefaultLayout");
  user32.oGetProcessDpiAwarenessInternal =
      GetProcAddress(user32.dll, "GetProcessDpiAwarenessInternal");
  user32.oGetProcessUIContextInformation =
      GetProcAddress(user32.dll, "GetProcessUIContextInformation");
  user32.oGetProcessWindowStation =
      GetProcAddress(user32.dll, "GetProcessWindowStation");
  user32.oGetProgmanWindow = GetProcAddress(user32.dll, "GetProgmanWindow");
  user32.oGetPropA = GetProcAddress(user32.dll, "GetPropA");
  user32.oGetPropW = GetProcAddress(user32.dll, "GetPropW");
  user32.oGetQueueStatus = GetProcAddress(user32.dll, "GetQueueStatus");
  user32.oGetRawInputBuffer = GetProcAddress(user32.dll, "GetRawInputBuffer");
  user32.oGetRawInputData = GetProcAddress(user32.dll, "GetRawInputData");
  user32.oGetRawInputDeviceInfoA =
      GetProcAddress(user32.dll, "GetRawInputDeviceInfoA");
  user32.oGetRawInputDeviceInfoW =
      GetProcAddress(user32.dll, "GetRawInputDeviceInfoW");
  user32.oGetRawInputDeviceList =
      GetProcAddress(user32.dll, "GetRawInputDeviceList");
  user32.oGetRawPointerDeviceData =
      GetProcAddress(user32.dll, "GetRawPointerDeviceData");
  user32.oGetReasonTitleFromReasonCode =
      GetProcAddress(user32.dll, "GetReasonTitleFromReasonCode");
  user32.oGetRegisteredRawInputDevices =
      GetProcAddress(user32.dll, "GetRegisteredRawInputDevices");
  user32.oGetScrollBarInfo = GetProcAddress(user32.dll, "GetScrollBarInfo");
  user32.oGetScrollInfo = GetProcAddress(user32.dll, "GetScrollInfo");
  user32.oGetScrollPos = GetProcAddress(user32.dll, "GetScrollPos");
  user32.oGetScrollRange = GetProcAddress(user32.dll, "GetScrollRange");
  user32.oGetSendMessageReceiver =
      GetProcAddress(user32.dll, "GetSendMessageReceiver");
  user32.oGetShellChangeNotifyWindow =
      GetProcAddress(user32.dll, "GetShellChangeNotifyWindow");
  user32.oGetShellWindow = GetProcAddress(user32.dll, "GetShellWindow");
  user32.oGetSubMenu = GetProcAddress(user32.dll, "GetSubMenu");
  user32.oGetSysColor = GetProcAddress(user32.dll, "GetSysColor");
  user32.oGetSysColorBrush = GetProcAddress(user32.dll, "GetSysColorBrush");
  user32.oGetSystemDpiForProcess =
      GetProcAddress(user32.dll, "GetSystemDpiForProcess");
  user32.oGetSystemMenu = GetProcAddress(user32.dll, "GetSystemMenu");
  user32.oGetSystemMetrics = GetProcAddress(user32.dll, "GetSystemMetrics");
  user32.oGetSystemMetricsForDpi =
      GetProcAddress(user32.dll, "GetSystemMetricsForDpi");
  user32.oGetTabbedTextExtentA =
      GetProcAddress(user32.dll, "GetTabbedTextExtentA");
  user32.oGetTabbedTextExtentW =
      GetProcAddress(user32.dll, "GetTabbedTextExtentW");
  user32.oGetTaskmanWindow = GetProcAddress(user32.dll, "GetTaskmanWindow");
  user32.oGetThreadDesktop = GetProcAddress(user32.dll, "GetThreadDesktop");
  user32.oGetThreadDpiAwarenessContext =
      GetProcAddress(user32.dll, "GetThreadDpiAwarenessContext");
  user32.oGetThreadDpiHostingBehavior =
      GetProcAddress(user32.dll, "GetThreadDpiHostingBehavior");
  user32.oGetTitleBarInfo = GetProcAddress(user32.dll, "GetTitleBarInfo");
  user32.oGetTopLevelWindow = GetProcAddress(user32.dll, "GetTopLevelWindow");
  user32.oGetTopWindow = GetProcAddress(user32.dll, "GetTopWindow");
  user32.oGetTouchInputInfo = GetProcAddress(user32.dll, "GetTouchInputInfo");
  user32.oGetUnpredictedMessagePos =
      GetProcAddress(user32.dll, "GetUnpredictedMessagePos");
  user32.oGetUpdateRect = GetProcAddress(user32.dll, "GetUpdateRect");
  user32.oGetUpdateRgn = GetProcAddress(user32.dll, "GetUpdateRgn");
  user32.oGetUpdatedClipboardFormats =
      GetProcAddress(user32.dll, "GetUpdatedClipboardFormats");
  user32.oGetUserObjectInformationA =
      GetProcAddress(user32.dll, "GetUserObjectInformationA");
  user32.oGetUserObjectInformationW =
      GetProcAddress(user32.dll, "GetUserObjectInformationW");
  user32.oGetUserObjectSecurity =
      GetProcAddress(user32.dll, "GetUserObjectSecurity");
  user32.oGetWinStationInfo = GetProcAddress(user32.dll, "GetWinStationInfo");
  user32.oGetWindow = GetProcAddress(user32.dll, "GetWindow");
  user32.oGetWindowBand = GetProcAddress(user32.dll, "GetWindowBand");
  user32.oGetWindowCompositionAttribute =
      GetProcAddress(user32.dll, "GetWindowCompositionAttribute");
  user32.oGetWindowCompositionInfo =
      GetProcAddress(user32.dll, "GetWindowCompositionInfo");
  user32.oGetWindowContextHelpId =
      GetProcAddress(user32.dll, "GetWindowContextHelpId");
  user32.oGetWindowDC = GetProcAddress(user32.dll, "GetWindowDC");
  user32.oGetWindowDisplayAffinity =
      GetProcAddress(user32.dll, "GetWindowDisplayAffinity");
  user32.oGetWindowDpiAwarenessContext =
      GetProcAddress(user32.dll, "GetWindowDpiAwarenessContext");
  user32.oGetWindowDpiHostingBehavior =
      GetProcAddress(user32.dll, "GetWindowDpiHostingBehavior");
  user32.oGetWindowFeedbackSetting =
      GetProcAddress(user32.dll, "GetWindowFeedbackSetting");
  user32.oGetWindowInfo = GetProcAddress(user32.dll, "GetWindowInfo");
  user32.oGetWindowLongA = GetProcAddress(user32.dll, "GetWindowLongA");
  user32.oGetWindowLongPtrA = GetProcAddress(user32.dll, "GetWindowLongPtrA");
  user32.oGetWindowLongPtrW = GetProcAddress(user32.dll, "GetWindowLongPtrW");
  user32.oGetWindowLongW = GetProcAddress(user32.dll, "GetWindowLongW");
  user32.oGetWindowMinimizeRect =
      GetProcAddress(user32.dll, "GetWindowMinimizeRect");
  user32.oGetWindowModuleFileName =
      GetProcAddress(user32.dll, "GetWindowModuleFileName");
  user32.oGetWindowModuleFileNameA =
      GetProcAddress(user32.dll, "GetWindowModuleFileNameA");
  user32.oGetWindowModuleFileNameW =
      GetProcAddress(user32.dll, "GetWindowModuleFileNameW");
  user32.oGetWindowPlacement = GetProcAddress(user32.dll, "GetWindowPlacement");
  user32.oGetWindowProcessHandle =
      GetProcAddress(user32.dll, "GetWindowProcessHandle");
  user32.oGetWindowRect = GetProcAddress(user32.dll, "GetWindowRect");
  user32.oGetWindowRgn = GetProcAddress(user32.dll, "GetWindowRgn");
  user32.oGetWindowRgnBox = GetProcAddress(user32.dll, "GetWindowRgnBox");
  user32.oGetWindowRgnEx = GetProcAddress(user32.dll, "GetWindowRgnEx");
  user32.oGetWindowTextA = GetProcAddress(user32.dll, "GetWindowTextA");
  user32.oGetWindowTextLengthA =
      GetProcAddress(user32.dll, "GetWindowTextLengthA");
  user32.oGetWindowTextLengthW =
      GetProcAddress(user32.dll, "GetWindowTextLengthW");
  user32.oGetWindowTextW = GetProcAddress(user32.dll, "GetWindowTextW");
  user32.oGetWindowThreadProcessId =
      GetProcAddress(user32.dll, "GetWindowThreadProcessId");
  user32.oGetWindowWord = GetProcAddress(user32.dll, "GetWindowWord");
  user32.oGhostWindowFromHungWindow =
      GetProcAddress(user32.dll, "GhostWindowFromHungWindow");
  user32.oGrayStringA = GetProcAddress(user32.dll, "GrayStringA");
  user32.oGrayStringW = GetProcAddress(user32.dll, "GrayStringW");
  user32.oHandleDelegatedInput =
      GetProcAddress(user32.dll, "HandleDelegatedInput");
  user32.oHideCaret = GetProcAddress(user32.dll, "HideCaret");
  user32.oHiliteMenuItem = GetProcAddress(user32.dll, "HiliteMenuItem");
  user32.oHungWindowFromGhostWindow =
      GetProcAddress(user32.dll, "HungWindowFromGhostWindow");
  user32.oIMPGetIMEA = GetProcAddress(user32.dll, "IMPGetIMEA");
  user32.oIMPGetIMEW = GetProcAddress(user32.dll, "IMPGetIMEW");
  user32.oIMPQueryIMEA = GetProcAddress(user32.dll, "IMPQueryIMEA");
  user32.oIMPQueryIMEW = GetProcAddress(user32.dll, "IMPQueryIMEW");
  user32.oIMPSetIMEA = GetProcAddress(user32.dll, "IMPSetIMEA");
  user32.oIMPSetIMEW = GetProcAddress(user32.dll, "IMPSetIMEW");
  user32.oImpersonateDdeClientWindow =
      GetProcAddress(user32.dll, "ImpersonateDdeClientWindow");
  user32.oInSendMessage = GetProcAddress(user32.dll, "InSendMessage");
  user32.oInSendMessageEx = GetProcAddress(user32.dll, "InSendMessageEx");
  user32.oInflateRect = GetProcAddress(user32.dll, "InflateRect");
  user32.oInheritWindowMonitor =
      GetProcAddress(user32.dll, "InheritWindowMonitor");
  user32.oInitDManipHook = GetProcAddress(user32.dll, "InitDManipHook");
  user32.oInitializeGenericHidInjection =
      GetProcAddress(user32.dll, "InitializeGenericHidInjection");
  user32.oInitializeInputDeviceInjection =
      GetProcAddress(user32.dll, "InitializeInputDeviceInjection");
  user32.oInitializeLpkHooks = GetProcAddress(user32.dll, "InitializeLpkHooks");
  user32.oInitializePointerDeviceInjection =
      GetProcAddress(user32.dll, "InitializePointerDeviceInjection");
  user32.oInitializePointerDeviceInjectionEx =
      GetProcAddress(user32.dll, "InitializePointerDeviceInjectionEx");
  user32.oInitializeTouchInjection =
      GetProcAddress(user32.dll, "InitializeTouchInjection");
  user32.oInjectDeviceInput = GetProcAddress(user32.dll, "InjectDeviceInput");
  user32.oInjectGenericHidInput =
      GetProcAddress(user32.dll, "InjectGenericHidInput");
  user32.oInjectKeyboardInput =
      GetProcAddress(user32.dll, "InjectKeyboardInput");
  user32.oInjectMouseInput = GetProcAddress(user32.dll, "InjectMouseInput");
  user32.oInjectPointerInput = GetProcAddress(user32.dll, "InjectPointerInput");
  user32.oInjectSyntheticPointerInput =
      GetProcAddress(user32.dll, "InjectSyntheticPointerInput");
  user32.oInjectTouchInput = GetProcAddress(user32.dll, "InjectTouchInput");
  user32.oInputSpaceRegionFromPoint =
      GetProcAddress(user32.dll, "InputSpaceRegionFromPoint");
  user32.oInsertMenuA = GetProcAddress(user32.dll, "InsertMenuA");
  user32.oInsertMenuItemA = GetProcAddress(user32.dll, "InsertMenuItemA");
  user32.oInsertMenuItemW = GetProcAddress(user32.dll, "InsertMenuItemW");
  user32.oInsertMenuW = GetProcAddress(user32.dll, "InsertMenuW");
  user32.oInternalGetWindowIcon =
      GetProcAddress(user32.dll, "InternalGetWindowIcon");
  user32.oInternalGetWindowText =
      GetProcAddress(user32.dll, "InternalGetWindowText");
  user32.oIntersectRect = GetProcAddress(user32.dll, "IntersectRect");
  user32.oInvalidateRect = GetProcAddress(user32.dll, "InvalidateRect");
  user32.oInvalidateRgn = GetProcAddress(user32.dll, "InvalidateRgn");
  user32.oInvertRect = GetProcAddress(user32.dll, "InvertRect");
  user32.oIsCharAlphaA = GetProcAddress(user32.dll, "IsCharAlphaA");
  user32.oIsCharAlphaNumericA =
      GetProcAddress(user32.dll, "IsCharAlphaNumericA");
  user32.oIsCharAlphaNumericW =
      GetProcAddress(user32.dll, "IsCharAlphaNumericW");
  user32.oIsCharAlphaW = GetProcAddress(user32.dll, "IsCharAlphaW");
  user32.oIsCharLowerA = GetProcAddress(user32.dll, "IsCharLowerA");
  user32.oIsCharLowerW = GetProcAddress(user32.dll, "IsCharLowerW");
  user32.oIsCharUpperA = GetProcAddress(user32.dll, "IsCharUpperA");
  user32.oIsCharUpperW = GetProcAddress(user32.dll, "IsCharUpperW");
  user32.oIsChild = GetProcAddress(user32.dll, "IsChild");
  user32.oIsClipboardFormatAvailable =
      GetProcAddress(user32.dll, "IsClipboardFormatAvailable");
  user32.oIsDialogMessage = GetProcAddress(user32.dll, "IsDialogMessage");
  user32.oIsDialogMessageA = GetProcAddress(user32.dll, "IsDialogMessageA");
  user32.oIsDialogMessageW = GetProcAddress(user32.dll, "IsDialogMessageW");
  user32.oIsDlgButtonChecked = GetProcAddress(user32.dll, "IsDlgButtonChecked");
  user32.oIsGUIThread = GetProcAddress(user32.dll, "IsGUIThread");
  user32.oIsHungAppWindow = GetProcAddress(user32.dll, "IsHungAppWindow");
  user32.oIsIconic = GetProcAddress(user32.dll, "IsIconic");
  user32.oIsImmersiveProcess = GetProcAddress(user32.dll, "IsImmersiveProcess");
  user32.oIsInDesktopWindowBand =
      GetProcAddress(user32.dll, "IsInDesktopWindowBand");
  user32.oIsInterceptWindow = GetProcAddress(user32.dll, "IsInterceptWindow");
  user32.oIsMenu = GetProcAddress(user32.dll, "IsMenu");
  user32.oIsMouseInPointerEnabled =
      GetProcAddress(user32.dll, "IsMouseInPointerEnabled");
  user32.oIsOneCoreTransformMode =
      GetProcAddress(user32.dll, "IsOneCoreTransformMode");
  user32.oIsProcessDPIAware = GetProcAddress(user32.dll, "IsProcessDPIAware");
  user32.oIsRectEmpty = GetProcAddress(user32.dll, "IsRectEmpty");
  user32.oIsSETEnabled = GetProcAddress(user32.dll, "IsSETEnabled");
  user32.oIsServerSideWindow = GetProcAddress(user32.dll, "IsServerSideWindow");
  user32.oIsThreadDesktopComposited =
      GetProcAddress(user32.dll, "IsThreadDesktopComposited");
  user32.oIsThreadMessageQueueAttached =
      GetProcAddress(user32.dll, "IsThreadMessageQueueAttached");
  user32.oIsThreadTSFEventAware =
      GetProcAddress(user32.dll, "IsThreadTSFEventAware");
  user32.oIsTopLevelWindow = GetProcAddress(user32.dll, "IsTopLevelWindow");
  user32.oIsTouchWindow = GetProcAddress(user32.dll, "IsTouchWindow");
  user32.oIsValidDpiAwarenessContext =
      GetProcAddress(user32.dll, "IsValidDpiAwarenessContext");
  user32.oIsWinEventHookInstalled =
      GetProcAddress(user32.dll, "IsWinEventHookInstalled");
  user32.oIsWindow = GetProcAddress(user32.dll, "IsWindow");
  user32.oIsWindowArranged = GetProcAddress(user32.dll, "IsWindowArranged");
  user32.oIsWindowDisplayChangeSuppressed =
      GetProcAddress(user32.dll, "IsWindowDisplayChangeSuppressed");
  user32.oIsWindowEnabled = GetProcAddress(user32.dll, "IsWindowEnabled");
  user32.oIsWindowInDestroy = GetProcAddress(user32.dll, "IsWindowInDestroy");
  user32.oIsWindowRedirectedForPrint =
      GetProcAddress(user32.dll, "IsWindowRedirectedForPrint");
  user32.oIsWindowUnicode = GetProcAddress(user32.dll, "IsWindowUnicode");
  user32.oIsWindowVisible = GetProcAddress(user32.dll, "IsWindowVisible");
  user32.oIsWow64Message = GetProcAddress(user32.dll, "IsWow64Message");
  user32.oIsZoomed = GetProcAddress(user32.dll, "IsZoomed");
  user32.oKillTimer = GetProcAddress(user32.dll, "KillTimer");
  user32.oLoadAcceleratorsA = GetProcAddress(user32.dll, "LoadAcceleratorsA");
  user32.oLoadAcceleratorsW = GetProcAddress(user32.dll, "LoadAcceleratorsW");
  user32.oLoadBitmapA = GetProcAddress(user32.dll, "LoadBitmapA");
  user32.oLoadBitmapW = GetProcAddress(user32.dll, "LoadBitmapW");
  user32.oLoadCursorA = GetProcAddress(user32.dll, "LoadCursorA");
  user32.oLoadCursorFromFileA =
      GetProcAddress(user32.dll, "LoadCursorFromFileA");
  user32.oLoadCursorFromFileW =
      GetProcAddress(user32.dll, "LoadCursorFromFileW");
  user32.oLoadCursorW = GetProcAddress(user32.dll, "LoadCursorW");
  user32.oLoadIconA = GetProcAddress(user32.dll, "LoadIconA");
  user32.oLoadIconW = GetProcAddress(user32.dll, "LoadIconW");
  user32.oLoadImageA = GetProcAddress(user32.dll, "LoadImageA");
  user32.oLoadImageW = GetProcAddress(user32.dll, "LoadImageW");
  user32.oLoadKeyboardLayoutA =
      GetProcAddress(user32.dll, "LoadKeyboardLayoutA");
  user32.oLoadKeyboardLayoutEx =
      GetProcAddress(user32.dll, "LoadKeyboardLayoutEx");
  user32.oLoadKeyboardLayoutW =
      GetProcAddress(user32.dll, "LoadKeyboardLayoutW");
  user32.oLoadLocalFonts = GetProcAddress(user32.dll, "LoadLocalFonts");
  user32.oLoadMenuA = GetProcAddress(user32.dll, "LoadMenuA");
  user32.oLoadMenuIndirectA = GetProcAddress(user32.dll, "LoadMenuIndirectA");
  user32.oLoadMenuIndirectW = GetProcAddress(user32.dll, "LoadMenuIndirectW");
  user32.oLoadMenuW = GetProcAddress(user32.dll, "LoadMenuW");
  user32.oLoadRemoteFonts = GetProcAddress(user32.dll, "LoadRemoteFonts");
  user32.oLoadStringA = GetProcAddress(user32.dll, "LoadStringA");
  user32.oLoadStringW = GetProcAddress(user32.dll, "LoadStringW");
  user32.oLockSetForegroundWindow =
      GetProcAddress(user32.dll, "LockSetForegroundWindow");
  user32.oLockWindowStation = GetProcAddress(user32.dll, "LockWindowStation");
  user32.oLockWindowUpdate = GetProcAddress(user32.dll, "LockWindowUpdate");
  user32.oLockWorkStation = GetProcAddress(user32.dll, "LockWorkStation");
  user32.oLogicalToPhysicalPoint =
      GetProcAddress(user32.dll, "LogicalToPhysicalPoint");
  user32.oLogicalToPhysicalPointForPerMonitorDPI =
      GetProcAddress(user32.dll, "LogicalToPhysicalPointForPerMonitorDPI");
  user32.oLookupIconIdFromDirectory =
      GetProcAddress(user32.dll, "LookupIconIdFromDirectory");
  user32.oLookupIconIdFromDirectoryEx =
      GetProcAddress(user32.dll, "LookupIconIdFromDirectoryEx");
  user32.oMBToWCSEx = GetProcAddress(user32.dll, "MBToWCSEx");
  user32.oMBToWCSExt = GetProcAddress(user32.dll, "MBToWCSExt");
  user32.oMB_GetString = GetProcAddress(user32.dll, "MB_GetString");
  user32.oMITGetCursorUpdateHandle =
      GetProcAddress(user32.dll, "MITGetCursorUpdateHandle");
  user32.oMITSetLastInputRecipient =
      GetProcAddress(user32.dll, "MITSetLastInputRecipient");
  user32.oMITSynthesizeTouchInput =
      GetProcAddress(user32.dll, "MITSynthesizeTouchInput");
  user32.oMakeThreadTSFEventAware =
      GetProcAddress(user32.dll, "MakeThreadTSFEventAware");
  user32.oMapDialogRect = GetProcAddress(user32.dll, "MapDialogRect");
  user32.oMapPointsByVisualIdentifier =
      GetProcAddress(user32.dll, "MapPointsByVisualIdentifier");
  user32.oMapVirtualKeyA = GetProcAddress(user32.dll, "MapVirtualKeyA");
  user32.oMapVirtualKeyExA = GetProcAddress(user32.dll, "MapVirtualKeyExA");
  user32.oMapVirtualKeyExW = GetProcAddress(user32.dll, "MapVirtualKeyExW");
  user32.oMapVirtualKeyW = GetProcAddress(user32.dll, "MapVirtualKeyW");
  user32.oMapVisualRelativePoints =
      GetProcAddress(user32.dll, "MapVisualRelativePoints");
  user32.oMapWindowPoints = GetProcAddress(user32.dll, "MapWindowPoints");
  user32.oMenuItemFromPoint = GetProcAddress(user32.dll, "MenuItemFromPoint");
  user32.oMenuWindowProcA = GetProcAddress(user32.dll, "MenuWindowProcA");
  user32.oMenuWindowProcW = GetProcAddress(user32.dll, "MenuWindowProcW");
  user32.oMessageBeep = GetProcAddress(user32.dll, "MessageBeep");
  user32.oMessageBoxA = GetProcAddress(user32.dll, "MessageBoxA");
  user32.oMessageBoxExA = GetProcAddress(user32.dll, "MessageBoxExA");
  user32.oMessageBoxExW = GetProcAddress(user32.dll, "MessageBoxExW");
  user32.oMessageBoxIndirectA =
      GetProcAddress(user32.dll, "MessageBoxIndirectA");
  user32.oMessageBoxIndirectW =
      GetProcAddress(user32.dll, "MessageBoxIndirectW");
  user32.oMessageBoxTimeoutA = GetProcAddress(user32.dll, "MessageBoxTimeoutA");
  user32.oMessageBoxTimeoutW = GetProcAddress(user32.dll, "MessageBoxTimeoutW");
  user32.oMessageBoxW = GetProcAddress(user32.dll, "MessageBoxW");
  user32.oModifyMenuA = GetProcAddress(user32.dll, "ModifyMenuA");
  user32.oModifyMenuW = GetProcAddress(user32.dll, "ModifyMenuW");
  user32.oMonitorFromPoint = GetProcAddress(user32.dll, "MonitorFromPoint");
  user32.oMonitorFromRect = GetProcAddress(user32.dll, "MonitorFromRect");
  user32.oMonitorFromWindow = GetProcAddress(user32.dll, "MonitorFromWindow");
  user32.oMoveWindow = GetProcAddress(user32.dll, "MoveWindow");
  user32.oMsgWaitForMultipleObjects =
      GetProcAddress(user32.dll, "MsgWaitForMultipleObjects");
  user32.oMsgWaitForMultipleObjectsEx =
      GetProcAddress(user32.dll, "MsgWaitForMultipleObjectsEx");
  user32.oNotifyOverlayWindow =
      GetProcAddress(user32.dll, "NotifyOverlayWindow");
  user32.oNotifyWinEvent = GetProcAddress(user32.dll, "NotifyWinEvent");
  user32.oOemKeyScan = GetProcAddress(user32.dll, "OemKeyScan");
  user32.oOemToCharA = GetProcAddress(user32.dll, "OemToCharA");
  user32.oOemToCharBuffA = GetProcAddress(user32.dll, "OemToCharBuffA");
  user32.oOemToCharBuffW = GetProcAddress(user32.dll, "OemToCharBuffW");
  user32.oOemToCharW = GetProcAddress(user32.dll, "OemToCharW");
  user32.oOffsetRect = GetProcAddress(user32.dll, "OffsetRect");
  user32.oOpenClipboard = GetProcAddress(user32.dll, "OpenClipboard");
  user32.oOpenDesktopA = GetProcAddress(user32.dll, "OpenDesktopA");
  user32.oOpenDesktopW = GetProcAddress(user32.dll, "OpenDesktopW");
  user32.oOpenIcon = GetProcAddress(user32.dll, "OpenIcon");
  user32.oOpenInputDesktop = GetProcAddress(user32.dll, "OpenInputDesktop");
  user32.oOpenThreadDesktop = GetProcAddress(user32.dll, "OpenThreadDesktop");
  user32.oOpenWindowStationA = GetProcAddress(user32.dll, "OpenWindowStationA");
  user32.oOpenWindowStationW = GetProcAddress(user32.dll, "OpenWindowStationW");
  user32.oPackDDElParam = GetProcAddress(user32.dll, "PackDDElParam");
  user32.oPackTouchHitTestingProximityEvaluation =
      GetProcAddress(user32.dll, "PackTouchHitTestingProximityEvaluation");
  user32.oPaintDesktop = GetProcAddress(user32.dll, "PaintDesktop");
  user32.oPaintMenuBar = GetProcAddress(user32.dll, "PaintMenuBar");
  user32.oPaintMonitor = GetProcAddress(user32.dll, "PaintMonitor");
  user32.oPeekMessageA = GetProcAddress(user32.dll, "PeekMessageA");
  user32.oPeekMessageW = GetProcAddress(user32.dll, "PeekMessageW");
  user32.oPhysicalToLogicalPoint =
      GetProcAddress(user32.dll, "PhysicalToLogicalPoint");
  user32.oPhysicalToLogicalPointForPerMonitorDPI =
      GetProcAddress(user32.dll, "PhysicalToLogicalPointForPerMonitorDPI");
  user32.oPostMessageA = GetProcAddress(user32.dll, "PostMessageA");
  user32.oPostMessageW = GetProcAddress(user32.dll, "PostMessageW");
  user32.oPostQuitMessage = GetProcAddress(user32.dll, "PostQuitMessage");
  user32.oPostThreadMessageA = GetProcAddress(user32.dll, "PostThreadMessageA");
  user32.oPostThreadMessageW = GetProcAddress(user32.dll, "PostThreadMessageW");
  user32.oPrintWindow = GetProcAddress(user32.dll, "PrintWindow");
  user32.oPrivateExtractIconExA =
      GetProcAddress(user32.dll, "PrivateExtractIconExA");
  user32.oPrivateExtractIconExW =
      GetProcAddress(user32.dll, "PrivateExtractIconExW");
  user32.oPrivateExtractIconsA =
      GetProcAddress(user32.dll, "PrivateExtractIconsA");
  user32.oPrivateExtractIconsW =
      GetProcAddress(user32.dll, "PrivateExtractIconsW");
  user32.oPrivateRegisterICSProc =
      GetProcAddress(user32.dll, "PrivateRegisterICSProc");
  user32.oPtInRect = GetProcAddress(user32.dll, "PtInRect");
  user32.oQueryBSDRWindow = GetProcAddress(user32.dll, "QueryBSDRWindow");
  user32.oQueryDisplayConfig = GetProcAddress(user32.dll, "QueryDisplayConfig");
  user32.oQuerySendMessage = GetProcAddress(user32.dll, "QuerySendMessage");
  user32.oRIMAddInputObserver =
      GetProcAddress(user32.dll, "RIMAddInputObserver");
  user32.oRIMAreSiblingDevices =
      GetProcAddress(user32.dll, "RIMAreSiblingDevices");
  user32.oRIMDeviceIoControl = GetProcAddress(user32.dll, "RIMDeviceIoControl");
  user32.oRIMEnableMonitorMappingForDevice =
      GetProcAddress(user32.dll, "RIMEnableMonitorMappingForDevice");
  user32.oRIMFreeInputBuffer = GetProcAddress(user32.dll, "RIMFreeInputBuffer");
  user32.oRIMGetDevicePreparsedData =
      GetProcAddress(user32.dll, "RIMGetDevicePreparsedData");
  user32.oRIMGetDevicePreparsedDataLockfree =
      GetProcAddress(user32.dll, "RIMGetDevicePreparsedDataLockfree");
  user32.oRIMGetDeviceProperties =
      GetProcAddress(user32.dll, "RIMGetDeviceProperties");
  user32.oRIMGetDevicePropertiesLockfree =
      GetProcAddress(user32.dll, "RIMGetDevicePropertiesLockfree");
  user32.oRIMGetPhysicalDeviceRect =
      GetProcAddress(user32.dll, "RIMGetPhysicalDeviceRect");
  user32.oRIMGetSourceProcessId =
      GetProcAddress(user32.dll, "RIMGetSourceProcessId");
  user32.oRIMObserveNextInput =
      GetProcAddress(user32.dll, "RIMObserveNextInput");
  user32.oRIMOnAsyncPnpWorkNotification =
      GetProcAddress(user32.dll, "RIMOnAsyncPnpWorkNotification");
  user32.oRIMOnPnpNotification =
      GetProcAddress(user32.dll, "RIMOnPnpNotification");
  user32.oRIMOnTimerNotification =
      GetProcAddress(user32.dll, "RIMOnTimerNotification");
  user32.oRIMQueryDevicePath = GetProcAddress(user32.dll, "RIMQueryDevicePath");
  user32.oRIMReadInput = GetProcAddress(user32.dll, "RIMReadInput");
  user32.oRIMRegisterForInput =
      GetProcAddress(user32.dll, "RIMRegisterForInput");
  user32.oRIMRegisterForInputEx =
      GetProcAddress(user32.dll, "RIMRegisterForInputEx");
  user32.oRIMRemoveInputObserver =
      GetProcAddress(user32.dll, "RIMRemoveInputObserver");
  user32.oRIMSetExtendedDeviceProperty =
      GetProcAddress(user32.dll, "RIMSetExtendedDeviceProperty");
  user32.oRIMSetTestModeStatus =
      GetProcAddress(user32.dll, "RIMSetTestModeStatus");
  user32.oRIMUnregisterForInput =
      GetProcAddress(user32.dll, "RIMUnregisterForInput");
  user32.oRIMUpdateInputObserverRegistration =
      GetProcAddress(user32.dll, "RIMUpdateInputObserverRegistration");
  user32.oRaiseLowerShellWindow =
      GetProcAddress(user32.dll, "RaiseLowerShellWindow");
  user32.oRealChildWindowFromPoint =
      GetProcAddress(user32.dll, "RealChildWindowFromPoint");
  user32.oRealGetWindowClass = GetProcAddress(user32.dll, "RealGetWindowClass");
  user32.oRealGetWindowClassA =
      GetProcAddress(user32.dll, "RealGetWindowClassA");
  user32.oRealGetWindowClassW =
      GetProcAddress(user32.dll, "RealGetWindowClassW");
  user32.oReasonCodeNeedsBugID =
      GetProcAddress(user32.dll, "ReasonCodeNeedsBugID");
  user32.oReasonCodeNeedsComment =
      GetProcAddress(user32.dll, "ReasonCodeNeedsComment");
  user32.oRecordShutdownReason =
      GetProcAddress(user32.dll, "RecordShutdownReason");
  user32.oRedrawWindow = GetProcAddress(user32.dll, "RedrawWindow");
  user32.oRegisterBSDRWindow = GetProcAddress(user32.dll, "RegisterBSDRWindow");
  user32.oRegisterClassA = GetProcAddress(user32.dll, "RegisterClassA");
  user32.oRegisterClassExA = GetProcAddress(user32.dll, "RegisterClassExA");
  user32.oRegisterClassExW = GetProcAddress(user32.dll, "RegisterClassExW");
  user32.oRegisterClassW = GetProcAddress(user32.dll, "RegisterClassW");
  user32.oRegisterClipboardFormatA =
      GetProcAddress(user32.dll, "RegisterClipboardFormatA");
  user32.oRegisterClipboardFormatW =
      GetProcAddress(user32.dll, "RegisterClipboardFormatW");
  user32.oRegisterCloakedNotification =
      GetProcAddress(user32.dll, "RegisterCloakedNotification");
  user32.oRegisterDManipHook = GetProcAddress(user32.dll, "RegisterDManipHook");
  user32.oRegisterDeviceNotificationA =
      GetProcAddress(user32.dll, "RegisterDeviceNotificationA");
  user32.oRegisterDeviceNotificationW =
      GetProcAddress(user32.dll, "RegisterDeviceNotificationW");
  user32.oRegisterErrorReportingDialog =
      GetProcAddress(user32.dll, "RegisterErrorReportingDialog");
  user32.oRegisterForCustomDockTargets =
      GetProcAddress(user32.dll, "RegisterForCustomDockTargets");
  user32.oRegisterForTooltipDismissNotification =
      GetProcAddress(user32.dll, "RegisterForTooltipDismissNotification");
  user32.oRegisterFrostWindow =
      GetProcAddress(user32.dll, "RegisterFrostWindow");
  user32.oRegisterGhostWindow =
      GetProcAddress(user32.dll, "RegisterGhostWindow");
  user32.oRegisterHotKey = GetProcAddress(user32.dll, "RegisterHotKey");
  user32.oRegisterLogonProcess =
      GetProcAddress(user32.dll, "RegisterLogonProcess");
  user32.oRegisterMessagePumpHook =
      GetProcAddress(user32.dll, "RegisterMessagePumpHook");
  user32.oRegisterPointerDeviceNotifications =
      GetProcAddress(user32.dll, "RegisterPointerDeviceNotifications");
  user32.oRegisterPointerInputTarget =
      GetProcAddress(user32.dll, "RegisterPointerInputTarget");
  user32.oRegisterPointerInputTargetEx =
      GetProcAddress(user32.dll, "RegisterPointerInputTargetEx");
  user32.oRegisterPowerSettingNotification =
      GetProcAddress(user32.dll, "RegisterPowerSettingNotification");
  user32.oRegisterRawInputDevices =
      GetProcAddress(user32.dll, "RegisterRawInputDevices");
  user32.oRegisterServicesProcess =
      GetProcAddress(user32.dll, "RegisterServicesProcess");
  user32.oRegisterSessionPort =
      GetProcAddress(user32.dll, "RegisterSessionPort");
  user32.oRegisterShellHookWindow =
      GetProcAddress(user32.dll, "RegisterShellHookWindow");
  user32.oRegisterSuspendResumeNotification =
      GetProcAddress(user32.dll, "RegisterSuspendResumeNotification");
  user32.oRegisterSystemThread =
      GetProcAddress(user32.dll, "RegisterSystemThread");
  user32.oRegisterTasklist = GetProcAddress(user32.dll, "RegisterTasklist");
  user32.oRegisterTouchHitTestingWindow =
      GetProcAddress(user32.dll, "RegisterTouchHitTestingWindow");
  user32.oRegisterTouchWindow =
      GetProcAddress(user32.dll, "RegisterTouchWindow");
  user32.oRegisterTouchpadCapableThread =
      GetProcAddress(user32.dll, "RegisterTouchpadCapableThread");
  user32.oRegisterTouchpadCapableWindow =
      GetProcAddress(user32.dll, "RegisterTouchpadCapableWindow");
  user32.oRegisterUserApiHook =
      GetProcAddress(user32.dll, "RegisterUserApiHook");
  user32.oRegisterWindowMessageA =
      GetProcAddress(user32.dll, "RegisterWindowMessageA");
  user32.oRegisterWindowMessageW =
      GetProcAddress(user32.dll, "RegisterWindowMessageW");
  user32.oReleaseCapture = GetProcAddress(user32.dll, "ReleaseCapture");
  user32.oReleaseDC = GetProcAddress(user32.dll, "ReleaseDC");
  user32.oReleaseDwmHitTestWaiters =
      GetProcAddress(user32.dll, "ReleaseDwmHitTestWaiters");
  user32.oRemoveClipboardFormatListener =
      GetProcAddress(user32.dll, "RemoveClipboardFormatListener");
  user32.oRemoveInjectionDevice =
      GetProcAddress(user32.dll, "RemoveInjectionDevice");
  user32.oRemoveMenu = GetProcAddress(user32.dll, "RemoveMenu");
  user32.oRemovePropA = GetProcAddress(user32.dll, "RemovePropA");
  user32.oRemovePropW = GetProcAddress(user32.dll, "RemovePropW");
  user32.oRemoveThreadTSFEventAwareness =
      GetProcAddress(user32.dll, "RemoveThreadTSFEventAwareness");
  user32.oRemoveVisualIdentifier =
      GetProcAddress(user32.dll, "RemoveVisualIdentifier");
  user32.oReplyMessage = GetProcAddress(user32.dll, "ReplyMessage");
  user32.oReportInertia = GetProcAddress(user32.dll, "ReportInertia");
  user32.oResolveDesktopForWOW =
      GetProcAddress(user32.dll, "ResolveDesktopForWOW");
  user32.oReuseDDElParam = GetProcAddress(user32.dll, "ReuseDDElParam");
  user32.oScreenToClient = GetProcAddress(user32.dll, "ScreenToClient");
  user32.oScrollChildren = GetProcAddress(user32.dll, "ScrollChildren");
  user32.oScrollDC = GetProcAddress(user32.dll, "ScrollDC");
  user32.oScrollWindow = GetProcAddress(user32.dll, "ScrollWindow");
  user32.oScrollWindowEx = GetProcAddress(user32.dll, "ScrollWindowEx");
  user32.oSendDlgItemMessageA =
      GetProcAddress(user32.dll, "SendDlgItemMessageA");
  user32.oSendDlgItemMessageW =
      GetProcAddress(user32.dll, "SendDlgItemMessageW");
  user32.oSendIMEMessageExA = GetProcAddress(user32.dll, "SendIMEMessageExA");
  user32.oSendIMEMessageExW = GetProcAddress(user32.dll, "SendIMEMessageExW");
  user32.oSendInput = GetProcAddress(user32.dll, "SendInput");
  user32.oSendMessageA = GetProcAddress(user32.dll, "SendMessageA");
  user32.oSendMessageCallbackA =
      GetProcAddress(user32.dll, "SendMessageCallbackA");
  user32.oSendMessageCallbackW =
      GetProcAddress(user32.dll, "SendMessageCallbackW");
  user32.oSendMessageTimeoutA =
      GetProcAddress(user32.dll, "SendMessageTimeoutA");
  user32.oSendMessageTimeoutW =
      GetProcAddress(user32.dll, "SendMessageTimeoutW");
  user32.oSendMessageW = GetProcAddress(user32.dll, "SendMessageW");
  user32.oSendNotifyMessageA = GetProcAddress(user32.dll, "SendNotifyMessageA");
  user32.oSendNotifyMessageW = GetProcAddress(user32.dll, "SendNotifyMessageW");
  user32.oSetActiveWindow = GetProcAddress(user32.dll, "SetActiveWindow");
  user32.oSetAdditionalForegroundBoostProcesses =
      GetProcAddress(user32.dll, "SetAdditionalForegroundBoostProcesses");
  user32.oSetCapture = GetProcAddress(user32.dll, "SetCapture");
  user32.oSetCaretBlinkTime = GetProcAddress(user32.dll, "SetCaretBlinkTime");
  user32.oSetCaretPos = GetProcAddress(user32.dll, "SetCaretPos");
  user32.oSetClassLongA = GetProcAddress(user32.dll, "SetClassLongA");
  user32.oSetClassLongPtrA = GetProcAddress(user32.dll, "SetClassLongPtrA");
  user32.oSetClassLongPtrW = GetProcAddress(user32.dll, "SetClassLongPtrW");
  user32.oSetClassLongW = GetProcAddress(user32.dll, "SetClassLongW");
  user32.oSetClassWord = GetProcAddress(user32.dll, "SetClassWord");
  user32.oSetClipboardData = GetProcAddress(user32.dll, "SetClipboardData");
  user32.oSetClipboardViewer = GetProcAddress(user32.dll, "SetClipboardViewer");
  user32.oSetCoalescableTimer =
      GetProcAddress(user32.dll, "SetCoalescableTimer");
  user32.oSetCoreWindow = GetProcAddress(user32.dll, "SetCoreWindow");
  user32.oSetCoveredWindowStates =
      GetProcAddress(user32.dll, "SetCoveredWindowStates");
  user32.oSetCursor = GetProcAddress(user32.dll, "SetCursor");
  user32.oSetCursorContents = GetProcAddress(user32.dll, "SetCursorContents");
  user32.oSetCursorPos = GetProcAddress(user32.dll, "SetCursorPos");
  user32.oSetDebugErrorLevel = GetProcAddress(user32.dll, "SetDebugErrorLevel");
  user32.oSetDeskWallpaper = GetProcAddress(user32.dll, "SetDeskWallpaper");
  user32.oSetDesktopColorTransform =
      GetProcAddress(user32.dll, "SetDesktopColorTransform");
  user32.oSetDialogControlDpiChangeBehavior =
      GetProcAddress(user32.dll, "SetDialogControlDpiChangeBehavior");
  user32.oSetDialogDpiChangeBehavior =
      GetProcAddress(user32.dll, "SetDialogDpiChangeBehavior");
  user32.oSetDisplayAutoRotationPreferences =
      GetProcAddress(user32.dll, "SetDisplayAutoRotationPreferences");
  user32.oSetDisplayConfig = GetProcAddress(user32.dll, "SetDisplayConfig");
  user32.oSetDlgItemInt = GetProcAddress(user32.dll, "SetDlgItemInt");
  user32.oSetDlgItemTextA = GetProcAddress(user32.dll, "SetDlgItemTextA");
  user32.oSetDlgItemTextW = GetProcAddress(user32.dll, "SetDlgItemTextW");
  user32.oSetDoubleClickTime = GetProcAddress(user32.dll, "SetDoubleClickTime");
  user32.oSetFeatureReportResponse =
      GetProcAddress(user32.dll, "SetFeatureReportResponse");
  user32.oSetFocus = GetProcAddress(user32.dll, "SetFocus");
  user32.oSetForegroundRedirectionForActivationObject =
      GetProcAddress(user32.dll, "SetForegroundRedirectionForActivationObject");
  user32.oSetForegroundWindow =
      GetProcAddress(user32.dll, "SetForegroundWindow");
  user32.oSetFullscreenMagnifierOffsetsDWMUpdated =
      GetProcAddress(user32.dll, "SetFullscreenMagnifierOffsetsDWMUpdated");
  user32.oSetGestureConfig = GetProcAddress(user32.dll, "SetGestureConfig");
  user32.oSetInternalWindowPos =
      GetProcAddress(user32.dll, "SetInternalWindowPos");
  user32.oSetKeyboardState = GetProcAddress(user32.dll, "SetKeyboardState");
  user32.oSetLastErrorEx = GetProcAddress(user32.dll, "SetLastErrorEx");
  user32.oSetLayeredWindowAttributes =
      GetProcAddress(user32.dll, "SetLayeredWindowAttributes");
  user32.oSetMagnificationDesktopColorEffect =
      GetProcAddress(user32.dll, "SetMagnificationDesktopColorEffect");
  user32.oSetMagnificationDesktopMagnification =
      GetProcAddress(user32.dll, "SetMagnificationDesktopMagnification");
  user32.oSetMagnificationDesktopMagnifierOffsetsDWMUpdated = GetProcAddress(
      user32.dll, "SetMagnificationDesktopMagnifierOffsetsDWMUpdated");
  user32.oSetMagnificationDesktopSamplingMode =
      GetProcAddress(user32.dll, "SetMagnificationDesktopSamplingMode");
  user32.oSetMagnificationLensCtxInformation =
      GetProcAddress(user32.dll, "SetMagnificationLensCtxInformation");
  user32.oSetMaxTouchpadSensitivity =
      GetProcAddress(user32.dll, "SetMaxTouchpadSensitivity");
  user32.oSetMenu = GetProcAddress(user32.dll, "SetMenu");
  user32.oSetMenuContextHelpId =
      GetProcAddress(user32.dll, "SetMenuContextHelpId");
  user32.oSetMenuDefaultItem = GetProcAddress(user32.dll, "SetMenuDefaultItem");
  user32.oSetMenuInfo = GetProcAddress(user32.dll, "SetMenuInfo");
  user32.oSetMenuItemBitmaps = GetProcAddress(user32.dll, "SetMenuItemBitmaps");
  user32.oSetMenuItemInfoA = GetProcAddress(user32.dll, "SetMenuItemInfoA");
  user32.oSetMenuItemInfoW = GetProcAddress(user32.dll, "SetMenuItemInfoW");
  user32.oSetMessageExtraInfo =
      GetProcAddress(user32.dll, "SetMessageExtraInfo");
  user32.oSetMessageQueue = GetProcAddress(user32.dll, "SetMessageQueue");
  user32.oSetMirrorRendering = GetProcAddress(user32.dll, "SetMirrorRendering");
  user32.oSetParent = GetProcAddress(user32.dll, "SetParent");
  user32.oSetPhysicalCursorPos =
      GetProcAddress(user32.dll, "SetPhysicalCursorPos");
  user32.oSetPointerDeviceInputSpace =
      GetProcAddress(user32.dll, "SetPointerDeviceInputSpace");
  user32.oSetProcessDPIAware = GetProcAddress(user32.dll, "SetProcessDPIAware");
  user32.oSetProcessDefaultLayout =
      GetProcAddress(user32.dll, "SetProcessDefaultLayout");
  user32.oSetProcessDpiAwarenessContext =
      GetProcAddress(user32.dll, "SetProcessDpiAwarenessContext");
  user32.oSetProcessDpiAwarenessInternal =
      GetProcAddress(user32.dll, "SetProcessDpiAwarenessInternal");
  user32.oSetProcessLaunchForegroundPolicy =
      GetProcAddress(user32.dll, "SetProcessLaunchForegroundPolicy");
  user32.oSetProcessRestrictionExemption =
      GetProcAddress(user32.dll, "SetProcessRestrictionExemption");
  user32.oSetProcessWindowStation =
      GetProcAddress(user32.dll, "SetProcessWindowStation");
  user32.oSetProgmanWindow = GetProcAddress(user32.dll, "SetProgmanWindow");
  user32.oSetPropA = GetProcAddress(user32.dll, "SetPropA");
  user32.oSetPropW = GetProcAddress(user32.dll, "SetPropW");
  user32.oSetRect = GetProcAddress(user32.dll, "SetRect");
  user32.oSetRectEmpty = GetProcAddress(user32.dll, "SetRectEmpty");
  user32.oSetScrollInfo = GetProcAddress(user32.dll, "SetScrollInfo");
  user32.oSetScrollPos = GetProcAddress(user32.dll, "SetScrollPos");
  user32.oSetScrollRange = GetProcAddress(user32.dll, "SetScrollRange");
  user32.oSetShellChangeNotifyWindow =
      GetProcAddress(user32.dll, "SetShellChangeNotifyWindow");
  user32.oSetShellWindow = GetProcAddress(user32.dll, "SetShellWindow");
  user32.oSetShellWindowEx = GetProcAddress(user32.dll, "SetShellWindowEx");
  user32.oSetSysColors = GetProcAddress(user32.dll, "SetSysColors");
  user32.oSetSysColorsTemp = GetProcAddress(user32.dll, "SetSysColorsTemp");
  user32.oSetSystemCursor = GetProcAddress(user32.dll, "SetSystemCursor");
  user32.oSetSystemMenu = GetProcAddress(user32.dll, "SetSystemMenu");
  user32.oSetTaskmanWindow = GetProcAddress(user32.dll, "SetTaskmanWindow");
  user32.oSetThreadCursorCreationScaling =
      GetProcAddress(user32.dll, "SetThreadCursorCreationScaling");
  user32.oSetThreadDesktop = GetProcAddress(user32.dll, "SetThreadDesktop");
  user32.oSetThreadDpiAwarenessContext =
      GetProcAddress(user32.dll, "SetThreadDpiAwarenessContext");
  user32.oSetThreadDpiHostingBehavior =
      GetProcAddress(user32.dll, "SetThreadDpiHostingBehavior");
  user32.oSetThreadInputBlocked =
      GetProcAddress(user32.dll, "SetThreadInputBlocked");
  user32.oSetTimer = GetProcAddress(user32.dll, "SetTimer");
  user32.oSetUserObjectCapability =
      GetProcAddress(user32.dll, "SetUserObjectCapability");
  user32.oSetUserObjectInformationA =
      GetProcAddress(user32.dll, "SetUserObjectInformationA");
  user32.oSetUserObjectInformationW =
      GetProcAddress(user32.dll, "SetUserObjectInformationW");
  user32.oSetUserObjectSecurity =
      GetProcAddress(user32.dll, "SetUserObjectSecurity");
  user32.oSetWinEventHook = GetProcAddress(user32.dll, "SetWinEventHook");
  user32.oSetWindowBand = GetProcAddress(user32.dll, "SetWindowBand");
  user32.oSetWindowCompositionAttribute =
      GetProcAddress(user32.dll, "SetWindowCompositionAttribute");
  user32.oSetWindowCompositionTransition =
      GetProcAddress(user32.dll, "SetWindowCompositionTransition");
  user32.oSetWindowContextHelpId =
      GetProcAddress(user32.dll, "SetWindowContextHelpId");
  user32.oSetWindowDisplayAffinity =
      GetProcAddress(user32.dll, "SetWindowDisplayAffinity");
  user32.oSetWindowFeedbackSetting =
      GetProcAddress(user32.dll, "SetWindowFeedbackSetting");
  user32.oSetWindowLongA = GetProcAddress(user32.dll, "SetWindowLongA");
  user32.oSetWindowLongPtrA = GetProcAddress(user32.dll, "SetWindowLongPtrA");
  user32.oSetWindowLongPtrW = GetProcAddress(user32.dll, "SetWindowLongPtrW");
  user32.oSetWindowLongW = GetProcAddress(user32.dll, "SetWindowLongW");
  user32.oSetWindowMessageCapability =
      GetProcAddress(user32.dll, "SetWindowMessageCapability");
  user32.oSetWindowPlacement = GetProcAddress(user32.dll, "SetWindowPlacement");
  user32.oSetWindowPos = GetProcAddress(user32.dll, "SetWindowPos");
  user32.oSetWindowRgn = GetProcAddress(user32.dll, "SetWindowRgn");
  user32.oSetWindowRgnEx = GetProcAddress(user32.dll, "SetWindowRgnEx");
  user32.oSetWindowStationUser =
      GetProcAddress(user32.dll, "SetWindowStationUser");
  user32.oSetWindowTextA = GetProcAddress(user32.dll, "SetWindowTextA");
  user32.oSetWindowTextW = GetProcAddress(user32.dll, "SetWindowTextW");
  user32.oSetWindowWord = GetProcAddress(user32.dll, "SetWindowWord");
  user32.oSetWindowsHookA = GetProcAddress(user32.dll, "SetWindowsHookA");
  user32.oSetWindowsHookExA = GetProcAddress(user32.dll, "SetWindowsHookExA");
  user32.oSetWindowsHookExAW = GetProcAddress(user32.dll, "SetWindowsHookExAW");
  user32.oSetWindowsHookExW = GetProcAddress(user32.dll, "SetWindowsHookExW");
  user32.oSetWindowsHookW = GetProcAddress(user32.dll, "SetWindowsHookW");
  user32.oShellForegroundBoostProcess =
      GetProcAddress(user32.dll, "ShellForegroundBoostProcess");
  user32.oShellHandwritingDelegateInput =
      GetProcAddress(user32.dll, "ShellHandwritingDelegateInput");
  user32.oShellHandwritingHandleDelegatedInput =
      GetProcAddress(user32.dll, "ShellHandwritingHandleDelegatedInput");
  user32.oShellHandwritingUndelegateInput =
      GetProcAddress(user32.dll, "ShellHandwritingUndelegateInput");
  user32.oShellMigrateWindow = GetProcAddress(user32.dll, "ShellMigrateWindow");
  user32.oShellRegisterHotKey =
      GetProcAddress(user32.dll, "ShellRegisterHotKey");
  user32.oShellSetWindowPos = GetProcAddress(user32.dll, "ShellSetWindowPos");
  user32.oShowCaret = GetProcAddress(user32.dll, "ShowCaret");
  user32.oShowCursor = GetProcAddress(user32.dll, "ShowCursor");
  user32.oShowOwnedPopups = GetProcAddress(user32.dll, "ShowOwnedPopups");
  user32.oShowScrollBar = GetProcAddress(user32.dll, "ShowScrollBar");
  user32.oShowStartGlass = GetProcAddress(user32.dll, "ShowStartGlass");
  user32.oShowSystemCursor = GetProcAddress(user32.dll, "ShowSystemCursor");
  user32.oShowWindow = GetProcAddress(user32.dll, "ShowWindow");
  user32.oShowWindowAsync = GetProcAddress(user32.dll, "ShowWindowAsync");
  user32.oShutdownBlockReasonCreate =
      GetProcAddress(user32.dll, "ShutdownBlockReasonCreate");
  user32.oShutdownBlockReasonDestroy =
      GetProcAddress(user32.dll, "ShutdownBlockReasonDestroy");
  user32.oShutdownBlockReasonQuery =
      GetProcAddress(user32.dll, "ShutdownBlockReasonQuery");
  user32.oSignalRedirectionStartComplete =
      GetProcAddress(user32.dll, "SignalRedirectionStartComplete");
  user32.oSkipPointerFrameMessages =
      GetProcAddress(user32.dll, "SkipPointerFrameMessages");
  user32.oSoftModalMessageBox =
      GetProcAddress(user32.dll, "SoftModalMessageBox");
  user32.oSoundSentry = GetProcAddress(user32.dll, "SoundSentry");
  user32.oSubtractRect = GetProcAddress(user32.dll, "SubtractRect");
  user32.oSuppressWindowDisplayChange =
      GetProcAddress(user32.dll, "SuppressWindowDisplayChange");
  user32.oSwapMouseButton = GetProcAddress(user32.dll, "SwapMouseButton");
  user32.oSwitchDesktop = GetProcAddress(user32.dll, "SwitchDesktop");
  user32.oSwitchDesktopWithFade =
      GetProcAddress(user32.dll, "SwitchDesktopWithFade");
  user32.oSwitchToThisWindow = GetProcAddress(user32.dll, "SwitchToThisWindow");
  user32.oSystemParametersInfoA =
      GetProcAddress(user32.dll, "SystemParametersInfoA");
  user32.oSystemParametersInfoForDpi =
      GetProcAddress(user32.dll, "SystemParametersInfoForDpi");
  user32.oSystemParametersInfoW =
      GetProcAddress(user32.dll, "SystemParametersInfoW");
  user32.oTabbedTextOutA = GetProcAddress(user32.dll, "TabbedTextOutA");
  user32.oTabbedTextOutW = GetProcAddress(user32.dll, "TabbedTextOutW");
  user32.oTileChildWindows = GetProcAddress(user32.dll, "TileChildWindows");
  user32.oTileWindows = GetProcAddress(user32.dll, "TileWindows");
  user32.oToAscii = GetProcAddress(user32.dll, "ToAscii");
  user32.oToAsciiEx = GetProcAddress(user32.dll, "ToAsciiEx");
  user32.oToUnicode = GetProcAddress(user32.dll, "ToUnicode");
  user32.oToUnicodeEx = GetProcAddress(user32.dll, "ToUnicodeEx");
  user32.oTrackMouseEvent = GetProcAddress(user32.dll, "TrackMouseEvent");
  user32.oTrackPopupMenu = GetProcAddress(user32.dll, "TrackPopupMenu");
  user32.oTrackPopupMenuEx = GetProcAddress(user32.dll, "TrackPopupMenuEx");
  user32.oTranslateAccelerator =
      GetProcAddress(user32.dll, "TranslateAccelerator");
  user32.oTranslateAcceleratorA =
      GetProcAddress(user32.dll, "TranslateAcceleratorA");
  user32.oTranslateAcceleratorW =
      GetProcAddress(user32.dll, "TranslateAcceleratorW");
  user32.oTranslateMDISysAccel =
      GetProcAddress(user32.dll, "TranslateMDISysAccel");
  user32.oTranslateMessage = GetProcAddress(user32.dll, "TranslateMessage");
  user32.oTranslateMessageEx = GetProcAddress(user32.dll, "TranslateMessageEx");
  user32.oUndelegateInput = GetProcAddress(user32.dll, "UndelegateInput");
  user32.oUnhookWinEvent = GetProcAddress(user32.dll, "UnhookWinEvent");
  user32.oUnhookWindowsHook = GetProcAddress(user32.dll, "UnhookWindowsHook");
  user32.oUnhookWindowsHookEx =
      GetProcAddress(user32.dll, "UnhookWindowsHookEx");
  user32.oUnionRect = GetProcAddress(user32.dll, "UnionRect");
  user32.oUnloadKeyboardLayout =
      GetProcAddress(user32.dll, "UnloadKeyboardLayout");
  user32.oUnlockWindowStation =
      GetProcAddress(user32.dll, "UnlockWindowStation");
  user32.oUnpackDDElParam = GetProcAddress(user32.dll, "UnpackDDElParam");
  user32.oUnregisterClassA = GetProcAddress(user32.dll, "UnregisterClassA");
  user32.oUnregisterClassW = GetProcAddress(user32.dll, "UnregisterClassW");
  user32.oUnregisterDeviceNotification =
      GetProcAddress(user32.dll, "UnregisterDeviceNotification");
  user32.oUnregisterHotKey = GetProcAddress(user32.dll, "UnregisterHotKey");
  user32.oUnregisterMessagePumpHook =
      GetProcAddress(user32.dll, "UnregisterMessagePumpHook");
  user32.oUnregisterPointerInputTarget =
      GetProcAddress(user32.dll, "UnregisterPointerInputTarget");
  user32.oUnregisterPointerInputTargetEx =
      GetProcAddress(user32.dll, "UnregisterPointerInputTargetEx");
  user32.oUnregisterPowerSettingNotification =
      GetProcAddress(user32.dll, "UnregisterPowerSettingNotification");
  user32.oUnregisterSessionPort =
      GetProcAddress(user32.dll, "UnregisterSessionPort");
  user32.oUnregisterSuspendResumeNotification =
      GetProcAddress(user32.dll, "UnregisterSuspendResumeNotification");
  user32.oUnregisterTouchWindow =
      GetProcAddress(user32.dll, "UnregisterTouchWindow");
  user32.oUnregisterUserApiHook =
      GetProcAddress(user32.dll, "UnregisterUserApiHook");
  user32.oUpdateDefaultDesktopThumbnail =
      GetProcAddress(user32.dll, "UpdateDefaultDesktopThumbnail");
  user32.oUpdateLayeredWindow =
      GetProcAddress(user32.dll, "UpdateLayeredWindow");
  user32.oUpdateLayeredWindowIndirect =
      GetProcAddress(user32.dll, "UpdateLayeredWindowIndirect");
  user32.oUpdatePerUserSystemParameters =
      GetProcAddress(user32.dll, "UpdatePerUserSystemParameters");
  user32.oUpdateWindow = GetProcAddress(user32.dll, "UpdateWindow");
  user32.oUpdateWindowInputSinkHints =
      GetProcAddress(user32.dll, "UpdateWindowInputSinkHints");
  user32.oUser32InitializeImmEntryTable =
      GetProcAddress(user32.dll, "User32InitializeImmEntryTable");
  user32.oUserClientDllInitialize =
      GetProcAddress(user32.dll, "UserClientDllInitialize");
  user32.oUserHandleGrantAccess =
      GetProcAddress(user32.dll, "UserHandleGrantAccess");
  user32.oUserLpkPSMTextOut = GetProcAddress(user32.dll, "UserLpkPSMTextOut");
  user32.oUserLpkTabbedTextOut =
      GetProcAddress(user32.dll, "UserLpkTabbedTextOut");
  user32.oUserRealizePalette = GetProcAddress(user32.dll, "UserRealizePalette");
  user32.oUserRegisterWowHandlers =
      GetProcAddress(user32.dll, "UserRegisterWowHandlers");
  user32.oVRipOutput = GetProcAddress(user32.dll, "VRipOutput");
  user32.oVTagOutput = GetProcAddress(user32.dll, "VTagOutput");
  user32.oValidateRect = GetProcAddress(user32.dll, "ValidateRect");
  user32.oValidateRgn = GetProcAddress(user32.dll, "ValidateRgn");
  user32.oVkKeyScanA = GetProcAddress(user32.dll, "VkKeyScanA");
  user32.oVkKeyScanExA = GetProcAddress(user32.dll, "VkKeyScanExA");
  user32.oVkKeyScanExW = GetProcAddress(user32.dll, "VkKeyScanExW");
  user32.oVkKeyScanW = GetProcAddress(user32.dll, "VkKeyScanW");
  user32.oWCSToMBEx = GetProcAddress(user32.dll, "WCSToMBEx");
  user32.oWINNLSEnableIME = GetProcAddress(user32.dll, "WINNLSEnableIME");
  user32.oWINNLSGetEnableStatus =
      GetProcAddress(user32.dll, "WINNLSGetEnableStatus");
  user32.oWINNLSGetIMEHotkey = GetProcAddress(user32.dll, "WINNLSGetIMEHotkey");
  user32.oWaitForInputIdle = GetProcAddress(user32.dll, "WaitForInputIdle");
  user32.oWaitForRedirectionStartComplete =
      GetProcAddress(user32.dll, "WaitForRedirectionStartComplete");
  user32.oWaitMessage = GetProcAddress(user32.dll, "WaitMessage");
  user32.oWinHelpA = GetProcAddress(user32.dll, "WinHelpA");
  user32.oWinHelpW = GetProcAddress(user32.dll, "WinHelpW");
  user32.oWindowFromDC = GetProcAddress(user32.dll, "WindowFromDC");
  user32.oWindowFromPhysicalPoint =
      GetProcAddress(user32.dll, "WindowFromPhysicalPoint");
  user32.oWindowFromPoint = GetProcAddress(user32.dll, "WindowFromPoint");
  user32.o_UserTestTokenForInteractive =
      GetProcAddress(user32.dll, "_UserTestTokenForInteractive");
  user32.ogSharedInfo = GetProcAddress(user32.dll, "gSharedInfo");
  user32.ogapfnScSendMessage = GetProcAddress(user32.dll, "gapfnScSendMessage");
  user32.okeybd_event = GetProcAddress(user32.dll, "keybd_event");
  user32.omouse_event = GetProcAddress(user32.dll, "mouse_event");
  user32.owsprintfA = GetProcAddress(user32.dll, "wsprintfA");
  user32.owsprintfW = GetProcAddress(user32.dll, "wsprintfW");
  user32.owvsprintfA = GetProcAddress(user32.dll, "wvsprintfA");
  user32.owvsprintfW = GetProcAddress(user32.dll, "wvsprintfW");
}
#pragma endregion
#endif // DLL_PROXY_H
