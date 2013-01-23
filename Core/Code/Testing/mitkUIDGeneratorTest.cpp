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

#include "mitkUIDGenerator.h"
#include <mitkTestingMacros.h>
#include <mitkLogMacros.h>

void newGeneratorInstancesHeapTest()
{
    mitk::UIDGenerator* uidGen1 = new mitk::UIDGenerator("UID_",8);
    mitk::UIDGenerator* uidGen2 = uidGen1;
    std::string uid1_1, uid2_1;

    uid1_1 = uidGen1->GetUID();

    uidGen1 = new mitk::UIDGenerator("UID_",8);

    uid2_1 = uidGen1->GetUID();

    MITK_INFO << uid1_1;
    MITK_INFO << uid2_1;

    delete uidGen1;
    delete uidGen2;

    MITK_TEST_CONDITION(uid1_1 != uid2_1,"Different UIDs are not allowed to be equal");

}


void newGeneratorInstancesTest()
{
    mitk::UIDGenerator uidGen1("UID_",8);
    std::string uid1_1, uid2_1;

    uid1_1 = uidGen1.GetUID();

    uidGen1 = mitk::UIDGenerator("UID_",8);

    uid2_1 = uidGen1.GetUID();

    MITK_INFO << uid1_1;
    MITK_INFO << uid2_1;

    MITK_TEST_CONDITION(uid1_1 != uid2_1,"Different UIDs are not allowed to be equal");

}

void severalGeneratorInstancesTest()
{
    mitk::UIDGenerator uidGen1("UID_",8);
    mitk::UIDGenerator uidGen2("UID_",8);
    std::string uid1_1, uid2_1;

    uid1_1 = uidGen1.GetUID();
    uid2_1 = uidGen2.GetUID();

    MITK_INFO << uid1_1;
    MITK_INFO << uid2_1;

    MITK_TEST_CONDITION(uid1_1 != uid2_1,"Different UIDs are not allowed to be equal");

}

int mitkUIDGeneratorTest(int /*argc*/, char* /*argv*/[])
{
    MITK_TEST_BEGIN("mitkUIDGeneratorTest");
    severalGeneratorInstancesTest();
    newGeneratorInstancesTest();
    newGeneratorInstancesHeapTest();

    MITK_TEST_END();
}
