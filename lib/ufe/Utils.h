// ===========================================================================
// Copyright 2019 Autodesk, Inc. All rights reserved.
//
// Use of this software is subject to the terms of the Autodesk license
// agreement provided at the time of installation or download, or which
// otherwise accompanies this software in either electronic or hard copy form.
// ===========================================================================
#pragma once

#include "../base/api.h"

#include "UsdSceneItem.h"

#include "ufe/path.h"
#include "ufe/pathSegment.h"

#include "pxr/usd/usd/prim.h"
#include "pxr/usd/sdf/layer.h"
#include "pxr/base/tf/token.h"

#include "maya/MDagPath.h"

PXR_NAMESPACE_USING_DIRECTIVE

MAYAUSD_NS_DEF {
namespace ufe {

//------------------------------------------------------------------------------
// Helper functions
//------------------------------------------------------------------------------

//! Get USD stage corresponding to argument Maya Dag path.
MAYAUSD_CORE_PUBLIC
UsdStageWeakPtr getStage(const Ufe::Path& path);

//! Return the ProxyShape node UFE path for the argument stage.
MAYAUSD_CORE_PUBLIC
Ufe::Path stagePath(UsdStageWeakPtr stage);

//! Return the USD prim corresponding to the argument UFE path.
MAYAUSD_CORE_PUBLIC
UsdPrim ufePathToPrim(const Ufe::Path& path);

MAYAUSD_CORE_PUBLIC
bool isRootChild(const Ufe::Path& path);

//! Return the highest-priority layer where the prim has a def primSpec.
MAYAUSD_CORE_PUBLIC
SdfLayerHandle defPrimSpecLayer(const UsdPrim& prim);

MAYAUSD_CORE_PUBLIC
UsdSceneItem::Ptr createSiblingSceneItem(const Ufe::Path& ufeSrcPath, const std::string& siblingName);

//! Split the source name into a base name and a numerical suffix (set to
//! 1 if absent).  Increment the numerical suffix until name is unique.
MAYAUSD_CORE_PUBLIC
std::string uniqueName(const TfToken::HashSet& existingNames, std::string srcName);

//! Return a unique child name. Parent must be a UsdSceneItem.
MAYAUSD_CORE_PUBLIC
std::string uniqueChildName(const Ufe::SceneItem::Ptr& parent, const Ufe::Path& childPath);

//! Return if a Maya node type is derived from the gateway node type.
MAYAUSD_CORE_PUBLIC
bool isAGatewayType(const std::string& mayaNodeType);

MAYAUSD_CORE_PUBLIC
Ufe::Path dagPathToUfe(const MDagPath& dagPath);

MAYAUSD_CORE_PUBLIC
Ufe::PathSegment dagPathToPathSegment(const MDagPath& dagPath);

MAYAUSD_CORE_PUBLIC
MDagPath nameToDagPath(const std::string& name);

} // namespace ufe
} // namespace MayaUsd