// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once

#include <optional>

#include "impeller/entity/geometry/geometry.h"
#include "impeller/geometry/rect.h"

namespace impeller {

/// @brief A geometry that is created from a filled path object.
class FillPathGeometry final : public Geometry {
 public:
  explicit FillPathGeometry(const Path& path,
                            std::optional<Rect> inner_rect = std::nullopt);

  ~FillPathGeometry() = default;

  // |Geometry|
  bool CoversArea(const Matrix& transform, const Rect& rect) const override;

 private:
  // |Geometry|
  GeometryResult GetPositionBuffer(const ContentContext& renderer,
                                   const Entity& entity,
                                   RenderPass& pass) const override;

  // |Geometry|
  GeometryVertexType GetVertexType() const override;

  // |Geometry|
  std::optional<Rect> GetCoverage(const Matrix& transform) const override;

  // |Geometry|
  GeometryResult GetPositionUVBuffer(Rect texture_coverage,
                                     Matrix effect_transform,
                                     const ContentContext& renderer,
                                     const Entity& entity,
                                     RenderPass& pass) const override;

  Path path_;
  std::optional<Rect> inner_rect_;

  FillPathGeometry(const FillPathGeometry&) = delete;

  FillPathGeometry& operator=(const FillPathGeometry&) = delete;
};

}  // namespace impeller
