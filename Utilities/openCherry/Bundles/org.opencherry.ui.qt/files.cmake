SET(SRC_CPP_FILES
  cherryQtEditorPart.cpp
  cherryQtViewPart.cpp
  
  # application
  application/cherryQtWorkbenchAdvisor.cpp
)

SET(INTERNAL_CPP_FILES

  defaultpresentation/cherryEmptyTabFolder.cpp
  defaultpresentation/cherryEmptyTabItem.cpp
  defaultpresentation/cherryNativeTabFolder.cpp
  defaultpresentation/cherryNativeTabItem.cpp
  defaultpresentation/cherryQCTabBar.cpp
  defaultpresentation/cherryQtWorkbenchPresentationFactory.cpp
  
  util/cherryAbstractTabFolder.cpp
  util/cherryLeftToRightTabOrder.cpp
  util/cherryPartInfo.cpp
  util/cherryPresentablePartFolder.cpp
  util/cherryReplaceDragHandler.cpp
  util/cherryTabbedStackPresentation.cpp
  util/cherryTabFolderEvent.cpp

  cherryLogView.cpp

  cherryQtControlWidget.cpp
  cherryQtDnDTweaklet.cpp
  cherryQtErrorView.cpp
  cherryQtFileImageDescriptor.cpp
  cherryQtIconImageDescriptor.cpp
  cherryQtImageTweaklet.cpp
  cherryQtLogView.cpp
  cherryQtMainWindowControl.cpp
  cherryQtMissingImageDescriptor.cpp
  cherryQtPlatformLogModel.cpp
  cherryQtSash.cpp
  cherryQtShell.cpp
  cherryQtShowViewAction.cpp
  cherryQtShowViewDialog.cpp
  cherryQtTracker.cpp
  cherryQtUIPlugin.cpp
  cherryQtWidgetController.cpp
  cherryQtWidgetsTweaklet.cpp
  cherryQtWidgetsTweakletImpl.cpp
  cherryQtWorkbenchPageTweaklet.cpp
  cherryQtWorkbenchTweaklet.cpp
)

SET(MOC_H_FILES
  src/internal/defaultpresentation/cherryNativeTabFolder.h
  src/internal/defaultpresentation/cherryQCTabBar.h
  
  src/internal/cherryQtControlWidget.h
  src/internal/cherryQtMainWindowControl.h
  src/internal/cherryQtSash.h
  src/internal/cherryQtShowViewAction.h
  src/internal/cherryQtTracker.h
  src/internal/cherryQtWidgetsTweakletImpl.h
)

SET(UI_FILES
  src/internal/cherryQtShowViewDialog.ui
  src/internal/cherryQtLogView.ui
)

SET(RES_FILES
  resources.qrc
)

SET(CPP_FILES manifest.cpp)

foreach(file ${SRC_CPP_FILES})
  SET(CPP_FILES ${CPP_FILES} src/${file})
endforeach(file ${SRC_CPP_FILES})

foreach(file ${INTERNAL_CPP_FILES})
  SET(CPP_FILES ${CPP_FILES} src/internal/${file})
endforeach(file ${INTERNAL_CPP_FILES})
