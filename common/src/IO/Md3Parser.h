/*
 Copyright (C) 2010-2017 Kristian Duske

 This file is part of TrenchBroom.

 TrenchBroom is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 TrenchBroom is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with TrenchBroom. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "Assets/EntityModel_Forward.h"
#include "IO/EntityModelParser.h"

#include <vecmath/forward.h>

#include <filesystem>
#include <memory>
#include <string>
#include <vector>

namespace TrenchBroom
{
namespace Assets
{
class Texture;
}

namespace IO
{
class FileSystem;
class Reader;

class Md3Parser : public EntityModelParser
{
private:
  std::string m_name;
  const Reader& m_reader;
  const FileSystem& m_fs;

private:
  struct Md3Triangle
  {
    size_t i1, i2, i3;
  };

public:
  Md3Parser(const std::string& name, const Reader& reader, const FileSystem& fs);

  static bool canParse(const std::filesystem::path& path, Reader reader);

private:
  std::unique_ptr<Assets::EntityModel> doInitializeModel(Logger& logger) override;
  void doLoadFrame(
    size_t frameIndex, Assets::EntityModel& model, Logger& logger) override;

  void parseSurfaces(
    Reader surfaceReader,
    size_t surfaceCount,
    Assets::EntityModel& model,
    Logger& logger);
  Assets::EntityModelLoadedFrame& parseFrame(
    Reader frameReader, size_t frameIndex, Assets::EntityModel& model);
  void parseFrameSurfaces(
    Reader surfaceReader,
    Assets::EntityModelLoadedFrame& frame,
    Assets::EntityModel& model);

  std::vector<Md3Triangle> parseTriangles(Reader reader, size_t triangleCount);
  std::vector<std::filesystem::path> parseShaders(Reader reader, size_t shaderCount);
  std::vector<vm::vec3f> parseVertexPositions(Reader reader, size_t vertexCount);
  std::vector<vm::vec2f> parseTexCoords(Reader reader, size_t vertexCount);
  std::vector<Assets::EntityModelVertex> buildVertices(
    const std::vector<vm::vec3f>& positions, const std::vector<vm::vec2f>& texCoords);

  void loadSurfaceSkins(
    Assets::EntityModelSurface& surface,
    const std::vector<std::filesystem::path>& shaders,
    Logger& logger);
  Assets::Texture loadShader(Logger& logger, const std::filesystem::path& path) const;

  void buildFrameSurface(
    Assets::EntityModelLoadedFrame& frame,
    Assets::EntityModelSurface& surface,
    const std::vector<Md3Parser::Md3Triangle>& triangles,
    const std::vector<Assets::EntityModelVertex>& vertices);
};
} // namespace IO
} // namespace TrenchBroom
