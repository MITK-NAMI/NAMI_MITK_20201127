#include "mitkAIFParametrizerHelper.h"

mitk::ModelBase::StaticParameterValuesType mitk::convertArrayToParameter(itk::Array<double> array)
{
    ModelBase::StaticParameterValuesType parameter;
    for(itk::Array<double>::const_iterator pos = array.begin(); pos != array.end(); ++pos)
    {
      parameter.push_back(*pos);
    }
    return parameter;
}

itk::Array<double> mitk::convertParameterToArray(ModelBase::StaticParameterValuesType parameter)
{
    itk::Array<double> array(parameter.size());
    array.fill(0.0);
    itk::Array<double>::iterator arrayPos = array.begin();
    for(ModelBase::StaticParameterValuesType::const_iterator pos = parameter.begin(); pos != parameter.end(); ++pos, ++arrayPos)
    {
      *arrayPos = *pos;
    }
    return array;
}
