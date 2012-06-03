/*
 Copyright (C) 2010-2012 Kristian Duske
 
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
 along with TrenchBroom.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TrenchBroom_Editor_h
#define TrenchBroom_Editor_h

#include <string>

namespace TrenchBroom {
    class Filter;
    
    namespace Model {
        namespace Assets {
            class TextureManager;
            class Palette;
        }
        class Map;
    }
    
    namespace Renderer {
        class MapRenderer;
    }
    
    namespace Controller {
        class Camera;
        class Grid;
        class InputController;
        class TransientOptions;
        class ProgressIndicator;

        class Editor {
        private:
            std::string m_mapPath;
            Model::Map* m_map;
            Camera* m_camera;
            Grid* m_grid;
            InputController* m_inputController;
            TransientOptions* m_options;
            Filter* m_filter;
            Model::Assets::TextureManager* m_textureManager;
            Model::Assets::Palette* m_palette;
            Renderer::MapRenderer* m_renderer;
            std::string m_entityDefinitionFilePath;

            void updateFaceTextures();
            void textureManagerDidChange(Model::Assets::TextureManager& textureManager);
            void preferencesDidChange(const std::string& key);
        public:
            Editor(const std::string& entityDefinitionFilePath, const std::string& palettePath);
            ~Editor();
            
            void loadMap(const std::string& path, ProgressIndicator* indicator);
            void saveMap(const std::string& path);
            
            void loadTextureWad(const std::string& path);
            
            Model::Map& map();
            Camera& camera();
            Grid& grid();
            InputController& inputController();
            TransientOptions& options();
            Filter& filter();
            Model::Assets::Palette& palette();
            Model::Assets::TextureManager& textureManager();
            
            void setRenderer(Renderer::MapRenderer* renderer);
            Renderer::MapRenderer* renderer();
        };
    }
}

#endif
