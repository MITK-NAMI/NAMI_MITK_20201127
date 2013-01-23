/*===================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center,
Division of Medical and Biological Informatics.
All rights reserved.

This software is distributed WITHOUT ANY WARRANTY; without
even the implied warranty of MERCHANTABILITY or FITNESS FOR
A PARTICULAR PURPOSE.

See LICENSE.txt or http://www.mitk.org for details.

===================================================================*/


#ifndef MITKPLANARFIGUREINTERACTOR_H_HEADER_INCLUDED
#define MITKPLANARFIGUREINTERACTOR_H_HEADER_INCLUDED

#include "PlanarFigureExports.h"

#include "mitkCommon.h"
#include "mitkVector.h"
#include "mitkInteractor.h"
#include "mitkBaseRenderer.h"

#pragma GCC visibility push(default)
#include <itkEventObject.h>
#pragma GCC visibility pop

namespace mitk
{

class DataNode;
class Geometry2D;
class DisplayGeometry;
class PlanarFigure;
class PositionEvent;

#pragma GCC visibility push(default)

// Define events for PlanarFigure interaction notifications
itkEventMacro( PlanarFigureEvent, itk::AnyEvent );
itkEventMacro( StartPlacementPlanarFigureEvent, PlanarFigureEvent );
itkEventMacro( EndPlacementPlanarFigureEvent, PlanarFigureEvent );
itkEventMacro( SelectPlanarFigureEvent, PlanarFigureEvent );
itkEventMacro( StartInteractionPlanarFigureEvent, PlanarFigureEvent );
itkEventMacro( EndInteractionPlanarFigureEvent, PlanarFigureEvent );
itkEventMacro( StartHoverPlanarFigureEvent, PlanarFigureEvent );
itkEventMacro( EndHoverPlanarFigureEvent, PlanarFigureEvent );
itkEventMacro( ContextMenuPlanarFigureEvent, PlanarFigureEvent );

#pragma GCC visibility pop


/**
  * \brief Interaction with mitk::PlanarFigure objects via control-points
  *
  * \ingroup Interaction
  */
class PlanarFigure_EXPORT PlanarFigureInteractor : public Interactor
{
public:
  mitkClassMacro(PlanarFigureInteractor, Interactor);
  mitkNewMacro3Param(Self, const char *, DataNode *, int);
  mitkNewMacro2Param(Self, const char *, DataNode *);

  /** \brief Sets the amount of precision */
  void SetPrecision( ScalarType precision );

  /** \brief Sets the minimal distance between two control points. */
  void SetMinimumPointDistance( ScalarType minimumDistance );

  /**
    * \brief Calculates how good the data, this statemachine handles, is hit
    * by the event.
    *
    * This method returns 0.0 (and thus does NOT handle the given event at
    * all) if:
    *  - the incoming event is NOT a mitk::PositionEvent
    *  - this statemachine has no transition for the incoming event in the current state
    *  - the current position (in world coordinates) of the incoming event is further away
    *    from the planarFigure geometry than the planeThickness
    *
    * If the planarFigure that is handled by this statemachine is NULL, 0.42 is returned.
    * (rather unlikely that the event will be handled)
    *
    * If the planarFigure is
    *  - selected but NOT placed (on click a new planarFigure will be created) -> 0.6 is returned
    *  - placed but NOT selected (picking of existing planarFigures) -> 0.7 is returned
    *  - placed AND selected (editing of selected planarFigure) -> 0.75 is returned
    *
    * Thus, the user rather edits an existing planarFigure than create a new one.
    */
  virtual float CanHandleEvent(StateEvent const *stateEvent) const;


protected:
  /**
    * \brief Constructor with Param n for limited Set of Points
    *
    * if no n is set, then the number of points is unlimited*
    */
  PlanarFigureInteractor(const char *type,
    DataNode *dataNode, int n = -1);

  /**
    * \brief Default Destructor
    **/
  virtual ~PlanarFigureInteractor();

  virtual bool ExecuteAction( Action *action,
    mitk::StateEvent const *stateEvent );

  /**
    \brief Used when clicking to determine if a point is too close to the previous point.
    */
  bool IsMousePositionAcceptableAsNewControlPoint( mitk::StateEvent const *, const PlanarFigure* );

  bool TransformPositionEventToPoint2D( const StateEvent *stateEvent,
    Point2D &point2D,
    const Geometry2D *planarFigureGeometry );

  bool TransformObjectToDisplay( const mitk::Point2D &point2D,
    mitk::Point2D &displayPoint,
    const mitk::Geometry2D *objectGeometry,
    const mitk::Geometry2D *rendererGeometry,
    const mitk::DisplayGeometry *displayGeometry ) const;

  /** \brief Returns true if the first specified point is in proximity of the line defined
   * the other two point; false otherwise.
   *
   * Proximity is defined as the rectangle around the line with pre-defined distance
   * from the line. */
  bool IsPointNearLine( const mitk::Point2D& point,
    const mitk::Point2D& startPoint, const mitk::Point2D& endPoint, mitk::Point2D& projectedPoint ) const;

  /** \brief Returns true if the point contained in the passed event (in display coordinates)
   * is over the planar figure (with a pre-defined tolerance range); false otherwise. */
  int IsPositionOverFigure(
    const StateEvent *StateEvent, PlanarFigure *planarFigure,
    const Geometry2D *planarFigureGeometry,
    const Geometry2D *rendererGeometry,
    const DisplayGeometry *displayGeometry,
    Point2D& pointProjectedOntoLine) const;

  /** \brief Returns the index of the marker (control point) over which the point contained
   * in the passed event (in display coordinates) currently is; -1 if the point is not over
   * a marker. */
  int IsPositionInsideMarker(
    const StateEvent *StateEvent, const PlanarFigure *planarFigure,
    const Geometry2D *planarFigureGeometry,
    const Geometry2D *rendererGeometry,
    const DisplayGeometry *displayGeometry ) const;

  void LogPrintPlanarFigureQuantities( const PlanarFigure *planarFigure );

private:

  /** \brief to store the value of precision to pick a point */
  ScalarType m_Precision;

  /** \brief Store the minimal distance between two control points. */
  ScalarType m_MinimumPointDistance;

  /** \brief True if the mouse is currently hovering over the image. */
  bool m_IsHovering;

  bool m_LastPointWasValid;
};

}

#endif // MITKPLANARFIGUREINTERACTOR_H_HEADER_INCLUDED
